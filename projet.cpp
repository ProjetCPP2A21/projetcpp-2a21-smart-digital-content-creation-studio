#include "projet.h"
#include "connection.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

Projet::Projet()
    : client(""), budgetPrevu(0.0), budgetRealise(0.0), dateDebut(""), dateFin("")
{}

Projet::Projet(QString client, double budgetPrevu, double budgetRealise, QString dateDebut, QString dateFin)
    : client(client), budgetPrevu(budgetPrevu), budgetRealise(budgetRealise), dateDebut(dateDebut), dateFin(dateFin)
{}

bool Projet::ajouter()
{
    QSqlQuery query;

    // REQUÊTE PRÉPARÉE adaptée à votre structure de table
    query.prepare("INSERT INTO PROJETS (CLIENT, BUDGETPREVU, BUDGET_REALISE, DATEDEBUT, DATEFIN) "
                  "VALUES (:client, :budget_prevu, :budget_realise, :date_debut, :date_fin)");

    // Liaison des valeurs
    query.bindValue(":client", client);
    query.bindValue(":budget_prevu", budgetPrevu);
    query.bindValue(":budget_realise", budgetRealise);
    query.bindValue(":date_debut", dateDebut);
    query.bindValue(":date_fin", dateFin);

    if (query.exec()) {
        qDebug() << "✅ Projet ajouté - CLIENT:" << client;
        return true;
    } else {
        qDebug() << "❌ Erreur ajout projet:" << query.lastError().text();
        return false;
    }
}

bool Projet::modifier(QString clientAncien)
{
    QSqlQuery query;

    // REQUÊTE PRÉPARÉE POUR LA MODIFICATION
    query.prepare("UPDATE PROJETS SET CLIENT = :new_client, BUDGETPREVU = :budget_prevu, "
                  "BUDGET_REALISE = :budget_realise, DATEDEBUT = :date_debut, DATEFIN = :date_fin "
                  "WHERE CLIENT = :old_client");

    // Liaison des valeurs
    query.bindValue(":new_client", client);
    query.bindValue(":budget_prevu", budgetPrevu);
    query.bindValue(":budget_realise", budgetRealise);
    query.bindValue(":date_debut", dateDebut);
    query.bindValue(":date_fin", dateFin);
    query.bindValue(":old_client", clientAncien);

    if (query.exec()) {
        qDebug() << "✅ Projet modifié - Ancien CLIENT:" << clientAncien << "Nouveau CLIENT:" << client;
        return true;
    } else {
        qDebug() << "❌ Erreur modification projet:" << query.lastError().text();
        return false;
    }
}

bool Projet::supprimer(QString client)
{
    QSqlQuery query;

    // REQUÊTE PRÉPARÉE POUR LA SUPPRESSION
    query.prepare("DELETE FROM PROJETS WHERE CLIENT = :client");
    query.bindValue(":client", client);

    if (query.exec()) {
        qDebug() << "✅ Projet supprimé - CLIENT:" << client;
        return true;
    } else {
        qDebug() << "❌ Erreur suppression projet:" << query.lastError().text();
        return false;
    }
}

QSqlQueryModel* Projet::afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel();

    // REQUÊTE POUR L'AFFICHAGE adaptée à votre structure
    model->setQuery("SELECT CLIENT, BUDGETPREVU, BUDGET_REALISE, DATEDEBUT, DATEFIN FROM PROJETS ORDER BY CLIENT");

    // Définition des en-têtes adaptées
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Client"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Budget Prévu"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Budget Réalisé"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date Début"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date Fin"));

    return model;
}

bool Projet::existeClient(QString client)
{
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM PROJETS WHERE CLIENT = :client");
    query.bindValue(":client", client);

    if (query.exec() && query.next()) {
        return query.value(0).toInt() > 0;
    }
    return false;
}
