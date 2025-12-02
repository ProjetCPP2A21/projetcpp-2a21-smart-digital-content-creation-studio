// ressourcemainwindow.cpp
#include "ressourcemainwindow.h"
#include "ui_ressourcemainwindow.h"
#include "ressource.h"
#include "statsdialog.h"
#include <QTemporaryFile>
#include <QDesktopServices>
#include <QUrl>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QDialog>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QMessageBox>
#include <QPixmap>
#include <QTimer>
#include <QFileInfo>
#include <QSqlQuery>
#include <QDate>
#include <QStyledItemDelegate>
#include <QPrinter>
#include <QTextDocument>
#include <QPageSize>
ressourceMainWindow::ressourceMainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::ressourceMainWindow)
{
    ui->setupUi(this);
    setWindowTitle("ARTEMIA - Gestion des Ressources");
    // =============================================
    // === COULEURS MODERNES & PROFESSIONNELLES ===
    // =============================================
    currentFileSize = 0;
    currentFilePath = "";
    // Fond général + style sombre élégant

    setStyleSheet(R"(
    /* Fond général + texte */
    QMainWindow, QWidget {
        background-color: #1e1e2e;
        color: #cdd6f4;
        font-family: "Segoe UI", Arial, sans-serif;
        font-size: 10pt;
    }

    /* Boutons principaux (bleu) */
    QPushButton {
        background-color: #89b4fa;
        color: #1e1e2e;
        border: none;
        border-radius: 8px;
        padding: 10px 20px;
        font-weight: bold;
    }
    QPushButton:hover  { background-color: #b4befe; }
    QPushButton:pressed { background-color: #74c7ec; }

    /* Bouton Supprimer (rouge) */
    QPushButton#SupprimerRess,
    QPushButton[text="Supprimer"] {
        background-color: #f38ba8;
    }
    QPushButton#SupprimerRess:hover,
    QPushButton[text="Supprimer"]:hover {
        background-color: #eba0ac;
    }

    /* Boutons orange (PDF + Stats) */
    QPushButton#PDFRess,
    QPushButton#StatistiqueRess,
    QPushButton[text="Exporter PDF"],
    QPushButton[text="Statistiques"] {
        background-color: #fab387;
    }
    QPushButton#PDFRess:hover,
    QPushButton#StatistiqueRess:hover {
        background-color: #f9e2af;
    }

    /* Zone d'aperçu / drag & drop */
    QLabel#labelAffichage {
        background-color: #313244;
        border: 3px dashed #89b4fa;
        border-radius: 12px;
        padding: 20px;
        font-size: 13pt;
        text-align: center;
    }

    /* Champs de saisie */
    QLineEdit, QComboBox, QDateEdit {
        background-color: #313244;
        border: 1px solid #585b70;
        border-radius: 6px;
        padding: 8px;
        color: white;
    }
    QLineEdit:focus, QComboBox:focus, QDateEdit:focus {
        border: 2px solid #89b4fa;
    }

    /* Barre de recherche */
    QLineEdit#RechercheRess {
        background-color: #313244;
        border: 2px solid #fab387;
        border-radius: 20px;
        padding: 10px 20px;
        font-size: 11pt;
    }

    /* Tableau */
    QTableView {
        background-color: #181825;
        gridline-color: #313244;
        alternate-background-color: #1e1e2e;
        selection-background-color: #89b4fa;
        selection-color: #1e1e2e;
    }
    QHeaderView::section {
        background-color: #313244;
        padding: 10px;
        font-weight: bold;
        color: #cdd6f4;
        border: none;
    }

    /* Checkboxes */
    QCheckBox {
        color: #cdd6f4;
    }
    QCheckBox::indicator:checked {
        background-color: #a6e3a1;
        border: 2px solid #a6e3a1;
    }

    /* Highlight recherche (jaune) */
    QTableView::item[highlight="true"] {
        background-color: #f9e2af;
        color: #1e1e2e;
        font-weight: bold;
    }
)");

    connect(ui->RechercheRess,   &QLineEdit::textChanged, this, &ressourceMainWindow::on_RechercheRess_textChanged);
    connect(ui->RessourceTab,    &QTableView::clicked, this, &ressourceMainWindow::on_RessourceTab_clicked);

    connect(ui->Imagecheck, &QCheckBox::checkStateChanged, this, &ressourceMainWindow::filterTable);
    connect(ui->Videocheck, &QCheckBox::checkStateChanged, this, &ressourceMainWindow::filterTable);
    connect(ui->audiocheck, &QCheckBox::checkStateChanged, this, &ressourceMainWindow::filterTable);
    connect(ui->RessourceTab, &QTableView::doubleClicked, this, &ressourceMainWindow::on_RessourceTab_doubleClicked);
    // Rendre l'ID en lecture seule (l'utilisateur ne peut pas l'éditer)
    ui->ID_RESSOURCE->setReadOnly(true);
    ui->ID_RESSOURCE->setStyleSheet("QLineEdit { background-color: #45475a; color: #cdd6f4; }");  // Optionnel : style grisé pour indiquer "non éditable"

    ui->DATECREATION->setDate(QDate::currentDate());
    ui->outputajout->setReadOnly(true);
    connect(ui->RechercheRess, &QLineEdit::textChanged, this, [this](const QString &text) {
        filterTable();                    // Ta fonction actuelle de filtrage
        highlightSearchResults(text);     // Nouvelle fonction magique
    });

    // Style global du tableau avec support du highlight
    ui->RessourceTab->setStyleSheet(R"(
        QTableView {
            background-color: #181825;
            gridline-color: #313244;
            alternate-background-color: #1e1e2e;
            selection-background-color: #89b4fa;
            selection-color: #1e1e2e;
        }
        QTableView::item {
            padding: 10px;
            border-radius: 6px;
        }
        QTableView::item[highlight="true"] {
            background-color: #f9e2af;
            color: #1e1e2e;
            font-weight: bold;
        }
    )");

    // Optionnel : placeholder
    ui->RechercheRess->setPlaceholderText("Rechercher par titre, tags, format...");

    QTimer::singleShot(500, this, [this](){
        refreshTable();
    });
}

ressourceMainWindow::~ressourceMainWindow() { delete ui; }

QString ressourceMainWindow::generateNextId()
{
    QSqlQuery q;
    q.exec("SELECT 'R' || LPAD(NVL(MAX(TO_NUMBER(SUBSTR(ID_RESSOURCE, 2))), 0) + 1, 4, '0') FROM ARTEMIA.RESSOURCES");
    if (q.next()) return q.value(0).toString();
    return "R0001";
}

void ressourceMainWindow::on_ImpBut_clicked()
{
    QString file = QFileDialog::getOpenFileName(this, "Choisir fichier", "", "Tous (*.*)");
    if (file.isEmpty()) return;
    currentFilePath = file;
    currentFileSize = QFileInfo(file).size();
    ui->outputajout->setText(QFileInfo(file).fileName() + " (" + QString::number(currentFileSize/1024.0,'f',1) + " KB)");
    loadFilePreview(file);
}

void ressourceMainWindow::loadFilePreview(const QString &path)
{
    ui->labelAffichage->clear();
    QPixmap pix(path);
    if (!pix.isNull()) {
        ui->labelAffichage->setPixmap(pix.scaled(381,351,Qt::KeepAspectRatio,Qt::SmoothTransformation));
    } else {
        ui->labelAffichage->setText("Fichier sélectionné:\n" + QFileInfo(path).fileName());
    }
}

void ressourceMainWindow::on_AjoutRess_clicked()
{
    QString id = ui->ID_RESSOURCE->text().trimmed();
    QString titre = ui->TITRE->text().trimmed();
    QString type = ui->TYPE->currentText().trimmed();
    QString tags = ui->TAGS->text().trimmed();
    QString format = ui->FORMAT->text().trimmed();
    QString dateCreation = ui->DATECREATION->date().toString("yyyy-MM-dd");
    QString id_projet = ui->ID_PROJET->text().trimmed();

    // Champs obligatoires (ID_PROJET N'EN FAIT PLUS PARTIE)
    if (titre.isEmpty() || type.isEmpty() || format.isEmpty()) {
        QMessageBox::warning(this, "Champs manquants",
                             "Veuillez remplir tous les champs obligatoires.");
        return;
    }

    if (id.isEmpty())
        id = generateNextId();
    // Après génération...
    ui->ID_RESSOURCE->setText(id);  // Affiche l'ID auto-généré avant l'ajout

    // Si le champ projet est vide → on met une valeur spéciale
    if (id_projet.isEmpty())
        id_projet = ""; // ou QVariant(), ou NULL selon ton SQL

    Ressource r(id, titre, type, tags, format, dateCreation,
                id_projet, currentFileSize, currentFilePath);

    if (currentFileSize > 1024 * 1024) {  // Limite à 1 MB, ajuste si besoin
        QMessageBox::warning(this, "Fichier trop volumineux",
                             "Le fichier dépasse 1 MB. L'insertion de gros BLOBs peut causer un crash avec ODBC/Oracle.\n"
                             "Utilisez un fichier plus petit ou stockez le chemin au lieu du BLOB.");
        return;
    }

    if (r.ajouter()) {
        QMessageBox::information(this, "Succès", "Ressource ajoutée !");
        refreshTable();
        clearForm();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout de la ressource.");
    }
}



void ressourceMainWindow::on_ModifieRess_clicked()
{
    if (ui->ID_RESSOURCE->text().isEmpty()) return;
    Ressource r(ui->ID_RESSOURCE->text(), ui->TITRE->text(), ui->TYPE->currentText(),
                ui->TAGS->text(), ui->FORMAT->text(),
                ui->DATECREATION->date().toString("yyyy-MM-dd"),
                ui->ID_PROJET->text(), currentFileSize,
                currentFilePath.isEmpty() ? "" : currentFilePath);

    if (r.modifier()) {
        QMessageBox::information(this, "Succès", "Modifié !");
        refreshTable();
    }
}

void ressourceMainWindow::on_SupprimerRess_clicked()
{
    QString id = ui->ID_RESSOURCE->text();
    if (id.isEmpty() || QMessageBox::question(this,"Confirmer","Supprimer ?") != QMessageBox::Yes) return;
    if (Ressource::supprimer(id)) {
        QMessageBox::information(this, "Succès", "Supprimé");
        refreshTable();
        clearForm();
    }
}

void ressourceMainWindow::on_RechercheRess_textChanged(const QString &) { filterTable(); }

void ressourceMainWindow::filterTable()
{
    QString search = ui->RechercheRess->text();
    bool img = ui->Imagecheck->isChecked();
    bool vid = ui->Videocheck->isChecked();
    bool aud = ui->audiocheck->isChecked();

    QString sql = "SELECT ID_RESSOURCE, TITRE, TYPE, TAGS, FORMAT, TO_CHAR(DATECREATION,'DD/MM/YYYY'), ID_PROJET FROM ARTEMIA.RESSOURCES WHERE 1=1";
    if (!search.isEmpty()) sql += " AND (LOWER(TITRE) LIKE :s OR LOWER(TAGS) LIKE :s)";
    if (img) sql += " AND LOWER(TYPE) LIKE '%image%'";
    if (vid) sql += " AND LOWER(TYPE) LIKE '%vid%'";
    if (aud) sql += " AND LOWER(TYPE) LIKE '%audio%'";
    sql += " ORDER BY DATECREATION DESC";

    QSqlQueryModel *model = new QSqlQueryModel;
    QSqlQuery q;
    q.prepare(sql);
    if (!search.isEmpty()) q.bindValue(":s", "%"+search.toLower()+"%");
    q.exec();
    model->setQuery(std::move(q));
    ui->RessourceTab->setModel(model);
    ui->RessourceTab->resizeColumnsToContents();
}

void ressourceMainWindow::on_RessourceTab_clicked(const QModelIndex &index)
{
    int r = index.row();
    ui->ID_RESSOURCE->setText(index.sibling(r,0).data().toString());
    ui->TITRE->setText(index.sibling(r,1).data().toString());
    ui->TYPE->setCurrentText(index.sibling(r,2).data().toString());
    ui->TAGS->setText(index.sibling(r,3).data().toString());
    ui->FORMAT->setText(index.sibling(r,4).data().toString());
    ui->DATECREATION->setDate(QDate::fromString(index.sibling(r,5).data().toString(),"dd/MM/yyyy"));
    ui->ID_PROJET->setText(index.sibling(r,6).data().toString());
}

void ressourceMainWindow::on_StatistiqueRess_clicked()
{
    StatsDialog dlg(Ressource::countByType("image"),
                    Ressource::countByType("video"),
                    Ressource::countByType("audio"), this);
    dlg.exec();
}

void ressourceMainWindow::on_PDFRess_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Exporter en PDF", "", "Fichiers PDF (*.pdf)");
    if (fileName.isEmpty()) return;
    if (!fileName.endsWith(".pdf", Qt::CaseInsensitive))
        fileName += ".pdf";

    QSqlQuery query;
    query.exec("SELECT ID_RESSOURCE, TITRE, TYPE, TAGS, FORMAT, DATECREATION, ID_PROJET, TAILLE FROM ARTEMIA.RESSOURCES ORDER BY DATECREATION DESC");

    QString html = R"(
    <!DOCTYPE html>
    <html>
    <head>
        <meta charset="utf-8">
        <style>
            body { font-family: Arial, sans-serif; margin: 40px; color: #333; }
            h1 { color: #89b4fa; text-align: center; font-size: 28pt; }
            .header { text-align: center; color: #666; font-size: 14pt; margin: 20px 0; }
            table { width: 100%; border-collapse: collapse; margin-top: 30px; font-size: 11pt; }
            th { background-color: #313244; color: white; padding: 12px; text-align: center; }
            td { padding: 10px; border-bottom: 1px solid #ddd; text-align: center; }
            tr:nth-child(even) { background-color: #f2f2f2; }
            tr:hover { background-color: #e0e0e0; }
            .footer { margin-top: 50px; text-align: center; color: #666; font-size: 10pt; }
        </style>
    </head>
    <body>
        <h1>RAPPORT DES RESSOURCES - ARTEMIA</h1>
        <div class="header">Généré le )" + QDateTime::currentDateTime().toString("dd/MM/yyyy à HH:mm") + R"(</div>
        <table>
            <tr>
                <th>ID</th><th>Titre</th><th>Type</th><th>Tags</th><th>Format</th><th>Date</th><th>Projet</th><th>Taille (Ko)</th>
            </tr>
    )";

    while (query.next()) {
        QString taille = query.value(7).toLongLong() > 0
                             ? QString::number(query.value(7).toLongLong() / 1024.0, 'f', 1)
                             : "0";

        html += "<tr>";
        html += "<td><strong>" + query.value(0).toString() + "</strong></td>";
        html += "<td>" + query.value(1).toString().toHtmlEscaped() + "</td>";
        html += "<td>" + query.value(2).toString() + "</td>";
        html += "<td>" + query.value(3).toString().toHtmlEscaped() + "</td>";
        html += "<td>" + query.value(4).toString() + "</td>";
        html += "<td>" + query.value(5).toDate().toString("dd/MM/yyyy") + "</td>";
        html += "<td>" + (query.value(6).isNull() ? "Aucun" : query.value(6).toString()) + "</td>";
        html += "<td>" + taille + "</td>";
        html += "</tr>";
    }

    html += R"(
        </table>
        <div class="footer">
            <strong>Total : )" + QString::number(query.size()) + R"( ressources</strong><br>
            © 2025 ARTEMIA - Tous droits réservés
        </div>
    </body>
    </html>
    )";

    QTextDocument doc;
    doc.setHtml(html);

    QPrinter printer;
printer.setPageSize(QPageSize(QPageSize::A4));    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);

    doc.print(&printer);

    QMessageBox::information(this, "Succès", "PDF généré avec succès !\n" + fileName);
}
void ressourceMainWindow::refreshTable()
{
    ui->RessourceTab->setModel(Ressource::afficher());
    ui->RessourceTab->resizeColumnsToContents();
}

void ressourceMainWindow::clearForm()
{
    ui->ID_RESSOURCE->clear();
    ui->TITRE->clear();
    ui->TAGS->clear();
    ui->FORMAT->clear();
    ui->ID_PROJET->clear();
    ui->outputajout->clear();
    ui->labelAffichage->clear();
    ui->DATECREATION->setDate(QDate::currentDate());
    currentFilePath.clear();
    currentFileSize = 0;
}
void ressourceMainWindow::on_RessourceTab_doubleClicked(const QModelIndex &index)
{
    QString id = index.siblingAtColumn(0).data().toString();
    if (id.isEmpty()) return;

    // Récupération du TYPE depuis le tableau (colonne 2)
    QString type = index.siblingAtColumn(2).data().toString().trimmed().toLower();

    QSqlQuery q;
    q.prepare("SELECT FICHIER, FORMAT FROM ARTEMIA.RESSOURCES WHERE ID_RESSOURCE = :id");
    q.bindValue(":id", id);
    if (!q.exec() || !q.next()) return;

    QByteArray data = q.value(0).toByteArray();
    QString format = q.value(1).toString().toLower();
    if (data.isEmpty()) {
        QMessageBox::information(this, "Info", "Aucun fichier joint.");
        return;
    }

    // PRIORITÉ 1 : C'EST UNE VIDÉO ?
    if (type == "video" || type == "vidéo" ||
        format.contains("mp4") || format.contains("avi") || format.contains("mov") ||
        format.contains("mkv") || format.contains("webm")) {

        QTemporaryFile tempFile(QDir::tempPath() + "/artemia_XXXXXX." +
                                (format.contains('.') ? format.split('.').last() : "mp4"));
        if (tempFile.open()) {
            tempFile.write(data);
            tempFile.close();

            QDialog d(this);
            d.setWindowTitle("Lecture Vidéo - " + id);
            d.resize(1000, 700);

            QMediaPlayer *player = new QMediaPlayer(&d);
            QVideoWidget *videoWidget = new QVideoWidget(&d);
            player->setVideoOutput(videoWidget);
            player->setSource(QUrl::fromLocalFile(tempFile.fileName()));

            QVBoxLayout *lay = new QVBoxLayout(&d);
            lay->addWidget(videoWidget);

            // Boutons Play/Pause (optionnel mais joli)
            QHBoxLayout *controls = new QHBoxLayout;
            QPushButton *playBtn = new QPushButton("Play");
            QPushButton *pauseBtn = new QPushButton("Pause");
            controls->addWidget(playBtn);
            controls->addWidget(pauseBtn);
            lay->addLayout(controls);

            connect(playBtn, &QPushButton::clicked, player, &QMediaPlayer::play);
            connect(pauseBtn, &QPushButton::clicked, player, &QMediaPlayer::pause);

            player->play();
            d.exec();
            player->stop();
        }
        return;
    }

    // PRIORITÉ 2 : C'EST UNE IMAGE ?
    if (type == "image" ||
        format.contains("jpg") || format.contains("jpeg") ||
        format.contains("png") || format.contains("gif") ||
        format.contains("bmp") || format.contains("webp")) {

        QPixmap pix;
        if (pix.loadFromData(data)) {
            QLabel *label = new QLabel;
            label->setPixmap(pix.scaled(900, 600, Qt::KeepAspectRatio, Qt::SmoothTransformation));
            label->setAlignment(Qt::AlignCenter);

            QDialog d(this);
            d.setWindowTitle("Aperçu Image - " + id);
            QVBoxLayout *lay = new QVBoxLayout(&d);
            lay->addWidget(label);
            d.resize(950, 650);
            d.exec();
        } else {
            QMessageBox::warning(this, "Erreur", "Impossible de charger l'image.");
        }
        return;
    }

    // Autres cas (audio, PDF, etc.) → ton code actuel
    // ...
}
// Fonction magique de highlight
void ressourceMainWindow::highlightSearchResults(const QString &searchText)
{
    if (searchText.trimmed().isEmpty()) {
        // Réinitialise tout
        for (int row = 0; row < ui->RessourceTab->model()->rowCount(); ++row) {
            ui->RessourceTab->setItemDelegateForRow(row, new QStyledItemDelegate(ui->RessourceTab));
        }
        return;
    }

    QStringList keywords = searchText.toLower().split(' ', Qt::SkipEmptyParts);
    if (keywords.isEmpty()) return;

    QAbstractItemModel *model = ui->RessourceTab->model();

    for (int row = 0; row < model->rowCount(); ++row) {
        bool hasMatch = false;

        for (int col = 0; col < model->columnCount(); ++col) {
            QString cellText = model->index(row, col).data().toString().toLower();

            for (const QString &kw : keywords) {
                if (cellText.contains(kw)) {
                    hasMatch = true;
                    break;
                }
            }
            if (hasMatch) break;
        }

        // Applique le delegate personnalisé avec highlight
        auto *delegate = new QStyledItemDelegate(ui->RessourceTab);
        delegate->setProperty("highlight", hasMatch);
        ui->RessourceTab->setItemDelegateForRow(row, delegate);
    }
}
