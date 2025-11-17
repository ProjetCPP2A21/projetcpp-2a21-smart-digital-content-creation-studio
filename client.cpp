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
    etat = "actif";   // valeur par défaut
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

    // Définition automatique de l'état
    this->etat = (dateInscription.daysTo(QDate::currentDate()) > 30)
                     ? "inactif"
                     : "actif";
}






//AJOUTER
bool Client::ajouter()
{
    QSqlQuery query;

    // Calcul automatique de l'état au moment de l'ajout
    QString autoEtat = (dateInscription.daysTo(QDate::currentDate()) > 30)
                           ? "inactif"
                           : "actif";

    query.prepare("INSERT INTO CLIENTT "
                  "(IDCLIENT, NOM, EMAIL, TELEPHONE, SECTEURACTIVITE, PAYS, DATEINSCRIPTION, ETAT) "
                  "VALUES (:id, :nom, :email, :telephone, :secteuractivite, :pays, "
                  "TO_DATE(:dateinscription, 'YYYY-MM-DD'), :etat)");

    query.bindValue(":id", id);
    query.bindValue(":nom", nom.trimmed());
    query.bindValue(":email", email.trimmed());
    query.bindValue(":telephone", telephone.trimmed());
    query.bindValue(":secteuractivite", secteur.trimmed());
    query.bindValue(":pays", pays.trimmed());
    query.bindValue(":dateinscription", dateInscription.toString("yyyy-MM-dd"));
    query.bindValue(":etat", autoEtat);

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
    model->setQuery("SELECT IDCLIENT, NOM, EMAIL, TELEPHONE, SECTEURACTIVITE, PAYS, DATEINSCRIPTION, ETAT "
                    "FROM CLIENTT ORDER BY IDCLIENT ASC");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Email"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Téléphone"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Secteur"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Pays"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Date d'inscription"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("État"));

    return model;
}







//SUPPRIMER
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








// MODIFIER
bool Client::modifier()
{
    QSqlQuery query;

    // recalcul automatique de l'état à la modification
    QString autoEtat = (dateInscription.daysTo(QDate::currentDate()) > 30)
                           ? "inactif"
                           : "actif";

    QString sql = "UPDATE CLIENTT SET "
                  "NOM = :nom, "
                  "EMAIL = :email, "
                  "TELEPHONE = :telephone, "
                  "SECTEURACTIVITE = :secteur, "
                  "PAYS = :pays, "
                  "DATEINSCRIPTION = TO_DATE(:dateInscription, 'YYYY-MM-DD'), "
                  "ETAT = :etat "
                  "WHERE IDCLIENT = :id";

    query.prepare(sql);

    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":email", email);
    query.bindValue(":telephone", telephone);
    query.bindValue(":secteur", secteur);
    query.bindValue(":pays", pays);
    query.bindValue(":dateInscription", dateInscription.toString("yyyy-MM-dd"));
    query.bindValue(":etat", autoEtat);

    if (query.exec()) {
        qDebug() << " Modification réussie.";
        return true;
    } else {
        qDebug() << " Erreur Oracle lors du UPDATE:" << query.lastError().text();
        return false;
    }
}
