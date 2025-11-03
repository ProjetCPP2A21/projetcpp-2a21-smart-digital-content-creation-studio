/********************************************************************************
** Form generated from reading UI file 'gestion_employe.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GESTION_EMPLOYE_H
#define UI_GESTION_EMPLOYE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
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

class Ui_gestion_employe
{
public:
    QWidget *centralwidget;
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
    QWidget *statistiques_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *gestion_employe)
    {
        if (gestion_employe->objectName().isEmpty())
            gestion_employe->setObjectName("gestion_employe");
        gestion_employe->resize(1250, 701);
        centralwidget = new QWidget(gestion_employe);
        centralwidget->setObjectName("centralwidget");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(10, 10, 1231, 661));
        tabWidget->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        tabWidget->setStyleSheet(QString::fromUtf8(""));
        tabWidget->setDocumentMode(false);
        tabWidget->setTabsClosable(false);
        tabWidget->setMovable(false);
        acceuil = new QWidget();
        acceuil->setObjectName("acceuil");
        groupBox = new QGroupBox(acceuil);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 60, 441, 491));
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
        label_prenom->setGeometry(QRect(10, 90, 211, 20));
        lineEdit_prenom = new QLineEdit(groupBox);
        lineEdit_prenom->setObjectName("lineEdit_prenom");
        lineEdit_prenom->setGeometry(QRect(10, 110, 411, 28));
        label_email = new QLabel(groupBox);
        label_email->setObjectName("label_email");
        label_email->setGeometry(QRect(10, 140, 211, 20));
        lineEdit_email = new QLineEdit(groupBox);
        lineEdit_email->setObjectName("lineEdit_email");
        lineEdit_email->setGeometry(QRect(10, 160, 411, 31));
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
        comboBox->setGeometry(QRect(10, 410, 411, 28));
        label_poste = new QLabel(groupBox);
        label_poste->setObjectName("label_poste");
        label_poste->setGeometry(QRect(10, 390, 63, 20));
        Button_ajouter = new QPushButton(groupBox);
        Button_ajouter->setObjectName("Button_ajouter");
        Button_ajouter->setGeometry(QRect(140, 450, 161, 29));
        Button_ajouter->setStyleSheet(QString::fromUtf8(""));
        comboBox_q = new QComboBox(groupBox);
        comboBox_q->addItem(QString());
        comboBox_q->addItem(QString());
        comboBox_q->addItem(QString());
        comboBox_q->addItem(QString());
        comboBox_q->addItem(QString());
        comboBox_q->addItem(QString());
        comboBox_q->setObjectName("comboBox_q");
        comboBox_q->setGeometry(QRect(10, 280, 411, 41));
        label_question = new QLabel(groupBox);
        label_question->setObjectName("label_question");
        label_question->setGeometry(QRect(10, 260, 141, 20));
        lineEdit_reponse = new QLineEdit(groupBox);
        lineEdit_reponse->setObjectName("lineEdit_reponse");
        lineEdit_reponse->setGeometry(QRect(10, 357, 411, 31));
        label_mdp_2 = new QLabel(groupBox);
        label_mdp_2->setObjectName("label_mdp_2");
        label_mdp_2->setGeometry(QRect(10, 330, 211, 20));
        lineEdit_mdp = new QLineEdit(groupBox);
        lineEdit_mdp->setObjectName("lineEdit_mdp");
        lineEdit_mdp->setGeometry(QRect(10, 221, 411, 28));
        label_mdp = new QLabel(groupBox);
        label_mdp->setObjectName("label_mdp");
        label_mdp->setGeometry(QRect(10, 200, 211, 21));
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
        tableWidgetEmployes = new QTableWidget(scrollAreaWidgetContents);
        if (tableWidgetEmployes->columnCount() < 5)
            tableWidgetEmployes->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidgetEmployes->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidgetEmployes->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidgetEmployes->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidgetEmployes->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidgetEmployes->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        if (tableWidgetEmployes->rowCount() < 7)
            tableWidgetEmployes->setRowCount(7);
        tableWidgetEmployes->setObjectName("tableWidgetEmployes");
        tableWidgetEmployes->setGeometry(QRect(0, 0, 741, 251));
        tableWidgetEmployes->horizontalHeader()->setDefaultSectionSize(145);
        scrollArea->setWidget(scrollAreaWidgetContents);
        lineEdit_recherche = new QLineEdit(groupBox_recherche);
        lineEdit_recherche->setObjectName("lineEdit_recherche");
        lineEdit_recherche->setGeometry(QRect(10, 60, 201, 28));
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
        tabWidget->addTab(acceuil, QString());
        statistiques = new QWidget();
        statistiques->setObjectName("statistiques");
        statistiques_2 = new QWidget(statistiques);
        statistiques_2->setObjectName("statistiques_2");
        statistiques_2->setGeometry(QRect(30, 10, 1141, 601));
        tabWidget->addTab(statistiques, QString());
        gestion_employe->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(gestion_employe);
        statusbar->setObjectName("statusbar");
        gestion_employe->setStatusBar(statusbar);

        retranslateUi(gestion_employe);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(gestion_employe);
    } // setupUi

    void retranslateUi(QMainWindow *gestion_employe)
    {
        gestion_employe->setWindowTitle(QCoreApplication::translate("gestion_employe", "MainWindow", nullptr));
#if QT_CONFIG(whatsthis)
        groupBox->setWhatsThis(QCoreApplication::translate("gestion_employe", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        groupBox->setTitle(QString());
        lineEdit_ajoute->setText(QCoreApplication::translate("gestion_employe", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:700; color:#ffaa00;\">formulaire employ\303\251</span></p></body></html>", nullptr));
        label_nom->setText(QCoreApplication::translate("gestion_employe", "<html><head/><body><p><span style=\" font-weight:700; color:#55007f;\">Nom</span></p></body></html>", nullptr));
        label_prenom->setText(QCoreApplication::translate("gestion_employe", "<html><head/><body><p><span style=\" font-weight:700; color:#55007f;\">Pr\303\251nom</span></p></body></html>", nullptr));
        label_email->setText(QCoreApplication::translate("gestion_employe", "<html><head/><body><p><span style=\" font-weight:700; color:#55007f;\">Email</span></p></body></html>", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("gestion_employe", "Chef de projet", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("gestion_employe", "Community Manager", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("gestion_employe", "Commercial", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("gestion_employe", "Consultant Cybers\303\251curit\303\251", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("gestion_employe", "Graphiste", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("gestion_employe", "Cr\303\251ateur", nullptr));
        comboBox->setItemText(6, QCoreApplication::translate("gestion_employe", "Developpeur", nullptr));
        comboBox->setItemText(7, QCoreApplication::translate("gestion_employe", "Responsable Marketing Digital", nullptr));
        comboBox->setItemText(8, QCoreApplication::translate("gestion_employe", "Responsable Produit", nullptr));
        comboBox->setItemText(9, QCoreApplication::translate("gestion_employe", "Responsable RH", nullptr));
        comboBox->setItemText(10, QCoreApplication::translate("gestion_employe", "Vid\303\251aste", nullptr));

        label_poste->setText(QCoreApplication::translate("gestion_employe", "<html><head/><body><p><span style=\" font-weight:700; color:#55007f;\">Poste</span></p></body></html>", nullptr));
        Button_ajouter->setText(QCoreApplication::translate("gestion_employe", "ajouter", nullptr));
        comboBox_q->setItemText(0, QCoreApplication::translate("gestion_employe", "Quel est le nom de votre premier animal de compagnie ?", nullptr));
        comboBox_q->setItemText(1, QCoreApplication::translate("gestion_employe", "Quel est le nom de votre \303\251cole primaire ?", nullptr));
        comboBox_q->setItemText(2, QCoreApplication::translate("gestion_employe", "Quel est le plat pr\303\251f\303\251r\303\251 de votre grand-parent ?", nullptr));
        comboBox_q->setItemText(3, QCoreApplication::translate("gestion_employe", "Quelle est la marque de votre premier t\303\251l\303\251phone portable ?", nullptr));
        comboBox_q->setItemText(4, QCoreApplication::translate("gestion_employe", "Quel est le nom de votre premi\303\250re voiture ?", nullptr));
        comboBox_q->setItemText(5, QCoreApplication::translate("gestion_employe", "Quel est le surnom que seule votre famille vous donne ?", nullptr));

        label_question->setText(QCoreApplication::translate("gestion_employe", "<html><head/><body><p><span style=\" font-weight:700; color:#55007f;\">Qestion secrete</span></p></body></html>", nullptr));
        label_mdp_2->setText(QCoreApplication::translate("gestion_employe", "<html><head/><body><p><span style=\" font-weight:700; color:#55007f;\">reponse secrete</span></p></body></html>", nullptr));
        label_mdp->setText(QCoreApplication::translate("gestion_employe", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:700; color:#55007f;\">Mot de passe</span></p></body></html>", nullptr));
        groupBox_recherche->setTitle(QString());
        QTableWidgetItem *___qtablewidgetitem = tableWidgetEmployes->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("gestion_employe", " ID   ", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetEmployes->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("gestion_employe", "Poste    ", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidgetEmployes->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("gestion_employe", "Nom    ", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidgetEmployes->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("gestion_employe", " Pr\303\251nom   ", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidgetEmployes->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("gestion_employe", "Email    ", nullptr));
        lineEdit_recherche->setText(QString());
        label_rechercher->setText(QCoreApplication::translate("gestion_employe", "<html><head/><body><p><span style=\" font-weight:700; color:#00007f;\">recherche d'un employ\303\251 par ID</span></p></body></html>", nullptr));
        Button_rechercher->setText(QCoreApplication::translate("gestion_employe", "appliquer", nullptr));
        Button_tri->setText(QCoreApplication::translate("gestion_employe", "trier par poste", nullptr));
        banner->setText(QString());
        Button_export->setText(QCoreApplication::translate("gestion_employe", "Exporter la liste des employ\303\251", nullptr));
        Button_supprimer_2->setText(QCoreApplication::translate("gestion_employe", "supprimer", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(acceuil), QCoreApplication::translate("gestion_employe", "       accueil         ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(statistiques), QCoreApplication::translate("gestion_employe", "    statistiques    ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class gestion_employe: public Ui_gestion_employe {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GESTION_EMPLOYE_H
