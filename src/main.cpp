#include "mbmain.h"
#include "mblogin.h"

#include <QApplication>

#define TEST

int main(int argc, char *argv[])
{
#ifndef TEST
    // Keyboard enable
    qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));
#endif

    QApplication a(argc, argv);

    MBMain meter;

    MBLogin login;

#ifdef TEST
//    login.show();

//    QObject::connect(&login, &MBLogin::accepted, &meter, &MBMain::show);
    meter.show();
#else
    login.showFullScreen();

    QObject::connect(&login, &MBLogin::accepted, &meter, &MBMain::showFullScreen);
#endif

    return a.exec();
}

