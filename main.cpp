#include <QApplication>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include "gestionclient.h"

void testConnexionEtTable()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("GestionClients");
    db.setUserName("selimaa");
    db.setPassword("0000");

    if (db.open()) {
        QSqlQuery query("SELECT table_name FROM user_tables WHERE table_name = 'CLIENT'");
        if (query.next()) {
            QMessageBox::information(nullptr, "Succès ✅",
                                     "Connexion Oracle établie et la table CLIENT existe !");
        } else {
            QMessageBox::warning(nullptr, "⚠️ ATTENTION",
                                 "Connexion OK mais la table CLIENT n'existe pas !");
        }
    } else {
        QMessageBox::critical(nullptr, "Erreur ❌",
                              "Impossible de se connecter à Oracle : " + db.lastError().text());
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Test Oracle avant d'ouvrir l'interface
    testConnexionEtTable();

    GestionClient w;
    w.show();
    return a.exec();
}
