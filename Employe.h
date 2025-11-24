#ifndef EMPLOYE_H
#define EMPLOYE_H

#include <QMainWindow>

#include <QDebug>
#include <QTableWidget>

#include <QMessageBox>
#include <QComboBox>

#include <QString>
#include <QDate>
#include <QStringList>
#include <QList>

#include <QTableWidgetItem>
#include <QTableWidget>
#include <QHeaderView>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>

#include <QVBoxLayout>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>

#include <QSqlQuery>
#include <QSqlQueryModel>


class Employe {
private:
    int id_employe;
    QString nom;
    QString prenom;
    QString email;
    QString poste;
    QString mdp;
    QString questionSecrete;
    QString reponseSecrete;


public:
    // Constructeurs
    Employe();
    Employe(int id_employe, const QString &nom, const QString &prenom, const QString &mdp, const QString &email,
            const QString &poste, const QString &questionSecrete, const QString &reponseSecrete);

    // Getters
    int getId_employe() const;
    QString getNom() const;
    QString getPrenom() const;
    QString getMdp() const;
    QString getEmail() const;
    QString getPoste() const;
    QString getQuestionSecrete() const;
    QString getReponseSecrete() const;

    // Setters
    void setNom(const QString &value);
    void setPrenom(const QString &value);
    void setMdp(const QString &value);
    void setEmail(const QString &value);
    void setPoste(const QString &value);
    void setQuestionSecrete(const QString &value);
    void setReponseSecrete(const QString &value);
    void setId_employe(const int &value);

    bool ajouter();  // Insère en DB
    QSqlQueryModel* afficher();  // Retourne modèle pour tous les employés
    bool supprimer(int id);  // Supprime par ID
    bool modifier();  // Met à jour l'employé courant
    QSqlQueryModel* rechercher(const QString& critere);  // Recherche simple (ex. par nom/email)
    bool idExiste(int id);  // Vérifie existence
};

#endif // EMPLOYE_H
