#pragma once

#include <QWidget>
#include <QString>
#include <QPlainTextEdit>
#include <QPushButton>
#include <QDebug>

namespace Ui {
    class Console;
}

class Console : public QWidget {
    Q_OBJECT

public:
    explicit Console(QWidget* parent = nullptr);
    ~Console();

    void update();

private:
    Ui::Console* ui;

    std::unique_ptr<QPushButton> refreshButton;
    std::unique_ptr<QPushButton> clearButton;
    std::unique_ptr<QPushButton> closeButton;

    std::unique_ptr<QPlainTextEdit> textEdit;
};
