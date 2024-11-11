#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    initGuiApi();

    init();
    initConnect();
}

MainWindow::~MainWindow()
{

}

void MainWindow::initGuiApi()
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

    pagePasswordConfirm =new PagePasswordConfirm(this);
    stackedWidget->addWidget(pagePasswordConfirm);

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

    HideComponents();
}

void MainWindow::initConnect()
{
    connect(stackedWidget,&QStackedWidget::currentChanged,this,&MainWindow::currentPageChanged);
    connect(stackedWidget,&QStackedWidget::currentChanged,this,[this](int index){
        Page *currentPage = qobject_cast<Page *>(stackedWidget->widget(index));
        qDebug()<<"update() index: "<<index;
        if(currentPage)
            currentPage->update();
    });
    connect(pagePassword,&PagePassword::signalPassword,this,[this](){stackedWidget->setCurrentIndex(PAGE_PASSWORD_CONFIRM);});
    connect(pagePasswordConfirm,&PagePasswordConfirm::signalShowPageHome,this,[this](){stackedWidget->setCurrentIndex(PAGE_HOME);});
}

void MainWindow::currentPageChanged(int index)
{
    QWidget *currentPage = stackedWidget->widget(index);

    if(listComHiddenPages.contains(currentPage))
    {
        HideComponents();
    }
    else
    {
        ShowComponents();
    }
}

void MainWindow::ShowComponents()
{
    for(CustomComponent *com : listComponent)
    {
        com->show();
        com->raise();
    }
}

void MainWindow::HideComponents()
{
    for(CustomComponent *com : listComponent)
    {
        com->hide();
        com->raise();
    }
}

