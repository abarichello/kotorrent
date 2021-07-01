#include "console.h"
#include "ui_console.h"

Console::Console(QWidget* parent) : QWidget(parent), ui(new Ui::Console) {
    ui->setupUi(this);
}

Console::~Console() {
    delete ui;
}

void Console::update() {
    //    textEdit->setText(textEdit->toPlainText() + "\n" + str);
    //    qInfo() << str;
}
