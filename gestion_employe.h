#ifndef GESTION_EMPLOYE_H
#define GESTION_EMPLOYE_H

#include <QMainWindow>

#include <QDebug>
#include <QPixmap>
#include <QTableWidget>

#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QMessageBox>
#include <QComboBox>

QT_BEGIN_NAMESPACE

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
};

namespace Ui {
class gestion_employe;
}
QT_END_NAMESPACE

class gestion_employe : public QMainWindow
{
    Q_OBJECT

public:
    gestion_employe(QWidget *parent = nullptr);
    ~gestion_employe();

private:

    Ui::gestion_employe *ui;
};


#endif // GESTION_EMPLOYE_H
