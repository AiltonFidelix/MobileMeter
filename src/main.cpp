#include "mobilemeter.h"
#include "mmlogin.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    // Enable line edit keyboard
    qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));

    QApplication a(argc, argv);

    MobileMeter meter;

    MMLogin login;
    login.showFullScreen();

    QObject::connect(&login, &MMLogin::accepted, &meter, &MobileMeter::showFullScreen);

    return a.exec();
}

