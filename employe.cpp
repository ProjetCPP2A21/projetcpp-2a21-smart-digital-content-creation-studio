#include "Employe.h"
#include "qsqlerror.h"

Employe::Employe() {}

Employe::Employe(int id_employe, const QString &nom, const QString &prenom, const QString &mdp, const QString &email,
                 const QString &poste, const QString &questionSecrete, const QString &reponseSecrete)
    : id_employe(id_employe), nom(nom), prenom(prenom), email(email), poste(poste),
    mdp(mdp),
    questionSecrete(questionSecrete), reponseSecrete(reponseSecrete) {}

// Getters
int Employe::getId_employe() const { return id_employe; }
QString Employe::getNom() const { return nom; }
QString Employe::getPrenom() const { return prenom; }
QString Employe::getMdp() const { return mdp; }
QString Employe::getEmail() const { return email; }
QString Employe::getPoste() const { return poste; }
QString Employe::getQuestionSecrete() const { return questionSecrete; }
QString Employe::getReponseSecrete() const { return reponseSecrete; }

// Setters
void Employe::setNom(const QString &value) { nom = value; }
void Employe::setPrenom(const QString &value) { prenom = value; }
void Employe::setMdp(const QString &value) { mdp = value; }
void Employe::setEmail(const QString &value) { email = value; }
void Employe::setPoste(const QString &value) { poste = value; }
void Employe::setQuestionSecrete(const QString &value) { questionSecrete = value; }
void Employe::setReponseSecrete(const QString &value) { reponseSecrete = value; }
void Employe::setId_employe(const int &value) { id_employe = value; }

bool Employe::ajouter() {
    QSqlQuery query;
    query.prepare("INSERT INTO employe (nom, prenom, email, poste, mdp, questionSecrete, reponseSecrete) "
                  "VALUES (:nom, :prenom, :email, :poste, :mdp, :questionSecrete, :reponseSecrete)");
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":email", email);
    query.bindValue(":poste", poste);
    query.bindValue(":mdp", mdp);
    query.bindValue(":questionSecrete", questionSecrete);
    query.bindValue(":reponseSecrete", reponseSecrete);
    if (query.exec()) {
        // Si ID auto-généré, récupère-le
        if (query.lastInsertId().isValid()) {
            id_employe = query.lastInsertId().toInt();
        }
        return true;
    } else {
        qDebug() << "Erreur ajout employe:" << query.lastError().text();
        return false;
    }
}

QSqlQueryModel* Employe::afficher() {
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM employe ORDER BY id_employe");
    return model;
}

bool Employe::supprimer(int id) {
    QSqlQuery query;
    query.prepare("DELETE FROM employe WHERE id_employe = :id");
    query.bindValue(":id", id);
    if (query.exec()) {
        return true;
    } else {
        qDebug() << "Erreur suppression:" << query.lastError().text();
        return false;
    }
}

bool Employe::modifier() {
    QSqlQuery query;
    query.prepare("UPDATE employe SET nom = :nom, prenom = :prenom, email = :email, poste = :poste, "
                  "mdp = :mdp, questionSecrete = :questionSecrete, reponseSecrete = :reponseSecrete "
                  "WHERE id_employe = :id");
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":email", email);
    query.bindValue(":poste", poste);
    query.bindValue(":mdp", mdp);
    query.bindValue(":questionSecrete", questionSecrete);
    query.bindValue(":reponseSecrete", reponseSecrete);
    query.bindValue(":id", id_employe);
    if (query.exec()) {
        return true;
    } else {
        qDebug() << "Erreur modification:" << query.lastError().text();
        return false;
    }
}

QSqlQueryModel* Employe::rechercher(const QString& critere) {
    QSqlQueryModel *model = new QSqlQueryModel();

    // Détecte si c'est un ID (nombre entier)
    bool isId = false;
    int idValue = critere.toInt(&isId);  // Essaie de convertir en int ; isId=true si succès

    QString req;
    if (isId && idValue > 0) {
        // Recherche exacte par ID
        req = QString("SELECT id_employe AS ID, nom AS Nom, prenom AS Prénom, email AS Email, poste AS Poste "
                      "FROM employe WHERE id_employe = %1 ORDER BY id_employe").arg(idValue);
        qDebug() << "Recherche par ID exact :" << idValue;
    } else {
        // Recherche approximative sur nom/prénom/email (pour texte)
        req = QString("SELECT id_employe AS ID, nom AS Nom, prenom AS Prénom, email AS Email, poste AS Poste "
                      "FROM employe WHERE UPPER(nom) LIKE '%%%1%' OR UPPER(prenom) LIKE '%%%1%' OR UPPER(email) LIKE '%%%1%' "
                      "ORDER BY id_employe").arg(critere.toUpper());  // UPPER pour recherche insensible à la casse
        qDebug() << "Recherche texte LIKE :" << critere;
    }

    model->setQuery(req);
    if (model->lastError().isValid()) {
        qDebug() << "Erreur query recherche :" << model->lastError().text();
    } else {
        qDebug() << "Recherche réussie - Lignes trouvées :" << model->rowCount();
    }
    return model;
}

bool Employe::idExiste(int id) {
    QSqlQuery query;
    query.prepare("SELECT id_employe FROM employe WHERE id_employe = :id");
    query.bindValue(":id", id);
    query.exec();
    return query.next();  // True si au moins une ligne
}

bool Employe::chargerParEmail(const QString& email) {
    QSqlQuery query;
    query.prepare("SELECT * FROM EMPLOYE WHERE EMAIL = :email");
    query.bindValue(":email", email);

    if(query.exec() && query.next()) {
        id_employe = query.value("ID_EMPLOYE").toInt();
        nom = query.value("NOM").toString();
        prenom = query.value("PRENOM").toString();
        mdp = query.value("MDP").toString();
        poste = query.value("POSTE").toString();
        questionSecrete = query.value("questionSecrete").toString();
        reponseSecrete = query.value("reponseSecrete").toString();
        return true;
    }
    return false;
}

bool Employe::mettreAJourMdp(const QString& nouveau) {
    QSqlQuery query;
    query.prepare("UPDATE EMPLOYE SET MDP = :m WHERE ID_EMPLOYE = :id");
    query.bindValue(":m", nouveau);
    query.bindValue(":id", id_employe);
    return query.exec();
}
