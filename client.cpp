#include "client.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QDebug>

// CONSTRUCTEURS
Client::Client()
{
    id = 0;
    nom = "";
    email = "";
    telephone = "";
    secteur = "";
    pays = "";
    dateInscription = QDate::currentDate();

    etat = "ACTIF";
}

Client::Client(int id, QString nom, QString email, QString telephone,
               QString secteur, QString pays, QDate dateInscription)
{
    this->id = id;
    this->nom = nom;
    this->email = email;
    this->telephone = telephone;
    this->secteur = secteur;
    this->pays = pays;
    this->dateInscription = dateInscription;

    // Nouveau calcul basé sur le dernier projet
    QSqlQuery q;
    q.prepare("SELECT MAX(DATE_FIN - DATE_DEBUT) FROM PROJET WHERE IDCLIENT = :id");
    q.bindValue(":id", id);
    q.exec();
    q.next();

    int duree = q.value(0).toInt();   // peut être NULL → 0
    etat = (duree >= 30) ? "ACTIF" : "INACTIF";
}


// AJOUTER CLIENT
bool Client::ajouter()
{
    QSqlQuery query;

    // Calcule l'état selon les projets
    QSqlQuery q;
    q.prepare("SELECT MAX(DATE_FIN - DATE_DEBUT) FROM PROJET WHERE IDCLIENT = :id");
    q.bindValue(":id", id);
    q.exec();
    q.next();

    int duree = q.value(0).toInt();
    QString autoEtat = (duree >= 30) ? "ACTIF" : "INACTIF";

    query.prepare("INSERT INTO CLIENTT "
                  "(IDCLIENT, NOM, EMAIL, TELEPHONE, SECTEURACTIVITE, PAYS, DATEINSCRIPTION, ETAT) "
                  "VALUES (:id, :nom, :email, :telephone, :secteur, :pays, "
                  "TO_DATE(:dateinscription, 'YYYY-MM-DD'), :etat)");

    query.bindValue(":id", id);
    query.bindValue(":nom", nom.trimmed());
    query.bindValue(":email", email.trimmed());
    query.bindValue(":telephone", telephone.trimmed());
    query.bindValue(":secteur", secteur.trimmed());
    query.bindValue(":pays", pays.trimmed());
    query.bindValue(":dateinscription", dateInscription.toString("yyyy-MM-dd"));
    query.bindValue(":etat", autoEtat);

    return query.exec();
}


// AFFICHER
QSqlQueryModel* Client::afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel();

    model->setQuery(R"(
        SELECT IDCLIENT,
               NOM,
               EMAIL,
               TELEPHONE,
               SECTEURACTIVITE,
               PAYS,
               DATEINSCRIPTION
        FROM CLIENTT
        ORDER BY IDCLIENT ASC
    )");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Email"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Téléphone"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Secteur"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Pays"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Date d'inscription"));

    return model;
}

// SUPPRIMER
bool Client::supprimer(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM CLIENTT WHERE IDCLIENT = :id");
    query.bindValue(":id", id);
    return query.exec();
}

// MODIFIER
bool Client::modifier()
{
    QSqlQuery query;

    // Calcule l'état selon les projets
    QSqlQuery q;
    q.prepare("SELECT MAX(DATE_FIN - DATE_DEBUT) FROM PROJET WHERE IDCLIENT = :id");
    q.bindValue(":id", id);
    q.exec();
    q.next();

    int duree = q.value(0).toInt();
    QString autoEtat = (duree >= 30) ? "ACTIF" : "INACTIF";

    query.prepare("UPDATE CLIENTT SET "
                  "NOM = :nom, "
                  "EMAIL = :email, "
                  "TELEPHONE = :telephone, "
                  "SECTEURACTIVITE = :secteur, "
                  "PAYS = :pays, "
                  "DATEINSCRIPTION = TO_DATE(:dateInscription, 'YYYY-MM-DD'), "
                  "ETAT = :etat "
                  "WHERE IDCLIENT = :id");

    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":email", email);
    query.bindValue(":telephone", telephone);
    query.bindValue(":secteur", secteur);
    query.bindValue(":pays", pays);
    query.bindValue(":dateInscription", dateInscription.toString("yyyy-MM-dd"));
    query.bindValue(":etat", autoEtat);

    return query.exec();
}

