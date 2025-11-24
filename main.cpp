#include "gestion_employe.h"
#include "connection.h"
#include "qapplication.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Connection& c= Connection::createInstance();
    bool test=c.createconnect();
    gestion_employe w;
    if(test)
    {w.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                                 QObject::tr("connection successful.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
        a.setStyleSheet("QWidget { background-color: white; color: black; }");

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                              QObject::tr("connection failed.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);


    return a.exec();
}
