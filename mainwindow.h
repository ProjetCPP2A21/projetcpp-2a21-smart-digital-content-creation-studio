#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qpushbutton.h"
#include <QMainWindow>
#include "ui_mainwindow.h"
#include "Employe.h"
#include "client.h"
#include "projet.h"
#include <QTableWidgetItem>
#include <QDate>
#include <QPalette>
#include <QColor>
#include <QPixmap>
#include <QPushButton>

// === MODULE SPONSOR ===
#include "sponsor.h"
#include <QSortFilterProxyModel>

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
    void on_tableClients_6_cellClicked(int row, int column);
    void on_btnAjouter_3_clicked();
    void on_btnModifier_3_clicked();
    void on_btnSupprimer_3_clicked();
    void on_leSearch_6_textChanged(const QString &text);
    void on_pushButton_7_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_8_clicked();

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

private:
    Ui::MainWindow *ui;
    QToolBar *m_tb = nullptr;
    bool isModifyingProjet;
    QString currentModifyClient;

    void setActiveButton(QPushButton *btn);
    void refreshClientTable();
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
};
#endif // MAINWINDOW_H
