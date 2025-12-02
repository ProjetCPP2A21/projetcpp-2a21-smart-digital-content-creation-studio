#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qpushbutton.h"
#include <QMainWindow>
#include "ui_mainwindow.h"
#include "Employe.h"
#include "client.h"
#include "sponsor.h"
#include "projet.h"
#include "chatbot.h"

#include <QComboBox>
#include <QTableWidgetItem>
#include <QDate>
#include <QPalette>
#include <QColor>
#include <QPixmap>
#include <QSortFilterProxyModel>
#include <QRegularExpression>
#include <QPushButton>
#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>
#include <QPdfWriter>
#include <QPainter>
#include <QVBoxLayout>
#include <QLabel>
#include <QHBoxLayout>
#include <QFile>
#include <utility>

//stat
#include <QtCharts/QChartView>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QValueAxis>
#include <QtCharts/QChart>

#include <QSqlQuery>
#include <QSqlError>
#include <QSqlQueryModel>

//ressources
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QAudioOutput>
#include <QSqlRecord>

//client
#include "bubblemapwindow.h"
#include <QTimer>

// Projets
#include <QCalendarWidget>
#include <QPrinter>
#include <QTextDocument>
#include <QTextCursor>
#include <QTextTable>
#include <QStandardPaths>

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

    // Mode développeur (bypass login)
    bool modeDev = true;

    // Interface ressources
    void setUpInterface();
    void allerAjoutPage();
    void allerPageStats();

private slots:
    // ==================== RESSOURCES ====================
    void on_AjoutBut2_clicked();
    void on_RessourceTab_doubleClicked(const QModelIndex &index);
    void on_StatsBut_clicked();
    void on_PDFBut_clicked();
    void on_RechercheRess_textChanged(const QString &text);
    void on_ImpBut_clicked();

    // ==================== EMPLOYÉS ====================
    void ajouterEmploye();
    void supprimerEmploye();
    void rechercherEmploye();
    void afficherEmployes(QSqlQueryModel *model);
    void trierParPoste();
    void exportEmployes();
    void afficherStatistiques();
    void onItemChanged(QTableWidgetItem *item);

    // ==================== LOGIN ====================
    void login();
    void ouvrirPageMdpOublie();
    void verifierReponseSecrete();
    void validerNouveauMdp();

    // ==================== NAVIGATION ====================
    void ouvrirPageProjet();
    void ouvrirPageClient();
    void ouvrirPageEmploye();
    void ouvrirPageMedia();
    void ouvrirPageFeedback();
    void ouvrirPageCategorie();

    // ==================== CLIENTS ====================
    void refreshClientTable();
    void on_tableClients_6_cellClicked(int row, int column);
    void on_btnAjouter_3_clicked();
    void on_btnModifier_3_clicked();
    void on_btnSupprimer_3_clicked();
    void on_leSearch_6_textChanged(const QString &text);
    void on_pushButton_9_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_10_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_11_clicked();
    void on_pushButton_client_clicked();

    // ==================== SPONSOR ====================
    void on_ajouterButton_2_clicked();
    void on_modifierButton_2_clicked();
    void on_supprimerButton_2_clicked();
    void on_lineEdit_searchGlobal_2_textChanged(const QString &text);
    void on_tableView_2_clicked(const QModelIndex &index);

    // ==================== PROJETS - FONCTIONS PRINCIPALES ====================
    void on_addProjectButton_clicked();
    void on_saveModificationButton_clicked();
    void on_modifButton_clicked();
    void on_cancelModificationButton_clicked();
    void on_deleteProjectButton_clicked();
    void on_searchButton_clicked();
    void on_searchLineEdit_textChanged(const QString &text);
    void on_sortByBudgetButton_clicked();
    void on_sortByDateButton_clicked();
    void on_refreshButton_clicked();
    void on_calendarButton_clicked();
    void on_calculateDaysButton_clicked();
    void on_statsBudgetButton_clicked();

    // CORRECTION IMPORTANTE : Le slot doit avoir exactement le même nom que le bouton dans l'UI
    // Si votre bouton s'appelle "chatbotButton" dans Qt Designer, le slot doit être "on_chatbotButton_clicked"
    void on_chatbotButton_clicked();

    void on_exportPdfButton_clicked();

    // ==================== PROJETS - FONCTIONS SECONDAIRES ====================
    void on_btnAjouterProjet_clicked();
    void on_btnModifierProjet_clicked();
    void on_btnSupprimerProjet_clicked();
    void on_btnTriBudgetProjet_clicked();
    void on_btnTriDateProjet_clicked();
    void on_btnRafraichirProjet_clicked();
    void on_btnAnnulerModifProjet_clicked();
    void on_tableProjets_cellClicked(int row, int column);

private:
    Ui::MainWindow *ui;

    // ==================== VARIABLES MEMBRES ====================

    // Projets
    bool isModifyingProjet;
    int currentModifyIdClientProjet;
    Projet projetModel;
    ChatBot *chatBotProjet;
    QSqlDatabase dbProjet;

    // Client - Carte des clients
    BubbleMapWindow *mapWindow;

    // Sponsor
    Sponsor tmpSponsor;
    QSortFilterProxyModel *proxySponsor;

    // Login et authentification
    Employe employeConnecte;
    Employe employeRecup;
    int tentative_mdp_oublie;

    // ==================== FONCTIONS PRIVÉES ====================

    // Gestion des droits d'accès
    bool accesAutorise(QString page);
    void redirigerSelonDroits();
    void setActiveButton(QPushButton *btn);

    // Projets - Fonctions auxiliaires
    void setupProjetTableWidget();
    void refreshProjetTableWidget();
    void searchProjects(const QString& searchText);
    void createProjetTableIfNotExists();
    bool validateProjetIdClient(const QString& idClientStr);
    void setProjetModificationMode(bool modifying);
    void clearProjetFormFields();
    bool validateProjetBudget(const QString& budgetStr);
    bool validateProjetDates(const QString& dateDebutStr, const QString& dateFinStr);
    void showCalendarWithProjects();
    void highlightProjectPeriods(QCalendarWidget *calendar);
    QDate parseProjetDate(const QString& dateStr);
    void showDaysCalculationResult(QLabel *resultLabel = nullptr);
    int calculateDaysRemaining(const QString& dateFinStr);
    void afficherDiagrammeCirculaireProjet();
    void exporterTableauPDFProjet();
    void mettreAJourStatsRapidesProjet();

    // Projets - Gestion du tableau
    void refreshProjetTable();
    void setupProjetTable();

    // Sponsor - Fonctions auxiliaires
    void actualiserSponsorTable();
    bool validateSponsorInputs();
    void clearSponsorFields();
};

#endif // MAINWINDOW_H
