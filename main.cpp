#include <QApplication>
#include <QMessageBox>
#include "ressourcemainwindow.h"
#include "connectionbd.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Connection c;
    if (!c.createconnect()) {
        QMessageBox::critical(nullptr, "ERREUR CRITIQUE",
                              "Impossible de se connecter à la base Oracle XE !\n"
                              "Vérifiez que le service Oracle est démarré.");
        return -1;
    }

    ressourceMainWindow w;
    w.show();                     // Affiche la fenêtre
    w.raise();                    // Met au premier plan
    w.activateWindow();           // Focus

    return a.exec();              // L'application reste ouverte jusqu'à fermeture manuelle
}
