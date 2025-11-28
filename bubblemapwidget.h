#ifndef BUBBLEMAPWIDGET_H
#define BUBBLEMAPWIDGET_H

#include <QWidget>
#include <QMap>

class BubbleMapWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BubbleMapWidget(QWidget *parent = nullptr);

    void addClient(const QString &name, const QString &city);
    void clearClients();

protected:
    void paintEvent(QPaintEvent *) override;
    void wheelEvent(QWheelEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

private:
    struct ClientMarker {
        QString name;
        QString city;
        QPoint mapPos;
        int offset;
    };

    QVector<ClientMarker> clients;
    QMap<QString,int> cityCount;

    QPixmap mapImage;
    float zoomFactor;
    QPoint mapOffset;

    QPoint cityToPoint(const QString &city);
};

#endif // BUBBLEMAPWIDGET_H
