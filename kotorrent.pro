kobo {
    DEFINES += KOBO
    DEFINES += __ARM_NEON__
    DEFINES -= DESKTOP

    KOBO_PLATFORM_PLUGIN_PATH = $$PWD/qt5-kobo-platform-plugin

    INCLUDEPATH += $$KOBO_PLATFORM_PLUGIN_PATH

    target.path = /mnt/onboard/.adds/kotorrent
    INSTALLS += target
    CONFIG += kobo
} else { # default is desktop
    DEFINES += DESKTOP
}

QT += core gui widgets network
TARGET = kotorrent
CONFIG += c++20

HEADERS += \
    src/utils/log.h \
    src/gui/console.h \
    src/gui/mainwidget.h

SOURCES += \
    src/utils/log.cpp \
    src/gui/console.cpp \
    src/gui/mainwidget.cpp \
    src/main.cpp

FORMS += \
    src/gui/console.ui \
    src/gui/mainwidget.ui
