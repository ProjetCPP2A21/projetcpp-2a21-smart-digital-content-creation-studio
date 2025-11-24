#ifndef GESTIONCLIENT_H
#define GESTIONCLIENT_H


#include "bubblemapwindow.h"



#include <QWidget>

namespace Ui {
class GestionClient;
}

class GestionClient : public QWidget
{
    Q_OBJECT

public:
    explicit GestionClient(QWidget *parent = nullptr);
    ~GestionClient();

private slots:
    void on_tableClients_6_cellClicked(int row, int column);
    void on_btnAjouter_3_clicked();
    void on_btnModifier_3_clicked();
    void on_btnSupprimer_3_clicked();
    void on_leSearch_6_textChanged(const QString &text);
    void on_pushButton_7_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_6_clicked();


    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();


private:
    Ui::GestionClient *ui;
    void refreshTable();
    BubbleMapWindow *mapWindow;
};

#endif // GESTIONCLIENT_H
