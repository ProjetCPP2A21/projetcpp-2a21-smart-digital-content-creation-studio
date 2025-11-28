#ifndef CLIENT_H
#define CLIENT_H

#include <QString>
#include <QSqlQuery>
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
    bool modifier();
    bool supprimer(int);

    // Affichage
    QSqlQueryModel* getAllClients();
    QSqlQueryModel* getClientsTries();
    QSqlQueryModel* rechercheSecteur(const QString &);
    QSqlQueryModel* getNomsEtVilles();

    // Projets d’un client
    QSqlQuery getProjetInfo(int);             // duree max + enCours
    QSqlQueryModel* getProjetsDuClient(int);  // liste détaillée
};

#endif // CLIENT_H
