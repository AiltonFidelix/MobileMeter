#include "mbmain.h"
#include "ui_mbmain.h"

MBMain::MBMain(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MBMain)
{
    ui->setupUi(this);

    ui->dtPeriodSince->setTime(QTime(0, 0));
    ui->dtPeriodUntil->setTime(QTime(0, 0));
    ui->dtPeriodSince->setDate(QDate::currentDate());
    ui->dtPeriodUntil->setDate(QDate::currentDate().addDays(1));

    ui->stackedWidget->setCurrentIndex(Dashboard);

    connect(ui->actionDashboard, &QAction::triggered, this, [this](){
        ui->labelMB->show();
        ui->stackedWidget->setCurrentIndex(Dashboard);
    });

    connect(ui->actionSettings, &QAction::triggered, this, [this](){
        ui->labelMB->hide();
        ui->tbSettings->setCurrentIndex(0);
        ui->stackedWidget->setCurrentIndex(Settings);
    });

    connect(ui->actionLogs, &QAction::triggered, this, [this](){
        ui->labelMB->hide();
        ui->stackedWidget->setCurrentIndex(logs);
    });

    connect(ui->pbSearch, &QPushButton::clicked, this, &MBMain::searchLogs);
}

MBMain::~MBMain()
{
    delete ui;
}

void
MBMain::searchLogs()
{

}

