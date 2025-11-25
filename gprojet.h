#ifndef GPROJET_H
#define GPROJET_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QCalendarWidget>
#include <QLabel>
#include <QDialog>
#include <QPrinter>
#include <QPainter>
#include <QFileDialog>
#include "projet.h"
#include "chatbot.h"

QT_BEGIN_NAMESPACE
namespace Ui { class gprojet; }
QT_END_NAMESPACE

class gprojet : public QMainWindow
{
    Q_OBJECT

public:
    explicit gprojet(QWidget *parent = nullptr);
    ~gprojet();

private slots:
    void on_addProjectButton_clicked();
    void on_deleteProjectButton_clicked();
    void on_sortByBudgetButton_clicked();
    void on_sortByDateButton_clicked();
    void on_refreshButton_clicked();
    void on_modifButton_clicked();
    void on_cancelModificationButton_clicked();
    void on_saveModificationButton_clicked();
    void on_searchButton_clicked();
    void on_searchLineEdit_textChanged(const QString &text);
    void on_calendarButton_clicked();
    void on_calculateDaysButton_clicked();
    void on_statsBudgetButton_clicked();
    void on_chatbotButton_clicked();
    void on_exportPdfButton_clicked();  // Nouveau slot

private:
    Ui::gprojet *ui;
    QSqlDatabase db;
    Projet projetModel;
    bool isModifying;
    int currentModifyIdClient;
    ChatBot *chatBot;

    void createTableIfNotExists();
    void clearFormFields();
    bool validateDates(const QString& dateDebutStr, const QString& dateFinStr);
    bool validateBudget(const QString& budgetStr);
    bool validateIdClient(const QString& idClientStr);
    void setModificationMode(bool modifying);
    void refreshTableWidget();
    void setupTableWidget();
    void searchProjects(const QString& searchText);
    void showCalendarWithProjects();
    void highlightProjectPeriods(QCalendarWidget *calendar);
    int calculateDaysRemaining(const QString& dateFinStr);
    QDate parseDate(const QString& dateStr);
    void showDaysCalculationResult(QLabel *resultLabel = nullptr);
    void afficherDiagrammeCirculaire();
    void mettreAJourStatsRapides();
    void exporterTableauPDF();  // Nouvelle méthode
};

#endif // GPROJET_H
