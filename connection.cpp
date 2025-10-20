#include "connection.h"
#include <QDebug>
#include <QSqlError>

connection::connection() {}

bool connection::createconnect()
{
    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("GestionClients");
    db.setUserName("selimaa");
    db.setPassword("0000");

    if (db.open()) {
        qDebug() << "Connexion Oracle réussie ";
        return true;
    } else {
        qDebug() << "Échec connexion Oracle :" << db.lastError().text();
        return false;
    }
}

void connection::closeconnect()
{
    if (db.isOpen())
        db.close();
}
