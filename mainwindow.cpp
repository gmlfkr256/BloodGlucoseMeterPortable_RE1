#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    init();
    initConnect();

    stackedWidget->setCurrentIndex(1);
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

    listComponent<<comBat<<comBle<<comClock<<comHome<<comMenu;
}

void MainWindow::initConnect()
{
    connect(stackedWidget,&QStackedWidget::currentChanged,this,&MainWindow::currentPageChanged);
}

void MainWindow::currentPageChanged(int index)
{
    ShowComponents();

    if(index == stackedWidget->indexOf(pagePassword))
    {
        HideComponents();
    }
}

void MainWindow::ShowComponents()
{
    for(CustomComponent *com : listComponent)
    {
        com->show();
    }
}

void MainWindow::HideComponents()
{
    for(CustomComponent *com : listComponent)
    {
        com->hide();
    }
}

