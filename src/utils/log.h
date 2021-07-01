#pragma once

#include <QDebug>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDateTime>

class Log {
public:
    Log();

    static void messageHandler(QtMsgType type, const QMessageLogContext& context, const QString& msg);
};
