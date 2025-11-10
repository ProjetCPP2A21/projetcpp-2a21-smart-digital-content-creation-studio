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
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GestionClient
{
public:
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
    QTableWidget *tableClients_6;

    void setupUi(QWidget *GestionClient)
    {
        if (GestionClient->objectName().isEmpty())
            GestionClient->setObjectName("GestionClient");
        GestionClient->resize(1231, 661);
        groupBox_2 = new QGroupBox(GestionClient);
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
        layoutWidget_2 = new QWidget(GestionClient);
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
        tableClients_6->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 2px solid #A64B00;\n"
"    border-radius: 8px;\n"
"    margin-top: 20px;\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 white,\n"
"        stop:1 #FB8C00\n"
"    );\n"
"\n"
"}"));
        tableClients_6->setColumnCount(8);

        verticalLayout_5->addWidget(tableClients_6);


        retranslateUi(GestionClient);

        QMetaObject::connectSlotsByName(GestionClient);
    } // setupUi

    void retranslateUi(QWidget *GestionClient)
    {
        groupBox_2->setTitle(QString());
        label_61->setText(QCoreApplication::translate("GestionClient", "<html><head/><body><p><span style=\" font-weight:700; text-decoration:none; color:#aa00ff;\">Formulaire client</span></p></body></html>", nullptr));
        label_54->setText(QCoreApplication::translate("GestionClient", "ID :", nullptr));
        leId_6->setText(QString());
        leId_6->setPlaceholderText(QCoreApplication::translate("GestionClient", "ID", nullptr));
        label_55->setText(QCoreApplication::translate("GestionClient", "Nom et Pr\303\251nom :", nullptr));
        leNom_6->setPlaceholderText(QCoreApplication::translate("GestionClient", "Nom et Pr\303\251nom", nullptr));
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
        cbPays_6->setItemText(5, QCoreApplication::translate("GestionClient", "Allemagne", nullptr));

        cbPays_6->setPlaceholderText(QCoreApplication::translate("GestionClient", "Pays", nullptr));
        label_60->setText(QCoreApplication::translate("GestionClient", "Date d'Inscription :", nullptr));
        deDate_6->setDisplayFormat(QCoreApplication::translate("GestionClient", "yyyy-MM-dd", nullptr));
        btnModifier_3->setText(QCoreApplication::translate("GestionClient", "Modifier", nullptr));
        btnAjouter_3->setText(QCoreApplication::translate("GestionClient", "Ajouter", nullptr));
        btnSupprimer_3->setText(QCoreApplication::translate("GestionClient", "Supprimer", nullptr));
        leSearch_6->setPlaceholderText(QCoreApplication::translate("GestionClient", "Recherche...", nullptr));
        pushButton_9->setText(QCoreApplication::translate("GestionClient", "Trier", nullptr));
        pushButton_7->setText(QCoreApplication::translate("GestionClient", "Export PDF", nullptr));
        pushButton_8->setText(QCoreApplication::translate("GestionClient", "Statistiques", nullptr));
        pushButton_6->setText(QCoreApplication::translate("GestionClient", "Clients Inactifs", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableClients_6->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("GestionClient", "Activit\303\251", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableClients_6->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("GestionClient", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableClients_6->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("GestionClient", "Nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableClients_6->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("GestionClient", "Email", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableClients_6->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("GestionClient", "T\303\251l\303\251phone", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableClients_6->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("GestionClient", "SecteurActivit\303\251", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableClients_6->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("GestionClient", "Pays", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableClients_6->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("GestionClient", "DateCr\303\251ation", nullptr));
        (void)GestionClient;
    } // retranslateUi

};

namespace Ui {
    class GestionClient: public Ui_GestionClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GESTIONCLIENT_H
