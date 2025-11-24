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







GestionClient::GestionClient(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GestionClient)
{
    ui->setupUi(this);
    refreshTable();
    mapWindow = new BubbleMapWindow();



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
    ui->tableClients_6->setColumnCount(8);

    QStringList headers = {"Activité", "ID", "Nom", "Email",
                           "Téléphone", "Secteur d'activité",
                           "Ville", "Date d'inscription"};

    ui->tableClients_6->setHorizontalHeaderLabels(headers);

    QDate today = QDate::currentDate();

    for (int i = 0; i < model->rowCount(); i++) {
        ui->tableClients_6->insertRow(i);

        // état activité (bulle)
        QDate dateInscription = model->data(model->index(i, 6)).toDate();
        // Récupération ID
        int id = model->data(model->index(i, 0)).toInt();

        // On regarde la durée de projet
        QSqlQuery q2;
        q2.prepare("SELECT MAX(DATE_FIN - DATE_DEBUT) FROM PROJET WHERE IDCLIENT = :id");
        q2.bindValue(":id", id);
        q2.exec();
        q2.next();

        int duree = q2.value(0).toInt();
        bool inactif = (duree < 30);


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

    // Vérification doublon ID
    QSqlQuery check;
    check.prepare("SELECT COUNT(*) FROM CLIENTT WHERE IDCLIENT = :id");
    check.bindValue(":id", id);
    check.exec();
    check.next();
    if (check.value(0).toInt() > 0) {
        QMessageBox::warning(this, "Erreur", "Cet ID existe déjà !");
        return;
    }

    // Ajout réel
    Client c(id, nom, email, tel, secteur, pays, dateInscription);
    if (c.ajouter()) {
        QMessageBox::information(this, "Succès", "Client ajouté !");
        refreshTable();

        // Mise à jour MAP
        mapWindow->clearClients();
        QSqlQuery q("SELECT NOM, PAYS FROM CLIENTT");
        while (q.next()) {
            mapWindow->addClient(q.value(0).toString(), q.value(1).toString());
        }
    } else {
        QMessageBox::critical(this, "Erreur", "Échec d'ajout !");
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

    QRegularExpression regexId("^[0-9]{8}$");
    QRegularExpression regexTel("^[0-9]{8}$");
    QRegularExpression regexNom("^[A-Za-zÀ-ÖØ-öø-ÿ\\s]+$");
    QRegularExpression regexEmail("^[\\w._%+-]+@[\\w.-]+\\.[A-Za-z]{2,}$");

    if (!regexId.match(idStr).hasMatch() ||
        !regexNom.match(nom).hasMatch() ||
        !regexEmail.match(email).hasMatch() ||
        !regexTel.match(tel).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Champs invalides !");
        return;
    }

    int id = idStr.toInt();

    QSqlQuery check;
    check.prepare("SELECT COUNT(*) FROM CLIENTT WHERE IDCLIENT = :id");
    check.bindValue(":id", id);
    check.exec();
    check.next();
    if (check.value(0).toInt() == 0) {
        QMessageBox::warning(this, "Erreur", "ID inexistant !");
        return;
    }

    Client c(id, nom, email, tel, secteur, pays, dateInscription);

    if (c.modifier()) {
        QMessageBox::information(this, "Succès", "Client modifié !");
        refreshTable();

        // Mise à jour MAP
        mapWindow->clearClients();
        QSqlQuery q("SELECT NOM, PAYS FROM CLIENTT");
        while (q.next()) {
            mapWindow->addClient(q.value(0).toString(), q.value(1).toString());
        }

    } else {
        QMessageBox::critical(this, "Erreur", "Modification échouée !");
    }
}









// SUPPRIMER
void GestionClient::on_btnSupprimer_3_clicked()
{
    if (ui->leId_6->text().isEmpty()) {
        QMessageBox::warning(this, "Attention", "Renseigne un ID.");
        return;
    }

    int id = ui->leId_6->text().toInt();
    Client c;

    if (c.supprimer(id)) {
        QMessageBox::information(this, "Succès", "Client supprimé !");
        refreshTable();
    } else {
        QMessageBox::critical(this, "Erreur", "Suppression impossible.");
    }
}







// RECHERCHE
void GestionClient::on_leSearch_6_textChanged(const QString &text)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM CLIENTT WHERE LOWER(SECTEURACTIVITE) LIKE LOWER(:rech) ORDER BY IDCLIENT ASC");
    query.bindValue(":rech", "%" + text + "%");
    query.exec();

    ui->tableClients_6->setRowCount(0);
    int row = 0;

    while (query.next()) {
        ui->tableClients_6->insertRow(row);
        for (int col = 0; col < 7; col++) {
            QVariant data = query.value(col);
            QString value = (data.typeId() == QMetaType::QDate)
                                ? data.toDate().toString("yyyy-MM-dd")
                                : data.toString();
            ui->tableClients_6->setItem(row, col + 1, new QTableWidgetItem(value));
        }
        row++;
    }

    ui->tableClients_6->resizeColumnsToContents();
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

    QColor mauve(147, 112, 219), orange(255, 140, 0),
        mauveLight(230, 220, 240), orangeLight(255, 245, 230);

    // TITRE
    painter.setFont(QFont("Arial", 18, QFont::Bold));
    painter.setPen(orange);
    painter.drawText(QRect(0, 200, pdf.width(), 100), Qt::AlignCenter, "Liste des clients");
    painter.setPen(QPen(mauve, 3));
    painter.drawLine(200, 350, pdf.width() - 200, 350);

    // TABLEAU
    int x = 100, y = 500, h = 90;
    int w[] = {250, 300, 450, 250, 260, 170, 220};
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

    // --- DONNÉES ---
    painter.setFont(QFont("Arial", 9));

    for (int i = 0; i < model->rowCount(); ++i) {

        // Récupération ID du client
        int id = model->data(model->index(i, 0)).toInt();

        // Récupération durée max des projets
        QSqlQuery q;
        q.prepare("SELECT MAX(DATE_FIN - DATE_DEBUT) FROM PROJET WHERE IDCLIENT = :id");
        q.bindValue(":id", id);
        q.exec();
        q.next();

        int duree = q.value(0).toInt(); // NULL → 0
        bool inactif = (duree < 30);

        QColor bg = inactif ? QColor(255, 220, 220)
                            : (i % 2 == 0 ? mauveLight : orangeLight);

        painter.fillRect(x, y, w[0]+w[1]+w[2]+w[3]+w[4]+w[5]+w[6], h, bg);
        painter.setPen(inactif ? QColor(200, 0, 0) : Qt::black);

        cx = x;
        for (int j = 0; j < 7; j++) {
            QString val = (j == 6)
            ? model->data(model->index(i, j)).toDate().toString("dd/MM/yyyy")
            : model->data(model->index(i, j)).toString();

            painter.drawText(QRect(cx + 5, y, w[j] - 10, h),
                             Qt::AlignVCenter | Qt::AlignLeft, val);
            cx += w[j];
        }

        y += h;

        if (y > pdf.height() - 400) {
            pdf.newPage();
            y = 200;
        }
    }

    // FOOTER
    painter.setFont(QFont("Arial", 9, -1, true));
    painter.setPen(orange);
    painter.drawText(100, pdf.height() - 150,
                     "Généré le : " + QDate::currentDate().toString("dd/MM/yyyy"));

    painter.end();
    QMessageBox::information(this, "PDF", "Exporté !");
}







//TRIER
void GestionClient::on_pushButton_9_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM CLIENTT ORDER BY DATEINSCRIPTION ASC");

    ui->tableClients_6->setRowCount(0);
    ui->tableClients_6->setColumnCount(8);

    QStringList headers = {
        "Activité", "ID", "Nom", "Email",
        "Téléphone", "Secteur d'activité", "Pays", "Date d'inscription"
    };
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
        bubble->setStyleSheet(QString("border-radius:7px; background-color:%1;")
                                  .arg(inactif ? "#E53935" : "#43A047"));
        layout->addWidget(bubble);
        ui->tableClients_6->setCellWidget(i, 0, cellWidget);

        for (int j = 0; j < model->columnCount(); j++) {
            QVariant data = model->data(model->index(i, j));
            QString value = (data.typeId() == QMetaType::QDate)
                                ? data.toDate().toString("yyyy-MM-dd")
                                : data.toString();
            ui->tableClients_6->setItem(i, j + 1, new QTableWidgetItem(value));
        }
    }

    ui->tableClients_6->resizeColumnsToContents();
}








//STATISTIQUES
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
void GestionClient::on_pushButton_8_clicked()
{
    //-------------------------------------------
    // 1️⃣ Charger tous les secteurs (y compris NULL)
    //-------------------------------------------
    QSqlQuery query;
    query.prepare(R"(
        SELECT SECTEURACTIVITE, COUNT(*) AS total
        FROM CLIENTT
        GROUP BY SECTEURACTIVITE
        ORDER BY total DESC
    )");

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur SQL", query.lastError().text());
        return;
    }

    QList<QString> secteurs;
    QList<int> totaux;
    int totalGlobal = 0;

    while (query.next()) {
        QString secteur = query.value(0).toString().trimmed();
        int count = query.value(1).toInt();

        // 🔥 IGNORE NULL, VIDE, ESPACES, 'NULL', 'null'
        if (secteur.isEmpty() || secteur == " " || secteur.toLower() == "null")
            continue;

        secteurs << secteur;
        totaux << count;
        totalGlobal += count;
    }

    if (secteurs.isEmpty()) {
        QMessageBox::information(
            this, "Info",
            "Aucun secteur valide trouvé.\n"
            "Veuillez ajouter des secteurs dans vos clients."
            );
        return;
    }

    int max = qMin(3, secteurs.size());

    //-------------------------------------------
    // 2️⃣ PIE DONUT PREMIUM
    //-------------------------------------------
    QPieSeries *series = new QPieSeries();
    series->setHoleSize(0.45);
    series->setPieSize(0.90);

    QList<QColor> colors = {
        QColor("#7B1FA2"),   // Purple
        QColor("#FB8C00"),   // Orange
        QColor("#9C27B0")    // Mauve
    };

    for (int i = 0; i < max; i++) {
        QPieSlice *slice = series->append("", totaux[i]);

        // Dégradé PREMIUM
        QLinearGradient grad;
        grad.setStart(0, 0);
        grad.setFinalStop(1, 1);
        grad.setColorAt(0, colors[i].lighter(130));
        grad.setColorAt(1, colors[i].darker(110));
        slice->setBrush(grad);

        // Séparation blanche
        slice->setPen(QPen(Qt::white, 4));

        // Animation hover
        connect(slice, &QPieSlice::hovered, slice, [slice](bool state){
            slice->setExploded(state);
            slice->setExplodeDistanceFactor(state ? 0.12 : 0.06);
        });

        slice->setExploded(true);
        slice->setExplodeDistanceFactor(0.06);
    }

    series->setLabelsVisible(false);

    //-------------------------------------------
    // 3️⃣ CHART PREMIUM
    //-------------------------------------------
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
    chartView->setStyleSheet(
        "background: transparent;"
        "border-radius: 20px;"
        );

    //-------------------------------------------
    // 4️⃣ LÉGENDE PREMIUM (avec puces colorées)
    //-------------------------------------------
    QWidget *legendWidget = new QWidget();
    QVBoxLayout *legendLayout = new QVBoxLayout(legendWidget);

    for (int i = 0; i < max; i++) {
        double percent = ((double)totaux[i] / totalGlobal) * 100.0;

        QLabel *label = new QLabel();

        QString bullet = QString("<span style='font-size:22px; color:%1;'>●</span>")
                             .arg(colors[i].name());

        QString html =
            QString("%1 <b style='font-size:16px; color:%2;'>%3</b><br>"
                    "<span style='color:%2; font-size:13px;'>%4 clients — %5%</span>")
                .arg(bullet)
                .arg(colors[i].name())
                .arg(secteurs[i])
                .arg(totaux[i])
                .arg(QString::number(percent, 'f', 1));

        label->setText(html);
        label->setWordWrap(true);
        label->setStyleSheet("padding: 6px;");

        legendLayout->addWidget(label);
    }

    //-------------------------------------------
    // 5️⃣ LAYOUT FINAL
    //-------------------------------------------
    QWidget *container = new QWidget();
    QHBoxLayout *hLayout = new QHBoxLayout(container);

    hLayout->addWidget(chartView, 3);
    hLayout->addWidget(legendWidget, 1);
    hLayout->setSpacing(30);

    container->setStyleSheet(
        "background-color: #EDEAF9;"
        "border-radius: 25px;"
        "padding: 20px;"
        );

    //-------------------------------------------
    // 6️⃣ DIALOG
    //-------------------------------------------
    QDialog *dialog = new QDialog(this);
    dialog->setWindowTitle("Statistiques - Secteurs d'activité");
    dialog->resize(1000, 650);

    QVBoxLayout *mainLayout = new QVBoxLayout(dialog);
    mainLayout->addWidget(container);

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

    QString filePath = QFileDialog::getSaveFileName(
        this, "Exporter PDF des clients inactifs", "", "Fichiers PDF (*.pdf)");
    if (filePath.isEmpty()) return;

    QPdfWriter pdf(filePath);
    pdf.setPageSize(QPageSize(QPageSize::A4));
    pdf.setResolution(300);

    QPainter painter(&pdf);
    painter.setRenderHint(QPainter::Antialiasing);

    // === COULEURS ===
    QColor mauveHeader(147, 112, 219);
    QColor orangeAccent(255, 140, 0);
    QColor mauveLight(230, 220, 240);
    QColor orangeLight(255, 245, 230);

    // === TITRE ===
    painter.setFont(QFont("Arial", 18, QFont::Bold));
    painter.setPen(orangeAccent);
    painter.drawText(QRect(0, 200, pdf.width(), 100),
                     Qt::AlignCenter,
                     "Liste des clients inactifs (selon projets < 30 jours)");

    painter.setPen(QPen(mauveHeader, 3));
    painter.drawLine(200, 350, pdf.width() - 200, 350);

    // === TABLEAU ===
    int startX = 200;
    int y = 500;
    int rowHeight = 100;

    int colIdWidth = 180;
    int colNomWidth = 450;
    int colEmailWidth = 700;
    int colDateWidth = 570;

    // === EN-TÊTES ===
    painter.setFont(QFont("Arial", 12, QFont::Bold));
    painter.setPen(Qt::white);
    painter.setBrush(mauveHeader);

    painter.drawRect(startX, y,
                     colIdWidth + colNomWidth + colEmailWidth + colDateWidth,
                     rowHeight);

    painter.setBrush(Qt::NoBrush);
    painter.setPen(QPen(mauveHeader, 2));

    painter.drawRect(startX, y, colIdWidth, rowHeight);
    painter.drawRect(startX + colIdWidth, y, colNomWidth, rowHeight);
    painter.drawRect(startX + colIdWidth + colNomWidth, y, colEmailWidth, rowHeight);
    painter.drawRect(startX + colIdWidth + colNomWidth + colEmailWidth, y, colDateWidth, rowHeight);

    painter.setPen(Qt::white);
    painter.drawText(QRect(startX, y, colIdWidth, rowHeight), Qt::AlignCenter, "ID");
    painter.drawText(QRect(startX + colIdWidth, y, colNomWidth, rowHeight), Qt::AlignCenter, "Nom");
    painter.drawText(QRect(startX + colIdWidth + colNomWidth, y, colEmailWidth, rowHeight), Qt::AlignCenter, "Email");
    painter.drawText(QRect(startX + colIdWidth + colNomWidth + colEmailWidth, y, colDateWidth, rowHeight), Qt::AlignCenter, "Durée max projet");

    // === DONNÉES ===
    painter.setFont(QFont("Arial", 10));
    y += rowHeight;

    int ligne = 0;

    for (int i = 0; i < model->rowCount(); ++i)
    {
        int id = model->data(model->index(i, 0)).toInt();
        QString nom = model->data(model->index(i, 1)).toString();
        QString email = model->data(model->index(i, 2)).toString();

        // Récupérer la durée max des projets
        QSqlQuery q;
        q.prepare("SELECT MAX(DATE_FIN - DATE_DEBUT) FROM PROJET WHERE IDCLIENT = :id");
        q.bindValue(":id", id);
        q.exec();
        q.next();

        int duree = q.value(0).toInt();  // NULL -> 0

        // === INACTIF ? ===
        if (duree < 30)
        {
            // Fond alterné
            QColor bg = (ligne % 2 == 0) ? mauveLight : orangeLight;
            painter.fillRect(startX, y,
                             colIdWidth + colNomWidth + colEmailWidth + colDateWidth,
                             rowHeight, bg);

            painter.setPen(QPen(mauveHeader, 1));
            painter.drawRect(startX, y, colIdWidth, rowHeight);
            painter.drawRect(startX + colIdWidth, y, colNomWidth, rowHeight);
            painter.drawRect(startX + colIdWidth + colNomWidth, y, colEmailWidth, rowHeight);
            painter.drawRect(startX + colIdWidth + colNomWidth + colEmailWidth, y, colDateWidth, rowHeight);

            // === Texte ===
            painter.setPen(Qt::black);
            painter.drawText(QRect(startX + 20, y, colIdWidth - 40, rowHeight),
                             Qt::AlignVCenter | Qt::AlignLeft, QString::number(id));
            painter.drawText(QRect(startX + colIdWidth + 20, y, colNomWidth - 40, rowHeight),
                             Qt::AlignVCenter | Qt::AlignLeft, nom);
            painter.drawText(QRect(startX + colIdWidth + colNomWidth + 20, y, colEmailWidth - 40, rowHeight),
                             Qt::AlignVCenter | Qt::AlignLeft, email);
            painter.drawText(QRect(startX + colIdWidth + colNomWidth + colEmailWidth + 20, y, colDateWidth - 40, rowHeight),
                             Qt::AlignVCenter | Qt::AlignLeft,
                             QString::number(duree) + " jours");

            y += rowHeight;
            ligne++;

            if (y > pdf.height() - 300)
            {
                pdf.newPage();
                y = 200;
            }
        }
    }

    // === FOOTER ===
    painter.setFont(QFont("Arial", 9, -1, true));
    painter.setPen(orangeAccent);
    painter.drawText(200, pdf.height() - 150,
                     "Généré le : " + QDate::currentDate().toString("dd/MM/yyyy"));

    painter.end();
    QMessageBox::information(this, "PDF", "PDF généré avec succès !");
}










//Afficher projets du clients
void GestionClient::on_pushButton_11_clicked()
{
    if (ui->leId_6->text().isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Sélectionnez un client d'abord.");
        return;
    }

    int idClient = ui->leId_6->text().toInt();

    QString filePath = QFileDialog::getSaveFileName(
        this, "Exporter Fiche Client", "", "PDF (*.pdf)");
    if (filePath.isEmpty()) return;

    QPdfWriter pdf(filePath);
    pdf.setPageSize(QPageSize(QPageSize::A4));
    pdf.setResolution(300);

    QPainter painter(&pdf);
    painter.setRenderHint(QPainter::Antialiasing);

    QColor mauve(147, 112, 219), orange(255, 140, 0),
        mauveLight(230, 220, 240), orangeLight(255, 245, 230);

    // TITRE
    painter.setFont(QFont("Arial", 20, QFont::Bold));
    painter.setPen(orange);
    painter.drawText(QRect(0, 200, pdf.width(), 100),
                     Qt::AlignCenter, "FICHE CLIENT");
    painter.setPen(QPen(mauve, 3));
    painter.drawLine(200, 300, pdf.width() - 200, 300);

    int x = 100, y = 380, h = 60;

    // SECTION INFORMATIONS
    painter.setFont(QFont("Arial", 12, QFont::Bold));
    painter.setPen(mauve);
    painter.drawText(x, y, "Informations du client");
    y += 40;


    // Calcul statut client
    QSqlQuery qs;
    qs.prepare("SELECT MAX(DATE_FIN - DATE_DEBUT) FROM PROJET WHERE IDCLIENT = :id");
    qs.bindValue(":id", idClient);
    qs.exec();
    qs.next();

    int duree = qs.value(0).toInt();  // 0 si aucun projet
    QString statut;

    if (duree < 30) {
        statut = "INACTIF depuis " + QString::number(30 - duree) + " jours";
    } else {
        statut = "ACTIF";
    }


    // Tableau infos
    QStringList labels = {
        "ID Client", "Nom", "Email", "Téléphone",
        "Secteur", "Ville", "Date d'inscription", "Statut"
    };

    QStringList values = {
        ui->leId_6->text(),
        ui->leNom_6->text(),
        ui->leEmail_6->text(),
        ui->leTel_6->text(),
        ui->cbSecteur_6->currentText(),
        ui->cbPays_6->currentText(),
        ui->deDate_6->date().toString("dd/MM/yyyy"),
        statut
    };


    int labelW = 450;
    int valueW = 650;

    for (int i = 0; i < labels.size(); i++) {
        // Alternance couleurs
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

    // SECTION PROJETS
    painter.setFont(QFont("Arial", 12, QFont::Bold));
    painter.setPen(mauve);
    painter.drawText(x, y, "Projets associés");
    y += 40;

    // En-têtes colonnes
    int w[] = {200, 300, 300, 300, 300};
    QStringList headers = {"ID", "Début", "Fin", "Budget", "Statut"};

    painter.setBrush(mauve);
    painter.setPen(Qt::white);
    painter.drawRect(x, y, w[0]+w[1]+w[2]+w[3]+w[4], h);

    int cx = x;
    painter.setFont(QFont("Arial", 10, QFont::Bold));
    for (int i = 0; i < 5; i++) {
        painter.drawText(QRect(cx, y, w[i], h),
                         Qt::AlignCenter, headers[i]);
        cx += w[i];
    }
    y += h;

    // Données projets
    QSqlQuery q;
    q.prepare("SELECT ID_PROJET, DATE_DEBUT, DATE_FIN, BUDGET_REALISE, STATUS "
              "FROM PROJET WHERE IDCLIENT = :id");
    q.bindValue(":id", idClient);
    q.exec();

    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial", 10));
    int rowIndex = 0;

    while (q.next()) {

        QColor bg = (rowIndex % 2 == 0 ? mauveLight : orangeLight);
        painter.fillRect(x, y, w[0]+w[1]+w[2]+w[3]+w[4], h, bg);

        cx = x;

        painter.drawText(QRect(cx+5, y, w[0], h),
                         Qt::AlignVCenter | Qt::AlignLeft,
                         q.value(0).toString());
        cx += w[0];

        painter.drawText(QRect(cx+5, y, w[1], h),
                         Qt::AlignVCenter | Qt::AlignLeft,
                         q.value(1).toDate().toString("dd/MM/yyyy"));
        cx += w[1];

        painter.drawText(QRect(cx+5, y, w[2], h),
                         Qt::AlignVCenter | Qt::AlignLeft,
                         q.value(2).toDate().toString("dd/MM/yyyy"));
        cx += w[2];

        painter.drawText(QRect(cx+5, y, w[3], h),
                         Qt::AlignVCenter | Qt::AlignLeft,
                         q.value(3).toString() + " DT");
        cx += w[3];

        painter.drawText(QRect(cx+5, y, w[4], h),
                         Qt::AlignVCenter | Qt::AlignLeft,
                         q.value(4).toString());

        y += h;
        rowIndex++;
    }


    // FOOTER PRO
    painter.setFont(QFont("Arial", 8, QFont::StyleItalic));
    painter.setPen(QColor(120,120,120));
    painter.drawText(
        QRect(100, pdf.height() - 120, pdf.width() - 200, 40),
        Qt::AlignCenter,
        "Document généré automatiquement - SDCCS - "
            + QDate::currentDate().toString("dd/MM/yyyy")
        );


    painter.end();
    QMessageBox::information(this, "PDF", "Fiche client exportée !");
}







#include "bubblemapwindow.h"
// REMPLACEZ cette fonction dans gestionclient.cpp
// (Cherchez "void GestionClient::on_pushButton_10_clicked()")

void GestionClient::on_pushButton_10_clicked()
{
    mapWindow->clearClients();

    QSqlQuery q("SELECT NOM, PAYS FROM CLIENTT ORDER BY PAYS, NOM");

    int count = 0;
    while (q.next()) {
        QString nom = q.value(0).toString().trimmed();
        QString ville = q.value(1).toString().trimmed();

        qDebug() << "Client:" << nom << "| Ville:" << ville;

        if (!nom.isEmpty() && !ville.isEmpty()) {
            mapWindow->addClient(nom, ville);
            count++;
        }
    }

    qDebug() << "========================================";
    qDebug() << "TOTAL clients sur la carte:" << count;
    qDebug() << "========================================";

    mapWindow->show();
}
