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
    fingerID = -1;

    // état automatique
    etat = "ACTIF";
}

Client::Client(int id, QString nom, QString email, QString telephone,
               QString secteur, QString pays, QDate dateInscription, int fingerID)
{
    this->id = id;
    this->nom = nom;
    this->email = email;
    this->telephone = telephone;
    this->secteur = secteur;
    this->pays = pays;
    this->dateInscription = dateInscription;
    this->fingerID = fingerID;

    //  CALCUL AUTOMATIQUE DE L’ÉTAT
    if (dateInscription.daysTo(QDate::currentDate()) > 30)
        this->etat = "INACTIF";
    else
        this->etat = "ACTIF";
}



// AJOUTER CLIENT

bool Client::ajouter()
{
    QSqlQuery query;

    QString autoEtat = (dateInscription.daysTo(QDate::currentDate()) > 30)
                           ? "INACTIF"
                           : "ACTIF";

    query.prepare("INSERT INTO CLIENTT "
                  "(IDCLIENT, NOM, EMAIL, TELEPHONE, SECTEURACTIVITE, PAYS, DATEINSCRIPTION, ETAT, FINGERID) "
                  "VALUES (:id, :nom, :email, :telephone, :secteuractivite, :pays, "
                  "TO_DATE(:dateinscription, 'YYYY-MM-DD'), :etat, :fingerID)");


    query.bindValue(":id", id);
    query.bindValue(":nom", nom.trimmed());
    query.bindValue(":email", email.trimmed());
    query.bindValue(":telephone", telephone.trimmed());
    query.bindValue(":secteur", secteur.trimmed());
    query.bindValue(":pays", pays.trimmed());
    query.bindValue(":dateinscription", dateInscription.toString("yyyy-MM-dd"));
    query.bindValue(":etat", autoEtat);
    query.bindValue(":fingerID", fingerID);

    if (query.exec()) {
        qDebug() << " Client ajouté";
        return true;
    } else {
        qDebug() << " Erreur ajout:" << query.lastError().text();
        return false;
    }
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
               DATEINSCRIPTION,
               FINGERID
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
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("ID Empreinte"));

    return model;
}






// SUPPRIMER CLIENT

bool Client::supprimer(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM CLIENTT WHERE IDCLIENT = :id");
    query.bindValue(":id", id);

    if (query.exec()) {
        qDebug() << "✔ Client supprimé";
        return true;
    } else {
        qDebug() << " Erreur suppression:" << query.lastError().text();
        return false;
    }
}




// MODIFIER CLIENT

bool Client::modifier()
{
    QSqlQuery query;

    QString autoEtat = (dateInscription.daysTo(QDate::currentDate()) > 30)
                           ? "INACTIF"
                           : "ACTIF";

    QString sql = "UPDATE CLIENTT SET "
                  "NOM = :nom, "
                  "EMAIL = :email, "
                  "TELEPHONE = :telephone, "
                  "SECTEURACTIVITE = :secteur, "
                  "PAYS = :pays, "
                  "DATEINSCRIPTION = TO_DATE(:dateInscription, 'YYYY-MM-DD'), "
                  "ETAT = :etat, "
                  "FINGERID = :fingerID "
                  "WHERE IDCLIENT = :id";


    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":email", email);
    query.bindValue(":telephone", telephone);
    query.bindValue(":secteur", secteur);
    query.bindValue(":pays", pays);
    query.bindValue(":dateinscription", dateInscription.toString("yyyy-MM-dd"));
    query.bindValue(":etat", autoEtat);
    query.bindValue(":fingerID", fingerID);

    if (query.exec()) {
        qDebug() << "Client modifié";
        return true;
    } else {
        qDebug() << " Erreur modification:" << query.lastError().text();
        return false;
    }
}
