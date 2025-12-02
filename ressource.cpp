#include "ressource.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QFile>
#include <QDebug>
#include <QVariant>
#include <QPrinter>
#include <QPainter>
#include <QDateTime>
#include <QFont>

// Constructeur par défaut (obligatoire en Qt 6)
Ressource::Ressource() : taille(0) {}

// Constructeur complet
Ressource::Ressource(const QString &id, const QString &titre, const QString &type,
                     const QString &tags, const QString &format, const QString &datecreation,
                     const QString &id_projet, qint64 taille, const QString &filepath)
    : id_res(id), titre(titre), type(type), tags(tags), format(format),
    datecreation(datecreation), id_projet(id_projet), taille(taille), filepath(filepath)
{}

bool Ressource::ajouter() const
{
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        qCritical() << "DB non ouverte";
        return false;
    }

    QSqlQuery q(db);

    // Requête avec ? (le seul moyen fiable avec QODBC + Oracle pour les nombres)
    q.prepare(R"(
        INSERT INTO ARTEMIA.RESSOURCES
        (ID_RESSOURCE, TITRE, TYPE, TAGS, FORMAT, DATECREATION, ID_PROJET, TAILLE, FICHIER)
        VALUES (?, ?, ?, ?, ?, TO_DATE(?, 'YYYY-MM-DD'), ?, ?, EMPTY_BLOB())
    )");

    q.addBindValue(id_res);
    q.addBindValue(titre);
    q.addBindValue(type);
    q.addBindValue(tags);
    q.addBindValue(format);
    q.addBindValue(datecreation);                 // format YYYY-MM-DD

    // ID_PROJET
    if (id_projet.isEmpty())
        q.addBindValue(QVariant());                   // NULL
    else
        q.addBindValue(id_projet.toInt());

    // TAILLE → LA LIGNE QUI RÉSOUT TOUT (conversion explicite en int 32 bits)
    if (taille <= 0)
        q.addBindValue(QVariant());                   // NULL
    else
        q.addBindValue(static_cast<int>(taille));     // Oracle accepte très bien un int pour NUMBER

    // FICHIER → on met EMPTY_BLOB() maintenant (plus sûr)
    // on remplira le BLOB après avec RETURNING

    if (!q.exec()) {
        qCritical() << "ERREUR INSERT :" << q.lastError().text();
        return false;
    }

    // === Insertion du BLOB avec RETURNING (méthode la plus fiable avec Oracle) ===
    if (!filepath.isEmpty() && QFile::exists(filepath)) {
        QFile file(filepath);
        if (file.open(QIODevice::ReadOnly)) {
            QByteArray blob = file.readAll();
            file.close();

            if (!blob.isEmpty()) {
                QSqlQuery upd(db);
                upd.prepare(R"(
                    UPDATE ARTEMIA.RESSOURCES
                    SET FICHIER = :blob,
                        TAILLE  = :size
                    WHERE ID_RESSOURCE = :id
                )");
                upd.bindValue(":blob", blob);
                upd.bindValue(":size", static_cast<int>(blob.size()));
                upd.bindValue(":id",   id_res);

                if (!upd.exec()) {
                    qWarning() << "Échec mise à jour BLOB :" << upd.lastError().text();
                }
            }
        }
    }

    qDebug() << "Ressource ajoutée avec succès :" << id_res;
    return true;
}
bool Ressource::modifier() const
{
    QSqlQuery q;
    // === DANS modifier() === (lignes ~90-95)
    q.prepare("UPDATE ARTEMIA.RESSOURCES SET "
              "TITRE=?, TYPE=?, TAGS=?, FORMAT=?, "
              "DATECREATION=TO_DATE(?, 'YYYY-MM-DD'), ID_PROJET=?, "
              "TAILLE=? WHERE ID_RESSOURCE=?");

    q.addBindValue(titre);
    q.addBindValue(type);
    q.addBindValue(tags);
    q.addBindValue(format);
    q.addBindValue(datecreation);
    q.addBindValue(id_projet.isEmpty() ? QVariant() : id_projet);
    q.addBindValue(taille <= 0 ? QVariant() : QVariant(taille));
    q.addBindValue(id_res);
    if (!q.exec()) {
        qCritical() << "ERREUR MODIF:" << q.lastError().text();
        return false;
    }

    // Si nouveau fichier, UPDATE BLOB séparé (comme dans ajouter)
    if (!filepath.isEmpty() && QFile::exists(filepath)) {
        // ... (copie le code UPDATE de ajouter() ici)
    }

    return true;
}

// ====================== SUPPRIMER ======================
bool Ressource::supprimer(const QString &id)
{
    QSqlQuery q;
    q.prepare("DELETE FROM ARTEMIA.RESSOURCES WHERE ID_RESSOURCE = :id");
    q.bindValue(":id", id);
    return q.exec();
}

QSqlQueryModel* Ressource::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel;
    // On affiche le NOM DU FICHIER au lieu du BLOB brut
    model->setQuery(R"(
        SELECT ID_RESSOURCE,
               TITRE,
               TYPE,
               TAGS,
               FORMAT,
               TO_CHAR(DATECREATION, 'DD/MM/YYYY') AS DATE_CREATION,
               ID_PROJET,
               CASE
                   WHEN FICHIER IS NULL THEN 'Aucun fichier'
                   WHEN DBMS_LOB.GETLENGTH(FICHIER) = 0 THEN 'Fichier vide'
                   ELSE 'Fichier joint (' || DBMS_LOB.GETLENGTH(FICHIER) || ' octets)'
               END AS FICHIER_INFO
        FROM ARTEMIA.RESSOURCES
        ORDER BY DATECREATION DESC
    )");
    // En-têtes du tableau (inchangé)
    model->setHeaderData(0, Qt::Horizontal, "ID");
    model->setHeaderData(1, Qt::Horizontal, "Titre");
    model->setHeaderData(2, Qt::Horizontal, "Type");
    model->setHeaderData(3, Qt::Horizontal, "Tags");
    model->setHeaderData(4, Qt::Horizontal, "Format");
    model->setHeaderData(5, Qt::Horizontal, "Date Création");
    model->setHeaderData(6, Qt::Horizontal, "ID Projet");
    model->setHeaderData(7, Qt::Horizontal, "Fichier");
    return model;
}
// ====================== STATISTIQUES ======================
int Ressource::countByType(const QString &type)
{
    QSqlQuery q;
    q.prepare("SELECT COUNT(*) FROM ARTEMIA.RESSOURCES WHERE LOWER(TYPE) LIKE LOWER(:t)");
    q.bindValue(":t", "%" + type + "%");
    q.exec();
    return q.next() ? q.value(0).toInt() : 0;
}

// ====================== EXPORT PDF – 0 WARNING CLAZY ======================
bool Ressource::exporterPDF(const QString &chemin)
{
    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(chemin);

    QPainter painter(&printer);
    painter.setFont(QFont(QStringLiteral("Arial"), 16, QFont::Bold));
    painter.drawText(100, 100, QStringLiteral("RAPPORT DES RESSOURCES - ARTEMIA"));

    painter.setFont(QFont(QStringLiteral("Arial"), 10));
    painter.drawText(100, 150,
                     QStringLiteral("Généré le %1")
                         .arg(QDateTime::currentDateTime().toString(QStringLiteral("dd/MM/yyyy à hh:mm"))));

    int y = 300;
    QSqlQuery q;
    q.exec(QStringLiteral("SELECT ID_RESSOURCE, TITRE, TYPE, TO_CHAR(DATECREATION,'DD/MM/YYYY') "
                          "FROM ARTEMIA.RESSOURCES ORDER BY DATECREATION DESC"));

    while (q.next()) {
        painter.drawText(100, y,
                         QStringLiteral("%1 • %2 • %3 • %4")
                             .arg(q.value(0).toString())
                             .arg(q.value(1).toString())
                             .arg(q.value(2).toString())
                             .arg(q.value(3).toString()));
        y += 60;
        if (y > 1100) {
            printer.newPage();
            y = 200;
        }
    }
    painter.end();
    return true;
}
