#include "gestion_employe.h"
#include "ui_gestion_employe.h"

gestion_employe::gestion_employe(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::gestion_employe)
{
    ui->setupUi(this);


    QPixmap pix2(":/banner.png");
    if (pix2.isNull()) {
        qDebug() << "Impossible de charger l'image !";
    } else {
        ui->banner->setPixmap(pix2.scaled(
            ui->banner->size(),          // adapte à la taille du QLabel
            Qt::KeepAspectRatio,
            Qt::SmoothTransformation
            ));
    }
    ui->banner->setScaledContents(true);


    QPixmap pix3(":/statistique.png");
    if (pix3.isNull()) {
        qDebug() << "Impossible de charger l'image !";
    } else {
        ui->statistique->setPixmap(pix3.scaled(
            ui->statistique->size(),          // adapte à la taille du QLabel
            Qt::KeepAspectRatio,
            Qt::SmoothTransformation
            ));
    }
    ui->statistique->setScaledContents(true);

    QLineEdit *lineEditRecherche = ui->groupBox_recherche->findChild<QLineEdit*>("lineEdit_recherche");
    if (lineEditRecherche) {
        lineEditRecherche->setPlaceholderText("ID employé");
        qDebug() << "Placeholder ajouté à lineEdit_recherche.";
    } else {
        qDebug() << "Erreur : lineEdit_recherche non trouvé dans groupBox_recherche !";
        ui->statusbar->showMessage("Erreur : Champ de recherche non trouvé !");
    }


}

gestion_employe::~gestion_employe()
{
    delete ui;
}


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



