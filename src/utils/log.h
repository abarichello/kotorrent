#pragma once

#include <QDebug>
#include <QString>
#include <QFile>
#include <QTextStream>

class Log {
public:
    Log();

    static void messageHandler(QtMsgType type, const QMessageLogContext& context, const QString& msg);
};
