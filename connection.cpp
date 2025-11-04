#include "connection.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QDebug>
#include <QMessageBox>

Connection::Connection() {}

bool Connection::createconnect()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("artemia"); // Nom de ta source ODBC (DSN)
    db.setUserName("artemia");     // Ton nom d'utilisateur Oracle
    db.setPassword("0000");        // Ton mot de passe Oracle

    qDebug() << "=== TENTATIVE DE CONNEXION ===";
    qDebug() << "DSN: artemia";
    qDebug() << "User: artemia";

    if (db.open()) {
        qDebug() << "✅✅✅ CONNEXION RÉUSSIE À ORACLE !";

        // TEST : Vérifier si on peut accéder à la table PROJET
        QSqlQuery testQuery;
        if (testQuery.exec("SELECT COUNT(*) FROM PROJET")) {
            if (testQuery.next()) {
                int count = testQuery.value(0).toInt();
                qDebug() << "✅ Nombre de projets dans la table:" << count;
            }
        } else {
            qDebug() << "❌ Impossible d'accéder à la table PROJET:" << testQuery.lastError().text();
        }

        return true;
    } else {
        qDebug() << "❌❌❌ ÉCHEC DE CONNEXION :" << db.lastError().text();
        QMessageBox::critical(nullptr, "Erreur Connexion",
                              "Échec de connexion à la base de données:\n" + db.lastError().text());
        return false;
    }
}

QSqlDatabase Connection::getDatabase()
{
    return QSqlDatabase::database();
}
