#ifndef GESTION_EMPLOYE_H
#define GESTION_EMPLOYE_H

#include <QMainWindow>

#include <QDebug>
#include <QPixmap>
#include <QTableWidget>

#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QMessageBox>
#include <QComboBox>

#include <QString>
#include <QDate>
#include <QStringList>
#include <QRandomGenerator>
#include <QList>

#include <QTableWidgetItem>
#include <QPixmap>
#include <QTableWidget>
#include <QHeaderView>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QChart>
#include <QVBoxLayout>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>

#include <QSqlQuery>
#include <QSqlQueryModel>

#include <QTemporaryDir>

QT_BEGIN_NAMESPACE

namespace Ui {
class gestion_employe;
}
QT_END_NAMESPACE

class gestion_employe : public QMainWindow
{
    Q_OBJECT

public:
    gestion_employe(QWidget *parent = nullptr);
    ~gestion_employe();
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

    Ui::gestion_employe *ui;
};


#endif // GESTION_EMPLOYE_H
