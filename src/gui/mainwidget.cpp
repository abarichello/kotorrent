#include "mainwidget.h"

MainWidget::MainWidget(QWidget* parent)
    : QWidget(parent),
      ui(new Ui::MainWidget),
      console(new Console()),
      menu(ui->menu),
      actionExit(ui->actionExit),
      menuKobo(ui->menuKobo),
      actionWifi(ui->actionWifi),
      menuDebug(ui->menuDebug),
      actionToggleConsole(ui->actionToggleConsole),
      actionRotate(ui->actionRotate),
      actionRefreshScreen(ui->actionRefreshScreen) {
    ui->setupUi(this);

#ifdef KOBO
    connect(ui->actionWifi, SIGNAL(triggered(bool)), this, SLOT(toggleWifi(bool)));
#endif
    connect(ui->actionExit, SIGNAL(triggered(bool)), this, SLOT(exitApplication()));
    connect(ui->actionToggleConsole, SIGNAL(triggered(bool)), this, SLOT(exitApplication()));

    console->show();
    this->setCentralWidget(console);
}

MainWidget::~MainWidget() {
    delete ui;
}

void MainWidget::exitApplication() {
    QApplication::quit();
}

void MainWidget::toggleConsole() {
    console->show();
}

#ifdef KOBO
void MainWidget::toggleWifi(bool triggered) {
    qInfo() << "Toggle wifi to:" << triggered;
    triggered ? KoboPlatformFunctions::enableWiFiConnection() : KoboPlatformFunctions::disableWiFiConnection();
    qInfo() << "Wifi status:" << KoboPlatformFunctions::testInternetConnection();
}
#endif
