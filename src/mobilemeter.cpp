#include "mobilemeter.h"
#include "ui_mobilemeter.h"

MobileMeter::MobileMeter(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MobileMeter)
{
    ui->setupUi(this);

    ui->stackedWidget->setCurrentIndex(Dashboard);
}

MobileMeter::~MobileMeter()
{
    delete ui;
}

