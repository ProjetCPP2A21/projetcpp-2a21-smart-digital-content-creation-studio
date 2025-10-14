#include "connection.h"
#include "mainwindow.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Connection c;
    bool test = c.createconnect();

    if (test)
        qDebug() << "Connexion Oracle établie avec succès ";
    else
        qDebug() << "Échec de la connexion Oracle ";

    MainWindow w;
    w.show();

    return a.exec();
}
