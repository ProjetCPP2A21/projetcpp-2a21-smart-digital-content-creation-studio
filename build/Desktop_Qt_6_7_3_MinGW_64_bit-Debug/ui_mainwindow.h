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
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QStackedWidget *stackedWidget_principale;
    QWidget *page_3;
    QStackedWidget *stackedWidget_login_2;
    QWidget *page_login_2;
    QLabel *label_mdp_login_2;
    QLineEdit *lineEdit_email_login_2;
    QLineEdit *lineEdit_mdp_login_2;
    QLabel *label_connexion_2;
    QLabel *label_email_login_2;
    QPushButton *pushButton_mdp_oublie_2;
    QWidget *page_mdp_oublie_2;
    QLineEdit *lineEdit_reponse_3;
    QLabel *label_38;
    QWidget *page_nouveau_mdp_2;
    QLabel *label_39;
    QLineEdit *lineEdit_nouveau_mdp_2;
    QPushButton *pushButton_valide_mdp_2;
    QLabel *background_2;
    QWidget *page_4;
    QStackedWidget *stackedWidget_2;
    QWidget *page_projet_2;
    QWidget *page_client_2;
    QWidget *layoutWidget_3;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *leSearch_7;
    QComboBox *cbPaysF_7;
    QPushButton *btnClearFilter_7;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QComboBox *cbSecteurF_7;
    QTableWidget *tableClients_7;
    QGroupBox *groupBox_4;
    QWidget *layoutWidget_4;
    QFormLayout *formLayout_5;
    QLabel *label_62;
    QLabel *label_63;
    QLabel *label_64;
    QLineEdit *leEmail_7;
    QLabel *label_65;
    QLineEdit *leTel_7;
    QLabel *label_66;
    QComboBox *cbSecteur_7;
    QLabel *label_67;
    QComboBox *cbPays_7;
    QLabel *label_68;
    QDateEdit *deDate_7;
    QLineEdit *leNom_7;
    QLineEdit *leId_7;
    QLabel *label_69;
    QPushButton *btnSupprimer_4;
    QPushButton *btnModifier_4;
    QPushButton *btnAjouter_4;
    QPushButton *pushButton_client_2;
    QWidget *page_employe_2;
    QTabWidget *tabWidget_2;
    QWidget *acceuil_2;
    QGroupBox *groupBox_5;
    QLabel *lineEdit_ajoute_3;
    QLineEdit *lineEdit_nom_2;
    QLabel *label_nom_2;
    QLabel *label_prenom_2;
    QLineEdit *lineEdit_prenom_2;
    QLabel *label_email_2;
    QLineEdit *lineEdit_email_2;
    QComboBox *comboBox_2;
    QLabel *label_poste_2;
    QPushButton *Button_ajouter_2;
    QComboBox *comboBox_q_2;
    QLabel *label_question_2;
    QLineEdit *lineEdit_reponse_4;
    QLabel *label_mdp_3;
    QLineEdit *lineEdit_mdp_2;
    QLabel *label_mdp_4;
    QGroupBox *groupBox_recherche_2;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QTableWidget *tableWidgetEmployes_2;
    QLineEdit *lineEdit_recherche_2;
    QLabel *label_rechercher_2;
    QPushButton *Button_rechercher_2;
    QPushButton *Button_tri_2;
    QLabel *banner_2;
    QPushButton *Button_export_2;
    QPushButton *Button_supprimer_3;
    QLineEdit *lineEdit_id_supp_2;
    QWidget *statistiques_2;
    QLabel *statistique_2;
    QWidget *page_media_2;
    QWidget *page_feedback_2;
    QPushButton *pushButton_12;
    QWidget *widget_2;
    QDateEdit *dateEdit_3;
    QLabel *label_8;
    QLineEdit *lineEdit_7;
    QLineEdit *lineEdit_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QDateEdit *dateEdit_4;
    QLabel *label_13;
    QLineEdit *lineEdit_9;
    QLineEdit *lineEdit_10;
    QLabel *label_14;
    QLineEdit *lineEdit_15;
    QPushButton *pushButton_13;
    QPushButton *pushButton_14;
    QLabel *lineEdit_ajoute_4;
    QPushButton *pushButton_15;
    QGroupBox *groupBox_6;
    QTableWidget *tableWidget_2;
    QLabel *label_32;
    QPushButton *pushButton_16;
    QLineEdit *lineEdit_11;
    QLineEdit *lineEdit_12;
    QWidget *page_categorie_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(952, 757);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        stackedWidget_principale = new QStackedWidget(centralWidget);
        stackedWidget_principale->setObjectName("stackedWidget_principale");
        stackedWidget_principale->setGeometry(QRect(-60, -20, 1431, 701));
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        stackedWidget_login_2 = new QStackedWidget(page_3);
        stackedWidget_login_2->setObjectName("stackedWidget_login_2");
        stackedWidget_login_2->setGeometry(QRect(810, 130, 521, 391));
        stackedWidget_login_2->setStyleSheet(QString::fromUtf8("/* Le stacked widget avec un d\303\251grad\303\251 orange -> blanc */\n"
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
        page_login_2 = new QWidget();
        page_login_2->setObjectName("page_login_2");
        label_mdp_login_2 = new QLabel(page_login_2);
        label_mdp_login_2->setObjectName("label_mdp_login_2");
        label_mdp_login_2->setGeometry(QRect(90, 220, 131, 20));
        lineEdit_email_login_2 = new QLineEdit(page_login_2);
        lineEdit_email_login_2->setObjectName("lineEdit_email_login_2");
        lineEdit_email_login_2->setEnabled(true);
        lineEdit_email_login_2->setGeometry(QRect(120, 170, 291, 31));
        lineEdit_email_login_2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background: transparent;\n"
"    border: 1px solid #0055ff;   /* ou autre couleur pour qu'on voie bien les bords */\n"
"    color: white;                /* texte */\n"
"}\n"
""));
        lineEdit_mdp_login_2 = new QLineEdit(page_login_2);
        lineEdit_mdp_login_2->setObjectName("lineEdit_mdp_login_2");
        lineEdit_mdp_login_2->setGeometry(QRect(120, 250, 291, 31));
        lineEdit_mdp_login_2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background: transparent;\n"
"    border: 1px solid #0055ff;   /* ou autre couleur pour qu'on voie bien les bords */\n"
"    color: white;                /* texte */\n"
"}\n"
""));
        label_connexion_2 = new QLabel(page_login_2);
        label_connexion_2->setObjectName("label_connexion_2");
        label_connexion_2->setGeometry(QRect(160, 60, 221, 51));
        label_email_login_2 = new QLabel(page_login_2);
        label_email_login_2->setObjectName("label_email_login_2");
        label_email_login_2->setGeometry(QRect(90, 140, 63, 20));
        pushButton_mdp_oublie_2 = new QPushButton(page_login_2);
        pushButton_mdp_oublie_2->setObjectName("pushButton_mdp_oublie_2");
        pushButton_mdp_oublie_2->setGeometry(QRect(160, 310, 191, 29));
        pushButton_mdp_oublie_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    color: blue;\n"
"    text-decoration: underline;\n"
"    background: transparent;\n"
"}\n"
""));
        stackedWidget_login_2->addWidget(page_login_2);
        page_mdp_oublie_2 = new QWidget();
        page_mdp_oublie_2->setObjectName("page_mdp_oublie_2");
        lineEdit_reponse_3 = new QLineEdit(page_mdp_oublie_2);
        lineEdit_reponse_3->setObjectName("lineEdit_reponse_3");
        lineEdit_reponse_3->setGeometry(QRect(100, 200, 311, 31));
        lineEdit_reponse_3->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background: transparent;\n"
"    border: 1px solid #ffffff;   /* ou autre couleur pour qu'on voie bien les bords */\n"
"    color: white;                /* texte */\n"
"}\n"
""));
        lineEdit_reponse_3->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_38 = new QLabel(page_mdp_oublie_2);
        label_38->setObjectName("label_38");
        label_38->setGeometry(QRect(110, 110, 321, 71));
        label_38->setAlignment(Qt::AlignmentFlag::AlignCenter);
        stackedWidget_login_2->addWidget(page_mdp_oublie_2);
        page_nouveau_mdp_2 = new QWidget();
        page_nouveau_mdp_2->setObjectName("page_nouveau_mdp_2");
        label_39 = new QLabel(page_nouveau_mdp_2);
        label_39->setObjectName("label_39");
        label_39->setGeometry(QRect(170, 130, 181, 31));
        label_39->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lineEdit_nouveau_mdp_2 = new QLineEdit(page_nouveau_mdp_2);
        lineEdit_nouveau_mdp_2->setObjectName("lineEdit_nouveau_mdp_2");
        lineEdit_nouveau_mdp_2->setGeometry(QRect(100, 180, 331, 31));
        lineEdit_nouveau_mdp_2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background: transparent;\n"
"    border: 1px solid #ffffff;   /* ou autre couleur pour qu'on voie bien les bords */\n"
"    color: white;                /* texte */\n"
"}"));
        lineEdit_nouveau_mdp_2->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        pushButton_valide_mdp_2 = new QPushButton(page_nouveau_mdp_2);
        pushButton_valide_mdp_2->setObjectName("pushButton_valide_mdp_2");
        pushButton_valide_mdp_2->setGeometry(QRect(210, 230, 90, 29));
        stackedWidget_login_2->addWidget(page_nouveau_mdp_2);
        background_2 = new QLabel(page_3);
        background_2->setObjectName("background_2");
        background_2->setGeometry(QRect(0, 0, 1431, 691));
        stackedWidget_principale->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName("page_4");
        stackedWidget_2 = new QStackedWidget(page_4);
        stackedWidget_2->setObjectName("stackedWidget_2");
        stackedWidget_2->setGeometry(QRect(70, 40, 1231, 661));
        page_projet_2 = new QWidget();
        page_projet_2->setObjectName("page_projet_2");
        stackedWidget_2->addWidget(page_projet_2);
        page_client_2 = new QWidget();
        page_client_2->setObjectName("page_client_2");
        layoutWidget_3 = new QWidget(page_client_2);
        layoutWidget_3->setObjectName("layoutWidget_3");
        layoutWidget_3->setGeometry(QRect(440, 10, 771, 731));
        verticalLayout_6 = new QVBoxLayout(layoutWidget_3);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        leSearch_7 = new QLineEdit(layoutWidget_3);
        leSearch_7->setObjectName("leSearch_7");
        leSearch_7->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
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

        horizontalLayout_5->addWidget(leSearch_7);

        cbPaysF_7 = new QComboBox(layoutWidget_3);
        cbPaysF_7->addItem(QString());
        cbPaysF_7->addItem(QString());
        cbPaysF_7->addItem(QString());
        cbPaysF_7->addItem(QString());
        cbPaysF_7->addItem(QString());
        cbPaysF_7->addItem(QString());
        cbPaysF_7->setObjectName("cbPaysF_7");
        cbPaysF_7->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
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
        cbPaysF_7->setIconSize(QSize(16, 21));

        horizontalLayout_5->addWidget(cbPaysF_7);

        btnClearFilter_7 = new QPushButton(layoutWidget_3);
        btnClearFilter_7->setObjectName("btnClearFilter_7");
        btnClearFilter_7->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
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

        horizontalLayout_5->addWidget(btnClearFilter_7);

        pushButton_9 = new QPushButton(layoutWidget_3);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
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

        horizontalLayout_5->addWidget(pushButton_9);

        pushButton_10 = new QPushButton(layoutWidget_3);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
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

        horizontalLayout_5->addWidget(pushButton_10);

        pushButton_11 = new QPushButton(layoutWidget_3);
        pushButton_11->setObjectName("pushButton_11");
        pushButton_11->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
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

        horizontalLayout_5->addWidget(pushButton_11);


        verticalLayout_6->addLayout(horizontalLayout_5);

        cbSecteurF_7 = new QComboBox(layoutWidget_3);
        cbSecteurF_7->addItem(QString());
        cbSecteurF_7->addItem(QString());
        cbSecteurF_7->addItem(QString());
        cbSecteurF_7->addItem(QString());
        cbSecteurF_7->addItem(QString());
        cbSecteurF_7->addItem(QString());
        cbSecteurF_7->setObjectName("cbSecteurF_7");
        cbSecteurF_7->setMinimumSize(QSize(174, 22));
        cbSecteurF_7->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
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
        cbSecteurF_7->setIconSize(QSize(8, 21));

        verticalLayout_6->addWidget(cbSecteurF_7);

        tableClients_7 = new QTableWidget(layoutWidget_3);
        if (tableClients_7->columnCount() < 7)
            tableClients_7->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableClients_7->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableClients_7->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableClients_7->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableClients_7->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableClients_7->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableClients_7->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableClients_7->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        tableClients_7->setObjectName("tableClients_7");
        tableClients_7->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
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
        tableClients_7->setColumnCount(7);

        verticalLayout_6->addWidget(tableClients_7);

        groupBox_4 = new QGroupBox(page_client_2);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setGeometry(QRect(0, 20, 431, 611));
        groupBox_4->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
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
        layoutWidget_4 = new QWidget(groupBox_4);
        layoutWidget_4->setObjectName("layoutWidget_4");
        layoutWidget_4->setGeometry(QRect(30, 80, 374, 455));
        formLayout_5 = new QFormLayout(layoutWidget_4);
        formLayout_5->setSpacing(6);
        formLayout_5->setContentsMargins(11, 11, 11, 11);
        formLayout_5->setObjectName("formLayout_5");
        formLayout_5->setContentsMargins(0, 0, 0, 0);
        label_62 = new QLabel(layoutWidget_4);
        label_62->setObjectName("label_62");
        QFont font;
        font.setPointSize(10);
        label_62->setFont(font);
        label_62->setFocusPolicy(Qt::FocusPolicy::TabFocus);
        label_62->setFrameShape(QFrame::Shape::NoFrame);

        formLayout_5->setWidget(0, QFormLayout::LabelRole, label_62);

        label_63 = new QLabel(layoutWidget_4);
        label_63->setObjectName("label_63");
        label_63->setFont(font);

        formLayout_5->setWidget(3, QFormLayout::SpanningRole, label_63);

        label_64 = new QLabel(layoutWidget_4);
        label_64->setObjectName("label_64");
        label_64->setFont(font);

        formLayout_5->setWidget(5, QFormLayout::LabelRole, label_64);

        leEmail_7 = new QLineEdit(layoutWidget_4);
        leEmail_7->setObjectName("leEmail_7");

        formLayout_5->setWidget(6, QFormLayout::FieldRole, leEmail_7);

        label_65 = new QLabel(layoutWidget_4);
        label_65->setObjectName("label_65");
        label_65->setFont(font);

        formLayout_5->setWidget(7, QFormLayout::LabelRole, label_65);

        leTel_7 = new QLineEdit(layoutWidget_4);
        leTel_7->setObjectName("leTel_7");

        formLayout_5->setWidget(8, QFormLayout::FieldRole, leTel_7);

        label_66 = new QLabel(layoutWidget_4);
        label_66->setObjectName("label_66");
        label_66->setFont(font);

        formLayout_5->setWidget(9, QFormLayout::SpanningRole, label_66);

        cbSecteur_7 = new QComboBox(layoutWidget_4);
        cbSecteur_7->addItem(QString());
        cbSecteur_7->addItem(QString());
        cbSecteur_7->addItem(QString());
        cbSecteur_7->addItem(QString());
        cbSecteur_7->addItem(QString());
        cbSecteur_7->addItem(QString());
        cbSecteur_7->setObjectName("cbSecteur_7");
        cbSecteur_7->setIconSize(QSize(130, 20));

        formLayout_5->setWidget(10, QFormLayout::FieldRole, cbSecteur_7);

        label_67 = new QLabel(layoutWidget_4);
        label_67->setObjectName("label_67");
        label_67->setFont(font);

        formLayout_5->setWidget(11, QFormLayout::LabelRole, label_67);

        cbPays_7 = new QComboBox(layoutWidget_4);
        cbPays_7->addItem(QString());
        cbPays_7->addItem(QString());
        cbPays_7->addItem(QString());
        cbPays_7->addItem(QString());
        cbPays_7->addItem(QString());
        cbPays_7->addItem(QString());
        cbPays_7->setObjectName("cbPays_7");

        formLayout_5->setWidget(12, QFormLayout::FieldRole, cbPays_7);

        label_68 = new QLabel(layoutWidget_4);
        label_68->setObjectName("label_68");
        label_68->setFont(font);

        formLayout_5->setWidget(13, QFormLayout::SpanningRole, label_68);

        deDate_7 = new QDateEdit(layoutWidget_4);
        deDate_7->setObjectName("deDate_7");
        deDate_7->setCalendarPopup(true);

        formLayout_5->setWidget(14, QFormLayout::FieldRole, deDate_7);

        leNom_7 = new QLineEdit(layoutWidget_4);
        leNom_7->setObjectName("leNom_7");

        formLayout_5->setWidget(4, QFormLayout::FieldRole, leNom_7);

        leId_7 = new QLineEdit(layoutWidget_4);
        leId_7->setObjectName("leId_7");

        formLayout_5->setWidget(1, QFormLayout::FieldRole, leId_7);

        label_69 = new QLabel(groupBox_4);
        label_69->setObjectName("label_69");
        label_69->setGeometry(QRect(20, 20, 251, 51));
        QFont font1;
        font1.setPointSize(18);
        font1.setUnderline(true);
        label_69->setFont(font1);
        label_69->setLayoutDirection(Qt::LayoutDirection::RightToLeft);
        label_69->setAutoFillBackground(false);
        label_69->setStyleSheet(QString::fromUtf8("selection-background-color: rgb(255, 170, 0);"));
        btnSupprimer_4 = new QPushButton(groupBox_4);
        btnSupprimer_4->setObjectName("btnSupprimer_4");
        btnSupprimer_4->setGeometry(QRect(290, 550, 111, 31));
        btnModifier_4 = new QPushButton(groupBox_4);
        btnModifier_4->setObjectName("btnModifier_4");
        btnModifier_4->setGeometry(QRect(20, 550, 111, 31));
        btnAjouter_4 = new QPushButton(groupBox_4);
        btnAjouter_4->setObjectName("btnAjouter_4");
        btnAjouter_4->setGeometry(QRect(150, 550, 111, 31));
        pushButton_client_2 = new QPushButton(groupBox_4);
        pushButton_client_2->setObjectName("pushButton_client_2");
        pushButton_client_2->setGeometry(QRect(330, 0, 91, 51));
        stackedWidget_2->addWidget(page_client_2);
        page_employe_2 = new QWidget();
        page_employe_2->setObjectName("page_employe_2");
        tabWidget_2 = new QTabWidget(page_employe_2);
        tabWidget_2->setObjectName("tabWidget_2");
        tabWidget_2->setGeometry(QRect(0, 0, 1231, 651));
        tabWidget_2->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        tabWidget_2->setStyleSheet(QString::fromUtf8("/* Les onglets (titres) */\n"
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
        tabWidget_2->setDocumentMode(false);
        tabWidget_2->setTabsClosable(false);
        tabWidget_2->setMovable(false);
        acceuil_2 = new QWidget();
        acceuil_2->setObjectName("acceuil_2");
        groupBox_5 = new QGroupBox(acceuil_2);
        groupBox_5->setObjectName("groupBox_5");
        groupBox_5->setGeometry(QRect(10, 10, 441, 581));
        groupBox_5->setStyleSheet(QString::fromUtf8("background-color: #1E1E2F; color: white; QHeaderView::section { background-color: #5500FF; color: white; }."));
        lineEdit_ajoute_3 = new QLabel(groupBox_5);
        lineEdit_ajoute_3->setObjectName("lineEdit_ajoute_3");
        lineEdit_ajoute_3->setGeometry(QRect(130, 10, 211, 31));
        lineEdit_nom_2 = new QLineEdit(groupBox_5);
        lineEdit_nom_2->setObjectName("lineEdit_nom_2");
        lineEdit_nom_2->setGeometry(QRect(10, 60, 411, 31));
        label_nom_2 = new QLabel(groupBox_5);
        label_nom_2->setObjectName("label_nom_2");
        label_nom_2->setGeometry(QRect(10, 40, 211, 20));
        label_prenom_2 = new QLabel(groupBox_5);
        label_prenom_2->setObjectName("label_prenom_2");
        label_prenom_2->setGeometry(QRect(10, 100, 211, 20));
        lineEdit_prenom_2 = new QLineEdit(groupBox_5);
        lineEdit_prenom_2->setObjectName("lineEdit_prenom_2");
        lineEdit_prenom_2->setGeometry(QRect(10, 120, 411, 28));
        label_email_2 = new QLabel(groupBox_5);
        label_email_2->setObjectName("label_email_2");
        label_email_2->setGeometry(QRect(10, 160, 211, 20));
        lineEdit_email_2 = new QLineEdit(groupBox_5);
        lineEdit_email_2->setObjectName("lineEdit_email_2");
        lineEdit_email_2->setGeometry(QRect(10, 180, 411, 31));
        comboBox_2 = new QComboBox(groupBox_5);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName("comboBox_2");
        comboBox_2->setGeometry(QRect(10, 470, 411, 28));
        label_poste_2 = new QLabel(groupBox_5);
        label_poste_2->setObjectName("label_poste_2");
        label_poste_2->setGeometry(QRect(10, 440, 63, 20));
        Button_ajouter_2 = new QPushButton(groupBox_5);
        Button_ajouter_2->setObjectName("Button_ajouter_2");
        Button_ajouter_2->setGeometry(QRect(140, 540, 161, 29));
        Button_ajouter_2->setStyleSheet(QString::fromUtf8(""));
        comboBox_q_2 = new QComboBox(groupBox_5);
        comboBox_q_2->addItem(QString());
        comboBox_q_2->addItem(QString());
        comboBox_q_2->addItem(QString());
        comboBox_q_2->addItem(QString());
        comboBox_q_2->addItem(QString());
        comboBox_q_2->addItem(QString());
        comboBox_q_2->setObjectName("comboBox_q_2");
        comboBox_q_2->setGeometry(QRect(10, 320, 411, 41));
        label_question_2 = new QLabel(groupBox_5);
        label_question_2->setObjectName("label_question_2");
        label_question_2->setGeometry(QRect(10, 300, 141, 20));
        lineEdit_reponse_4 = new QLineEdit(groupBox_5);
        lineEdit_reponse_4->setObjectName("lineEdit_reponse_4");
        lineEdit_reponse_4->setGeometry(QRect(10, 400, 411, 31));
        label_mdp_3 = new QLabel(groupBox_5);
        label_mdp_3->setObjectName("label_mdp_3");
        label_mdp_3->setGeometry(QRect(10, 380, 211, 20));
        lineEdit_mdp_2 = new QLineEdit(groupBox_5);
        lineEdit_mdp_2->setObjectName("lineEdit_mdp_2");
        lineEdit_mdp_2->setGeometry(QRect(10, 260, 411, 31));
        label_mdp_4 = new QLabel(groupBox_5);
        label_mdp_4->setObjectName("label_mdp_4");
        label_mdp_4->setGeometry(QRect(10, 230, 211, 21));
        groupBox_recherche_2 = new QGroupBox(acceuil_2);
        groupBox_recherche_2->setObjectName("groupBox_recherche_2");
        groupBox_recherche_2->setGeometry(QRect(460, 180, 761, 371));
        groupBox_recherche_2->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
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
        scrollArea_2 = new QScrollArea(groupBox_recherche_2);
        scrollArea_2->setObjectName("scrollArea_2");
        scrollArea_2->setGeometry(QRect(10, 100, 741, 251));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName("scrollAreaWidgetContents_2");
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 739, 249));
        tableWidgetEmployes_2 = new QTableWidget(scrollAreaWidgetContents_2);
        if (tableWidgetEmployes_2->columnCount() < 5)
            tableWidgetEmployes_2->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidgetEmployes_2->setHorizontalHeaderItem(0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidgetEmployes_2->setHorizontalHeaderItem(1, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidgetEmployes_2->setHorizontalHeaderItem(2, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidgetEmployes_2->setHorizontalHeaderItem(3, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidgetEmployes_2->setHorizontalHeaderItem(4, __qtablewidgetitem11);
        tableWidgetEmployes_2->setObjectName("tableWidgetEmployes_2");
        tableWidgetEmployes_2->setGeometry(QRect(0, 0, 741, 251));
        tableWidgetEmployes_2->horizontalHeader()->setDefaultSectionSize(150);
        scrollArea_2->setWidget(scrollAreaWidgetContents_2);
        lineEdit_recherche_2 = new QLineEdit(groupBox_recherche_2);
        lineEdit_recherche_2->setObjectName("lineEdit_recherche_2");
        lineEdit_recherche_2->setGeometry(QRect(10, 60, 201, 28));
        lineEdit_recherche_2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background: transparent;\n"
"    border: 1px solid#55007f;   /* ou autre couleur pour qu'on voie bien les bords */\n"
"    color:#55007f;                 /* texte */\n"
"}"));
        label_rechercher_2 = new QLabel(groupBox_recherche_2);
        label_rechercher_2->setObjectName("label_rechercher_2");
        label_rechercher_2->setGeometry(QRect(10, 30, 341, 20));
        Button_rechercher_2 = new QPushButton(groupBox_recherche_2);
        Button_rechercher_2->setObjectName("Button_rechercher_2");
        Button_rechercher_2->setGeometry(QRect(230, 60, 101, 29));
        Button_tri_2 = new QPushButton(groupBox_recherche_2);
        Button_tri_2->setObjectName("Button_tri_2");
        Button_tri_2->setGeometry(QRect(620, 60, 121, 29));
        banner_2 = new QLabel(acceuil_2);
        banner_2->setObjectName("banner_2");
        banner_2->setGeometry(QRect(470, 10, 731, 171));
        banner_2->setAutoFillBackground(false);
        Button_export_2 = new QPushButton(acceuil_2);
        Button_export_2->setObjectName("Button_export_2");
        Button_export_2->setGeometry(QRect(470, 570, 211, 29));
        Button_export_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: green;\n"
"    color: white; /* Optionnel : texte blanc pour contraste */\n"
"    border: 1px solid darkgreen; /* Optionnel : bordure pour un meilleur rendu */\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: darkgreen; /* Optionnel : couleur au survol */\n"
"}"));
        Button_supprimer_3 = new QPushButton(acceuil_2);
        Button_supprimer_3->setObjectName("Button_supprimer_3");
        Button_supprimer_3->setGeometry(QRect(1140, 570, 81, 29));
        Button_supprimer_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: red;\n"
"    color: white; /* Texte blanc pour contraste */\n"
"    border: 1px solid darkred; /* Bordure pour un meilleur rendu */\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: darkred; /* Couleur au survol */\n"
"}"));
        lineEdit_id_supp_2 = new QLineEdit(acceuil_2);
        lineEdit_id_supp_2->setObjectName("lineEdit_id_supp_2");
        lineEdit_id_supp_2->setGeometry(QRect(950, 570, 181, 28));
        lineEdit_id_supp_2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background: transparent;\n"
"    border: 1px solid#55007f;   /* ou autre couleur pour qu'on voie bien les bords */\n"
"    color:#55007f;                 /* texte */\n"
"}"));
        tabWidget_2->addTab(acceuil_2, QString());
        statistiques_2 = new QWidget();
        statistiques_2->setObjectName("statistiques_2");
        statistique_2 = new QLabel(statistiques_2);
        statistique_2->setObjectName("statistique_2");
        statistique_2->setGeometry(QRect(230, 30, 861, 521));
        tabWidget_2->addTab(statistiques_2, QString());
        stackedWidget_2->addWidget(page_employe_2);
        page_media_2 = new QWidget();
        page_media_2->setObjectName("page_media_2");
        stackedWidget_2->addWidget(page_media_2);
        page_feedback_2 = new QWidget();
        page_feedback_2->setObjectName("page_feedback_2");
        pushButton_12 = new QPushButton(page_feedback_2);
        pushButton_12->setObjectName("pushButton_12");
        pushButton_12->setGeometry(QRect(410, 490, 111, 29));
        pushButton_12->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: green;\n"
"    color: white; /* Optionnel : texte blanc pour contraste */\n"
"    border: 1px solid darkgreen; /* Optionnel : bordure pour un meilleur rendu */\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: darkgreen; /* Optionnel : couleur au survol */\n"
"}"));
        widget_2 = new QWidget(page_feedback_2);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(10, 20, 391, 571));
        widget_2->setStyleSheet(QString::fromUtf8("background-color: #1E1E2F; color: white; QHeaderView::section { background-color: #5500FF; color: white; }."));
        dateEdit_3 = new QDateEdit(widget_2);
        dateEdit_3->setObjectName("dateEdit_3");
        dateEdit_3->setGeometry(QRect(160, 450, 181, 29));
        label_8 = new QLabel(widget_2);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(10, 490, 121, 20));
        lineEdit_7 = new QLineEdit(widget_2);
        lineEdit_7->setObjectName("lineEdit_7");
        lineEdit_7->setGeometry(QRect(140, 310, 241, 28));
        lineEdit_8 = new QLineEdit(widget_2);
        lineEdit_8->setObjectName("lineEdit_8");
        lineEdit_8->setGeometry(QRect(140, 240, 241, 28));
        label_9 = new QLabel(widget_2);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(30, 310, 63, 20));
        label_10 = new QLabel(widget_2);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(30, 380, 91, 20));
        label_11 = new QLabel(widget_2);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(30, 100, 101, 20));
        label_12 = new QLabel(widget_2);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(30, 450, 63, 20));
        dateEdit_4 = new QDateEdit(widget_2);
        dateEdit_4->setObjectName("dateEdit_4");
        dateEdit_4->setGeometry(QRect(160, 380, 181, 29));
        label_13 = new QLabel(widget_2);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(30, 240, 63, 20));
        lineEdit_9 = new QLineEdit(widget_2);
        lineEdit_9->setObjectName("lineEdit_9");
        lineEdit_9->setGeometry(QRect(140, 170, 241, 28));
        lineEdit_10 = new QLineEdit(widget_2);
        lineEdit_10->setObjectName("lineEdit_10");
        lineEdit_10->setGeometry(QRect(140, 100, 241, 28));
        label_14 = new QLabel(widget_2);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(10, 170, 131, 20));
        lineEdit_15 = new QLineEdit(widget_2);
        lineEdit_15->setObjectName("lineEdit_15");
        lineEdit_15->setGeometry(QRect(140, 490, 241, 28));
        pushButton_13 = new QPushButton(widget_2);
        pushButton_13->setObjectName("pushButton_13");
        pushButton_13->setGeometry(QRect(80, 530, 90, 29));
        pushButton_14 = new QPushButton(widget_2);
        pushButton_14->setObjectName("pushButton_14");
        pushButton_14->setGeometry(QRect(230, 530, 90, 29));
        lineEdit_ajoute_4 = new QLabel(widget_2);
        lineEdit_ajoute_4->setObjectName("lineEdit_ajoute_4");
        lineEdit_ajoute_4->setGeometry(QRect(90, 30, 211, 31));
        pushButton_15 = new QPushButton(page_feedback_2);
        pushButton_15->setObjectName("pushButton_15");
        pushButton_15->setGeometry(QRect(1130, 490, 90, 29));
        pushButton_15->setStyleSheet(QString::fromUtf8("alternate-background-color: rgb(204, 0, 3);\n"
"background-color: rgb(157, 7, 10);"));
        groupBox_6 = new QGroupBox(page_feedback_2);
        groupBox_6->setObjectName("groupBox_6");
        groupBox_6->setGeometry(QRect(410, 60, 811, 421));
        groupBox_6->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
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
        tableWidget_2 = new QTableWidget(groupBox_6);
        if (tableWidget_2->columnCount() < 7)
            tableWidget_2->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(0, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(1, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(2, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(3, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(4, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(5, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(6, __qtablewidgetitem18);
        tableWidget_2->setObjectName("tableWidget_2");
        tableWidget_2->setGeometry(QRect(10, 90, 791, 311));
        tableWidget_2->setStyleSheet(QString::fromUtf8(""));
        tableWidget_2->horizontalHeader()->setDefaultSectionSize(113);
        label_32 = new QLabel(groupBox_6);
        label_32->setObjectName("label_32");
        label_32->setGeometry(QRect(10, 40, 63, 20));
        pushButton_16 = new QPushButton(groupBox_6);
        pushButton_16->setObjectName("pushButton_16");
        pushButton_16->setGeometry(QRect(460, 40, 90, 29));
        pushButton_16->setStyleSheet(QString::fromUtf8(""));
        lineEdit_11 = new QLineEdit(groupBox_6);
        lineEdit_11->setObjectName("lineEdit_11");
        lineEdit_11->setGeometry(QRect(60, 40, 371, 28));
        lineEdit_11->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background: transparent;\n"
"    border: 1px solid#55007f;   /* ou autre couleur pour qu'on voie bien les bords */\n"
"    color:#55007f;                 /* texte */\n"
"}\n"
""));
        lineEdit_12 = new QLineEdit(page_feedback_2);
        lineEdit_12->setObjectName("lineEdit_12");
        lineEdit_12->setGeometry(QRect(750, 490, 371, 28));
        lineEdit_12->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background: transparent;\n"
"    border: 1px solid#55007f;   /* ou autre couleur pour qu'on voie bien les bords */\n"
"    color:#55007f;                 /* texte */\n"
"}"));
        stackedWidget_2->addWidget(page_feedback_2);
        page_categorie_2 = new QWidget();
        page_categorie_2->setObjectName("page_categorie_2");
        stackedWidget_2->addWidget(page_categorie_2);
        stackedWidget_principale->addWidget(page_4);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 952, 17));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName("mainToolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        stackedWidget_principale->setCurrentIndex(1);
        stackedWidget_login_2->setCurrentIndex(0);
        stackedWidget_2->setCurrentIndex(1);
        tabWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Gestion des Clients", nullptr));
        label_mdp_login_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:700; color:#55007f;\">mots de passe:</span></p></body></html>", nullptr));
        label_connexion_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:26pt; font-weight:700; color:#ffaa00;\">Connexion</span></p></body></html>", nullptr));
        label_email_login_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:700; color:#55007f;\">Email:</span></p></body></html>", nullptr));
        pushButton_mdp_oublie_2->setText(QCoreApplication::translate("MainWindow", "mot de passe oubli\303\251 ?", nullptr));
        label_38->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:700; color:#ffffff;\">quel est le nom de votre premier </span></p><p align=\"center\"><span style=\" font-size:12pt; font-weight:700; color:#ffffff;\">animal de compagnie ?</span></p></body></html>", nullptr));
        label_39->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:700; color:#ffffff;\">nouveau mot de passe</span></p></body></html>", nullptr));
        pushButton_valide_mdp_2->setText(QCoreApplication::translate("MainWindow", "valid\303\251", nullptr));
        background_2->setText(QString());
        leSearch_7->setPlaceholderText(QCoreApplication::translate("MainWindow", "Recherche...", nullptr));
        cbPaysF_7->setItemText(0, QCoreApplication::translate("MainWindow", "Pays", nullptr));
        cbPaysF_7->setItemText(1, QCoreApplication::translate("MainWindow", "Tunisie", nullptr));
        cbPaysF_7->setItemText(2, QCoreApplication::translate("MainWindow", "Alg\303\251rie", nullptr));
        cbPaysF_7->setItemText(3, QCoreApplication::translate("MainWindow", "France", nullptr));
        cbPaysF_7->setItemText(4, QCoreApplication::translate("MainWindow", "Italie", nullptr));
        cbPaysF_7->setItemText(5, QCoreApplication::translate("MainWindow", "Allemagne", nullptr));

        cbPaysF_7->setPlaceholderText(QCoreApplication::translate("MainWindow", "Pays", nullptr));
        btnClearFilter_7->setText(QCoreApplication::translate("MainWindow", "Effacer les filtres", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "Export CSV", nullptr));
        pushButton_10->setText(QCoreApplication::translate("MainWindow", "Statistiques", nullptr));
        pushButton_11->setText(QCoreApplication::translate("MainWindow", "Clients Inactifs", nullptr));
        cbSecteurF_7->setItemText(0, QCoreApplication::translate("MainWindow", "Secteur", nullptr));
        cbSecteurF_7->setItemText(1, QCoreApplication::translate("MainWindow", "Design et Multim\303\251dia", nullptr));
        cbSecteurF_7->setItemText(2, QCoreApplication::translate("MainWindow", "D\303\251veloppement Web", nullptr));
        cbSecteurF_7->setItemText(3, QCoreApplication::translate("MainWindow", "Marketing et Communication digitale", nullptr));
        cbSecteurF_7->setItemText(4, QCoreApplication::translate("MainWindow", "Production Vid\303\251o", nullptr));
        cbSecteurF_7->setItemText(5, QCoreApplication::translate("MainWindow", "\303\211dition et Contenu \303\251crit", nullptr));

        cbSecteurF_7->setPlaceholderText(QCoreApplication::translate("MainWindow", "Secteur", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableClients_7->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableClients_7->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableClients_7->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableClients_7->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "T\303\251l\303\251phone", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableClients_7->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "SecteurActivit\303\251", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableClients_7->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "Pays", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableClients_7->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "DateCr\303\251ation", nullptr));
        groupBox_4->setTitle(QString());
        label_62->setText(QCoreApplication::translate("MainWindow", "ID :", nullptr));
        label_63->setText(QCoreApplication::translate("MainWindow", "Nom et Pr\303\251nom :", nullptr));
        label_64->setText(QCoreApplication::translate("MainWindow", "Email :", nullptr));
        leEmail_7->setPlaceholderText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        label_65->setText(QCoreApplication::translate("MainWindow", "T\303\251l\303\251phone :", nullptr));
        leTel_7->setPlaceholderText(QCoreApplication::translate("MainWindow", "T\303\251l\303\251phone", nullptr));
        label_66->setText(QCoreApplication::translate("MainWindow", "Secteur d'Activit\303\251 :", nullptr));
        cbSecteur_7->setItemText(0, QCoreApplication::translate("MainWindow", "Secteur...", nullptr));
        cbSecteur_7->setItemText(1, QCoreApplication::translate("MainWindow", "Design et Multim\303\251dia", nullptr));
        cbSecteur_7->setItemText(2, QCoreApplication::translate("MainWindow", "D\303\251veloppement Web", nullptr));
        cbSecteur_7->setItemText(3, QCoreApplication::translate("MainWindow", "Marketing et Communication digital", nullptr));
        cbSecteur_7->setItemText(4, QCoreApplication::translate("MainWindow", "Production Vid\303\251o", nullptr));
        cbSecteur_7->setItemText(5, QCoreApplication::translate("MainWindow", "\303\211dition & Contenu \303\251crit", nullptr));

        cbSecteur_7->setPlaceholderText(QCoreApplication::translate("MainWindow", "Secteur", nullptr));
        label_67->setText(QCoreApplication::translate("MainWindow", "Pays :", nullptr));
        cbPays_7->setItemText(0, QCoreApplication::translate("MainWindow", "Pays...", nullptr));
        cbPays_7->setItemText(1, QCoreApplication::translate("MainWindow", "Tunisie", nullptr));
        cbPays_7->setItemText(2, QCoreApplication::translate("MainWindow", "Alg\303\251rie", nullptr));
        cbPays_7->setItemText(3, QCoreApplication::translate("MainWindow", "France", nullptr));
        cbPays_7->setItemText(4, QCoreApplication::translate("MainWindow", "Italie", nullptr));
        cbPays_7->setItemText(5, QCoreApplication::translate("MainWindow", "Allemagne ", nullptr));

        cbPays_7->setPlaceholderText(QCoreApplication::translate("MainWindow", "Pays", nullptr));
        label_68->setText(QCoreApplication::translate("MainWindow", "Date d'Inscription :", nullptr));
        deDate_7->setDisplayFormat(QCoreApplication::translate("MainWindow", "yyyy-MM-dd", nullptr));
        leNom_7->setText(QString());
        leNom_7->setPlaceholderText(QCoreApplication::translate("MainWindow", "Nom et Pr\303\251nom", nullptr));
        leId_7->setPlaceholderText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        label_69->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:700; text-decoration:none; color:#aa00ff;\">Formulaire client</span></p></body></html>", nullptr));
        btnSupprimer_4->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        btnModifier_4->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        btnAjouter_4->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        pushButton_client_2->setText(QCoreApplication::translate("MainWindow", "Client", nullptr));
#if QT_CONFIG(whatsthis)
        groupBox_5->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        groupBox_5->setTitle(QString());
        lineEdit_ajoute_3->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:700; color:#ffaa00;\">formulaire employ\303\251</span></p></body></html>", nullptr));
        label_nom_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:700; color:#55007f;\">Nom</span></p></body></html>", nullptr));
        label_prenom_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:700; color:#55007f;\">Pr\303\251nom</span></p></body></html>", nullptr));
        label_email_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:700; color:#55007f;\">Email</span></p></body></html>", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("MainWindow", "Chef de projet", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("MainWindow", "Community Manager", nullptr));
        comboBox_2->setItemText(2, QCoreApplication::translate("MainWindow", "Commercial", nullptr));
        comboBox_2->setItemText(3, QCoreApplication::translate("MainWindow", "Consultant Cybers\303\251curit\303\251", nullptr));
        comboBox_2->setItemText(4, QCoreApplication::translate("MainWindow", "Graphiste", nullptr));
        comboBox_2->setItemText(5, QCoreApplication::translate("MainWindow", "Cr\303\251ateur", nullptr));
        comboBox_2->setItemText(6, QCoreApplication::translate("MainWindow", "Developpeur", nullptr));
        comboBox_2->setItemText(7, QCoreApplication::translate("MainWindow", "Responsable Marketing Digital", nullptr));
        comboBox_2->setItemText(8, QCoreApplication::translate("MainWindow", "Responsable Produit", nullptr));
        comboBox_2->setItemText(9, QCoreApplication::translate("MainWindow", "Responsable RH", nullptr));
        comboBox_2->setItemText(10, QCoreApplication::translate("MainWindow", "Vid\303\251aste", nullptr));

        label_poste_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:700; color:#55007f;\">Poste</span></p></body></html>", nullptr));
        Button_ajouter_2->setText(QCoreApplication::translate("MainWindow", "ajouter", nullptr));
        comboBox_q_2->setItemText(0, QCoreApplication::translate("MainWindow", "Quel est le nom de votre premier animal de compagnie ?", nullptr));
        comboBox_q_2->setItemText(1, QCoreApplication::translate("MainWindow", "Quel est le nom de votre \303\251cole primaire ?", nullptr));
        comboBox_q_2->setItemText(2, QCoreApplication::translate("MainWindow", "Quel est le plat pr\303\251f\303\251r\303\251 de votre grand-parent ?", nullptr));
        comboBox_q_2->setItemText(3, QCoreApplication::translate("MainWindow", "Quelle est la marque de votre premier t\303\251l\303\251phone portable ?", nullptr));
        comboBox_q_2->setItemText(4, QCoreApplication::translate("MainWindow", "Quel est le nom de votre premi\303\250re voiture ?", nullptr));
        comboBox_q_2->setItemText(5, QCoreApplication::translate("MainWindow", "Quel est le surnom que seule votre famille vous donne ?", nullptr));

        label_question_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:700; color:#55007f;\">Qestion secrete</span></p></body></html>", nullptr));
        label_mdp_3->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:700; color:#55007f;\">reponse secrete</span></p></body></html>", nullptr));
        label_mdp_4->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:700; color:#55007f;\">Mot de passe</span></p></body></html>", nullptr));
        groupBox_recherche_2->setTitle(QString());
        QTableWidgetItem *___qtablewidgetitem7 = tableWidgetEmployes_2->horizontalHeaderItem(0);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", " ID   ", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidgetEmployes_2->horizontalHeaderItem(1);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "Poste    ", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidgetEmployes_2->horizontalHeaderItem(2);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "Nom    ", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidgetEmployes_2->horizontalHeaderItem(3);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", " Pr\303\251nom   ", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidgetEmployes_2->horizontalHeaderItem(4);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("MainWindow", "Email    ", nullptr));
        lineEdit_recherche_2->setText(QString());
        label_rechercher_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:700; color:#00007f;\">recherche d'un employ\303\251 par ID</span></p></body></html>", nullptr));
        Button_rechercher_2->setText(QCoreApplication::translate("MainWindow", "appliquer", nullptr));
        Button_tri_2->setText(QCoreApplication::translate("MainWindow", "trier par poste", nullptr));
        banner_2->setText(QString());
        Button_export_2->setText(QCoreApplication::translate("MainWindow", "Exporter la liste des employ\303\251", nullptr));
        Button_supprimer_3->setText(QCoreApplication::translate("MainWindow", "supprimer", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(acceuil_2), QCoreApplication::translate("MainWindow", "       accueil         ", nullptr));
        statistique_2->setText(QString());
        tabWidget_2->setTabText(tabWidget_2->indexOf(statistiques_2), QCoreApplication::translate("MainWindow", "    statistiques    ", nullptr));
        pushButton_12->setText(QCoreApplication::translate("MainWindow", "exporter PDF", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "plateforme cibl\303\251e", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "budget", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "date d\303\251but", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "ID compagne", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "date fin", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "objectif", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "nom de compagne", nullptr));
        pushButton_13->setText(QCoreApplication::translate("MainWindow", "ajouter", nullptr));
        pushButton_14->setText(QCoreApplication::translate("MainWindow", "modifier", nullptr));
        lineEdit_ajoute_4->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:700; color:#ffaa00;\">formulaire Compagne</span></p></body></html>", nullptr));
        pushButton_15->setText(QCoreApplication::translate("MainWindow", "supprimer", nullptr));
        groupBox_6->setTitle(QString());
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget_2->horizontalHeaderItem(0);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("MainWindow", "ID ", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget_2->horizontalHeaderItem(1);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("MainWindow", "nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget_2->horizontalHeaderItem(2);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("MainWindow", "objectif", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget_2->horizontalHeaderItem(3);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("MainWindow", "budget", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget_2->horizontalHeaderItem(4);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("MainWindow", "date d\303\251but", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget_2->horizontalHeaderItem(5);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("MainWindow", "date fin", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget_2->horizontalHeaderItem(6);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("MainWindow", "plateforme", nullptr));
        label_32->setText(QCoreApplication::translate("MainWindow", "statut:", nullptr));
        pushButton_16->setText(QCoreApplication::translate("MainWindow", "recherche", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
