#ifndef BUBBLEMAPWINDOW_H
#define BUBBLEMAPWINDOW_H

#include <QWidget>
#include "bubblemapwidget.h"

class BubbleMapWindow : public QWidget
{
    Q_OBJECT

public:
    explicit BubbleMapWindow(QWidget *parent = nullptr);

    void addClient(const QString &name, const QString &city);
    void clearClients();

private:
    BubbleMapWidget *mapWidget;
};

#endif // BUBBLEMAPWINDOW_H
