#include "projet.h"
#include "connection.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

Projet::Projet()
    : idClient(0), budgetPrevu(0.0), budgetRealise(0.0),
    dateDebut(""), dateFin(""), statut("En cours")
{}

Projet::Projet(int idClient, double budgetPrevu, double budgetRealise,
               QString dateDebut, QString dateFin, QString statut)
    : idClient(idClient), budgetPrevu(budgetPrevu), budgetRealise(budgetRealise),
    dateDebut(dateDebut), dateFin(dateFin), statut(statut)
{}

bool Projet::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO PROJETS (ID_CLIENT, BUDGETPREVU, BUDGET_REALISE, DATEDEBUT, DATEFIN, STATUT) "
                  "VALUES (:id_client, :budget_prevu, :budget_realise, :date_debut, :date_fin, :statut)");

    query.bindValue(":id_client", idClient);
    query.bindValue(":budget_prevu", budgetPrevu);
    query.bindValue(":budget_realise", budgetRealise);
    query.bindValue(":date_debut", dateDebut);
    query.bindValue(":date_fin", dateFin);
    query.bindValue(":statut", statut);

    if (query.exec()) {
        qDebug() << "✅ Projet ajouté - ID_CLIENT:" << idClient;
        return true;
    } else {
        qDebug() << "❌ Erreur ajout projet:" << query.lastError().text();
        return false;
    }
}

bool Projet::modifier(int idClientAncien)
{
    QSqlQuery query;
    query.prepare("UPDATE PROJETS SET ID_CLIENT = :new_id_client, BUDGETPREVU = :budget_prevu, "
                  "BUDGET_REALISE = :budget_realise, DATEDEBUT = :date_debut, DATEFIN = :date_fin, STATUT = :statut "
                  "WHERE ID_CLIENT = :old_id_client");

    query.bindValue(":new_id_client", idClient);
    query.bindValue(":budget_prevu", budgetPrevu);
    query.bindValue(":budget_realise", budgetRealise);
    query.bindValue(":date_debut", dateDebut);
    query.bindValue(":date_fin", dateFin);
    query.bindValue(":statut", statut);
    query.bindValue(":old_id_client", idClientAncien);

    if (query.exec()) {
        qDebug() << "✅ Projet modifié - Ancien ID_CLIENT:" << idClientAncien << "Nouveau ID_CLIENT:" << idClient;
        return true;
    } else {
        qDebug() << "❌ Erreur modification projet:" << query.lastError().text();
        return false;
    }
}

bool Projet::supprimer(int idClient)
{
    QSqlQuery query;
    query.prepare("DELETE FROM PROJETS WHERE ID_CLIENT = :id_client");
    query.bindValue(":id_client", idClient);

    if (query.exec()) {
        qDebug() << "✅ Projet supprimé - ID_CLIENT:" << idClient;
        return true;
    } else {
        qDebug() << "❌ Erreur suppression projet:" << query.lastError().text();
        return false;
    }
}

QSqlQueryModel* Projet::afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT ID_CLIENT, BUDGETPREVU, BUDGET_REALISE, DATEDEBUT, DATEFIN, STATUT FROM PROJETS ORDER BY ID_CLIENT");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID Client"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Budget Prévu"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Budget Réalisé"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date Début"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date Fin"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Statut"));

    return model;
}

QSqlQueryModel* Projet::rechercher(const QString& motCle)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QString requete = "SELECT ID_CLIENT, BUDGETPREVU, BUDGET_REALISE, DATEDEBUT, DATEFIN, STATUT FROM PROJETS "
                      "WHERE TO_CHAR(ID_CLIENT) LIKE '%" + motCle + "%' "
                                 "OR TO_CHAR(BUDGETPREVU) LIKE '%" + motCle + "%' "
                                 "OR TO_CHAR(BUDGET_REALISE) LIKE '%" + motCle + "%' "
                                 "OR DATEDEBUT LIKE '%" + motCle + "%' "
                                 "OR DATEFIN LIKE '%" + motCle + "%' "
                                 "OR UPPER(STATUT) LIKE UPPER('%" + motCle + "%') "
                                 "ORDER BY ID_CLIENT";

    model->setQuery(requete);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID Client"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Budget Prévu"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Budget Réalisé"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date Début"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date Fin"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Statut"));

    return model;
}

bool Projet::existeClient(int idClient)
{
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM PROJETS WHERE ID_CLIENT = :id_client");
    query.bindValue(":id_client", idClient);

    if (query.exec() && query.next()) {
        return query.value(0).toInt() > 0;
    }
    return false;
}

QVector<QPair<QString, int>> Projet::compterProjetsParPlageBudget()
{
    QVector<QPair<QString, int>> resultats;
    QSqlQuery query;

    // VERSION CORRIGÉE - Plus robuste
    QString requete =
        "SELECT "
        "SUM(CASE WHEN BUDGETPREVU BETWEEN 0 AND 499.99 THEN 1 ELSE 0 END) as moins_500, "
        "SUM(CASE WHEN BUDGETPREVU BETWEEN 500 AND 999.99 THEN 1 ELSE 0 END) as 500_1000, "
        "SUM(CASE WHEN BUDGETPREVU BETWEEN 1000 AND 1999.99 THEN 1 ELSE 0 END) as 1000_2000, "
        "SUM(CASE WHEN BUDGETPREVU >= 2000 THEN 1 ELSE 0 END) as plus_2000, "
        "COUNT(*) as total "
        "FROM PROJETS WHERE BUDGETPREVU IS NOT NULL AND BUDGETPREVU > 0";

    if (query.exec(requete)) {
        if (query.next()) {
            int moins500 = query.value(0).toInt();
            int p500_1000 = query.value(1).toInt();
            int p1000_2000 = query.value(2).toInt();
            int plus2000 = query.value(3).toInt();
            int total = query.value(4).toInt();

            qDebug() << "🔍 Résultats statistiques SQL:";
            qDebug() << "0-499.99:" << moins500;
            qDebug() << "500-999.99:" << p500_1000;
            qDebug() << "1000-1999.99:" << p1000_2000;
            qDebug() << "2000+:" << plus2000;
            qDebug() << "Total avec budget:" << total;

            if (total > 0) {
                resultats.append(qMakePair(QString("0-499 €"), moins500));
                resultats.append(qMakePair(QString("500-999 €"), p500_1000));
                resultats.append(qMakePair(QString("1000-1999 €"), p1000_2000));
                resultats.append(qMakePair(QString("2000+ €"), plus2000));
            }
        }
    } else {
        qDebug() << "❌ Erreur requête statistiques:" << query.lastError().text();

        // FALLBACK - Méthode manuelle si la requête échoue
        qDebug() << "🔄 Utilisation de la méthode manuelle...";
        query.exec("SELECT BUDGETPREVU FROM PROJETS"); // SUPPRIMÉ idClient inutilisé

        int moins500 = 0, p500_1000 = 0, p1000_2000 = 0, plus2000 = 0;
        int totalAvecBudget = 0;

        while (query.next()) {
            double budget = query.value(0).toDouble();

            if (budget > 0) {
                totalAvecBudget++;
                if (budget <= 499.99) moins500++;
                else if (budget <= 999.99) p500_1000++;
                else if (budget <= 1999.99) p1000_2000++;
                else plus2000++;
            }
        }

        qDebug() << "📊 Calcul manuel:";
        qDebug() << "0-499:" << moins500 << "500-999:" << p500_1000
                 << "1000-1999:" << p1000_2000 << "2000+:" << plus2000
                 << "Total:" << totalAvecBudget;

        if (totalAvecBudget > 0) {
            resultats.append(qMakePair(QString("0-499 €"), moins500));
            resultats.append(qMakePair(QString("500-999 €"), p500_1000));
            resultats.append(qMakePair(QString("1000-1999 €"), p1000_2000));
            resultats.append(qMakePair(QString("2000+ €"), plus2000));
        }
    }

    return resultats;
}

QMap<QString, double> Projet::statistiquesPlagesBudget()
{
    QMap<QString, double> pourcentages;
    QVector<QPair<QString, int>> comptage = compterProjetsParPlageBudget();

    int totalProjets = 0;
    for (const auto& paire : comptage) {
        totalProjets += paire.second;
    }

    if (totalProjets > 0) {
        for (const auto& paire : comptage) {
            double pourcentage = (paire.second * 100.0) / totalProjets;
            pourcentages[paire.first] = pourcentage;
        }
    }

    qDebug() << "📈 Pourcentages calculés - Total projets:" << totalProjets;
    for (auto it = pourcentages.begin(); it != pourcentages.end(); ++it) {
        qDebug() << it.key() << ":" << it.value() << "%";
    }

    return pourcentages;
}
