#ifndef MBSERIALDIALOG_H
#define MBSERIALDIALOG_H

#include <QDialog>
#include <QSerialPort>

namespace Ui {
class MBSerialDialog;
}

class MBSerialDialog : public QDialog
{
    Q_OBJECT

public:
    struct Settings {
        int parity = QSerialPort::EvenParity;
        int baud = QSerialPort::Baud19200;
        int dataBits = QSerialPort::Data8;
        int stopBits = QSerialPort::OneStop;
        int responseTime = 1000;
        int numberOfRetries = 3;
    };

    explicit MBSerialDialog(QWidget *parent = nullptr);
    ~MBSerialDialog();

    Settings settings() const;

private:
    Ui::MBSerialDialog *ui;
    Settings m_settings;
};

#endif // MBSERIALDIALOG_H
