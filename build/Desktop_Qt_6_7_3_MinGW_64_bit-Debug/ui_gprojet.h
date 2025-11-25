/********************************************************************************
** Form generated from reading UI file 'gprojet.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GPROJET_H
#define UI_GPROJET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gprojet
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *acceuil;
    QGroupBox *groupBox;
    QLabel *lineEdit_ajoute;
    QLineEdit *idClientLineEdit;
    QLabel *label_nom;
    QPushButton *addProjectButton;
    QLabel *label_nom_3;
    QLabel *label_nom_4;
    QLabel *label_nom_5;
    QLineEdit *dateDebutEdit;
    QLineEdit *dateFinEdit;
    QLineEdit *budgetRealiseLineEdit;
    QLabel *label_nom_6;
    QLineEdit *budgetPrevuLineEdit;
    QLabel *label_nom_7;
    QLineEdit *statutLineEdit;
    QGroupBox *groupBox_recherche;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QTableWidget *tableWidget;
    QLabel *label_rechercher;
    QPushButton *sortByDateButton;
    QPushButton *sortByBudgetButton;
    QLabel *label_nom_2;
    QPushButton *sortByBudgetButton_2;
    QLineEdit *searchLineEdit;
    QPushButton *deleteProjectButton;
    QLineEdit *deleteLineEdit;
    QPushButton *modifButton;
    QPushButton *cancelModificationButton;
    QPushButton *refreshButton;
    QCalendarWidget *calendarButton;
    QPushButton *calculateDaysButton;
    QPushButton *statsBudgetButton;
    QPushButton *chatbotButton;
    QPushButton *exportPdfButton;
    QWidget *statistiques;
    QLabel *statistique;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *gprojet)
    {
        if (gprojet->objectName().isEmpty())
            gprojet->setObjectName("gprojet");
        gprojet->resize(1262, 702);
        centralwidget = new QWidget(gprojet);
        centralwidget->setObjectName("centralwidget");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(10, 0, 1231, 661));
        tabWidget->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        tabWidget->setStyleSheet(QString::fromUtf8(""));
        tabWidget->setDocumentMode(false);
        tabWidget->setTabsClosable(false);
        tabWidget->setMovable(false);
        acceuil = new QWidget();
        acceuil->setObjectName("acceuil");
        groupBox = new QGroupBox(acceuil);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 40, 441, 531));
        groupBox->setStyleSheet(QString::fromUtf8("background-color: #1E1E2F; color: white; QHeaderView::section { background-color: #5500FF; color: white; }."));
        lineEdit_ajoute = new QLabel(groupBox);
        lineEdit_ajoute->setObjectName("lineEdit_ajoute");
        lineEdit_ajoute->setGeometry(QRect(110, 10, 211, 31));
        idClientLineEdit = new QLineEdit(groupBox);
        idClientLineEdit->setObjectName("idClientLineEdit");
        idClientLineEdit->setGeometry(QRect(10, 70, 411, 28));
        label_nom = new QLabel(groupBox);
        label_nom->setObjectName("label_nom");
        label_nom->setGeometry(QRect(10, 40, 211, 20));
        addProjectButton = new QPushButton(groupBox);
        addProjectButton->setObjectName("addProjectButton");
        addProjectButton->setGeometry(QRect(120, 470, 161, 29));
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
        dateDebutEdit = new QLineEdit(groupBox);
        dateDebutEdit->setObjectName("dateDebutEdit");
        dateDebutEdit->setGeometry(QRect(10, 140, 411, 28));
        dateFinEdit = new QLineEdit(groupBox);
        dateFinEdit->setObjectName("dateFinEdit");
        dateFinEdit->setGeometry(QRect(10, 210, 411, 28));
        budgetRealiseLineEdit = new QLineEdit(groupBox);
        budgetRealiseLineEdit->setObjectName("budgetRealiseLineEdit");
        budgetRealiseLineEdit->setGeometry(QRect(10, 280, 411, 28));
        label_nom_6 = new QLabel(groupBox);
        label_nom_6->setObjectName("label_nom_6");
        label_nom_6->setGeometry(QRect(10, 320, 211, 20));
        budgetPrevuLineEdit = new QLineEdit(groupBox);
        budgetPrevuLineEdit->setObjectName("budgetPrevuLineEdit");
        budgetPrevuLineEdit->setGeometry(QRect(10, 350, 411, 28));
        label_nom_7 = new QLabel(groupBox);
        label_nom_7->setObjectName("label_nom_7");
        label_nom_7->setGeometry(QRect(10, 390, 211, 20));
        statutLineEdit = new QLineEdit(groupBox);
        statutLineEdit->setObjectName("statutLineEdit");
        statutLineEdit->setGeometry(QRect(10, 420, 411, 28));
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
        label_rechercher->setGeometry(QRect(10, 30, 161, 20));
        sortByDateButton = new QPushButton(groupBox_recherche);
        sortByDateButton->setObjectName("sortByDateButton");
        sortByDateButton->setGeometry(QRect(460, 40, 121, 29));
        sortByBudgetButton = new QPushButton(groupBox_recherche);
        sortByBudgetButton->setObjectName("sortByBudgetButton");
        sortByBudgetButton->setGeometry(QRect(600, 40, 151, 29));
        label_nom_2 = new QLabel(groupBox_recherche);
        label_nom_2->setObjectName("label_nom_2");
        label_nom_2->setGeometry(QRect(20, 60, 71, 20));
        sortByBudgetButton_2 = new QPushButton(groupBox_recherche);
        sortByBudgetButton_2->setObjectName("sortByBudgetButton_2");
        sortByBudgetButton_2->setGeometry(QRect(250, 70, 91, 29));
        searchLineEdit = new QLineEdit(groupBox_recherche);
        searchLineEdit->setObjectName("searchLineEdit");
        searchLineEdit->setGeometry(QRect(210, 30, 181, 28));
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
        deleteLineEdit = new QLineEdit(acceuil);
        deleteLineEdit->setObjectName("deleteLineEdit");
        deleteLineEdit->setGeometry(QRect(950, 570, 181, 28));
        modifButton = new QPushButton(acceuil);
        modifButton->setObjectName("modifButton");
        modifButton->setGeometry(QRect(830, 570, 81, 29));
        modifButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: red;\n"
"    color: white; /* Texte blanc pour contraste */\n"
"    border: 1px solid darkred; /* Bordure pour un meilleur rendu */\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: darkred; /* Couleur au survol */\n"
"}"));
        cancelModificationButton = new QPushButton(acceuil);
        cancelModificationButton->setObjectName("cancelModificationButton");
        cancelModificationButton->setGeometry(QRect(590, 570, 81, 29));
        cancelModificationButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: red;\n"
"    color: white; /* Texte blanc pour contraste */\n"
"    border: 1px solid darkred; /* Bordure pour un meilleur rendu */\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: darkred; /* Couleur au survol */\n"
"}"));
        refreshButton = new QPushButton(acceuil);
        refreshButton->setObjectName("refreshButton");
        refreshButton->setGeometry(QRect(710, 570, 81, 29));
        refreshButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: red;\n"
"    color: white; /* Texte blanc pour contraste */\n"
"    border: 1px solid darkred; /* Bordure pour un meilleur rendu */\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: darkred; /* Couleur au survol */\n"
"}"));
        calendarButton = new QCalendarWidget(acceuil);
        calendarButton->setObjectName("calendarButton");
        calendarButton->setGeometry(QRect(920, 0, 296, 195));
        calculateDaysButton = new QPushButton(acceuil);
        calculateDaysButton->setObjectName("calculateDaysButton");
        calculateDaysButton->setGeometry(QRect(770, 10, 91, 29));
        statsBudgetButton = new QPushButton(acceuil);
        statsBudgetButton->setObjectName("statsBudgetButton");
        statsBudgetButton->setGeometry(QRect(470, 160, 121, 29));
        chatbotButton = new QPushButton(acceuil);
        chatbotButton->setObjectName("chatbotButton");
        chatbotButton->setGeometry(QRect(620, 160, 101, 29));
        exportPdfButton = new QPushButton(acceuil);
        exportPdfButton->setObjectName("exportPdfButton");
        exportPdfButton->setGeometry(QRect(750, 160, 91, 29));
        tabWidget->addTab(acceuil, QString());
        statistiques = new QWidget();
        statistiques->setObjectName("statistiques");
        statistique = new QLabel(statistiques);
        statistique->setObjectName("statistique");
        statistique->setGeometry(QRect(230, 30, 861, 521));
        tabWidget->addTab(statistiques, QString());
        gprojet->setCentralWidget(centralwidget);
        menubar = new QMenuBar(gprojet);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1262, 25));
        gprojet->setMenuBar(menubar);
        statusbar = new QStatusBar(gprojet);
        statusbar->setObjectName("statusbar");
        gprojet->setStatusBar(statusbar);

        retranslateUi(gprojet);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(gprojet);
    } // setupUi

    void retranslateUi(QMainWindow *gprojet)
    {
        gprojet->setWindowTitle(QCoreApplication::translate("gprojet", "gprojet", nullptr));
#if QT_CONFIG(whatsthis)
        groupBox->setWhatsThis(QCoreApplication::translate("gprojet", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        groupBox->setTitle(QString());
        lineEdit_ajoute->setText(QCoreApplication::translate("gprojet", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:700; color:#ffaa00;\">formulaire projet</span></p></body></html>", nullptr));
        label_nom->setText(QCoreApplication::translate("gprojet", "<html><head/><body><p><span style=\" font-weight:700; color:#55007f;\">id client:</span></p></body></html>", nullptr));
        addProjectButton->setText(QCoreApplication::translate("gprojet", "ajouter", nullptr));
        label_nom_3->setText(QCoreApplication::translate("gprojet", "<html><head/><body><p><span style=\" font-weight:700; color:#55007f;\"> Date debut:</span></p></body></html>", nullptr));
        label_nom_4->setText(QCoreApplication::translate("gprojet", "<html><head/><body><p><span style=\" font-weight:700; color:#55007f;\">Date fin:</span></p></body></html>", nullptr));
        label_nom_5->setText(QCoreApplication::translate("gprojet", "<html><head/><body><p><span style=\" font-weight:700; color:#55007f;\">Budget rialiser:</span></p></body></html>", nullptr));
        label_nom_6->setText(QCoreApplication::translate("gprojet", "<html><head/><body><p><span style=\" font-weight:700; color:#55007f;\">Budget prevu:</span></p></body></html>", nullptr));
        label_nom_7->setText(QCoreApplication::translate("gprojet", "<html><head/><body><p><span style=\" font-weight:700; color:#55007f;\">staut;</span></p></body></html>", nullptr));
        groupBox_recherche->setTitle(QString());
        label_rechercher->setText(QCoreApplication::translate("gprojet", "<html><head/><body><p><span style=\" font-weight:700; color:#00007f;\">recherche d'un projet</span></p></body></html>", nullptr));
        sortByDateButton->setText(QCoreApplication::translate("gprojet", "Trier par date", nullptr));
        sortByBudgetButton->setText(QCoreApplication::translate("gprojet", "Trier par budget", nullptr));
        label_nom_2->setText(QCoreApplication::translate("gprojet", "<html><head/><body><p><span style=\" font-weight:700; color:#55007f;\">type:</span></p></body></html>", nullptr));
        sortByBudgetButton_2->setText(QCoreApplication::translate("gprojet", "recherche", nullptr));
        deleteProjectButton->setText(QCoreApplication::translate("gprojet", "supprimer", nullptr));
        modifButton->setText(QCoreApplication::translate("gprojet", "modifier", nullptr));
        cancelModificationButton->setText(QCoreApplication::translate("gprojet", "annuler ", nullptr));
        refreshButton->setText(QCoreApplication::translate("gprojet", "Rafra\303\256chir", nullptr));
        calculateDaysButton->setText(QCoreApplication::translate("gprojet", "Calcul Jours", nullptr));
        statsBudgetButton->setText(QCoreApplication::translate("gprojet", "statistique", nullptr));
        chatbotButton->setText(QCoreApplication::translate("gprojet", "chatbot", nullptr));
        exportPdfButton->setText(QCoreApplication::translate("gprojet", "exporter pdf", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(acceuil), QCoreApplication::translate("gprojet", "       accueil         ", nullptr));
        statistique->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(statistiques), QCoreApplication::translate("gprojet", "    statistiques    ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class gprojet: public Ui_gprojet {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GPROJET_H
