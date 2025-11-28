#ifndef GESTIONCLIENT_H
#define GESTIONCLIENT_H

#include <QWidget>
#include "client.h"
#include "bubblemapwindow.h"

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
    void refreshTable();
    void on_tableClients_6_cellClicked(int row, int column);

    void on_btnAjouter_3_clicked();
    void on_btnModifier_3_clicked();
    void on_btnSupprimer_3_clicked();
    void on_leSearch_6_textChanged(const QString &text);
    void on_pushButton_9_clicked();  // tri
    void on_pushButton_7_clicked();  // PDF global
    void on_pushButton_6_clicked();  // PDF inactifs
    void on_pushButton_8_clicked();  // statistiques
    void on_pushButton_10_clicked(); // MAP
    void on_pushButton_11_clicked(); // fiche
private:
    Ui::GestionClient *ui;
    BubbleMapWindow *mapWindow;
};

#endif // GESTIONCLIENT_H
