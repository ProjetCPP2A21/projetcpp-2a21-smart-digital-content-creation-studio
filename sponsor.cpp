#include "sponsor.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QDebug>

bool Sponsor::ajouter() {
    // Oracle : prévoir CONDIDAT_SEQ/trigger équivalent pour SPONSOR (ID auto)
    QSqlQuery q;
    q.prepare(R"(INSERT INTO SPONSOR (NOM_S, TYPE_DE_SPONSOR, MONTANT, MAIL_S, FIN_CONTRAT)
                 VALUES (:nom, :type, :montant, :mail, :fin))");

    q.bindValue(":nom", NOM_S);
    q.bindValue(":type", TYPE_DE_SPONSOR);
    q.bindValue(":montant", MONTANT);
    q.bindValue(":mail", MAIL_S);
    q.bindValue(":fin", FIN_CONTRAT); // QDate → Oracle DATE via ODBC

    if (!q.exec()) {
        qDebug() << "INSERT error:" << q.lastError().text();
        return false;
    }

    // ID généré (méthode simple et portable)
    QSqlQuery qid("SELECT MAX(IDSPONSOR) FROM SPONSOR");
    if (qid.next()) IDSPONSOR = qid.value(0).toInt();

    return true;
}

bool Sponsor::modifier() {
    QSqlQuery q;
    q.prepare(R"(UPDATE SPONSOR
                 SET NOM_S=:nom, TYPE_DE_SPONSOR=:type, MONTANT=:montant, MAIL_S=:mail, FIN_CONTRAT=:fin
                 WHERE IDSPONSOR=:id)");

    q.bindValue(":nom", NOM_S);
    q.bindValue(":type", TYPE_DE_SPONSOR);
    q.bindValue(":montant", MONTANT);
    q.bindValue(":mail", MAIL_S);
    q.bindValue(":fin", FIN_CONTRAT);
    q.bindValue(":id", IDSPONSOR);

    if (!q.exec()) {
        qDebug() << "UPDATE error:" << q.lastError().text();
        return false;
    }
    return (q.numRowsAffected() > 0);
}

bool Sponsor::supprimer(int idSponsor) {
    QSqlQuery q;
    q.prepare("DELETE FROM SPONSOR WHERE IDSPONSOR=:id");
    q.bindValue(":id", idSponsor);
    if (!q.exec()) {
        qDebug() << "DELETE error:" << q.lastError().text();
        return false;
    }
    return (q.numRowsAffected() > 0);
}

bool Sponsor::rechercher() {
    QSqlQuery q;
    q.prepare("SELECT NOM_S, TYPE_DE_SPONSOR, MONTANT, MAIL_S, FIN_CONTRAT FROM SPONSOR WHERE IDSPONSOR=:id");
    q.bindValue(":id", IDSPONSOR);

    if (!q.exec()) {
        qDebug() << "SELECT error:" << q.lastError().text();
        return false;
    }
    if (!q.next()) return false;

    NOM_S            = q.value(0).toString();
    TYPE_DE_SPONSOR  = q.value(1).toString();
    MONTANT          = q.value(2).toDouble();
    MAIL_S           = q.value(3).toString();
    FIN_CONTRAT      = q.value(4).toDate();
    return true;
}

QSqlQueryModel* Sponsor::afficher() {
    auto *m = new QSqlQueryModel();
    m->setQuery("SELECT IDSPONSOR, NOM_S, TYPE_DE_SPONSOR, MONTANT, MAIL_S, FIN_CONTRAT FROM SPONSOR");
    m->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    m->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    m->setHeaderData(2, Qt::Horizontal, QObject::tr("Type"));
    m->setHeaderData(3, Qt::Horizontal, QObject::tr("Montant"));
    m->setHeaderData(4, Qt::Horizontal, QObject::tr("Mail"));
    m->setHeaderData(5, Qt::Horizontal, QObject::tr("Fin contrat"));
    return m;
}
