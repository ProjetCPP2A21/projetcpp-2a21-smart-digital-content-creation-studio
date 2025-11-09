#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qpushbutton.h"
#include <QMainWindow>
#include "ui_mainwindow.h"
#include "Employe.h"
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
    //////employes/////
    void ajouterEmploye();
    void supprimerEmploye();
    void rechercherEmploye();
    void afficherEmployes(QSqlQueryModel *model);
    void trierParPoste();
    void exportEmployes();
    void afficherStatistiques();
    void onItemChanged(QTableWidgetItem *item);


    //client//Selima
    void on_tableClients_6_cellClicked(int row, int column);
    void on_btnAjouter_3_clicked();
    void on_btnModifier_3_clicked();
    void on_btnSupprimer_3_clicked();
    void on_leSearch_6_textChanged(const QString &text);
    void on_pushButton_7_clicked();  // Export CSV
    void on_pushButton_9_clicked();  // Trier
    void on_pushButton_8_clicked();  // Statistiques

    // bouton du menu latéral pour ouvrir la page client :
    void on_pushButton_client_clicked();


private:
    Ui::MainWindow *ui;
    QToolBar *m_tb = nullptr;
    void setActiveButton(QPushButton *btn);

    void refreshClientTable(); //Client


};
#endif // MAINWINDOW_H
