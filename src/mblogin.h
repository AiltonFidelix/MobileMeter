#ifndef MBLOGIN_H
#define MBLOGIN_H

#include <QDialog>

namespace Ui {
class MBLogin;
}

class MBLogin : public QDialog
{
    Q_OBJECT
public:
    explicit MBLogin(QWidget *parent = nullptr);
    ~MBLogin();

private:
    Ui::MBLogin *ui;

private slots:
    void login();
};

#endif // MBLOGIN_H
