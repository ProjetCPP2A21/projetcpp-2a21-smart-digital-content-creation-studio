#include "statsdialog.h"
#include <QPainter>

StatsDialog::StatsDialog(int images, int videos, int audios, QWidget *parent)
    : QDialog(parent), nbImages(images), nbVideos(videos), nbAudios(audios)
{
    setWindowTitle("Statistiques");
    resize(600, 420);
}

void StatsDialog::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing);

    int total = nbImages + nbVideos + nbAudios;
    if (total == 0) {
        p.drawText(rect(), Qt::AlignCenter, "Aucune ressource.");
        return;
    }

    QRectF pieRect(20, 20, 300, 300);
    qreal start = 0.0;
    qreal aImg = (qreal(nbImages) / total) * 360.0;
    qreal aVid = (qreal(nbVideos) / total) * 360.0;
    qreal aAud = (qreal(nbAudios) / total) * 360.0;

    p.setBrush(QColor(100,149,237));
    p.drawPie(pieRect, int(start*16), int(aImg*16));
    start += aImg;
    p.setBrush(QColor(60,179,113));
    p.drawPie(pieRect, int(start*16), int(aVid*16));
    start += aVid;
    p.setBrush(QColor(255,165,0));
    p.drawPie(pieRect, int(start*16), int(aAud*16));

    // legend
    int lx = 340, ly = 60;
    p.setBrush(QColor(100,149,237)); p.drawRect(lx, ly, 18, 18); p.drawText(lx+25, ly+14, QString("Images: %1").arg(nbImages));
    p.setBrush(QColor(60,179,113)); p.drawRect(lx, ly+30, 18, 18); p.drawText(lx+25, ly+44, QString("Vidéos: %1").arg(nbVideos));
    p.setBrush(QColor(255,165,0)); p.drawRect(lx, ly+60, 18, 18); p.drawText(lx+25, ly+74, QString("Audios: %1").arg(nbAudios));
}
