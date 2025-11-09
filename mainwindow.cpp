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

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //  Style uniforme pour tous les boutons
    this->setStyleSheet("QPushButton { background:#2A2E63; color:#EDEAF9; border:1px solid #4B4F87; border-radius:8px; padding:6px 12px; }"
                        "QPushButton:hover { background:#3A3F7A; }"
                        "QPushButton:pressed { background:#1B1D3F; }");


    // === Connexions des boutons de navigation ===
    connect(ui->pushButton_projet, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentWidget(ui->page_projet);
        setActiveButton(ui->pushButton_projet);
    });
    connect(ui->pushButton_client, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentWidget(ui->page_client);
        setActiveButton(ui->pushButton_client);
    });
    connect(ui->pushButton_employe, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentWidget(ui->page_employe);
        setActiveButton(ui->pushButton_employe);
    });
    connect(ui->pushButton_media, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentWidget(ui->page_media);
        setActiveButton(ui->pushButton_media);
    });
    connect(ui->pushButton_feedback, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentWidget(ui->page_feedback);
        setActiveButton(ui->pushButton_feedback);
    });
    connect(ui->pushButton_categorie, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentWidget(ui->page_categorie);
        setActiveButton(ui->pushButton_categorie);
    });
    connect(ui->pushButton_quitter, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget_principale->setCurrentWidget(ui->page);
    });

    // === Gestion du login ===
    connect(ui->lineEdit_mdp_login, &QLineEdit::returnPressed, this, [=]() {
        ui->stackedWidget_principale->setCurrentIndex(1);
    });
    connect(ui->pushButton_mdp_oublie, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget_login->setCurrentWidget(ui->page_mdp_oublie);
    });
    connect(ui->lineEdit_reponse_2, &QLineEdit::returnPressed, this, [=]() {
        ui->stackedWidget_login->setCurrentWidget(ui->page_nouveau_mdp);
    });
    connect(ui->pushButton_valide_mdp, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget_login->setCurrentWidget(ui->page_login);
    });

    // === Logos ===
    QPixmap pix(":/logo.png");
    if (!pix.isNull())
        ui->logo->setPixmap(pix.scaled(ui->logo->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ui->logo->setScaledContents(true);

    QPixmap pix_bg(":/background+logo.png");
    if (!pix_bg.isNull())
        ui->background->setPixmap(pix_bg.scaled(ui->background->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ui->background->setScaledContents(true);

//################             Gestion_employes           ###################///////////

    ui->tableWidgetEmployes->setEditTriggers(QAbstractItemView::DoubleClicked | QAbstractItemView::EditKeyPressed);

    //Connecter le signal "itemChanged" au slot
    connect(ui->tableWidgetEmployes, &QTableWidget::itemChanged, this, &MainWindow::onItemChanged);

    // Connexions boutons CRUD
    connect(ui->Button_ajouter, &QPushButton::clicked, this, &MainWindow::ajouterEmploye);
    connect(ui->Button_supprimer_2, &QPushButton::clicked, this, &MainWindow::supprimerEmploye);
    connect(ui->Button_rechercher, &QPushButton::clicked, this, &MainWindow::rechercherEmploye);
    connect(ui->Button_export, &QPushButton::clicked, this, &MainWindow::exportEmployes);

    // Configuration du tableau
    ui->tableWidgetEmployes->setColumnCount(5);
    QStringList headers = {"ID", "Nom", "Prénom", "Email", "Poste"};
    ui->tableWidgetEmployes->setHorizontalHeaderLabels(headers);
    ui->tableWidgetEmployes->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidgetEmployes->horizontalHeader()->setStretchLastSection(false);

    // Affichage initial depuis DB
    Employe tempEmp;  // Instance temporaire pour appeler les méthodes DB
    QSqlQueryModel *initialModel = tempEmp.afficher();
    afficherEmployes(initialModel);
    delete initialModel;

    QPushButton *buttonTri = ui->groupBox_recherche->findChild<QPushButton*>("Button_tri");
    if (buttonTri) {
        connect(buttonTri, &QPushButton::clicked, this, &MainWindow::trierParPoste);
        qDebug() << "Button_tri connecté avec succès.";
    } else {
        qDebug() << "Erreur : Button_tri non trouvé dans groupBox_recherche !";
        //ui->statusbar->showMessage("Erreur : Bouton de tri non trouvé !");
    }

    afficherStatistiques();  // Appel initial des stats depuis DB

    QPixmap pix2(":/banner.png");
    if (pix2.isNull()) {
        qDebug() << "Impossible de charger l'image !";
    } else {
        ui->banner->setPixmap(pix2.scaled(
            ui->banner->size(),
            Qt::KeepAspectRatio,
            Qt::SmoothTransformation
            ));
    }
    ui->banner->setScaledContents(true);

    QLineEdit *lineEditRecherche = ui->groupBox_recherche->findChild<QLineEdit*>("lineEdit_recherche");
    if (lineEditRecherche) {
        lineEditRecherche->setPlaceholderText("ID employé");
        qDebug() << "Placeholder ajouté à lineEdit_recherche.";
    } else {
        qDebug() << "Erreur : lineEdit_recherche non trouvé dans groupBox_recherche !";
        //ui->statusbar->showMessage("Erreur : Champ de recherche non trouvé !");
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setActiveButton(QPushButton *btn)
{
    //  Réinitialiser sans écraser le style global
    ui->pushButton_projet->setStyleSheet("");
    ui->pushButton_client->setStyleSheet("");
    ui->pushButton_employe->setStyleSheet("");
    ui->pushButton_media->setStyleSheet("");
    ui->pushButton_feedback->setStyleSheet("");
    ui->pushButton_categorie->setStyleSheet("");

    //  Bouton actif (orange)
    btn->setStyleSheet("background-color:#FF8C00; color:black; font-weight:bold;");
}


//#######################          gestion_employes            #####################//
void MainWindow::ajouterEmploye() {
    QString nom = ui->lineEdit_nom->text();
    QString prenom = ui->lineEdit_prenom->text();
    QString mdp = ui->lineEdit_mdp->text();
    QString email = ui->lineEdit_email->text();
    QString poste = ui->comboBox->currentText();
    QString questionSecrete = ui->comboBox_q->currentText();
    QString reponseSecrete = ui->lineEdit_reponse->text();

    // Vérifier les champs obligatoires
    if (nom.isEmpty() || prenom.isEmpty() || email.isEmpty() || mdp. isEmpty() || reponseSecrete. isEmpty()) {
        QMessageBox::warning(this, "Champs manquants",
                             "Veuillez remplir tous les champs");
        return;
    }

    // Vérifier la validité de l'email
    QRegularExpression emailRegex(
        "^[A-Za-z0-9._%+-]+@(gmail\\.com|yahoo\\.fr|outlook\\.com)$",
        QRegularExpression::CaseInsensitiveOption);

    if (!emailRegex.match(email).hasMatch()) {
        QMessageBox::warning(this, "Email invalide",
                             "Veuillez entrer une adresse email valide");
        return;
    }

    // Créer et remplir l'objet Employe
    Employe emp;
    emp.setNom(nom);
    emp.setPrenom(prenom);
    emp.setMdp(mdp);
    emp.setEmail(email);
    emp.setPoste(poste);
    emp.setQuestionSecrete(questionSecrete);
    emp.setReponseSecrete(reponseSecrete);

    // Tenter l'ajout
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

  // fonction modifier
void MainWindow::onItemChanged(QTableWidgetItem *item) {
    // Vérif: Si pas de tableau, on sort
    QTableWidget *tableWidget = ui->tableWidgetEmployes;
    if (!tableWidget || !item) {
        return;
    }

    int row = item->row();  // Ligne modifiée
    int col = item->column();  // Colonne modifiée

    // Récup l'ID de la ligne ( colonne 0 non modifiable)
    QTableWidgetItem *idItem = tableWidget->item(row, 0);
    if (!idItem) {
        //ui->statusbar->showMessage("Erreur : Impossible de récupérer l'ID !");
        return;
    }
    int id_employe = idItem->text().toInt();
    if (id_employe <= 0) {
        //ui->statusbar->showMessage("ID invalide pour la modification !");
        return;
    }

    // Nouvelle valeur tapée par l'utilisateur
    QString newValue = item->text().trimmed();  // Enlève les espaces inutiles
    if (newValue.isEmpty()) {
        //ui->statusbar->showMessage("Valeur vide non autorisée !");
        return;  // Empêche les champs vides
    }

    // Détermine QUEL champ de la DB modifier (selon la colonne)
    QString fieldName;  // Nom de la colonne en DB
    switch (col) {
    case 1: fieldName = "nom"; break;      // Colonne 1 = Nom
    case 2: fieldName = "prenom"; break;   // Colonne 2 = Prénom
    case 3: fieldName = "email"; break;    // Colonne 3 = Email
    case 4: fieldName = "poste"; break;    // Colonne 4 = Poste
    default:
        //ui->statusbar->showMessage("Colonne non modifiable ! (ex. ID)");
        return;  // Protège l'ID (colonne 0)
    }

    // MISE À JOUR EN BASE DE DONNÉES
    QSqlQuery query;
    // Requête dynamique : UPDATE employe SET [champ] = [nouvelle_valeur] WHERE id = [id]
    query.prepare(QString("UPDATE employe SET %1 = :newValue WHERE id_employe = :id").arg(fieldName));
    query.bindValue(":newValue", newValue);  // Lie la nouvelle valeur
    query.bindValue(":id", id_employe);      // Lie l'ID

    if (query.exec()) {  // Exécute la requête
        if (query.numRowsAffected() > 0) {  // Vérifie si une ligne a été modifiée
            //ui->statusbar->showMessage(QString("Employé %1 (%2) mis à jour : %3").arg(id_employe).arg(fieldName).arg(newValue));
            qDebug() << "Succès DB : ID" << id_employe << "->" << fieldName << "=" << newValue;

            afficherStatistiques();
        } else {
            //ui->statusbar->showMessage("Aucune modification (ID introuvable ?)");
        }
    } else {
        // Erreur DB
        qDebug() << "Erreur UPDATE :" << query.lastError().text();
        //ui->statusbar->showMessage("Erreur DB : Modification annulée !");
        QMessageBox::warning(this, "Erreur", "Impossible de sauvegarder. Vérifiez la console.");

    }
}

// Supprimer
void MainWindow::supprimerEmploye() {
    bool ok;
    int id_employe = ui->lineEdit_id_supp->text().toInt(&ok); // Vérifie la conversion en entier
    if (!ok || id_employe <= 0) {
        //ui->statusbar->showMessage("Erreur : Veuillez entrer un ID valide !");
        return;
    }

    Employe emp;
    if (emp.supprimer(id_employe)) {
        ui->lineEdit_id_supp->clear(); // Vider le champ après suppression
        //ui->statusbar->showMessage("Employé supprimé avec succès !");
        // Rafraîchir affichage
        QSqlQueryModel *model = emp.afficher();
        afficherEmployes(model);
        delete model;
        afficherStatistiques();
    } else {
        //ui->statusbar->showMessage("Employé introuvable ou erreur suppression !");
    }
}

void MainWindow::rechercherEmploye() {
    QString critere = ui->lineEdit_recherche->text();

    // Vérifier si la saisie est vide
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

    if (!model) {
        qDebug() << "Modèle nul pour affichage !";
        return;
    }

    for (int i = 0; i < model->rowCount(); ++i) {
        ui->tableWidgetEmployes->insertRow(i);

        for (int j = 0; j < 5 && j < model->columnCount(); ++j) {
            QVariant data = model->data(model->index(i, j));
            ui->tableWidgetEmployes->setItem(i, j, new QTableWidgetItem(data.toString()));
        }
    }

    qDebug() << "Affichage de" << model->rowCount() << "employés.";
}

void MainWindow::trierParPoste() {
    Employe emp;
    QSqlQueryModel *model = new QSqlQueryModel();
    // Query avec ORDER BY
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

    if (fileName.isEmpty()) {
        return;
    }

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Erreur", "Impossible d'ouvrir le fichier.");
        return;
    }

    QTextStream out(&file);

    // les en-têtes
    out << "\"ID\";\"Nom\";\"Prénom\";\"Email\";\"Poste\"\n";

    // les données depuis DB
    QSqlQuery query("SELECT id_employe, nom, prenom, email, poste FROM employe");
    if (query.exec()) {
        while (query.next()) {
            out << "\"" << query.value(0).toString() << "\";"
                << "\"" << query.value(1).toString() << "\";"
                << "\"" << query.value(2).toString() << "\";"
                << "\"" << query.value(3).toString() << "\";"
                << "\"" << query.value(4).toString() << "\"\n";
        }
    } else {
        qDebug() << "Erreur query export:" << query.lastError().text();
    }

    file.close();
    QMessageBox::information(this, "Succès", "Liste exportée avec succès !");
}


void MainWindow::afficherStatistiques()
{
    QSqlQuery query;

    if (!query.exec("SELECT poste, COUNT(*) as count FROM employe GROUP BY poste")) {
        qDebug() << "Erreur query stats:" << query.lastError().text();
        //ui->statusbar->showMessage("Erreur lors du calcul des stats !");
        return;
    }

    QMap<QString, int> statsPoste;
    while (query.next()) {
        QString poste = query.value(0).toString();
        int count = query.value(1).toInt();
        if (!poste.isEmpty()) {
            statsPoste[poste] += count;
        }
    }

    if (statsPoste.isEmpty()) {
        //ui->statusbar->showMessage("Aucune donnée pour les statistiques !");
        return;
    }

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
        QColor("#FF7F32"),
        QColor("#FFAA33"),
        QColor("#1A237E"),
        QColor("#512DA8"),
        QColor("#7E57C2"),
        QColor("#3949AB")
    };

    QList<QPair<QString, QColor>> legendItems;
    int colorIndex = 0;
    for (auto it = statsPoste.begin(); it != statsPoste.end(); ++it) {
        QPieSlice *slice = series->append(it.key(), it.value());
        QColor color = palette[colorIndex % palette.size()];
        slice->setPen(QPen(Qt::white, 1));
        slice->setBrush(color); // appliquer couleur
        legendItems.append(qMakePair(it.key(), color));
        colorIndex++;
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setAnimationOptions(QChart::SeriesAnimations);
    chart->legend()->setVisible(false); // Masquer la légende par défaut

    // Définir les labels des slices comme pourcentages (après addSeries pour calculer percentage())
    for (QPieSlice *slice : series->slices()) {
        slice->setLabel(QString("%1%").arg(qRound(slice->percentage() * 100)));
        slice->setLabelVisible(true);
        slice->setLabelPosition(QPieSlice::LabelOutside); // Positionner les labels à l'extérieur avec lignes
    }

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumSize(400, 300);

    // Titre séparé
    QLabel *titleLabel = new QLabel("Répartition des employés par poste");
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setStyleSheet("font-weight: bold; font-size: 14px;");

    // Créer une légende personnalisée avec carrés colorés et textes noirs
    QString legendHtml;
    for (const auto &item : legendItems) {
        if (!legendHtml.isEmpty()) {
            legendHtml += " &nbsp;&nbsp; ";
        }
        legendHtml += QString("<span style='color:%1; font-size: 16px;'>■</span> %2").arg(item.second.name(), item.first);
    }
    QLabel *legendLabel = new QLabel(legendHtml);
    legendLabel->setAlignment(Qt::AlignCenter);

    QVBoxLayout *layout = new QVBoxLayout(ui->statistiques);
    layout->addWidget(titleLabel);
    layout->addWidget(legendLabel);
    layout->addWidget(chartView);
    ui->statistiques->setLayout(layout);
    //ui->statusbar->showMessage(QString("Statistiques affichées : %1 postes uniques.").arg(statsPoste.size()));
}

