#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qpushbutton.h"
#include <QMainWindow>
#include "ui_mainwindow.h"
#include "Employe.h"
#include "client.h"
#include "projet.h"
#include <QTableWidgetItem>
#include <QDate>
#include <QPalette>
#include <QColor>
#include <QPixmap>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // Employés
    void ajouterEmploye();
    void supprimerEmploye();
    void rechercherEmploye();
    void afficherEmployes(QSqlQueryModel *model);
    void trierParPoste();
    void exportEmployes();
    void afficherStatistiques();
    void onItemChanged(QTableWidgetItem *item);

    // Clients
    void on_tableClients_6_cellClicked(int row, int column);
    void on_btnAjouter_3_clicked();
    void on_btnModifier_3_clicked();
    void on_btnSupprimer_3_clicked();
    void on_leSearch_6_textChanged(const QString &text);
    void on_pushButton_7_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_8_clicked();

    // Projets
    void on_btnAjouterProjet_clicked();
    void on_btnModifierProjet_clicked();
    void on_btnSupprimerProjet_clicked();
    void on_btnTriBudgetProjet_clicked();
    void on_btnTriDateProjet_clicked();
    void on_btnRafraichirProjet_clicked();
    void on_btnAnnulerModifProjet_clicked();
    void on_tableProjets_cellClicked(int row, int column);

    // Navigation
    void on_pushButton_client_clicked();

private:
    Ui::MainWindow *ui;
    QToolBar *m_tb = nullptr;
    bool isModifyingProjet;
    QString currentModifyClient;

    void setActiveButton(QPushButton *btn);
    void refreshClientTable();
    void refreshProjetTable();
    void setupProjetTable();
};
#endif // MAINWINDOW_H
