#include "connection.h"
#include <QSqlError>
#include <QMessageBox>
#include <QDebug>

Connection::Connection() {}

bool Connection::createconnect()
{
    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Source_Projet2A");
    db.setUserName("selima");
    db.setPassword("0000");

    if (db.open()) {
        QMessageBox::information(nullptr, QObject::tr("Succès"),
                                 QObject::tr("Connexion établie avec Oracle !"));
        qDebug() << "Connexion Oracle réussie ";
        return true;
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                              QObject::tr("Échec de connexion : %1")
                                  .arg(db.lastError().text()));
        qDebug() << "Échec de connexion " << db.lastError().text();
        return false;
    }
}

void Connection::closeconnect()
{
    db.close();
}
