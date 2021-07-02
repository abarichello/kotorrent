#include "console.h"
#include "ui_console.h"

Console::Console(QWidget* parent)
    : QWidget(parent),
      ui(new Ui::Console),
      refreshButton(ui->refreshButton),
      clearButton(ui->clearButton),
      closeButton(ui->closeButton) {
    ui->setupUi(this);

    update();
}

Console::~Console() {
    delete ui;
}

void Console::update() {
    QFile outFile("log.txt");
    outFile.open(QIODevice::ReadOnly);
    const auto logStr = outFile.readAll();
    textEdit->setPlainText(logStr);
}
