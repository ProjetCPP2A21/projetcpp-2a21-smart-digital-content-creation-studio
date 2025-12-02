#ifndef SPONSOR_H
#define SPONSOR_H

#include <QString>
#include <QDate>
#include <QSqlQueryModel>

class Sponsor {
private:
    int     IDSPONSOR{0};
    QString NOM_S;
    QString TYPE_DE_SPONSOR;   // "argent" | "partenariat média" | "produit"
    double  MONTANT{0.0};
    QString MAIL_S;
    QDate   FIN_CONTRAT;

public:
    Sponsor() = default;

    // AJOUT (sans ID)
    Sponsor(const QString& nom,
            const QString& type,
            double montant,
            const QString& mail,
            const QDate& fin)
        : NOM_S(nom), TYPE_DE_SPONSOR(type), MONTANT(montant), MAIL_S(mail), FIN_CONTRAT(fin) {}

    // MODIF/SUPPR (avec ID)
    Sponsor(int id,
            const QString& nom,
            const QString& type,
            double montant,
            const QString& mail,
            const QDate& fin)
        : IDSPONSOR(id), NOM_S(nom), TYPE_DE_SPONSOR(type), MONTANT(montant), MAIL_S(mail), FIN_CONTRAT(fin) {}

    // Getters / Setters
    void setId(int id) { IDSPONSOR = id; }
    int  id() const { return IDSPONSOR; }
    const QString& nom() const { return NOM_S; }
    const QString& type() const { return TYPE_DE_SPONSOR; }
    double montant() const { return MONTANT; }
    const QString& mail() const { return MAIL_S; }
    const QDate&  finContrat() const { return FIN_CONTRAT; }

    void setNom(const QString& v) { NOM_S = v; }
    void setType(const QString& v) { TYPE_DE_SPONSOR = v; }
    void setMontant(double v) { MONTANT = v; }
    void setMail(const QString& v) { MAIL_S = v; }
    void setFinContrat(const QDate& v) { FIN_CONTRAT = v; }

    // CRUD
    bool ajouter();                 // INSERT sans ID (Oracle: séquence+trigger)
    bool modifier();                // UPDATE WHERE IDSPONSOR=:id
    bool supprimer(int idSponsor);  // DELETE WHERE IDSPONSOR=:id
    bool rechercher();              // SELECT … WHERE IDSPONSOR=:id → remplit l'objet
    QSqlQueryModel* afficher();     // Modèle pour tableView
};

#endif // SPONSOR_H
