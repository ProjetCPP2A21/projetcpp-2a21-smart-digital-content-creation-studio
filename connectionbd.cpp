#include "connectionbd.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>

Connection::Connection() {}

bool Connection::createconnect()
{
    for (const QString &name : QSqlDatabase::connectionNames())
        QSqlDatabase::removeDatabase(name);

    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Driver={Oracle in XE};Dbq=XE;Uid=artemia;Pwd=0000;");

    if (!db.open()) {
        qCritical() << "Connexion échouée:" << db.lastError().text();
        return false;
    }
    qDebug() << "Connecté à Oracle XE avec succès !";
    return true;
}
