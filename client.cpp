#include "client.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
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

Client::Client(int id, QString nom, QString email, QString telephone, QString secteur, QString pays, QDate dateInscription)
{
    this->id = id;
    this->nom = nom;
    this->email = email;
    this->telephone = telephone;
    this->secteur = secteur;
    this->pays = pays;
    this->dateInscription = dateInscription;
}

//  AJOUTER
bool Client::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO CLIENT (IDCLIENT, NOM, EMAIL, TELEPHONE, SECTEURACTIVITE, PAYS, DATEINSCRIPTION) "
                  "VALUES (:id, :nom, :email, :telephone, :secteur, :pays, :dateInscription)");

    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":email", email);
    query.bindValue(":telephone", telephone);
    query.bindValue(":secteur", secteur);
    query.bindValue(":pays", pays);
    query.bindValue(":dateInscription", dateInscription);

    if (query.exec()) {
        qDebug() << " Client ajouté avec succès !";
        return true;
    } else {
        qDebug() << " Erreur ajout client:" << query.lastError().text();
        return false;
    }
}

// AFFICHER
QSqlQueryModel* Client::afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM CLIENT ORDER BY IDCLIENT ASC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Email"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Téléphone"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Secteur d'activité"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Pays"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Date d'inscription"));
    return model;
}

// SUPPRIMER
bool Client::supprimer(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM CLIENT WHERE IDCLIENT = :id");
    query.bindValue(":id", id);

    if (query.exec()) {
        qDebug() << "🗑️ Client supprimé avec succès !";
        return true;
    } else {
        qDebug() << "❌ Erreur suppression client:" << query.lastError().text();
        return false;
    }
}

//  MODIFIER
bool Client::modifier()
{
    QSqlQuery query;
    query.prepare("UPDATE CLIENT SET NOM=:nom, EMAIL=:email, TELEPHONE=:telephone, "
                  "SECTEURACTIVITE=:secteur, PAYS=:pays, DATEINSCRIPTION=:dateInscription "
                  "WHERE IDCLIENT=:id");

    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":email", email);
    query.bindValue(":telephone", telephone);
    query.bindValue(":secteur", secteur);
    query.bindValue(":pays", pays);
    query.bindValue(":dateInscription", dateInscription);

    if (query.exec()) {
        qDebug() << "✏️ Client modifié avec succès !";
        return true;
    } else {
        qDebug() << "❌ Erreur modification client:" << query.lastError().text();
        return false;
    }
}
