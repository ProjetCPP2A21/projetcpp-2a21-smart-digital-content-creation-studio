#include "gprojet.h"
#include "ui_gprojet.h"
#include "connection.h"
#include "projet.h"
#include <QMessageBox>
#include <QDate>
#include <QDebug>
#include <QSqlQuery>

gprojet::gprojet(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::gprojet)
{
    ui->setupUi(this);

    // Configuration de la table
    ui->tableWidget->setColumnCount(5);
    QStringList headers;
    headers << "Clien" << "Budget Prévu" << "Budget Réalisé" << "Date Début" << "Date Fin";
    ui->tableWidget->setHorizontalHeaderLabels(headers);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);

    // Connexion à la base de données
    Connection connection;
    if (connection.createconnect()) {
        db = connection.getDatabase();
        qDebug() << "✅ Connexion réussie";
        loadProjectsFromDatabase();
    } else {
        QMessageBox::critical(this, "Erreur", "Impossible de se connecter à la base de données.");
    }
}

gprojet::~gprojet()
{
    delete ui;
}

void gprojet::loadProjectsFromDatabase()
{
    qDebug() << "=== CHARGEMENT DES PROJETS ===";

    // Vider la table actuelle
    ui->tableWidget->setRowCount(0);

    // REQUÊTE DIRECTE AVEC LES BONS NOMS DE COLONNES
    QSqlQuery query(db);

    QString sql = "SELECT CLIEN, BUDGET_PREVU, BUDGET_REALISE, DATE_DEBUT, DATE_FIN FROM PROJET ORDER BY CLIEN";
    qDebug() << "Requête:" << sql;

    if (query.exec(sql)) {
        qDebug() << "✅ Requête exécutée avec succès";

        int row = 0;
        while (query.next()) {
            ui->tableWidget->insertRow(row);

            // Récupération avec les bons noms de colonnes
            QString clien = query.value(0).toString();
            double budgetPrevu = query.value(1).toDouble();
            double budgetRealise = query.value(2).toDouble();
            QString dateDebut = query.value(3).toString();
            QString dateFin = query.value(4).toString();

            qDebug() << "📋 Ligne" << row << "- Clien:" << clien;

            ui->tableWidget->setItem(row, 0, new QTableWidgetItem(clien));
            ui->tableWidget->setItem(row, 1, new QTableWidgetItem(QString::number(budgetPrevu, 'f', 2)));
            ui->tableWidget->setItem(row, 2, new QTableWidgetItem(QString::number(budgetRealise, 'f', 2)));
            ui->tableWidget->setItem(row, 3, new QTableWidgetItem(dateDebut));
            ui->tableWidget->setItem(row, 4, new QTableWidgetItem(dateFin));

            row++;
        }

        qDebug() << "✅ Chargement réussi:" << row << "projets affichés";

        if (row == 0) {
            QMessageBox::information(this, "Information", "La table PROJET est vide.");
        }

    } else {
        qDebug() << "❌ Erreur requête:" << query.lastError().text();
        QMessageBox::critical(this, "Erreur", "Erreur chargement: " + query.lastError().text());
    }
}

void gprojet::clearForm()
{
    ui->nomLineEdit->clear();
    ui->budgetPrevuLineEdit->clear();
    ui->budgetRealiseLineEdit->clear();
    ui->dateDebutEdit->clear();
    ui->dateFinEdit->clear();
}

void gprojet::on_addProjectButton_clicked()
{
    QString clien = ui->nomLineEdit->text().trimmed();
    QString budgetPrevuStr = ui->budgetPrevuLineEdit->text().trimmed();
    QString budgetRealiseStr = ui->budgetRealiseLineEdit->text().trimmed();
    QString dateDebutStr = ui->dateDebutEdit->text().trimmed();
    QString dateFinStr = ui->dateFinEdit->text().trimmed();

    qDebug() << "=== AJOUT PROJET ===";
    qDebug() << "Clien:" << clien;

    // Validation
    if (clien.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Le clien est obligatoire !");
        return;
    }

    if (clien.length() > 20) {
        QMessageBox::warning(this, "Erreur", "Le clien ne doit pas dépasser 20 caractères !");
        return;
    }

    // Conversion des budgets
    bool ok1, ok2;
    double budgetPrevu = budgetPrevuStr.toDouble(&ok1);
    double budgetRealise = budgetRealiseStr.toDouble(&ok2);

    if (!ok1 || !ok2) {
        QMessageBox::warning(this, "Erreur", "Les budgets doivent être des nombres valides !");
        return;
    }

    // Validation des dates
    if (dateDebutStr.isEmpty() || dateFinStr.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Les dates sont obligatoires !");
        return;
    }

    // AJOUT DIRECT AVEC LES BONS NOMS DE COLONNES
    QSqlQuery query(db);
    query.prepare("INSERT INTO PROJET (CLIEN, BUDGET_PREVU, BUDGET_REALISE, DATE_DEBUT, DATE_FIN) "
                  "VALUES (:clien, :budget_prev, :budget_real, :date_deb, :date_fin)");

    query.bindValue(":clien", clien);
    query.bindValue(":budget_prev", budgetPrevu);
    query.bindValue(":budget_real", budgetRealise);
    query.bindValue(":date_deb", dateDebutStr);
    query.bindValue(":date_fin", dateFinStr);

    if (query.exec()) {
        qDebug() << "✅✅✅ INSERTION RÉUSSIE !";

        // Vider les champs
        clearForm();

        // Recharger
        loadProjectsFromDatabase();

        QMessageBox::information(this, "Succès", "Projet ajouté avec succès !");
    } else {
        qDebug() << "❌ ERREUR INSERTION:" << query.lastError().text();
        QMessageBox::critical(this, "Erreur", "Erreur: " + query.lastError().text());
    }
}

void gprojet::on_deleteProjectButton_clicked()
{
    int currentRow = ui->tableWidget->currentRow();
    if (currentRow < 0) {
        QMessageBox::warning(this, "Suppression", "Veuillez sélectionner une ligne à supprimer.");
        return;
    }

    QString clien = ui->tableWidget->item(currentRow, 0)->text();

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmation",
                                  "Voulez-vous vraiment supprimer le projet : " + clien + " ?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        QSqlQuery query(db);
        query.prepare("DELETE FROM PROJET WHERE CLIEN = :clien");
        query.bindValue(":clien", clien);

        if (query.exec()) {
            loadProjectsFromDatabase();
            QMessageBox::information(this, "Succès", "Projet supprimé !");
        } else {
            QMessageBox::critical(this, "Erreur", "Erreur suppression !");
        }
    }
}

void gprojet::on_sortByBudgetButton_clicked()
{
    ui->tableWidget->sortItems(1, Qt::DescendingOrder);
}

void gprojet::on_sortByDateButton_clicked()
{
    ui->tableWidget->sortItems(4, Qt::AscendingOrder);
}

void gprojet::on_refreshButton_clicked()
{
    loadProjectsFromDatabase();
    QMessageBox::information(this, "Rafraîchissement", "Données rafraîchies !");
}
