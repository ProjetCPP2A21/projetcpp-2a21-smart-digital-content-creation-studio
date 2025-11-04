#include "projet.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QSqlDatabase>

Projet::Projet()
{
    clien = "";
    budgetPrevu = 0.0;
    budgetRealise = 0.0;
    dateDebut = "";
    dateFin = "";
}

Projet::Projet(QString clien, double budgetPrevu, double budgetRealise, QString dateDebut, QString dateFin)
{
    this->clien = clien;
    this->budgetPrevu = budgetPrevu;
    this->budgetRealise = budgetRealise;
    this->dateDebut = dateDebut;
    this->dateFin = dateFin;
}

bool Projet::ajouter()
{
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query;

    qDebug() << "=== TENTATIVE AJOUT PROJET ===";
    qDebug() << "CLIEN:" << clien;
    qDebug() << "Budget Prévu:" << budgetPrevu;
    qDebug() << "Budget Réalisé:" << budgetRealise;

    // REQUÊTE CORRIGÉE - CLIEN au lieu de CLIENT
    query.prepare("INSERT INTO PROJET (CLIEN, BUDGET_PREVU, BUDGET_REALISE, DATE_DEBUT, DATE_FIN) "
                  "VALUES (:clien, :budget_prev, :budget_real, :date_deb, :date_fin)");

    query.bindValue(":clien", clien);
    query.bindValue(":budget_prev", budgetPrevu);
    query.bindValue(":budget_real", budgetRealise);
    query.bindValue(":date_deb", dateDebut);
    query.bindValue(":date_fin", dateFin);

    if (query.exec()) {
        qDebug() << "✅✅✅ PROJET AJOUTÉ AVEC SUCCÈS !";
        return true;
    } else {
        qDebug() << "❌❌❌ ERREUR AJOUT PROJET:" << query.lastError().text();
        return false;
    }
}

bool Projet::supprimer(QString clien)
{
    QSqlQuery query;

    qDebug() << "Tentative de suppression - CLIEN:" << clien;

    query.prepare("DELETE FROM PROJET WHERE CLIEN = :clien");
    query.bindValue(":clien", clien);

    if (query.exec()) {
        qDebug() << "✅ Projet supprimé. CLIEN:" << clien;
        return true;
    } else {
        qDebug() << "❌ Erreur suppression:" << query.lastError().text();
        return false;
    }
}

QSqlQueryModel* Projet::afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel();

    qDebug() << "=== TENTATIVE AFFICHAGE PROJETS ===";

    // REQUÊTE CORRIGÉE - CLIEN au lieu de CLIENT
    bool success = model->setQuery("SELECT CLIEN, BUDGET_PREVU, BUDGET_REALISE, DATE_DEBUT, DATE_FIN FROM PROJET ORDER BY CLIEN");

    if (!success) {
        qDebug() << "❌ Erreur modèle:" << model->lastError().text();
    } else {
        qDebug() << "✅ Modèle chargé - Lignes:" << model->rowCount();
    }

    // EN-TÊTES CORRIGÉES
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Clien"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Budget Prévu"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Budget Réalisé"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date Début"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date Fin"));

    return model;
}
