VERSION = 1.0.0

DEFINES += APP_NAME=\\\"MobileMeter\\\" \
           APP_VER=\\\"$$VERSION\\\" \

QT += core gui

QT += serialport sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

OBJECTS_DIR += .obj/
MOC_DIR += .moc/
UI_DIR += .ui/

SOURCES += \
    src/main.cpp \
    src/mbdatabase.cpp \
    src/mblogin.cpp \
    src/mbmain.cpp \
    src/mbmodbus.cpp \
    src/mbserialdialog.cpp

HEADERS += \
    src/mbdatabase.h \
    src/mblogin.h \
    src/mbmain.h \
    src/mbmodbus.h \
    src/mbserialdialog.h

FORMS += \
    ui/mblogin.ui \
    ui/mbmain.ui \
    ui/mbserialdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
