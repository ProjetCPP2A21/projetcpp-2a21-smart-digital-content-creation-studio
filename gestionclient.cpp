#include "gestionclient.h"
#include "ui_gestionclient.h"
#include "client.h"
#include <QMessageBox>
#include <QSqlError>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QFileDialog>
#include <QTextStream>
#include <QLabel>
#include <QDate>
#include <QPdfWriter>
#include <QPainter>

#include <QtCharts/QChartView>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QtCharts/QChart>
#include <QVBoxLayout>




GestionClient::GestionClient(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GestionClient)
{
    ui->setupUi(this);
    refreshTable();
}

GestionClient::~GestionClient()
{
    delete ui;
}



void GestionClient::refreshTable()
{
    Client c;
    QSqlQueryModel *model = c.afficher();
    ui->tableClients_6->setRowCount(0);
    ui->tableClients_6->setColumnCount(8);

    QStringList headers = {"Activité", "ID", "Nom", "Email", "Téléphone", "Secteur d'activité", "Pays", "Date d'inscription"};
    ui->tableClients_6->setHorizontalHeaderLabels(headers);

    QDate today = QDate::currentDate();

    for (int i = 0; i < model->rowCount(); i++) {
        ui->tableClients_6->insertRow(i);

        // Vérifie si le client est inactif (>30 jours)
        QDate dateInscription = model->data(model->index(i, 6)).toDate();
        bool inactif = (dateInscription.daysTo(today) > 30);

        // Création d’une bulle vert pour client actif et rouge pour inactif
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

        // Remplissage des colonnes suivantes
        for (int j = 0; j < model->columnCount(); j++) {
            QVariant data = model->data(model->index(i, j));
            QString value;

            if (data.typeId() == QMetaType::QDate || data.typeId() == QMetaType::QDateTime)
                value = data.toDate().toString("yyyy-MM-dd");
            else
                value = data.toString();

            ui->tableClients_6->setItem(i, j + 1, new QTableWidgetItem(value));
        }
    }

    ui->tableClients_6->resizeColumnsToContents();
    ui->tableClients_6->horizontalHeader()->setStretchLastSection(true);
}






//LE CLIENT S'AFFICHE QUAND ON CLIQUE SUR SON ID
void GestionClient::on_tableClients_6_cellClicked(int row, int column)
{
    Q_UNUSED(column);
    ui->leId_6->setText(ui->tableClients_6->item(row, 1)->text());
    ui->leNom_6->setText(ui->tableClients_6->item(row, 2)->text());
    ui->leEmail_6->setText(ui->tableClients_6->item(row, 3)->text());
    ui->leTel_6->setText(ui->tableClients_6->item(row, 4)->text());
    ui->cbSecteur_6->setCurrentText(ui->tableClients_6->item(row, 5)->text());
    ui->cbPays_6->setCurrentText(ui->tableClients_6->item(row, 6)->text());
    ui->deDate_6->setDate(QDate::fromString(ui->tableClients_6->item(row, 7)->text(), "yyyy-MM-dd"));
}







// === AJOUTER ===
void GestionClient::on_btnAjouter_3_clicked()
{
    if (ui->leId_6->text().isEmpty()) {
        QMessageBox::warning(this, "Attention", "Veuillez saisir un ID valide !");
        return;
    }

    int id = ui->leId_6->text().toInt();
    QString nom = ui->leNom_6->text().trimmed();
    QString email = ui->leEmail_6->text().trimmed();
    QString tel = ui->leTel_6->text().trimmed();
    QString secteur = ui->cbSecteur_6->currentText();
    QString pays = ui->cbPays_6->currentText();
    QDate dateInscription = ui->deDate_6->date();

    // Vérification anti-doublons Oracle
    QSqlQuery check;
    check.prepare("SELECT COUNT(*) FROM CLIENTT WHERE LOWER(NOM)=LOWER(:nom) OR LOWER(EMAIL)=LOWER(:email) OR TELEPHONE=:tel");
    check.bindValue(":nom", nom);
    check.bindValue(":email", email);
    check.bindValue(":tel", tel);

    if (!check.exec()) {
        QMessageBox::critical(this, "Erreur SQL", check.lastError().text());
        return;
    }

    check.next();
    int count = check.value(0).toInt();

    if (count > 0) {
        QMessageBox::warning(this, "Doublon détecté", "Ce client existe déjà.");
        return;
    }

    Client c(id, nom, email, tel, secteur, pays, dateInscription);
    if (c.ajouter()) {
        QMessageBox::information(this, "Succès ", "Client ajouté avec succès !");
        refreshTable();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout du client !");
    }
}







// === MODIFIER ===
void GestionClient::on_btnModifier_3_clicked()
{
    if (ui->leId_6->text().isEmpty()) {
        QMessageBox::warning(this, "Attention", "Veuillez saisir un ID valide à modifier !");
        return;
    }

    int id = ui->leId_6->text().toInt();
    QString nom = ui->leNom_6->text().trimmed();
    QString email = ui->leEmail_6->text().trimmed();
    QString tel = ui->leTel_6->text().trimmed();
    QString secteur = ui->cbSecteur_6->currentText();
    QString pays = ui->cbPays_6->currentText();
    QDate dateInscription = ui->deDate_6->date();

    // Vérification anti-doublons (exclut le client en cours de modif)
    QSqlQuery check;
    check.prepare("SELECT COUNT(*) FROM CLIENTT WHERE (LOWER(NOM)=LOWER(:nom) OR LOWER(EMAIL)=LOWER(:email) OR TELEPHONE=:tel) AND IDCLIENT!=:id");
    check.bindValue(":nom", nom);
    check.bindValue(":email", email);
    check.bindValue(":tel", tel);
    check.bindValue(":id", id);

    if (!check.exec()) {
        QMessageBox::critical(this, "Erreur SQL", check.lastError().text());
        return;
    }

    check.next();
    int count = check.value(0).toInt();

    if (count > 0) {
        QMessageBox::warning(this, "️ Doublon détecté", "Un autre client avec ces informations existe déjà !");
        return;
    }

    Client c(id, nom, email, tel, secteur, pays, dateInscription);
    if (c.modifier()) {
        QMessageBox::information(this, "Succès", "Client modifié avec succès !");
        refreshTable();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la modification du client !");
    }
}







// SUPPRIMER
void GestionClient::on_btnSupprimer_3_clicked()
{
    if (ui->leId_6->text().isEmpty()) {
        QMessageBox::warning(this, "Attention", "Renseigne un ID valide à supprimer.");
        return;
    }

    int id = ui->leId_6->text().toInt();
    Client c;

    if (c.supprimer(id)) {
        QMessageBox::information(this, "Succès", "Client supprimé avec succès !");
        refreshTable();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la suppression du client !");
    }
}







// RECHERCHE
void GestionClient::on_leSearch_6_textChanged(const QString &text)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM CLIENTT "
                  "WHERE LOWER(SECTEURACTIVITE) LIKE LOWER(:rech) "
                  "ORDER BY IDCLIENT ASC");

    query.bindValue(":rech", "%" + text + "%");

    if (!query.exec()) {
        qDebug() << " Erreur recherche :" << query.lastError().text();
        return;
    }

    ui->tableClients_6->setRowCount(0);
    int row = 0;

    while (query.next()) {
        ui->tableClients_6->insertRow(row);
        for (int col = 0; col < 7; col++) {
            QVariant data = query.value(col);
            QString value = (data.typeId() == QMetaType::QDate || data.typeId() == QMetaType::QDateTime)
                                ? data.toDate().toString("yyyy-MM-dd")
                                : data.toString();
            ui->tableClients_6->setItem(row, col + 1, new QTableWidgetItem(value));
        }
        row++;
    }

    ui->tableClients_6->resizeColumnsToContents();
    ui->tableClients_6->horizontalHeader()->setStretchLastSection(true);
}







// EXPORT CSV (inchangé)
void GestionClient::on_pushButton_7_clicked()
{
    QString filePath = QFileDialog::getSaveFileName(this, "Exporter les clients", "", "Fichiers CSV (*.csv)");
    if (filePath.isEmpty()) return;

    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Erreur", "Impossible d’ouvrir le fichier.");
        return;
    }

    QTextStream out(&file);
    out << "ID;Nom;Email;Téléphone;Secteur;Pays;Date d'inscription\n";

    int rowCount = ui->tableClients_6->rowCount();
    int colCount = ui->tableClients_6->columnCount();

    for (int i = 0; i < rowCount; ++i) {
        QStringList rowData;
        for (int j = 1; j < colCount; ++j)
            rowData << (ui->tableClients_6->item(i, j) ? ui->tableClients_6->item(i, j)->text() : "");
        out << rowData.join(";") << "\n";
    }

    file.close();
    QMessageBox::information(this, "Succès", " Exportation terminée avec succès !");
}

