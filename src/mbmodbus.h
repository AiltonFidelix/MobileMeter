#ifndef MBMODBUS_H
#define MBMODBUS_H

#include <QObject>
#include <QSerialPort>

class MBModbus : public QObject
{
    Q_OBJECT
public:
    explicit MBModbus(QObject *parent = nullptr);

signals:

private:
    QString m_portName;
    QString m_baudRate;
};

#endif // MBMODBUS_H
