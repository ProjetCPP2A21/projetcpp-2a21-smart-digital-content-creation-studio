#ifndef GESTIONCLIENT_H
#define GESTIONCLIENT_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class GestionClient;
}
QT_END_NAMESPACE

class GestionClient : public QMainWindow
{
    Q_OBJECT

public:
    GestionClient(QWidget *parent = nullptr);
    ~GestionClient();

private:
    Ui::GestionClient *ui;
};
#endif // GESTIONCLIENT_H
