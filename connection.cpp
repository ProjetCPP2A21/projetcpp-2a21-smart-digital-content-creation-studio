#include "connection.h"
#include <QDebug>
#include <QSqlError>

connection::connection() {}

bool connection::createconnect()
{
    db = QSqlDatabase::addDatabase("QODBC");

    //  Utilisation du DSN défini dans ton ODBC (nommé "artemia")
    db.setDatabaseName("artemia");

    //  Identifiants Oracle
    db.setUserName("artemia");   // même nom que dans SQL Developer
    db.setPassword("0000");      // ton mot de passe Oracle exact

    if (db.open()) {
        qDebug() << " Connexion Oracle réussie via ODBC (artemia)";
        return true;
    } else {
        qDebug() << " Échec connexion Oracle:" << db.lastError().text();
        return false;
    }
}

void connection::closeconnect()
{
    if (db.isOpen())
        db.close();
}
