#ifndef RESSOURCE_H
#define RESSOURCE_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Ressource
{
public:
    Ressource();
    Ressource(int, QString, QString, QString);

    int getId();
    QString getType();
    QString getNomProjet();
    QString getNomFichier();

    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier(int, QString, QString, QString);
    QSqlQueryModel* trier(QString type);
    QSqlQueryModel* statistiques();

private:
    int id;
    QString type, nomProjet, nomFichier;
};

#endif // RESSOURCE_H
