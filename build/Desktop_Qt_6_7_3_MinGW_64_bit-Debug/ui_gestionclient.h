/********************************************************************************
** Form generated from reading UI file 'gestionclient.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GESTIONCLIENT_H
#define UI_GESTIONCLIENT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GestionClient
{
public:
    QAction *actionExport_CSV;
    QAction *actionStatistique;
    QAction *actionClients_Inactifs;
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
    QLabel *label_36;
    QWidget *page_nouveau_mdp;
    QLabel *label_37;
    QLineEdit *lineEdit_nouveau_mdp;
    QPushButton *pushButton_valide_mdp;
    QLabel *background;
    QWidget *page_2;
    QStackedWidget *stackedWidget;
    QWidget *page_projet;
    QWidget *page_client;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *leSearch_6;
    QComboBox *cbPaysF_6;
    QPushButton *btnClearFilter_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_6;
    QComboBox *cbSecteurF_6;
    QTableWidget *tableClients_6;
    QGroupBox *groupBox_2;
    QWidget *layoutWidget;
    QFormLayout *formLayout_4;
    QLabel *label_54;
    QLabel *label_55;
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
    QLineEdit *leNom_6;
    QLineEdit *leId_6;
    QLabel *label_61;
    QPushButton *btnSupprimer_3;
    QPushButton *btnModifier_3;
    QPushButton *btnAjouter_3;
    QPushButton *pushButton_client;
    QWidget *page_employe;
    QTabWidget *tabWidget;
    QWidget *acceuil;
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
    QWidget *statistiques;
    QLabel *statistique;
    QWidget *page_media;
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
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *GestionClient)
    {
        if (GestionClient->objectName().isEmpty())
            GestionClient->setObjectName("GestionClient");
        GestionClient->resize(975, 689);
        actionExport_CSV = new QAction(GestionClient);
        actionExport_CSV->setObjectName("actionExport_CSV");
        actionExport_CSV->setMenuRole(QAction::MenuRole::NoRole);
        actionStatistique = new QAction(GestionClient);
        actionStatistique->setObjectName("actionStatistique");
        actionStatistique->setMenuRole(QAction::MenuRole::NoRole);
        actionClients_Inactifs = new QAction(GestionClient);
        actionClients_Inactifs->setObjectName("actionClients_Inactifs");
        actionClients_Inactifs->setMenuRole(QAction::MenuRole::NoRole);
        centralwidget = new QWidget(GestionClient);
        centralwidget->setObjectName("centralwidget");
        stackedWidget_principale = new QStackedWidget(centralwidget);
        stackedWidget_principale->setObjectName("stackedWidget_principale");
        stackedWidget_principale->setGeometry(QRect(-20, -40, 1431, 701));
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
        lineEdit_email_login = new QLineEdit(page_login);
        lineEdit_email_login->setObjectName("lineEdit_email_login");
        lineEdit_email_login->setEnabled(true);
        lineEdit_email_login->setGeometry(QRect(120, 170, 291, 31));
        lineEdit_email_login->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background: transparent;\n"
"    border: 1px solid #0055ff;   /* ou autre couleur pour qu'on voie bien les bords */\n"
"    color: white;                /* texte */\n"
"}\n"
""));
        lineEdit_mdp_login = new QLineEdit(page_login);
        lineEdit_mdp_login->setObjectName("lineEdit_mdp_login");
        lineEdit_mdp_login->setGeometry(QRect(120, 250, 291, 31));
        lineEdit_mdp_login->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background: transparent;\n"
"    border: 1px solid #0055ff;   /* ou autre couleur pour qu'on voie bien les bords */\n"
"    color: white;                /* texte */\n"
"}\n"
""));
        label_connexion = new QLabel(page_login);
        label_connexion->setObjectName("label_connexion");
        label_connexion->setGeometry(QRect(160, 60, 221, 51));
        label_email_login = new QLabel(page_login);
        label_email_login->setObjectName("label_email_login");
        label_email_login->setGeometry(QRect(90, 140, 63, 20));
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
"    border: 1px solid #ffffff;   /* ou autre couleur pour qu'on voie bien les bords */\n"
"    color: white;                /* texte */\n"
"}\n"
""));
        lineEdit_reponse_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_36 = new QLabel(page_mdp_oublie);
        label_36->setObjectName("label_36");
        label_36->setGeometry(QRect(110, 110, 321, 71));
        label_36->setAlignment(Qt::AlignmentFlag::AlignCenter);
        stackedWidget_login->addWidget(page_mdp_oublie);
        page_nouveau_mdp = new QWidget();
        page_nouveau_mdp->setObjectName("page_nouveau_mdp");
        label_37 = new QLabel(page_nouveau_mdp);
        label_37->setObjectName("label_37");
        label_37->setGeometry(QRect(170, 130, 181, 31));
        label_37->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lineEdit_nouveau_mdp = new QLineEdit(page_nouveau_mdp);
        lineEdit_nouveau_mdp->setObjectName("lineEdit_nouveau_mdp");
        lineEdit_nouveau_mdp->setGeometry(QRect(100, 180, 331, 31));
        lineEdit_nouveau_mdp->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background: transparent;\n"
"    border: 1px solid #ffffff;   /* ou autre couleur pour qu'on voie bien les bords */\n"
"    color: white;                /* texte */\n"
"}"));
        lineEdit_nouveau_mdp->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        pushButton_valide_mdp = new QPushButton(page_nouveau_mdp);
        pushButton_valide_mdp->setObjectName("pushButton_valide_mdp");
        pushButton_valide_mdp->setGeometry(QRect(210, 230, 90, 29));
        stackedWidget_login->addWidget(page_nouveau_mdp);
        background = new QLabel(page);
        background->setObjectName("background");
        background->setGeometry(QRect(0, 0, 1431, 691));
        stackedWidget_principale->addWidget(page);
        background->raise();
        stackedWidget_login->raise();
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        stackedWidget = new QStackedWidget(page_2);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(70, 40, 1231, 661));
        page_projet = new QWidget();
        page_projet->setObjectName("page_projet");
        stackedWidget->addWidget(page_projet);
        page_client = new QWidget();
        page_client->setObjectName("page_client");
        layoutWidget_2 = new QWidget(page_client);
        layoutWidget_2->setObjectName("layoutWidget_2");
        layoutWidget_2->setGeometry(QRect(440, 10, 771, 731));
        verticalLayout_5 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        leSearch_6 = new QLineEdit(layoutWidget_2);
        leSearch_6->setObjectName("leSearch_6");
        leSearch_6->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
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

        horizontalLayout_4->addWidget(leSearch_6);

        cbPaysF_6 = new QComboBox(layoutWidget_2);
        cbPaysF_6->addItem(QString());
        cbPaysF_6->addItem(QString());
        cbPaysF_6->addItem(QString());
        cbPaysF_6->addItem(QString());
        cbPaysF_6->addItem(QString());
        cbPaysF_6->addItem(QString());
        cbPaysF_6->setObjectName("cbPaysF_6");
        cbPaysF_6->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
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
        cbPaysF_6->setIconSize(QSize(16, 21));

        horizontalLayout_4->addWidget(cbPaysF_6);

        btnClearFilter_6 = new QPushButton(layoutWidget_2);
        btnClearFilter_6->setObjectName("btnClearFilter_6");
        btnClearFilter_6->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
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

        horizontalLayout_4->addWidget(btnClearFilter_6);

        pushButton_7 = new QPushButton(layoutWidget_2);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
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

        horizontalLayout_4->addWidget(pushButton_7);

        pushButton_8 = new QPushButton(layoutWidget_2);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
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

        horizontalLayout_4->addWidget(pushButton_8);

        pushButton_6 = new QPushButton(layoutWidget_2);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
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

        horizontalLayout_4->addWidget(pushButton_6);


        verticalLayout_5->addLayout(horizontalLayout_4);

        cbSecteurF_6 = new QComboBox(layoutWidget_2);
        cbSecteurF_6->addItem(QString());
        cbSecteurF_6->addItem(QString());
        cbSecteurF_6->addItem(QString());
        cbSecteurF_6->addItem(QString());
        cbSecteurF_6->addItem(QString());
        cbSecteurF_6->addItem(QString());
        cbSecteurF_6->setObjectName("cbSecteurF_6");
        cbSecteurF_6->setMinimumSize(QSize(174, 22));
        cbSecteurF_6->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
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
        cbSecteurF_6->setIconSize(QSize(8, 21));

        verticalLayout_5->addWidget(cbSecteurF_6);

        tableClients_6 = new QTableWidget(layoutWidget_2);
        if (tableClients_6->columnCount() < 7)
            tableClients_6->setColumnCount(7);
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
        tableClients_6->setObjectName("tableClients_6");
        tableClients_6->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
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
        tableClients_6->setColumnCount(7);

        verticalLayout_5->addWidget(tableClients_6);

        groupBox_2 = new QGroupBox(page_client);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(0, 20, 431, 611));
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
        layoutWidget = new QWidget(groupBox_2);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(30, 80, 374, 455));
        formLayout_4 = new QFormLayout(layoutWidget);
        formLayout_4->setObjectName("formLayout_4");
        formLayout_4->setContentsMargins(0, 0, 0, 0);
        label_54 = new QLabel(layoutWidget);
        label_54->setObjectName("label_54");
        QFont font;
        font.setPointSize(10);
        label_54->setFont(font);
        label_54->setFocusPolicy(Qt::FocusPolicy::TabFocus);
        label_54->setFrameShape(QFrame::Shape::NoFrame);

        formLayout_4->setWidget(0, QFormLayout::LabelRole, label_54);

        label_55 = new QLabel(layoutWidget);
        label_55->setObjectName("label_55");
        label_55->setFont(font);

        formLayout_4->setWidget(3, QFormLayout::SpanningRole, label_55);

        label_56 = new QLabel(layoutWidget);
        label_56->setObjectName("label_56");
        label_56->setFont(font);

        formLayout_4->setWidget(5, QFormLayout::LabelRole, label_56);

        leEmail_6 = new QLineEdit(layoutWidget);
        leEmail_6->setObjectName("leEmail_6");

        formLayout_4->setWidget(6, QFormLayout::FieldRole, leEmail_6);

        label_57 = new QLabel(layoutWidget);
        label_57->setObjectName("label_57");
        label_57->setFont(font);

        formLayout_4->setWidget(7, QFormLayout::LabelRole, label_57);

        leTel_6 = new QLineEdit(layoutWidget);
        leTel_6->setObjectName("leTel_6");

        formLayout_4->setWidget(8, QFormLayout::FieldRole, leTel_6);

        label_58 = new QLabel(layoutWidget);
        label_58->setObjectName("label_58");
        label_58->setFont(font);

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
        label_59->setFont(font);

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
        label_60->setFont(font);

        formLayout_4->setWidget(13, QFormLayout::SpanningRole, label_60);

        deDate_6 = new QDateEdit(layoutWidget);
        deDate_6->setObjectName("deDate_6");
        deDate_6->setCalendarPopup(true);

        formLayout_4->setWidget(14, QFormLayout::FieldRole, deDate_6);

        leNom_6 = new QLineEdit(layoutWidget);
        leNom_6->setObjectName("leNom_6");

        formLayout_4->setWidget(4, QFormLayout::FieldRole, leNom_6);

        leId_6 = new QLineEdit(layoutWidget);
        leId_6->setObjectName("leId_6");

        formLayout_4->setWidget(1, QFormLayout::FieldRole, leId_6);

        label_61 = new QLabel(groupBox_2);
        label_61->setObjectName("label_61");
        label_61->setGeometry(QRect(20, 20, 251, 51));
        QFont font1;
        font1.setPointSize(18);
        font1.setUnderline(true);
        label_61->setFont(font1);
        label_61->setLayoutDirection(Qt::LayoutDirection::RightToLeft);
        label_61->setAutoFillBackground(false);
        label_61->setStyleSheet(QString::fromUtf8("selection-background-color: rgb(255, 170, 0);"));
        btnSupprimer_3 = new QPushButton(groupBox_2);
        btnSupprimer_3->setObjectName("btnSupprimer_3");
        btnSupprimer_3->setGeometry(QRect(290, 550, 111, 31));
        btnModifier_3 = new QPushButton(groupBox_2);
        btnModifier_3->setObjectName("btnModifier_3");
        btnModifier_3->setGeometry(QRect(20, 550, 111, 31));
        btnAjouter_3 = new QPushButton(groupBox_2);
        btnAjouter_3->setObjectName("btnAjouter_3");
        btnAjouter_3->setGeometry(QRect(150, 550, 111, 31));
        pushButton_client = new QPushButton(groupBox_2);
        pushButton_client->setObjectName("pushButton_client");
        pushButton_client->setGeometry(QRect(330, 0, 91, 51));
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
        groupBox = new QGroupBox(acceuil);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 10, 441, 581));
        groupBox->setStyleSheet(QString::fromUtf8("background-color: #1E1E2F; color: white; QHeaderView::section { background-color: #5500FF; color: white; }."));
        lineEdit_ajoute = new QLabel(groupBox);
        lineEdit_ajoute->setObjectName("lineEdit_ajoute");
        lineEdit_ajoute->setGeometry(QRect(130, 10, 211, 31));
        lineEdit_nom = new QLineEdit(groupBox);
        lineEdit_nom->setObjectName("lineEdit_nom");
        lineEdit_nom->setGeometry(QRect(10, 60, 411, 31));
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
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(10, 470, 411, 28));
        label_poste = new QLabel(groupBox);
        label_poste->setObjectName("label_poste");
        label_poste->setGeometry(QRect(10, 440, 63, 20));
        Button_ajouter = new QPushButton(groupBox);
        Button_ajouter->setObjectName("Button_ajouter");
        Button_ajouter->setGeometry(QRect(140, 540, 161, 29));
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
        label_mdp_2->setGeometry(QRect(10, 380, 211, 20));
        lineEdit_mdp = new QLineEdit(groupBox);
        lineEdit_mdp->setObjectName("lineEdit_mdp");
        lineEdit_mdp->setGeometry(QRect(10, 260, 411, 31));
        label_mdp = new QLabel(groupBox);
        label_mdp->setObjectName("label_mdp");
        label_mdp->setGeometry(QRect(10, 230, 211, 21));
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
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidgetEmployes->setHorizontalHeaderItem(0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidgetEmployes->setHorizontalHeaderItem(1, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidgetEmployes->setHorizontalHeaderItem(2, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidgetEmployes->setHorizontalHeaderItem(3, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidgetEmployes->setHorizontalHeaderItem(4, __qtablewidgetitem11);
        tableWidgetEmployes->setObjectName("tableWidgetEmployes");
        tableWidgetEmployes->setGeometry(QRect(0, 0, 741, 251));
        tableWidgetEmployes->horizontalHeader()->setDefaultSectionSize(150);
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
        tabWidget->addTab(acceuil, QString());
        statistiques = new QWidget();
        statistiques->setObjectName("statistiques");
        statistique = new QLabel(statistiques);
        statistique->setObjectName("statistique");
        statistique->setGeometry(QRect(230, 30, 861, 521));
        tabWidget->addTab(statistiques, QString());
        stackedWidget->addWidget(page_employe);
        page_media = new QWidget();
        page_media->setObjectName("page_media");
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
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem18);
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
        stackedWidget->addWidget(page_categorie);
        stackedWidget_principale->addWidget(page_2);
        GestionClient->setCentralWidget(centralwidget);
        menubar = new QMenuBar(GestionClient);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 975, 17));
        GestionClient->setMenuBar(menubar);
        statusbar = new QStatusBar(GestionClient);
        statusbar->setObjectName("statusbar");
        GestionClient->setStatusBar(statusbar);

        retranslateUi(GestionClient);

        stackedWidget_principale->setCurrentIndex(1);
        stackedWidget_login->setCurrentIndex(0);
        stackedWidget->setCurrentIndex(1);
        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(GestionClient);
    } // setupUi

    void retranslateUi(QMainWindow *GestionClient)
    {
        GestionClient->setWindowTitle(QCoreApplication::translate("GestionClient", "GestionClient", nullptr));
        actionExport_CSV->setText(QCoreApplication::translate("GestionClient", "Export CSV", nullptr));
        actionStatistique->setText(QCoreApplication::translate("GestionClient", "Statistique", nullptr));
        actionClients_Inactifs->setText(QCoreApplication::translate("GestionClient", "Clients Inactifs", nullptr));
        label_mdp_login->setText(QCoreApplication::translate("GestionClient", "<html><head/><body><p><span style=\" font-weight:700; color:#55007f;\">mots de passe:</span></p></body></html>", nullptr));
        label_connexion->setText(QCoreApplication::translate("GestionClient", "<html><head/><body><p><span style=\" font-size:26pt; font-weight:700; color:#ffaa00;\">Connexion</span></p></body></html>", nullptr));
        label_email_login->setText(QCoreApplication::translate("GestionClient", "<html><head/><body><p><span style=\" font-weight:700; color:#55007f;\">Email:</span></p></body></html>", nullptr));
        pushButton_mdp_oublie->setText(QCoreApplication::translate("GestionClient", "mot de passe oubli\303\251 ?", nullptr));
        label_36->setText(QCoreApplication::translate("GestionClient", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:700; color:#ffffff;\">quel est le nom de votre premier </span></p><p align=\"center\"><span style=\" font-size:12pt; font-weight:700; color:#ffffff;\">animal de compagnie ?</span></p></body></html>", nullptr));
        label_37->setText(QCoreApplication::translate("GestionClient", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:700; color:#ffffff;\">nouveau mot de passe</span></p></body></html>", nullptr));
        pushButton_valide_mdp->setText(QCoreApplication::translate("GestionClient", "valid\303\251", nullptr));
        background->setText(QString());
        leSearch_6->setPlaceholderText(QCoreApplication::translate("GestionClient", "Recherche...", nullptr));
        cbPaysF_6->setItemText(0, QCoreApplication::translate("GestionClient", "Pays", nullptr));
        cbPaysF_6->setItemText(1, QCoreApplication::translate("GestionClient", "Tunisie", nullptr));
        cbPaysF_6->setItemText(2, QCoreApplication::translate("GestionClient", "Alg\303\251rie", nullptr));
        cbPaysF_6->setItemText(3, QCoreApplication::translate("GestionClient", "France", nullptr));
        cbPaysF_6->setItemText(4, QCoreApplication::translate("GestionClient", "Italie", nullptr));
        cbPaysF_6->setItemText(5, QCoreApplication::translate("GestionClient", "Allemagne", nullptr));

        cbPaysF_6->setPlaceholderText(QCoreApplication::translate("GestionClient", "Pays", nullptr));
        btnClearFilter_6->setText(QCoreApplication::translate("GestionClient", "Effacer les filtres", nullptr));
        pushButton_7->setText(QCoreApplication::translate("GestionClient", "Export CSV", nullptr));
        pushButton_8->setText(QCoreApplication::translate("GestionClient", "Statistiques", nullptr));
        pushButton_6->setText(QCoreApplication::translate("GestionClient", "Clients Inactifs", nullptr));
        cbSecteurF_6->setItemText(0, QCoreApplication::translate("GestionClient", "Secteur", nullptr));
        cbSecteurF_6->setItemText(1, QCoreApplication::translate("GestionClient", "Design et Multim\303\251dia", nullptr));
        cbSecteurF_6->setItemText(2, QCoreApplication::translate("GestionClient", "D\303\251veloppement Web", nullptr));
        cbSecteurF_6->setItemText(3, QCoreApplication::translate("GestionClient", "Marketing et Communication digitale", nullptr));
        cbSecteurF_6->setItemText(4, QCoreApplication::translate("GestionClient", "Production Vid\303\251o", nullptr));
        cbSecteurF_6->setItemText(5, QCoreApplication::translate("GestionClient", "\303\211dition et Contenu \303\251crit", nullptr));

        cbSecteurF_6->setPlaceholderText(QCoreApplication::translate("GestionClient", "Secteur", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableClients_6->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("GestionClient", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableClients_6->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("GestionClient", "Nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableClients_6->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("GestionClient", "Email", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableClients_6->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("GestionClient", "T\303\251l\303\251phone", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableClients_6->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("GestionClient", "SecteurActivit\303\251", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableClients_6->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("GestionClient", "Pays", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableClients_6->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("GestionClient", "DateCr\303\251ation", nullptr));
        groupBox_2->setTitle(QString());
        label_54->setText(QCoreApplication::translate("GestionClient", "ID :", nullptr));
        label_55->setText(QCoreApplication::translate("GestionClient", "Nom et Pr\303\251nom :", nullptr));
        label_56->setText(QCoreApplication::translate("GestionClient", "Email :", nullptr));
        leEmail_6->setPlaceholderText(QCoreApplication::translate("GestionClient", "Email", nullptr));
        label_57->setText(QCoreApplication::translate("GestionClient", "T\303\251l\303\251phone :", nullptr));
        leTel_6->setPlaceholderText(QCoreApplication::translate("GestionClient", "T\303\251l\303\251phone", nullptr));
        label_58->setText(QCoreApplication::translate("GestionClient", "Secteur d'Activit\303\251 :", nullptr));
        cbSecteur_6->setItemText(0, QCoreApplication::translate("GestionClient", "Secteur...", nullptr));
        cbSecteur_6->setItemText(1, QCoreApplication::translate("GestionClient", "Design et Multim\303\251dia", nullptr));
        cbSecteur_6->setItemText(2, QCoreApplication::translate("GestionClient", "D\303\251veloppement Web", nullptr));
        cbSecteur_6->setItemText(3, QCoreApplication::translate("GestionClient", "Marketing et Communication digital", nullptr));
        cbSecteur_6->setItemText(4, QCoreApplication::translate("GestionClient", "Production Vid\303\251o", nullptr));
        cbSecteur_6->setItemText(5, QCoreApplication::translate("GestionClient", "\303\211dition & Contenu \303\251crit", nullptr));

        cbSecteur_6->setPlaceholderText(QCoreApplication::translate("GestionClient", "Secteur", nullptr));
        label_59->setText(QCoreApplication::translate("GestionClient", "Pays :", nullptr));
        cbPays_6->setItemText(0, QCoreApplication::translate("GestionClient", "Pays...", nullptr));
        cbPays_6->setItemText(1, QCoreApplication::translate("GestionClient", "Tunisie", nullptr));
        cbPays_6->setItemText(2, QCoreApplication::translate("GestionClient", "Alg\303\251rie", nullptr));
        cbPays_6->setItemText(3, QCoreApplication::translate("GestionClient", "France", nullptr));
        cbPays_6->setItemText(4, QCoreApplication::translate("GestionClient", "Italie", nullptr));
        cbPays_6->setItemText(5, QCoreApplication::translate("GestionClient", "Allemagne ", nullptr));

        cbPays_6->setPlaceholderText(QCoreApplication::translate("GestionClient", "Pays", nullptr));
        label_60->setText(QCoreApplication::translate("GestionClient", "Date d'Inscription :", nullptr));
        deDate_6->setDisplayFormat(QCoreApplication::translate("GestionClient", "yyyy-MM-dd", nullptr));
        leNom_6->setText(QString());
        leNom_6->setPlaceholderText(QCoreApplication::translate("GestionClient", "Nom et Pr\303\251nom", nullptr));
        leId_6->setPlaceholderText(QCoreApplication::translate("GestionClient", "ID", nullptr));
        label_61->setText(QCoreApplication::translate("GestionClient", "<html><head/><body><p><span style=\" font-weight:700; text-decoration:none; color:#aa00ff;\">Formulaire client</span></p></body></html>", nullptr));
        btnSupprimer_3->setText(QCoreApplication::translate("GestionClient", "Supprimer", nullptr));
        btnModifier_3->setText(QCoreApplication::translate("GestionClient", "Modifier", nullptr));
        btnAjouter_3->setText(QCoreApplication::translate("GestionClient", "Ajouter", nullptr));
        pushButton_client->setText(QCoreApplication::translate("GestionClient", "Client", nullptr));
#if QT_CONFIG(whatsthis)
        groupBox->setWhatsThis(QCoreApplication::translate("GestionClient", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        groupBox->setTitle(QString());
        lineEdit_ajoute->setText(QCoreApplication::translate("GestionClient", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:700; color:#ffaa00;\">formulaire employ\303\251</span></p></body></html>", nullptr));
        label_nom->setText(QCoreApplication::translate("GestionClient", "<html><head/><body><p><span style=\" font-weight:700; color:#55007f;\">Nom</span></p></body></html>", nullptr));
        label_prenom->setText(QCoreApplication::translate("GestionClient", "<html><head/><body><p><span style=\" font-weight:700; color:#55007f;\">Pr\303\251nom</span></p></body></html>", nullptr));
        label_email->setText(QCoreApplication::translate("GestionClient", "<html><head/><body><p><span style=\" font-weight:700; color:#55007f;\">Email</span></p></body></html>", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("GestionClient", "Chef de projet", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("GestionClient", "Community Manager", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("GestionClient", "Commercial", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("GestionClient", "Consultant Cybers\303\251curit\303\251", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("GestionClient", "Graphiste", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("GestionClient", "Cr\303\251ateur", nullptr));
        comboBox->setItemText(6, QCoreApplication::translate("GestionClient", "Developpeur", nullptr));
        comboBox->setItemText(7, QCoreApplication::translate("GestionClient", "Responsable Marketing Digital", nullptr));
        comboBox->setItemText(8, QCoreApplication::translate("GestionClient", "Responsable Produit", nullptr));
        comboBox->setItemText(9, QCoreApplication::translate("GestionClient", "Responsable RH", nullptr));
        comboBox->setItemText(10, QCoreApplication::translate("GestionClient", "Vid\303\251aste", nullptr));

        label_poste->setText(QCoreApplication::translate("GestionClient", "<html><head/><body><p><span style=\" font-weight:700; color:#55007f;\">Poste</span></p></body></html>", nullptr));
        Button_ajouter->setText(QCoreApplication::translate("GestionClient", "ajouter", nullptr));
        comboBox_q->setItemText(0, QCoreApplication::translate("GestionClient", "Quel est le nom de votre premier animal de compagnie ?", nullptr));
        comboBox_q->setItemText(1, QCoreApplication::translate("GestionClient", "Quel est le nom de votre \303\251cole primaire ?", nullptr));
        comboBox_q->setItemText(2, QCoreApplication::translate("GestionClient", "Quel est le plat pr\303\251f\303\251r\303\251 de votre grand-parent ?", nullptr));
        comboBox_q->setItemText(3, QCoreApplication::translate("GestionClient", "Quelle est la marque de votre premier t\303\251l\303\251phone portable ?", nullptr));
        comboBox_q->setItemText(4, QCoreApplication::translate("GestionClient", "Quel est le nom de votre premi\303\250re voiture ?", nullptr));
        comboBox_q->setItemText(5, QCoreApplication::translate("GestionClient", "Quel est le surnom que seule votre famille vous donne ?", nullptr));

        label_question->setText(QCoreApplication::translate("GestionClient", "<html><head/><body><p><span style=\" font-weight:700; color:#55007f;\">Qestion secrete</span></p></body></html>", nullptr));
        label_mdp_2->setText(QCoreApplication::translate("GestionClient", "<html><head/><body><p><span style=\" font-weight:700; color:#55007f;\">reponse secrete</span></p></body></html>", nullptr));
        label_mdp->setText(QCoreApplication::translate("GestionClient", "<html><head/><body><p><span style=\" font-weight:700; color:#55007f;\">Mot de passe</span></p></body></html>", nullptr));
        groupBox_recherche->setTitle(QString());
        QTableWidgetItem *___qtablewidgetitem7 = tableWidgetEmployes->horizontalHeaderItem(0);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("GestionClient", " ID   ", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidgetEmployes->horizontalHeaderItem(1);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("GestionClient", "Poste    ", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidgetEmployes->horizontalHeaderItem(2);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("GestionClient", "Nom    ", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidgetEmployes->horizontalHeaderItem(3);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("GestionClient", " Pr\303\251nom   ", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidgetEmployes->horizontalHeaderItem(4);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("GestionClient", "Email    ", nullptr));
        lineEdit_recherche->setText(QString());
        label_rechercher->setText(QCoreApplication::translate("GestionClient", "<html><head/><body><p><span style=\" font-weight:700; color:#00007f;\">recherche d'un employ\303\251 par ID</span></p></body></html>", nullptr));
        Button_rechercher->setText(QCoreApplication::translate("GestionClient", "appliquer", nullptr));
        Button_tri->setText(QCoreApplication::translate("GestionClient", "trier par poste", nullptr));
        banner->setText(QString());
        Button_export->setText(QCoreApplication::translate("GestionClient", "Exporter la liste des employ\303\251", nullptr));
        Button_supprimer_2->setText(QCoreApplication::translate("GestionClient", "supprimer", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(acceuil), QCoreApplication::translate("GestionClient", "       accueil         ", nullptr));
        statistique->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(statistiques), QCoreApplication::translate("GestionClient", "    statistiques    ", nullptr));
        pushButton_5->setText(QCoreApplication::translate("GestionClient", "exporter PDF", nullptr));
        label_7->setText(QCoreApplication::translate("GestionClient", "plateforme cibl\303\251e", nullptr));
        label_4->setText(QCoreApplication::translate("GestionClient", "budget", nullptr));
        label_5->setText(QCoreApplication::translate("GestionClient", "date d\303\251but", nullptr));
        label->setText(QCoreApplication::translate("GestionClient", "ID compagne", nullptr));
        label_6->setText(QCoreApplication::translate("GestionClient", "date fin", nullptr));
        label_3->setText(QCoreApplication::translate("GestionClient", "objectif", nullptr));
        label_2->setText(QCoreApplication::translate("GestionClient", "nom de compagne", nullptr));
        pushButton->setText(QCoreApplication::translate("GestionClient", "ajouter", nullptr));
        pushButton_2->setText(QCoreApplication::translate("GestionClient", "modifier", nullptr));
        lineEdit_ajoute_2->setText(QCoreApplication::translate("GestionClient", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:700; color:#ffaa00;\">formulaire Compagne</span></p></body></html>", nullptr));
        pushButton_3->setText(QCoreApplication::translate("GestionClient", "supprimer", nullptr));
        groupBox_3->setTitle(QString());
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("GestionClient", "ID ", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("GestionClient", "nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("GestionClient", "objectif", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("GestionClient", "budget", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("GestionClient", "date d\303\251but", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("GestionClient", "date fin", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("GestionClient", "plateforme", nullptr));
        label_31->setText(QCoreApplication::translate("GestionClient", "statut:", nullptr));
        pushButton_4->setText(QCoreApplication::translate("GestionClient", "recherche", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GestionClient: public Ui_GestionClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GESTIONCLIENT_H
