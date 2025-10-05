#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qpushbutton.h"
#include <QMainWindow>
#include "ui_mainwindow.h"


#include <QTableWidgetItem>
#include <QDate>
#include <QPalette>
#include <QColor>
#include <QPixmap>
#include <QPushButton>

class gestion_employe;

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


private:
    gestion_employe *Gestion_employe;
    Ui::MainWindow *ui;
    QToolBar *m_tb = nullptr;
    void setActiveButton(QPushButton *btn);

};
#endif // MAINWINDOW_H
