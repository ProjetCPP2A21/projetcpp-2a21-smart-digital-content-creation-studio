#include "gestionclient.h"
#include "ui_gestionclient.h"
#include "client.h"
#include <QMessageBox>
#include <QSqlError>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QFileDialog>
#include <QTextStream>
#include <QLabel>
#include <QDate>
#include <QPdfWriter>
#include <QPainter>

#include <QtCharts/QChartView>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QtCharts/QChart>
#include <QVBoxLayout>




//-----------------ARDUINO----------------------
#include <QSerialPort>     // // Arduino
#include <QSerialPortInfo> // // Liste des ports COM





GestionClient::GestionClient(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GestionClient)
{
    ui->setupUi(this);
    refreshTable();





    //-----------------ARDUINO----------------------
    // === Connexion Arduino ===
    arduino = new QSerialPort(this);

    // // auto-détection du port Arduino
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        if (info.description().contains("Arduino") ||
            info.manufacturer().contains("Arduino"))
        {
            arduino->setPort(info);
            break;
        }
    }

    arduino->setBaudRate(QSerialPort::Baud9600);

    if (arduino->open(QSerialPort::ReadWrite)) {
        // // si Arduino connecté
        connect(arduino, &QSerialPort::readyRead, this, &GestionClient::readArduinoData);
        qDebug() << "Arduino connecté.";
    } else {
        qDebug() << "Arduino NON détecté.";
    }

}



GestionClient::~GestionClient()
{
    delete ui;
}



void GestionClient::refreshTable()
{
    Client c;
    QSqlQueryModel *model = c.afficher();
    ui->tableClients_6->setRowCount(0);
    ui->tableClients_6->setColumnCount(9);

    QStringList headers = {"Activité", "ID", "Nom", "Email", "Téléphone",
                           "Secteur d'activité", "Pays", "Date d'inscription", "ID Empreinte"};

    ui->tableClients_6->setHorizontalHeaderLabels(headers);

    QDate today = QDate::currentDate();

    for (int i = 0; i < model->rowCount(); i++) {
        ui->tableClients_6->insertRow(i);

        // Vérifie si le client est inactif (>30 jours)
        QDate dateInscription = model->data(model->index(i, 6)).toDate();
        bool inactif = (dateInscription.daysTo(today) > 30);

        // Création d’une bulle vert pour client actif et rouge pour inactif
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

        // Remplissage des colonnes suivantes
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






//LE CLIENT S'AFFICHE QUAND ON CLIQUE SUR SON ID
void GestionClient::on_tableClients_6_cellClicked(int row, int column)
{
    refreshTable();
    Q_UNUSED(column);
    ui->leId_6->setText(ui->tableClients_6->item(row, 1)->text());
    ui->leNom_6->setText(ui->tableClients_6->item(row, 2)->text());
    ui->leEmail_6->setText(ui->tableClients_6->item(row, 3)->text());
    ui->leTel_6->setText(ui->tableClients_6->item(row, 4)->text());
    ui->cbSecteur_6->setCurrentText(ui->tableClients_6->item(row, 5)->text());
    ui->cbPays_6->setCurrentText(ui->tableClients_6->item(row, 6)->text());
    ui->deDate_6->setDate(QDate::fromString(ui->tableClients_6->item(row, 7)->text(), "yyyy-MM-dd"));
}







// === AJOUTER ===
void GestionClient::on_btnAjouter_3_clicked()
{
    QString idStr = ui->leId_6->text().trimmed();
    QString nom = ui->leNom_6->text().trimmed();
    QString email = ui->leEmail_6->text().trimmed();
    QString tel = ui->leTel_6->text().trimmed();
    QString secteur = ui->cbSecteur_6->currentText();
    QString pays = ui->cbPays_6->currentText();
    QDate dateInscription = ui->deDate_6->date();

    // --- Contrôles de saisie ---
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
        QMessageBox::warning(this, "Erreur", "Veuillez saisir une adresse e-mail valide (ex: nom@mail.com).");
        return;
    }
    if (!regexTel.match(tel).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Le numéro de téléphone doit contenir exactement 8 chiffres.");
        return;
    }

    int id = idStr.toInt();

    // Vérification doublon
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

    // Ajout du client
    Client c(id, nom, email, tel, secteur, pays, dateInscription);
    if (c.ajouter()) {
        QMessageBox::information(this, "Succès", "Client ajouté avec succès !");
        refreshTable();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout du client !");
    }
}







//Modifier client
void GestionClient::on_btnModifier_3_clicked()
{
    QString idStr = ui->leId_6->text().trimmed();
    QString nom = ui->leNom_6->text().trimmed();
    QString email = ui->leEmail_6->text().trimmed();
    QString tel = ui->leTel_6->text().trimmed();
    QString secteur = ui->cbSecteur_6->currentText();
    QString pays = ui->cbPays_6->currentText();
    QDate dateInscription = ui->deDate_6->date();

    // --- Contrôles de saisie ---
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
        QMessageBox::warning(this, "Erreur", "Veuillez saisir une adresse e-mail valide (ex: nom@mail.com).");
        return;
    }
    if (!regexTel.match(tel).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Le numéro de téléphone doit contenir exactement 8 chiffres.");
        return;
    }

    int id = idStr.toInt();

    // Vérification doublon
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

    // Modification
    Client c(id, nom, email, tel, secteur, pays, dateInscription);
    if (c.modifier()) {
        QMessageBox::information(this, "Succès", "Client modifié avec succès !");
        refreshTable();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la modification du client !");
    }
}







// SUPPRIMER
void GestionClient::on_btnSupprimer_3_clicked()
{
    if (ui->leId_6->text().isEmpty()) {
        QMessageBox::warning(this, "Attention", "Renseigne un ID valide à supprimer.");
        return;
    }

    int id = ui->leId_6->text().toInt();
    Client c;

    if (c.supprimer(id)) {
        QMessageBox::information(this, "Succès", "Client supprimé avec succès !");
        refreshTable();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la suppression du client !");
    }
}







// RECHERCHE
void GestionClient::on_leSearch_6_textChanged(const QString &text)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM CLIENTT "
                  "WHERE LOWER(SECTEURACTIVITE) LIKE LOWER(:rech) "
                  "ORDER BY IDCLIENT ASC");

    query.bindValue(":rech", "%" + text + "%");

    if (!query.exec()) {
        qDebug() << " Erreur recherche :" << query.lastError().text();
        return;
    }

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







// EXPORT PDF
void GestionClient::on_pushButton_7_clicked()
{
    Client c;
    QSqlQueryModel *model = c.afficher();

    QString filePath = QFileDialog::getSaveFileName(this, "Exporter PDF", "", "PDF (*.pdf)");
    if (filePath.isEmpty()) return;

    QPdfWriter pdf(filePath);
    pdf.setPageSize(QPageSize(QPageSize::A4));
    pdf.setResolution(300);

    QPainter painter(&pdf);
    painter.setRenderHint(QPainter::Antialiasing);

    QColor mauve(147, 112, 219), orange(255, 140, 0), mauveLight(230, 220, 240), orangeLight(255, 245, 230);

    // TITRE
    painter.setFont(QFont("Arial", 18, QFont::Bold));
    painter.setPen(orange);
    painter.drawText(QRect(0, 200, pdf.width(), 100), Qt::AlignCenter, "Liste des clients");
    painter.setPen(QPen(mauve, 3));
    painter.drawLine(200, 350, pdf.width() - 200, 350);

    // TABLEAU
    int x = 100, y = 500, h = 90;
    int w[] = {250, 300, 450, 250, 260, 170, 220}; // ID: 250, Tél: 250
    QStringList headers = {"ID", "Nom", "Email", "Tél", "Secteur", "Pays", "Date"};

    // EN-TÊTE
    painter.setFont(QFont("Arial", 10, QFont::Bold));
    painter.setBrush(mauve);
    painter.drawRect(x, y, w[0]+w[1]+w[2]+w[3]+w[4]+w[5]+w[6], h);
    painter.setPen(Qt::white);
    int cx = x;
    for (int i = 0; i < 7; i++) {
        painter.drawText(QRect(cx, y, w[i], h), Qt::AlignCenter, headers[i]);
        cx += w[i];
    }
    y += h;

    // DONNÉES
    painter.setFont(QFont("Arial", 9));
    QDate today = QDate::currentDate();
    for (int i = 0; i < model->rowCount(); ++i) {
        bool inactif = model->data(model->index(i, 6)).toDate().daysTo(today) > 30;
        QColor bg = inactif ? QColor(255, 220, 220) : (i % 2 == 0 ? mauveLight : orangeLight);

        painter.fillRect(x, y, w[0]+w[1]+w[2]+w[3]+w[4]+w[5]+w[6], h, bg);
        painter.setPen(inactif ? QColor(200, 0, 0) : Qt::black);

        cx = x;
        for (int j = 0; j < 7; j++) {
            QString val = (j == 6) ? model->data(model->index(i, j)).toDate().toString("dd/MM/yyyy")
                                   : model->data(model->index(i, j)).toString();
            painter.drawText(QRect(cx + 5, y, w[j] - 10, h), Qt::AlignVCenter | Qt::AlignLeft, val);
            cx += w[j];
        }
        y += h;
        if (y > pdf.height() - 400) { pdf.newPage(); y = 200; }
    }

    // FOOTER
    painter.setFont(QFont("Arial", 9, -1, true));
    painter.setPen(orange);
    painter.drawText(100, pdf.height() - 150, "Généré le : " + QDate::currentDate().toString("dd/MM/yyyy"));

    painter.end();
    QMessageBox::information(this, "PDF", "Exporté !");
}






//TRIER
void GestionClient::on_pushButton_9_clicked()
{
    // Création du modèle trié (ordre croissant sur la date d’inscription)
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM CLIENTT ORDER BY DATEINSCRIPTION ASC");

    // Réinitialisation du tableau
    ui->tableClients_6->setRowCount(0);
    ui->tableClients_6->setColumnCount(8);

    QStringList headers = {
        "Activité", "ID", "Nom", "Email",
        "Téléphone", "Secteur d'activité", "Pays", "Date d'inscription"
    };
    ui->tableClients_6->setHorizontalHeaderLabels(headers);

    QDate today = QDate::currentDate();

    // Remplissage
    for (int i = 0; i < model->rowCount(); i++) {
        ui->tableClients_6->insertRow(i);

        // Calcul activité/inactivité
        QDate dateInscription = model->data(model->index(i, 6)).toDate();
        bool inactif = (dateInscription.daysTo(today) > 30);

        // Bulle rouge/verte
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

        // Remplir les colonnes
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

    QMessageBox::information(this, "Tri effectué",
                             "Le tableau a été trié par date d'inscription (ordre croissant).");
}








//STATISTIQUES
void GestionClient::on_pushButton_8_clicked()
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
    QVector<int> dataNouveaux(12, 0);
    QVector<int> dataAnciens(12, 0);

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

    for (int i = 0; i < 12; ++i) {
        categories << QLocale::system().monthName(i + 1);
    }

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

    QFont font("Segoe UI", 10, QFont::Bold);
    chart->setTitleFont(font);

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    axisX->setLabelsColor(QColor("#14172D"));
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    //  Axe Y corrigé : entiers seulement
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






//CLIENTS INACTIFS
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QMessageBox>
#include <QDate>
#include <QSqlQueryModel>
#include <QPageSize>
#include <QColor>

void GestionClient::on_pushButton_6_clicked()
{
    Client c;
    QSqlQueryModel *model = c.afficher();
    QDate today = QDate::currentDate();

    QString filePath = QFileDialog::getSaveFileName(this, "Exporter PDF des clients inactifs", "", "Fichiers PDF (*.pdf)");
    if (filePath.isEmpty()) return;

    QPdfWriter pdf(filePath);
    pdf.setPageSize(QPageSize(QPageSize::A4));
    pdf.setResolution(300);

    QPainter painter(&pdf);
    painter.setRenderHint(QPainter::Antialiasing);

    // === COULEURS DU THÈME ===
    QColor mauveHeader(147, 112, 219);      // Mauve pour l'en-tête
    QColor orangeAccent(255, 140, 0);       // Orange pour les accents
    QColor mauveLight(230, 220, 240);       // Mauve clair pour les lignes alternées
    QColor orangeLight(255, 245, 230);      // Orange clair

    // === TITRE ===
    QFont titleFont("Arial", 18, QFont::Bold);
    painter.setFont(titleFont);
    painter.setPen(orangeAccent);
    painter.drawText(QRect(0, 200, pdf.width(), 100), Qt::AlignCenter, "Liste des clients inactifs (> 30 jours)");

    painter.setPen(QPen(mauveHeader, 3));
    painter.drawLine(200, 350, pdf.width() - 200, 350);

    // === TABLEAU ===
    int startX = 200;
    int y = 500;
    int rowHeight = 100;

    int colIdWidth = 180;
    int colNomWidth = 450;
    int colEmailWidth = 700;
    int colDateWidth = 570;  // Agrandi pour "Date d'inscription"

    // EN-TÊTES
    QFont headerFont("Arial", 12, QFont::Bold);
    painter.setFont(headerFont);
    painter.setPen(Qt::white);
    painter.setBrush(mauveHeader);  //Fond mauve

    // Fond pour l'en-tête
    painter.drawRect(startX, y, colIdWidth + colNomWidth + colEmailWidth + colDateWidth, rowHeight);

    painter.setBrush(Qt::NoBrush);
    painter.setPen(QPen(mauveHeader, 2));

    // Bordures de l'en-tête
    painter.drawRect(startX, y, colIdWidth, rowHeight);
    painter.drawRect(startX + colIdWidth, y, colNomWidth, rowHeight);
    painter.drawRect(startX + colIdWidth + colNomWidth, y, colEmailWidth, rowHeight);
    painter.drawRect(startX + colIdWidth + colNomWidth + colEmailWidth, y, colDateWidth, rowHeight);

    // Texte des en-têtes (centré verticalement)
    painter.setPen(Qt::white);
    painter.drawText(QRect(startX, y, colIdWidth, rowHeight), Qt::AlignCenter, "ID");
    painter.drawText(QRect(startX + colIdWidth, y, colNomWidth, rowHeight), Qt::AlignCenter, "Nom");
    painter.drawText(QRect(startX + colIdWidth + colNomWidth, y, colEmailWidth, rowHeight), Qt::AlignCenter, "Email");
    painter.drawText(QRect(startX + colIdWidth + colNomWidth + colEmailWidth, y, colDateWidth, rowHeight), Qt::AlignCenter, "Date d'inscription");

    //DONNÉES
    QFont bodyFont("Arial", 10);
    painter.setFont(bodyFont);
    y += rowHeight;

    int ligne = 0;

    for (int i = 0; i < model->rowCount(); ++i) {
        QDate date = model->data(model->index(i, 6)).toDate();

        if (date.daysTo(today) > 30) {
            QString id = model->data(model->index(i, 0)).toString();
            QString nom = model->data(model->index(i, 1)).toString();
            QString email = model->data(model->index(i, 2)).toString();
            QString dateStr = date.toString("dd/MM/yyyy");

            // Fond alterné avec les couleurs du thème
            if (ligne % 2 == 0) {
                painter.fillRect(startX, y, colIdWidth + colNomWidth + colEmailWidth + colDateWidth, rowHeight, mauveLight);
            } else {
                painter.fillRect(startX, y, colIdWidth + colNomWidth + colEmailWidth + colDateWidth, rowHeight, orangeLight);
            }

            // Bordures
            painter.setPen(QPen(mauveHeader, 1));
            painter.drawRect(startX, y, colIdWidth, rowHeight);
            painter.drawRect(startX + colIdWidth, y, colNomWidth, rowHeight);
            painter.drawRect(startX + colIdWidth + colNomWidth, y, colEmailWidth, rowHeight);
            painter.drawRect(startX + colIdWidth + colNomWidth + colEmailWidth, y, colDateWidth, rowHeight);

            // Texte centré verticalement dans chaque cellule
            painter.setPen(Qt::black);
            painter.drawText(QRect(startX + 20, y, colIdWidth - 40, rowHeight), Qt::AlignVCenter | Qt::AlignLeft, id);
            painter.drawText(QRect(startX + colIdWidth + 20, y, colNomWidth - 40, rowHeight), Qt::AlignVCenter | Qt::AlignLeft, nom);
            painter.drawText(QRect(startX + colIdWidth + colNomWidth + 20, y, colEmailWidth - 40, rowHeight), Qt::AlignVCenter | Qt::AlignLeft, email);
            painter.drawText(QRect(startX + colIdWidth + colNomWidth + colEmailWidth + 20, y, colDateWidth - 40, rowHeight), Qt::AlignVCenter | Qt::AlignLeft, dateStr);

            y += rowHeight;
            ligne++;

            // Nouvelle page si nécessaire
            if (y > pdf.height() - 300) {
                pdf.newPage();
                y = 200;
            }
        }
    }

    // === Date de génération ===
    QFont footerFont("Arial", 9);
    footerFont.setItalic(true);
    painter.setFont(footerFont);
    painter.setPen(orangeAccent);
    painter.drawText(200, pdf.height() - 150, "Généré le : " + QDate::currentDate().toString("dd/MM/yyyy"));

    painter.end();
    QMessageBox::information(this, "PDF", " PDF généré avec succès !");
}







//-----------------ARDUINO----------------------


//LECTURE ARDUINO
void GestionClient::readArduinoData()
{
    if (!arduino || !arduino->isOpen()) return;

    QString data = arduino->readAll().trimmed();
    qDebug() << "[Arduino → Qt] " << data;

    // 1️⃣ Détection d’une empreinte : Arduino → Qt
    if (data.startsWith("FINGER:")) {
        QString id = data.mid(7).trimmed();
        activerClient(id);
        return;
    }

    // 2️⃣ Nombre d’empreintes dans le capteur : Arduino → Qt
    if (data.startsWith("TEMPLATE_COUNT:")) {
        QString nb = data.mid(15).trimmed();
        int count = nb.toInt();
        verifierSynchronisation(count);  // Compare Oracle ↔ Capteur
        return;
    }

    // 3️⃣ Message SYSTEM_READY (juste pour info)
    if (data == "SYSTEM_READY") {
        qDebug() << "[INFO] Arduino prêt.";
        return;
    }
}




//ACTIVATION CLIENT
void GestionClient::activerClient(QString id)
{
    // // mise à jour SQL : mettre le client comme actif aujourd’hui
    QSqlQuery query;
    query.prepare("UPDATE CLIENTT SET DATEINSCRIPTION = SYSDATE WHERE IDCLIENT = :id");
    query.bindValue(":id", id);

    if (query.exec()) {
        QMessageBox::information(this, "Emprunte OK", "Client " + id + " reconnu !");
        refreshTable();   // // rafraîchit les bulles vertes
    } else {
        QMessageBox::warning(this, "Erreur", "Client introuvable !");
    }
}




//ARDUINO : QT_READY
void GestionClient::envoyerQtReady()
{
    if (!arduino || !arduino->isOpen()) return;

    arduino->write("QT_READY\n");
    qDebug() << "[QT → Arduino] QT_READY envoyé";
}




//ARDUINO : SYNCHRONISATION
void GestionClient::verifierSynchronisation(int templateCount)
{
    QSqlQuery q;
    q.prepare("SELECT COUNT(*) FROM CLIENTT WHERE FINGERID IS NOT NULL");
    q.exec();
    q.next();
    int nbOracle = q.value(0).toInt();

    if (!arduino || !arduino->isOpen()) return;

    if (nbOracle == templateCount) {
        arduino->write("SYNC_OK\n");
        qDebug() << "[QT → Arduino] SYNC_OK";
    } else {
        arduino->write("SYNC_WARNING\n");
        qDebug() << "[QT → Arduino] SYNC_WARNING";
    }
}


