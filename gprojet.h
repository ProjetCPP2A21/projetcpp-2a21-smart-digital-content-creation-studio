#ifndef GPROJET_H
#define GPROJET_H

#include <QMainWindow>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QSqlQueryModel>
#include "projet.h"

QT_BEGIN_NAMESPACE
namespace Ui { class gprojet; }
QT_END_NAMESPACE

class gprojet : public QMainWindow
{
    Q_OBJECT

public:
    explicit gprojet(QWidget *parent = nullptr);
    ~gprojet();

private slots:
    void on_addProjectButton_clicked();
    void on_deleteProjectButton_clicked();
    void on_sortByBudgetButton_clicked();
    void on_sortByDateButton_clicked();
    void on_refreshButton_clicked();

private:
    Ui::gprojet *ui;
    QSqlDatabase db;
    Projet prj;

    void loadProjectsFromDatabase();
    void clearForm();
};

#endif // GPROJET_H
