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

    // ️ Préparation de la requête (identique à ta structure de table)
    query.prepare("INSERT INTO CLIENTT "
                  "(IDCLIENT, NOM, EMAIL, TELEPHONE, SECTEURACTIVITE, PAYS, DATEINSCRIPTION) "
                  "VALUES (:id, :nom, :email, :telephone, :secteuractivite, :pays, TO_DATE(:dateinscription, 'YYYY-MM-DD'))");

    //  Liaison des valeurs
    query.bindValue(":id", id);
    query.bindValue(":nom", nom.trimmed());
    query.bindValue(":email", email.trimmed());
    query.bindValue(":telephone", telephone.trimmed());
    query.bindValue(":secteuractivite", secteur.trimmed());
    query.bindValue(":pays", pays.trimmed());
    query.bindValue(":dateinscription", dateInscription.toString("yyyy-MM-dd"));

    // 🧩 Exécution
    if (query.exec()) {
        qDebug() << " Client ajouté avec succès !";
        return true;
    } else {
        //  Détails complets en cas d'erreur Oracle
        qDebug() << " Erreur ajout client:" << query.lastError().text();
        qDebug() << " Détail driver:" << query.lastError().driverText();
        qDebug() << " Détail base:" << query.lastError().databaseText();
        qDebug() << " Requête exécutée:" << query.lastQuery();
        return false;
    }
}






// AFFICHER
QSqlQueryModel* Client::afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM CLIENTT ORDER BY IDCLIENT ASC");
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
    query.prepare("DELETE FROM CLIENTT WHERE IDCLIENT = :id");
    query.bindValue(":id", id);

    if (query.exec()) {
        qDebug() << " Client supprimé avec succès !";
        return true;
    } else {
        qDebug() << " Erreur suppression client:" << query.lastError().text();
        return false;
    }
}

//  MODIFIER
bool Client::modifier()
{
    QSqlQuery query;

    QString sql = "UPDATE CLIENTT SET "
                  "NOM = :nom, "
                  "EMAIL = :email, "
                  "TELEPHONE = :telephone, "
                  "SECTEURACTIVITE = :secteur, "
                  "PAYS = :pays, "
                  "DATEINSCRIPTION = TO_DATE(:dateInscription, 'YYYY-MM-DD') "
                  "WHERE IDCLIENT = :id";

    query.prepare(sql);

    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":email", email);
    query.bindValue(":telephone", telephone);
    query.bindValue(":secteur", secteur);
    query.bindValue(":pays", pays);
    query.bindValue(":dateInscription", dateInscription.toString("yyyy-MM-dd"));

    qDebug() << " [DEBUG SQL] Requête préparée :" << sql;
    qDebug() << " [DEBUG PARAMS] ID:" << id
             << ", NOM:" << nom
             << ", EMAIL:" << email
             << ", TEL:" << telephone
             << ", SECTEUR:" << secteur
             << ", PAYS:" << pays
             << ", DATE:" << dateInscription.toString("yyyy-MM-dd");

    if (query.exec()) {
        int rows = query.numRowsAffected();
        qDebug() << " Requête exécutée. Lignes affectées :" << rows;
        return rows > 0;
    } else {
        qDebug() << " Erreur Oracle lors du UPDATE:" << query.lastError().text();
        return false;
    }
}


