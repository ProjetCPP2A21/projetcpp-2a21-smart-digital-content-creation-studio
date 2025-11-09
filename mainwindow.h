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


private:
    Ui::MainWindow *ui;
    QToolBar *m_tb = nullptr;
    void setActiveButton(QPushButton *btn);

};
#endif // MAINWINDOW_H
