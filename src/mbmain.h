#ifndef MBMAIN_H
#define MBMAIN_H

#include <QMainWindow>

#include "mbserialdialog.h"

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
    void logsList();

private:
    Ui::MBMain *ui;
    MBSerialDialog m_serialDialog;

    enum Screens { Dashboard, Settings, logs };
};
#endif // MBMAIN_H
