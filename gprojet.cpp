#include "gprojet.h"
#include "ui_gprojet.h"
#include "connection.h"
#include "projet.h"
#include "chatbot.h"
#include <QMessageBox>
#include <QDate>
#include <QDebug>
#include <QSqlQuery>
#include <QHeaderView>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QCalendarWidget>
#include <QTextCharFormat>
#include <QVBoxLayout>
#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QPainter>
#include <QPrinter>
#include <QFileDialog>
#include <QTextDocument>
#include <QTextCursor>
#include <QTextTable>
#include <QStandardPaths>

gprojet::gprojet(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::gprojet)
    , isModifying(false)
    , currentModifyIdClient(0)
    , chatBot(nullptr)
{
    ui->setupUi(this);

    // Configuration de la table
    setupTableWidget();

    // Mode normal au départ
    setModificationMode(false);

    // Connexion à la base de données via singleton
    Connection& connection = Connection::getInstance();
    if (connection.createconnect()) {
        db = connection.getDatabase();
        createTableIfNotExists();
        refreshTableWidget();
        qDebug() << "✅ Connexion à la base de données établie";
    } else {
        QMessageBox::critical(this, "Erreur", "Impossible de se connecter à la base de données.");
        qDebug() << "❌ Échec de connexion à la base de données";
    }

    // Connexion pour la recherche en temps réel
    connect(ui->searchLineEdit, &QLineEdit::textChanged, this, &gprojet::on_searchLineEdit_textChanged);

    // Connexion du bouton statistiques
    connect(ui->statsBudgetButton, &QPushButton::clicked, this, &gprojet::on_statsBudgetButton_clicked);

    // Connexion du bouton chatbot
    connect(ui->chatbotButton, &QPushButton::clicked, this, &gprojet::on_chatbotButton_clicked);

    // Connexion du bouton export PDF
    connect(ui->exportPdfButton, &QPushButton::clicked, this, &gprojet::on_exportPdfButton_clicked);
}

gprojet::~gprojet()
{
    delete ui;
    if (chatBot) {
        delete chatBot;
    }
}

void gprojet::setupTableWidget()
{
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->setColumnCount(6);
    QStringList headers;
    headers << "ID Client" << "Budget Prévu" << "Budget Réalisé" << "Date Début" << "Date Fin" << "Statut";
    ui->tableWidget->setHorizontalHeaderLabels(headers);
}

void gprojet::refreshTableWidget()
{
    ui->tableWidget->setRowCount(0);
    QSqlQueryModel* model = projetModel.afficher();

    if (model) {
        for (int row = 0; row < model->rowCount(); ++row) {
            ui->tableWidget->insertRow(row);
            for (int col = 0; col < model->columnCount(); ++col) {
                QTableWidgetItem *item = new QTableWidgetItem(
                    model->data(model->index(row, col)).toString()
                    );
                ui->tableWidget->setItem(row, col, item);
            }
        }
        ui->tableWidget->resizeColumnsToContents();
        delete model;
        qDebug() << "✅ Tableau rafraîchi avec" << ui->tableWidget->rowCount() << "projets";

        // Mettre à jour les stats rapides
        mettreAJourStatsRapides();
    } else {
        qDebug() << "❌ Erreur lors du chargement des projets";
    }
}

void gprojet::mettreAJourStatsRapides()
{
    QVector<QPair<QString, int>> donnees = Projet::compterProjetsParPlageBudget();
    // int total = 0;  // Variable commentée pour éviter l'avertissement

    for (const auto& paire : donnees) {
        // total += paire.second;  // Ligne commentée
    }
}

void gprojet::searchProjects(const QString& searchText)
{
    ui->tableWidget->setRowCount(0);

    if (searchText.isEmpty()) {
        refreshTableWidget();
        return;
    }

    QSqlQueryModel* model = projetModel.rechercher(searchText);

    if (model) {
        for (int row = 0; row < model->rowCount(); ++row) {
            ui->tableWidget->insertRow(row);
            for (int col = 0; col < model->columnCount(); ++col) {
                QTableWidgetItem *item = new QTableWidgetItem(
                    model->data(model->index(row, col)).toString()
                    );
                ui->tableWidget->setItem(row, col, item);
            }
        }
        ui->tableWidget->resizeColumnsToContents();
        delete model;
        qDebug() << "✅ Recherche effectuée pour:" << searchText << "-" << ui->tableWidget->rowCount() << "résultats";
    }
}

void gprojet::createTableIfNotExists()
{
    QSqlQuery query(db);
    QString checkTableSQL = "SELECT COUNT(*) FROM USER_TABLES WHERE TABLE_NAME = 'PROJETS'";

    if (query.exec(checkTableSQL) && query.next() && query.value(0).toInt() == 0) {
        QString createTableSQL =
            "CREATE TABLE PROJETS ("
            "   ID_CLIENT NUMBER PRIMARY KEY, "
            "   BUDGETPREVU NUMBER(15,2), "
            "   BUDGET_REALISE NUMBER(15,2), "
            "   DATEDEBUT VARCHAR2(20), "
            "   DATEFIN VARCHAR2(20), "
            "   STATUT VARCHAR2(50) DEFAULT 'En cours'"
            ")";

        if (query.exec(createTableSQL)) {
            qDebug() << "✅ Table 'PROJETS' créée avec succès";
        } else {
            qDebug() << "❌ Erreur création table:" << query.lastError().text();
        }
    } else {
        qDebug() << "✅ Table 'PROJETS' existe déjà";
    }
}

bool gprojet::validateIdClient(const QString& idClientStr)
{
    if (idClientStr.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "L'ID client est obligatoire !");
        return false;
    }

    bool ok;
    int idClient = idClientStr.toInt(&ok);

    if (!ok || idClient <= 0) {
        QMessageBox::warning(this, "Erreur", "L'ID client doit être un nombre positif !");
        return false;
    }

    return true;
}

void gprojet::setModificationMode(bool modifying)
{
    isModifying = modifying;

    if (modifying) {
        ui->addProjectButton->setText("Confirmer Modification");
        ui->addProjectButton->setStyleSheet("background-color: #ffa500; color: white;");
        ui->cancelModificationButton->setVisible(true);
        ui->modifButton->setEnabled(false);
        ui->deleteProjectButton->setEnabled(false);
        ui->sortByBudgetButton->setEnabled(false);
        ui->sortByDateButton->setEnabled(false);
        ui->calendarButton->setEnabled(false);
        ui->calculateDaysButton->setEnabled(false);
        ui->statsBudgetButton->setEnabled(false);
        ui->chatbotButton->setEnabled(false);
        ui->exportPdfButton->setEnabled(false);
    } else {
        ui->addProjectButton->setText("Ajouter Projet");
        ui->addProjectButton->setStyleSheet("");
        ui->cancelModificationButton->setVisible(false);
        ui->modifButton->setEnabled(true);
        ui->deleteProjectButton->setEnabled(true);
        ui->sortByBudgetButton->setEnabled(true);
        ui->sortByDateButton->setEnabled(true);
        ui->calendarButton->setEnabled(true);
        ui->calculateDaysButton->setEnabled(true);
        ui->statsBudgetButton->setEnabled(true);
        ui->chatbotButton->setEnabled(true);
        ui->exportPdfButton->setEnabled(true);
        currentModifyIdClient = 0;
        clearFormFields();
    }
}

void gprojet::clearFormFields()
{
    ui->idClientLineEdit->clear();
    ui->budgetPrevuLineEdit->clear();
    ui->budgetRealiseLineEdit->clear();
    ui->dateDebutEdit->clear();
    ui->dateFinEdit->clear();
    ui->statutLineEdit->clear();
}

bool gprojet::validateBudget(const QString& budgetStr)
{
    if (budgetStr.isEmpty()) {
        return true; // Budget vide est autorisé
    }

    bool ok;
    double budget = budgetStr.toDouble(&ok);

    if (!ok) {
        QMessageBox::warning(this, "Erreur", "Le budget doit être un nombre valide !");
        return false;
    }

    if (budget < 0) {
        QMessageBox::warning(this, "Erreur", "Le budget ne peut pas être négatif !");
        return false;
    }

    return true;
}

bool gprojet::validateDates(const QString& dateDebutStr, const QString& dateFinStr)
{
    // Validation date début
    if (!dateDebutStr.isEmpty() && dateDebutStr != "N/A") {
        QDate dateDebut = QDate::fromString(dateDebutStr, "dd/MM/yyyy");
        if (!dateDebut.isValid()) {
            dateDebut = QDate::fromString(dateDebutStr, "d/M/yyyy");
            if (!dateDebut.isValid()) {
                QMessageBox::warning(this, "Erreur",
                                     "Format de date début invalide. Utilisez dd/MM/yyyy (ex. 01/11/2025).");
                ui->dateDebutEdit->setFocus();
                return false;
            }
        }
    }

    // Validation date fin
    if (!dateFinStr.isEmpty() && dateFinStr != "N/A") {
        QDate dateFin = QDate::fromString(dateFinStr, "dd/MM/yyyy");
        if (!dateFin.isValid()) {
            dateFin = QDate::fromString(dateFinStr, "d/M/yyyy");
            if (!dateFin.isValid()) {
                QMessageBox::warning(this, "Erreur",
                                     "Format de date fin invalide. Utilisez dd/MM/yyyy (ex. 31/12/2025).");
                ui->dateFinEdit->setFocus();
                return false;
            }
        }
    }

    // Vérification que la date de fin est après la date de début
    if (!dateDebutStr.isEmpty() && !dateFinStr.isEmpty() &&
        dateDebutStr != "N/A" && dateFinStr != "N/A") {

        QDate dateDebut = QDate::fromString(dateDebutStr, "dd/MM/yyyy");
        if (!dateDebut.isValid()) {
            dateDebut = QDate::fromString(dateDebutStr, "d/M/yyyy");
        }

        QDate dateFin = QDate::fromString(dateFinStr, "dd/MM/yyyy");
        if (!dateFin.isValid()) {
            dateFin = QDate::fromString(dateFinStr, "d/M/yyyy");
        }

        if (dateFin < dateDebut) {
            QMessageBox::warning(this, "Erreur", "La date de fin doit être après la date de début !");
            ui->dateFinEdit->setFocus();
            return false;
        }
    }

    return true;
}

void gprojet::on_addProjectButton_clicked()
{
    if (isModifying) {
        on_saveModificationButton_clicked();
        return;
    }

    QString idClientStr = ui->idClientLineEdit->text().trimmed();
    QString budgetPrevuStr = ui->budgetPrevuLineEdit->text().trimmed();
    QString budgetRealiseStr = ui->budgetRealiseLineEdit->text().trimmed();
    QString dateDebutStr = ui->dateDebutEdit->text().trimmed();
    QString dateFinStr = ui->dateFinEdit->text().trimmed();
    QString statut = ui->statutLineEdit->text().trimmed();

    if (!validateIdClient(idClientStr)) {
        ui->idClientLineEdit->setFocus();
        return;
    }

    int idClient = idClientStr.toInt();

    if (Projet::existeClient(idClient)) {
        QMessageBox::warning(this, "Erreur", "Cet ID client existe déjà !");
        ui->idClientLineEdit->setFocus();
        return;
    }

    if (!budgetPrevuStr.isEmpty() && !validateBudget(budgetPrevuStr)) {
        QMessageBox::warning(this, "Erreur", "Budget prévu invalide !");
        ui->budgetPrevuLineEdit->setFocus();
        return;
    }

    if (!budgetRealiseStr.isEmpty() && !validateBudget(budgetRealiseStr)) {
        QMessageBox::warning(this, "Erreur", "Budget réalisé invalide !");
        ui->budgetRealiseLineEdit->setFocus();
        return;
    }

    if (!validateDates(dateDebutStr, dateFinStr)) {
        return;
    }

    double budgetPrevu = budgetPrevuStr.isEmpty() ? 0.0 : budgetPrevuStr.toDouble();
    double budgetRealise = budgetRealiseStr.isEmpty() ? 0.0 : budgetRealiseStr.toDouble();
    QString dateDebutFormatted = dateDebutStr.isEmpty() ? "N/A" : dateDebutStr;
    QString dateFinFormatted = dateFinStr.isEmpty() ? "N/A" : dateFinStr;

    if (statut.isEmpty()) {
        statut = "En cours";
    }

    Projet nouveauProjet(idClient, budgetPrevu, budgetRealise, dateDebutFormatted, dateFinFormatted, statut);
    bool success = nouveauProjet.ajouter();

    if (success) {
        refreshTableWidget();
        clearFormFields();
        QMessageBox::information(this, "Succès", "Projet ajouté avec succès !");
        qDebug() << "✅ Projet ajouté dans Oracle. ID_CLIENT:" << idClient;
    } else {
        QMessageBox::critical(this, "Erreur", "Erreur lors de l'ajout du projet dans la base de données.");
    }
}

void gprojet::on_saveModificationButton_clicked()
{
    if (currentModifyIdClient == 0) {
        QMessageBox::warning(this, "Erreur", "Aucun projet sélectionné pour modification.");
        return;
    }

    QString nouveauIdClientStr = ui->idClientLineEdit->text().trimmed();
    QString nouveauBudgetPrevuStr = ui->budgetPrevuLineEdit->text().trimmed();
    QString nouveauBudgetRealiseStr = ui->budgetRealiseLineEdit->text().trimmed();
    QString nouvelleDateDebutStr = ui->dateDebutEdit->text().trimmed();
    QString nouvelleDateFinStr = ui->dateFinEdit->text().trimmed();
    QString nouveauStatut = ui->statutLineEdit->text().trimmed();

    if (!validateIdClient(nouveauIdClientStr)) {
        ui->idClientLineEdit->setFocus();
        return;
    }

    int nouveauIdClient = nouveauIdClientStr.toInt();

    if (nouveauIdClient != currentModifyIdClient && Projet::existeClient(nouveauIdClient)) {
        QMessageBox::warning(this, "Erreur", "Cet ID client existe déjà !");
        ui->idClientLineEdit->setFocus();
        return;
    }

    if (!nouveauBudgetPrevuStr.isEmpty() && !validateBudget(nouveauBudgetPrevuStr)) {
        QMessageBox::warning(this, "Erreur", "Budget prévu invalide !");
        ui->budgetPrevuLineEdit->setFocus();
        return;
    }

    if (!nouveauBudgetRealiseStr.isEmpty() && !validateBudget(nouveauBudgetRealiseStr)) {
        QMessageBox::warning(this, "Erreur", "Budget réalisé invalide !");
        ui->budgetRealiseLineEdit->setFocus();
        return;
    }

    if (!validateDates(nouvelleDateDebutStr, nouvelleDateFinStr)) {
        return;
    }

    double nouveauBudgetPrevu = nouveauBudgetPrevuStr.isEmpty() ? 0.0 : nouveauBudgetPrevuStr.toDouble();
    double nouveauBudgetRealise = nouveauBudgetRealiseStr.isEmpty() ? 0.0 : nouveauBudgetRealiseStr.toDouble();
    QString nouvelleDateDebutFormatted = nouvelleDateDebutStr.isEmpty() ? "N/A" : nouvelleDateDebutStr;
    QString nouvelleDateFinFormatted = nouvelleDateFinStr.isEmpty() ? "N/A" : nouvelleDateFinStr;

    if (nouveauStatut.isEmpty()) {
        nouveauStatut = "En cours";
    }

    Projet projetModifie(nouveauIdClient, nouveauBudgetPrevu, nouveauBudgetRealise,
                         nouvelleDateDebutFormatted, nouvelleDateFinFormatted, nouveauStatut);

    bool success = projetModifie.modifier(currentModifyIdClient);

    if (success) {
        refreshTableWidget();
        setModificationMode(false);
        QMessageBox::information(this, "Succès", "Projet modifié avec succès !");
        qDebug() << "✅ Projet modifié dans Oracle. Ancien ID_CLIENT:" << currentModifyIdClient << "Nouveau ID_CLIENT:" << nouveauIdClient;
    } else {
        QMessageBox::critical(this, "Erreur", "Erreur lors de la modification du projet dans la base de données.");
    }
}

void gprojet::on_modifButton_clicked()
{
    int currentRow = ui->tableWidget->currentRow();
    if (currentRow < 0) {
        QMessageBox::warning(this, "Modification", "Veuillez sélectionner un projet à modifier.");
        return;
    }

    currentModifyIdClient = ui->tableWidget->item(currentRow, 0)->text().toInt();
    QString budgetPrevuActuel = ui->tableWidget->item(currentRow, 1)->text();
    QString budgetRealiseActuel = ui->tableWidget->item(currentRow, 2)->text();
    QString dateDebutActuelle = ui->tableWidget->item(currentRow, 3)->text();
    QString dateFinActuelle = ui->tableWidget->item(currentRow, 4)->text();
    QString statutActuel = ui->tableWidget->item(currentRow, 5)->text();

    ui->idClientLineEdit->setText(QString::number(currentModifyIdClient));
    ui->budgetPrevuLineEdit->setText(budgetPrevuActuel);
    ui->budgetRealiseLineEdit->setText(budgetRealiseActuel);
    ui->dateDebutEdit->setText(dateDebutActuelle);
    ui->dateFinEdit->setText(dateFinActuelle);
    ui->statutLineEdit->setText(statutActuel);

    setModificationMode(true);

    QMessageBox::information(this, "Modification",
                             "Mode modification activé pour l'ID client: " + QString::number(currentModifyIdClient) +
                                 "\nModifiez les valeurs et cliquez sur 'Confirmer Modification' pour sauvegarder.");
}

void gprojet::on_cancelModificationButton_clicked()
{
    setModificationMode(false);
    QMessageBox::information(this, "Annulation", "Modification annulée.");
}

void gprojet::on_deleteProjectButton_clicked()
{
    int currentRow = ui->tableWidget->currentRow();
    if (currentRow < 0) {
        QMessageBox::warning(this, "Suppression", "Veuillez sélectionner un projet à supprimer.");
        return;
    }

    int idClientProjet = ui->tableWidget->item(currentRow, 0)->text().toInt();
    QString statutProjet = ui->tableWidget->item(currentRow, 5)->text();

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmation",
                                  "Voulez-vous vraiment supprimer le projet avec l'ID client : " + QString::number(idClientProjet) + " ?\n"
                                                                                                                                     "Statut: " + statutProjet,
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        bool success = projetModel.supprimer(idClientProjet);

        if (success) {
            refreshTableWidget();
            QMessageBox::information(this, "Succès", "Projet supprimé avec succès !");
            qDebug() << "✅ Projet supprimé d'Oracle. ID_CLIENT:" << idClientProjet;
        } else {
            QMessageBox::critical(this, "Erreur", "Erreur lors de la suppression du projet dans la base de données.");
        }
    }
}

void gprojet::on_searchButton_clicked()
{
    QString searchText = ui->searchLineEdit->text().trimmed();
    searchProjects(searchText);

    if (searchText.isEmpty()) {
        QMessageBox::information(this, "Recherche", "Affichage de tous les projets.");
    } else {
        QMessageBox::information(this, "Recherche", "Recherche effectuée pour: " + searchText);
    }
}

void gprojet::on_searchLineEdit_textChanged(const QString &text)
{
    searchProjects(text);
}

void gprojet::on_sortByBudgetButton_clicked()
{
    ui->tableWidget->sortItems(1, Qt::DescendingOrder);
    qDebug() << "✅ Tri par budget effectué";
    QMessageBox::information(this, "Tri", "Projets triés par budget (décroissant).");
}

void gprojet::on_sortByDateButton_clicked()
{
    ui->tableWidget->sortItems(4, Qt::AscendingOrder);
    qDebug() << "✅ Tri par date effectué";
    QMessageBox::information(this, "Tri", "Projets triés par date de fin (croissant).");
}

void gprojet::on_refreshButton_clicked()
{
    refreshTableWidget();
    QMessageBox::information(this, "Rafraîchissement", "Données rafraîchies depuis la base de données Oracle.");
    qDebug() << "✅ Données rafraîchies depuis Oracle";
}

// ==================== FONCTIONNALITÉS CALENDRIER ====================

void gprojet::on_calendarButton_clicked()
{
    showCalendarWithProjects();
}

void gprojet::on_calculateDaysButton_clicked()
{
    showDaysCalculationResult();
}

void gprojet::showCalendarWithProjects()
{
    QDialog *calendarDialog = new QDialog(this);
    calendarDialog->setWindowTitle("📅 Calendrier des Projets - Périodes en ROUGE");
    calendarDialog->setMinimumSize(700, 600);

    QVBoxLayout *layout = new QVBoxLayout(calendarDialog);

    QCalendarWidget *calendar = new QCalendarWidget();
    calendar->setGridVisible(true);
    calendar->setMinimumDate(QDate(2020, 1, 1));
    calendar->setMaximumDate(QDate(2030, 12, 31));

    QLabel *infoLabel = new QLabel("🔴 Les périodes des projets sont marquées en ROUGE\n"
                                   "Sélectionnez un projet dans le tableau principal puis cliquez sur '⏳ Calcul Jours'");
    infoLabel->setStyleSheet("QLabel { background-color: #e3f2fd; padding: 10px; border: 1px solid #2196F3; border-radius: 5px; }");

    QLabel *daysLabel = new QLabel("Sélectionnez un projet dans le tableau principal...");
    daysLabel->setStyleSheet("QLabel { background-color: #f5f5f5; padding: 12px; border: 2px solid #cccccc; border-radius: 5px; min-height: 60px; }");
    daysLabel->setAlignment(Qt::AlignCenter);

    QPushButton *calculateButton = new QPushButton("⏳ Calculer Jours Restants pour le Projet Sélectionné");
    calculateButton->setStyleSheet("QPushButton { background-color: #FF9800; color: white; padding: 10px; font-weight: bold; border-radius: 5px; }");

    highlightProjectPeriods(calendar);

    connect(calculateButton, &QPushButton::clicked, [this, daysLabel]() {
        showDaysCalculationResult(daysLabel);
    });

    layout->addWidget(infoLabel);
    layout->addWidget(calendar);
    layout->addWidget(daysLabel);
    layout->addWidget(calculateButton);

    calendarDialog->exec();
}

void gprojet::highlightProjectPeriods(QCalendarWidget *calendar)
{
    if (!calendar) return;

    QTextCharFormat projectFormat;
    projectFormat.setBackground(Qt::red);
    projectFormat.setForeground(Qt::white);
    projectFormat.setFontWeight(QFont::Bold);

    QSqlQuery query;
    query.exec("SELECT ID_CLIENT, DATEDEBUT, DATEFIN FROM PROJETS WHERE DATEDEBUT != 'N/A' AND DATEFIN != 'N/A'");

    int projectsHighlighted = 0;

    while (query.next()) {
        int idProjet = query.value(0).toInt();
        QString dateDebutStr = query.value(1).toString();
        QString dateFinStr = query.value(2).toString();

        QDate dateDebut = parseDate(dateDebutStr);
        QDate dateFin = parseDate(dateFinStr);

        if (dateDebut.isValid() && dateFin.isValid() && dateDebut <= dateFin) {
            QDate currentDate = dateDebut;
            while (currentDate <= dateFin) {
                calendar->setDateTextFormat(currentDate, projectFormat);
                currentDate = currentDate.addDays(1);
            }
            projectsHighlighted++;
            qDebug() << "📅 Projet #" << idProjet << ":" << dateDebutStr << "-" << dateFinStr;
        }
    }

    qDebug() << "✅ Périodes de" << projectsHighlighted << "projets mises en évidence sur le calendrier";
}

QDate gprojet::parseDate(const QString& dateStr)
{
    QDate date = QDate::fromString(dateStr, "dd/MM/yyyy");
    if (!date.isValid()) {
        date = QDate::fromString(dateStr, "d/M/yyyy");
    }
    if (!date.isValid()) {
        date = QDate::fromString(dateStr, "yyyy-MM-dd");
    }
    if (!date.isValid()) {
        date = QDate::fromString(dateStr, "MM/dd/yyyy");
    }
    return date;
}

void gprojet::showDaysCalculationResult(QLabel *resultLabel)
{
    int currentRow = ui->tableWidget->currentRow();
    if (currentRow < 0) {
        QString errorMsg = "❌ Veuillez d'abord sélectionner un projet dans le tableau !";
        if (resultLabel) {
            resultLabel->setText(errorMsg);
            resultLabel->setStyleSheet("QLabel { background-color: #ffebee; color: #c62828; padding: 12px; border: 2px solid #f44336; border-radius: 5px; min-height: 60px; }");
        } else {
            QMessageBox::warning(this, "Calcul Impossible", errorMsg);
        }
        return;
    }

    QString projetId = ui->tableWidget->item(currentRow, 0)->text();
    QString budgetPrevu = ui->tableWidget->item(currentRow, 1)->text();
    QString dateDebutStr = ui->tableWidget->item(currentRow, 3)->text();
    QString dateFinStr = ui->tableWidget->item(currentRow, 4)->text();
    QString projetStatut = ui->tableWidget->item(currentRow, 5)->text();

    if (dateFinStr == "N/A" || dateFinStr.isEmpty()) {
        QString errorMsg = "❌ Ce projet n'a pas de date de fin définie !";
        if (resultLabel) {
            resultLabel->setText(errorMsg);
            resultLabel->setStyleSheet("QLabel { background-color: #ffebee; color: #c62828; padding: 12px; border: 2px solid #f44336; border-radius: 5px; min-height: 60px; }");
        } else {
            QMessageBox::warning(this, "Calcul Impossible", errorMsg);
        }
        return;
    }

    int joursRestants = calculateDaysRemaining(dateFinStr);
    QString message;
    QString styleSheet;

    if (joursRestants > 0) {
        message = QString("📅 PROJET #%1\n"
                          "💰 Budget: %2 €\n"
                          "📆 Période: %3 - %4\n"
                          "⏳ Jours restants: %5 jours\n"
                          "✅ Statut: %6")
                      .arg(projetId)
                      .arg(budgetPrevu)
                      .arg(dateDebutStr)
                      .arg(dateFinStr)
                      .arg(joursRestants)
                      .arg(projetStatut);
        styleSheet = "QLabel { background-color: #e8f5e8; color: #2e7d32; padding: 12px; border: 2px solid #4caf50; border-radius: 5px; min-height: 60px; }";
    } else if (joursRestants == 0) {
        message = QString("⚠️ PROJET #%1\n"
                          "💰 Budget: %2 €\n"
                          "🎯 ÉCHÉANCE AUJOURD'HUI !\n"
                          "📅 Date fin: %3\n"
                          "✅ Statut: %4")
                      .arg(projetId)
                      .arg(budgetPrevu)
                      .arg(dateFinStr)
                      .arg(projetStatut);
        styleSheet = "QLabel { background-color: #fff3e0; color: #ef6c00; padding: 12px; border: 2px solid #ff9800; border-radius: 5px; min-height: 60px; }";
    } else {
        message = QString("❌ PROJET #%1\n"
                          "💰 Budget: %2 €\n"
                          "⌛ DÉPASSÉ de %3 jours\n"
                          "📅 Date fin était: %4\n"
                          "✅ Statut: %5")
                      .arg(projetId)
                      .arg(budgetPrevu)
                      .arg(-joursRestants)
                      .arg(dateFinStr)
                      .arg(projetStatut);
        styleSheet = "QLabel { background-color: #ffebee; color: #c62828; padding: 12px; border: 2px solid #f44336; border-radius: 5px; min-height: 60px; }";
    }

    if (resultLabel) {
        resultLabel->setText(message);
        resultLabel->setStyleSheet(styleSheet);
    } else {
        QMessageBox::information(this, "⏳ Calcul des Jours Restants", message);
    }

    qDebug() << "✅ Calcul jours restants - Projet:" << projetId << "Jours:" << joursRestants;
}

int gprojet::calculateDaysRemaining(const QString& dateFinStr)
{
    QDate dateFin = parseDate(dateFinStr);
    QDate aujourdhui = QDate::currentDate();

    if (!dateFin.isValid()) {
        qDebug() << "❌ Date invalide:" << dateFinStr;
        return -999;
    }

    int joursRestants = aujourdhui.daysTo(dateFin);

    qDebug() << "🔍 Calcul jours - Aujourd'hui:" << aujourdhui.toString("dd/MM/yyyy")
             << "Date fin:" << dateFin.toString("dd/MM/yyyy")
             << "Jours restants:" << joursRestants;

    return joursRestants;
}

// ==================== STATISTIQUES BUDGET ====================

void gprojet::on_statsBudgetButton_clicked()
{
    qDebug() << "🔄 Clic sur bouton statistiques - Début analyse";

    QSqlQuery testQuery;
    testQuery.exec("SELECT BUDGETPREVU FROM PROJETS");
    int totalProjets = 0;
    int projetsAvecBudget = 0;

    while (testQuery.next()) {
        totalProjets++;
        double budget = testQuery.value(0).toDouble();
        if (budget > 0) {
            projetsAvecBudget++;
            qDebug() << "Budget trouvé:" << budget;
        }
    }

    qDebug() << "📋 Bilan général - Total projets:" << totalProjets
             << "Avec budget > 0:" << projetsAvecBudget;

    QVector<QPair<QString, int>> donnees = Projet::compterProjetsParPlageBudget();
    int totalAvecBudget = 0;

    for (const auto& paire : donnees) {
        totalAvecBudget += paire.second;
        qDebug() << "Plage:" << paire.first << "Count:" << paire.second;
    }

    qDebug() << "Total projets dans plages:" << totalAvecBudget;

    if (totalAvecBudget == 0) {
        if (totalProjets == 0) {
            QMessageBox::information(this, "Statistiques",
                                     "Aucun projet dans la base de données.\n"
                                     "Ajoutez d'abord des projets.");
        } else if (projetsAvecBudget == 0) {
            QMessageBox::information(this, "Statistiques",
                                     "Aucun projet avec budget défini.\n"
                                     "Ajoutez des budgets aux projets existants.");
        } else {
            QMessageBox::information(this, "Statistiques",
                                     "Les budgets existent mais ne sont pas classés.\n"
                                     "Vérifiez les valeurs des budgets.");
        }
        return;
    }

    afficherDiagrammeCirculaire();
}

void gprojet::afficherDiagrammeCirculaire()
{
    QDialog *statsDialog = new QDialog(this);
    statsDialog->setWindowTitle("📊 Statistiques des Budgets par Plage");
    statsDialog->setMinimumSize(500, 400);
    statsDialog->setStyleSheet("QDialog { background-color: #f8f9fa; }");

    QVBoxLayout *mainLayout = new QVBoxLayout(statsDialog);

    QLabel *titleLabel = new QLabel("📈 RÉPARTITION DES PROJETS PAR PLAGE DE BUDGET");
    titleLabel->setStyleSheet("QLabel { font-size: 14px; font-weight: bold; color: #2c3e50; padding: 15px; background-color: #e3f2fd; border-radius: 8px; }");
    titleLabel->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(titleLabel);

    QMap<QString, double> stats = Projet::statistiquesPlagesBudget();
    QVector<QPair<QString, int>> comptage = Projet::compterProjetsParPlageBudget();

    int totalProjets = 0;
    for (const auto& paire : comptage) {
        totalProjets += paire.second;
    }

    QWidget *statsWidget = new QWidget();
    QVBoxLayout *statsLayout = new QVBoxLayout(statsWidget);

    QLabel *totalLabel = new QLabel(QString("📊 TOTAL PROJETS ANALYSÉS: %1").arg(totalProjets));
    totalLabel->setStyleSheet("QLabel { font-size: 12px; font-weight: bold; color: #2c3e50; padding: 10px; background-color: white; border: 2px solid #3498db; border-radius: 5px; }");
    totalLabel->setAlignment(Qt::AlignCenter);
    statsLayout->addWidget(totalLabel);

    QVector<QColor> couleurs = {
        QColor("#3498db"),
        QColor("#2ecc71"),
        QColor("#f39c12"),
        QColor("#e74c3c")
    };

    int index = 0;
    for (const auto& paire : comptage) {
        if (paire.second > 0 && stats.contains(paire.first)) {
            double pourcentage = stats[paire.first];

            QWidget *plageWidget = new QWidget();
            QHBoxLayout *plageLayout = new QHBoxLayout(plageWidget);

            QLabel *plageLabel = new QLabel(
                QString("%1: %2 projets (%3%)")
                    .arg(paire.first)
                    .arg(paire.second)
                    .arg(QString::number(pourcentage, 'f', 1))
                );
            plageLabel->setStyleSheet("QLabel { font-size: 11px; font-weight: bold; min-width: 150px; }");

            QWidget *barreWidget = new QWidget();
            barreWidget->setFixedHeight(20);
            barreWidget->setStyleSheet(
                QString("QWidget { background-color: %1; border-radius: 10px; }")
                    .arg(couleurs[index].name())
                );

            int largeurBarre = qMin(200, static_cast<int>(pourcentage * 2));
            barreWidget->setFixedWidth(largeurBarre);

            QLabel *percentLabel = new QLabel(QString("%1%").arg(QString::number(pourcentage, 'f', 1)));
            percentLabel->setStyleSheet("QLabel { font-size: 10px; min-width: 40px; }");

            plageLayout->addWidget(plageLabel);
            plageLayout->addWidget(barreWidget);
            plageLayout->addWidget(percentLabel);
            plageLayout->addStretch();

            statsLayout->addWidget(plageWidget);
            index++;
        }
    }

    QLabel *analyseTitle = new QLabel("📈 ANALYSE");
    analyseTitle->setStyleSheet("QLabel { font-weight: bold; color: #2c3e50; font-size: 12px; margin-top: 15px; }");
    statsLayout->addWidget(analyseTitle);

    QString plageDominante;
    double maxPourcentage = 0;
    for (auto it = stats.begin(); it != stats.end(); ++it) {
        if (it.value() > maxPourcentage) {
            maxPourcentage = it.value();
            plageDominante = it.key();
        }
    }

    QLabel *dominanteLabel = new QLabel(
        QString("🏆 Plage dominante: %1 (%2%)")
            .arg(plageDominante)
            .arg(QString::number(maxPourcentage, 'f', 1))
        );
    dominanteLabel->setStyleSheet("QLabel { font-size: 11px; padding: 8px; background-color: #e8f5e8; border-radius: 5px; margin: 5px; }");
    statsLayout->addWidget(dominanteLabel);

    QLabel *interpretationLabel = new QLabel();
    QString interpretation;
    if (maxPourcentage > 50) {
        interpretation = "💡 La majorité des projets se situent dans cette plage de budget";
    } else if (maxPourcentage > 30) {
        interpretation = "💡 Cette plage représente une part significative des projets";
    } else {
        interpretation = "💡 Les projets sont bien répartis entre les différentes plages";
    }
    interpretationLabel->setText(interpretation);
    interpretationLabel->setStyleSheet("QLabel { font-size: 10px; padding: 8px; background-color: #fff3e0; border-radius: 5px; margin: 5px; }");
    interpretationLabel->setWordWrap(true);
    statsLayout->addWidget(interpretationLabel);

    statsLayout->addStretch();

    QPushButton *closeButton = new QPushButton("Fermer");
    closeButton->setStyleSheet("QPushButton { background-color: #607d8b; color: white; padding: 8px; border-radius: 5px; font-weight: bold; }");
    connect(closeButton, &QPushButton::clicked, statsDialog, &QDialog::accept);
    statsLayout->addWidget(closeButton);

    mainLayout->addWidget(statsWidget);

    statsDialog->exec();
}

// ==================== CHATBOT ====================

void gprojet::on_chatbotButton_clicked()
{
    if (!chatBot) {
        chatBot = new ChatBot(this);
    }

    chatBot->setWindowFlags(Qt::Window | Qt::WindowCloseButtonHint);
    chatBot->setWindowTitle("🤖 Assistant de Gestion de Projets");
    chatBot->resize(500, 600);
    chatBot->show();
    chatBot->raise();
    chatBot->activateWindow();
}

// ==================== EXPORT PDF ====================

void gprojet::on_exportPdfButton_clicked()
{
    exporterTableauPDF();
}

void gprojet::exporterTableauPDF()
{
    if (ui->tableWidget->rowCount() == 0) {
        QMessageBox::warning(this, "Export PDF", "Aucune donnée à exporter !");
        return;
    }

    QString fileName = QFileDialog::getSaveFileName(this,
                                                    "Exporter en PDF",
                                                    QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/projets.pdf",
                                                    "Fichiers PDF (*.pdf)");

    if (fileName.isEmpty()) {
        return;
    }

    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);
    printer.setPageSize(QPageSize(QPageSize::A4));
    printer.setPageOrientation(QPageLayout::Landscape);

    QTextDocument document;
    QTextCursor cursor(&document);

    QTextCharFormat titleFormat;
    titleFormat.setFontPointSize(16);
    titleFormat.setFontWeight(QFont::Bold);
    titleFormat.setForeground(Qt::darkBlue);
    cursor.setCharFormat(titleFormat);
    cursor.insertText("RAPPORT DES PROJETS - ARTEMIA\n");

    QTextCharFormat dateFormat;
    dateFormat.setFontPointSize(10);
    dateFormat.setForeground(Qt::darkGray);
    cursor.setCharFormat(dateFormat);
    cursor.insertText("Généré le: " + QDateTime::currentDateTime().toString("dd/MM/yyyy à hh:mm") + "\n\n");

    QTextCharFormat statsFormat;
    statsFormat.setFontPointSize(10);
    statsFormat.setFontWeight(QFont::Bold);
    cursor.setCharFormat(statsFormat);
    cursor.insertText(QString("Nombre total de projets: %1\n").arg(ui->tableWidget->rowCount()));

    double totalBudgetPrevu = 0;
    double totalBudgetRealise = 0;
    int projetsEnCours = 0;
    int projetsTermines = 0;

    for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
        double budgetPrevu = ui->tableWidget->item(row, 1)->text().toDouble();
        double budgetRealise = ui->tableWidget->item(row, 2)->text().toDouble();
        QString statut = ui->tableWidget->item(row, 5)->text();

        totalBudgetPrevu += budgetPrevu;
        totalBudgetRealise += budgetRealise;

        if (statut.contains("terminé", Qt::CaseInsensitive) || statut.contains("fini", Qt::CaseInsensitive)) {
            projetsTermines++;
        } else {
            projetsEnCours++;
        }
    }

    cursor.insertText(QString("Budget total prévu: %1 €\n").arg(totalBudgetPrevu, 0, 'f', 2));
    cursor.insertText(QString("Budget total réalisé: %1 €\n").arg(totalBudgetRealise, 0, 'f', 2));
    cursor.insertText(QString("Projets en cours: %1 | Projets terminés: %2\n\n").arg(projetsEnCours).arg(projetsTermines));

    QTextTableFormat tableFormat;
    tableFormat.setHeaderRowCount(1);
    tableFormat.setBorderStyle(QTextFrameFormat::BorderStyle_Solid);
    tableFormat.setBorder(1);
    tableFormat.setCellSpacing(0);
    tableFormat.setCellPadding(4);
    tableFormat.setAlignment(Qt::AlignCenter);
    tableFormat.setWidth(QTextLength(QTextLength::PercentageLength, 100));

    QTextTable *table = cursor.insertTable(ui->tableWidget->rowCount() + 1, ui->tableWidget->columnCount(), tableFormat);

    QTextCharFormat headerFormat;
    headerFormat.setFontWeight(QFont::Bold);
    headerFormat.setBackground(QColor(200, 200, 200));
    headerFormat.setForeground(Qt::black);

    for (int col = 0; col < ui->tableWidget->columnCount(); ++col) {
        QTextTableCell headerCell = table->cellAt(0, col);
        QTextCursor headerCursor = headerCell.firstCursorPosition();
        headerCursor.setCharFormat(headerFormat);
        headerCursor.insertText(ui->tableWidget->horizontalHeaderItem(col)->text());
    }

    QTextCharFormat cellFormat;
    cellFormat.setFontPointSize(8);

    for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
        for (int col = 0; col < ui->tableWidget->columnCount(); ++col) {
            QTableWidgetItem *item = ui->tableWidget->item(row, col);
            if (item) {
                QTextTableCell cell = table->cellAt(row + 1, col);
                QTextCursor cellCursor = cell.firstCursorPosition();

                if (col == 1 || col == 2) {
                    QTextCharFormat budgetFormat = cellFormat;
                    budgetFormat.setForeground(Qt::darkGreen);
                    cellCursor.setCharFormat(budgetFormat);
                    QString text = item->text();
                    if (!text.isEmpty() && text != "0") {
                        cellCursor.insertText(text + " €");
                    } else {
                        cellCursor.insertText("N/A");
                    }
                }
                else if (col == 5) {
                    QTextCharFormat statusFormat = cellFormat;
                    QString statut = item->text().toLower();
                    if (statut.contains("terminé") || statut.contains("fini")) {
                        statusFormat.setForeground(Qt::darkGreen);
                        statusFormat.setFontWeight(QFont::Bold);
                    } else if (statut.contains("en cours")) {
                        statusFormat.setForeground(Qt::darkBlue);
                    } else if (statut.contains("retard")) {
                        statusFormat.setForeground(Qt::red);
                    } else {
                        statusFormat.setForeground(Qt::black);
                    }
                    cellCursor.setCharFormat(statusFormat);
                    cellCursor.insertText(item->text());
                }
                else {
                    cellCursor.setCharFormat(cellFormat);
                    cellCursor.insertText(item->text());
                }
            }
        }
    }

    cursor.movePosition(QTextCursor::End);
    cursor.insertBlock();
    cursor.insertBlock();

    QTextCharFormat footerFormat;
    footerFormat.setFontPointSize(8);
    footerFormat.setForeground(Qt::darkGray);
    footerFormat.setFontItalic(true);
    cursor.setCharFormat(footerFormat);
    cursor.insertText("Document généré automatiquement par Artemia - Système de Gestion de Projets");

    document.print(&printer);

    QMessageBox::information(this,
                             "Export PDF Réussi",
                             QString("Le tableau a été exporté avec succès vers:\n%1\n\n"
                                     "Statistiques exportées:\n"
                                     "• %2 projets\n"
                                     "• Budget total: %3 €\n"
                                     "• Date: %4")
                                 .arg(fileName)
                                 .arg(ui->tableWidget->rowCount())
                                 .arg(totalBudgetPrevu, 0, 'f', 2)
                                 .arg(QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm")));

    qDebug() << "✅ PDF exporté:" << fileName;
}
