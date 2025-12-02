#include "bubblemapwindow.h"
#include <QHBoxLayout>

BubbleMapWindow::BubbleMapWindow(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Carte des clients");
    resize(900, 700);

    mapWidget = new BubbleMapWidget(this);

    auto *layout = new QHBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(mapWidget);
    setLayout(layout);
}

void BubbleMapWindow::addClient(const QString &name, const QString &city)
{
    mapWidget->addClient(name, city);
}

void BubbleMapWindow::clearClients()
{
    mapWidget->clearClients();
}
