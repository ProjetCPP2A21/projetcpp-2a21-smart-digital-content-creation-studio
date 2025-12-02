#ifndef RESSOURCE_H
#define RESSOURCE_H

#include <QString>
#include <QSqlQueryModel>

class Ressource
{
public:
    Ressource();  // AJOUTÉ : constructeur par défaut obligatoire en Qt 6

    Ressource(const QString &id, const QString &titre, const QString &type,
              const QString &tags, const QString &format, const QString &datecreation,
              const QString &id_projet = QString(), qint64 taille = 0,
              const QString &filepath = QString());

    bool ajouter() const;
    bool modifier() const;
    static bool supprimer(const QString &id);
    static QSqlQueryModel* afficher();

    static int countByType(const QString &type);
    static bool exporterPDF(const QString &chemin);

    QString getId() const { return id_res; }

private:
    QString id_res;
    QString titre;
    QString type;
    QString tags;
    QString format;
    QString datecreation;
    QString id_projet;
    qint64 taille;
    QString filepath;
};

#endif // RESSOURCE_H
