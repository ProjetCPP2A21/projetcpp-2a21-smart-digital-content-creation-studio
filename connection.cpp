#include "connection.h"
#include <QDebug>

Connection::Connection() {}

Connection& Connection::getInstance()
{
    static Connection instance;
    return instance;
}

bool Connection::createconnect()
{
    db = QSqlDatabase::addDatabase("QODBC");
    db.setHostName("localhost");
    db.setDatabaseName("artemia");
    db.setUserName("artemia");
    db.setPassword("0000");

    if (db.open()) {
        qDebug() << "✅ Connexion réussie à Oracle via ODBC !";
        return true;
    } else {
        qDebug() << "❌ Échec de connexion :" << db.lastError().text();
        return false;
    }
}

void Connection::closeconnect()
{
    if (db.isOpen()) {
        db.close();
        qDebug() << "Connexion fermée";
    }
}

QSqlDatabase Connection::getDatabase()
{
    return db;
}
