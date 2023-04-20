#include "mmlogin.h"
#include "ui_mmlogin.h"

#include <QApplication>
#include <QMessageBox>
#include <QDebug>

MMLogin::MMLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MMLogin)
{
    ui->setupUi(this);

    connect(ui->pbLogin, &QPushButton::clicked, this, &MMLogin::login);
//    connect(this, &QInputMethod::selectionChanged, this, &MMLogin::enableKeyboard);
    connect(ui->leUsername, &QLineEdit::selectionChanged, this, &MMLogin::enableKeyboard);
}

MMLogin::~MMLogin()
{
    delete ui;
}

void
MMLogin::login()
{
    QString user = ui->leUsername->text();
    QString pass = ui->lePassword->text();

    if(user == "admin" && pass == "admin")
        accept();
    else
        QMessageBox::warning(this, "Login Failed", "Username or Password wrong!");
}

void
MMLogin::enableKeyboard()
{

        bool keyboardVisible = QGuiApplication::inputMethod()->isVisible();

        qInfo() << "keyboardVisible: " << keyboardVisible;
}

void
MMLogin::disableKeyboard()
{
    QGuiApplication::inputMethod()->setVisible(false);
}


//bool
//MMLogin::event(QEvent *event)
//{
//    Q_UNUSED(event)

//    bool keyboardVisible = QGuiApplication::inputMethod()->isVisible();

//    qInfo() << "keyboardVisible: " << keyboardVisible;

//    return true;;
//}
