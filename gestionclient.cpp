#include "gestionclient.h"
#include "ui_gestionclient.h"
#include "client.h"
#include "bubblemapwindow.h"

#include <QMessageBox>
#include <QFileDialog>
#include <QPdfWriter>
#include <QPainter>
#include <QRegularExpression>
#include <QLabel>
#include <QDate>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QTimer>


GestionClient::GestionClient(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GestionClient)
{
    ui->setupUi(this);
    QTimer *timerRefresh = new QTimer(this);
    connect(timerRefresh, &QTimer::timeout, this, &GestionClient::refreshTable);
    timerRefresh->start(3000);  // toutes les 3 secondes

    refreshTable();
    mapWindow = new BubbleMapWindow();
}

GestionClient::~GestionClient()
{
    delete ui;
}

//REFRESH TABLE – Affichage clients + statut ACTIF/INACTIF
void GestionClient::refreshTable()
{
    Client c;
    QSqlQueryModel *model = c.getAllClients();

    ui->tableClients_6->setRowCount(0);
    ui->tableClients_6->setColumnCount(8);

    QStringList headers = {
        "Activité", "ID", "Nom", "Email",
        "Téléphone", "Secteur d'activité",
        "Pays", "Date d'inscription"
    };
    ui->tableClients_6->setHorizontalHeaderLabels(headers);

    for (int i = 0; i < model->rowCount(); ++i)
    {
        ui->tableClients_6->insertRow(i);

        int idClient = model->data(model->index(i, 0)).toInt();

        //  Info projet depuis client.cpp (SQL uniquement là-bas)
        QSqlQuery info = c.getProjetInfo(idClient);
        info.next();
        int duree = info.value("duree").toInt();
        bool enCours = info.value("enCours").toInt();
        bool inactif = (!enCours && duree < 30);

        // Bulle activité (colonne 0)
        QWidget *cellWidget = new QWidget();
        QHBoxLayout *layout = new QHBoxLayout(cellWidget);
        layout->setContentsMargins(0, 0, 0, 0);
        layout->setAlignment(Qt::AlignCenter);

        QLabel *bubble = new QLabel();
        bubble->setFixedSize(14, 14);
        bubble->setStyleSheet(QString("border-radius:7px; background-color:%1;")
                                  .arg(inactif ? "#E53935" : "#43A047"));
        layout->addWidget(bubble);
        ui->tableClients_6->setCellWidget(i, 0, cellWidget);

        // Autres colonnes
        for (int j = 0; j < model->columnCount(); ++j)
        {
            QVariant data = model->data(model->index(i, j));
            QString value;

            if (data.typeId() == QMetaType::QDate ||
                data.typeId() == QMetaType::QDateTime)
                value = data.toDate().toString("yyyy-MM-dd");
            else
                value = data.toString();

            ui->tableClients_6->setItem(i, j + 1, new QTableWidgetItem(value));
        }
    }

    ui->tableClients_6->resizeColumnsToContents();
    ui->tableClients_6->horizontalHeader()->setStretchLastSection(true);
}




//SELECTION D’UN CLIENT DANS LE TABLEAU
void GestionClient::on_tableClients_6_cellClicked(int row, int column)
{
    Q_UNUSED(column);
    refreshTable();

    ui->leId_6->setText(ui->tableClients_6->item(row, 1)->text());
    ui->leNom_6->setText(ui->tableClients_6->item(row, 2)->text());
    ui->leEmail_6->setText(ui->tableClients_6->item(row, 3)->text());
    ui->leTel_6->setText(ui->tableClients_6->item(row, 4)->text());
    ui->cbSecteur_6->setCurrentText(ui->tableClients_6->item(row, 5)->text());
    ui->cbPays_6->setCurrentText(ui->tableClients_6->item(row, 6)->text());
    ui->deDate_6->setDate(QDate::fromString(
        ui->tableClients_6->item(row, 7)->text(), "yyyy-MM-dd"));
}



//AJOUTER UN CLIENT

void GestionClient::on_btnAjouter_3_clicked()
{
    QString idStr = ui->leId_6->text().trimmed();
    QString nom = ui->leNom_6->text().trimmed();
    QString email = ui->leEmail_6->text().trimmed();
    QString tel = ui->leTel_6->text().trimmed();
    QString secteur = ui->cbSecteur_6->currentText();
    QString pays = ui->cbPays_6->currentText();
    QDate dateInscription = ui->deDate_6->date();

    QRegularExpression regexId("^[0-9]{8}$");
    QRegularExpression regexTel("^[0-9]{8}$");
    QRegularExpression regexNom("^[A-Za-zÀ-ÖØ-öø-ÿ\\s]+$");
    QRegularExpression regexEmail("^[\\w._%+-]+@[\\w.-]+\\.[A-Za-z]{2,}$");

    if (!regexId.match(idStr).hasMatch())
    {
        QMessageBox::warning(this, "Erreur",
                             "L'ID doit contenir exactement 8 chiffres.");
        return;
    }
    if (!regexNom.match(nom).hasMatch())
    {
        QMessageBox::warning(this, "Erreur", "Nom invalide.");
        return;
    }
    if (!regexEmail.match(email).hasMatch())
    {
        QMessageBox::warning(this, "Erreur", "Email invalide.");
        return;
    }
    if (!regexTel.match(tel).hasMatch())
    {
        QMessageBox::warning(this, "Erreur", "Téléphone invalide.");
        return;
    }

    int id = idStr.toInt();

    // Vérif doublon ID via le modèle (toujours sans SQL ici)
    Client checker;
    QSqlQueryModel *all = checker.getAllClients();
    for (int i = 0; i < all->rowCount(); ++i)
    {
        if (all->data(all->index(i, 0)).toInt() == id)
        {
            QMessageBox::warning(this, "Erreur",
                                 "Cet ID existe déjà !");
            return;
        }
    }

    Client c(id, nom, email, tel, secteur, pays, dateInscription);

    if (c.ajouter())
    {
        QMessageBox::information(this, "Succès", "Client ajouté !");
        refreshTable();
    }
    else
    {
        QMessageBox::critical(this, "Erreur",
                              "Échec de l'ajout du client.");
    }
}





//MODIFIER UN CLIENT
void GestionClient::on_btnModifier_3_clicked()
{
    QString idStr = ui->leId_6->text().trimmed();
    QString nom = ui->leNom_6->text().trimmed();
    QString email = ui->leEmail_6->text().trimmed();
    QString tel = ui->leTel_6->text().trimmed();
    QString secteur = ui->cbSecteur_6->currentText();
    QString pays = ui->cbPays_6->currentText();
    QDate dateInscription = ui->deDate_6->date();

    if (idStr.isEmpty())
    {
        QMessageBox::warning(this, "Erreur",
                             "Sélectionnez un client.");
        return;
    }

    QRegularExpression regexId("^[0-9]{8}$");
    QRegularExpression regexTel("^[0-9]{8}$");
    QRegularExpression regexNom("^[A-Za-zÀ-ÖØ-öø-ÿ\\s]+$");
    QRegularExpression regexEmail("^[\\w._%+-]+@[\\w.-]+\\.[A-Za-z]{2,}$");

    if (!regexId.match(idStr).hasMatch() ||
        !regexNom.match(nom).hasMatch() ||
        !regexEmail.match(email).hasMatch() ||
        !regexTel.match(tel).hasMatch())
    {
        QMessageBox::warning(this, "Erreur", "Champs invalides !");
        return;
    }

    int id = idStr.toInt();

    Client c(id, nom, email, tel, secteur, pays, dateInscription);

    if (c.modifier())
    {
        QMessageBox::information(this, "Succès", "Client modifié !");
        refreshTable();
    }
    else
    {
        QMessageBox::critical(this, "Erreur",
                              "Échec de la modification.");
    }
}





//SUPPRIMER UN CLIENT
void GestionClient::on_btnSupprimer_3_clicked()
{
    if (ui->leId_6->text().isEmpty())
    {
        QMessageBox::warning(this, "Erreur",
                             "Sélectionnez un client.");
        return;
    }

    int id = ui->leId_6->text().toInt();
    Client c;

    if (c.supprimer(id))
    {
        QMessageBox::information(this, "Succès", "Client supprimé !");
        refreshTable();
    }
    else
    {
        QMessageBox::critical(this, "Erreur",
                              "Suppression impossible.");
    }
}






//RECHERCHE PAR SECTEUR
void GestionClient::on_leSearch_6_textChanged(const QString &text)
{
    Client c;
    QSqlQueryModel *model = c.rechercheSecteur(text);

    ui->tableClients_6->setRowCount(0);
    ui->tableClients_6->setColumnCount(8);

    // On ne recalcule pas activité ici (recherche simple)
    for (int i = 0; i < model->rowCount(); ++i)
    {
        ui->tableClients_6->insertRow(i);

        for (int j = 0; j < model->columnCount(); ++j)
        {
            QVariant data = model->data(model->index(i, j));
            QString value =
                (data.typeId() == QMetaType::QDate)
                    ? data.toDate().toString("yyyy-MM-dd")
                    : data.toString();

            ui->tableClients_6->setItem(i, j + 1,
                                        new QTableWidgetItem(value));
        }
    }

    ui->tableClients_6->resizeColumnsToContents();
}







//TRI PAR DATE D’INSCRIPTION
void GestionClient::on_pushButton_9_clicked()
{
    Client c;
    QSqlQueryModel *model = c.getClientsTries();

    ui->tableClients_6->setRowCount(0);
    ui->tableClients_6->setColumnCount(8);

    for (int i = 0; i < model->rowCount(); ++i)
    {
        ui->tableClients_6->insertRow(i);

        int idClient = model->data(model->index(i, 0)).toInt();

        // Statut via getProjetInfo
        QSqlQuery info = c.getProjetInfo(idClient);
        info.next();
        int duree = info.value("duree").toInt();
        bool enCours = info.value("enCours").toInt();
        bool inactif = (!enCours && duree < 30);

        QWidget *cellWidget = new QWidget();
        QHBoxLayout *layout = new QHBoxLayout(cellWidget);
        layout->setContentsMargins(0, 0, 0, 0);
        layout->setAlignment(Qt::AlignCenter);

        QLabel *bubble = new QLabel();
        bubble->setFixedSize(14, 14);
        bubble->setStyleSheet(QString("border-radius:7px; background-color:%1;")
                                  .arg(inactif ? "#E53935" : "#43A047"));
        layout->addWidget(bubble);
        ui->tableClients_6->setCellWidget(i, 0, cellWidget);

        for (int j = 0; j < model->columnCount(); ++j)
        {
            QVariant data = model->data(model->index(i, j));
            QString value =
                (data.typeId() == QMetaType::QDate)
                    ? data.toDate().toString("yyyy-MM-dd")
                    : data.toString();

            ui->tableClients_6->setItem(i, j + 1,
                                        new QTableWidgetItem(value));
        }
    }

    ui->tableClients_6->resizeColumnsToContents();
}






//EXPORT PDF – LISTE DE TOUS LES CLIENTS
void GestionClient::on_pushButton_7_clicked()
{
    Client c;
    QSqlQueryModel *model = c.getAllClients();

    QString filePath = QFileDialog::getSaveFileName(
        this, "Exporter PDF", "", "PDF (*.pdf)");
    if (filePath.isEmpty())
        return;

    QPdfWriter pdf(filePath);
    pdf.setPageSize(QPageSize(QPageSize::A4));
    pdf.setResolution(300);

    QPainter painter(&pdf);
    painter.setRenderHint(QPainter::Antialiasing);

    QColor mauve(147, 112, 219), orange(255, 140, 0),
        mauveLight(230, 220, 240), orangeLight(255, 245, 230);

    // Titre
    painter.setFont(QFont("Arial", 18, QFont::Bold));
    painter.setPen(orange);
    painter.drawText(QRect(0, 200, pdf.width(), 100),
                     Qt::AlignCenter, "Liste des clients");
    painter.setPen(QPen(mauve, 3));
    painter.drawLine(200, 350, pdf.width() - 200, 350);

    int x = -25, y = 500, h = 120;
    int w[] = {250, 330, 550, 250, 610, 250, 260};

    QStringList headers = {"ID", "Nom", "Email", "Tél",
                           "Secteur", "Ville", "Date"};

    // En-tête
    painter.setFont(QFont("Arial", 10, QFont::Bold));
    painter.setBrush(mauve);
    painter.drawRect(x, y,
                     w[0] + w[1] + w[2] + w[3] + w[4] + w[5] + w[6], h);
    painter.setPen(Qt::white);

    int cx = x;
    for (int i = 0; i < 7; ++i)
    {
        painter.drawText(QRect(cx, y, w[i], h),
                         Qt::AlignCenter, headers[i]);
        cx += w[i];
    }
    y += h;

    painter.setFont(QFont("Arial", 9));

    for (int i = 0; i < model->rowCount(); ++i)
    {
        int idClient = model->data(model->index(i, 0)).toInt();

        // Statut inactif ? (pour colorer la ligne)
        QSqlQuery info = c.getProjetInfo(idClient);
        info.next();
        int duree = info.value("duree").toInt();
        bool enCours = info.value("enCours").toInt();
        bool inactif = (!enCours && duree < 30);

        QColor bg = inactif ? QColor(255, 220, 220)
                            : (i % 2 == 0 ? mauveLight : orangeLight);
        painter.fillRect(x, y,
                         w[0] + w[1] + w[2] + w[3] + w[4] + w[5] + w[6],
                         h, bg);
        painter.setPen(inactif ? QColor(200, 0, 0) : Qt::black);

        cx = x;
        for (int j = 0; j < 7; ++j)
        {
            QVariant data = model->data(model->index(i, j));
            QString val =
                (j == 6)
                    ? data.toDate().toString("dd/MM/yyyy")
                    : data.toString();

            painter.drawText(QRect(cx + 5, y, w[j] - 10, h),
                             Qt::AlignVCenter | Qt::AlignLeft, val);
            cx += w[j];
        }

        y += h;

        if (y > pdf.height() - 400)
        {
            pdf.newPage();
            y = 200;
        }
    }

    painter.setFont(QFont("Arial", 9, -1, true));
    painter.setPen(orange);
    painter.drawText(100, pdf.height() - 150,
                     "Généré le : " +
                         QDate::currentDate().toString("dd/MM/yyyy"));

    painter.end();
    QMessageBox::information(this, "PDF", "Exporté !");
}








//EXPORT PDF – CLIENTS INACTIFS
void GestionClient::on_pushButton_6_clicked()
{
    Client c;
    QSqlQueryModel *model = c.getAllClients();

    QString filePath = QFileDialog::getSaveFileName(
        this, "Exporter PDF des clients inactifs", "",
        "Fichiers PDF (*.pdf)");
    if (filePath.isEmpty())
        return;

    QPdfWriter pdf(filePath);
    pdf.setPageSize(QPageSize(QPageSize::A4));
    pdf.setResolution(300);

    QPainter painter(&pdf);
    painter.setRenderHint(QPainter::Antialiasing);

    QColor mauveHeader(147, 112, 219);
    QColor orangeAccent(255, 140, 0);
    QColor mauveLight(230, 220, 240);
    QColor orangeLight(255, 245, 230);

    painter.setFont(QFont("Arial", 18, QFont::Bold));
    painter.setPen(orangeAccent);
    painter.drawText(QRect(0, 200, pdf.width(), 100),
                     Qt::AlignCenter,
                     "Liste des clients inactifs (projets < 30 jours)");
    painter.setPen(QPen(mauveHeader, 3));
    painter.drawLine(200, 350, pdf.width() - 200, 350);

    int startX = 200;
    int y = 500;
    int rowHeight = 100;

    int colIdWidth = 180;
    int colNomWidth = 450;
    int colEmailWidth = 700;
    int colDureeWidth = 570;

    painter.setFont(QFont("Arial", 12, QFont::Bold));
    painter.setPen(Qt::white);
    painter.setBrush(mauveHeader);
    painter.drawRect(startX, y,
                     colIdWidth + colNomWidth + colEmailWidth + colDureeWidth,
                     rowHeight);

    painter.setBrush(Qt::NoBrush);
    painter.setPen(QPen(mauveHeader, 2));

    painter.drawRect(startX, y, colIdWidth, rowHeight);
    painter.drawRect(startX + colIdWidth, y, colNomWidth, rowHeight);
    painter.drawRect(startX + colIdWidth + colNomWidth, y, colEmailWidth,
                     rowHeight);
    painter.drawRect(startX + colIdWidth + colNomWidth + colEmailWidth, y,
                     colDureeWidth, rowHeight);

    painter.setPen(Qt::white);
    painter.drawText(QRect(startX, y, colIdWidth, rowHeight),
                     Qt::AlignCenter, "ID");
    painter.drawText(QRect(startX + colIdWidth, y, colNomWidth, rowHeight),
                     Qt::AlignCenter, "Nom");
    painter.drawText(QRect(startX + colIdWidth + colNomWidth, y,
                           colEmailWidth, rowHeight),
                     Qt::AlignCenter, "Email");
    painter.drawText(QRect(startX + colIdWidth + colNomWidth + colEmailWidth,
                           y, colDureeWidth, rowHeight),
                     Qt::AlignCenter, "Durée max projet");

    painter.setFont(QFont("Arial", 10));
    y += rowHeight;

    int ligne = 0;

    for (int i = 0; i < model->rowCount(); ++i)
    {
        int idClient = model->data(model->index(i, 0)).toInt();
        QString nom = model->data(model->index(i, 1)).toString();
        QString email = model->data(model->index(i, 2)).toString();

        QSqlQuery info = c.getProjetInfo(idClient);
        info.next();
        int duree = info.value("duree").toInt();
        bool enCours = info.value("enCours").toInt();
        bool inactif = (!enCours && duree < 30);

        if (!inactif)
            continue;

        QColor bg = (ligne % 2 == 0) ? mauveLight : orangeLight;
        painter.fillRect(startX, y,
                         colIdWidth + colNomWidth + colEmailWidth +
                             colDureeWidth,
                         rowHeight, bg);

        painter.setPen(QPen(mauveHeader, 1));
        painter.drawRect(startX, y, colIdWidth, rowHeight);
        painter.drawRect(startX + colIdWidth, y, colNomWidth, rowHeight);
        painter.drawRect(startX + colIdWidth + colNomWidth, y,
                         colEmailWidth, rowHeight);
        painter.drawRect(startX + colIdWidth + colNomWidth + colEmailWidth, y,
                         colDureeWidth, rowHeight);

        painter.setPen(Qt::black);
        painter.drawText(QRect(startX + 20, y, colIdWidth - 40, rowHeight),
                         Qt::AlignVCenter | Qt::AlignLeft,
                         QString::number(idClient));
        painter.drawText(QRect(startX + colIdWidth + 20, y,
                               colNomWidth - 40, rowHeight),
                         Qt::AlignVCenter | Qt::AlignLeft, nom);
        painter.drawText(QRect(startX + colIdWidth + colNomWidth + 20, y,
                               colEmailWidth - 40, rowHeight),
                         Qt::AlignVCenter | Qt::AlignLeft, email);
        painter.drawText(QRect(startX + colIdWidth + colNomWidth +
                                   colEmailWidth + 20,
                               y, colDureeWidth - 40, rowHeight),
                         Qt::AlignVCenter | Qt::AlignLeft,
                         QString::number(duree) + " jours");

        y += rowHeight;
        ++ligne;

        if (y > pdf.height() - 300)
        {
            pdf.newPage();
            y = 200;
        }
    }

    painter.setFont(QFont("Arial", 9, -1, true));
    painter.setPen(orangeAccent);
    painter.drawText(
        200, pdf.height() - 150,
        "Généré le : " + QDate::currentDate().toString("dd/MM/yyyy"));

    painter.end();
    QMessageBox::information(this, "PDF",
                             "PDF généré avec succès !");
}








//FICHE CLIENT – PDF DÉTAILLÉ
void GestionClient::on_pushButton_11_clicked()
{
    if (ui->leId_6->text().isEmpty())
    {
        QMessageBox::warning(this, "Erreur",
                             "Sélectionnez un client d'abord.");
        return;
    }

    int idClient = ui->leId_6->text().toInt();
    Client c;

    QString filePath = QFileDialog::getSaveFileName(
        this, "Exporter Fiche Client", "", "PDF (*.pdf)");
    if (filePath.isEmpty())
        return;

    QPdfWriter pdf(filePath);
    pdf.setPageSize(QPageSize(QPageSize::A4));
    pdf.setResolution(300);

    QPainter painter(&pdf);
    painter.setRenderHint(QPainter::Antialiasing);

    QColor mauve(147, 112, 219), orange(255, 140, 0),
        mauveLight(230, 220, 240), orangeLight(255, 245, 230);

    painter.setFont(QFont("Arial", 20, QFont::Bold));
    painter.setPen(orange);
    painter.drawText(QRect(0, 200, pdf.width(), 100),
                     Qt::AlignCenter, "FICHE CLIENT");
    painter.setPen(QPen(mauve, 3));
    painter.drawLine(200, 300, pdf.width() - 200, 300);

    int x = 100, y = 380, h = 60;

    painter.setFont(QFont("Arial", 12, QFont::Bold));
    painter.setPen(mauve);
    painter.drawText(x, y, "Informations du client");
    y += 40;

    // ➜ Projets du client (pour trouver dernière date_fin)
    QSqlQueryModel *projModel = c.getProjetsDuClient(idClient);
    QDate lastEnd;
    for (int i = 0; i < projModel->rowCount(); ++i)
    {
        QDate fin = projModel->data(projModel->index(i, 2)).toDate();
        if (!fin.isValid())
            continue;
        if (!lastEnd.isValid() || fin > lastEnd)
            lastEnd = fin;
    }

    QString statut = "ACTIF";
    if (lastEnd.isValid())
    {
        int daysInactive = lastEnd.daysTo(QDate::currentDate());
        if (daysInactive > 0)
            statut = "INACTIF depuis " + lastEnd.toString("dd/MM/yyyy");
    }

    QStringList labels = {"ID Client", "Nom", "Email", "Téléphone",
                          "Secteur",  "Ville",
                          "Date d'inscription"};

    QStringList values = {
        ui->leId_6->text(),
        ui->leNom_6->text(),
        ui->leEmail_6->text(),
        ui->leTel_6->text(),
        ui->cbSecteur_6->currentText(),
        ui->cbPays_6->currentText(),
        ui->deDate_6->date().toString("dd/MM/yyyy"),
    };

    int labelW = 450;
    int valueW = 650;

    for (int i = 0; i < labels.size(); ++i)
    {
        QColor bg = (i % 2 == 0 ? mauveLight : orangeLight);
        painter.fillRect(x, y, labelW + valueW, h, bg);

        painter.setPen(Qt::black);
        painter.setFont(QFont("Arial", 10, QFont::Bold));
        painter.drawText(QRect(x + 10, y, labelW - 20, h),
                         Qt::AlignVCenter | Qt::AlignLeft,
                         labels[i] + " :");

        painter.setFont(QFont("Arial", 10));
        painter.drawText(QRect(x + labelW + 10, y, valueW - 20, h),
                         Qt::AlignVCenter | Qt::AlignLeft,
                         values[i]);

        y += h;
    }

    y += 60;

    // SECTION PROJETS
    painter.setFont(QFont("Arial", 12, QFont::Bold));
    painter.setPen(mauve);
    painter.drawText(x, y, "Projets associés");
    y += 40;

    int w[] = {250, 350, 350, 350, 350};
    QStringList headers = {"ID", "Début", "Fin", "Budget", "Statut"};

    painter.setBrush(mauve);
    painter.setPen(Qt::white);
    painter.drawRect(x, y,
                     w[0] + w[1] + w[2] + w[3] + w[4], h);

    int cx = x;
    painter.setFont(QFont("Arial", 10, QFont::Bold));
    for (int i = 0; i < 5; ++i)
    {
        painter.drawText(QRect(cx, y, w[i], h),
                         Qt::AlignCenter, headers[i]);
        cx += w[i];
    }
    y += h;

    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial", 10));
    int rowIndex = 0;

    for (int i = 0; i < projModel->rowCount(); ++i)
    {
        QColor bg = (rowIndex % 2 == 0 ? mauveLight : orangeLight);
        painter.fillRect(x, y,
                         w[0] + w[1] + w[2] + w[3] + w[4], h, bg);

        cx = x;

        painter.drawText(QRect(cx + 5, y, w[0], h),
                         Qt::AlignVCenter | Qt::AlignLeft,
                         projModel->data(projModel->index(i, 0)).toString());
        cx += w[0];

        painter.drawText(QRect(cx + 5, y, w[1], h),
                         Qt::AlignVCenter | Qt::AlignLeft,
                         projModel->data(projModel->index(i, 1))
                             .toDate()
                             .toString("dd/MM/yyyy"));
        cx += w[1];

        painter.drawText(QRect(cx + 5, y, w[2], h),
                         Qt::AlignVCenter | Qt::AlignLeft,
                         projModel->data(projModel->index(i, 2))
                             .toDate()
                             .toString("dd/MM/yyyy"));
        cx += w[2];

        painter.drawText(QRect(cx + 5, y, w[3], h),
                         Qt::AlignVCenter | Qt::AlignLeft,
                         projModel->data(projModel->index(i, 3)).toString() +
                             " DT");
        cx += w[3];

        painter.drawText(QRect(cx + 5, y, w[4], h),
                         Qt::AlignVCenter | Qt::AlignLeft,
                         projModel->data(projModel->index(i, 4)).toString());

        y += h;
        ++rowIndex;
    }

    painter.setFont(QFont("Arial", 8, QFont::StyleItalic));
    painter.setPen(QColor(120, 120, 120));
    painter.drawText(
        QRect(100, pdf.height() - 120, pdf.width() - 200, 40),
        Qt::AlignCenter,
        "Document généré automatiquement - SDCCS - " +
            QDate::currentDate().toString("dd/MM/yyyy"));

    painter.end();
    QMessageBox::information(this, "PDF", "Fiche client exportée !");
}









//MAP GÉO CLIENTS – UTILISE Client::getNomsEtVilles()
void GestionClient::on_pushButton_10_clicked()
{
    Client c;
    QSqlQueryModel *model = c.getNomsEtVilles();

    mapWindow->clearClients();

    for (int i = 0; i < model->rowCount(); ++i)
    {
        QString nom =
            model->data(model->index(i, 0)).toString().trimmed();
        QString ville =
            model->data(model->index(i, 1)).toString().trimmed();

        if (!nom.isEmpty() && !ville.isEmpty())
            mapWindow->addClient(nom, ville);
    }

    mapWindow->show();
}









//STATISTIQUES – TOP 3 SECTEURS D’ACTIVITÉ
void GestionClient::on_pushButton_8_clicked()
{
    Client c;
    QSqlQueryModel *model = c.getAllClients();

    QMap<QString, int> counts;
    int totalGlobal = 0;

    for (int i = 0; i < model->rowCount(); ++i)
    {
        QString secteur =
            model->data(model->index(i, 4)).toString().trimmed();

        if (secteur.isEmpty() || secteur == " " ||
            secteur.toLower() == "null")
            continue;

        counts[secteur]++;
        totalGlobal++;
    }

    if (counts.isEmpty())
    {
        QMessageBox::information(
            this, "Info",
            "Aucun secteur valide trouvé.\n"
            "Veuillez ajouter des secteurs dans vos clients.");
        return;
    }

    // Trier par nombre décroissant
    QList<QPair<QString, int>> liste;
    for (auto it = counts.begin(); it != counts.end(); ++it)
        liste.append(qMakePair(it.key(), it.value()));

    std::sort(liste.begin(), liste.end(),
              [](const QPair<QString, int> &a,
                 const QPair<QString, int> &b) {
                  return a.second > b.second;
              });

    int max = qMin(3, liste.size());

    QPieSeries *series = new QPieSeries();
    series->setHoleSize(0.45);
    series->setPieSize(0.90);

    QList<QColor> colors = {QColor("#0A1A2F"), QColor("#FB8C00"),
                            QColor("#9C27B0")};

    for (int i = 0; i < max; ++i)
    {
        int value = liste[i].second;
        QPieSlice *slice = series->append("", value);

        QLinearGradient grad;
        grad.setStart(0, 0);
        grad.setFinalStop(1, 1);
        grad.setColorAt(0, colors[i].lighter(130));
        grad.setColorAt(1, colors[i].darker(110));
        slice->setBrush(grad);

        slice->setPen(QPen(Qt::white, 4));
        connect(slice, &QPieSlice::hovered, slice,
                [slice](bool state) {
                    slice->setExploded(state);
                    slice->setExplodeDistanceFactor(state ? 0.12
                                                          : 0.06);
                });
        slice->setExploded(true);
        slice->setExplodeDistanceFactor(0.06);
    }

    series->setLabelsVisible(false);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle(
        "Top 3 secteurs d'activité les plus fréquents");
    chart->setTitleFont(QFont("Segoe UI", 16, QFont::Bold));
    chart->legend()->hide();
    chart->setDropShadowEnabled(true);
    chart->setBackgroundBrush(QColor("#EDEAF9"));
    chart->setBackgroundRoundness(20);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setStyleSheet("background: transparent;"
                             "border-radius: 20px;");

    QWidget *legendWidget = new QWidget();
    QVBoxLayout *legendLayout = new QVBoxLayout(legendWidget);

    for (int i = 0; i < max; ++i)
    {
        QString secteur = liste[i].first;
        int count = liste[i].second;
        double percent =
            ((double)count / (double)totalGlobal) * 100.0;

        QLabel *label = new QLabel();
        QString bullet = QString(
                             "<span style='font-size:22px; "
                             "color:%1;'>●</span>")
                             .arg(colors[i].name());

        QString html =
            QString("%1 <b style='font-size:16px; color:%2;'>%3</b><br>"
                    "<span style='color:%2; font-size:13px;'>%4 "
                    "clients — %5%</span>")
                .arg(bullet)
                .arg(colors[i].name())
                .arg(secteur)
                .arg(count)
                .arg(QString::number(percent, 'f', 1));

        label->setText(html);
        label->setWordWrap(true);
        label->setStyleSheet("padding: 6px;");

        legendLayout->addWidget(label);
    }

    QWidget *container = new QWidget();
    QHBoxLayout *hLayout = new QHBoxLayout(container);

    hLayout->addWidget(chartView, 3);
    hLayout->addWidget(legendWidget, 1);
    hLayout->setSpacing(30);

    container->setStyleSheet("background-color: #EDEAF9;"
                             "border-radius: 25px;"
                             "padding: 20px;");

    QDialog *dialog = new QDialog(this);
    dialog->setWindowTitle(
        "Statistiques - Secteurs d'activité");
    dialog->resize(1000, 650);

    QVBoxLayout *mainLayout = new QVBoxLayout(dialog);
    mainLayout->addWidget(container);

    dialog->exec();
}
