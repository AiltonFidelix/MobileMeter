#include "mbserialdialog.h"
#include "ui_mbserialdialog.h"

MBSerialDialog::MBSerialDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MBSerialDialog)
{
    ui->setupUi(this);

    ui->parityCombo->setCurrentIndex(1);
    ui->baudCombo->setCurrentText(QString::number(m_settings.baud));
    ui->dataBitsCombo->setCurrentText(QString::number(m_settings.dataBits));
    ui->stopBitsCombo->setCurrentText(QString::number(m_settings.stopBits));
    ui->timeoutSpinner->setValue(m_settings.responseTime);
    ui->retriesSpinner->setValue(m_settings.numberOfRetries);

    connect(ui->applyButton, &QPushButton::clicked, [this]() {
        m_settings.parity = ui->parityCombo->currentIndex();
        if (m_settings.parity > 0)
            m_settings.parity++;
        m_settings.baud = ui->baudCombo->currentText().toInt();
        m_settings.dataBits = ui->dataBitsCombo->currentText().toInt();
        m_settings.stopBits = ui->stopBitsCombo->currentText().toInt();
        m_settings.responseTime = ui->timeoutSpinner->value();
        m_settings.numberOfRetries = ui->retriesSpinner->value();

        hide();
    });
}

MBSerialDialog::~MBSerialDialog()
{
    delete ui;
}

MBSerialDialog::Settings
MBSerialDialog::settings() const
{
    return m_settings;
}
