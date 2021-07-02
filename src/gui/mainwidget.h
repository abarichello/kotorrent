#pragma once

#include <QMainWindow>
#include <QMenuBar>
#include <QAction>
#include <QDebug>
#include <QLayout>
#include <QWidget>

#include "console.h"
#include "ui_mainwidget.h"
#ifdef KOBO
#include "koboplatformfunctions.h"
#endif

namespace Ui {
    class MainWidget;
}

class MainWidget : public QWidget {
    Q_OBJECT

public:
    explicit MainWidget(QWidget* parent = nullptr);
    ~MainWidget();

public slots:
#ifdef KOBO
    void toggleWifi(bool triggered);
#endif
    void exitApplication();
    void toggleConsole();

private:
    Ui::MainWidget* ui;
    std::unique_ptr<Console> console;

    // File
    std::unique_ptr<QMenuBar> menu;
    std::unique_ptr<QAction> actionExit;
    // Kobo
    std::unique_ptr<QMenu> menuKobo;
    std::unique_ptr<QAction> actionWifi;
    // Debug
    std::unique_ptr<QMenu> menuDebug;
    std::unique_ptr<QAction> actionToggleConsole;
    std::unique_ptr<QAction> actionRotate;
    std::unique_ptr<QAction> actionRefreshScreen;
};
