#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    init();
}

MainWindow::~MainWindow()
{

}

void MainWindow::init()
{
    LoadFont loadFont;
    loadFont.Load();

    stackedWidget = new QStackedWidget(this);
    stackedWidget->setGeometry(this->geometry());

    pagePassword = new PagePassword(this);
    stackedWidget->addWidget(pagePassword);
    pageHome = new PageHome(this);
    stackedWidget->addWidget(pageHome);
    pageSelect = new PageSelect(this);
    stackedWidget->addWidget(pageSelect);

    comBat = new ComponentBattery(stackedWidget);
    comBle = new ComponentBluetooth(stackedWidget);
    comClock = new ComponentClock(stackedWidget);
    comHome = new ComponentHome(stackedWidget);
    comMenu = new ComponentMenu(stackedWidget);
}

