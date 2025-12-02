#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include "ressource.h"
#include "sponsor.h"
#include "projet.h"

#include <QDebug>
#include <QSqlRecord>
#include <QMessageBox>
#include <QDate>
#include <QTimer>
#include <QFileDialog>
#include <QTextStream>
#include <QPdfWriter>
#include <QPainter>
#include <QVBoxLayout>
#include <QLabel>
#include <QHBoxLayout>
#include <QFile>
#include <QRegularExpression>
#include <QComboBox>
#include <QTableWidgetItem>
#include <QPalette>
#include <QColor>
#include <QPixmap>
#include <QSortFilterProxyModel>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QAudioOutput>

// Charts
#include <QtCharts/QChartView>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QValueAxis>
#include <QtCharts/QChart>

Ressource R; // objet global temporaire

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , isModifyingProjet(false)
    , currentModifyIdClientProjet(0)
    , chatBotProjet(nullptr)  // Initialisé à nullptr
    , mapWindow(nullptr)      // Initialisé à nullptr
    , proxySponsor(nullptr)   // Initialisé à nullptr
    , tentative_mdp_oublie(0)
{
    ui->setupUi(this);

    //clients
    ui->stackedWidget->setCurrentIndex(0);
    refreshClientTable();
    mapWindow = new BubbleMapWindow();

    QTimer *timerRefresh = new QTimer(this);
    connect(timerRefresh, &QTimer::timeout,
            this, &MainWindow::refreshClientTable);
    timerRefresh->start(3000);
    //finclient

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
    currentModifyIdClientProjet = 0; // Utilisez la variable correcte
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
    // Note: Ces boutons doivent exister dans votre UI
    // Si ils n'existent pas, commentez ces lignes
    /*
    connect(ui->btnAjouterProjet, &QPushButton::clicked, this, &MainWindow::on_btnAjouterProjet_clicked);
    connect(ui->btnModifierProjet, &QPushButton::clicked, this, &MainWindow::on_btnModifierProjet_clicked);
    connect(ui->btnSupprimerProjet, &QPushButton::clicked, this, &MainWindow::on_btnSupprimerProjet_clicked);
    connect(ui->btnTriBudgetProjet, &QPushButton::clicked, this, &MainWindow::on_btnTriBudgetProjet_clicked);
    connect(ui->btnTriDateProjet, &QPushButton::clicked, this, &MainWindow::on_btnTriDateProjet_clicked);
    connect(ui->btnRafraichirProjet, &QPushButton::clicked, this, &MainWindow::on_btnRafraichirProjet_clicked);
    connect(ui->btnAnnulerModifProjet, &QPushButton::clicked, this, &MainWindow::on_btnAnnulerModifProjet_clicked);
    connect(ui->tableWidgetProjets, &QTableWidget::cellClicked, this, &MainWindow::on_tableProjets_cellClicked);

    ui->btnAnnulerModifProjet->setVisible(false);
    */
}

MainWindow::~MainWindow()
{
    delete ui;
    delete mapWindow;
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

void MainWindow::rechercherEmploye()
{
    QString critere = ui->lineEdit_recherche->text().trimmed();

    Employe emp;
    QSqlQueryModel *model = nullptr;

    // Si champ vide → afficher tout
    if (critere.isEmpty()) {
        model = emp.afficher();
    }
    else {
        model = emp.rechercher(critere);
    }

    afficherEmployes(model);

    delete model;  // éviter les fuites
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

void MainWindow::trierParPoste()
{
    Employe emp;
    QSqlQueryModel *model = emp.trierParPoste();
    afficherEmployes(model);
}


void MainWindow::exportEmployes()
{
    QString fileName = QFileDialog::getSaveFileName(this,"Exporter","employes.csv","CSV (*.csv)");
    if (fileName.isEmpty()) return;

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this,"Erreur","Impossible d'ouvrir le fichier.");
        return;
    }

    Employe emp;
    QSqlQueryModel *model = emp.getAllEmployes();

    QTextStream out(&file);
    out.setEncoding(QStringConverter::Utf8);
    out << QChar(0xFEFF);

    out << "\"ID\";\"Nom\";\"Prénom\";\"Email\";\"Poste\"\n";

    for (int i = 0; i < model->rowCount(); i++) {
        out << "\"" << model->record(i).value("id_employe").toString() << "\";"
            << "\"" << model->record(i).value("nom").toString()        << "\";"
            << "\"" << model->record(i).value("prenom").toString()     << "\";"
            << "\"" << model->record(i).value("email").toString()      << "\";"
            << "\"" << model->record(i).value("poste").toString()      << "\"\n";
    }

    file.close();
    QMessageBox::information(this,"Succès","Export terminé !");
}



void MainWindow::afficherStatistiques()
{
    Employe emp;
    QSqlQuery query = emp.getStatsParPoste();

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
        QColor("#FF7F32"), QColor("#FFD966"), QColor("#FFA500"),
        QColor("#1A237E"), QColor("#7E57C2"), QColor("#3949AB"),
        QColor("#FFC266"), QColor("#FFB366"), QColor("#9575CD"),
        QColor("#4527A0"), QColor("#303F9F"), QColor("#5C6BC0"),
        QColor("#7B1FA2")
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

    // --- Créer le graphique ---
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setAnimationOptions(QChart::SeriesAnimations);
    chart->legend()->setVisible(false);

    // Affichage des pourcentages
    for (QPieSlice *slice : series->slices()) {
        slice->setLabel(QString("%1%").arg(qRound(slice->percentage() * 100)));
        slice->setLabelVisible(true);
        slice->setLabelPosition(QPieSlice::LabelOutside);
    }

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumSize(400, 300);

    // --- Créer titre et légende personnalisée ---
    QLabel *titleLabel = new QLabel("Répartition des employés par poste");
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setStyleSheet("font-weight: bold; font-size: 14px;");

    QString legendHtml;
    for (const auto &item : legendItems) {
        if (!legendHtml.isEmpty()) legendHtml += " &nbsp;&nbsp; ";
        legendHtml += QString("<span style='color:%1; font-size: 16px;'>■</span> %2")
                          .arg(item.second.name(), item.first);
    }
    QLabel *legendLabel = new QLabel(legendHtml);
    legendLabel->setAlignment(Qt::AlignCenter);

    // --- Ajouter tout au layout ---
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


    // MODE DEVELOPPEUR (bypass)
    if (modeDev) {
        Employe dev;
        dev.setPoste("Admin");
        employeConnecte = dev;

        ui->stackedWidget_principale->setCurrentWidget(ui->page_2);
        redirigerSelonDroits();
        return;
    }

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

    if (modeDev) {
        ui->stackedWidget_login->setCurrentWidget(ui->page_nouveau_mdp);
        return;
    }

    QString email = ui->lineEdit_email_login->text().trimmed();

    // Chercher l'employé qui correspond à l'email
    if(!employeRecup.chargerParEmail(email)) {
        QMessageBox::warning(this, "Erreur", "Email introuvable.");
        return;
    }

    // Remise à zéro des tentatives
    tentative_mdp_oublie = 0;


    ui->label_question_secrete->setWordWrap(true);

    ui->label_question_secrete->setText(
        "<span style='font-weight:bold; color:#55007f;'>" +
        employeRecup.getQuestionSecrete() +
        "</span>"
        );

    ui->stackedWidget_login->setCurrentWidget(ui->page_mdp_oublie);
}


void MainWindow::verifierReponseSecrete() {

    if (modeDev) {
        ui->stackedWidget_login->setCurrentWidget(ui->page_nouveau_mdp);
        return;
    }

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

    if (modeDev) {
        ui->stackedWidget_login->setCurrentWidget(ui->page_login);
        return;
    }

    QString nouveauMdp = ui->lineEdit_nouveau_mdp->text();

    if(nouveauMdp.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Mot de passe vide.");
        return;
    }

    QRegularExpression mdpRegex("^(?=.*[A-Za-z])(?=.*\\d)[A-Za-z\\d]{8,}$");
    if (!mdpRegex.match(nouveauMdp).hasMatch()) {
        QMessageBox::warning(this, "Mot de passe invalide",
                             "Le mot de passe doit contenir au moins 8 caractères, "
                             "avec au moins une lettre et un chiffre.");
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

    if (modeDev)
        return true;

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

    // Force le rafraîchissement quand on ouvre la page
    qDebug() << "📄 Ouverture page projet - Rafraîchissement tableau...";
    refreshProjetTable();
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
//REFRESH TABLE
void MainWindow::refreshClientTable()
{
    Client c;
    QSqlQueryModel *model = c.getAllClients();

    ui->tableClients_6->setRowCount(0);
    ui->tableClients_6->setColumnCount(8);

    QStringList headers = {
        "Activité", "ID", "Nom", "Email",
        "Téléphone", "Secteur d'activité",
        "Pays", "Date d'inscription"
    };
    ui->tableClients_6->setHorizontalHeaderLabels(headers);

    for (int i = 0; i < model->rowCount(); ++i)
    {
        ui->tableClients_6->insertRow(i);

        int idClient = model->data(model->index(i, 0)).toInt();

        // Récupération projet via client.cpp (SQL uniquement là-bas)
        QSqlQuery info = c.getProjetInfo(idClient);
        info.next();
        int duree = info.value("duree").toInt();
        bool enCours = info.value("enCours").toInt();
        bool inactif = (!enCours && duree < 30);

        //  Bulle statut (colonne 0)
        QWidget *cellWidget = new QWidget();
        QHBoxLayout *layout = new QHBoxLayout(cellWidget);
        layout->setContentsMargins(0, 0, 0, 0);
        layout->setAlignment(Qt::AlignCenter);

        QLabel *bubble = new QLabel();
        bubble->setFixedSize(14, 14);
        bubble->setStyleSheet(QString("border-radius:7px; background-color:%1;")
                                  .arg(inactif ? "#E53935" : "#43A047"));
        layout->addWidget(bubble);
        ui->tableClients_6->setCellWidget(i, 0, cellWidget);

        //  Autres colonnes (1 → 7)
        for (int j = 0; j < model->columnCount(); ++j)
        {
            QVariant data = model->data(model->index(i, j));
            QString value;

            if (data.typeId() == QMetaType::QDate ||
                data.typeId() == QMetaType::QDateTime)
                value = data.toDate().toString("yyyy-MM-dd");
            else
                value = data.toString();

            ui->tableClients_6->setItem(i, j + 1, new QTableWidgetItem(value));
        }
    }

    ui->tableClients_6->resizeColumnsToContents();
    ui->tableClients_6->horizontalHeader()->setStretchLastSection(true);
}




//SELECTION CLIENT TABLE
void MainWindow::on_tableClients_6_cellClicked(int row, int column)
{
    Q_UNUSED(column);

    // NE PAS refreshClientTable() ici → ça efface la sélection
    // refreshClientTable();

    if (row < 0) return;

    ui->leId_6->setText(ui->tableClients_6->item(row, 1)->text());
    ui->leNom_6->setText(ui->tableClients_6->item(row, 2)->text());
    ui->leEmail_6->setText(ui->tableClients_6->item(row, 3)->text());
    ui->leTel_6->setText(ui->tableClients_6->item(row, 4)->text());
    ui->cbSecteur_6->setCurrentText(ui->tableClients_6->item(row, 5)->text());
    ui->cbPays_6->setCurrentText(ui->tableClients_6->item(row, 6)->text());

    // Date
    QString dateStr = ui->tableClients_6->item(row, 7)->text();
    QDate d = QDate::fromString(dateStr, "yyyy-MM-dd");
    if (d.isValid())
        ui->deDate_6->setDate(d);
}





//AJOUTER

void MainWindow::on_btnAjouter_3_clicked()
{
    QString idStr = ui->leId_6->text().trimmed();
    QString nom = ui->leNom_6->text().trimmed();
    QString email = ui->leEmail_6->text().trimmed();
    QString tel = ui->leTel_6->text().trimmed();
    QString secteur = ui->cbSecteur_6->currentText();
    QString pays = ui->cbPays_6->currentText();
    QDate dateInscription = ui->deDate_6->date();

    //  VALIDATIONS
    QRegularExpression regexId("^[0-9]{8}$");
    QRegularExpression regexTel("^[0-9]{8}$");
    QRegularExpression regexNom("^[A-Za-zÀ-ÖØ-öø-ÿ\\s]+$");
    QRegularExpression regexEmail("^[\\w._%+-]+@[\\w.-]+\\.[A-Za-z]{2,}$");

    if (!regexId.match(idStr).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "L'ID doit contenir exactement 8 chiffres.");
        return;
    }
    if (!regexNom.match(nom).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Nom invalide.");
        return;
    }
    if (!regexEmail.match(email).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Email invalide.");
        return;
    }
    if (!regexTel.match(tel).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Téléphone invalide.");
        return;
    }

    int id = idStr.toInt();

    //  Anti-doublon total (sans SQL direct ici)

    Client checker;
    QSqlQueryModel *all = checker.getAllClients();
    for (int i = 0; i < all->rowCount(); ++i)
    {
        if (all->data(all->index(i, 0)).toInt() == id)
        {
            QMessageBox::warning(this, "Erreur", "Cet ID existe déjà !");
            return;
        }
    }

    //  AJOUT
    Client c(id, nom, email, tel, secteur, pays, dateInscription);

    if (c.ajouter()) {
        QMessageBox::information(this, "Succès", "Client ajouté !");
        refreshClientTable();   // la bonne fonction MainWindow

        // Optionnel : nettoyer les champs
        ui->leId_6->clear();
        ui->leNom_6->clear();
        ui->leEmail_6->clear();
        ui->leTel_6->clear();
    }
    else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout du client.");
    }
}




//MODIFIER
void MainWindow::on_btnModifier_3_clicked()
{
    QString idStr = ui->leId_6->text().trimmed();
    QString nom = ui->leNom_6->text().trimmed();
    QString email = ui->leEmail_6->text().trimmed();
    QString tel = ui->leTel_6->text().trimmed();
    QString secteur = ui->cbSecteur_6->currentText();
    QString pays = ui->cbPays_6->currentText();
    QDate dateInscription = ui->deDate_6->date();


    //  Vérifier qu’un client est sélectionné

    if (idStr.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Sélectionnez un client.");
        return;
    }

    //  VALIDATIONS
    QRegularExpression regexId("^[0-9]{8}$");
    QRegularExpression regexTel("^[0-9]{8}$");
    QRegularExpression regexNom("^[A-Za-zÀ-ÖØ-öø-ÿ\\s]+$");
    QRegularExpression regexEmail("^[\\w._%+-]+@[\\w.-]+\\.[A-Za-z]{2,}$");

    if (!regexId.match(idStr).hasMatch() ||
        !regexNom.match(nom).hasMatch() ||
        !regexEmail.match(email).hasMatch() ||
        !regexTel.match(tel).hasMatch())
    {
        QMessageBox::warning(this, "Erreur", "Champs invalides !");
        return;
    }
    //  MODIFICATION

    int id = idStr.toInt();
    Client c(id, nom, email, tel, secteur, pays, dateInscription);

    if (c.modifier()) {
        QMessageBox::information(this, "Succès", "Client modifié !");
        refreshClientTable();   //  bon nom dans MainWindow
        //  Mise à jour automatique de la MAP après modification
        mapWindow->clearClients();

        Client c2;
        QSqlQueryModel *m = c2.getNomsEtVilles();

        for (int i = 0; i < m->rowCount(); ++i)
        {
            QString nom = m->data(m->index(i, 0)).toString().trimmed();
            QString ville = m->data(m->index(i, 1)).toString().trimmed();

            if (!nom.isEmpty() && !ville.isEmpty())
                mapWindow->addClient(nom, ville);
        }

        mapWindow->update();

    }
    else {
        QMessageBox::critical(this, "Erreur",
                              "Échec de la modification.");
    }
}


//SUPPRIMER
void MainWindow::on_btnSupprimer_3_clicked()
{
    // Vérifier la sélection
    if (ui->leId_6->text().isEmpty()) {
        QMessageBox::warning(this, "Erreur",
                             "Sélectionnez un client.");
        return;
    }

    int id = ui->leId_6->text().toInt();
    Client c;

    // Suppression
    if (c.supprimer(id)) {
        QMessageBox::information(this, "Succès", "Client supprimé !");
        refreshClientTable();   // bon nom pour MainWindow

        // Optionnel : nettoyer le formulaire
        ui->leId_6->clear();
        ui->leNom_6->clear();
        ui->leEmail_6->clear();
        ui->leTel_6->clear();
    }
    else {
        QMessageBox::critical(this, "Erreur",
                              "Suppression impossible.");
    }
}







//RECHERCHE
void MainWindow::on_leSearch_6_textChanged(const QString &text)
{
    Client c;
    QSqlQueryModel *model = c.rechercheSecteur(text);

    ui->tableClients_6->setRowCount(0);
    ui->tableClients_6->setColumnCount(8);

    // Colonnes
    QStringList headers = {
        "Activité", "ID", "Nom", "Email",
        "Téléphone", "Secteur d'activité",
        "Pays", "Date d'inscription"
    };
    ui->tableClients_6->setHorizontalHeaderLabels(headers);

    for (int i = 0; i < model->rowCount(); ++i)
    {
        ui->tableClients_6->insertRow(i);

        //  Activité : ici on ne recalcule pas (comme ton commentaire)
        // Je mets une bulle grise par défaut pour éviter un vide moche
        QWidget *cellWidget = new QWidget();
        QHBoxLayout *layout = new QHBoxLayout(cellWidget);
        layout->setContentsMargins(0, 0, 0, 0);
        layout->setAlignment(Qt::AlignCenter);

        QLabel *bubble = new QLabel();
        bubble->setFixedSize(14, 14);
        bubble->setStyleSheet("border-radius:7px; background-color:#BDBDBD;");
        layout->addWidget(bubble);
        ui->tableClients_6->setCellWidget(i, 0, cellWidget);

        //  Remplissage des colonnes 1..7
        for (int j = 0; j < model->columnCount(); ++j)
        {
            QVariant data = model->data(model->index(i, j));
            QString value = (data.typeId() == QMetaType::QDate)
                                ? data.toDate().toString("yyyy-MM-dd")
                                : data.toString();

            ui->tableClients_6->setItem(i, j + 1, new QTableWidgetItem(value));
        }
    }

    ui->tableClients_6->resizeColumnsToContents();
    ui->tableClients_6->horizontalHeader()->setStretchLastSection(true);
}








//TRIER

void MainWindow::on_pushButton_9_clicked()
{
    Client c;
    QSqlQueryModel *model = c.getClientsTries();  // tri depuis client.cpp

    ui->tableClients_6->setRowCount(0);
    ui->tableClients_6->setColumnCount(8);

    // En-têtes (cohérents avec refresh et recherche)
    QStringList headers = {
        "Activité", "ID", "Nom", "Email",
        "Téléphone", "Secteur d'activité",
        "Pays", "Date d'inscription"
    };
    ui->tableClients_6->setHorizontalHeaderLabels(headers);

    for (int i = 0; i < model->rowCount(); ++i)
    {
        ui->tableClients_6->insertRow(i);

        int idClient = model->data(model->index(i, 0)).toInt();

        //  Statut via getProjetInfo
        QSqlQuery info = c.getProjetInfo(idClient);
        info.next();
        int duree = info.value("duree").toInt();
        bool enCours = info.value("enCours").toInt();
        bool inactif = (!enCours && duree < 30);

        //  Bulle activité
        QWidget *cellWidget = new QWidget();
        QHBoxLayout *layout = new QHBoxLayout(cellWidget);
        layout->setContentsMargins(0, 0, 0, 0);
        layout->setAlignment(Qt::AlignCenter);

        QLabel *bubble = new QLabel();
        bubble->setFixedSize(14, 14);
        bubble->setStyleSheet(QString("border-radius:7px; background-color:%1;")
                                  .arg(inactif ? "#E53935" : "#43A047"));
        layout->addWidget(bubble);
        ui->tableClients_6->setCellWidget(i, 0, cellWidget);

        //  Remplissage colonnes 1..7
        for (int j = 0; j < model->columnCount(); ++j)
        {
            QVariant data = model->data(model->index(i, j));
            QString value = (data.typeId() == QMetaType::QDate)
                                ? data.toDate().toString("yyyy-MM-dd")
                                : data.toString();

            ui->tableClients_6->setItem(i, j + 1,
                                        new QTableWidgetItem(value));
        }
    }

    ui->tableClients_6->resizeColumnsToContents();
    ui->tableClients_6->horizontalHeader()->setStretchLastSection(true);
}








//EXPORTTPDF

void MainWindow::on_pushButton_7_clicked()
{
    Client c;
    QSqlQueryModel *model = c.getAllClients();

    QString filePath = QFileDialog::getSaveFileName(
        this, "Exporter PDF", "", "PDF (*.pdf)");
    if (filePath.isEmpty())
        return;

    QPdfWriter pdf(filePath);
    pdf.setPageSize(QPageSize(QPageSize::A4));
    pdf.setResolution(300);

    QPainter painter(&pdf);
    painter.setRenderHint(QPainter::Antialiasing);

    QColor mauve(147, 112, 219), orange(255, 140, 0),
        mauveLight(230, 220, 240), orangeLight(255, 245, 230);

    //  TITRE
    painter.setFont(QFont("Arial", 18, QFont::Bold));
    painter.setPen(orange);
    painter.drawText(QRect(0, 200, pdf.width(), 100),
                     Qt::AlignCenter, "Liste des clients");
    painter.setPen(QPen(mauve, 3));
    painter.drawLine(200, 350, pdf.width() - 200, 350);

    int x = -25, y = 500, h = 120;
    int w[] = {250, 330, 550, 250, 610, 250, 260};

    QStringList headers = {"ID", "Nom", "Email", "Tél",
                           "Secteur", "Ville", "Date"};

    //  EN-TÊTE TABLEAU
    painter.setFont(QFont("Arial", 10, QFont::Bold));
    painter.setBrush(mauve);
    painter.drawRect(x, y,
                     w[0] + w[1] + w[2] + w[3] + w[4] + w[5] + w[6], h);
    painter.setPen(Qt::white);

    int cx = x;
    for (int i = 0; i < 7; ++i)
    {
        painter.drawText(QRect(cx, y, w[i], h),
                         Qt::AlignCenter, headers[i]);
        cx += w[i];
    }
    y += h;

    painter.setFont(QFont("Arial", 9));

    //  LIGNES DES CLIENTS
    for (int i = 0; i < model->rowCount(); ++i)
    {
        int idClient = model->data(model->index(i, 0)).toInt();

        //  Active / Inactive (couleur ligne)
        QSqlQuery info = c.getProjetInfo(idClient);
        info.next();
        int duree = info.value("duree").toInt();
        bool enCours = info.value("enCours").toInt();
        bool inactif = (!enCours && duree < 30);

        QColor bg = inactif ?
                        QColor(255, 220, 220) :
                        (i % 2 == 0 ? mauveLight : orangeLight);

        painter.fillRect(x, y,
                         w[0] + w[1] + w[2] + w[3] + w[4] + w[5] + w[6],
                         h, bg);
        painter.setPen(inactif ? QColor(200, 0, 0) : Qt::black);

        cx = x;
        for (int j = 0; j < 7; ++j)
        {
            QVariant data = model->data(model->index(i, j));
            QString val =
                (j == 6)
                    ? data.toDate().toString("dd/MM/yyyy")
                    : data.toString();

            painter.drawText(QRect(cx + 5, y, w[j] - 10, h),
                             Qt::AlignVCenter | Qt::AlignLeft, val);
            cx += w[j];
        }

        y += h;

        //  Gestion saut de page
        if (y > pdf.height() - 400)
        {
            pdf.newPage();
            y = 200;
        }
    }

    //  PIED DE PAGE
    painter.setFont(QFont("Arial", 9, -1, true));
    painter.setPen(orange);
    painter.drawText(100, pdf.height() - 150,
                     "Généré le : " +
                         QDate::currentDate().toString("dd/MM/yyyy"));

    painter.end();

    QMessageBox::information(this, "PDF", "Exporté !");
}







//EXPORT CLIENTS INACTIFS
void MainWindow::on_pushButton_6_clicked()
{
    Client c;
    QSqlQueryModel *model = c.getAllClients();

    QString filePath = QFileDialog::getSaveFileName(
        this, "Exporter PDF des clients inactifs", "",
        "Fichiers PDF (*.pdf)");
    if (filePath.isEmpty())
        return;

    QPdfWriter pdf(filePath);
    pdf.setPageSize(QPageSize(QPageSize::A4));
    pdf.setResolution(300);

    QPainter painter(&pdf);
    painter.setRenderHint(QPainter::Antialiasing);

    QColor mauveHeader(147, 112, 219);
    QColor orangeAccent(255, 140, 0);
    QColor mauveLight(230, 220, 240);
    QColor orangeLight(255, 245, 230);

    //  TITRE
    painter.setFont(QFont("Arial", 18, QFont::Bold));
    painter.setPen(orangeAccent);
    painter.drawText(QRect(0, 200, pdf.width(), 100),
                     Qt::AlignCenter,
                     "Liste des clients inactifs (projets < 30 jours)");
    painter.setPen(QPen(mauveHeader, 3));
    painter.drawLine(200, 350, pdf.width() - 200, 350);

    int startX = 200;
    int y = 500;
    int rowHeight = 100;

    int colIdWidth = 180;
    int colNomWidth = 450;
    int colEmailWidth = 700;
    int colDureeWidth = 570;

    painter.setFont(QFont("Arial", 12, QFont::Bold));
    painter.setPen(Qt::white);
    painter.setBrush(mauveHeader);
    painter.drawRect(startX, y,
                     colIdWidth + colNomWidth + colEmailWidth + colDureeWidth,
                     rowHeight);

    painter.setBrush(Qt::NoBrush);
    painter.setPen(QPen(mauveHeader, 2));

    painter.drawRect(startX, y, colIdWidth, rowHeight);
    painter.drawRect(startX + colIdWidth, y, colNomWidth, rowHeight);
    painter.drawRect(startX + colIdWidth + colNomWidth, y, colEmailWidth,
                     rowHeight);
    painter.drawRect(startX + colIdWidth + colNomWidth + colEmailWidth, y,
                     colDureeWidth, rowHeight);

    painter.setPen(Qt::white);
    painter.drawText(QRect(startX, y, colIdWidth, rowHeight),
                     Qt::AlignCenter, "ID");
    painter.drawText(QRect(startX + colIdWidth, y, colNomWidth, rowHeight),
                     Qt::AlignCenter, "Nom");
    painter.drawText(QRect(startX + colIdWidth + colNomWidth, y,
                           colEmailWidth, rowHeight),
                     Qt::AlignCenter, "Email");
    painter.drawText(QRect(startX + colIdWidth + colNomWidth + colEmailWidth,
                           y, colDureeWidth, rowHeight),
                     Qt::AlignCenter, "Durée max projet");

    painter.setFont(QFont("Arial", 10));
    y += rowHeight;

    int ligne = 0;

    for (int i = 0; i < model->rowCount(); ++i)
    {
        int idClient = model->data(model->index(i, 0)).toInt();
        QString nom = model->data(model->index(i, 1)).toString();
        QString email = model->data(model->index(i, 2)).toString();

        QSqlQuery info = c.getProjetInfo(idClient);
        info.next();
        int duree = info.value("duree").toInt();
        bool enCours = info.value("enCours").toInt();
        bool inactif = (!enCours && duree < 30);

        if (!inactif)
            continue;

        QColor bg = (ligne % 2 == 0) ? mauveLight : orangeLight;
        painter.fillRect(startX, y,
                         colIdWidth + colNomWidth + colEmailWidth +
                             colDureeWidth,
                         rowHeight, bg);

        painter.setPen(QPen(mauveHeader, 1));
        painter.drawRect(startX, y, colIdWidth, rowHeight);
        painter.drawRect(startX + colIdWidth, y, colNomWidth, rowHeight);
        painter.drawRect(startX + colIdWidth + colNomWidth, y,
                         colEmailWidth, rowHeight);
        painter.drawRect(startX + colIdWidth + colNomWidth + colEmailWidth, y,
                         colDureeWidth, rowHeight);

        painter.setPen(Qt::black);
        painter.drawText(QRect(startX + 20, y, colIdWidth - 40, rowHeight),
                         Qt::AlignVCenter | Qt::AlignLeft,
                         QString::number(idClient));
        painter.drawText(QRect(startX + colIdWidth + 20, y,
                               colNomWidth - 40, rowHeight),
                         Qt::AlignVCenter | Qt::AlignLeft, nom);
        painter.drawText(QRect(startX + colIdWidth + colNomWidth + 20, y,
                               colEmailWidth - 40, rowHeight),
                         Qt::AlignVCenter | Qt::AlignLeft, email);
        painter.drawText(QRect(startX + colIdWidth + colNomWidth +
                                   colEmailWidth + 20,
                               y, colDureeWidth - 40, rowHeight),
                         Qt::AlignVCenter | Qt::AlignLeft,
                         QString::number(duree) + " jours");

        y += rowHeight;
        ++ligne;

        if (y > pdf.height() - 300)
        {
            pdf.newPage();
            y = 200;
        }
    }

    painter.setFont(QFont("Arial", 9, -1, true));
    painter.setPen(orangeAccent);
    painter.drawText(
        200, pdf.height() - 150,
        "Généré le : " + QDate::currentDate().toString("dd/MM/yyyy"));

    painter.end();
    QMessageBox::information(this, "PDF",
                             "PDF généré avec succès !");
}










//FICHE CLIENT
void MainWindow::on_pushButton_10_clicked()
{
    if (ui->leId_6->text().isEmpty())
    {
        QMessageBox::warning(this, "Erreur",
                             "Sélectionnez un client d'abord.");
        return;
    }

    int idClient = ui->leId_6->text().toInt();
    Client c;

    QString filePath = QFileDialog::getSaveFileName(
        this, "Exporter Fiche Client", "", "PDF (*.pdf)");
    if (filePath.isEmpty())
        return;

    QPdfWriter pdf(filePath);
    pdf.setPageSize(QPageSize(QPageSize::A4));
    pdf.setResolution(300);

    QPainter painter(&pdf);
    painter.setRenderHint(QPainter::Antialiasing);

    QColor mauve(147, 112, 219), orange(255, 140, 0),
        mauveLight(230, 220, 240), orangeLight(255, 245, 230);

    //  TITRE
    painter.setFont(QFont("Arial", 20, QFont::Bold));
    painter.setPen(orange);
    painter.drawText(QRect(0, 200, pdf.width(), 100),
                     Qt::AlignCenter, "FICHE CLIENT");
    painter.setPen(QPen(mauve, 3));
    painter.drawLine(200, 300, pdf.width() - 200, 300);

    int x = 100, y = 380, h = 60;

    //  SECTION "INFORMATIONS DU CLIENT"
    painter.setFont(QFont("Arial", 12, QFont::Bold));
    painter.setPen(mauve);
    painter.drawText(x, y, "Informations du client");
    y += 40;

    // Récup projets pour statut
    QSqlQueryModel *projModel = c.getProjetsDuClient(idClient);
    QDate lastEnd;

    for (int i = 0; i < projModel->rowCount(); ++i)
    {
        QDate fin = projModel->data(projModel->index(i, 2)).toDate();
        if (fin.isValid() && (!lastEnd.isValid() || fin > lastEnd))
            lastEnd = fin;
    }

    QString statut = "ACTIF";
    if (lastEnd.isValid())
    {
        int daysInactive = lastEnd.daysTo(QDate::currentDate());
        if (daysInactive > 0)
            statut = "INACTIF depuis " + lastEnd.toString("dd/MM/yyyy");
    }

    QStringList labels = {"ID Client", "Nom", "Email", "Téléphone",
                          "Secteur", "Ville",
                          "Date d'inscription"};

    QStringList values = {
        ui->leId_6->text(),
        ui->leNom_6->text(),
        ui->leEmail_6->text(),
        ui->leTel_6->text(),
        ui->cbSecteur_6->currentText(),
        ui->cbPays_6->currentText(),
        ui->deDate_6->date().toString("dd/MM/yyyy"),
    };

    int labelW = 450;
    int valueW = 650;

    //  TABLE INFORMATIONS
    for (int i = 0; i < labels.size(); ++i)
    {
        QColor bg = (i % 2 == 0 ? mauveLight : orangeLight);
        painter.fillRect(x, y, labelW + valueW, h, bg);

        painter.setPen(Qt::black);
        painter.setFont(QFont("Arial", 10, QFont::Bold));
        painter.drawText(QRect(x + 10, y, labelW - 20, h),
                         Qt::AlignVCenter | Qt::AlignLeft,
                         labels[i] + " :");

        painter.setFont(QFont("Arial", 10));
        painter.drawText(QRect(x + labelW + 10, y, valueW - 20, h),
                         Qt::AlignVCenter | Qt::AlignLeft,
                         values[i]);

        y += h;
    }

    y += 60;

    //  SECTION "PROJETS ASSOCIÉS"
    painter.setFont(QFont("Arial", 12, QFont::Bold));
    painter.setPen(mauve);
    painter.drawText(x, y, "Projets associés");
    y += 40;

    int w[] = {250, 350, 350, 350, 350};
    QStringList headers = {"ID", "Début", "Fin", "Budget", "Statut"};

    painter.setBrush(mauve);
    painter.setPen(Qt::white);
    painter.drawRect(x, y,
                     w[0] + w[1] + w[2] + w[3] + w[4], h);

    int cx = x;
    painter.setFont(QFont("Arial", 10, QFont::Bold));
    for (int i = 0; i < 5; ++i)
    {
        painter.drawText(QRect(cx, y, w[i], h),
                         Qt::AlignCenter, headers[i]);
        cx += w[i];
    }
    y += h;

    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial", 10));
    int rowIndex = 0;

    for (int i = 0; i < projModel->rowCount(); ++i)
    {
        QColor bg = (rowIndex % 2 == 0 ? mauveLight : orangeLight);
        painter.fillRect(x, y,
                         w[0] + w[1] + w[2] + w[3] + w[4], h, bg);

        cx = x;

        painter.drawText(QRect(cx + 5, y, w[0], h),
                         Qt::AlignVCenter | Qt::AlignLeft,
                         projModel->data(projModel->index(i, 0)).toString());
        cx += w[0];

        painter.drawText(QRect(cx + 5, y, w[1], h),
                         Qt::AlignVCenter | Qt::AlignLeft,
                         projModel->data(projModel->index(i, 1)).toDate().toString("dd/MM/yyyy"));
        cx += w[1];

        painter.drawText(QRect(cx + 5, y, w[2], h),
                         Qt::AlignVCenter | Qt::AlignLeft,
                         projModel->data(projModel->index(i, 2)).toDate().toString("dd/MM/yyyy"));
        cx += w[2];

        painter.drawText(QRect(cx + 5, y, w[3], h),
                         Qt::AlignVCenter | Qt::AlignLeft,
                         projModel->data(projModel->index(i, 3)).toString() + " DT");
        cx += w[3];

        painter.drawText(QRect(cx + 5, y, w[4], h),
                         Qt::AlignVCenter | Qt::AlignLeft,
                         projModel->data(projModel->index(i, 4)).toString());

        y += h;
        ++rowIndex;
    }

    // FOOTER
    painter.setFont(QFont("Arial", 8, QFont::StyleItalic));
    painter.setPen(QColor(120, 120, 120));
    painter.drawText(
        QRect(100, pdf.height() - 120, pdf.width() - 200, 40),
        Qt::AlignCenter,
        "Document généré automatiquement - SDCCS - " +
            QDate::currentDate().toString("dd/MM/yyyy"));

    painter.end();

    QMessageBox::information(this, "PDF", "Fiche client exportée !");
}










//MAP
void MainWindow::on_pushButton_11_clicked()
{
    Client c;
    QSqlQueryModel *model = c.getNomsEtVilles();

    if (!mapWindow)
        mapWindow = new BubbleMapWindow();

    mapWindow->clearClients();

    for (int i = 0; i < model->rowCount(); ++i)
    {
        QString nom = model->data(model->index(i, 0)).toString().trimmed();
        QString ville = model->data(model->index(i, 1)).toString().trimmed();

        if (!nom.isEmpty() && !ville.isEmpty())
            mapWindow->addClient(nom, ville);
    }

    mapWindow->show();
}









//STATS
/* ============================================================
   🔵 STATISTIQUES – TOP 3 SECTEURS D'ACTIVITÉ
   ============================================================ */
void MainWindow::on_pushButton_8_clicked()
{
    Client c;
    QSqlQueryModel *model = c.getAllClients();

    QMap<QString, int> counts;
    int totalGlobal = 0;

    // Comptage secteurs
    for (int i = 0; i < model->rowCount(); ++i)
    {
        QString secteur = model->data(model->index(i, 4)).toString().trimmed();

        if (secteur.isEmpty() || secteur == " " ||
            secteur.toLower() == "null")
            continue;

        counts[secteur]++;
        totalGlobal++;
    }

    if (counts.isEmpty())
    {
        QMessageBox::information(
            this, "Info",
            "Aucun secteur valide trouvé.\n"
            "Veuillez ajouter des secteurs dans vos clients.");
        return;
    }

    // Tri décroissant
    QList<QPair<QString, int>> liste;
    for (auto it = counts.begin(); it != counts.end(); ++it)
        liste.append(qMakePair(it.key(), it.value()));

    std::sort(liste.begin(), liste.end(),
              [](const QPair<QString, int> &a,
                 const QPair<QString, int> &b) {
                  return a.second > b.second;
              });

    int max = qMin(3, liste.size());

    // CHART
    QPieSeries *series = new QPieSeries();
    series->setHoleSize(0.45);
    series->setPieSize(0.90);

    QList<QColor> colors = {QColor("#0A1A2F"), QColor("#FB8C00"), QColor("#9C27B0")};

    for (int i = 0; i < max; ++i)
    {
        int value = liste[i].second;
        QPieSlice *slice = series->append("", value);

        QLinearGradient grad;
        grad.setStart(0, 0);
        grad.setFinalStop(1, 1);
        grad.setColorAt(0, colors[i].lighter(130));
        grad.setColorAt(1, colors[i].darker(110));
        slice->setBrush(grad);

        slice->setPen(QPen(Qt::white, 4));
        connect(slice, &QPieSlice::hovered, slice,
                [slice](bool state) {
                    slice->setExploded(state);
                    slice->setExplodeDistanceFactor(state ? 0.12 : 0.06);
                });

        slice->setExploded(true);
        slice->setExplodeDistanceFactor(0.06);
    }

    series->setLabelsVisible(false);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Top 3 secteurs d'activité les plus fréquents");
    chart->setTitleFont(QFont("Segoe UI", 16, QFont::Bold));
    chart->legend()->hide();
    chart->setDropShadowEnabled(true);
    chart->setBackgroundBrush(QColor("#EDEAF9"));
    chart->setBackgroundRoundness(20);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setStyleSheet("background: transparent; border-radius: 20px;");

    // Légende personnalisée
    QWidget *legendWidget = new QWidget();
    QVBoxLayout *legendLayout = new QVBoxLayout(legendWidget);

    for (int i = 0; i < max; ++i)
    {
        QString secteur = liste[i].first;
        int count = liste[i].second;
        double percent = ((double)count / (double)totalGlobal) * 100.0;

        QLabel *label = new QLabel();

        QString bullet = QString("<span style='font-size:22px; color:%1;'>●</span>")
                             .arg(colors[i].name());

        QString html =
            QString("%1 <b style='font-size:16px; color:%2;'>%3</b><br>"
                    "<span style='color:%2; font-size:13px;'>%4 clients — %5%</span>")
                .arg(bullet)
                .arg(colors[i].name())
                .arg(secteur)
                .arg(count)
                .arg(QString::number(percent, 'f', 1));

        label->setText(html);
        label->setWordWrap(true);
        label->setStyleSheet("padding: 6px;");
        legendLayout->addWidget(label);
    }

    // Layout final
    QWidget *container = new QWidget();
    QHBoxLayout *hLayout = new QHBoxLayout(container);

    hLayout->addWidget(chartView, 3);
    hLayout->addWidget(legendWidget, 1);
    hLayout->setSpacing(30);

    container->setStyleSheet(
        "background-color: #EDEAF9;"
        "border-radius: 25px;"
        "padding: 20px;");

    // Dialog
    QDialog *dialog = new QDialog(this);
    dialog->setWindowTitle("Statistiques - Secteurs d'activité");
    dialog->resize(1000, 650);

    QVBoxLayout *mainLayout = new QVBoxLayout(dialog);
    mainLayout->addWidget(container);

    dialog->exec();
}




void MainWindow::on_pushButton_client_clicked()
{
    ui->stackedWidget->setCurrentIndex(2); // ou ce que tu veux
    refreshClientTable();
}


//fin gestionclient


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
            QMessageBox::warning(this, "Erreur", "Impossible de charger l'image.");
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
        QMessageBox::information(this, "Info", "Ce type de fichier n'est pas pris en charge.");
    }
}

// ==================== FONCTIONS PROJETS ====================

// ==================== FONCTIONS GESTION PROJETS ====================

// Dans setupProjetTableWidget() :
void MainWindow::setupProjetTableWidget()
{
    ui->tableWidget_2->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget_2->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget_2->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget_2->setColumnCount(6);
    QStringList headers;
    headers << "ID Client" << "Budget Prévu" << "Budget Réalisé" << "Date Début" << "Date Fin" << "Statut";
    ui->tableWidget_2->setHorizontalHeaderLabels(headers);
}

void MainWindow::refreshProjetTableWidget()
{
    ui->tableWidget_2->setRowCount(0);
    QSqlQueryModel* model = projetModel.afficher();

    if (model) {
        for (int row = 0; row < model->rowCount(); ++row) {
            ui->tableWidget_2->insertRow(row);
            for (int col = 0; col < model->columnCount(); ++col) {
                QString textValue = model->data(model->index(row, col)).toString();
                QTableWidgetItem *item = new QTableWidgetItem(textValue);

                // Définir les données de tri pour les colonnes spécifiques
                if (col == 1 || col == 2) { // Colonnes budget (1: budget prévu, 2: budget réalisé)
                    bool ok;
                    double numericValue = textValue.toDouble(&ok);
                    if (ok) {
                        item->setData(Qt::UserRole, numericValue);
                    } else {
                        item->setData(Qt::UserRole, 0.0);
                    }
                } else if (col == 3 || col == 4) { // Colonnes dates (3: date début, 4: date fin)
                    QDate dateValue = parseProjetDate(textValue);
                    if (dateValue.isValid()) {
                        item->setData(Qt::UserRole, dateValue);
                    }
                }

                ui->tableWidget_2->setItem(row, col, item);
            }
        }
        ui->tableWidget_2->resizeColumnsToContents();
        delete model;
        qDebug() << "✅ Tableau rafraîchi avec" << ui->tableWidget_2->rowCount() << "projets";
        mettreAJourStatsRapidesProjet();
    } else {
        qDebug() << "❌ Erreur lors du chargement des projets";
    }
}
void MainWindow::mettreAJourStatsRapidesProjet()
{
    QVector<QPair<QString, int>> donnees = Projet::compterProjetsParPlageBudget();
    for (const auto& paire : donnees) {
        // Traitement si nécessaire
    }
}

void MainWindow::searchProjects(const QString& searchText)
{
    // CORRECTION : Utiliser ui->tableWidget_2 au lieu de ui->tableWidget
    ui->tableWidget_2->setRowCount(0);

    if (searchText.isEmpty()) {
        refreshProjetTableWidget();
        return;
    }

    QSqlQueryModel* model = projetModel.rechercher(searchText);

    if (model) {
        for (int row = 0; row < model->rowCount(); ++row) {
            ui->tableWidget_2->insertRow(row);
            for (int col = 0; col < model->columnCount(); ++col) {
                QTableWidgetItem *item = new QTableWidgetItem(
                    model->data(model->index(row, col)).toString()
                    );
                ui->tableWidget_2->setItem(row, col, item);
            }
        }
        ui->tableWidget_2->resizeColumnsToContents();
        delete model;
        qDebug() << "✅ Recherche effectuée pour:" << searchText << "-" << ui->tableWidget_2->rowCount() << "résultats";
    } else {
        qDebug() << "❌ Erreur lors de la recherche";
    }
}
void MainWindow::createProjetTableIfNotExists()
{
    QSqlQuery query(dbProjet);
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

bool MainWindow::validateProjetIdClient(const QString& idClientStr)
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

void MainWindow::setProjetModificationMode(bool modifying)
{
    isModifyingProjet = modifying;

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
        currentModifyIdClientProjet = 0;
        clearProjetFormFields();
    }
}

void MainWindow::clearProjetFormFields()
{
    ui->idClientLineEdit->clear();
    ui->budgetPrevuLineEdit->clear();
    ui->budgetRealiseLineEdit->clear();
    ui->dateDebutEdit->clear();
    ui->dateFinEdit->clear();
    ui->statutLineEdit->clear();
}

bool MainWindow::validateProjetBudget(const QString& budgetStr)
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

bool MainWindow::validateProjetDates(const QString& dateDebutStr, const QString& dateFinStr)
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

void MainWindow::on_addProjectButton_clicked()
{
    if (isModifyingProjet) {
        on_saveModificationButton_clicked();
        return;
    }

    QString idClientStr = ui->idClientLineEdit->text().trimmed();
    QString budgetPrevuStr = ui->budgetPrevuLineEdit->text().trimmed();
    QString budgetRealiseStr = ui->budgetRealiseLineEdit->text().trimmed();
    QString dateDebutStr = ui->dateDebutEdit->text().trimmed();
    QString dateFinStr = ui->dateFinEdit->text().trimmed();
    QString statut = ui->statutLineEdit->text().trimmed();

    if (!validateProjetIdClient(idClientStr)) {
        ui->idClientLineEdit->setFocus();
        return;
    }

    int idClient = idClientStr.toInt();

    if (Projet::existeClient(idClient)) {
        QMessageBox::warning(this, "Erreur", "Cet ID client existe déjà !");
        ui->idClientLineEdit->setFocus();
        return;
    }

    if (!budgetPrevuStr.isEmpty() && !validateProjetBudget(budgetPrevuStr)) {
        QMessageBox::warning(this, "Erreur", "Budget prévu invalide !");
        ui->budgetPrevuLineEdit->setFocus();
        return;
    }

    if (!budgetRealiseStr.isEmpty() && !validateProjetBudget(budgetRealiseStr)) {
        QMessageBox::warning(this, "Erreur", "Budget réalisé invalide !");
        ui->budgetRealiseLineEdit->setFocus();
        return;
    }

    if (!validateProjetDates(dateDebutStr, dateFinStr)) {
        return;
    }

    double budgetPrevu = budgetPrevuStr.isEmpty() ? 0.0 : budgetPrevuStr.toDouble();
    double budgetRealise = budgetRealiseStr.isEmpty() ? 0.0 : budgetRealiseStr.toDouble();
    QString dateDebutFormatted = dateDebutStr.isEmpty() ? "N/A" : dateDebutStr;
    QString dateFinFormatted = dateFinStr.isEmpty() ? "N/A" : dateFinStr;

    if (statut.isEmpty()) {
        statut = "En cours";
    }

    // DEBUG AVANT AJOUT
    qDebug() << "➕ AVANT AJOUT - Données:";
    qDebug() << "  ID Client:" << idClient;
    qDebug() << "  Budget prévu:" << budgetPrevu;
    qDebug() << "  Budget réalisé:" << budgetRealise;
    qDebug() << "  Date début:" << dateDebutFormatted;
    qDebug() << "  Date fin:" << dateFinFormatted;
    qDebug() << "  Statut:" << statut;

    Projet nouveauProjet(idClient, budgetPrevu, budgetRealise, dateDebutFormatted, dateFinFormatted, statut);
    bool success = nouveauProjet.ajouter();

    if (success) {
        // CORRECTION ICI : Appeler refreshProjetTable() au lieu de refreshProjetTableWidget()
        refreshProjetTable();  // <-- CHANGEMENT IMPORTANT

        // DEBUG APRÈS AJOUT
        qDebug() << "✅ APRÈS AJOUT";
        qDebug() << "  Lignes dans tableau:" << ui->tableWidget->rowCount();

        clearProjetFormFields();
        QMessageBox::information(this, "Succès", "Projet ajouté avec succès !");
        qDebug() << "✅ Projet ajouté dans Oracle. ID_CLIENT:" << idClient;
    } else {
        QMessageBox::critical(this, "Erreur", "Erreur lors de l'ajout du projet dans la base de données.");
        qDebug() << "❌ Erreur lors de l'ajout du projet";
    }
}
void MainWindow::on_saveModificationButton_clicked()
{
    if (currentModifyIdClientProjet == 0) {
        QMessageBox::warning(this, "Erreur", "Aucun projet sélectionné pour modification.");
        return;
    }

    QString nouveauIdClientStr = ui->idClientLineEdit->text().trimmed();
    QString nouveauBudgetPrevuStr = ui->budgetPrevuLineEdit->text().trimmed();
    QString nouveauBudgetRealiseStr = ui->budgetRealiseLineEdit->text().trimmed();
    QString nouvelleDateDebutStr = ui->dateDebutEdit->text().trimmed();
    QString nouvelleDateFinStr = ui->dateFinEdit->text().trimmed();
    QString nouveauStatut = ui->statutLineEdit->text().trimmed();

    if (!validateProjetIdClient(nouveauIdClientStr)) {
        ui->idClientLineEdit->setFocus();
        return;
    }

    int nouveauIdClient = nouveauIdClientStr.toInt();

    if (nouveauIdClient != currentModifyIdClientProjet && Projet::existeClient(nouveauIdClient)) {
        QMessageBox::warning(this, "Erreur", "Cet ID client existe déjà !");
        ui->idClientLineEdit->setFocus();
        return;
    }

    if (!nouveauBudgetPrevuStr.isEmpty() && !validateProjetBudget(nouveauBudgetPrevuStr)) {
        QMessageBox::warning(this, "Erreur", "Budget prévu invalide !");
        ui->budgetPrevuLineEdit->setFocus();
        return;
    }

    if (!nouveauBudgetRealiseStr.isEmpty() && !validateProjetBudget(nouveauBudgetRealiseStr)) {
        QMessageBox::warning(this, "Erreur", "Budget réalisé invalide !");
        ui->budgetRealiseLineEdit->setFocus();
        return;
    }

    if (!validateProjetDates(nouvelleDateDebutStr, nouvelleDateFinStr)) {
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

    bool success = projetModifie.modifier(currentModifyIdClientProjet);

    if (success) {
        refreshProjetTableWidget();
        setProjetModificationMode(false);
        QMessageBox::information(this, "Succès", "Projet modifié avec succès !");
        qDebug() << "✅ Projet modifié dans Oracle. Ancien ID_CLIENT:" << currentModifyIdClientProjet << "Nouveau ID_CLIENT:" << nouveauIdClient;
    } else {
        QMessageBox::critical(this, "Erreur", "Erreur lors de la modification du projet dans la base de données.");
    }
}

void MainWindow::on_modifButton_clicked()
{
    // CORRECTION : Utiliser ui->tableWidget_2 au lieu de ui->tableWidget
    int currentRow = ui->tableWidget_2->currentRow();
    if (currentRow < 0) {
        QMessageBox::warning(this, "Modification", "Veuillez sélectionner un projet à modifier.");
        return;
    }

    currentModifyIdClientProjet = ui->tableWidget_2->item(currentRow, 0)->text().toInt();
    QString budgetPrevuActuel = ui->tableWidget_2->item(currentRow, 1)->text();
    QString budgetRealiseActuel = ui->tableWidget_2->item(currentRow, 2)->text();
    QString dateDebutActuelle = ui->tableWidget_2->item(currentRow, 3)->text();
    QString dateFinActuelle = ui->tableWidget_2->item(currentRow, 4)->text();
    QString statutActuel = ui->tableWidget_2->item(currentRow, 5)->text();

    ui->idClientLineEdit->setText(QString::number(currentModifyIdClientProjet));
    ui->budgetPrevuLineEdit->setText(budgetPrevuActuel);
    ui->budgetRealiseLineEdit->setText(budgetRealiseActuel);
    ui->dateDebutEdit->setText(dateDebutActuelle);
    ui->dateFinEdit->setText(dateFinActuelle);
    ui->statutLineEdit->setText(statutActuel);

    setProjetModificationMode(true);

    QMessageBox::information(this, "Modification",
                             "Mode modification activé pour l'ID client: " + QString::number(currentModifyIdClientProjet) +
                                 "\nModifiez les valeurs et cliquez sur 'Confirmer Modification' pour sauvegarder.");
}

void MainWindow::on_cancelModificationButton_clicked()
{
    setProjetModificationMode(false);
    QMessageBox::information(this, "Annulation", "Modification annulée.");
}

void MainWindow::on_deleteProjectButton_clicked()
{
    int currentRow = ui->tableWidget_2->currentRow();
    if (currentRow < 0) {
        QMessageBox::warning(this, "Suppression", "Veuillez sélectionner un projet à supprimer.");
        return;
    }

    int idClientProjet = ui->tableWidget_2->item(currentRow, 0)->text().toInt();
    QString statutProjet = ui->tableWidget_2->item(currentRow, 5)->text();

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmation",
                                  "Voulez-vous vraiment supprimer le projet avec l'ID client : " +
                                      QString::number(idClientProjet) + " ?\n"
                                                                        "Statut: " + statutProjet,
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        bool success = projetModel.supprimer(idClientProjet);

        if (success) {
            QMessageBox::information(this, "Succès", "Projet supprimé avec succès !");
            refreshProjetTableWidget();
            qDebug() << "✅ Projet supprimé d'Oracle. ID_CLIENT:" << idClientProjet;
        } else {
            QMessageBox::critical(this, "Erreur",
                                  "Erreur lors de la suppression du projet dans la base de données.\n"
                                  "Vérifiez que le projet existe et n'est pas référencé ailleurs.");
        }
    }
}
void MainWindow::on_searchButton_clicked()
{
    QString searchText = ui->searchLineEdit->text().trimmed();
    searchProjects(searchText);

    if (searchText.isEmpty()) {
        QMessageBox::information(this, "Recherche", "Affichage de tous les projets.");
    } else {
        QMessageBox::information(this, "Recherche", "Recherche effectuée pour: " + searchText);
    }
}

void MainWindow::on_searchLineEdit_textChanged(const QString &text)
{
    searchProjects(text);
}

void MainWindow::on_sortByBudgetButton_clicked()
{
    // Trier par budget prévu (colonne 1)
    ui->tableWidget_2->sortItems(1, Qt::DescendingOrder);
    qDebug() << "✅ Tri par budget effectué";
    QMessageBox::information(this, "Tri", "Projets triés par budget (décroissant).");
}

void MainWindow::on_sortByDateButton_clicked()
{
    // Trier par date de fin (colonne 4)
    ui->tableWidget_2->sortItems(4, Qt::AscendingOrder);
    qDebug() << "✅ Tri par date effectué";
    QMessageBox::information(this, "Tri", "Projets triés par date de fin (croissant).");
}
void MainWindow::on_refreshButton_clicked()
{
    refreshProjetTableWidget();
    QMessageBox::information(this, "Rafraîchissement", "Données rafraîchies depuis la base de données Oracle.");
    qDebug() << "✅ Données rafraîchies depuis Oracle";
}

// ==================== FONCTIONNALITÉS CALENDRIER ====================

void MainWindow::on_calendarButton_clicked()
{
    showCalendarWithProjects();
}

void MainWindow::on_calculateDaysButton_clicked()
{
    showDaysCalculationResult();
}

void MainWindow::showCalendarWithProjects()
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

void MainWindow::highlightProjectPeriods(QCalendarWidget *calendar)
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

        QDate dateDebut = parseProjetDate(dateDebutStr);
        QDate dateFin = parseProjetDate(dateFinStr);

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

QDate MainWindow::parseProjetDate(const QString& dateStr)
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

void MainWindow::showDaysCalculationResult(QLabel *resultLabel)
{
    // CORRECTION : Utiliser ui->tableWidget_2 au lieu de ui->tableWidget
    int currentRow = ui->tableWidget_2->currentRow();
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

    QString projetId = ui->tableWidget_2->item(currentRow, 0)->text();
    QString budgetPrevu = ui->tableWidget_2->item(currentRow, 1)->text();
    QString dateDebutStr = ui->tableWidget_2->item(currentRow, 3)->text();
    QString dateFinStr = ui->tableWidget_2->item(currentRow, 4)->text();
    QString projetStatut = ui->tableWidget_2->item(currentRow, 5)->text();

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
int MainWindow::calculateDaysRemaining(const QString& dateFinStr)
{
    QDate dateFin = parseProjetDate(dateFinStr);
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

void MainWindow::on_statsBudgetButton_clicked()
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

    afficherDiagrammeCirculaireProjet();
}

void MainWindow::afficherDiagrammeCirculaireProjet()
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

void MainWindow::on_chatbotButton_clicked()
{
    qDebug() << "🔄 Bouton chatbot cliqué !";

    // Vérifier si le chatbot existe déjà
    if (!chatBotProjet) {
        qDebug() << "➕ Création d'un nouveau ChatBot...";
        chatBotProjet = new ChatBot(this);

        // Configuration de la fenêtre
        chatBotProjet->setWindowTitle("🤖 Assistant IA - ARTEMIA");
        chatBotProjet->setMinimumSize(500, 600);
        chatBotProjet->setAttribute(Qt::WA_DeleteOnClose, false);

        qDebug() << "✅ ChatBot créé avec succès";
    } else {
        qDebug() << "📱 ChatBot existe déjà, réutilisation...";

        // Vérifier si la fenêtre est cachée
        if (!chatBotProjet->isVisible()) {
            qDebug() << "👁️ ChatBot était caché, on le montre";
        } else {
            qDebug() << "👁️ ChatBot est déjà visible";
        }
    }

    // Afficher le ChatBot
    chatBotProjet->show();
    chatBotProjet->raise();
    chatBotProjet->activateWindow();

    // Forcer le focus
    chatBotProjet->setFocus();

    qDebug() << "✅ ChatBot affiché - Visible:" << chatBotProjet->isVisible()
             << "Actif:" << chatBotProjet->isActiveWindow();
}
// ==================== EXPORT PDF ====================
void MainWindow::on_exportPdfButton_clicked()
{
    exporterTableauPDFProjet();
}

void MainWindow::exporterTableauPDFProjet()
{
    // CORRECTION : Utiliser ui->tableWidget_2 au lieu de ui->tableWidget
    if (ui->tableWidget_2->rowCount() == 0) {
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

    // CORRECTION : Utiliser ui->tableWidget_2
    cursor.insertText(QString("Nombre total de projets: %1\n").arg(ui->tableWidget_2->rowCount()));

    double totalBudgetPrevu = 0;
    double totalBudgetRealise = 0;
    int projetsEnCours = 0;
    int projetsTermines = 0;

    // CORRECTION : Utiliser ui->tableWidget_2
    for (int row = 0; row < ui->tableWidget_2->rowCount(); ++row) {
        double budgetPrevu = ui->tableWidget_2->item(row, 1)->text().toDouble();
        double budgetRealise = ui->tableWidget_2->item(row, 2)->text().toDouble();
        QString statut = ui->tableWidget_2->item(row, 5)->text();

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

    // CORRECTION : Utiliser ui->tableWidget_2
    QTextTable *table = cursor.insertTable(ui->tableWidget_2->rowCount() + 1, ui->tableWidget_2->columnCount(), tableFormat);

    QTextCharFormat headerFormat;
    headerFormat.setFontWeight(QFont::Bold);
    headerFormat.setBackground(QColor(200, 200, 200));
    headerFormat.setForeground(Qt::black);

    // CORRECTION : Utiliser ui->tableWidget_2
    for (int col = 0; col < ui->tableWidget_2->columnCount(); ++col) {
        QTextTableCell headerCell = table->cellAt(0, col);
        QTextCursor headerCursor = headerCell.firstCursorPosition();
        headerCursor.setCharFormat(headerFormat);
        headerCursor.insertText(ui->tableWidget_2->horizontalHeaderItem(col)->text());
    }

    QTextCharFormat cellFormat;
    cellFormat.setFontPointSize(8);

    // CORRECTION : Utiliser ui->tableWidget_2
    for (int row = 0; row < ui->tableWidget_2->rowCount(); ++row) {
        for (int col = 0; col < ui->tableWidget_2->columnCount(); ++col) {
            QTableWidgetItem *item = ui->tableWidget_2->item(row, col);
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
                                 .arg(ui->tableWidget_2->rowCount())
                                 .arg(totalBudgetPrevu, 0, 'f', 2)
                                 .arg(QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm")));

    qDebug() << "✅ PDF exporté:" << fileName;
}
// ==================== FONCTIONS PROJETS MANQUANTES ====================

void MainWindow::setupProjetTable()
{
    // Cette fonction appelle simplement setupProjetTableWidget()
    setupProjetTableWidget();
}

void MainWindow::refreshProjetTable()
{
    // CORRECTION : Appeler refreshProjetTableWidget() au lieu de rien faire
    refreshProjetTableWidget();

    // Ajouter du debug pour vérifier
    qDebug() << "🔄 refreshProjetTable() appelé - Lignes affichées:" << ui->tableWidget->rowCount();
}
void MainWindow::on_btnAjouterProjet_clicked()
{
    QMessageBox::information(this, "Projets", "Ajouter projet - Utilisez le bouton 'Ajouter Projet' sur la page projets");
}

void MainWindow::on_btnModifierProjet_clicked()
{
    QMessageBox::information(this, "Projets", "Modifier projet - Utilisez le bouton 'Modifier' sur la page projets");
}

void MainWindow::on_btnSupprimerProjet_clicked()
{
    QMessageBox::information(this, "Projets", "Supprimer projet - Utilisez le bouton 'Supprimer' sur la page projets");
}

void MainWindow::on_btnTriBudgetProjet_clicked()
{
    QMessageBox::information(this, "Projets", "Tri par budget - Utilisez le bouton 'Tri Budget' sur la page projets");
}

void MainWindow::on_btnTriDateProjet_clicked()
{
    QMessageBox::information(this, "Projets", "Tri par date - Utilisez le bouton 'Tri Date' sur la page projets");
}

void MainWindow::on_btnRafraichirProjet_clicked()
{
    QMessageBox::information(this, "Projets", "Rafraîchir - Utilisez le bouton 'Rafraîchir' sur la page projets");
}

void MainWindow::on_btnAnnulerModifProjet_clicked()
{
    QMessageBox::information(this, "Projets", "Annuler modification - Utilisez le bouton 'Annuler' sur la page projets");
}

void MainWindow::on_tableProjets_cellClicked(int row, int column)
{
    Q_UNUSED(row);
    Q_UNUSED(column);
    QMessageBox::information(this, "Projets", "Clic sur cellule projet");
}
