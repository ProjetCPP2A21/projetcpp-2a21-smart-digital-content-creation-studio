#include "gestionclient.h"
#include "ui_gestionclient.h"
#include "client.h"
#include <QMessageBox>
#include <QSqlError>
#include <QDebug>

GestionClient::GestionClient(QWidget *parent)
    : QMainWindow(parent)
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

    // Effacer le contenu existant
    ui->tableClients_6->setRowCount(0);
    ui->tableClients_6->setColumnCount(7);
    QStringList headers = {"ID", "Nom", "Email", "Téléphone", "Secteur d'activité", "Pays", "Date d'inscription"};
    ui->tableClients_6->setHorizontalHeaderLabels(headers);

    // Remplir le tableau manuellement
    for (int i = 0; i < model->rowCount(); i++) {
        ui->tableClients_6->insertRow(i);
        for (int j = 0; j < model->columnCount(); j++) {
            QVariant data = model->data(model->index(i, j));
            QString value;

            // Si la colonne est une date, on la formate proprement
            if (data.typeId() == QMetaType::QDate || data.typeId() == QMetaType::QDateTime)
                value = data.toDate().toString("yyyy-MM-dd");
            else
                value = data.toString();

            ui->tableClients_6->setItem(i, j, new QTableWidgetItem(value));

            ui->tableClients_6->setItem(i, j, new QTableWidgetItem(value));
        }
    }
}


// AJOUTER
void GestionClient::on_btnAjouter_3_clicked()
{
    if (ui->leId_6->text().isEmpty()) {
        QMessageBox::warning(this, "Attention", "Veuillez saisir un ID valide !");
        return;
    }

    int id = ui->leId_6->text().toInt();
    QString nom = ui->leNom_6->text();
    QString email = ui->leEmail_6->text();
    QString tel = ui->leTel_6->text();
    QString secteur = ui->cbSecteur_6->currentText();
    QString pays = ui->cbPays_6->currentText();
    QDate dateInscription = QDate::currentDate(); // par défaut, aujourd'hui

    Client c(id, nom, email, tel, secteur, pays, dateInscription);

    bool test = c.ajouter();

    if (test) {
        QMessageBox::information(this, "Succès", "Client ajouté avec succès !");
        refreshTable();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout du client !");
    }
}

// MODIFIER
void GestionClient::on_btnModifier_3_clicked()
{
    if (ui->leId_6->text().isEmpty()) {
        QMessageBox::warning(this, "Attention", "Veuillez saisir un ID valide à modifier !");
        return;
    }

    int id = ui->leId_6->text().toInt();
    QString nom = ui->leNom_6->text();
    QString email = ui->leEmail_6->text();
    QString tel = ui->leTel_6->text();
    QString secteur = ui->cbSecteur_6->currentText();
    QString pays = ui->cbPays_6->currentText();
    QDate dateInscription = QDate::currentDate();

    Client c(id, nom, email, tel, secteur, pays, dateInscription);

    bool test = c.modifier();

    if (test) {
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

    bool test = c.supprimer(id);

    if (test) {
        QMessageBox::information(this, "Succès", "Client supprimé avec succès !");
        refreshTable();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la suppression du client !");
    }
}
