#ifndef PROJET_H
#define PROJET_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Projet
{
private:
    QString client;          // CHANGÉ : int → QString
    double budgetPrevu;
    double budgetRealise;
    QString dateDebut;
    QString dateFin;

public:
    // Constructeurs
    Projet();
    Projet(QString client, double budgetPrevu, double budgetRealise, QString dateDebut, QString dateFin);

    // Getters
    QString getClient() const { return client; }
    double getBudgetPrevu() const { return budgetPrevu; }
    double getBudgetRealise() const { return budgetRealise; }
    QString getDateDebut() const { return dateDebut; }
    QString getDateFin() const { return dateFin; }

    // Setters
    void setClient(QString c) { client = c; }
    void setBudgetPrevu(double b) { budgetPrevu = b; }
    void setBudgetRealise(double b) { budgetRealise = b; }
    void setDateDebut(QString d) { dateDebut = d; }
    void setDateFin(QString d) { dateFin = d; }

    // Fonctionnalités CRUD
    bool ajouter();
    bool modifier(QString clientAncien);
    bool supprimer(QString client);
    QSqlQueryModel* afficher();

    // Méthodes statiques
    static bool existeClient(QString client);
};

#endif // PROJET_H
