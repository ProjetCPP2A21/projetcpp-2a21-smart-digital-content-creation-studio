#include "client.h"
#include "ressource.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>
#include <QPdfWriter>
#include <QPainter>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QtCharts/QChart>
#include <QVBoxLayout>
#include <QDate>
#include <QLabel>
#include <QHBoxLayout>
#include <QDebug>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QMessageBox>
#include <QComboBox>
#include <QRegularExpression>
#include "qsqlerror.h"

#include <QMediaPlayer>
#include <QVideoWidget>
#include <QAudioOutput>
#include <QSqlRecord>
#include <QPdfWriter>
#include <QPainter>
#include <utility>
#include <QTemporaryDir>


// === SPONSOR ===
#include "sponsor.h"
#include <QSortFilterProxyModel>
#include <QRegularExpression>

Ressource R; // objet global temporaire


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//ressource
    setUpInterface();

    ui->RessourceTab->setModel(R.afficher());

    connect(ui->AjoutBut, &QPushButton::clicked, this, &MainWindow::allerAjoutPage);
    connect(ui->RetourneBut, &QPushButton::clicked, this, &MainWindow::setUpInterface);
    connect(ui->StatsBut, &QPushButton::clicked, this, &MainWindow::allerPageStats);

    // ================= SPONSOR MODULE INITIALISATION =================
    proxySponsor = new QSortFilterProxyModel(this);
    proxySponsor->setFilterCaseSensitivity(Qt::CaseInsensitive);
    proxySponsor->setFilterKeyColumn(-1); // search all columns

    actualiserSponsorTable();

    // Search sponsor
    connect(ui->lineEdit_searchGlobal_2, &QLineEdit::textChanged, this, &MainWindow::on_lineEdit_searchGlobal_2_textChanged);

    // Click table row
    connect(ui->tableView_2, &QTableView::clicked, this, &MainWindow::on_tableView_2_clicked);



    // Initialisation des variables
    isModifyingProjet = false;
    currentModifyClient = "";

    refreshClientTable();
    setupProjetTable();
    refreshProjetTable();

    // Style uniforme
    this->setStyleSheet("QPushButton { background:#2A2E63; color:#EDEAF9; border:1px solid #4B4F87; border-radius:8px; padding:6px 12px; }"
                        "QPushButton:hover { background:#3A3F7A; }"
                        "QPushButton:pressed { background:#1B1D3F; }");


///////           modificationssss    //////////
    connect(ui->pushButton_quitter, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget_principale->setCurrentWidget(ui->page);
    });

    // ONGLET ACCES
    connect(ui->pushButton_projet, &QPushButton::clicked, this, &MainWindow::ouvrirPageProjet);
    connect(ui->pushButton_client, &QPushButton::clicked, this, &MainWindow::ouvrirPageClient);
    connect(ui->pushButton_employe, &QPushButton::clicked, this, &MainWindow::ouvrirPageEmploye);
    connect(ui->pushButton_media, &QPushButton::clicked, this, &MainWindow::ouvrirPageMedia);
    connect(ui->pushButton_feedback, &QPushButton::clicked, this, &MainWindow::ouvrirPageFeedback);
    connect(ui->pushButton_categorie, &QPushButton::clicked, this, &MainWindow::ouvrirPageCategorie);

    //login
    connect(ui->lineEdit_mdp_login, &QLineEdit::returnPressed, this, &MainWindow::login);
    connect(ui->pushButton_mdp_oublie, &QPushButton::clicked, this, &MainWindow::ouvrirPageMdpOublie);
    connect(ui->lineEdit_reponse_2, &QLineEdit::returnPressed, this, &MainWindow::verifierReponseSecrete);
    connect(ui->pushButton_valide_mdp, &QPushButton::clicked, this, &MainWindow::validerNouveauMdp);


    // Logos
    QPixmap pix(":/logo.png");
    if (!pix.isNull())
        ui->logo->setPixmap(pix.scaled(ui->logo->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ui->logo->setScaledContents(true);

    QPixmap pix_bg(":/background+logo.png");
    if (!pix_bg.isNull())
        ui->background->setPixmap(pix_bg.scaled(ui->background->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ui->background->setScaledContents(true);

    // Gestion employés
    ui->tableWidgetEmployes->setEditTriggers(QAbstractItemView::DoubleClicked | QAbstractItemView::EditKeyPressed);
    connect(ui->tableWidgetEmployes, &QTableWidget::itemChanged, this, &MainWindow::onItemChanged);
    connect(ui->Button_ajouter, &QPushButton::clicked, this, &MainWindow::ajouterEmploye);
    connect(ui->Button_supprimer_2, &QPushButton::clicked, this, &MainWindow::supprimerEmploye);
    connect(ui->Button_rechercher, &QPushButton::clicked, this, &MainWindow::rechercherEmploye);
    connect(ui->Button_export, &QPushButton::clicked, this, &MainWindow::exportEmployes);

    // Configuration tableau employés
    ui->tableWidgetEmployes->setColumnCount(5);
    QStringList headers = {"ID", "Nom", "Prénom", "Email", "Poste"};
    ui->tableWidgetEmployes->setHorizontalHeaderLabels(headers);
    ui->tableWidgetEmployes->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidgetEmployes->horizontalHeader()->setStretchLastSection(false);

    // Affichage initial employés
    Employe tempEmp;
    QSqlQueryModel *initialModel = tempEmp.afficher();
    afficherEmployes(initialModel);
    delete initialModel;

    QPushButton *buttonTri = ui->groupBox_recherche->findChild<QPushButton*>("Button_tri");
    if (buttonTri) {
        connect(buttonTri, &QPushButton::clicked, this, &MainWindow::trierParPoste);
    }

    afficherStatistiques();

    QPixmap pix2(":/banner.png");
    if (!pix2.isNull()) {
        ui->banner->setPixmap(pix2.scaled(ui->banner->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
    ui->banner->setScaledContents(true);

    QLineEdit *lineEditRecherche = ui->groupBox_recherche->findChild<QLineEdit*>("lineEdit_recherche");
    if (lineEditRecherche) {
        lineEditRecherche->setPlaceholderText("ID employé");
    }

    // Connexions pour les boutons projets
    connect(ui->btnAjouterProjet, &QPushButton::clicked, this, &MainWindow::on_btnAjouterProjet_clicked);
    connect(ui->btnModifierProjet, &QPushButton::clicked, this, &MainWindow::on_btnModifierProjet_clicked);
    connect(ui->btnSupprimerProjet, &QPushButton::clicked, this, &MainWindow::on_btnSupprimerProjet_clicked);
    connect(ui->btnTriBudgetProjet, &QPushButton::clicked, this, &MainWindow::on_btnTriBudgetProjet_clicked);
    connect(ui->btnTriDateProjet, &QPushButton::clicked, this, &MainWindow::on_btnTriDateProjet_clicked);
    connect(ui->btnRafraichirProjet, &QPushButton::clicked, this, &MainWindow::on_btnRafraichirProjet_clicked);
    connect(ui->btnAnnulerModifProjet, &QPushButton::clicked, this, &MainWindow::on_btnAnnulerModifProjet_clicked);
    connect(ui->tableWidgetProjets, &QTableWidget::cellClicked, this, &MainWindow::on_tableProjets_cellClicked);

    // Masquer le bouton annuler modification au démarrage
    ui->btnAnnulerModifProjet->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setActiveButton(QPushButton *btn)
{
    ui->pushButton_projet->setStyleSheet("");
    ui->pushButton_client->setStyleSheet("");
    ui->pushButton_employe->setStyleSheet("");
    ui->pushButton_media->setStyleSheet("");
    ui->pushButton_feedback->setStyleSheet("");
    ui->pushButton_categorie->setStyleSheet("");

    btn->setStyleSheet("background-color:#FF8C00; color:black; font-weight:bold;");
}

// Gestion employés
void MainWindow::ajouterEmploye() {
    QString nom = ui->lineEdit_nom->text();
    QString prenom = ui->lineEdit_prenom->text();
    QString mdp = ui->lineEdit_mdp->text();
    QString email = ui->lineEdit_email->text();
    QString poste = ui->comboBox->currentText();
    QString questionSecrete = ui->comboBox_q->currentText();
    QString reponseSecrete = ui->lineEdit_reponse->text();

    if (nom.isEmpty() || prenom.isEmpty() || email.isEmpty() || mdp.isEmpty() || reponseSecrete.isEmpty()) {
        QMessageBox::warning(this, "Champs manquants", "Veuillez remplir tous les champs");
        return;
    }

    QRegularExpression emailRegex("^[A-Za-z0-9._%+-]+@(gmail\\.com|yahoo\\.fr|outlook\\.com)$", QRegularExpression::CaseInsensitiveOption);
    if (!emailRegex.match(email).hasMatch()) {
        QMessageBox::warning(this, "Email invalide", "Veuillez entrer une adresse email valide");
        return;
    }

    Employe emp;
    emp.setNom(nom);
    emp.setPrenom(prenom);
    emp.setMdp(mdp);
    emp.setEmail(email);
    emp.setPoste(poste);
    emp.setQuestionSecrete(questionSecrete);
    emp.setReponseSecrete(reponseSecrete);

    if (emp.ajouter()) {
        QMessageBox::information(this, "Succès", "Employé ajouté avec succès !");
        QSqlQueryModel *model = emp.afficher();
        afficherEmployes(model);
        delete model;
        afficherStatistiques();

        ui->lineEdit_nom->clear();
        ui->lineEdit_prenom->clear();
        ui->lineEdit_email->clear();
        ui->lineEdit_reponse->clear();
        ui->lineEdit_mdp->clear();
    } else {
        QMessageBox::critical(this, "Erreur", "Erreur lors de l'ajout de l'employé !");
    }
}

void MainWindow::onItemChanged(QTableWidgetItem *item) {
    QTableWidget *tableWidget = ui->tableWidgetEmployes;
    if (!tableWidget || !item) return;

    int row = item->row();
    int col = item->column();

    QTableWidgetItem *idItem = tableWidget->item(row, 0);
    if (!idItem) return;

    int id_employe = idItem->text().toInt();
    if (id_employe <= 0) return;

    QString newValue = item->text().trimmed();
    if (newValue.isEmpty()) return;

    QString fieldName;
    switch (col) {
    case 1: fieldName = "nom"; break;
    case 2: fieldName = "prenom"; break;
    case 3: fieldName = "email"; break;
    case 4: fieldName = "poste"; break;
    default: return;
    }

    QSqlQuery query;
    query.prepare(QString("UPDATE employe SET %1 = :newValue WHERE id_employe = :id").arg(fieldName));
    query.bindValue(":newValue", newValue);
    query.bindValue(":id", id_employe);

    if (query.exec()) {
        if (query.numRowsAffected() > 0) {
            afficherStatistiques();
        }
    } else {
        QMessageBox::warning(this, "Erreur", "Impossible de sauvegarder.");
    }
}

void MainWindow::supprimerEmploye() {
    bool ok;
    int id_employe = ui->lineEdit_id_supp->text().toInt(&ok);
    if (!ok || id_employe <= 0) return;

    Employe emp;
    if (emp.supprimer(id_employe)) {
        ui->lineEdit_id_supp->clear();
        QSqlQueryModel *model = emp.afficher();
        afficherEmployes(model);
        delete model;
        afficherStatistiques();
    }
}

void MainWindow::rechercherEmploye() {
    QString critere = ui->lineEdit_recherche->text();

    if (critere.isEmpty()) {
        Employe emp;
        QSqlQueryModel *model = emp.afficher();
        afficherEmployes(model);
        delete model;
        return;
    }

    Employe emp;
    QSqlQueryModel *model = emp.rechercher(critere);
    afficherEmployes(model);
    delete model;
}

void MainWindow::afficherEmployes(QSqlQueryModel *model) {
    ui->tableWidgetEmployes->setRowCount(0);

    if (!model) return;

    for (int i = 0; i < model->rowCount(); ++i) {
        ui->tableWidgetEmployes->insertRow(i);
        for (int j = 0; j < 5 && j < model->columnCount(); ++j) {
            QVariant data = model->data(model->index(i, j));
            ui->tableWidgetEmployes->setItem(i, j, new QTableWidgetItem(data.toString()));
        }
    }
}

void MainWindow::trierParPoste() {
    Employe emp;
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT id_employe, nom, prenom, email, poste FROM employe ORDER BY poste");
    afficherEmployes(model);
    delete model;
}

void MainWindow::exportEmployes()
{
    QString fileName = QFileDialog::getSaveFileName(
        this,
        "Exporter en Excel",
        "employes.csv",
        "Fichiers CSV (*.csv);;Tous les fichiers (*.*)"
        );

    if (fileName.isEmpty()) return;

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Erreur", "Impossible d'ouvrir le fichier.");
        return;
    }

    QTextStream out(&file);

    // ----- ENCODAGE UTF-8 + BOM -----
    out.setEncoding(QStringConverter::Utf8);
    out << QChar(0xFEFF);  // BOM pour Excel

    // En-têtes
    out << "\"ID\";\"Nom\";\"Prénom\";\"Email\";\"Poste\"\n";

    QSqlQuery query;
    query.prepare("SELECT id_employe, nom, prenom, email, poste FROM employe");

    if (!query.exec()) {
        QMessageBox::warning(this, "Erreur", "Impossible d'exécuter la requête d'export.");
        return;
    }

    // Lignes
    while (query.next()) {
        out << "\"" << query.value(0).toString() << "\";"
            << "\"" << query.value(1).toString() << "\";"
            << "\"" << query.value(2).toString() << "\";"
            << "\"" << query.value(3).toString() << "\";"
            << "\"" << query.value(4).toString() << "\"\n";
    }

    file.close();
    QMessageBox::information(this, "Succès", "Liste exportée avec succès !");
}



void MainWindow::afficherStatistiques()
{
    QSqlQuery query;
    if (!query.exec("SELECT poste, COUNT(*) as count FROM employe GROUP BY poste")) return;

    QMap<QString, int> statsPoste;
    while (query.next()) {
        QString poste = query.value(0).toString();
        int count = query.value(1).toInt();
        if (!poste.isEmpty()) {
            statsPoste[poste] += count;
        }
    }

    if (statsPoste.isEmpty()) return;

    if (ui->statistiques->layout()) {
        QLayout *oldLayout = ui->statistiques->layout();
        QLayoutItem *item;
        while ((item = oldLayout->takeAt(0)) != nullptr) {
            delete item->widget();
            delete item;
        }
        delete oldLayout;
    }

    QPieSeries *series = new QPieSeries();
    QList<QColor> palette = {
        QColor("#FF7F32"), // orange vif
        QColor("#FFD966"), // jaune pâle tirant sur l'orange
        QColor("#FFA500"), // orange moyen classique
        QColor("#1A237E"), // bleu foncé
        QColor("#512DA8"), // violet foncé
        QColor("#7E57C2"), // mauve
        QColor("#3949AB"), // bleu moyen foncé
        QColor("#FFC266"), // jaune/orangé clair
        QColor("#FF8C42"), // orange moyen soutenu
        QColor("#FFB366"), // orange clair
        QColor("#673AB7"), // violet moyen
        QColor("#9575CD"), // mauve clair
        QColor("#4527A0"), // violet profond
        QColor("#303F9F"), // bleu indigo
        QColor("#283593"), // bleu foncé
        QColor("#5C6BC0"), // bleu-violet
        QColor("#7B1FA2")  // violet profond
    };


    QList<QPair<QString, QColor>> legendItems;
    int colorIndex = 0;
    for (auto it = statsPoste.begin(); it != statsPoste.end(); ++it) {
        QPieSlice *slice = series->append(it.key(), it.value());
        QColor color = palette[colorIndex % palette.size()];
        slice->setPen(QPen(Qt::white, 1));
        slice->setBrush(color);
        legendItems.append(qMakePair(it.key(), color));
        colorIndex++;
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setAnimationOptions(QChart::SeriesAnimations);
    chart->legend()->setVisible(false);

    for (QPieSlice *slice : series->slices()) {
        slice->setLabel(QString("%1%").arg(qRound(slice->percentage() * 100)));
        slice->setLabelVisible(true);
        slice->setLabelPosition(QPieSlice::LabelOutside);
    }

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumSize(400, 300);

    QLabel *titleLabel = new QLabel("Répartition des employés par poste");
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setStyleSheet("font-weight: bold; font-size: 14px;");

    QString legendHtml;
    for (const auto &item : legendItems) {
        if (!legendHtml.isEmpty()) legendHtml += " &nbsp;&nbsp; ";
        legendHtml += QString("<span style='color:%1; font-size: 16px;'>■</span> %2").arg(item.second.name(), item.first);
    }
    QLabel *legendLabel = new QLabel(legendHtml);
    legendLabel->setAlignment(Qt::AlignCenter);

    QVBoxLayout *layout = new QVBoxLayout(ui->statistiques);
    layout->addWidget(titleLabel);
    layout->addWidget(legendLabel);
    layout->addWidget(chartView);
    ui->statistiques->setLayout(layout);
}

// login
void MainWindow::login() {
    QString email = ui->lineEdit_email_login->text();
    QString mdp = ui->lineEdit_mdp_login->text();

    Employe emp;

    if(!emp.chargerParEmail(email)) {
        QMessageBox::warning(this, "Erreur", "Email incorrect.");
        return;
    }

    if(emp.getMdp() != mdp) {
        QMessageBox::warning(this, "Erreur", "Mot de passe incorrect.");
        return;
    }

    employeConnecte = emp;

    ui->stackedWidget_principale->setCurrentWidget(ui->page_2);


    redirigerSelonDroits();


}


void MainWindow::ouvrirPageMdpOublie() {
    QString email = ui->lineEdit_email_login->text().trimmed();

    // Chercher l'employé qui correspond à l'email
    if(!employeRecup.chargerParEmail(email)) {
        QMessageBox::warning(this, "Erreur", "Email introuvable.");
        return;
    }

    // Remise à zéro des tentatives
    tentative_mdp_oublie = 0;



    ui->label_question_secrete->setText(
        "<span style='font-weight:bold; color:#55007f;'>" +
        employeRecup.getQuestionSecrete() +
        "</span>"
        );

    ui->stackedWidget_login->setCurrentWidget(ui->page_mdp_oublie);
}


void MainWindow::verifierReponseSecrete() {

    if(ui->lineEdit_reponse_2->text() != employeRecup.getReponseSecrete()) {

        tentative_mdp_oublie++;

        if(tentative_mdp_oublie >= 3) {
            QMessageBox::critical(this, "Erreur", "3 réponses incorrectes. Retour au login.");
            ui->stackedWidget_login->setCurrentWidget(ui->page_login);
            return;
        }

        QMessageBox::warning(this, "Erreur", "Réponse incorrecte.");
        return;
    }

    ui->stackedWidget_login->setCurrentWidget(ui->page_nouveau_mdp);
}

void MainWindow::validerNouveauMdp() {
    QString nouveauMdp = ui->lineEdit_nouveau_mdp->text();

    if(nouveauMdp.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Mot de passe vide.");
        return;
    }

    if(employeRecup.mettreAJourMdp(nouveauMdp)) {
        QMessageBox::information(this, "Succès", "Mot de passe mis à jour !");
        ui->stackedWidget_login->setCurrentWidget(ui->page_login);
    } else {
        QMessageBox::critical(this, "Erreur", "Impossible de mettre à jour le mot de passe.");
    }
}
//gestion des droits d'acces
bool MainWindow::accesAutorise(QString page) {

    QString poste = employeConnecte.getPoste();

    if(page == "employe")
        return (poste == "Responsable RH" || poste == "Assistante RH");

    if(page == "projet")
        return (poste == "Chef de projet" || poste=="Créateur" || poste == "Responsable Marketing Digital");

    if(page == "client")
        return (poste == "Commercial" || poste == "Chef de projet");

    if(page == "media")
        return (poste == "Graphiste" || poste == "Web Designer" ||  poste == "Créateur"
                || poste == "Chef de projet" || poste == "Illustrateur" || poste == "Vidéaste" || poste == "Monteur vidéo");

    if(page == "campagne")
        return (poste == "Community Manager" ||  poste=="Technicien lumière & plateau" || poste == "Vidéaste" || poste == "Chef de projet"
                || poste == "Copywriter" || poste == "Responsable Marketing Digital");

    if(page == "sponsor")
        return (poste == "Responsable financier" || poste == "Comptable"|| poste == "Chef de projet" || poste == "Social Media Manager");

    return false;
}

void MainWindow::ouvrirPageEmploye() {
    if(!accesAutorise("employe")) {
        QMessageBox::warning(this, "Accès refusé", "Vous n'avez pas accès à la page Employe.");
        return;
    }

    ui->stackedWidget->setCurrentWidget(ui->page_employe);
    setActiveButton(ui->pushButton_employe);
}

void MainWindow::ouvrirPageProjet() {
    if(!accesAutorise("projet")) {
        QMessageBox::warning(this, "Accès refusé", "Vous n'avez pas accès à la page Projet.");
        return;
    }

    ui->stackedWidget->setCurrentWidget(ui->page_projet);
    setActiveButton(ui->pushButton_projet);
}

void MainWindow::ouvrirPageClient() {
    if(!accesAutorise("client")) {
        QMessageBox::warning(this, "Accès refusé", "Vous n'avez pas accès à la page Client.");
        return;
    }

    ui->stackedWidget->setCurrentWidget(ui->page_client);
    setActiveButton(ui->pushButton_client);
}

void MainWindow::ouvrirPageMedia() {
    if(!accesAutorise("media")) {
        QMessageBox::warning(this, "Accès refusé", "Vous n'avez pas accès à la page Ressources.");
        return;
    }

    ui->stackedWidget->setCurrentWidget(ui->page_media);
    setActiveButton(ui->pushButton_media);
}

void MainWindow::ouvrirPageFeedback() {
    if(!accesAutorise("campagne")) {
        QMessageBox::warning(this, "Accès refusé", "Vous n'avez pas accès à la page Campagne.");
        return;
    }

    ui->stackedWidget->setCurrentWidget(ui->page_feedback);
    setActiveButton(ui->pushButton_feedback);
}

void MainWindow::ouvrirPageCategorie() {
    if(!accesAutorise("sponsor")) {
        QMessageBox::warning(this, "Accès refusé", "Vous n'avez pas accès à la page Sponsor.");
        return;
    }

    ui->stackedWidget->setCurrentWidget(ui->page_categorie);
    setActiveButton(ui->pushButton_categorie);
}

void MainWindow::redirigerSelonDroits()
{
    // Ordre des pages que tu préfères afficher
    if (accesAutorise("employe")) {
        ouvrirPageEmploye();
        return;
    }

    if (accesAutorise("projet")) {
        ouvrirPageProjet();
        return;
    }

    if (accesAutorise("client")) {
        ouvrirPageClient();
        return;
    }

    if (accesAutorise("media")) {
        ouvrirPageMedia();
        return;
    }

    if (accesAutorise("campagne")) {
        ouvrirPageFeedback();
        return;
    }

    if (accesAutorise("sponsor")) {
        ouvrirPageCategorie();
        return;
    }

    QMessageBox::critical(this, "Erreur", "Aucune page autorisée pour cet employé !");
}



// Gestion Clients
void MainWindow::refreshClientTable()
{
    Client c;
    QSqlQueryModel *model = c.afficher();
    ui->tableClients_6->setRowCount(0);
    ui->tableClients_6->setColumnCount(8);

    QStringList headers = {"Activité", "ID", "Nom", "Email", "Téléphone", "Secteur d'activité", "Pays", "Date d'inscription"};
    ui->tableClients_6->setHorizontalHeaderLabels(headers);

    QDate today = QDate::currentDate();

    for (int i = 0; i < model->rowCount(); i++) {
        ui->tableClients_6->insertRow(i);

        QDate dateInscription = model->data(model->index(i, 6)).toDate();
        bool inactif = (dateInscription.daysTo(today) > 30);

        QWidget *cellWidget = new QWidget();
        QHBoxLayout *layout = new QHBoxLayout(cellWidget);
        layout->setContentsMargins(0, 0, 0, 0);
        layout->setAlignment(Qt::AlignCenter);

        QLabel *bubble = new QLabel();
        bubble->setFixedSize(14, 14);
        bubble->setStyleSheet(QString("border-radius:7px; background-color:%1;").arg(inactif ? "#E53935" : "#43A047"));
        layout->addWidget(bubble);
        ui->tableClients_6->setCellWidget(i, 0, cellWidget);

        for (int j = 0; j < model->columnCount(); j++) {
            QVariant data = model->data(model->index(i, j));
            QString value;
            if (data.typeId() == QMetaType::QDate || data.typeId() == QMetaType::QDateTime)
                value = data.toDate().toString("yyyy-MM-dd");
            else
                value = data.toString();
            ui->tableClients_6->setItem(i, j + 1, new QTableWidgetItem(value));
        }
    }

    ui->tableClients_6->resizeColumnsToContents();
    ui->tableClients_6->horizontalHeader()->setStretchLastSection(true);
}

void MainWindow::on_tableClients_6_cellClicked(int row, int column)
{
    Q_UNUSED(column);
    ui->leId_6->setText(ui->tableClients_6->item(row, 1)->text());
    ui->leNom_6->setText(ui->tableClients_6->item(row, 2)->text());
    ui->leEmail_6->setText(ui->tableClients_6->item(row, 3)->text());
    ui->leTel_6->setText(ui->tableClients_6->item(row, 4)->text());
    ui->cbSecteur_6->setCurrentText(ui->tableClients_6->item(row, 5)->text());
    ui->cbPays_6->setCurrentText(ui->tableClients_6->item(row, 6)->text());
    ui->deDate_6->setDate(QDate::fromString(ui->tableClients_6->item(row, 7)->text(), "yyyy-MM-dd"));
}

void MainWindow::on_btnAjouter_3_clicked()
{
    QString idStr = ui->leId_6->text().trimmed();
    QString nom = ui->leNom_6->text().trimmed();
    QString email = ui->leEmail_6->text().trimmed();
    QString tel = ui->leTel_6->text().trimmed();
    QString secteur = ui->cbSecteur_6->currentText();
    QString pays = ui->cbPays_6->currentText();
    QDate dateInscription = ui->deDate_6->date();

    QRegularExpression regexId("^[0-9]{8}$");
    QRegularExpression regexTel("^[0-9]{8}$");
    QRegularExpression regexNom("^[A-Za-zÀ-ÖØ-öø-ÿ\\s]+$");
    QRegularExpression regexEmail("^[\\w._%+-]+@[\\w.-]+\\.[A-Za-z]{2,}$");

    if (!regexId.match(idStr).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "L'ID doit contenir exactement 8 chiffres.");
        return;
    }
    if (!regexNom.match(nom).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Le nom/prénom ne doit contenir que des lettres et espaces.");
        return;
    }
    if (!regexEmail.match(email).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Veuillez saisir une adresse e-mail valide.");
        return;
    }
    if (!regexTel.match(tel).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Le numéro de téléphone doit contenir exactement 8 chiffres.");
        return;
    }

    int id = idStr.toInt();
    QSqlQuery check;
    check.prepare("SELECT COUNT(*) FROM CLIENTT WHERE LOWER(NOM)=LOWER(:nom) OR LOWER(EMAIL)=LOWER(:email) OR TELEPHONE=:tel");
    check.bindValue(":nom", nom);
    check.bindValue(":email", email);
    check.bindValue(":tel", tel);
    if (!check.exec()) {
        QMessageBox::critical(this, "Erreur SQL", check.lastError().text());
        return;
    }
    check.next();
    if (check.value(0).toInt() > 0) {
        QMessageBox::warning(this, "Doublon détecté", "Ce client existe déjà.");
        return;
    }

    Client c(id, nom, email, tel, secteur, pays, dateInscription);
    if (c.ajouter()) {
        QMessageBox::information(this, "Succès", "Client ajouté avec succès !");
        refreshClientTable();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout du client !");
    }
}

void MainWindow::on_btnModifier_3_clicked()
{
    QString idStr = ui->leId_6->text().trimmed();
    QString nom = ui->leNom_6->text().trimmed();
    QString email = ui->leEmail_6->text().trimmed();
    QString tel = ui->leTel_6->text().trimmed();
    QString secteur = ui->cbSecteur_6->currentText();
    QString pays = ui->cbPays_6->currentText();
    QDate dateInscription = ui->deDate_6->date();

    QRegularExpression regexId("^[0-9]{8}$");
    QRegularExpression regexTel("^[0-9]{8}$");
    QRegularExpression regexNom("^[A-Za-zÀ-ÖØ-öø-ÿ\\s]+$");
    QRegularExpression regexEmail("^[\\w._%+-]+@[\\w.-]+\\.[A-Za-z]{2,}$");

    if (!regexId.match(idStr).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "L'ID doit contenir exactement 8 chiffres.");
        return;
    }
    if (!regexNom.match(nom).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Le nom/prénom ne doit contenir que des lettres et espaces.");
        return;
    }
    if (!regexEmail.match(email).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Veuillez saisir une adresse e-mail valide.");
        return;
    }
    if (!regexTel.match(tel).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Le numéro de téléphone doit contenir exactement 8 chiffres.");
        return;
    }

    int id = idStr.toInt();
    QSqlQuery check;
    check.prepare("SELECT COUNT(*) FROM CLIENTT WHERE (LOWER(NOM)=LOWER(:nom) OR LOWER(EMAIL)=LOWER(:email) OR TELEPHONE=:tel) AND IDCLIENT!=:id");
    check.bindValue(":nom", nom);
    check.bindValue(":email", email);
    check.bindValue(":tel", tel);
    check.bindValue(":id", id);
    if (!check.exec()) {
        QMessageBox::critical(this, "Erreur SQL", check.lastError().text());
        return;
    }
    check.next();
    if (check.value(0).toInt() > 0) {
        QMessageBox::warning(this, "Doublon détecté", "Un autre client avec ces informations existe déjà !");
        return;
    }

    Client c(id, nom, email, tel, secteur, pays, dateInscription);
    if (c.modifier()) {
        QMessageBox::information(this, "Succès", "Client modifié avec succès !");
        refreshClientTable();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la modification du client !");
    }
}

void MainWindow::on_btnSupprimer_3_clicked()
{
    if (ui->leId_6->text().isEmpty()) {
        QMessageBox::warning(this, "Attention", "Renseigne un ID valide à supprimer.");
        return;
    }

    int id = ui->leId_6->text().toInt();
    Client c;

    if (c.supprimer(id)) {
        QMessageBox::information(this, "Succès", "Client supprimé avec succès !");
        refreshClientTable();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la suppression du client !");
    }
}

void MainWindow::on_leSearch_6_textChanged(const QString &text)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM CLIENTT WHERE LOWER(SECTEURACTIVITE) LIKE LOWER(:rech) ORDER BY IDCLIENT ASC");
    query.bindValue(":rech", "%" + text + "%");
    if (!query.exec()) return;

    ui->tableClients_6->setRowCount(0);
    int row = 0;

    while (query.next()) {
        ui->tableClients_6->insertRow(row);
        for (int col = 0; col < 7; col++) {
            QVariant data = query.value(col);
            QString value = (data.typeId() == QMetaType::QDate || data.typeId() == QMetaType::QDateTime)
                                ? data.toDate().toString("yyyy-MM-dd")
                                : data.toString();
            ui->tableClients_6->setItem(row, col + 1, new QTableWidgetItem(value));
        }
        row++;
    }

    ui->tableClients_6->resizeColumnsToContents();
    ui->tableClients_6->horizontalHeader()->setStretchLastSection(true);
}

void MainWindow::on_pushButton_7_clicked()
{
    QString filePath = QFileDialog::getSaveFileName(this, "Exporter les clients", "", "Fichiers CSV (*.csv)");
    if (filePath.isEmpty()) return;

    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Erreur", "Impossible d'ouvrir le fichier.");
        return;
    }

    QTextStream out(&file);
    out << "ID;Nom;Email;Téléphone;Secteur;Pays;Date d'inscription\n";

    int rowCount = ui->tableClients_6->rowCount();
    int colCount = ui->tableClients_6->columnCount();

    for (int i = 0; i < rowCount; ++i) {
        QStringList rowData;
        for (int j = 1; j < colCount; ++j)
            rowData << (ui->tableClients_6->item(i, j) ? ui->tableClients_6->item(i, j)->text() : "");
        out << rowData.join(";") << "\n";
    }

    file.close();
    QMessageBox::information(this, "Succès", "Exportation terminée avec succès !");
}

void MainWindow::on_pushButton_9_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM CLIENTT ORDER BY DATEINSCRIPTION ASC");

    ui->tableClients_6->setRowCount(0);
    ui->tableClients_6->setColumnCount(8);
    QStringList headers = {"Activité", "ID", "Nom", "Email", "Téléphone", "Secteur d'activité", "Pays", "Date d'inscription"};
    ui->tableClients_6->setHorizontalHeaderLabels(headers);

    QDate today = QDate::currentDate();

    for (int i = 0; i < model->rowCount(); i++) {
        ui->tableClients_6->insertRow(i);

        QDate dateInscription = model->data(model->index(i, 6)).toDate();
        bool inactif = (dateInscription.daysTo(today) > 30);

        QWidget *cellWidget = new QWidget();
        QHBoxLayout *layout = new QHBoxLayout(cellWidget);
        layout->setContentsMargins(0, 0, 0, 0);
        layout->setAlignment(Qt::AlignCenter);

        QLabel *bubble = new QLabel();
        bubble->setFixedSize(14, 14);
        bubble->setStyleSheet(QString("border-radius:7px; background-color:%1;").arg(inactif ? "#E53935" : "#43A047"));
        layout->addWidget(bubble);
        ui->tableClients_6->setCellWidget(i, 0, cellWidget);

        for (int j = 0; j < model->columnCount(); j++) {
            QVariant data = model->data(model->index(i, j));
            QString value = (data.typeId() == QMetaType::QDate || data.typeId() == QMetaType::QDateTime)
                                ? data.toDate().toString("yyyy-MM-dd")
                                : data.toString();
            ui->tableClients_6->setItem(i, j + 1, new QTableWidgetItem(value));
        }
    }

    ui->tableClients_6->resizeColumnsToContents();
    ui->tableClients_6->horizontalHeader()->setStretchLastSection(true);

    QMessageBox::information(this, "Tri effectué", "✅ Le tableau a été trié par date d'inscription (ordre croissant).");
}

void MainWindow::on_pushButton_8_clicked()
{
    QSqlQuery query;
    query.prepare(R"(
        SELECT TO_CHAR(DATEINSCRIPTION, 'MM') AS mois, COUNT(*) AS total
        FROM CLIENTT
        GROUP BY TO_CHAR(DATEINSCRIPTION, 'MM')
        ORDER BY mois
    )");
    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur SQL", query.lastError().text());
        return;
    }

    QBarSet *setNouveaux = new QBarSet("Nouveaux clients");
    QBarSet *setAnciens = new QBarSet("Anciens clients (> 30 jours)");
    setNouveaux->setColor(QColor("#6A0DAD"));
    setAnciens->setColor(QColor("#FB8C00"));

    QStringList categories;
    QVector<int> dataNouveaux(12, 0), dataAnciens(12, 0);
    QDate today = QDate::currentDate();

    while (query.next()) {
        int mois = query.value("mois").toInt();
        int total = query.value("total").toInt();

        QSqlQuery subQuery;
        subQuery.prepare(R"(
            SELECT COUNT(*) FROM CLIENTT
            WHERE TO_CHAR(DATEINSCRIPTION, 'MM') = :mois
            AND (TRUNC(:today - DATEINSCRIPTION) > 30)
        )");
        subQuery.bindValue(":mois", mois);
        subQuery.bindValue(":today", today);
        subQuery.exec();
        subQuery.next();
        int anciens = subQuery.value(0).toInt();

        int nouveaux = total - anciens;
        dataNouveaux[mois - 1] = nouveaux;
        dataAnciens[mois - 1] = anciens;
    }

    for (int i = 0; i < 12; ++i) categories << QLocale::system().monthName(i + 1);

    *setNouveaux << dataNouveaux[0] << dataNouveaux[1] << dataNouveaux[2] << dataNouveaux[3]
                 << dataNouveaux[4] << dataNouveaux[5] << dataNouveaux[6] << dataNouveaux[7]
                 << dataNouveaux[8] << dataNouveaux[9] << dataNouveaux[10] << dataNouveaux[11];

    *setAnciens << dataAnciens[0] << dataAnciens[1] << dataAnciens[2] << dataAnciens[3]
                << dataAnciens[4] << dataAnciens[5] << dataAnciens[6] << dataAnciens[7]
                << dataAnciens[8] << dataAnciens[9] << dataAnciens[10] << dataAnciens[11];

    QBarSeries *series = new QBarSeries();
    series->append(setNouveaux);
    series->append(setAnciens);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("📊 Répartition des clients (nouveaux vs anciens)");
    chart->setAnimationOptions(QChart::SeriesAnimations);
    chart->setBackgroundBrush(QBrush(QColor("#EDEAF9")));
    chart->setTitleBrush(QBrush(QColor("#14172D")));
    chart->setTitleFont(QFont("Segoe UI", 10, QFont::Bold));

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    axisX->setLabelsColor(QColor("#14172D"));
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText("Nombre de clients");
    axisY->setLabelsColor(QColor("#14172D"));
    axisY->setTitleBrush(QBrush(QColor("#14172D")));
    axisY->setLabelFormat("%d");
    axisY->setTickType(QValueAxis::TicksDynamic);
    axisY->setMinorTickCount(0);
    axisY->setTickInterval(1.0);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignTop);
    chart->legend()->setLabelColor(QColor("#14172D"));
    chart->legend()->setFont(QFont("Segoe UI", 9));
    chart->legend()->setBackgroundVisible(false);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setStyleSheet("background-color: #EDEAF9; border-radius: 10px;");

    QDialog *dialog = new QDialog(this);
    dialog->setWindowTitle("Statistiques des Clients");
    dialog->resize(900, 600);

    QVBoxLayout *layout = new QVBoxLayout(dialog);
    layout->addWidget(chartView);
    dialog->setLayout(layout);
    dialog->exec();
}



// Gestion Projets
void MainWindow::setupProjetTable()
{
    ui->tableWidgetProjets->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidgetProjets->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidgetProjets->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidgetProjets->horizontalHeader()->setStretchLastSection(true);

    ui->tableWidgetProjets->setColumnCount(5);
    QStringList headers;
    headers << "Client" << "Budget Prévu" << "Budget Réalisé" << "Date Début" << "Date Fin";
    ui->tableWidgetProjets->setHorizontalHeaderLabels(headers);
}

void MainWindow::refreshProjetTable()
{
    ui->tableWidgetProjets->setRowCount(0);

    Projet projetModel;
    QSqlQueryModel* model = projetModel.afficher();

    for (int row = 0; row < model->rowCount(); ++row) {
        ui->tableWidgetProjets->insertRow(row);
        for (int col = 0; col < model->columnCount(); ++col) {
            QTableWidgetItem *item = new QTableWidgetItem(model->data(model->index(row, col)).toString());
            ui->tableWidgetProjets->setItem(row, col, item);
        }
    }

    ui->tableWidgetProjets->resizeColumnsToContents();
    delete model;
}

void MainWindow::on_btnAjouterProjet_clicked()
{
    if (isModifyingProjet) {
        // Mode modification - sauvegarder les modifications
        if (currentModifyClient.isEmpty()) {
            QMessageBox::warning(this, "Erreur", "Aucun projet sélectionné pour modification.");
            return;
        }

        QString nouveauClientStr = ui->lineEditClientProjet->text().trimmed();
        QString nouveauBudgetPrevuStr = ui->lineEditBudgetPrevu->text().trimmed();
        QString nouveauBudgetRealiseStr = ui->lineEditBudgetRealise->text().trimmed();
        QString nouvelleDateDebutStr = ui->dateEditDebut->text().trimmed();
        QString nouvelleDateFinStr = ui->dateEditFin->text().trimmed();

        if (nouveauClientStr.isEmpty()) {
            QMessageBox::warning(this, "Erreur", "Le nom du client est obligatoire !");
            ui->lineEditClientProjet->setFocus();
            return;
        }

        bool okPrevu, okRealise;
        double nouveauBudgetPrevu = nouveauBudgetPrevuStr.toDouble(&okPrevu);
        double nouveauBudgetRealise = nouveauBudgetRealiseStr.toDouble(&okRealise);

        if (!nouveauBudgetPrevuStr.isEmpty() && !okPrevu) {
            QMessageBox::warning(this, "Erreur", "Budget prévu invalide !");
            ui->lineEditBudgetPrevu->setFocus();
            return;
        }

        if (!nouveauBudgetRealiseStr.isEmpty() && !okRealise) {
            QMessageBox::warning(this, "Erreur", "Budget réalisé invalide !");
            ui->lineEditBudgetRealise->setFocus();
            return;
        }

        QDate nouvelleDateDebut = QDate::fromString(nouvelleDateDebutStr, "dd/MM/yyyy");
        QDate nouvelleDateFin = QDate::fromString(nouvelleDateFinStr, "dd/MM/yyyy");

        if (!nouvelleDateDebutStr.isEmpty() && !nouvelleDateDebut.isValid()) {
            QMessageBox::warning(this, "Erreur", "Format de date début invalide !");
            ui->dateEditDebut->setFocus();
            return;
        }

        if (!nouvelleDateFinStr.isEmpty() && !nouvelleDateFin.isValid()) {
            QMessageBox::warning(this, "Erreur", "Format de date fin invalide !");
            ui->dateEditFin->setFocus();
            return;
        }

        if (nouvelleDateDebut.isValid() && nouvelleDateFin.isValid() && nouvelleDateFin < nouvelleDateDebut) {
            QMessageBox::warning(this, "Erreur", "La date de fin doit être après la date de début !");
            ui->dateEditFin->setFocus();
            return;
        }

        nouveauBudgetPrevu = nouveauBudgetPrevuStr.isEmpty() ? 0.0 : nouveauBudgetPrevu;
        nouveauBudgetRealise = nouveauBudgetRealiseStr.isEmpty() ? 0.0 : nouveauBudgetRealise;

        QString nouvelleDateDebutFormatted = nouvelleDateDebutStr.isEmpty() ? "N/A" : nouvelleDateDebutStr;
        QString nouvelleDateFinFormatted = nouvelleDateFinStr.isEmpty() ? "N/A" : nouvelleDateFinStr;

        Projet projetModifie(nouveauClientStr, nouveauBudgetPrevu, nouveauBudgetRealise, nouvelleDateDebutFormatted, nouvelleDateFinFormatted);

        if (projetModifie.modifier(currentModifyClient)) {
            refreshProjetTable();
            on_btnAnnulerModifProjet_clicked();
            QMessageBox::information(this, "Succès", "Projet modifié avec succès !");
        } else {
            QMessageBox::critical(this, "Erreur", "Erreur lors de la modification du projet !");
        }
        return;
    }

    // Mode ajout normal
    QString clientStr = ui->lineEditClientProjet->text().trimmed();
    QString budgetPrevuStr = ui->lineEditBudgetPrevu->text().trimmed();
    QString budgetRealiseStr = ui->lineEditBudgetRealise->text().trimmed();
    QString dateDebutStr = ui->dateEditDebut->text().trimmed();
    QString dateFinStr = ui->dateEditFin->text().trimmed();

    if (clientStr.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Le nom du client est obligatoire !");
        ui->lineEditClientProjet->setFocus();
        return;
    }

    bool okPrevu, okRealise;
    double budgetPrevu = budgetPrevuStr.toDouble(&okPrevu);
    double budgetRealise = budgetRealiseStr.toDouble(&okRealise);

    if (!budgetPrevuStr.isEmpty() && !okPrevu) {
        QMessageBox::warning(this, "Erreur", "Budget prévu invalide !");
        ui->lineEditBudgetPrevu->setFocus();
        return;
    }

    if (!budgetRealiseStr.isEmpty() && !okRealise) {
        QMessageBox::warning(this, "Erreur", "Budget réalisé invalide !");
        ui->lineEditBudgetRealise->setFocus();
        return;
    }

    QDate dateDebut = QDate::fromString(dateDebutStr, "dd/MM/yyyy");
    QDate dateFin = QDate::fromString(dateFinStr, "dd/MM/yyyy");

    if (!dateDebutStr.isEmpty() && !dateDebut.isValid()) {
        QMessageBox::warning(this, "Erreur", "Format de date début invalide !");
        ui->dateEditDebut->setFocus();
        return;
    }

    if (!dateFinStr.isEmpty() && !dateFin.isValid()) {
        QMessageBox::warning(this, "Erreur", "Format de date fin invalide !");
        ui->dateEditFin->setFocus();
        return;
    }

    if (dateDebut.isValid() && dateFin.isValid() && dateFin < dateDebut) {
        QMessageBox::warning(this, "Erreur", "La date de fin doit être après la date de début !");
        ui->dateEditFin->setFocus();
        return;
    }

    budgetPrevu = budgetPrevuStr.isEmpty() ? 0.0 : budgetPrevu;
    budgetRealise = budgetRealiseStr.isEmpty() ? 0.0 : budgetRealise;

    QString dateDebutFormatted = dateDebutStr.isEmpty() ? "N/A" : dateDebutStr;
    QString dateFinFormatted = dateFinStr.isEmpty() ? "N/A" : dateFinStr;

    Projet nouveauProjet(clientStr, budgetPrevu, budgetRealise, dateDebutFormatted, dateFinFormatted);

    if (nouveauProjet.ajouter()) {
        refreshProjetTable();
        ui->lineEditClientProjet->clear();
        ui->lineEditBudgetPrevu->clear();
        ui->lineEditBudgetRealise->clear();
        ui->dateEditDebut->clear();
        ui->dateEditFin->clear();
        QMessageBox::information(this, "Succès", "Projet ajouté avec succès !");
    } else {
        QMessageBox::critical(this, "Erreur", "Erreur lors de l'ajout du projet !");
    }
}

void MainWindow::on_btnModifierProjet_clicked()
{
    int currentRow = ui->tableWidgetProjets->currentRow();
    if (currentRow < 0) {
        QMessageBox::warning(this, "Modification", "Veuillez sélectionner un projet à modifier.");
        return;
    }

    currentModifyClient = ui->tableWidgetProjets->item(currentRow, 0)->text();
    QString budgetPrevuActuel = ui->tableWidgetProjets->item(currentRow, 1)->text();
    QString budgetRealiseActuel = ui->tableWidgetProjets->item(currentRow, 2)->text();
    QString dateDebutActuelle = ui->tableWidgetProjets->item(currentRow, 3)->text();
    QString dateFinActuelle = ui->tableWidgetProjets->item(currentRow, 4)->text();

    ui->lineEditClientProjet->setText(currentModifyClient);
    ui->lineEditBudgetPrevu->setText(budgetPrevuActuel);
    ui->lineEditBudgetRealise->setText(budgetRealiseActuel);
    ui->dateEditDebut->setText(dateDebutActuelle);
    ui->dateEditFin->setText(dateFinActuelle);

    isModifyingProjet = true;
    ui->btnAjouterProjet->setText("Confirmer Modification");
    ui->btnAnnulerModifProjet->setVisible(true);
    ui->btnModifierProjet->setEnabled(false);
    ui->btnSupprimerProjet->setEnabled(false);

    QMessageBox::information(this, "Modification", "Mode modification activé pour le client: " + currentModifyClient);
}

void MainWindow::on_btnAnnulerModifProjet_clicked()
{
    isModifyingProjet = false;
    currentModifyClient = "";

    ui->btnAjouterProjet->setText("Ajouter Projet");
    ui->btnAnnulerModifProjet->setVisible(false);
    ui->btnModifierProjet->setEnabled(true);
    ui->btnSupprimerProjet->setEnabled(true);

    ui->lineEditClientProjet->clear();
    ui->lineEditBudgetPrevu->clear();
    ui->lineEditBudgetRealise->clear();
    ui->dateEditDebut->clear();
    ui->dateEditFin->clear();
}

void MainWindow::on_btnSupprimerProjet_clicked()
{
    int currentRow = ui->tableWidgetProjets->currentRow();
    if (currentRow < 0) {
        QMessageBox::warning(this, "Suppression", "Veuillez sélectionner un projet à supprimer.");
        return;
    }

    QString clientProjet = ui->tableWidgetProjets->item(currentRow, 0)->text();

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmation", "Voulez-vous vraiment supprimer le projet du client : " + clientProjet + " ?", QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        Projet projetModel;
        bool success = projetModel.supprimer(clientProjet);

        if (success) {
            refreshProjetTable();
            QMessageBox::information(this, "Succès", "Projet supprimé avec succès !");
        } else {
            QMessageBox::critical(this, "Erreur", "Erreur lors de la suppression du projet !");
        }
    }
}

void MainWindow::on_btnTriBudgetProjet_clicked()
{
    ui->tableWidgetProjets->sortItems(1, Qt::DescendingOrder);
    QMessageBox::information(this, "Tri", "Projets triés par budget (décroissant) !");
}

void MainWindow::on_btnTriDateProjet_clicked()
{
    ui->tableWidgetProjets->sortItems(4, Qt::AscendingOrder);
    QMessageBox::information(this, "Tri", "Projets triés par date de fin (croissant) !");
}

void MainWindow::on_btnRafraichirProjet_clicked()
{
    refreshProjetTable();
    QMessageBox::information(this, "Rafraîchissement", "Données des projets rafraîchies !");
}

void MainWindow::on_tableProjets_cellClicked(int row, int column)
{
    Q_UNUSED(column);
    if (!isModifyingProjet) {
        ui->lineEditClientProjet->setText(ui->tableWidgetProjets->item(row, 0)->text());
        ui->lineEditBudgetPrevu->setText(ui->tableWidgetProjets->item(row, 1)->text());
        ui->lineEditBudgetRealise->setText(ui->tableWidgetProjets->item(row, 2)->text());
        ui->dateEditDebut->setText(ui->tableWidgetProjets->item(row, 3)->text());
        ui->dateEditFin->setText(ui->tableWidgetProjets->item(row, 4)->text());
    }
}

// =============================================================
// ====================== SPONSOR FUNCTIONS =====================
// =============================================================

void MainWindow::actualiserSponsorTable()
{
    QSqlQueryModel *model = tmpSponsor.afficher();
    proxySponsor->setSourceModel(model);
    ui->tableView_2->setModel(proxySponsor);
    ui->tableView_2->resizeColumnsToContents();
}

bool MainWindow::validateSponsorInputs()
{
    if (ui->lineEdit_nom_9->text().trimmed().isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Nom sponsor vide.");
        return false;
    }

    if (ui->comboBox_type_2->currentText().trimmed().isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Type sponsor invalide.");
        return false;
    }

    bool ok;
    double montant = ui->lineEdit_montant_2->text().toDouble(&ok);
    if (!ok || montant < 0) {
        QMessageBox::warning(this, "Erreur", "Montant invalide.");
        return false;
    }

    QRegularExpression rx(R"(\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,}\b)");
    if (!rx.match(ui->lineEdit_mail_2->text()).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Email invalide.");
        return false;
    }

    return true;
}

void MainWindow::clearSponsorFields()
{
    ui->lineEdit_nom_9->clear();
    ui->comboBox_type_2->setCurrentIndex(0);
    ui->lineEdit_montant_2->clear();
    ui->lineEdit_mail_2->clear();
    ui->dateEdit_fin_2->setDate(QDate::currentDate());
    ui->lineEdit_id_modify_2->clear();
    ui->lineEdit_id_delete_2->clear();
}

// ========================= AJOUT =============================

void MainWindow::on_ajouterButton_2_clicked()
{
    if (!validateSponsorInputs()) return;

    Sponsor s(
        ui->lineEdit_nom_9->text(),
        ui->comboBox_type_2->currentText(),
        ui->lineEdit_montant_2->text().toDouble(),
        ui->lineEdit_mail_2->text(),
        ui->dateEdit_fin_2->date()
        );

    if (s.ajouter()) {
        QMessageBox::information(this, "Succès", "Sponsor ajouté !");
        actualiserSponsorTable();
        clearSponsorFields();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec ajout sponsor.");
    }
}

// ========================= MODIFIER =============================

void MainWindow::on_modifierButton_2_clicked()
{
    bool ok;
    int id = ui->lineEdit_id_modify_2->text().toInt(&ok);
    if (!ok || id <= 0) {
        QMessageBox::warning(this, "Erreur", "ID invalide.");
        return;
    }

    if (!validateSponsorInputs()) return;

    Sponsor s(
        id,
        ui->lineEdit_nom_9->text(),
        ui->comboBox_type_2->currentText(),
        ui->lineEdit_montant_2->text().toDouble(),
        ui->lineEdit_mail_2->text(),
        ui->dateEdit_fin_2->date()
        );

    if (s.modifier()) {
        QMessageBox::information(this, "Succès", "Sponsor modifié.");
        actualiserSponsorTable();
    } else {
        QMessageBox::critical(this, "Erreur", "Aucune ligne modifiée.");
    }
}

// ========================= SUPPRIMER =============================

void MainWindow::on_supprimerButton_2_clicked()
{
    bool ok;
    int id = ui->lineEdit_id_delete_2->text().toInt(&ok);
    if (!ok || id <= 0) {
        QMessageBox::warning(this, "Erreur", "ID invalide.");
        return;
    }

    if (QMessageBox::question(this, "Confirmation",
                              "Voulez-vous supprimer ce sponsor ?")
        == QMessageBox::Yes)
    {
        if (tmpSponsor.supprimer(id)) {
            QMessageBox::information(this, "Succès", "Sponsor supprimé.");
            actualiserSponsorTable();
        } else {
            QMessageBox::critical(this, "Erreur", "Échec suppression.");
        }
    }
}

// ========================= SEARCH =============================

void MainWindow::on_lineEdit_searchGlobal_2_textChanged(const QString &term)
{
    proxySponsor->setFilterRegularExpression(
        QRegularExpression(term, QRegularExpression::CaseInsensitiveOption)
        );
}

// ========================= CLICK TABLE =============================

void MainWindow::on_tableView_2_clicked(const QModelIndex &index)
{
    QModelIndex src = proxySponsor->mapToSource(index);
    QAbstractItemModel *m = proxySponsor->sourceModel();

    int row = src.row();

    int id = m->data(m->index(row, 0)).toInt();
    QString nom = m->data(m->index(row, 1)).toString();
    QString type = m->data(m->index(row, 2)).toString();
    double montant = m->data(m->index(row, 3)).toDouble();
    QString mail = m->data(m->index(row, 4)).toString();
    QDate fin = m->data(m->index(row, 5)).toDate();

    ui->lineEdit_nom_9->setText(nom);
    ui->comboBox_type_2->setCurrentText(type);
    ui->lineEdit_montant_2->setText(QString::number(montant));
    ui->lineEdit_mail_2->setText(mail);
    ui->dateEdit_fin_2->setDate(fin);

    ui->lineEdit_id_modify_2->setText(QString::number(id));
    ui->lineEdit_id_delete_2->setText(QString::number(id));
}



////////////// ressourcess ///////////////
// -------------------- AJOUT --------------------
void MainWindow::on_AjoutBut2_clicked()
{
    int id = ui->lineNom->text().toInt();
    QString type;

    if (ui->Imagecheck->isChecked()) type = "Image";
    else if (ui->Videocheck->isChecked()) type = "Video";
    else if (ui->audiocheck->isChecked()) type = "Audio";
    else type = "Autre";

    QString nomProjet = ui->comboProj->currentText();
    QString nomFichier = ui->outputajout->text();

    Ressource r(id, type, nomProjet, nomFichier);
    if (r.ajouter()) {
        QMessageBox::information(this, "Ajout", "Ressource ajoutée avec succès ✅");
        ui->RessourceTab->setModel(R.afficher());
    } else {
        QMessageBox::critical(this, "Erreur", "Échec d'ajout ❌");
    }
}

// -------------------- SUPPRESSION --------------------
void MainWindow::on_RessourceTab_doubleClicked(const QModelIndex &index)
{
    int id = ui->RessourceTab->model()->data(ui->RessourceTab->model()->index(index.row(), 0)).toInt();
    if (QMessageBox::question(this, "Suppression", "Supprimer cette ressource ?") == QMessageBox::Yes)
    {
        R.supprimer(id);
        ui->RessourceTab->setModel(R.afficher());
    }
}

// -------------------- STATISTIQUES --------------------
void MainWindow::on_StatsBut_clicked()
{
    QSqlQueryModel *model = R.statistiques();
    QString stats;

    for (int i = 0; i < model->rowCount(); i++) {
        QString type = model->record(i).value("type").toString();
        int nombre = model->record(i).value("nombre").toInt();
        stats += type + " : " + QString::number(nombre) + "\n";
    }

    QMessageBox::information(this, "Statistiques 📊", stats);
}

// -------------------- EXPORT PDF --------------------
void MainWindow::on_PDFBut_clicked()
{
    QPdfWriter pdf("Ressources.pdf");
    QPainter painter(&pdf);

    painter.drawText(100, 100, "Liste des Ressources :");
    int y = 300;

    QSqlQuery query("SELECT * FROM ressources");
    while (query.next()) {
        QString line = query.value(0).toString() + " | " +
                       query.value(1).toString() + " | " +
                       query.value(2).toString() + " | " +
                       query.value(3).toString();
        painter.drawText(100, y, line);
        y += 200;
    }

    painter.end();
    QMessageBox::information(this, "PDF", "Fichier PDF généré avec succès ✅");
}

// -------------------- RECHERCHE --------------------
void MainWindow::on_RechercheRess_textChanged(const QString &text)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT * FROM ressources WHERE nomFichier LIKE :text OR type LIKE :text OR nomProjet LIKE :text");
    query.bindValue(":text", "%" + text + "%");
    query.exec();
    model->setQuery(std::move(query));
    ui->RessourceTab->setModel(model);
}

// -------------------- INTERFACE --------------------
void MainWindow::setUpInterface()
{
    ui->AjoutBut2->setVisible(false);
    ui->labelAjout->setVisible(false);
    ui->labelStat->setVisible(false);
    ui->lineNom->setVisible(false);
    ui->comboProj->setVisible(false);
    ui->label_nomm->setVisible(false);
    ui->label_stats->setVisible(false);
    ui->RetourneBut->setVisible(false);
    ui->label_4->setVisible(false);
    ui->ImpBut->setVisible(false);
    ui->label->setVisible(false);
    ui->outputajout->setVisible(false);
    ui->statReturnBut->setVisible(false);
}

void MainWindow::allerAjoutPage()
{
    ui->AjoutBut2->setVisible(true);
    ui->labelAjout->setVisible(true);
    ui->lineNom->setVisible(true);
    ui->comboProj->setVisible(true);
    ui->label_nomm->setVisible(true);
    ui->RetourneBut->setVisible(true);
    ui->label_4->setVisible(true);
    ui->ImpBut->setVisible(true);
    ui->label->setVisible(true);
    ui->outputajout->setVisible(true);
    ui->labelAffichage->setVisible(true);
}

void MainWindow::allerPageStats()
{
    ui->labelStat->setVisible(true);
    ui->label_stats->setVisible(true);
    ui->statReturnBut->setVisible(true);
}

// -------------------- IMPORT --------------------
void MainWindow::on_ImpBut_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(
        this,
        "Importer un fichier multimédia",
        "",
        "Fichiers multimédias (*.mp3 *.wav *.ogg *.mp4 *.avi *.mkv *.mov *.jpg *.jpeg *.png *.bmp *.gif)"
        );

    if (fileName.isEmpty())
        return;

    QFileInfo fileInfo(fileName);
    QString extension = fileInfo.suffix().toLower();

    // --- IMAGE ---
    if (extension == "png" || extension == "jpg" || extension == "jpeg" ||
        extension == "bmp" || extension == "gif")
    {
        QPixmap pixmap(fileName);
        if (!pixmap.isNull()) {
            ui->labelAffichage->setPixmap(
                pixmap.scaled(ui->labelAffichage->size(),
                              Qt::KeepAspectRatio,
                              Qt::SmoothTransformation)
                );
        } else {
            QMessageBox::warning(this, "Erreur", "Impossible de charger l’image.");
        }
    }
    // --- VIDÉO ---
    else if (extension == "mp4" || extension == "avi" ||
             extension == "mkv" || extension == "mov")
    {
        QVideoWidget *videoWidget = new QVideoWidget(this);
        QMediaPlayer *player = new QMediaPlayer(this);
        player->setVideoOutput(videoWidget);
        player->setSource(QUrl::fromLocalFile(fileName));

        videoWidget->setGeometry(ui->labelAffichage->geometry());
        videoWidget->show();
        player->play();
    }
    // --- AUDIO ---
    else if (extension == "mp3" || extension == "wav" || extension == "ogg")
    {
        QMediaPlayer *player = new QMediaPlayer(this);
        QAudioOutput *audioOutput = new QAudioOutput(this);

        player->setAudioOutput(audioOutput);
        player->setSource(QUrl::fromLocalFile(fileName));
        audioOutput->setVolume(0.5); // 50 %

        player->play();
        QMessageBox::information(this, "Lecture audio", "Lecture du fichier audio...");
    }
    else
    {
        QMessageBox::information(this, "Info", "Ce type de fichier n’est pas pris en charge.");
    }
}
