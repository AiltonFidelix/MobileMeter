QT += core gui

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
    src/mmlineedit.cpp \
    src/mmlogin.cpp \
    src/mobilemeter.cpp

HEADERS += \
    src/mmlineedit.h \
    src/mmlogin.h \
    src/mobilemeter.h

FORMS += \
    ui/mmlogin.ui \
    ui/mobilemeter.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
