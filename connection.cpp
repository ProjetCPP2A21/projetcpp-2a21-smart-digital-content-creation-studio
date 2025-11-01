#include "connection.h"
#include <QDebug>
#include <QSqlError>

connection::connection() {}  // Constructeur privé

// Fournit l'unique instance globale
connection& connection::getInstance()
{
    static connection instance;  // créée une seule fois !
    return instance;
}

bool connection::createconnect()
{
    if (QSqlDatabase::contains("qt_sql_default_connection"))
        db = QSqlDatabase::database("qt_sql_default_connection");
    else
        db = QSqlDatabase::addDatabase("QODBC");

    db.setDatabaseName("artemia");
    db.setUserName("artemia");
    db.setPassword("0000");

    if (db.open()) {
        qDebug() << "Connexion Oracle réussie via ODBC (Singleton actif)";
        return true;
    } else {
        qDebug() << "Échec connexion Oracle:" << db.lastError().text();
        return false;
    }
}

void connection::closeconnect()
{
    if (db.isOpen())
        db.close();
}
