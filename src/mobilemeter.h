#ifndef MOBILEMETER_H
#define MOBILEMETER_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MobileMeter; }
QT_END_NAMESPACE

class MobileMeter : public QMainWindow
{
    Q_OBJECT

public:
    MobileMeter(QWidget *parent = nullptr);
    ~MobileMeter();

private:
    Ui::MobileMeter *ui;

    enum Screens { Dashboard, logs };
};
#endif // MOBILEMETER_H
