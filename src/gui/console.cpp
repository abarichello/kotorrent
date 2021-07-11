#include "console.h"
#include "ui_console.h"

Console::Console(QWidget* parent)
    : QWidget(parent),
      ui(new Ui::Console),
      refreshButton(ui->refreshButton),
      clearLogButton(ui->clearLogButton),
      closeButton(ui->closeButton) {
    ui->setupUi(this);

    hide();
    connect(ui->refreshButton, SIGNAL(clicked(bool)), this, SLOT(refreshText()));
    connect(ui->clearLogButton, SIGNAL(clicked(bool)), this, SLOT(clearLogFile()));
    connect(ui->closeButton, SIGNAL(clicked(bool)), this, SLOT(toggleConsole()));
}

Console::~Console() {
    delete ui;
}

void Console::refreshText() {
    QFile logFile("log.txt");
    if (!logFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return;
    }

    ui->textEdit->setPlainText("Debug console:\n---\n");
    QTextStream in(&logFile);
    while (!in.atEnd()) {
        QString line = in.readLine();
        ui->textEdit->appendPlainText(line);
    }
}

void Console::clearLogFile() {
    QFile logFile("log.txt");
    if (!logFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return;
    }
    logFile.remove();
    qInfo() << "Cleared log file";
    refreshText();
}

void Console::toggleConsole() {
    if (isVisible()) {
        hide();
    } else {
        show();
        refreshText();
    }
}
