#ifndef CLIENT_H
#define CLIENT_H

#include <QString>
#include <QSqlQueryModel>
#include <QDate>

class Client
{
private:
    int id;
    QString nom;
    QString email;
    QString telephone;
    QString secteur;
    QString pays;
    QDate dateInscription;

public:
    Client();
    Client(int, QString, QString, QString, QString, QString, QDate);

    // CRUD
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier();
};

#endif // CLIENT_H
