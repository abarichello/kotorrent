kobo {
    DEFINES += KOBO
    DEFINES += __ARM_NEON__
    DEFINES -= DESKTOP

    KOBO_PLATFORM_PLUGIN_PATH = $$PWD/../qt5-kobo-platform-plugin

    INCLUDEPATH += $$KOBO_PLATFORM_PLUGIN_PATH

    target.path = /mnt/onboard/.adds/kotorrent
    INSTALLS += target
} else { # default is desktop
    DEFINES += DESKTOP
}

QT += core gui widgets
TARGET = kotorrent
CONFIG += c++17

SOURCES += \
    src/main.cpp \
    src/mainwindow.cpp

HEADERS += \
    src/mainwindow.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

FORMS += \
    src/mainwindow.ui
