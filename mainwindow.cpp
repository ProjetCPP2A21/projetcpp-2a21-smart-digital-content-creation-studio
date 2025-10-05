#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPixmap>


#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QMessageBox>
#include <QComboBox>




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
///////////integration/////////////
    //gestion_employe

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

    connect(ui->pushButton_projet, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentWidget(ui->page_projet);
        setActiveButton(ui->pushButton_projet);
    });

    connect(ui->pushButton_client, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentWidget(ui->page_client);
        setActiveButton(ui->pushButton_client);
    });

    connect(ui->pushButton_employe, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentWidget(ui->page_employe);
        setActiveButton(ui->pushButton_employe);
    });

    connect(ui->pushButton_media, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentWidget(ui->page_media);
        setActiveButton(ui->pushButton_media);
    });
    connect(ui->pushButton_feedback, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentWidget(ui->page_feedback);
        setActiveButton(ui->pushButton_feedback);
    });
    connect(ui->pushButton_categorie, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentWidget(ui->page_categorie);
        setActiveButton(ui->pushButton_categorie);
    });
    connect(ui->pushButton_quitter, &QPushButton::clicked, this, [=](){
        ui->stackedWidget_principale->setCurrentWidget(ui->page);
    });

    // Quand on tape Entrée dans le champ mot de passe -> aller à la page 2 du stackedWidget_principale
    connect(ui->lineEdit_mdp_login, &QLineEdit::returnPressed, this, [=]() {
        ui->stackedWidget_principale->setCurrentIndex(1); // page_2
    });
    // Cliquer sur "mot de passe oublié ?" -> aller à la page_mdp_oublie
    connect(ui->pushButton_mdp_oublie, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget_login->setCurrentWidget(ui->page_mdp_oublie);
    });
    // Taper Entrée dans lineEdit_reponse2 -> aller à la page_nouveau_mdp
    connect(ui->lineEdit_reponse_2, &QLineEdit::returnPressed, this, [=]() {
        ui->stackedWidget_login->setCurrentWidget(ui->page_nouveau_mdp);
    });
    // Bouton "Valider" -> retour à la page_login
    connect(ui->pushButton_valide_mdp, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget_login->setCurrentWidget(ui->page_login);
    });


    QPixmap pix(":/logo.png");

    if (pix.isNull()) {
        qDebug() << "Impossible de charger l'image !";
    } else {
        ui->logo->setPixmap(pix.scaled(
            ui->logo->size(),          // adapte à la taille du QLabel
            Qt::KeepAspectRatio,
            Qt::SmoothTransformation
            ));
    }
    ui->logo->setScaledContents(true);

//////////////
    QPixmap pix_bg(":/background+logo.png");

    if (pix_bg.isNull()) {
        qDebug() << "Impossible de charger l'image !";
    } else {
        ui->background->setPixmap(pix_bg.scaled(
            ui->background->size(),          // adapte à la taille du QLabel
            Qt::KeepAspectRatio,
            Qt::SmoothTransformation
            ));
    }
    ui->background->setScaledContents(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::setActiveButton(QPushButton *btn) {
    // Reset tous les boutons
    ui->pushButton_projet->setStyleSheet("background-color: #4B0082; color: white;");
    ui->pushButton_client->setStyleSheet("background-color: #4B0082; color: white;");
    ui->pushButton_employe->setStyleSheet("background-color: #4B0082; color: white;");
    ui->pushButton_media->setStyleSheet("background-color: #4B0082; color: white;");
    ui->pushButton_feedback->setStyleSheet("background-color: #4B0082; color: white;");
    ui->pushButton_categorie->setStyleSheet("background-color: #4B0082; color: white;");

    // Bouton actif
    btn->setStyleSheet("background-color: #FF8C00; color: black; font-weight: bold;");
}


