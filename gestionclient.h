#ifndef GESTIONCLIENT_H
#define GESTIONCLIENT_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class GestionClient; }
QT_END_NAMESPACE

class GestionClient : public QMainWindow
{
    Q_OBJECT

public:
    explicit GestionClient(QWidget *parent = nullptr);
    ~GestionClient();

private slots:
    void on_btnAjouter_3_clicked();
    void on_btnModifier_3_clicked();
    void on_btnSupprimer_3_clicked();

private:
    Ui::GestionClient *ui;
    void refreshTable();   // recharge le QTableWidget à partir du modèle SQL
    void clearForm();      // vide les champs du formulaire
};

#endif // GESTIONCLIENT_H
