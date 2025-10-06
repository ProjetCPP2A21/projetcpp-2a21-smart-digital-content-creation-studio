#include "gestionclient.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GestionClient w;
    w.show();
    return a.exec();
}
