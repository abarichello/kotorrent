#include "mainwidget.h"
#include "ui_mainwidget.h"

#ifdef KOBO
#include "koboplatformfunctions.h"
#endif

MainWidget::MainWidget(QWidget* parent)
    : QWidget(parent),
      ui(new Ui::MainWidget),
      menu(ui->menu),
      menuKobo(ui->menuKobo),
      actionExit(ui->actionExit),
      actionWifi(ui->actionWifi),
      menuDebug(ui->menuDebug),
      actionRotate(ui->actionRotate),
      actionRefreshScreen(ui->actionRefreshScreen) {
    ui->setupUi(this);

#ifdef KOBO
    connect(ui->actionWifi, SIGNAL(triggered(bool)), this, SLOT(toggleWifi(bool)));
#endif
    connect(ui->actionExit, SIGNAL(triggered(bool)), this, SLOT(exitApplication()));
}

MainWidget::~MainWidget() {
    delete ui;
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
