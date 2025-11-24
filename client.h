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
    QString etat;

public:
    Client();
    Client(int id, QString nom, QString email, QString telephone,
           QString secteur, QString pays, QDate dateInscription);

    // CRUD
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int id);
    bool modifier();

    int getId() const { return id; }
    QString getEtat() const { return etat; }
};

#endif // CLIENT_H
