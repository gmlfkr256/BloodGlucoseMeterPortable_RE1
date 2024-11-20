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
    listComHiddenPageIndex.append(stackedWidget->indexOf(pagePassword));

    pagePasswordConfirm =new PagePasswordConfirm(this);
    stackedWidget->addWidget(pagePasswordConfirm);
    listComHiddenPageIndex.append(stackedWidget->indexOf(pagePasswordConfirm));

    pageHome = new PageHome(this);
    stackedWidget->addWidget(pageHome);

    pageSelect = new PageSelect(this);
    stackedWidget->addWidget(pageSelect);

    pageMenu = new PageMenu(this);
    stackedWidget->addWidget(pageMenu);

    pageCaliCheck = new PageCaliCheck(this);
    stackedWidget->addWidget(pageCaliCheck);

    pageCaliGainConfirm = new PageCaliGainConfirm(this);
    stackedWidget->addWidget(pageCaliGainConfirm);

    pageGraph = new PageGarph(this);
    stackedWidget->addWidget(pageGraph);
    listComHiddenPageIndex.append(stackedWidget->indexOf(pageGraph));

    pageCaliGainResult = new PageCaliGainResult(this);
    stackedWidget->addWidget(pageCaliGainResult);

    pageCaliSelect = new PageCaliSelect(this);
    stackedWidget->addWidget(pageCaliSelect);

    pageCaliSelectInfo = new PageCaliSelectInfo(this);
    stackedWidget->addWidget(pageCaliSelectInfo);

    pageCaliConfirm = new PageCaliConfirm(this);
    stackedWidget->addWidget(pageCaliConfirm);

    pageCaliValue = new PageCaliValue(this);
    stackedWidget->addWidget(pageCaliValue);

    comBat = new ComponentBattery(stackedWidget);
    comBle = new ComponentBluetooth(stackedWidget);
    comClock = new ComponentClock(stackedWidget);
    comHome = new ComponentHome(stackedWidget);
    comMenu = new ComponentMenu(stackedWidget);

    listComponent<<comBat<<comBle<<comClock<<comHome<<comMenu;

    mapPageNumName =
    {
        {PAGE_PASSWORD, "PagePassword"},
        {PAGE_PASSWORD_CONFIRM, "PagePasswordConfirm"},
        {PAGE_HOME, "PageHome"},
        {PAGE_SELECT, "PageSelect"},
        {PAGE_MENU, "PageMenu"},
        {PAGE_CALI_CHECK, "PageCaliCheck"},
        {PAGE_CALI_GAIN_CONFIRM, "PageCaliGainConfirm"},
        {PAGE_GRAPH, "PageGraph"},
        {PAGE_CALI_GAIN_RESULT, "PageCaliGainResult"},
        {PAGE_CALI_SELECT, "PageCaliSelect"},
        {PAGE_CALI_SELECT_INFO, "PageCaliSelectInfo"},
        {PAGE_CALI_CONFIRM, "PageCaliConfirm"},
        {PAGE_CALI_VALUE, "PageCaliValue"},

        {PAGE_CALIBRATION, "PageCalibration"},
        {PAGE_CALI_SELECT, "PageCaliSelect"},
        {PAGE_THRESHOLD, "PageThreshold"},
        {PAGE_HISTORY, "PageHistory"},
        {PAGE_SOUND, "PageSound"},
        {PAGE_SLEEP, "PageSleep"},
        {PAGE_REVERSE, "PageReverse"},
        {PAGE_DATETIME, "PageDateTime"},
        {PAGE_TRANSLATION, "PageTranslation"},
        {PAGE_UPGRADE, "PageUpgrade"},
        {PAGE_DEVICEINFO, "PageDeviceInfo"},
        {PAGE_RESET, "PageReset"},
        {PAGE_USER, "PageUser"},
        {PAGE_COLOR, "PageColor"},
        {CUSTOM_BUTTON, "CustomButton"},
        {PAGE_MAX, "InvalidPage"}  // 예외 처리
    };

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

    //com
    connect(comHome,&ComponentHome::singalShowPageHome,this,[this](){stackedWidget->setCurrentIndex(PAGE_HOME);});
    connect(comMenu,&ComponentMenu::signalShowPageMenu,this,[this](){stackedWidget->setCurrentIndex(PAGE_MENU);});

    //page
    connect(pagePassword,&PagePassword::signalPassword,this,[this](){stackedWidget->setCurrentIndex(PAGE_PASSWORD_CONFIRM);});
    connect(pagePasswordConfirm,&PagePasswordConfirm::signalShowPageHome,this,[this](){stackedWidget->setCurrentIndex(PAGE_HOME);});
    connect(pageHome,&PageHome::signalShowPageSelect,this,[this](){stackedWidget->setCurrentIndex(PAGE_SELECT); pageSelect->update();});
    connect(pageSelect,&PageSelect::signalShowPageHome,this,[this](){stackedWidget->setCurrentIndex(PAGE_HOME);});
    connect(pageMenu, &PageMenu::signalShowPageNum, this,&MainWindow::setPageByPageNum);
    connect(pageCaliCheck, &PageCaliCheck::signalShowPageNum,this,&MainWindow::setPageByPageNum);
    connect(pageCaliGainConfirm, &PageCaliGainConfirm::signalShowPageNum,this,&MainWindow::setPageByPageNum);
    connect(pageGraph, &PageGarph::signalShowPageNum,this,&MainWindow::setPageByPageNum);
    connect(pageCaliGainResult, &PageCaliGainResult::signalShowPageNum,this,&MainWindow::setPageByPageNum);
    connect(pageCaliSelect, &PageCaliSelect::signalShowPageNum,this,&MainWindow::setPageByPageNum);
    connect(pageCaliSelectInfo, &PageCaliSelectInfo::signalShowPageNum,this,&MainWindow::setPageByPageNum);
    connect(pageCaliConfirm, &PageCaliConfirm::signalShowPageNum,this,&MainWindow::setPageByPageNum);
}

void MainWindow::currentPageChanged(int index)
{
    if(listComHiddenPageIndex.contains(index))
    {
        HideComponents();
    }
    else
    {
        ShowComponents();
    }
}

void MainWindow::setPageByPageNum(PageNum pageNum)
{
    qDebug() << "set pageName: "<<getPageName(pageNum);
    if (stackedWidget && pageNum >= 0 && pageNum < stackedWidget->count()) {
        stackedWidget->setCurrentIndex(static_cast<int>(pageNum));

        Page *page = qobject_cast<Page*>(stackedWidget->currentWidget());
        if(page)
            page->pageShow();
    } else {
        qDebug() << "[fail] Invalid pageNum:" << static_cast<int>(pageNum)<<" page open fail";
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

QString MainWindow::getPageName(PageNum pageNum)
{
    if(mapPageNumName.contains(pageNum))
        return mapPageNumName.value(pageNum);
    else
        return QString("This page is empty, pageNum:"+QString::number(pageNum));
}
