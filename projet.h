#ifndef PROJET_H
#define PROJET_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMap>
#include <QVector>
#include <QPair>

class Projet
{
private:
    int idClient;
    double budgetPrevu;
    double budgetRealise;
    QString dateDebut;
    QString dateFin;
    QString statut;

public:
    Projet();
    Projet(int idClient, double budgetPrevu, double budgetRealise,
           QString dateDebut, QString dateFin, QString statut = "En cours");

    int getIdClient() const { return idClient; }
    double getBudgetPrevu() const { return budgetPrevu; }
    double getBudgetRealise() const { return budgetRealise; }
    QString getDateDebut() const { return dateDebut; }
    QString getDateFin() const { return dateFin; }
    QString getStatut() const { return statut; }

    void setIdClient(int id) { idClient = id; }
    void setBudgetPrevu(double b) { budgetPrevu = b; }
    void setBudgetRealise(double b) { budgetRealise = b; }
    void setDateDebut(QString d) { dateDebut = d; }
    void setDateFin(QString d) { dateFin = d; }
    void setStatut(QString s) { statut = s; }

    bool ajouter();
    bool modifier(int idClientAncien);
    bool supprimer(int idClient);
    QSqlQueryModel* afficher();
    QSqlQueryModel* rechercher(const QString& motCle);
    static bool existeClient(int idClient);

    static QMap<QString, double> statistiquesPlagesBudget();
    static QVector<QPair<QString, int>> compterProjetsParPlageBudget();
};

#endif // PROJET_H
