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

    ui->actionDashboard->setVisible(false);
    ui->stackedWidget->setCurrentIndex(Dashboard);

    connect(ui->actionDashboard, &QAction::triggered, this, [this](){
        ui->labelMB->show();
        ui->actionDashboard->setVisible(false);
        ui->stackedWidget->setCurrentIndex(Dashboard);
    });

    connect(ui->actionSettings, &QAction::triggered, this, [this](){
        ui->labelMB->hide();
        ui->actionDashboard->setVisible(true);
        ui->tbSettings->setCurrentIndex(0);
        ui->stackedWidget->setCurrentIndex(Settings);
    });

    connect(ui->actionLogs, &QAction::triggered, this, [this](){
        ui->labelMB->hide();
        ui->actionDashboard->setVisible(true);
        ui->stackedWidget->setCurrentIndex(logs);
    });

    connect(ui->cbCommunicationType, QOverload<int>::of(&QComboBox::currentIndexChanged), this, [this](int index){
        ui->stCommunication->setCurrentIndex(index);
    });

    connect(ui->pbModbusSerialConfig, &QPushButton::clicked, &m_serialDialog, &MBSerialDialog::exec);

    connect(ui->pbSearch, &QPushButton::clicked, this, &MBMain::logsList);
}

MBMain::~MBMain()
{
    delete ui;
}

void
MBMain::logsList()
{

}

