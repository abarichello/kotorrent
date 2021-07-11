#pragma once

#include <QWidget>
#include <QString>
#include <QPlainTextEdit>
#include <QPushButton>
#include <QDebug>
#include <QFile>
#include <QTextStream>

namespace Ui {
    class Console;
}

class Console : public QWidget {
    Q_OBJECT

public:
    explicit Console(QWidget* parent = nullptr);
    ~Console();

public slots:
    void refreshText();
    void clearLogFile();
    void toggleConsole();

private:
    Ui::Console* ui;

    std::unique_ptr<QPushButton> refreshButton;
    std::unique_ptr<QPushButton> clearLogButton;
    std::unique_ptr<QPushButton> closeButton;
};
