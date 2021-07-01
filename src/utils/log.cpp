#include "log.h"

Log::Log() {
}

void Log::messageHandler(QtMsgType type, const QMessageLogContext& context, const QString& msg) {
    QFile outFile("log.txt");
    outFile.open(QIODevice::WriteOnly | QIODevice::Append);
    QTextStream ts(&outFile);

    QString lineFormat = "%1|%2|%3 (%4:%5, %6)\n";
    auto datetime = QDateTime::currentDateTime().toString("yyyy.MM.dd hh:mm:ss");
    QString lineOutput;
    auto outputFunction = qDebug();
    switch (type) {
        case QtDebugMsg:
            lineOutput = lineFormat.arg("[DEBUG]", datetime, msg, context.file, QString::number(context.line),
                                        context.function);
            break;
        case QtInfoMsg:
            lineOutput = lineFormat.arg("[INFO ]", datetime, msg, context.file, QString::number(context.line),
                                        context.function);
            outputFunction = qInfo();
            break;
        case QtWarningMsg:
            lineOutput = lineFormat.arg("[WARN ]", datetime, msg, context.file, QString::number(context.line),
                                        context.function);
            outputFunction = qWarning();
            break;
        case QtCriticalMsg:
            lineOutput = lineFormat.arg("[CRTCL]", datetime, msg, context.file, QString::number(context.line),
                                        context.function);
            outputFunction = qCritical();
            break;
        case QtFatalMsg:
            lineOutput = lineFormat.arg("[FATAL]", datetime, msg, context.file, QString::number(context.line),
                                        context.function);
            outputFunction = qCritical();
            abort();
    }
    ts << lineOutput;
    outputFunction << lineOutput.toUtf8();
}
