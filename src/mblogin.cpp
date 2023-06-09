#include "ui_mblogin.h"
#include "mblogin.h"
#include "mbdatabase.h"

#include <QApplication>
#include <QMessageBox>

MBLogin::MBLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MBLogin)
{
    ui->setupUi(this);

    connect(ui->pbLogin, &QPushButton::clicked, this, &MBLogin::login);
}

MBLogin::~MBLogin()
{
    delete ui;
}

void
MBLogin::login()
{
    QString user = ui->leUsername->text();
    QString pass = ui->lePassword->text();

    if(MBDataBase::instance()->authenticate(user, pass))
        accept();
    else
        QMessageBox::warning(this, "Login Failed", MBDataBase::instance()->errors().join(""));
}
