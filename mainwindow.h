#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "bubblemapwindow.h"
#include "qpushbutton.h"
#include <QMainWindow>
#include "ui_mainwindow.h"
#include "Employe.h"
#include "projet.h"
#include <QTableWidgetItem>
#include <QDate>
#include <QPalette>
#include <QColor>
#include <QPixmap>
#include <QPushButton>
//client
#include "client.h"
#include "bubblemapwindow.h"
//client

// === MODULE SPONSOR ===
#include "sponsor.h"
#include <QSortFilterProxyModel>


//ARDUINO
#include "arduino_manager.h"
#include <QMap>



//FIN ARDUINO

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
//ressource
    void setUpInterface();
    void allerAjoutPage();
    void allerPageStats();
    void on_AjoutBut2_clicked();
    void on_RessourceTab_doubleClicked(const QModelIndex &index);
    void on_StatsBut_clicked();
    void on_PDFBut_clicked();

    // --- Recherche dynamique ---
    void on_RechercheRess_textChanged(const QString &text);


private slots:
    // Employés
    void ajouterEmploye();
    void supprimerEmploye();
    void rechercherEmploye();
    void afficherEmployes(QSqlQueryModel *model);
    void trierParPoste();
    void exportEmployes();
    void afficherStatistiques();
    void onItemChanged(QTableWidgetItem *item);
       // ******* login ********
    void login();
    void ouvrirPageMdpOublie();
    void verifierReponseSecrete();
    void validerNouveauMdp();

    void ouvrirPageProjet();
    void ouvrirPageClient();
    void ouvrirPageEmploye();
    void ouvrirPageMedia();
    void ouvrirPageFeedback();
    void ouvrirPageCategorie();

    // Clients
    void refreshClientTable();
    void on_tableClients_6_cellClicked(int row, int column);
    void on_btnAjouter_3_clicked();
    void on_btnModifier_3_clicked();
    void on_btnSupprimer_3_clicked();
    void on_leSearch_6_textChanged(const QString &text);
    void on_pushButton_9_clicked(); // Tri
    void on_pushButton_7_clicked(); // Export PDF - liste complète
    void on_pushButton_6_clicked(); // Export PDF - inactifs
    void on_pushButton_10_clicked(); // Fiche client PDF
    void on_pushButton_8_clicked(); // Statistiques secteurs
    void on_pushButton_11_clicked(); // Map clients
    void on_pushButton_client_clicked(); // bouton du menu latéral pour ouvrir la page client
    //fin client

    // Projets
    void on_btnAjouterProjet_clicked();
    void on_btnModifierProjet_clicked();
    void on_btnSupprimerProjet_clicked();
    void on_btnTriBudgetProjet_clicked();
    void on_btnTriDateProjet_clicked();
    void on_btnRafraichirProjet_clicked();
    void on_btnAnnulerModifProjet_clicked();
    void on_tableProjets_cellClicked(int row, int column);


    // ==== SPONSOR ====
    void on_ajouterButton_2_clicked();
    void on_modifierButton_2_clicked();
    void on_supprimerButton_2_clicked();
    void on_lineEdit_searchGlobal_2_textChanged(const QString &text);
    void on_tableView_2_clicked(const QModelIndex &index);
//ressource
    void on_ImpBut_clicked();


    // === ARDUINO ===
    void onDuplicateDetected();
    void onNoDuplicate();
    void onEnrollOk();
    void onEnrollFail();
    void onFingerId(int id);
    void onCaptureError(QString msg);
    void onClearDbOk();
    void onClearDbFail();
    void verifierEmployeDansBD(int id);
    //scan
    void on_btnScanner_clicked();
    //MAP


    // === FIN ARDUINO ===



private:
    Ui::MainWindow *ui;
    QToolBar *m_tb = nullptr;
    bool isModifyingProjet;
    QString currentModifyClient;
    //clients
    BubbleMapWindow *mapWindow; //map clients
    //finclients

    void setActiveButton(QPushButton *btn);
    void refreshProjetTable();
    void setupProjetTable();

    // === VARIABLES SPONSOR ===
    Sponsor tmpSponsor;
    QSortFilterProxyModel *proxySponsor = nullptr;

    // === FONCTIONS SPONSOR ===
    void actualiserSponsorTable();
    bool validateSponsorInputs();
    void clearSponsorFields();
    // ***** login *****
    bool accesAutorise(QString page);
    Employe employeConnecte;
    Employe employeRecup;
    int tentative_mdp_oublie = 0;
    void redirigerSelonDroits();




    // === EMPREINTE + ARDUINO ===
    // ==========================
    // VARIABLES TEMPORAIRES EMPLOYÉ
    // ==========================

    QString tempNom;
    QString tempPrenom;
    QString tempEmail;
    QString tempMdp;
    QString tempPoste;
    QString tempQ;
    QString tempR;

    int tempFingerprintID = -1;  // ID entre 1 et 127 pour le capteur
    int tempEmployeeID = -1;     // ID employé dans Oracle

    // ==========================
    // ÉTATS D'ATTENTE
    // ==========================
    bool waitingDuplicate = false;  // Attente réponse CHECK_DUPLICATE
    bool waitingEnroll = false;     // Attente réponse ENROLL

    // ==========================
    // MODE D'OPÉRATION
    // ==========================
    enum ModeOperation {
        Mode_Aucun,
        Mode_Ajout,
        Mode_Identification
    };

    ModeOperation modeActuel = Mode_Aucun;

    // ==========================
    // ARDUINO + MAPPING EMPREINTES
    // ==========================
    ArduinoManager *arduino;

    // Mapping : FingerprintID (1–127) → ID_EMPLOYE (Oracle)
    QMap<int, int> fpMap;

    // === FIN EMPREINTE ===
    QMap<int, int> fingerprintMap;   // fpID → employeeID
    // fpID → employeeID Oracle
    int getNextFingerprintSlot();
    void saveFingerprintMap();
    void loadFingerprintMap();

};
#endif // MAINWINDOW_H
