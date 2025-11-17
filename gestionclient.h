#ifndef GESTIONCLIENT_H
#define GESTIONCLIENT_H

#include <QSerialPort>
#include <QSerialPortInfo>


#include <QWidget>

namespace Ui {
class GestionClient;   // ✅ c’est bien GestionClient
}

class GestionClient : public QWidget    //  QWidget, pas QMainWindow
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
    void on_pushButton_7_clicked();  // export CSV
    void on_pushButton_9_clicked();  // Trier
    void on_pushButton_8_clicked();  // stats
    void on_pushButton_6_clicked();  // PDF inactifs

    //-----------------ARDUINO----------------------
    void readArduinoData();
    void activerClient(QString id);

private:
    Ui::GestionClient *ui;
    void refreshTable();


    //-----------------ARDUINO----------------------
    //initialisation port arduino
    QSerialPort *arduino;

};

#endif // GESTIONCLIENT_H
