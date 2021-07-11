#include "mainwidget.h"
#include "ui_mainwidget.h"

#ifdef KOBO
#include "koboplatformfunctions.h"
#endif

MainWidget::MainWidget(QWidget* parent)
    : QWidget(parent),
      ui(new Ui::MainWidget),
      menu(ui->menu),
      actionExit(ui->actionExit),
      menuKobo(ui->menuKobo),
      actionWifi(ui->actionWifi),
      menuDebug(ui->menuDebug),
      actionRotate(ui->actionRotate),
      actionRefreshScreen(ui->actionRefreshScreen),
      console(new Console()) {
    ui->setupUi(this);
    console->setParent(this);

#ifdef KOBO
    connect(ui->actionWifi, SIGNAL(triggered(bool)), this, SLOT(toggleWifi(bool)));
#endif
    connect(ui->actionExit, SIGNAL(triggered(bool)), this, SLOT(exitApplication()));
    connect(ui->actionToggleConsole, SIGNAL(triggered(bool)), this, SLOT(toggleConsole()));
}

MainWidget::~MainWidget() {
    delete ui;
}

void MainWidget::toggleConsole() {
    console->toggleConsole();
}

void MainWidget::exitApplication() {
    QApplication::quit();
}

#ifdef KOBO
void MainWidget::toggleWifi(bool triggered) {
    qInfo() << "Toggle wifi to:" << triggered;
    triggered ? KoboPlatformFunctions::enableWiFiConnection() : KoboPlatformFunctions::disableWiFiConnection();
    qInfo() << "Wifi status:" << KoboPlatformFunctions::testInternetConnection();
}
#endif
