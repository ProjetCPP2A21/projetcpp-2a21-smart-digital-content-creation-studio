#include "client.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

Client::Client()
{
    id = 0;
    nom = "";
    email = "";
    telephone = "";
    secteur = "";
    pays = "";
    dateInscription = QDate::currentDate();
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
}

/* ============================================================
   🔵 AJOUTER
   ============================================================ */
bool Client::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO CLIENTT "
                  "(IDCLIENT, NOM, EMAIL, TELEPHONE, SECTEURACTIVITE, PAYS, DATEINSCRIPTION) "
                  "VALUES (:id, :nom, :email, :tel, :secteur, :pays, :dateIns)");

    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":email", email);
    query.bindValue(":tel", telephone);
    query.bindValue(":secteur", secteur);
    query.bindValue(":pays", pays);
    query.bindValue(":dateIns", dateInscription);

    return query.exec();
}

/* ============================================================
   🔵 MODIFIER
   ============================================================ */
bool Client::modifier()
{
    QSqlQuery query;
    query.prepare("UPDATE CLIENTT SET "
                  "NOM=:nom, EMAIL=:email, TELEPHONE=:tel, "
                  "SECTEURACTIVITE=:secteur, PAYS=:pays, DATEINSCRIPTION=:dateIns "
                  "WHERE IDCLIENT=:id");

    query.bindValue(":nom", nom);
    query.bindValue(":email", email);
    query.bindValue(":tel", telephone);
    query.bindValue(":secteur", secteur);
    query.bindValue(":pays", pays);
    query.bindValue(":dateIns", dateInscription);
    query.bindValue(":id", id);

    return query.exec();
}

/* ============================================================
   🔵 SUPPRIMER
   ============================================================ */
bool Client::supprimer(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM CLIENTT WHERE IDCLIENT=:id");
    query.bindValue(":id", id);
    return query.exec();
}

/* ============================================================
   🔵 AFFICHAGE COMPLET
   ============================================================ */
QSqlQueryModel* Client::getAllClients()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT IDCLIENT, NOM, EMAIL, TELEPHONE, SECTEURACTIVITE, PAYS, DATEINSCRIPTION FROM CLIENTT");
    return model;
}

/* ============================================================
   🔵 TRI PAR DATE
   ============================================================ */
QSqlQueryModel* Client::getClientsTries()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT IDCLIENT, NOM, EMAIL, TELEPHONE, SECTEURACTIVITE, PAYS, DATEINSCRIPTION "
                    "FROM CLIENTT ORDER BY DATEINSCRIPTION ASC");
    return model;
}

/* ============================================================
   🔵 RECHERCHE PAR SECTEUR
   ============================================================ */
QSqlQueryModel* Client::rechercheSecteur(const QString &secteur)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("SELECT IDCLIENT, NOM, EMAIL, TELEPHONE, SECTEURACTIVITE, PAYS, DATEINSCRIPTION "
                  "FROM CLIENTT WHERE LOWER(SECTEURACTIVITE) LIKE LOWER(:sec)");

    query.bindValue(":sec", "%" + secteur + "%");
    query.exec();
    model->setQuery(query);

    return model;
}

/* ============================================================
   🔵 POUR LA MAP – Nom + Ville
   ============================================================ */
QSqlQueryModel* Client::getNomsEtVilles()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT NOM, PAYS FROM CLIENTT");
    return model;
}

/* ============================================================
   🔵 STATUT CLIENT BASÉ SUR PROJET
      - duree = MAX(date_fin - date_debut)
      - enCours = existe projet où date_fin >= aujourd’hui
   ============================================================ */
QSqlQuery Client::getProjetInfo(int idClient)
{
    QSqlQuery query;

    query.prepare(
        "SELECT NVL(MAX(DATE_FIN - DATE_DEBUT), 0) AS duree "
        "FROM PROJET WHERE IDCLIENT = :idc"
        );

    query.bindValue(":idc", idClient);
    query.exec();
    return query;
}


/* ============================================================
   🔵 LISTE DÉTAILLÉE DES PROJETS POUR LE PDF FICHE
   ============================================================ */
QSqlQueryModel* Client::getProjetsDuClient(int idClient)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("SELECT ID_PROJET, DATE_DEBUT, DATE_FIN, BUDGET_REALISE, STATUS "
                  "FROM PROJET WHERE IDCLIENT = :idc "
                  "ORDER BY DATE_DEBUT DESC");
    query.bindValue(":idc", idClient);
    query.exec();

    model->setQuery(query);
    return model;
}

