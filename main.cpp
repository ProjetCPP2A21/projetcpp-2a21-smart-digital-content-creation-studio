#include "gprojet.h"
#include "connection.h"
#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Connexion à la base de données
    Connection& connection = Connection::getInstance();
    bool test = connection.createconnect();

    if (test) {
        gprojet w;
        w.show();
        return a.exec();
    } else {
        QMessageBox::critical(nullptr, "Erreur de connexion",
                              "Impossible de se connecter à la base de données.\n"
                              "Vérifiez la configuration ODBC et les paramètres de connexion.");
        return -1;
    }
}
