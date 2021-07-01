#pragma once

#include <QMainWindow>
#include <QMenuBar>
#include <QAction>
#include <QDebug>
#include <QLayout>
#include <QWidget>

namespace Ui {
    class MainWidget;
}

class MainWidget : public QWidget {
    Q_OBJECT

public:
    explicit MainWidget(QWidget* parent = nullptr);
    ~MainWidget();

public slots:
    void exitApplication();
#ifdef KOBO
    void toggleWifi(bool triggered);
#endif

private:
    Ui::MainWidget* ui;

    std::unique_ptr<QMenuBar> menu;
    std::unique_ptr<QAction> actionExit;
    std::unique_ptr<QMenu> menuKobo;
    std::unique_ptr<QAction> actionWifi;
    std::unique_ptr<QMenu> menuDebug;
    std::unique_ptr<QAction> actionRotate;
    std::unique_ptr<QAction> actionRefreshScreen;

    std::unique_ptr<QWidget> console;
};
