#ifndef GESTIONPROJET3_H
#define GESTIONPROJET3_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class gestionprojet3;
}
QT_END_NAMESPACE

class gestionprojet3 : public QMainWindow
{
    Q_OBJECT

public:
    gestionprojet3(QWidget *parent = nullptr);
    ~gestionprojet3();

private:
    Ui::gestionprojet3 *ui;
};
#endif // GESTIONPROJET3_H
