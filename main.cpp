#include "gestionclient.h"
#include "connection.h"
#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Appel du Singleton
    connection &c = connection::getInstance();

    // Connexion à la base Oracle via Singleton
    if (c.createconnect()) {
        QMessageBox::information(nullptr,
                                 QObject::tr("Connexion réussie"),
                                 QObject::tr("Connexion à la base Oracle établie avec succès !"));

        // Instanciation de la fenêtre principale après connexion
        GestionClient w;
        w.show();

        return a.exec();
    } else {
        QMessageBox::critical(nullptr,
                              QObject::tr("Erreur de connexion"),
                              QObject::tr("Échec de la connexion à la base Oracle.\n"
                                          "Veuillez vérifier vos identifiants ou votre source ODBC."));
        return -1;
    }
}
