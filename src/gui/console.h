#pragma once

#include <QWidget>
#include <QString>
#include <QPlainTextEdit>
#include <QDebug>

namespace Ui {
    class Console;
}

class Console : public QWidget {
    Q_OBJECT

public:
    explicit Console(QWidget* parent = nullptr);
    ~Console();

    static void update();

private:
    Ui::Console* ui;

    std::unique_ptr<QPlainTextEdit> textEdit;
};
