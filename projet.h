#ifndef PROJET_H
#define PROJET_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
#include <QDebug>

class Projet
{
private:
    QString clien;  // CLIEN au lieu de client
    double budgetPrevu;
    double budgetRealise;
    QString dateDebut;
    QString dateFin;

public:
    // Constructeurs
    Projet();
    Projet(QString clien, double budgetPrevu, double budgetRealise, QString dateDebut, QString dateFin);

    // Getters
    QString getClien() const { return clien; }
    double getBudgetPrevu() const { return budgetPrevu; }
    double getBudgetRealise() const { return budgetRealise; }
    QString getDateDebut() const { return dateDebut; }
    QString getDateFin() const { return dateFin; }

    // Setters
    void setClien(QString clien) { this->clien = clien; }
    void setBudgetPrevu(double budget) { this->budgetPrevu = budget; }
    void setBudgetRealise(double budget) { this->budgetRealise = budget; }
    void setDateDebut(QString date) { this->dateDebut = date; }
    void setDateFin(QString date) { this->dateFin = date; }

    // Fonctionnalités CRUD
    bool ajouter();
    bool supprimer(QString clien);
    QSqlQueryModel* afficher();
};

#endif // PROJET_H
