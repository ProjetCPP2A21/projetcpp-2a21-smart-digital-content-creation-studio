#include "ressource.h"
#include <QSqlQuery>
#include <QSqlQueryModel>

Ressource::Ressource() {}

Ressource::Ressource(int id, QString type, QString nomProjet, QString nomFichier)
{
    this->id = id;
    this->type = type;
    this->nomProjet = nomProjet;
    this->nomFichier = nomFichier;
}

int Ressource::getId() { return id; }
QString Ressource::getType() { return type; }
QString Ressource::getNomProjet() { return nomProjet; }
QString Ressource::getNomFichier() { return nomFichier; }

bool Ressource::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO ressources (id, type, nomProjet, nomFichier) "
                  "VALUES (:id, :type, :nomProjet, :nomFichier)");
    query.bindValue(":id", id);
    query.bindValue(":type", type);
    query.bindValue(":nomProjet", nomProjet);
    query.bindValue(":nomFichier", nomFichier);

    return query.exec();
}

QSqlQueryModel* Ressource::afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM ressources");
    return model;
}

bool Ressource::supprimer(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM ressources WHERE id = :id");
    query.bindValue(":id", id);
    return query.exec();
}

bool Ressource::modifier(int id, QString type, QString nomProjet, QString nomFichier)
{
    QSqlQuery query;
    query.prepare("UPDATE ressources SET type=:type, nomProjet=:nomProjet, nomFichier=:nomFichier WHERE id=:id");
    query.bindValue(":id", id);
    query.bindValue(":type", type);
    query.bindValue(":nomProjet", nomProjet);
    query.bindValue(":nomFichier", nomFichier);
    return query.exec();
}

QSqlQueryModel* Ressource::trier(QString type)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM ressources WHERE type = '" + type + "'");
    return model;
}

QSqlQueryModel* Ressource::statistiques()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT type, COUNT(*) as nombre FROM ressources GROUP BY type");
    return model;
}
