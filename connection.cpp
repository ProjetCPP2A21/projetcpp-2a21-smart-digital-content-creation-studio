#include "connection.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QDebug>

Connection::Connection()
{
    db = QSqlDatabase::addDatabase("QODBC");
}

Connection::~Connection() {
    if (db.isOpen()) {
        db.close();
        qDebug() << "Connexion fermée proprement.";
    }
}

Connection& Connection::createInstance() {
    static Connection instance;  // Unique instance créée une seule fois
    return instance;
}

bool Connection::createconnect()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setHostName("localhost");
    db.setDatabaseName("artemia");
    db.setUserName("artemia");
    db.setPassword("0000");

    if (db.open()) {
        qDebug() << " Connexion réussie à Oracle via ODBC !";
        return true;
    } else {
        qDebug() << " Échec de connexion :" << db.lastError().text();
        return false;
    }
}

