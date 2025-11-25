#include "gestionprojet3.h"
#include "ui_gestionprojet3.h"

gestionprojet3::gestionprojet3(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::gestionprojet3)
{
    ui->setupUi(this);
}

gestionprojet3::~gestionprojet3()
{
    delete ui;
}
