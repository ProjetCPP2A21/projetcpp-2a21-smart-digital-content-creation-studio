#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Connecter le bouton "Ajouter projet" au slot
    connect(ui->addProjectButton, &QPushButton::clicked, this, &MainWindow::on_addProjectButton_clicked);
    // Connecter le bouton "Supprimer projet" au slot
    connect(ui->deleteProjectButton, &QPushButton::clicked, this, &MainWindow::on_deleteProjectButton_clicked);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_addProjectButton_clicked() {
    // Récupérer les valeurs des champs
    QString client = ui->clientLineEdit->text();
    QString dateDebut = ui->dateDebutLineEdit->text();
    QString dateFin = ui->dateFinLineEdit->text();
    QString budgetPrevu = ui->budgetPrevuLineEdit->text();
    QString budgetRealise = ui->budgetRealiseLineEdit->text();

    // Ajouter une nouvelle ligne au tableau
    int rowCount = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(rowCount);

    // Ajouter les données dans les cellules
    ui->tableWidget->setItem(rowCount, 0, new QTableWidgetItem(dateDebut));
    ui->tableWidget->setItem(rowCount, 1, new QTableWidgetItem(budgetPrevu));
    ui->tableWidget->setItem(rowCount, 2, new QTableWidgetItem(budgetRealise));
    ui->tableWidget->setItem(rowCount, 3, new QTableWidgetItem(dateFin));

    // Optionnel : Vider les champs après ajout
    ui->clientLineEdit->clear();
    ui->dateDebutLineEdit->clear();
    ui->dateFinLineEdit->clear();
    ui->budgetPrevuLineEdit->clear();
    ui->budgetRealiseLineEdit->clear();
}

void MainWindow::on_deleteProjectButton_clicked() {
    // Récupérer la ligne sélectionnée
    QList<QTableWidgetItem*> selectedItems = ui->tableWidget->selectedItems();
    if (!selectedItems.isEmpty()) {
        // Supprimer la ligne correspondant à la première cellule sélectionnée
        int rowToDelete = selectedItems.first()->row();
        ui->tableWidget->removeRow(rowToDelete);
    }
}
