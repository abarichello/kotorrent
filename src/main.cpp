#include <QApplication>
#include <QDebug>

#include "gui/mainwidget.h"
#include "utils/log.h"

int main(int argc, char* argv[]) {
    qInstallMessageHandler(Log::messageHandler);
    qInfo() << "Installed message handler";
    QApplication app(argc, argv);
    MainWidget w;
    w.show();
    return app.exec();
}
