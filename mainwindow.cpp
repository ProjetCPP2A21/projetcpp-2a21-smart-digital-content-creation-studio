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

    // 🌈 Style uniforme pour tous les boutons
    this->setStyleSheet("QPushButton { background:#2A2E63; color:#EDEAF9; border:1px solid #4B4F87; border-radius:8px; padding:6px 12px; }"
                        "QPushButton:hover { background:#3A3F7A; }"
                        "QPushButton:pressed { background:#1B1D3F; }");

    // === Gestion des images ===
    QPixmap pix2(":/banner.png");
    if (!pix2.isNull())
        ui->banner->setPixmap(pix2.scaled(ui->banner->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ui->banner->setScaledContents(true);

    QPixmap pix3(":/statistique.png");
    if (!pix3.isNull())
        ui->statistique->setPixmap(pix3.scaled(ui->statistique->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ui->statistique->setScaledContents(true);

    // === Connexions des boutons de navigation ===
    connect(ui->pushButton_projet, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentWidget(ui->page_projet);
        setActiveButton(ui->pushButton_projet);
    });
    connect(ui->pushButton_client, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentWidget(ui->page_client);
        setActiveButton(ui->pushButton_client);
    });
    connect(ui->pushButton_employe, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentWidget(ui->page_employe);
        setActiveButton(ui->pushButton_employe);
    });
    connect(ui->pushButton_media, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentWidget(ui->page_media);
        setActiveButton(ui->pushButton_media);
    });
    connect(ui->pushButton_feedback, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentWidget(ui->page_feedback);
        setActiveButton(ui->pushButton_feedback);
    });
    connect(ui->pushButton_categorie, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentWidget(ui->page_categorie);
        setActiveButton(ui->pushButton_categorie);
    });
    connect(ui->pushButton_quitter, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget_principale->setCurrentWidget(ui->page);
    });

    // === Gestion du login ===
    connect(ui->lineEdit_mdp_login, &QLineEdit::returnPressed, this, [=]() {
        ui->stackedWidget_principale->setCurrentIndex(1);
    });
    connect(ui->pushButton_mdp_oublie, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget_login->setCurrentWidget(ui->page_mdp_oublie);
    });
    connect(ui->lineEdit_reponse_2, &QLineEdit::returnPressed, this, [=]() {
        ui->stackedWidget_login->setCurrentWidget(ui->page_nouveau_mdp);
    });
    connect(ui->pushButton_valide_mdp, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget_login->setCurrentWidget(ui->page_login);
    });

    // === Logos ===
    QPixmap pix(":/logo.png");
    if (!pix.isNull())
        ui->logo->setPixmap(pix.scaled(ui->logo->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ui->logo->setScaledContents(true);

    QPixmap pix_bg(":/background+logo.png");
    if (!pix_bg.isNull())
        ui->background->setPixmap(pix_bg.scaled(ui->background->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ui->background->setScaledContents(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setActiveButton(QPushButton *btn)
{
    // 🔄 Réinitialiser sans écraser le style global
    ui->pushButton_projet->setStyleSheet("");
    ui->pushButton_client->setStyleSheet("");
    ui->pushButton_employe->setStyleSheet("");
    ui->pushButton_media->setStyleSheet("");
    ui->pushButton_feedback->setStyleSheet("");
    ui->pushButton_categorie->setStyleSheet("");

    // 🟠 Bouton actif (orange)
    btn->setStyleSheet("background-color:#FF8C00; color:black; font-weight:bold;");
}
