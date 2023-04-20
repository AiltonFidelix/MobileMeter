#ifndef MMLOGIN_H
#define MMLOGIN_H

//#include "mmlineedit.h"

#include <QDialog>

namespace Ui {
class MMLogin;
}

class MMLogin : public QDialog
{
    Q_OBJECT

public:
    explicit MMLogin(QWidget *parent = nullptr);
    ~MMLogin();

private:
    Ui::MMLogin *ui;

private slots:
    void login();
    void enableKeyboard();
    void disableKeyboard();

//public:
//    bool event(QEvent *event);


};

#endif // MMLOGIN_H
