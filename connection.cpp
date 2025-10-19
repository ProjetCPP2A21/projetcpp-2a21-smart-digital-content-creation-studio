#include "connection.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QDebug>

Connection::Connection()
{
}

bool Connection::createconnect()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setHostName("localhost");
    db.setDatabaseName("Source_Projet2A");
    db.setUserName("EmnaTrabelsi");
    db.setPassword("luna.suga.2005");

    if (db.open()) {
        qDebug() << " Connexion réussie à Oracle via ODBC !";
        return true;
    } else {
        qDebug() << " Échec de connexion :" << db.lastError().text();
        return false;
    }
}
