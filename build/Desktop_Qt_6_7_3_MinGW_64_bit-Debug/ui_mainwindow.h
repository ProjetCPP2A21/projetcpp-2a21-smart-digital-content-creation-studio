/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget_principale;
    QWidget *page;
    QStackedWidget *stackedWidget_login;
    QWidget *page_login;
    QLabel *label_mdp_login;
    QLineEdit *lineEdit_email_login;
    QLineEdit *lineEdit_mdp_login;
    QLabel *label_connexion;
    QLabel *label_email_login;
    QPushButton *pushButton_mdp_oublie;
    QWidget *page_mdp_oublie;
    QLineEdit *lineEdit_reponse_2;
    QLabel *label_question_secrete;
    QWidget *page_nouveau_mdp;
    QLabel *label_37;
    QLineEdit *lineEdit_nouveau_mdp;
    QPushButton *pushButton_valide_mdp;
    QLabel *background;
    QWidget *page_2;
    QWidget *widget_side_bar;
    QPushButton *pushButton_projet;
    QPushButton *pushButton_client;
    QPushButton *pushButton_employe;
    QPushButton *pushButton_media;
    QLabel *logo;
    QPushButton *pushButton_feedback;
    QPushButton *pushButton_categorie;
    QPushButton *pushButton_quitter;
    QStackedWidget *stackedWidget;
    QWidget *page_projet;
    QPushButton *btnSupprimerProjet;
    QLineEdit *lineEdit_id_supp_2;
    QGroupBox *groupBox_6;
    QLabel *lineEdit_ajoute_5;
    QLineEdit *lineEditClientProjet;
    QLabel *label_nom_3;
    QPushButton *btnAjouterProjet;
    QLabel *label_nom_4;
    QLabel *label_nom_5;
    QLabel *label_nom_6;
    QLineEdit *dateEditDebut;
    QLineEdit *dateEditFin;
    QLineEdit *lineEditBudgetRealise;
    QLabel *label_nom_7;
    QLineEdit *lineEditBudgetPrevu;
    QGroupBox *groupBox_recherche_3;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QTableWidget *tableWidgetProjets;
    QLabel *label_rechercher_2;
    QPushButton *btnTriDateProjet;
    QPushButton *btnTriBudgetProjet;
    QLabel *label_nom_2;
    QPushButton *btnModifierProjet;
    QPushButton *btnRafraichirProjet;
    QPushButton *btnAnnulerModifProjet;
    QWidget *page_client;
    QGroupBox *groupBox_2;
    QLabel *label_61;
    QWidget *layoutWidget;
    QFormLayout *formLayout_4;
    QLabel *label_54;
    QLineEdit *leId_6;
    QLabel *label_55;
    QLineEdit *leNom_6;
    QLabel *label_56;
    QLineEdit *leEmail_6;
    QLabel *label_57;
    QLineEdit *leTel_6;
    QLabel *label_58;
    QComboBox *cbSecteur_6;
    QLabel *label_59;
    QComboBox *cbPays_6;
    QLabel *label_60;
    QDateEdit *deDate_6;
    QPushButton *btnModifier_3;
    QPushButton *btnAjouter_3;
    QPushButton *btnSupprimer_3;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *leSearch_6;
    QPushButton *pushButton_9;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_6;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QTableWidget *tableClients_6;
    QWidget *page_employe;
    QTabWidget *tabWidget;
    QWidget *acceuil;
    QGroupBox *groupBox_recherche;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QTableWidget *tableWidgetEmployes;
    QLineEdit *lineEdit_recherche;
    QLabel *label_rechercher;
    QPushButton *Button_rechercher;
    QPushButton *Button_tri;
    QLabel *banner;
    QPushButton *Button_export;
    QPushButton *Button_supprimer_2;
    QLineEdit *lineEdit_id_supp;
    QGroupBox *groupBox;
    QLabel *lineEdit_ajoute;
    QLineEdit *lineEdit_nom;
    QLabel *label_nom;
    QLabel *label_prenom;
    QLineEdit *lineEdit_prenom;
    QLabel *label_email;
    QLineEdit *lineEdit_email;
    QComboBox *comboBox;
    QLabel *label_poste;
    QPushButton *Button_ajouter;
    QComboBox *comboBox_q;
    QLabel *label_question;
    QLineEdit *lineEdit_reponse;
    QLabel *label_mdp_2;
    QLineEdit *lineEdit_mdp;
    QLabel *label_mdp;
    QWidget *statistiques;
    QWidget *page_media;
    QStackedWidget *stackedWidget_3;
    QWidget *page_3;
    QCheckBox *Imagecheck;
    QCheckBox *Videocheck;
    QCheckBox *audiocheck;
    QLineEdit *RechercheRess;
    QPushButton *AjoutBut;
    QPushButton *PDFBut;
    QPushButton *StatsBut;
    QTableView *RessourceTab;
    QLineEdit *lineNom;
    QPushButton *AjoutBut2;
    QPushButton *ImpBut;
    QPushButton *RetourneBut;
    QLabel *outputajout;
    QLabel *label_nomm;
    QComboBox *comboProj;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *labelStat;
    QLabel *label_stats;
    QLabel *labelAjout;
    QPushButton *statReturnBut;
    QLabel *labelAffichage;
    QWidget *page_4;
    QWidget *page_feedback;
    QPushButton *pushButton_5;
    QWidget *widget;
    QDateEdit *dateEdit_2;
    QLabel *label_7;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_2;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label;
    QLabel *label_6;
    QDateEdit *dateEdit;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLineEdit *lineEdit_14;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *lineEdit_ajoute_2;
    QPushButton *pushButton_3;
    QGroupBox *groupBox_3;
    QTableWidget *tableWidget;
    QLabel *label_31;
    QPushButton *pushButton_4;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QWidget *page_categorie;
    QStackedWidget *stackedWidget_2;
    QWidget *page_5;
    QLabel *label_25;
    QTabWidget *tabWidget_2;
    QWidget *tab_3;
    QGroupBox *groupBox_11;
    QLabel *label_15;
    QLineEdit *lineEdit_nom_9;
    QLabel *label_16;
    QLabel *label_17;
    QLineEdit *lineEdit_montant_2;
    QLabel *label_18;
    QPushButton *ajouterButton_2;
    QLabel *label_19;
    QLineEdit *lineEdit_mail_2;
    QDateEdit *dateEdit_fin_2;
    QComboBox *comboBox_type_2;
    QGroupBox *groupBox_12;
    QLineEdit *lineEdit_searchGlobal_2;
    QGroupBox *groupBox_13;
    QLabel *label_20;
    QLineEdit *lineEdit_id_modify_2;
    QPushButton *modifierButton_2;
    QGroupBox *groupBox_14;
    QLabel *label_sort_2;
    QComboBox *comboBox_4;
    QPushButton *pushButton_19;
    QTableView *tableView_2;
    QPushButton *pushButton_20;
    QLineEdit *lineEdit_9;
    QPushButton *pushButton_21;
    QGroupBox *groupBox_15;
    QLabel *label_21;
    QLineEdit *lineEdit_id_delete_2;
    QPushButton *supprimerButton_2;
    QWidget *tab_4;
    QLabel *label_stats_title_2;
    QLabel *label_stats_info_2;
    QWidget *page_6;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1428, 690);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        stackedWidget_principale = new QStackedWidget(centralwidget);
        stackedWidget_principale->setObjectName("stackedWidget_principale");
        stackedWidget_principale->setGeometry(QRect(-80, 0, 1431, 701));
        page = new QWidget();
        page->setObjectName("page");
        stackedWidget_login = new QStackedWidget(page);
        stackedWidget_login->setObjectName("stackedWidget_login");
        stackedWidget_login->setGeometry(QRect(810, 130, 521, 391));
        stackedWidget_login->setStyleSheet(QString::fromUtf8("/* Le stacked widget avec un d\303\251grad\303\251 orange -> blanc */\n"
"QStackedWidget {\n"
"    border: 2px solid #ffaa00;\n"
"    border-radius: 8px;\n"
"    margin-top: 20px;\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 transparent,\n"
"        stop:1 #ffaa00\n"
"    );\n"
"    color: black;\n"
"}\n"
"\n"
"/* Les pages internes (QWidget enfants directs) doivent \303\252tre transparentes */\n"
"QStackedWidget > QWidget {\n"
"    background: transparent;\n"
"}\n"
"\n"
"/* Boutons \303\240 l'int\303\251rieur */\n"
"QStackedWidget QPushButton {\n"
"    background: #6A0DAD;         /* Mauve */\n"
"    color: white;\n"
"    border: 1px solid #4B0082;\n"
"    border-radius: 6px;\n"
"    padding: 5px 10px;\n"
"}\n"
"QStackedWidget QPushButton:hover {\n"
"    background: #1B1B3A;         /* Bleu fonc\303\251 au survol */\n"
"}\n"
""));
        page_login = new QWidget();
        page_login->setObjectName("page_login");
        label_mdp_login = new QLabel(page_login);
        label_mdp_login->setObjectName("label_mdp_login");
        label_mdp_login->setGeometry(QRect(90, 220, 131, 20));
        label_mdp_login->setStyleSheet(QString::fromUtf8("label->setAutoFillBackground(false);\n"
""));
        lineEdit_email_login = new QLineEdit(page_login);
        lineEdit_email_login->setObjectName("lineEdit_email_login");
        lineEdit_email_login->setEnabled(true);
        lineEdit_email_login->setGeometry(QRect(120, 170, 291, 31));
        lineEdit_email_login->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background: transparent;\n"
"    border: 1px solid #0055ff;\n"
"    color: white;\n"
"}\n"
""));
        lineEdit_mdp_login = new QLineEdit(page_login);
        lineEdit_mdp_login->setObjectName("lineEdit_mdp_login");
        lineEdit_mdp_login->setGeometry(QRect(120, 250, 291, 31));
        lineEdit_mdp_login->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background: transparent;\n"
"    border: 1px solid #0055ff;\n"
"    color: white;\n"
"}\n"
""));
        label_connexion = new QLabel(page_login);
        label_connexion->setObjectName("label_connexion");
        label_connexion->setGeometry(QRect(160, 60, 221, 51));
        label_connexion->setStyleSheet(QString::fromUtf8("label->setAutoFillBackground(false);\n"
""));
        label_email_login = new QLabel(page_login);
        label_email_login->setObjectName("label_email_login");
        label_email_login->setGeometry(QRect(90, 140, 63, 20));
        label_email_login->setStyleSheet(QString::fromUtf8("label->setAutoFillBackground(false);\n"
""));
        pushButton_mdp_oublie = new QPushButton(page_login);
        pushButton_mdp_oublie->setObjectName("pushButton_mdp_oublie");
        pushButton_mdp_oublie->setGeometry(QRect(160, 310, 191, 29));
        pushButton_mdp_oublie->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    color: blue;\n"
"    text-decoration: underline;\n"
"    background: transparent;\n"
"}\n"
""));
        stackedWidget_login->addWidget(page_login);
        page_mdp_oublie = new QWidget();
        page_mdp_oublie->setObjectName("page_mdp_oublie");
        lineEdit_reponse_2 = new QLineEdit(page_mdp_oublie);
        lineEdit_reponse_2->setObjectName("lineEdit_reponse_2");
        lineEdit_reponse_2->setGeometry(QRect(100, 200, 311, 31));
        lineEdit_reponse_2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background: transparent;\n"
"    border: 1px solid #ffffff;\n"
"    color: white;\n"
"}\n"
""));
        lineEdit_reponse_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_question_secrete = new QLabel(page_mdp_oublie);
        label_question_secrete->setObjectName("label_question_secrete");
        label_question_secrete->setGeometry(QRect(110, 110, 321, 71));
        label_question_secrete->setStyleSheet(QString::fromUtf8("label->setAutoFillBackground(false);\n"
""));
        label_question_secrete->setAlignment(Qt::AlignmentFlag::AlignCenter);
        stackedWidget_login->addWidget(page_mdp_oublie);
        page_nouveau_mdp = new QWidget();
        page_nouveau_mdp->setObjectName("page_nouveau_mdp");
        label_37 = new QLabel(page_nouveau_mdp);
        label_37->setObjectName("label_37");
        label_37->setGeometry(QRect(170, 130, 181, 31));
        label_37->setStyleSheet(QString::fromUtf8("label->setAutoFillBackground(false);\n"
""));
        label_37->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lineEdit_nouveau_mdp = new QLineEdit(page_nouveau_mdp);
        lineEdit_nouveau_mdp->setObjectName("lineEdit_nouveau_mdp");
        lineEdit_nouveau_mdp->setGeometry(QRect(100, 180, 331, 31));
        lineEdit_nouveau_mdp->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background: transparent;\n"
"    border: 1px solid #ffffff;\n"
"    color: white;\n"
"}"));
        lineEdit_nouveau_mdp->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        pushButton_valide_mdp = new QPushButton(page_nouveau_mdp);
        pushButton_valide_mdp->setObjectName("pushButton_valide_mdp");
        pushButton_valide_mdp->setGeometry(QRect(210, 230, 90, 29));
        stackedWidget_login->addWidget(page_nouveau_mdp);
        background = new QLabel(page);
        background->setObjectName("background");
        background->setGeometry(QRect(-20, -20, 1451, 711));
        stackedWidget_principale->addWidget(page);
        background->raise();
        stackedWidget_login->raise();
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        widget_side_bar = new QWidget(page_2);
        widget_side_bar->setObjectName("widget_side_bar");
        widget_side_bar->setGeometry(QRect(0, 10, 161, 641));
        widget_side_bar->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #4B0082;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 8px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #8000ff;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #2e0854;\n"
"}\n"
""));
        pushButton_projet = new QPushButton(widget_side_bar);
        pushButton_projet->setObjectName("pushButton_projet");
        pushButton_projet->setGeometry(QRect(0, 130, 161, 71));
        pushButton_projet->setStyleSheet(QString::fromUtf8(""));
        pushButton_client = new QPushButton(widget_side_bar);
        pushButton_client->setObjectName("pushButton_client");
        pushButton_client->setGeometry(QRect(0, 200, 161, 71));
        pushButton_employe = new QPushButton(widget_side_bar);
        pushButton_employe->setObjectName("pushButton_employe");
        pushButton_employe->setGeometry(QRect(0, 270, 161, 71));
        pushButton_media = new QPushButton(widget_side_bar);
        pushButton_media->setObjectName("pushButton_media");
        pushButton_media->setGeometry(QRect(0, 340, 161, 81));
        logo = new QLabel(widget_side_bar);
        logo->setObjectName("logo");
        logo->setGeometry(QRect(10, 10, 141, 111));
        pushButton_feedback = new QPushButton(widget_side_bar);
        pushButton_feedback->setObjectName("pushButton_feedback");
        pushButton_feedback->setGeometry(QRect(0, 420, 161, 71));
        pushButton_categorie = new QPushButton(widget_side_bar);
        pushButton_categorie->setObjectName("pushButton_categorie");
        pushButton_categorie->setGeometry(QRect(0, 490, 161, 81));
        pushButton_quitter = new QPushButton(widget_side_bar);
        pushButton_quitter->setObjectName("pushButton_quitter");
        pushButton_quitter->setGeometry(QRect(0, 570, 161, 71));
        pushButton_quitter->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: red;\n"
"    color: white;\n"
"    border: 1px solid darkred;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: darkred;\n"
"}"));
        stackedWidget = new QStackedWidget(page_2);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(170, 20, 1231, 661));
        page_projet = new QWidget();
        page_projet->setObjectName("page_projet");
        btnSupprimerProjet = new QPushButton(page_projet);
        btnSupprimerProjet->setObjectName("btnSupprimerProjet");
        btnSupprimerProjet->setGeometry(QRect(1140, 570, 81, 29));
        btnSupprimerProjet->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: red;\n"
"    color: white;\n"
"    border: 1px solid darkred;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: darkred;\n"
"}"));
        lineEdit_id_supp_2 = new QLineEdit(page_projet);
        lineEdit_id_supp_2->setObjectName("lineEdit_id_supp_2");
        lineEdit_id_supp_2->setGeometry(QRect(950, 570, 181, 28));
        groupBox_6 = new QGroupBox(page_projet);
        groupBox_6->setObjectName("groupBox_6");
        groupBox_6->setGeometry(QRect(10, 60, 441, 491));
        groupBox_6->setStyleSheet(QString::fromUtf8("background-color: #1E1E2F; color: white; QHeaderView::section { background-color: #5500FF; color: white; }."));
        lineEdit_ajoute_5 = new QLabel(groupBox_6);
        lineEdit_ajoute_5->setObjectName("lineEdit_ajoute_5");
        lineEdit_ajoute_5->setGeometry(QRect(110, 10, 211, 31));
        lineEditClientProjet = new QLineEdit(groupBox_6);
        lineEditClientProjet->setObjectName("lineEditClientProjet");
        lineEditClientProjet->setGeometry(QRect(10, 70, 411, 28));
        label_nom_3 = new QLabel(groupBox_6);
        label_nom_3->setObjectName("label_nom_3");
        label_nom_3->setGeometry(QRect(10, 40, 211, 20));
        btnAjouterProjet = new QPushButton(groupBox_6);
        btnAjouterProjet->setObjectName("btnAjouterProjet");
        btnAjouterProjet->setGeometry(QRect(110, 420, 161, 29));
        btnAjouterProjet->setStyleSheet(QString::fromUtf8(""));
        label_nom_4 = new QLabel(groupBox_6);
        label_nom_4->setObjectName("label_nom_4");
        label_nom_4->setGeometry(QRect(10, 110, 211, 20));
        label_nom_5 = new QLabel(groupBox_6);
        label_nom_5->setObjectName("label_nom_5");
        label_nom_5->setGeometry(QRect(10, 180, 211, 20));
        label_nom_6 = new QLabel(groupBox_6);
        label_nom_6->setObjectName("label_nom_6");
        label_nom_6->setGeometry(QRect(10, 250, 211, 20));
        dateEditDebut = new QLineEdit(groupBox_6);
        dateEditDebut->setObjectName("dateEditDebut");
        dateEditDebut->setGeometry(QRect(10, 140, 411, 28));
        dateEditFin = new QLineEdit(groupBox_6);
        dateEditFin->setObjectName("dateEditFin");
        dateEditFin->setGeometry(QRect(10, 210, 411, 28));
        lineEditBudgetRealise = new QLineEdit(groupBox_6);
        lineEditBudgetRealise->setObjectName("lineEditBudgetRealise");
        lineEditBudgetRealise->setGeometry(QRect(10, 280, 411, 28));
        label_nom_7 = new QLabel(groupBox_6);
        label_nom_7->setObjectName("label_nom_7");
        label_nom_7->setGeometry(QRect(10, 320, 211, 20));
        lineEditBudgetPrevu = new QLineEdit(groupBox_6);
        lineEditBudgetPrevu->setObjectName("lineEditBudgetPrevu");
        lineEditBudgetPrevu->setGeometry(QRect(10, 350, 411, 28));
        groupBox_recherche_3 = new QGroupBox(page_projet);
        groupBox_recherche_3->setObjectName("groupBox_recherche_3");
        groupBox_recherche_3->setGeometry(QRect(460, 170, 761, 371));
        groupBox_recherche_3->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 2px solid #A64B00;\n"
"    border-radius: 8px;\n"
"    margin-top: 20px;\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 white,\n"
"        stop:1 #FB8C00\n"
"    );\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left;\n"
"    padding: 4px;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QGroupBox * {\n"
"    background: transparent;\n"
"    color: black;\n"
"}\n"
"\n"
"QGroupBox QPushButton {\n"
"    background: #6A0DAD;         /* Mauve */\n"
"    color: white;\n"
"    border: 1px solid #4B0082;\n"
"    border-radius: 6px;\n"
"    padding: 5px 10px;\n"
"}\n"
"\n"
"QGroupBox QPushButton:hover {\n"
"    background: #1B1B3A;         /* Bleu fonc\303\251 au survol */\n"
"}\n"
"\n"
"QGroupBox QComboBox {\n"
"    background: #6A0DAD;         /* Mauve */\n"
"    color: white;\n"
"    border: 1px solid #4B0082;\n"
"    border-radius: 6px;\n"
"    padding: 4px 8px;\n"
"}\n"
"\n"
""
                        "QGroupBox QComboBox:hover {\n"
"    background: #1B1B3A;         /* Bleu fonc\303\251 au survol */\n"
"}\n"
"\n"
"QGroupBox QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 20px;\n"
"    border-left: 1px solid #4B0082;\n"
"    border-top-right-radius: 6px;\n"
"    border-bottom-right-radius: 6px;\n"
"    background: #6A0DAD;         /* M\303\252me mauve que le QComboBox */\n"
"}\n"
"\n"
"QGroupBox QComboBox::down-arrow {\n"
"    width: 12px;\n"
"    height: 12px;\n"
"}"));
        scrollArea_2 = new QScrollArea(groupBox_recherche_3);
        scrollArea_2->setObjectName("scrollArea_2");
        scrollArea_2->setGeometry(QRect(10, 100, 741, 251));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName("scrollAreaWidgetContents_2");
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 739, 249));
        tableWidgetProjets = new QTableWidget(scrollAreaWidgetContents_2);
        tableWidgetProjets->setObjectName("tableWidgetProjets");
        tableWidgetProjets->setGeometry(QRect(0, 0, 741, 251));
        scrollArea_2->setWidget(scrollAreaWidgetContents_2);
        label_rechercher_2 = new QLabel(groupBox_recherche_3);
        label_rechercher_2->setObjectName("label_rechercher_2");
        label_rechercher_2->setGeometry(QRect(10, 30, 341, 20));
        btnTriDateProjet = new QPushButton(groupBox_recherche_3);
        btnTriDateProjet->setObjectName("btnTriDateProjet");
        btnTriDateProjet->setGeometry(QRect(230, 60, 121, 29));
        btnTriBudgetProjet = new QPushButton(groupBox_recherche_3);
        btnTriBudgetProjet->setObjectName("btnTriBudgetProjet");
        btnTriBudgetProjet->setGeometry(QRect(590, 60, 151, 29));
        label_nom_2 = new QLabel(groupBox_recherche_3);
        label_nom_2->setObjectName("label_nom_2");
        label_nom_2->setGeometry(QRect(20, 60, 71, 20));
        btnModifierProjet = new QPushButton(page_projet);
        btnModifierProjet->setObjectName("btnModifierProjet");
        btnModifierProjet->setGeometry(QRect(840, 570, 81, 29));
        btnModifierProjet->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: red;\n"
"    color: white; /* Texte blanc pour contraste */\n"
"    border: 1px solid darkred; /* Bordure pour un meilleur rendu */\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: darkred; /* Couleur au survol */\n"
"}"));
        btnRafraichirProjet = new QPushButton(page_projet);
        btnRafraichirProjet->setObjectName("btnRafraichirProjet");
        btnRafraichirProjet->setGeometry(QRect(710, 570, 81, 29));
        btnRafraichirProjet->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: red;\n"
"    color: white; /* Texte blanc pour contraste */\n"
"    border: 1px solid darkred; /* Bordure pour un meilleur rendu */\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: darkred; /* Couleur au survol */\n"
"}"));
        btnAnnulerModifProjet = new QPushButton(page_projet);
        btnAnnulerModifProjet->setObjectName("btnAnnulerModifProjet");
        btnAnnulerModifProjet->setGeometry(QRect(580, 570, 81, 29));
        btnAnnulerModifProjet->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: red;\n"
"    color: white; /* Texte blanc pour contraste */\n"
"    border: 1px solid darkred; /* Bordure pour un meilleur rendu */\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: darkred; /* Couleur au survol */\n"
"}"));
        stackedWidget->addWidget(page_projet);
        page_client = new QWidget();
        page_client->setObjectName("page_client");
        groupBox_2 = new QGroupBox(page_client);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(0, 30, 431, 611));
        groupBox_2->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 2px solid #A64B00;\n"
"    border-radius: 8px;\n"
"    margin-top: 20px;\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 white,\n"
"        stop:1 #FB8C00\n"
"    );\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left;\n"
"    padding: 4px;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QGroupBox * {\n"
"    background: transparent;\n"
"    color: black;\n"
"}\n"
"\n"
"QGroupBox QPushButton {\n"
"    background: #6A0DAD;\n"
"    color: white;\n"
"    border: 1px solid #4B0082;\n"
"    border-radius: 6px;\n"
"    padding: 5px 10px;\n"
"}\n"
"\n"
"QGroupBox QPushButton:hover {\n"
"    background: #1B1B3A;\n"
"}\n"
"\n"
"QGroupBox QComboBox {\n"
"    background: #6A0DAD;\n"
"    color: white;\n"
"    border: 1px solid #4B0082;\n"
"    border-radius: 6px;\n"
"    padding: 4px 8px;\n"
"}\n"
"\n"
"QGroupBox QComboBox:hover {\n"
"    background: #1B1B3A;\n"
"}\n"
"\n"
"QGroup"
                        "Box QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 20px;\n"
"    border-left: 1px solid #4B0082;\n"
"    border-top-right-radius: 6px;\n"
"    border-bottom-right-radius: 6px;\n"
"    background: #6A0DAD;\n"
"}\n"
"\n"
"QGroupBox QComboBox::down-arrow {\n"
"    width: 12px;\n"
"    height: 12px;\n"
"}"));
        label_61 = new QLabel(groupBox_2);
        label_61->setObjectName("label_61");
        label_61->setGeometry(QRect(20, 20, 251, 51));
        QFont font;
        font.setPointSize(18);
        font.setUnderline(true);
        label_61->setFont(font);
        label_61->setLayoutDirection(Qt::LayoutDirection::RightToLeft);
        label_61->setAutoFillBackground(false);
        label_61->setStyleSheet(QString::fromUtf8("selection-background-color: rgb(255, 170, 0);"));
        layoutWidget = new QWidget(groupBox_2);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(30, 80, 374, 455));
        formLayout_4 = new QFormLayout(layoutWidget);
        formLayout_4->setObjectName("formLayout_4");
        formLayout_4->setContentsMargins(0, 0, 0, 0);
        label_54 = new QLabel(layoutWidget);
        label_54->setObjectName("label_54");
        QFont font1;
        font1.setPointSize(10);
        label_54->setFont(font1);
        label_54->setFocusPolicy(Qt::FocusPolicy::TabFocus);
        label_54->setFrameShape(QFrame::Shape::NoFrame);

        formLayout_4->setWidget(0, QFormLayout::LabelRole, label_54);

        leId_6 = new QLineEdit(layoutWidget);
        leId_6->setObjectName("leId_6");

        formLayout_4->setWidget(1, QFormLayout::FieldRole, leId_6);

        label_55 = new QLabel(layoutWidget);
        label_55->setObjectName("label_55");
        label_55->setFont(font1);

        formLayout_4->setWidget(3, QFormLayout::SpanningRole, label_55);

        leNom_6 = new QLineEdit(layoutWidget);
        leNom_6->setObjectName("leNom_6");

        formLayout_4->setWidget(4, QFormLayout::FieldRole, leNom_6);

        label_56 = new QLabel(layoutWidget);
        label_56->setObjectName("label_56");
        label_56->setFont(font1);

        formLayout_4->setWidget(5, QFormLayout::LabelRole, label_56);

        leEmail_6 = new QLineEdit(layoutWidget);
        leEmail_6->setObjectName("leEmail_6");

        formLayout_4->setWidget(6, QFormLayout::FieldRole, leEmail_6);

        label_57 = new QLabel(layoutWidget);
        label_57->setObjectName("label_57");
        label_57->setFont(font1);

        formLayout_4->setWidget(7, QFormLayout::LabelRole, label_57);

        leTel_6 = new QLineEdit(layoutWidget);
        leTel_6->setObjectName("leTel_6");

        formLayout_4->setWidget(8, QFormLayout::FieldRole, leTel_6);

        label_58 = new QLabel(layoutWidget);
        label_58->setObjectName("label_58");
        label_58->setFont(font1);

        formLayout_4->setWidget(9, QFormLayout::SpanningRole, label_58);

        cbSecteur_6 = new QComboBox(layoutWidget);
        cbSecteur_6->addItem(QString());
        cbSecteur_6->addItem(QString());
        cbSecteur_6->addItem(QString());
        cbSecteur_6->addItem(QString());
        cbSecteur_6->addItem(QString());
        cbSecteur_6->addItem(QString());
        cbSecteur_6->setObjectName("cbSecteur_6");
        cbSecteur_6->setIconSize(QSize(130, 20));

        formLayout_4->setWidget(10, QFormLayout::FieldRole, cbSecteur_6);

        label_59 = new QLabel(layoutWidget);
        label_59->setObjectName("label_59");
        label_59->setFont(font1);

        formLayout_4->setWidget(11, QFormLayout::LabelRole, label_59);

        cbPays_6 = new QComboBox(layoutWidget);
        cbPays_6->addItem(QString());
        cbPays_6->addItem(QString());
        cbPays_6->addItem(QString());
        cbPays_6->addItem(QString());
        cbPays_6->addItem(QString());
        cbPays_6->addItem(QString());
        cbPays_6->setObjectName("cbPays_6");

        formLayout_4->setWidget(12, QFormLayout::FieldRole, cbPays_6);

        label_60 = new QLabel(layoutWidget);
        label_60->setObjectName("label_60");
        label_60->setFont(font1);

        formLayout_4->setWidget(13, QFormLayout::SpanningRole, label_60);

        deDate_6 = new QDateEdit(layoutWidget);
        deDate_6->setObjectName("deDate_6");
        deDate_6->setCalendarPopup(true);

        formLayout_4->setWidget(14, QFormLayout::FieldRole, deDate_6);

        btnModifier_3 = new QPushButton(groupBox_2);
        btnModifier_3->setObjectName("btnModifier_3");
        btnModifier_3->setGeometry(QRect(20, 550, 111, 31));
        btnAjouter_3 = new QPushButton(groupBox_2);
        btnAjouter_3->setObjectName("btnAjouter_3");
        btnAjouter_3->setGeometry(QRect(150, 550, 111, 31));
        btnSupprimer_3 = new QPushButton(groupBox_2);
        btnSupprimer_3->setObjectName("btnSupprimer_3");
        btnSupprimer_3->setGeometry(QRect(290, 550, 111, 31));
        layoutWidget_2 = new QWidget(page_client);
        layoutWidget_2->setObjectName("layoutWidget_2");
        layoutWidget_2->setGeometry(QRect(440, 10, 771, 631));
        verticalLayout_5 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        leSearch_6 = new QLineEdit(layoutWidget_2);
        leSearch_6->setObjectName("leSearch_6");
        leSearch_6->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: #6A0DAD;\n"
"    color: white;\n"
"    border: 1px solid #4B0082;\n"
"    border-radius: 6px;\n"
"    padding: 5px 10px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background: #1B1B3A;\n"
"}"));

        horizontalLayout_4->addWidget(leSearch_6);

        pushButton_9 = new QPushButton(layoutWidget_2);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: #6A0DAD;\n"
"    color: white;\n"
"    border: 1px solid #4B0082;\n"
"    border-radius: 6px;\n"
"    padding: 5px 10px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background: #1B1B3A;\n"
"}"));

        horizontalLayout_4->addWidget(pushButton_9);

        pushButton_7 = new QPushButton(layoutWidget_2);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: #6A0DAD;\n"
"    color: white;\n"
"    border: 1px solid #4B0082;\n"
"    border-radius: 6px;\n"
"    padding: 5px 10px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background: #1B1B3A;\n"
"}"));

        horizontalLayout_4->addWidget(pushButton_7);

        pushButton_8 = new QPushButton(layoutWidget_2);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: #6A0DAD;\n"
"    color: white;\n"
"    border: 1px solid #4B0082;\n"
"    border-radius: 6px;\n"
"    padding: 5px 10px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background: #1B1B3A;\n"
"}"));

        horizontalLayout_4->addWidget(pushButton_8);

        pushButton_6 = new QPushButton(layoutWidget_2);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: #6A0DAD;\n"
"    color: white;\n"
"    border: 1px solid #4B0082;\n"
"    border-radius: 6px;\n"
"    padding: 5px 10px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background: #1B1B3A;\n"
"}"));

        horizontalLayout_4->addWidget(pushButton_6);

        pushButton_10 = new QPushButton(layoutWidget_2);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: #6A0DAD;\n"
"    color: white;\n"
"    border: 1px solid #4B0082;\n"
"    border-radius: 6px;\n"
"    padding: 5px 10px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background: #1B1B3A;\n"
"}"));

        horizontalLayout_4->addWidget(pushButton_10);

        pushButton_11 = new QPushButton(layoutWidget_2);
        pushButton_11->setObjectName("pushButton_11");
        pushButton_11->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: #6A0DAD;\n"
"    color: white;\n"
"    border: 1px solid #4B0082;\n"
"    border-radius: 6px;\n"
"    padding: 5px 10px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background: #1B1B3A;\n"
"}"));

        horizontalLayout_4->addWidget(pushButton_11);


        verticalLayout_5->addLayout(horizontalLayout_4);

        tableClients_6 = new QTableWidget(layoutWidget_2);
        if (tableClients_6->columnCount() < 8)
            tableClients_6->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableClients_6->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableClients_6->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableClients_6->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableClients_6->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableClients_6->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableClients_6->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableClients_6->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableClients_6->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        tableClients_6->setObjectName("tableClients_6");
        tableClients_6->setStyleSheet(QString::fromUtf8("\n"
"            QTableWidget {\n"
"    border: none;\n"
"    border-radius: 10px;\n"
"    background-color: #F9F6FF;                /* fond lavande p\303\242le */\n"
"    color: #1E1A2E;                           /* texte anthracite profond */\n"
"    gridline-color: #D3C0FF;                  /* lignes fines lavande */\n"
"    alternate-background-color: #EFE9FF;      /* z\303\251brage doux */\n"
"    selection-background-color: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #8E24AA,\n"
"        stop:1 #CE93D8\n"
"    );                                        /* d\303\251grad\303\251 mauve clair */\n"
"    selection-color: white;\n"
"    font-family: \"Poppins\";\n"
"    font-size: 10.5pt;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #5E35B1,\n"
"        stop:1 #AB47BC\n"
"    );                                        /* d\303\251grad\303\251 violet pastel */\n"
"    color: white;\n"
"    font-weight:"
                        " bold;\n"
"    border: none;\n"
"    padding: 8px;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"QTableCornerButton::section {\n"
"    background: #6A0DAD;\n"
"    border: none;\n"
"}\n"
"\n"
"QScrollBar:vertical {\n"
"    background: #F2E9FF;\n"
"    width: 10px;\n"
"    margin: 0px 0px 0px 0px;\n"
"    border-radius: 5px;\n"
"}\n"
"QScrollBar::handle:vertical {\n"
"    background: #B388FF;\n"
"    border-radius: 5px;\n"
"}\n"
"QScrollBar::handle:vertical:hover {\n"
"    background: #8E24AA;\n"
"}\n"
"\n"
""));
        tableClients_6->setColumnCount(8);

        verticalLayout_5->addWidget(tableClients_6);

        stackedWidget->addWidget(page_client);
        page_employe = new QWidget();
        page_employe->setObjectName("page_employe");
        tabWidget = new QTabWidget(page_employe);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(0, 0, 1231, 651));
        tabWidget->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        tabWidget->setStyleSheet(QString::fromUtf8("/* Les onglets (titres) */\n"
"QTabBar::tab {\n"
"    background: #eeeeee;\n"
"    color: #55007f;          /* couleur du texte */\n"
"    border: 1px solid white;\n"
"    border-top-left-radius: 6px;\n"
"    border-top-right-radius: 6px;\n"
"    padding: 6px 12px;\n"
"    margin-right: 2px;\n"
"}\n"
"\n"
"/* Onglet actif (s\303\251lectionn\303\251) */\n"
"QTabBar::tab:selected {\n"
"    background: white;     /* violet clair */\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"/* Onglet au survol */\n"
"QTabBar::tab:hover {\n"
"    background: #f2e6ff;\n"
"}\n"
""));
        tabWidget->setDocumentMode(false);
        tabWidget->setTabsClosable(false);
        tabWidget->setMovable(false);
        acceuil = new QWidget();
        acceuil->setObjectName("acceuil");
        groupBox_recherche = new QGroupBox(acceuil);
        groupBox_recherche->setObjectName("groupBox_recherche");
        groupBox_recherche->setGeometry(QRect(460, 180, 761, 371));
        groupBox_recherche->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 2px solid #A64B00;\n"
"    border-radius: 8px;\n"
"    margin-top: 20px;\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 white,\n"
"        stop:1 #FB8C00\n"
"    );\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left;\n"
"    padding: 4px;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QGroupBox * {\n"
"    background: transparent;\n"
"    color: black;\n"
"}\n"
"\n"
"QGroupBox QPushButton {\n"
"    background: #6A0DAD;         /* Mauve */\n"
"    color: white;\n"
"    border: 1px solid #4B0082;\n"
"    border-radius: 6px;\n"
"    padding: 5px 10px;\n"
"}\n"
"\n"
"QGroupBox QPushButton:hover {\n"
"    background: #1B1B3A;         /* Bleu fonc\303\251 au survol */\n"
"}\n"
"\n"
"QGroupBox QComboBox {\n"
"    background: #6A0DAD;         /* Mauve */\n"
"    color: white;\n"
"    border: 1px solid #4B0082;\n"
"    border-radius: 6px;\n"
"    padding: 4px 8px;\n"
"}\n"
"\n"
""
                        "QGroupBox QComboBox:hover {\n"
"    background: #1B1B3A;         /* Bleu fonc\303\251 au survol */\n"
"}\n"
"\n"
"QGroupBox QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 20px;\n"
"    border-left: 1px solid #4B0082;\n"
"    border-top-right-radius: 6px;\n"
"    border-bottom-right-radius: 6px;\n"
"    background: #6A0DAD;         /* M\303\252me mauve que le QComboBox */\n"
"}\n"
"\n"
"QGroupBox QComboBox::down-arrow {\n"
"    width: 12px;\n"
"    height: 12px;\n"
"}"));
        scrollArea = new QScrollArea(groupBox_recherche);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(10, 100, 741, 251));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 739, 249));
        tableWidgetEmployes = new QTableWidget(scrollAreaWidgetContents);
        if (tableWidgetEmployes->columnCount() < 5)
            tableWidgetEmployes->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidgetEmployes->setHorizontalHeaderItem(0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidgetEmployes->setHorizontalHeaderItem(1, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidgetEmployes->setHorizontalHeaderItem(2, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidgetEmployes->setHorizontalHeaderItem(3, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidgetEmployes->setHorizontalHeaderItem(4, __qtablewidgetitem12);
        if (tableWidgetEmployes->rowCount() < 7)
            tableWidgetEmployes->setRowCount(7);
        tableWidgetEmployes->setObjectName("tableWidgetEmployes");
        tableWidgetEmployes->setGeometry(QRect(0, 0, 741, 251));
        tableWidgetEmployes->horizontalHeader()->setDefaultSectionSize(145);
        scrollArea->setWidget(scrollAreaWidgetContents);
        lineEdit_recherche = new QLineEdit(groupBox_recherche);
        lineEdit_recherche->setObjectName("lineEdit_recherche");
        lineEdit_recherche->setGeometry(QRect(10, 60, 201, 28));
        lineEdit_recherche->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background: transparent;\n"
"    border: 1px solid#55007f;   /* ou autre couleur pour qu'on voie bien les bords */\n"
"    color:#55007f;                 /* texte */\n"
"}"));
        label_rechercher = new QLabel(groupBox_recherche);
        label_rechercher->setObjectName("label_rechercher");
        label_rechercher->setGeometry(QRect(10, 30, 341, 20));
        Button_rechercher = new QPushButton(groupBox_recherche);
        Button_rechercher->setObjectName("Button_rechercher");
        Button_rechercher->setGeometry(QRect(230, 60, 101, 29));
        Button_tri = new QPushButton(groupBox_recherche);
        Button_tri->setObjectName("Button_tri");
        Button_tri->setGeometry(QRect(620, 60, 121, 29));
        banner = new QLabel(acceuil);
        banner->setObjectName("banner");
        banner->setGeometry(QRect(470, 10, 731, 171));
        banner->setAutoFillBackground(false);
        Button_export = new QPushButton(acceuil);
        Button_export->setObjectName("Button_export");
        Button_export->setGeometry(QRect(470, 570, 211, 29));
        Button_export->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: green;\n"
"    color: white; /* Optionnel : texte blanc pour contraste */\n"
"    border: 1px solid darkgreen; /* Optionnel : bordure pour un meilleur rendu */\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: darkgreen; /* Optionnel : couleur au survol */\n"
"}"));
        Button_supprimer_2 = new QPushButton(acceuil);
        Button_supprimer_2->setObjectName("Button_supprimer_2");
        Button_supprimer_2->setGeometry(QRect(1140, 570, 81, 29));
        Button_supprimer_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: red;\n"
"    color: white; /* Texte blanc pour contraste */\n"
"    border: 1px solid darkred; /* Bordure pour un meilleur rendu */\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: darkred; /* Couleur au survol */\n"
"}"));
        lineEdit_id_supp = new QLineEdit(acceuil);
        lineEdit_id_supp->setObjectName("lineEdit_id_supp");
        lineEdit_id_supp->setGeometry(QRect(950, 570, 181, 28));
        lineEdit_id_supp->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background: transparent;\n"
"    border: 1px solid#55007f;   /* ou autre couleur pour qu'on voie bien les bords */\n"
"    color:#55007f;                 /* texte */\n"
"}"));
        groupBox = new QGroupBox(acceuil);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 40, 441, 551));
        groupBox->setStyleSheet(QString::fromUtf8("background-color: #1E1E2F; color: white; QHeaderView::section { background-color: #5500FF; color: white; }."));
        lineEdit_ajoute = new QLabel(groupBox);
        lineEdit_ajoute->setObjectName("lineEdit_ajoute");
        lineEdit_ajoute->setGeometry(QRect(110, 10, 211, 31));
        lineEdit_nom = new QLineEdit(groupBox);
        lineEdit_nom->setObjectName("lineEdit_nom");
        lineEdit_nom->setGeometry(QRect(10, 60, 411, 28));
        label_nom = new QLabel(groupBox);
        label_nom->setObjectName("label_nom");
        label_nom->setGeometry(QRect(10, 40, 211, 20));
        label_prenom = new QLabel(groupBox);
        label_prenom->setObjectName("label_prenom");
        label_prenom->setGeometry(QRect(10, 100, 211, 20));
        lineEdit_prenom = new QLineEdit(groupBox);
        lineEdit_prenom->setObjectName("lineEdit_prenom");
        lineEdit_prenom->setGeometry(QRect(10, 120, 411, 28));
        label_email = new QLabel(groupBox);
        label_email->setObjectName("label_email");
        label_email->setGeometry(QRect(10, 160, 211, 20));
        lineEdit_email = new QLineEdit(groupBox);
        lineEdit_email->setObjectName("lineEdit_email");
        lineEdit_email->setGeometry(QRect(10, 180, 411, 31));
        comboBox = new QComboBox(groupBox);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(10, 460, 411, 28));
        label_poste = new QLabel(groupBox);
        label_poste->setObjectName("label_poste");
        label_poste->setGeometry(QRect(10, 440, 63, 20));
        Button_ajouter = new QPushButton(groupBox);
        Button_ajouter->setObjectName("Button_ajouter");
        Button_ajouter->setGeometry(QRect(140, 510, 161, 29));
        Button_ajouter->setStyleSheet(QString::fromUtf8(""));
        comboBox_q = new QComboBox(groupBox);
        comboBox_q->addItem(QString());
        comboBox_q->addItem(QString());
        comboBox_q->addItem(QString());
        comboBox_q->addItem(QString());
        comboBox_q->addItem(QString());
        comboBox_q->addItem(QString());
        comboBox_q->setObjectName("comboBox_q");
        comboBox_q->setGeometry(QRect(10, 320, 411, 41));
        label_question = new QLabel(groupBox);
        label_question->setObjectName("label_question");
        label_question->setGeometry(QRect(10, 300, 141, 20));
        lineEdit_reponse = new QLineEdit(groupBox);
        lineEdit_reponse->setObjectName("lineEdit_reponse");
        lineEdit_reponse->setGeometry(QRect(10, 400, 411, 31));
        label_mdp_2 = new QLabel(groupBox);
        label_mdp_2->setObjectName("label_mdp_2");
        label_mdp_2->setGeometry(QRect(10, 373, 211, 20));
        lineEdit_mdp = new QLineEdit(groupBox);
        lineEdit_mdp->setObjectName("lineEdit_mdp");
        lineEdit_mdp->setGeometry(QRect(10, 250, 411, 28));
        label_mdp = new QLabel(groupBox);
        label_mdp->setObjectName("label_mdp");
        label_mdp->setGeometry(QRect(10, 229, 211, 21));
        tabWidget->addTab(acceuil, QString());
        statistiques = new QWidget();
        statistiques->setObjectName("statistiques");
        tabWidget->addTab(statistiques, QString());
        stackedWidget->addWidget(page_employe);
        page_media = new QWidget();
        page_media->setObjectName("page_media");
        stackedWidget_3 = new QStackedWidget(page_media);
        stackedWidget_3->setObjectName("stackedWidget_3");
        stackedWidget_3->setGeometry(QRect(30, 20, 1041, 711));
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        Imagecheck = new QCheckBox(page_3);
        Imagecheck->setObjectName("Imagecheck");
        Imagecheck->setGeometry(QRect(20, 30, 71, 24));
        Videocheck = new QCheckBox(page_3);
        Videocheck->setObjectName("Videocheck");
        Videocheck->setGeometry(QRect(100, 30, 61, 24));
        audiocheck = new QCheckBox(page_3);
        audiocheck->setObjectName("audiocheck");
        audiocheck->setGeometry(QRect(170, 30, 61, 24));
        RechercheRess = new QLineEdit(page_3);
        RechercheRess->setObjectName("RechercheRess");
        RechercheRess->setGeometry(QRect(440, 30, 281, 26));
        AjoutBut = new QPushButton(page_3);
        AjoutBut->setObjectName("AjoutBut");
        AjoutBut->setGeometry(QRect(800, 30, 31, 29));
        PDFBut = new QPushButton(page_3);
        PDFBut->setObjectName("PDFBut");
        PDFBut->setGeometry(QRect(840, 30, 61, 29));
        StatsBut = new QPushButton(page_3);
        StatsBut->setObjectName("StatsBut");
        StatsBut->setGeometry(QRect(920, 30, 61, 29));
        RessourceTab = new QTableView(page_3);
        RessourceTab->setObjectName("RessourceTab");
        RessourceTab->setGeometry(QRect(40, 70, 1001, 531));
        lineNom = new QLineEdit(page_3);
        lineNom->setObjectName("lineNom");
        lineNom->setGeometry(QRect(538, 250, 251, 26));
        AjoutBut2 = new QPushButton(page_3);
        AjoutBut2->setObjectName("AjoutBut2");
        AjoutBut2->setGeometry(QRect(548, 500, 93, 29));
        ImpBut = new QPushButton(page_3);
        ImpBut->setObjectName("ImpBut");
        ImpBut->setGeometry(QRect(538, 300, 251, 29));
        RetourneBut = new QPushButton(page_3);
        RetourneBut->setObjectName("RetourneBut");
        RetourneBut->setGeometry(QRect(688, 500, 93, 29));
        outputajout = new QLabel(page_3);
        outputajout->setObjectName("outputajout");
        outputajout->setGeometry(QRect(548, 340, 231, 141));
        label_nomm = new QLabel(page_3);
        label_nomm->setObjectName("label_nomm");
        label_nomm->setGeometry(QRect(378, 250, 121, 20));
        comboProj = new QComboBox(page_3);
        comboProj->setObjectName("comboProj");
        comboProj->setGeometry(QRect(538, 210, 251, 26));
        label_8 = new QLabel(page_3);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(308, 190, 501, 351));
        label_9 = new QLabel(page_3);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(330, 210, 201, 20));
        labelStat = new QLabel(page_3);
        labelStat->setObjectName("labelStat");
        labelStat->setGeometry(QRect(340, 110, 521, 561));
        labelStat->setStyleSheet(QString::fromUtf8("QLabel#labelStat{\n"
"\n"
"	background-image: url(:/new/te/TD_BD.jpg);\n"
"}"));
        label_stats = new QLabel(page_3);
        label_stats->setObjectName("label_stats");
        label_stats->setGeometry(QRect(300, 130, 521, 61));
        labelAjout = new QLabel(page_3);
        labelAjout->setObjectName("labelAjout");
        labelAjout->setGeometry(QRect(340, 190, 471, 351));
        statReturnBut = new QPushButton(page_3);
        statReturnBut->setObjectName("statReturnBut");
        statReturnBut->setGeometry(QRect(700, 110, 93, 29));
        labelAffichage = new QLabel(page_3);
        labelAffichage->setObjectName("labelAffichage");
        labelAffichage->setGeometry(QRect(100, 200, 351, 401));
        labelAffichage->setScaledContents(true);
        stackedWidget_3->addWidget(page_3);
        label_8->raise();
        label_9->raise();
        labelAjout->raise();
        RessourceTab->raise();
        label_stats->raise();
        Imagecheck->raise();
        Videocheck->raise();
        audiocheck->raise();
        RechercheRess->raise();
        AjoutBut->raise();
        PDFBut->raise();
        StatsBut->raise();
        lineNom->raise();
        AjoutBut2->raise();
        ImpBut->raise();
        RetourneBut->raise();
        outputajout->raise();
        statReturnBut->raise();
        labelStat->raise();
        labelAffichage->raise();
        label_nomm->raise();
        comboProj->raise();
        page_4 = new QWidget();
        page_4->setObjectName("page_4");
        stackedWidget_3->addWidget(page_4);
        stackedWidget->addWidget(page_media);
        page_feedback = new QWidget();
        page_feedback->setObjectName("page_feedback");
        pushButton_5 = new QPushButton(page_feedback);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(410, 490, 111, 29));
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: green;\n"
"    color: white; /* Optionnel : texte blanc pour contraste */\n"
"    border: 1px solid darkgreen; /* Optionnel : bordure pour un meilleur rendu */\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: darkgreen; /* Optionnel : couleur au survol */\n"
"}"));
        widget = new QWidget(page_feedback);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(10, 20, 391, 571));
        widget->setStyleSheet(QString::fromUtf8("background-color: #1E1E2F; color: white; QHeaderView::section { background-color: #5500FF; color: white; }."));
        dateEdit_2 = new QDateEdit(widget);
        dateEdit_2->setObjectName("dateEdit_2");
        dateEdit_2->setGeometry(QRect(160, 450, 181, 29));
        label_7 = new QLabel(widget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(10, 490, 121, 20));
        lineEdit_6 = new QLineEdit(widget);
        lineEdit_6->setObjectName("lineEdit_6");
        lineEdit_6->setGeometry(QRect(140, 310, 241, 28));
        lineEdit_2 = new QLineEdit(widget);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(140, 240, 241, 28));
        label_4 = new QLabel(widget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(30, 310, 63, 20));
        label_5 = new QLabel(widget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(30, 380, 91, 20));
        label = new QLabel(widget);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 100, 101, 20));
        label_6 = new QLabel(widget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(30, 450, 63, 20));
        dateEdit = new QDateEdit(widget);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setGeometry(QRect(160, 380, 181, 29));
        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(30, 240, 63, 20));
        lineEdit_3 = new QLineEdit(widget);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(140, 170, 241, 28));
        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(140, 100, 241, 28));
        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 170, 131, 20));
        lineEdit_14 = new QLineEdit(widget);
        lineEdit_14->setObjectName("lineEdit_14");
        lineEdit_14->setGeometry(QRect(140, 490, 241, 28));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(80, 530, 90, 29));
        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(230, 530, 90, 29));
        lineEdit_ajoute_2 = new QLabel(widget);
        lineEdit_ajoute_2->setObjectName("lineEdit_ajoute_2");
        lineEdit_ajoute_2->setGeometry(QRect(90, 30, 211, 31));
        pushButton_3 = new QPushButton(page_feedback);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(1130, 490, 90, 29));
        pushButton_3->setStyleSheet(QString::fromUtf8("alternate-background-color: rgb(204, 0, 3);\n"
"background-color: rgb(157, 7, 10);"));
        groupBox_3 = new QGroupBox(page_feedback);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(410, 60, 811, 421));
        groupBox_3->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 2px solid #A64B00;\n"
"    border-radius: 8px;\n"
"    margin-top: 20px;\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 white,\n"
"        stop:1 #FB8C00\n"
"    );\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left;\n"
"    padding: 4px;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QGroupBox * {\n"
"    background: transparent;\n"
"    color: black;\n"
"}\n"
"\n"
"QGroupBox QPushButton {\n"
"    background: #6A0DAD;         /* Mauve */\n"
"    color: white;\n"
"    border: 1px solid #4B0082;\n"
"    border-radius: 6px;\n"
"    padding: 5px 10px;\n"
"}\n"
"\n"
"QGroupBox QPushButton:hover {\n"
"    background: #1B1B3A;         /* Bleu fonc\303\251 au survol */\n"
"}\n"
"\n"
"QGroupBox QComboBox {\n"
"    background: #6A0DAD;         /* Mauve */\n"
"    color: white;\n"
"    border: 1px solid #4B0082;\n"
"    border-radius: 6px;\n"
"    padding: 4px 8px;\n"
"}\n"
"\n"
""
                        "QGroupBox QComboBox:hover {\n"
"    background: #1B1B3A;         /* Bleu fonc\303\251 au survol */\n"
"}\n"
"\n"
"QGroupBox QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 20px;\n"
"    border-left: 1px solid #4B0082;\n"
"    border-top-right-radius: 6px;\n"
"    border-bottom-right-radius: 6px;\n"
"    background: #6A0DAD;         /* M\303\252me mauve que le QComboBox */\n"
"}\n"
"\n"
"QGroupBox QComboBox::down-arrow {\n"
"    width: 12px;\n"
"    height: 12px;\n"
"}"));
        tableWidget = new QTableWidget(groupBox_3);
        if (tableWidget->columnCount() < 7)
            tableWidget->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem19);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(10, 90, 791, 311));
        tableWidget->setStyleSheet(QString::fromUtf8(""));
        tableWidget->horizontalHeader()->setDefaultSectionSize(113);
        label_31 = new QLabel(groupBox_3);
        label_31->setObjectName("label_31");
        label_31->setGeometry(QRect(10, 40, 63, 20));
        pushButton_4 = new QPushButton(groupBox_3);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(460, 40, 90, 29));
        pushButton_4->setStyleSheet(QString::fromUtf8(""));
        lineEdit_4 = new QLineEdit(groupBox_3);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(60, 40, 371, 28));
        lineEdit_4->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background: transparent;\n"
"    border: 1px solid#55007f;   /* ou autre couleur pour qu'on voie bien les bords */\n"
"    color:#55007f;                 /* texte */\n"
"}\n"
""));
        lineEdit_5 = new QLineEdit(page_feedback);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setGeometry(QRect(750, 490, 371, 28));
        lineEdit_5->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background: transparent;\n"
"    border: 1px solid#55007f;   /* ou autre couleur pour qu'on voie bien les bords */\n"
"    color:#55007f;                 /* texte */\n"
"}"));
        stackedWidget->addWidget(page_feedback);
        page_categorie = new QWidget();
        page_categorie->setObjectName("page_categorie");
        stackedWidget_2 = new QStackedWidget(page_categorie);
        stackedWidget_2->setObjectName("stackedWidget_2");
        stackedWidget_2->setGeometry(QRect(0, -110, 1221, 768));
        stackedWidget_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        page_5 = new QWidget();
        page_5->setObjectName("page_5");
        label_25 = new QLabel(page_5);
        label_25->setObjectName("label_25");
        label_25->setGeometry(QRect(92, 30, 171, 41));
        tabWidget_2 = new QTabWidget(page_5);
        tabWidget_2->setObjectName("tabWidget_2");
        tabWidget_2->setGeometry(QRect(0, 110, 1161, 701));
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        groupBox_11 = new QGroupBox(tab_3);
        groupBox_11->setObjectName("groupBox_11");
        groupBox_11->setGeometry(QRect(10, 20, 350, 281));
        groupBox_11->setStyleSheet(QString::fromUtf8("background-color: #1E1E2F; color: white; QHeaderView::section { background-color: #5500FF; color: white; }."));
        label_15 = new QLabel(groupBox_11);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(20, 35, 120, 20));
        lineEdit_nom_9 = new QLineEdit(groupBox_11);
        lineEdit_nom_9->setObjectName("lineEdit_nom_9");
        lineEdit_nom_9->setGeometry(QRect(150, 30, 180, 31));
        label_16 = new QLabel(groupBox_11);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(20, 60, 120, 20));
        label_17 = new QLabel(groupBox_11);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(20, 90, 130, 20));
        lineEdit_montant_2 = new QLineEdit(groupBox_11);
        lineEdit_montant_2->setObjectName("lineEdit_montant_2");
        lineEdit_montant_2->setGeometry(QRect(150, 90, 180, 31));
        label_18 = new QLabel(groupBox_11);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(20, 120, 121, 20));
        ajouterButton_2 = new QPushButton(groupBox_11);
        ajouterButton_2->setObjectName("ajouterButton_2");
        ajouterButton_2->setGeometry(QRect(70, 230, 210, 40));
        label_19 = new QLabel(groupBox_11);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(20, 150, 50, 20));
        lineEdit_mail_2 = new QLineEdit(groupBox_11);
        lineEdit_mail_2->setObjectName("lineEdit_mail_2");
        lineEdit_mail_2->setGeometry(QRect(150, 150, 180, 31));
        dateEdit_fin_2 = new QDateEdit(groupBox_11);
        dateEdit_fin_2->setObjectName("dateEdit_fin_2");
        dateEdit_fin_2->setGeometry(QRect(150, 120, 111, 31));
        comboBox_type_2 = new QComboBox(groupBox_11);
        comboBox_type_2->addItem(QString());
        comboBox_type_2->addItem(QString());
        comboBox_type_2->addItem(QString());
        comboBox_type_2->setObjectName("comboBox_type_2");
        comboBox_type_2->setGeometry(QRect(150, 60, 161, 31));
        comboBox_type_2->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    min-width: 45  px;\n"
"    max-width: 200 px;\n"
"    height: 30px;                 /* hauteur standard */\n"
"    border: 1px solid #ccc;       /* bordure grise claire */\n"
"    border-radius: 0px;           /* pas arrondi \342\206\222 carr\303\251 */\n"
"    background-color: #ffffff;    /* fond blanc */\n"
"    color: black;                 /* texte noir */\n"
"    padding: 4px;                 /* petite marge interne */\n"
"    font-size: 13px;\n"
"}\n"
""));
        groupBox_12 = new QGroupBox(tab_3);
        groupBox_12->setObjectName("groupBox_12");
        groupBox_12->setGeometry(QRect(10, 305, 350, 140));
        groupBox_12->setStyleSheet(QString::fromUtf8("background-color: #1E1E2F; color: white; QHeaderView::section { background-color: #5500FF; color: white; }."));
        lineEdit_searchGlobal_2 = new QLineEdit(groupBox_12);
        lineEdit_searchGlobal_2->setObjectName("lineEdit_searchGlobal_2");
        lineEdit_searchGlobal_2->setGeometry(QRect(20, 59, 310, 31));
        groupBox_13 = new QGroupBox(tab_3);
        groupBox_13->setObjectName("groupBox_13");
        groupBox_13->setGeometry(QRect(10, 450, 350, 160));
        groupBox_13->setStyleSheet(QString::fromUtf8("background-color: #1E1E2F; color: white; QHeaderView::section { background-color: #5500FF; color: white; }."));
        label_20 = new QLabel(groupBox_13);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(20, 70, 130, 20));
        lineEdit_id_modify_2 = new QLineEdit(groupBox_13);
        lineEdit_id_modify_2->setObjectName("lineEdit_id_modify_2");
        lineEdit_id_modify_2->setGeometry(QRect(150, 64, 180, 41));
        modifierButton_2 = new QPushButton(groupBox_13);
        modifierButton_2->setObjectName("modifierButton_2");
        modifierButton_2->setGeometry(QRect(100, 110, 150, 35));
        groupBox_14 = new QGroupBox(tab_3);
        groupBox_14->setObjectName("groupBox_14");
        groupBox_14->setGeometry(QRect(370, -30, 751, 451));
        groupBox_14->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 2px solid #A64B00;\n"
"    border-radius: 8px;\n"
"    margin-top: 20px;\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 white,\n"
"        stop:1 #FB8C00\n"
"    );\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left;\n"
"    padding: 4px;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QGroupBox * {\n"
"    background: transparent;\n"
"    color: black;\n"
"}\n"
"\n"
"QGroupBox QPushButton {\n"
"    background: #6A0DAD;         /* Mauve */\n"
"    color: white;\n"
"    border: 1px solid #4B0082;\n"
"    border-radius: 6px;\n"
"    padding: 5px 10px;\n"
"}\n"
"\n"
"QGroupBox QPushButton:hover {\n"
"    background: #1B1B3A;         /* Bleu fonc\303\251 au survol */\n"
"}\n"
"\n"
"QGroupBox QComboBox {\n"
"    background: #6A0DAD;         /* Mauve */\n"
"    color: white;\n"
"    border: 1px solid #4B0082;\n"
"    border-radius: 6px;\n"
"    padding: 4px 8px;\n"
"}\n"
"\n"
""
                        "QGroupBox QComboBox:hover {\n"
"    background: #1B1B3A;         /* Bleu fonc\303\251 au survol */\n"
"}\n"
"\n"
"QGroupBox QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 20px;\n"
"    border-left: 1px solid #4B0082;\n"
"    border-top-right-radius: 6px;\n"
"    border-bottom-right-radius: 6px;\n"
"    background: #6A0DAD;         /* M\303\252me mauve que le QComboBox */\n"
"}\n"
"\n"
"QGroupBox QComboBox::down-arrow {\n"
"    width: 12px;\n"
"    height: 12px;\n"
"}"));
        label_sort_2 = new QLabel(groupBox_14);
        label_sort_2->setObjectName("label_sort_2");
        label_sort_2->setGeometry(QRect(20, 80, 80, 20));
        comboBox_4 = new QComboBox(groupBox_14);
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->setObjectName("comboBox_4");
        comboBox_4->setGeometry(QRect(108, 73, 150, 31));
        pushButton_19 = new QPushButton(groupBox_14);
        pushButton_19->setObjectName("pushButton_19");
        pushButton_19->setGeometry(QRect(266, 70, 80, 30));
        tableView_2 = new QTableView(groupBox_14);
        tableView_2->setObjectName("tableView_2");
        tableView_2->setGeometry(QRect(5, 110, 611, 291));
        pushButton_20 = new QPushButton(groupBox_14);
        pushButton_20->setObjectName("pushButton_20");
        pushButton_20->setGeometry(QRect(50, 410, 150, 40));
        lineEdit_9 = new QLineEdit(groupBox_14);
        lineEdit_9->setObjectName("lineEdit_9");
        lineEdit_9->setGeometry(QRect(-80, 50, 181, 31));
        pushButton_21 = new QPushButton(tab_3);
        pushButton_21->setObjectName("pushButton_21");
        pushButton_21->setGeometry(QRect(980, 530, 120, 40));
        pushButton_21->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #607D8B, stop:1 #455A64);\n"
"}\n"
"QPushButton:hover {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #455A64, stop:1 #263238);\n"
"}"));
        groupBox_15 = new QGroupBox(tab_3);
        groupBox_15->setObjectName("groupBox_15");
        groupBox_15->setGeometry(QRect(380, 450, 350, 160));
        groupBox_15->setStyleSheet(QString::fromUtf8("background-color: #1E1E2F; color: white; QHeaderView::section { background-color: #5500FF; color: white; }."));
        label_21 = new QLabel(groupBox_15);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(20, 70, 130, 20));
        lineEdit_id_delete_2 = new QLineEdit(groupBox_15);
        lineEdit_id_delete_2->setObjectName("lineEdit_id_delete_2");
        lineEdit_id_delete_2->setGeometry(QRect(120, 60, 180, 41));
        supprimerButton_2 = new QPushButton(groupBox_15);
        supprimerButton_2->setObjectName("supprimerButton_2");
        supprimerButton_2->setGeometry(QRect(100, 110, 150, 35));
        tabWidget_2->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        label_stats_title_2 = new QLabel(tab_4);
        label_stats_title_2->setObjectName("label_stats_title_2");
        label_stats_title_2->setGeometry(QRect(20, 20, 1100, 40));
        label_stats_title_2->setStyleSheet(QString::fromUtf8("font-size: 22px; color: #009688; font-weight: bold;"));
        label_stats_title_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_stats_info_2 = new QLabel(tab_4);
        label_stats_info_2->setObjectName("label_stats_info_2");
        label_stats_info_2->setGeometry(QRect(50, 80, 1050, 500));
        label_stats_info_2->setStyleSheet(QString::fromUtf8("font-size: 16px;\n"
"color: #37474F;\n"
"background: white;\n"
"border: 2px solid #009688;\n"
"border-radius: 10px;\n"
"padding: 30px;"));
        label_stats_info_2->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);
        label_stats_info_2->setWordWrap(true);
        tabWidget_2->addTab(tab_4, QString());
        stackedWidget_2->addWidget(page_5);
        page_6 = new QWidget();
        page_6->setObjectName("page_6");
        stackedWidget_2->addWidget(page_6);
        stackedWidget->addWidget(page_categorie);
        stackedWidget_principale->addWidget(page_2);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        stackedWidget_principale->setCurrentIndex(1);
        stackedWidget_login->setCurrentIndex(0);
        stackedWidget->setCurrentIndex(1);
        tabWidget->setCurrentIndex(0);
        stackedWidget_3->setCurrentIndex(0);
        stackedWidget_2->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_mdp_login->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:700; color:#55007f;\">mots de passe:</span></p></body></html>", nullptr));
        label_connexion->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:26pt; font-weight:700; color:#ffaa00;\">Connexion</span></p></body></html>", nullptr));
        label_email_login->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:700; color:#55007f;\">Email:</span></p></body></html>", nullptr));
        pushButton_mdp_oublie->setText(QCoreApplication::translate("MainWindow", "mot de passe oubli\303\251 ?", nullptr));
        label_question_secrete->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><br/></p></body></html>", nullptr));
        label_37->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:700; color:#55007f;\">nouveau mot de passe</span></p></body></html>", nullptr));
        pushButton_valide_mdp->setText(QCoreApplication::translate("MainWindow", "valid\303\251", nullptr));
        background->setText(QString());
        pushButton_projet->setText(QCoreApplication::translate("MainWindow", "Projet", nullptr));
        pushButton_client->setText(QCoreApplication::translate("MainWindow", "Client", nullptr));
        pushButton_employe->setText(QCoreApplication::translate("MainWindow", "Employe", nullptr));
        pushButton_media->setText(QCoreApplication::translate("MainWindow", "reccources", nullptr));
        logo->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        pushButton_feedback->setText(QCoreApplication::translate("MainWindow", "campagne", nullptr));
        pushButton_categorie->setText(QCoreApplication::translate("MainWindow", "sponsor", nullptr));
        pushButton_quitter->setText(QCoreApplication::translate("MainWindow", "quitter", nullptr));
        btnSupprimerProjet->setText(QCoreApplication::translate("MainWindow", "supprimer", nullptr));
#if QT_CONFIG(whatsthis)
        groupBox_6->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        groupBox_6->setTitle(QString());
        lineEdit_ajoute_5->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:700; color:#ffaa00;\">formulaire projet</span></p></body></html>", nullptr));
        label_nom_3->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:700; color:#55007f;\">client:</span></p></body></html>", nullptr));
        btnAjouterProjet->setText(QCoreApplication::translate("MainWindow", "ajouter", nullptr));
        label_nom_4->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:700; color:#55007f;\"> Date debut:</span></p></body></html>", nullptr));
        label_nom_5->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:700; color:#55007f;\">Date fin:</span></p></body></html>", nullptr));
        label_nom_6->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:700; color:#55007f;\">Budget rialiser:</span></p></body></html>", nullptr));
        label_nom_7->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:700; color:#55007f;\">Budget prevu:</span></p></body></html>", nullptr));
        groupBox_recherche_3->setTitle(QString());
        label_rechercher_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:700; color:#00007f;\">recherche d'un projet</span></p></body></html>", nullptr));
        btnTriDateProjet->setText(QCoreApplication::translate("MainWindow", "Trier par date", nullptr));
        btnTriBudgetProjet->setText(QCoreApplication::translate("MainWindow", "Trier par budget", nullptr));
        label_nom_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:700; color:#55007f;\">type:</span></p></body></html>", nullptr));
        btnModifierProjet->setText(QCoreApplication::translate("MainWindow", "modifier", nullptr));
        btnRafraichirProjet->setText(QCoreApplication::translate("MainWindow", "Rafra\303\256chir", nullptr));
        btnAnnulerModifProjet->setText(QCoreApplication::translate("MainWindow", "annuler ", nullptr));
        groupBox_2->setTitle(QString());
        label_61->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:700; text-decoration:none; color:#aa00ff;\">Formulaire client</span></p></body></html>", nullptr));
        label_54->setText(QCoreApplication::translate("MainWindow", "ID :", nullptr));
        leId_6->setText(QString());
        leId_6->setPlaceholderText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        label_55->setText(QCoreApplication::translate("MainWindow", "Nom et Pr\303\251nom :", nullptr));
        leNom_6->setText(QString());
        leNom_6->setPlaceholderText(QCoreApplication::translate("MainWindow", "Nom et Pr\303\251nom", nullptr));
        label_56->setText(QCoreApplication::translate("MainWindow", "Email :", nullptr));
        leEmail_6->setPlaceholderText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        label_57->setText(QCoreApplication::translate("MainWindow", "T\303\251l\303\251phone :", nullptr));
        leTel_6->setPlaceholderText(QCoreApplication::translate("MainWindow", "T\303\251l\303\251phone", nullptr));
        label_58->setText(QCoreApplication::translate("MainWindow", "Secteur d'Activit\303\251 :", nullptr));
        cbSecteur_6->setItemText(0, QCoreApplication::translate("MainWindow", "Secteur...", nullptr));
        cbSecteur_6->setItemText(1, QCoreApplication::translate("MainWindow", "Design et Multim\303\251dia", nullptr));
        cbSecteur_6->setItemText(2, QCoreApplication::translate("MainWindow", "D\303\251veloppement Web", nullptr));
        cbSecteur_6->setItemText(3, QCoreApplication::translate("MainWindow", "Marketing et Communication digital", nullptr));
        cbSecteur_6->setItemText(4, QCoreApplication::translate("MainWindow", "Production Vid\303\251o", nullptr));
        cbSecteur_6->setItemText(5, QCoreApplication::translate("MainWindow", "\303\211dition & Contenu \303\251crit", nullptr));

        cbSecteur_6->setPlaceholderText(QCoreApplication::translate("MainWindow", "Secteur", nullptr));
        label_59->setText(QCoreApplication::translate("MainWindow", "Ville :", nullptr));
        cbPays_6->setItemText(0, QCoreApplication::translate("MainWindow", "Ville...", nullptr));
        cbPays_6->setItemText(1, QCoreApplication::translate("MainWindow", "Tunis", nullptr));
        cbPays_6->setItemText(2, QCoreApplication::translate("MainWindow", "Bizerte", nullptr));
        cbPays_6->setItemText(3, QCoreApplication::translate("MainWindow", "Sousse", nullptr));
        cbPays_6->setItemText(4, QCoreApplication::translate("MainWindow", "Zaghouan", nullptr));
        cbPays_6->setItemText(5, QCoreApplication::translate("MainWindow", "Nabeul", nullptr));

        cbPays_6->setPlaceholderText(QCoreApplication::translate("MainWindow", "Ville", nullptr));
        label_60->setText(QCoreApplication::translate("MainWindow", "Date d'Inscription :", nullptr));
        deDate_6->setDisplayFormat(QCoreApplication::translate("MainWindow", "yyyy-MM-dd", nullptr));
        btnModifier_3->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        btnAjouter_3->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        btnSupprimer_3->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        leSearch_6->setPlaceholderText(QCoreApplication::translate("MainWindow", "Recherche...", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "Trier", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "Export CSV", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "Statistiques", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "Clients Inactifs", nullptr));
        pushButton_10->setText(QCoreApplication::translate("MainWindow", "Fiche Client", nullptr));
        pushButton_11->setText(QCoreApplication::translate("MainWindow", "Map Clients", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableClients_6->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Activit\303\251", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableClients_6->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableClients_6->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableClients_6->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableClients_6->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "T\303\251l\303\251phone", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableClients_6->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "SecteurActivit\303\251", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableClients_6->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "Ville", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableClients_6->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "DateCr\303\251ation", nullptr));
        groupBox_recherche->setTitle(QString());
        QTableWidgetItem *___qtablewidgetitem8 = tableWidgetEmployes->horizontalHeaderItem(0);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", " ID   ", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidgetEmployes->horizontalHeaderItem(1);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "Poste    ", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidgetEmployes->horizontalHeaderItem(2);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "Nom    ", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidgetEmployes->horizontalHeaderItem(3);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("MainWindow", " Pr\303\251nom   ", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidgetEmployes->horizontalHeaderItem(4);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("MainWindow", "Email    ", nullptr));
        lineEdit_recherche->setText(QString());
        label_rechercher->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:700; color:#00007f;\">recherche d'un employ\303\251 par ID</span></p></body></html>", nullptr));
        Button_rechercher->setText(QCoreApplication::translate("MainWindow", "appliquer", nullptr));
        Button_tri->setText(QCoreApplication::translate("MainWindow", "trier par poste", nullptr));
        banner->setText(QString());
        Button_export->setText(QCoreApplication::translate("MainWindow", "Exporter la liste des employ\303\251", nullptr));
        Button_supprimer_2->setText(QCoreApplication::translate("MainWindow", "supprimer", nullptr));
#if QT_CONFIG(whatsthis)
        groupBox->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        groupBox->setTitle(QString());
        lineEdit_ajoute->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:700; color:#ffaa00;\">formulaire employ\303\251</span></p></body></html>", nullptr));
        label_nom->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:700; color:#aa55ff;\">Nom</span></p></body></html>", nullptr));
        label_prenom->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:700; color:#aa55ff;\">Pr\303\251nom</span></p></body></html>", nullptr));
        label_email->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:700; color:#aa55ff;\">Email</span></p></body></html>", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Assistante RH", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Chef de projet", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Community Manager", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "Commercial", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("MainWindow", "Comptable", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("MainWindow", "Copywriter", nullptr));
        comboBox->setItemText(6, QCoreApplication::translate("MainWindow", "Graphiste", nullptr));
        comboBox->setItemText(7, QCoreApplication::translate("MainWindow", "Cr\303\251ateur", nullptr));
        comboBox->setItemText(8, QCoreApplication::translate("MainWindow", "Illustrateur", nullptr));
        comboBox->setItemText(9, QCoreApplication::translate("MainWindow", "Ing\303\251nieur son", nullptr));
        comboBox->setItemText(10, QCoreApplication::translate("MainWindow", "Monteur vid\303\251o", nullptr));
        comboBox->setItemText(11, QCoreApplication::translate("MainWindow", "Responsable financier", nullptr));
        comboBox->setItemText(12, QCoreApplication::translate("MainWindow", "Responsable Marketing Digital", nullptr));
        comboBox->setItemText(13, QCoreApplication::translate("MainWindow", "Responsable Produit", nullptr));
        comboBox->setItemText(14, QCoreApplication::translate("MainWindow", "Responsable RH", nullptr));
        comboBox->setItemText(15, QCoreApplication::translate("MainWindow", "Social Media Manager", nullptr));
        comboBox->setItemText(16, QCoreApplication::translate("MainWindow", "Technicien lumi\303\250re & plateau", nullptr));
        comboBox->setItemText(17, QCoreApplication::translate("MainWindow", "Vid\303\251aste", nullptr));
        comboBox->setItemText(18, QCoreApplication::translate("MainWindow", "Web Designer", nullptr));

        label_poste->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:700; color:#aa55ff;\">Poste</span></p></body></html>", nullptr));
        Button_ajouter->setText(QCoreApplication::translate("MainWindow", "ajouter", nullptr));
        comboBox_q->setItemText(0, QCoreApplication::translate("MainWindow", "Quel est le nom de votre premier animal de compagnie ?", nullptr));
        comboBox_q->setItemText(1, QCoreApplication::translate("MainWindow", "Quel est le nom de votre \303\251cole primaire ?", nullptr));
        comboBox_q->setItemText(2, QCoreApplication::translate("MainWindow", "Quel est le plat pr\303\251f\303\251r\303\251 de votre grand-parent ?", nullptr));
        comboBox_q->setItemText(3, QCoreApplication::translate("MainWindow", "Quelle est la marque de votre premier t\303\251l\303\251phone portable ?", nullptr));
        comboBox_q->setItemText(4, QCoreApplication::translate("MainWindow", "Quel est le nom de votre premi\303\250re voiture ?", nullptr));
        comboBox_q->setItemText(5, QCoreApplication::translate("MainWindow", "Quel est le surnom que seule votre famille vous donne ?", nullptr));

        label_question->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:700; color:#aa55ff;\">Qestion secrete</span></p></body></html>", nullptr));
        label_mdp_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:700; color:#aa55ff;\">reponse secrete</span></p></body></html>", nullptr));
        label_mdp->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:700; color:#aa55ff;\">Mot de passe</span></p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(acceuil), QCoreApplication::translate("MainWindow", "       accueil         ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(statistiques), QCoreApplication::translate("MainWindow", "    statistiques    ", nullptr));
        Imagecheck->setText(QCoreApplication::translate("MainWindow", "Image", nullptr));
        Videocheck->setText(QCoreApplication::translate("MainWindow", "Vid\303\251o", nullptr));
        audiocheck->setText(QCoreApplication::translate("MainWindow", "audio", nullptr));
        RechercheRess->setText(QCoreApplication::translate("MainWindow", "Rechercher", nullptr));
        AjoutBut->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        PDFBut->setText(QCoreApplication::translate("MainWindow", "PDF", nullptr));
        StatsBut->setText(QCoreApplication::translate("MainWindow", "Stats", nullptr));
        lineNom->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        AjoutBut2->setText(QCoreApplication::translate("MainWindow", "ajouter", nullptr));
        ImpBut->setText(QCoreApplication::translate("MainWindow", "importer le fichier", nullptr));
        RetourneBut->setText(QCoreApplication::translate("MainWindow", "retourner", nullptr));
        outputajout->setText(QCoreApplication::translate("MainWindow", "fichier import\303\251", nullptr));
        label_nomm->setText(QCoreApplication::translate("MainWindow", "nom :", nullptr));
        label_8->setText(QString());
        label_9->setText(QCoreApplication::translate("MainWindow", "nom du projet associ\303\251:", nullptr));
        labelStat->setText(QString());
        label_stats->setText(QCoreApplication::translate("MainWindow", "statistique", nullptr));
        labelAjout->setText(QString());
        statReturnBut->setText(QCoreApplication::translate("MainWindow", "retourner", nullptr));
        labelAffichage->setText(QString());
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "exporter PDF", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "plateforme cibl\303\251e", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "budget", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "date d\303\251but", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "ID compagne", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "date fin", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "objectif", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "nom de compagne", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "ajouter", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "modifier", nullptr));
        lineEdit_ajoute_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:700; color:#ffaa00;\">formulaire Compagne</span></p></body></html>", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "supprimer", nullptr));
        groupBox_3->setTitle(QString());
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("MainWindow", "ID ", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("MainWindow", "nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("MainWindow", "objectif", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("MainWindow", "budget", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("MainWindow", "date d\303\251but", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("MainWindow", "date fin", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("MainWindow", "plateforme", nullptr));
        label_31->setText(QCoreApplication::translate("MainWindow", "statut:", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "recherche", nullptr));
        label_25->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        groupBox_11->setTitle(QCoreApplication::translate("MainWindow", "\342\236\225 Ajouter sponsor", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Nom de sponsor:", nullptr));
        lineEdit_nom_9->setText(QString());
        lineEdit_nom_9->setPlaceholderText(QString());
        label_16->setText(QCoreApplication::translate("MainWindow", "Type de sponsor ", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "Montant ", nullptr));
        lineEdit_montant_2->setText(QString());
        label_18->setText(QCoreApplication::translate("MainWindow", "fin de contrat ", nullptr));
        ajouterButton_2->setText(QCoreApplication::translate("MainWindow", "\342\236\225 Ajouter Condidat", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "Mail", nullptr));
        lineEdit_mail_2->setText(QString());
        lineEdit_mail_2->setPlaceholderText(QString());
        comboBox_type_2->setItemText(0, QCoreApplication::translate("MainWindow", "argent", nullptr));
        comboBox_type_2->setItemText(1, QCoreApplication::translate("MainWindow", "produit ", nullptr));
        comboBox_type_2->setItemText(2, QCoreApplication::translate("MainWindow", "partenariat m\303\251dia", nullptr));

        groupBox_12->setTitle(QCoreApplication::translate("MainWindow", "\360\237\224\215 Rechercher", nullptr));
        lineEdit_searchGlobal_2->setPlaceholderText(QCoreApplication::translate("MainWindow", "Rechercher...", nullptr));
        groupBox_13->setTitle(QCoreApplication::translate("MainWindow", "\342\234\217\357\270\217 Modifier sponsor", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "Modification", nullptr));
        lineEdit_id_modify_2->setPlaceholderText(QCoreApplication::translate("MainWindow", "Nouvelle valeur", nullptr));
        modifierButton_2->setText(QCoreApplication::translate("MainWindow", "\342\234\217\357\270\217 Modifier", nullptr));
        groupBox_14->setTitle(QCoreApplication::translate("MainWindow", "\360\237\223\213 Liste des sponsor", nullptr));
        label_sort_2->setText(QCoreApplication::translate("MainWindow", "Trier par:", nullptr));
        comboBox_4->setItemText(0, QCoreApplication::translate("MainWindow", "Date d'inscriotion", nullptr));
        comboBox_4->setItemText(1, QCoreApplication::translate("MainWindow", "Alphabet", nullptr));

        pushButton_19->setText(QCoreApplication::translate("MainWindow", "\360\237\224\204 Trier", nullptr));
        pushButton_20->setText(QCoreApplication::translate("MainWindow", "\360\237\223\204 Exporter PDF", nullptr));
        pushButton_21->setText(QCoreApplication::translate("MainWindow", "\342\235\214 Quitter", nullptr));
        groupBox_15->setTitle(QCoreApplication::translate("MainWindow", "Supprimer sponsor", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        lineEdit_id_delete_2->setPlaceholderText(QCoreApplication::translate("MainWindow", "Nouvelle valeur", nullptr));
        supprimerButton_2->setText(QCoreApplication::translate("MainWindow", "\342\235\214Supprimer", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_3), QCoreApplication::translate("MainWindow", "\360\237\217\240 Accueil", nullptr));
        label_stats_title_2->setText(QCoreApplication::translate("MainWindow", "\360\237\223\212 Statistiques ", nullptr));
        label_stats_info_2->setText(QString());
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_4), QCoreApplication::translate("MainWindow", "\360\237\223\212 Statistiques", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
