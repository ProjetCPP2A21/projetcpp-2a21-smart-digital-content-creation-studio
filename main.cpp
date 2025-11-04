#include "gprojet.h"
#include "connection.h"
#include <QApplication>
#include <QMessageBox>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Test de connexion au démarrage
    Connection conn;
    if (!conn.createconnect()) {
        QMessageBox::critical(nullptr, "Erreur", "Impossible de se connecter à la base de données au démarrage !");
        return -1;
    }

    gprojet w;
    w.show();

    qDebug() << "=== APPLICATION DÉMARRÉE ===";

    return a.exec();
}
