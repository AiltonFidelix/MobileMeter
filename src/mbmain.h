#ifndef MBMAIN_H
#define MBMAIN_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MBMain; }
QT_END_NAMESPACE

class MBMain : public QMainWindow
{
    Q_OBJECT
public:
    MBMain(QWidget *parent = nullptr);
    ~MBMain();

private slots:
    void searchLogs();

private:
    Ui::MBMain *ui;

    enum Screens { Dashboard, Settings, logs };
};
#endif // MBMAIN_H
