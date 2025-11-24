// bubblemapwidget.cpp
#include "bubblemapwidget.h"
#include <QPainter>
#include <QWheelEvent>
#include <QKeyEvent>
#include <QDebug>

BubbleMapWidget::BubbleMapWidget(QWidget *parent) : QWidget(parent)
{
    mapImage.load(":/maptunisie.png");
    zoomFactor = 1.0f;
    mapOffset = QPoint(0, 0);
    setFocusPolicy(Qt::StrongFocus);
}

void BubbleMapWidget::clearClients()
{
    clients.clear();
    cityCount.clear();
    update();
}

void BubbleMapWidget::addClient(const QString &name, const QString &city)
{
    QString normalizedCity = city.trimmed();

    QMap<QString, QString> cityAliases = {
        {"Gabes", "Gabès"},
        {"Beja", "Béja"}
    };

    if (cityAliases.contains(normalizedCity)) {
        normalizedCity = cityAliases[normalizedCity];
    }

    QPoint p = cityToPoint(normalizedCity);
    if (p == QPoint(-1, -1)) {
        qDebug() << "⚠️ Ville non trouvée:" << normalizedCity;
        return;
    }

    int count = cityCount[normalizedCity]++;

    // ✅ Espacement adapté selon la ville
    int offset = 0;

    // Pour Tunis : ligne vers la droite (dans la mer)
    if (normalizedCity == "Tunis") {
        offset = count * 25;  // Moins d'espacement
    }
    // Pour Bizerte : lignes vers le haut
    else if (normalizedCity == "Bizerte") {
        if (count == 0) {
            offset = -30;  // Premier = EN HAUT
        } else {
            offset = -10;   // Deuxième = EN BAS
        }
    }
    else if (normalizedCity == "Zaghouan") {
        offset = count * -17;  // Espacement vertical
    }
    else if (normalizedCity == "Nabeul") {
        offset = count * 25;  // Espacement vertical
    }
    // Pour Monastir/Sousse : vers le haut aussi
    else if (normalizedCity == "Monastir" || normalizedCity == "Sousse") {
        offset = -(count * 20);  // NÉGATIF = vers le haut !
    }
    // Autres villes : normal
    else {
        offset = count * 35;
    }

    ClientMarker m{name, normalizedCity, p, offset};
    clients.append(m);
    qDebug() << "✅ Client ajouté:" << name << "à" << normalizedCity << "offset:" << offset;
    update();
}

void BubbleMapWidget::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing);

    if (mapImage.isNull()) return;

    QRectF target(
        (width() - mapImage.width() * zoomFactor) / 2 + mapOffset.x(),
        (height() - mapImage.height() * zoomFactor) / 2 + mapOffset.y(),
        mapImage.width() * zoomFactor,
        mapImage.height() * zoomFactor
        );

    p.drawPixmap(target, mapImage, mapImage.rect());

    QFont font("Segoe UI", 13, QFont::Bold);
    p.setFont(font);

    for (const ClientMarker &c : clients)
    {
        QPointF center(
            target.x() + c.mapPos.x() * zoomFactor,
            target.y() + c.mapPos.y() * zoomFactor
            );

        // ✅ Position du texte selon la ville
        QPointF textPos;

        if (c.city == "Tunis") {
            // Tunis : texte à DROITE et EN HAUT (vers la mer, pas vers Nabeul)
            textPos = QPointF(center.x() + 100, center.y() - 72 + c.offset);
        }
        else if (c.city == "Bizerte") {
            textPos = QPointF(center.x() + 50, center.y() + 5 + c.offset);

        }
        else if (c.city == "Monastir" || c.city == "Sousse") {
            // Monastir : texte à DROITE
            textPos = QPointF(center.x() + 35, center.y() + c.offset);
        }
        else if (c.city == "Zaghouan") {
            // Zaghouan : texte PLUS À DROITE
            textPos = QPointF(center.x() + 90, center.y() + c.offset);  // ✅ 60 au lieu de 35
        }
        else if (c.city == "Nabeul") {
            // Nabeul : texte à DROITE (dans la mer)
            textPos = QPointF(center.x() + 35, center.y() + c.offset);
        }
        else {
            // Autres : normal (Zaghouan/Amina)
            textPos = QPointF(center.x() + 80 + c.offset, center.y() - 10);
        }


        // Ligne mauve
        p.setPen(QPen(QColor("#9C27B0"), 2));
        p.drawLine(center, textPos);

        // Cercle mauve
        p.setPen(QPen(Qt::white, 2));
        p.setBrush(QColor("#9C27B0"));
        p.drawEllipse(center, 8, 8);

        // Contour blanc
        p.setPen(QPen(Qt::white, 4));
        p.drawText(textPos + QPointF(4, 4), c.name);

        // Texte noir
        p.setPen(QPen(Qt::black, 2));
        p.drawText(textPos + QPointF(4, 4), c.name);
    }
}

void BubbleMapWidget::wheelEvent(QWheelEvent *event)
{
    float oldZoom = zoomFactor;

    if (event->angleDelta().y() > 0) {
        zoomFactor += 0.15f;
    } else {
        zoomFactor -= 0.15f;
    }

    zoomFactor = qMax(0.5f, qMin(zoomFactor, 5.0f));

    QPointF mousePos = event->position();
    float zoomRatio = zoomFactor / oldZoom;

    mapOffset.setX(mousePos.x() - zoomRatio * (mousePos.x() - mapOffset.x()));
    mapOffset.setY(mousePos.y() - zoomRatio * (mousePos.y() - mapOffset.y()));

    update();
    event->accept();
}

void BubbleMapWidget::keyPressEvent(QKeyEvent *event)
{
    int step = 30;

    switch(event->key()) {
    case Qt::Key_Left:
        mapOffset.setX(mapOffset.x() + step);
        break;
    case Qt::Key_Right:
        mapOffset.setX(mapOffset.x() - step);
        break;
    case Qt::Key_Up:
        mapOffset.setY(mapOffset.y() + step);
        break;
    case Qt::Key_Down:
        mapOffset.setY(mapOffset.y() - step);
        break;
    case Qt::Key_Plus:
    case Qt::Key_Equal:
        zoomFactor += 0.2f;
        zoomFactor = qMin(zoomFactor, 5.0f);
        break;
    case Qt::Key_Minus:
        zoomFactor -= 0.2f;
        zoomFactor = qMax(zoomFactor, 0.5f);
        break;
    case Qt::Key_R:
    case Qt::Key_Home:
        mapOffset = QPoint(0, 0);
        zoomFactor = 1.0f;
        break;
    default:
        QWidget::keyPressEvent(event);
        return;
    }

    update();
    event->accept();
}

// COORDONNÉES FINALES CORRIGÉES
QPoint BubbleMapWidget::cityToPoint(const QString &city)
{
    QMap<QString, QPoint> pos = {
        // Nord
        {"Tunis",       {443, 95}},
        {"Ariana",      {430, 80}},
        {"Ben Arous",   {440, 105}},
        {"Manouba",     {400, 90}},
        {"Bizerte",     {340, 50}},
        {"Nabeul",      {520, 90}},

        // Nord-Ouest
        {"Béja",        {350, 130}},
        {"Jendouba",    {240, 100}},
        {"Kef",         {270, 180}},
        {"Siliana",     {360, 190}},

        // Centre-Est
        {"Zaghouan",    {410, 180}},
        {"Sousse",      {470, 220}},
        {"Monastir",    {505, 310}},
        {"Mahdia",      {520, 340}},

        // Centre
        {"Kairouan",    {415, 280}},
        {"Kasserine",   {280, 345}},
        {"Sidi Bouzid", {375, 355}},

        // Sud
        {"Sfax",        {480, 420}},
        {"Gabès",       {435, 540}},
        {"Medenine",    {520, 595}},
        {"Tataouine",   {425, 720}},

        // Sud-Ouest
        {"Gafsa",       {310, 470}},
        {"Tozeur",      {240, 520}},
        {"Kebili",      {350, 595}}
    };

    return pos.value(city, QPoint(-1,-1));
}
