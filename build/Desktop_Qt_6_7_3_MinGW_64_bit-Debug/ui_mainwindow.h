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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *acceuil;
    QGroupBox *groupBox;
    QLabel *lineEdit_ajoute;
    QLineEdit *clientLineEdit;
    QLabel *label_nom;
    QPushButton *addProjectButton;
    QLabel *label_nom_3;
    QLabel *label_nom_4;
    QLabel *label_nom_5;
    QLabel *label_nom_6;
    QLineEdit *dateDebutLineEdit;
    QLineEdit *dateFinLineEdit;
    QLineEdit *budgetPrevuLineEdit;
    QLineEdit *budgetRealiseLineEdit;
    QLabel *label_nom_7;
    QLineEdit *lineEdit_nom_6;
    QGroupBox *groupBox_recherche;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QTableWidget *tableWidget;
    QLabel *label_rechercher;
    QPushButton *Button_rechercher;
    QPushButton *Button_tri;
    QLabel *label_nom_2;
    QLabel *banner;
    QPushButton *deleteProjectButton;
    QLineEdit *lineEdit_id_supp;
    QWidget *statistiques;
    QLabel *statistique;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1307, 678);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: #1E1E2F; color: white; QHeaderView::section { background-color: #5500FF; color: white; }.\n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(20, 10, 1231, 661));
        tabWidget->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        tabWidget->setStyleSheet(QString::fromUtf8(""));
        tabWidget->setDocumentMode(false);
        tabWidget->setTabsClosable(false);
        tabWidget->setMovable(false);
        acceuil = new QWidget();
        acceuil->setObjectName("acceuil");
        groupBox = new QGroupBox(acceuil);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 80, 441, 491));
        groupBox->setStyleSheet(QString::fromUtf8("background-color: #1E1E2F; color: white; QHeaderView::section { background-color: #5500FF; color: white; }."));
        lineEdit_ajoute = new QLabel(groupBox);
        lineEdit_ajoute->setObjectName("lineEdit_ajoute");
        lineEdit_ajoute->setGeometry(QRect(110, 10, 211, 31));
        clientLineEdit = new QLineEdit(groupBox);
        clientLineEdit->setObjectName("clientLineEdit");
        clientLineEdit->setGeometry(QRect(10, 70, 411, 28));
        label_nom = new QLabel(groupBox);
        label_nom->setObjectName("label_nom");
        label_nom->setGeometry(QRect(10, 40, 211, 20));
        addProjectButton = new QPushButton(groupBox);
        addProjectButton->setObjectName("addProjectButton");
        addProjectButton->setGeometry(QRect(140, 450, 161, 29));
        addProjectButton->setStyleSheet(QString::fromUtf8(""));
        label_nom_3 = new QLabel(groupBox);
        label_nom_3->setObjectName("label_nom_3");
        label_nom_3->setGeometry(QRect(10, 110, 211, 20));
        label_nom_4 = new QLabel(groupBox);
        label_nom_4->setObjectName("label_nom_4");
        label_nom_4->setGeometry(QRect(10, 180, 211, 20));
        label_nom_5 = new QLabel(groupBox);
        label_nom_5->setObjectName("label_nom_5");
        label_nom_5->setGeometry(QRect(10, 250, 211, 20));
        label_nom_6 = new QLabel(groupBox);
        label_nom_6->setObjectName("label_nom_6");
        label_nom_6->setGeometry(QRect(10, 320, 211, 20));
        dateDebutLineEdit = new QLineEdit(groupBox);
        dateDebutLineEdit->setObjectName("dateDebutLineEdit");
        dateDebutLineEdit->setGeometry(QRect(10, 140, 411, 28));
        dateFinLineEdit = new QLineEdit(groupBox);
        dateFinLineEdit->setObjectName("dateFinLineEdit");
        dateFinLineEdit->setGeometry(QRect(10, 210, 411, 28));
        budgetPrevuLineEdit = new QLineEdit(groupBox);
        budgetPrevuLineEdit->setObjectName("budgetPrevuLineEdit");
        budgetPrevuLineEdit->setGeometry(QRect(10, 280, 411, 28));
        budgetRealiseLineEdit = new QLineEdit(groupBox);
        budgetRealiseLineEdit->setObjectName("budgetRealiseLineEdit");
        budgetRealiseLineEdit->setGeometry(QRect(10, 350, 411, 28));
        label_nom_7 = new QLabel(groupBox);
        label_nom_7->setObjectName("label_nom_7");
        label_nom_7->setGeometry(QRect(10, 390, 211, 20));
        lineEdit_nom_6 = new QLineEdit(groupBox);
        lineEdit_nom_6->setObjectName("lineEdit_nom_6");
        lineEdit_nom_6->setGeometry(QRect(10, 410, 411, 28));
        groupBox_recherche = new QGroupBox(acceuil);
        groupBox_recherche->setObjectName("groupBox_recherche");
        groupBox_recherche->setGeometry(QRect(460, 190, 761, 371));
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
        tableWidget = new QTableWidget(scrollAreaWidgetContents);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(0, 0, 741, 251));
        scrollArea->setWidget(scrollAreaWidgetContents);
        label_rechercher = new QLabel(groupBox_recherche);
        label_rechercher->setObjectName("label_rechercher");
        label_rechercher->setGeometry(QRect(10, 30, 341, 20));
        Button_rechercher = new QPushButton(groupBox_recherche);
        Button_rechercher->setObjectName("Button_rechercher");
        Button_rechercher->setGeometry(QRect(230, 60, 121, 29));
        Button_tri = new QPushButton(groupBox_recherche);
        Button_tri->setObjectName("Button_tri");
        Button_tri->setGeometry(QRect(590, 60, 151, 29));
        label_nom_2 = new QLabel(groupBox_recherche);
        label_nom_2->setObjectName("label_nom_2");
        label_nom_2->setGeometry(QRect(20, 60, 71, 20));
        banner = new QLabel(acceuil);
        banner->setObjectName("banner");
        banner->setGeometry(QRect(470, 10, 731, 171));
        banner->setAutoFillBackground(false);
        deleteProjectButton = new QPushButton(acceuil);
        deleteProjectButton->setObjectName("deleteProjectButton");
        deleteProjectButton->setGeometry(QRect(1140, 570, 81, 29));
        deleteProjectButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        tabWidget->addTab(acceuil, QString());
        statistiques = new QWidget();
        statistiques->setObjectName("statistiques");
        statistique = new QLabel(statistiques);
        statistique->setObjectName("statistique");
        statistique->setGeometry(QRect(230, 30, 861, 521));
        tabWidget->addTab(statistiques, QString());
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
#if QT_CONFIG(whatsthis)
        groupBox->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        groupBox->setTitle(QString());
        lineEdit_ajoute->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:700; color:#ffaa00;\">formulaire employ\303\251</span></p></body></html>", nullptr));
        label_nom->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:700; color:#55007f;\">client:</span></p></body></html>", nullptr));
        addProjectButton->setText(QCoreApplication::translate("MainWindow", "ajouter", nullptr));
        label_nom_3->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:700; color:#55007f;\"> Date debut:</span></p></body></html>", nullptr));
        label_nom_4->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:700; color:#55007f;\">Date fin:</span></p></body></html>", nullptr));
        label_nom_5->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:700; color:#55007f;\">Budget rialiser:</span></p></body></html>", nullptr));
        label_nom_6->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:700; color:#55007f;\">Statut:</span></p></body></html>", nullptr));
        label_nom_7->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:700; color:#55007f;\">Statut:</span></p></body></html>", nullptr));
        groupBox_recherche->setTitle(QString());
        label_rechercher->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:700; color:#00007f;\">recherche d'un projet</span></p></body></html>", nullptr));
        Button_rechercher->setText(QCoreApplication::translate("MainWindow", "Trier par date", nullptr));
        Button_tri->setText(QCoreApplication::translate("MainWindow", "Trier par budget", nullptr));
        label_nom_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:700; color:#55007f;\">type:</span></p></body></html>", nullptr));
        banner->setText(QString());
        deleteProjectButton->setText(QCoreApplication::translate("MainWindow", "supprimer", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(acceuil), QCoreApplication::translate("MainWindow", "       accueil         ", nullptr));
        statistique->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(statistiques), QCoreApplication::translate("MainWindow", "    statistiques    ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
