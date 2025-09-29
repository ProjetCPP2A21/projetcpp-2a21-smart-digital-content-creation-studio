#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Initialisation du tableau
    ui->tableWidget->setColumnCount(6);
    QStringList headers = {"ID", "Titre", "Type", "Taille", "Format", "Date d'import"};
    ui->tableWidget->setHorizontalHeaderLabels(headers);
    ui->tableWidget->setAlternatingRowColors(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnAjouter_clicked()
{
    int row = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(row);

    ui->tableWidget->setItem(row, 0, new QTableWidgetItem(QString::number(row+1)));
    ui->tableWidget->setItem(row, 1, new QTableWidgetItem("Nouveau média"));
    ui->tableWidget->setItem(row, 2, new QTableWidgetItem("Image"));
    ui->tableWidget->setItem(row, 3, new QTableWidgetItem("2 MB"));
    ui->tableWidget->setItem(row, 4, new QTableWidgetItem("PNG"));
    ui->tableWidget->setItem(row, 5, new QTableWidgetItem("2025-09-29"));
}

void MainWindow::on_btnModifier_clicked()
{
    QMessageBox::information(this, "Modifier", "Fonction de modification à implémenter");
}

void MainWindow::on_btnSupprimer_clicked()
{
    int row = ui->tableWidget->currentRow();
    if(row >= 0) {
        ui->tableWidget->removeRow(row);
    } else {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner une ligne à supprimer");
    }
}

void MainWindow::on_btnExporter_clicked()
{
    QString file = QFileDialog::getSaveFileName(this, "Exporter en CSV", "", "Fichiers CSV (*.csv)");
    if(file.isEmpty()) return;

    QFile f(file);
    if(f.open(QIODevice::WriteOnly)) {
        QTextStream out(&f);
        for(int i=0; i<ui->tableWidget->rowCount(); i++) {
            QStringList rowContent;
            for(int j=0; j<ui->tableWidget->columnCount(); j++) {
                QTableWidgetItem *item = ui->tableWidget->item(i,j);
                rowContent << (item ? item->text() : "");
            }
            out << rowContent.join(",") << "\n";
        }
        f.close();
        QMessageBox::information(this, "Export", "Exportation terminée !");
    }
}
