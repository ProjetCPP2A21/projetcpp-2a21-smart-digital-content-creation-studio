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
    QString etat;   // nouvelle colonne
    int fingerID; //empreinte

public:
    Client();
    Client(int id, QString nom, QString email, QString telephone,
           QString secteur, QString pays, QDate dateInscription);

    // CRUD
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int id);
    bool modifier();

    // optional getters ans setters
    QString getEtat() const { return etat; }
    void setFingerID(int f) { fingerID = f; }
    int getFingerID() const { return fingerID; }
};

#endif // CLIENT_H
