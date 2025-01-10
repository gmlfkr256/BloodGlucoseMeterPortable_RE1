#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    initGuiApi();

    init();
    initConnect();

    qApp->installEventFilter(this);
}

MainWindow::~MainWindow()
{

}

void MainWindow::initGuiApi()
{

}

void MainWindow::init()
{
#if DEVICE
    instance.guiApi.glucoseAttach();
    instance.guiApi.glucoseGetDispData(&instance.dispData);
#endif

    LoadFont loadFont;
    loadFont.Load();

    stackedWidget = new QStackedWidget(this);
    stackedWidget->setGeometry(this->geometry());

    pagePassword = new PagePassword(this);
    stackedWidget->addWidget(pagePassword);
    listComHiddenPageIndex.append(stackedWidget->indexOf(pagePassword));

    pagePasswordConfirm = new PagePasswordConfirm(this);
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

    pageCaliResult = new PageCaliResult(this);
    stackedWidget->addWidget(pageCaliResult);

    pageCaliResultMulti = new PageCaliResultMulti(this);
    stackedWidget->addWidget(pageCaliResultMulti);

    pageResult = new PageResult(this);
    stackedWidget->addWidget(pageResult);

    pageInit = new PageInit(this);
    stackedWidget->addWidget(pageInit);

    pageInitConfirm = new PageInitConfirm(this);
    stackedWidget->addWidget(pageInitConfirm);

    pageThreshold = new PageThreshold(this);
    stackedWidget->addWidget(pageThreshold);

    pageThresholdValue = new PageThresholdValue(this);
    stackedWidget->addWidget(pageThresholdValue);

    pageSound = new PageSound(this);
    stackedWidget->addWidget(pageSound);

    pageSleep = new PageSleep(this);
    stackedWidget->addWidget(pageSleep);

    pageDateTime = new PageDateTime(this);
    stackedWidget->addWidget(pageDateTime);

    pageUpgrade = new PageUpgrade(this);
    stackedWidget->addWidget(pageUpgrade);

    pageUpgradeConfirm = new PageUpgradeConfirm(this);
    stackedWidget->addWidget(pageUpgradeConfirm);

    pageDeviceInfo = new PageDeviceInfo(this);
    stackedWidget->addWidget(pageDeviceInfo);

    pageUserInfo = new PageUserInfo(this);
    stackedWidget->addWidget(pageUserInfo);

    pageBatteryPopup = new PageBatteryPopup(this);
    stackedWidget->addWidget(pageBatteryPopup);

    pageReverse = new PageReverse(this);
    stackedWidget->addWidget(pageReverse);

    pageTrans = new PageTrans(this);
    stackedWidget->addWidget(pageTrans);

    pageHistory = new PageHistory(this);
    stackedWidget->addWidget(pageHistory);

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
        {PAGE_CALI_RESULT, "PageCaliResult"},
        {PAGE_CALI_RESULT_MULTI, "PageCaliResultMulti"},
        {PAGE_RESULT,"PageResult"},
        {PAGE_INIT,"PageInit"},
        {PAGE_INIT_CONFIRM,"PageInitConfirm"},
        {PAGE_THRESHOLD, "PageThreshold"},
        {PAGE_THRESHOLD_VALUE, "PageThresholdValue"},
        {PAGE_SOUND, "PageSound"},
        {PAGE_SLEEP, "PageSleep"},
        {PAGE_DATETIME, "PageDateTime"},
        {PAGE_UPGRADE, "PageUpgrade"},
        {PAGE_UPGRADE_CONFIRM, "PageUpgradeConfirm"},
        {PAGE_DEVICEINFO, "PageDeviceInfo"},
        {PAGE_USERINFO, "PageUserInfo"},
        {PAGE_BATPOPUP, "PageBatteryPopup"},
        {PAGE_REVERSE, "PageReverse"},
        {PAGE_TRANS, "PageTrans"},
        {PAGE_HISTORY, "PageHistory"},

        {CUSTOM_BUTTON, "CustomButton"},
        {PAGE_MAX, "InvalidPage"}  // 예외 처리
    };

    HideComponents();
#if DEVICE
    instance.updateSysUserInfo();
#endif
}

void MainWindow::initConnect()
{
    connect(stackedWidget,&QStackedWidget::currentChanged,this,&MainWindow::currentPageChanged);

    //com
    connect(comHome,&ComponentHome::singalShowPageNum,this,&MainWindow::setPageByPageNum);
    connect(comMenu,&ComponentMenu::signalShowPageNum,this,&MainWindow::setPageByPageNum);
    connect(comBat,&ComponentBattery::signalShowPageNum,this,&MainWindow::setPageByPageNum);

    //page
    for(int i=0; i<stackedWidget->count(); i++)
    {
        Page* page = qobject_cast<Page*>(stackedWidget->widget(i));

        connect(page,&Page::signalShowPageNum,this,&MainWindow::setPageByPageNum);
    }
    /*
    connect(pagePassword,&PagePassword::signalShowPageNum,this,&MainWindow::setPageByPageNum);
    connect(pagePasswordConfirm,&PagePasswordConfirm::signalShowPageNum,this,&MainWindow::setPageByPageNum);
    connect(pageHome,&PageHome::signalShowPageNum,this,&MainWindow::setPageByPageNum);
    connect(pageSelect,&PageSelect::signalShowPageNum,this,&MainWindow::setPageByPageNum);
    connect(pageMenu, &PageMenu::signalShowPageNum, this,&MainWindow::setPageByPageNum);
    connect(pageCaliCheck, &PageCaliCheck::signalShowPageNum,this,&MainWindow::setPageByPageNum);
    connect(pageCaliGainConfirm, &PageCaliGainConfirm::signalShowPageNum,this,&MainWindow::setPageByPageNum);
    connect(pageGraph, &PageGarph::signalShowPageNum,this,&MainWindow::setPageByPageNum);
    connect(pageCaliGainResult, &PageCaliGainResult::signalShowPageNum,this,&MainWindow::setPageByPageNum);
    connect(pageCaliSelect, &PageCaliSelect::signalShowPageNum,this,&MainWindow::setPageByPageNum);
    connect(pageCaliSelectInfo, &PageCaliSelectInfo::signalShowPageNum,this,&MainWindow::setPageByPageNum);
    connect(pageCaliConfirm, &PageCaliConfirm::signalShowPageNum,this,&MainWindow::setPageByPageNum);
    connect(pageCaliValue, &PageCaliValue::signalShowPageNum,this,&MainWindow::setPageByPageNum);
    connect(pageCaliResult, &PageCaliResult::signalShowPageNum,this,&MainWindow::setPageByPageNum);
    connect(pageCaliResultMulti, &PageCaliResultMulti::signalShowPageNum,this,&MainWindow::setPageByPageNum);
    connect(pageResult, &PageResult::signalShowPageNum,this,&MainWindow::setPageByPageNum);
    connect(pageInit, &PageInit::signalShowPageNum,this,&MainWindow::setPageByPageNum);
    connect(pageInitConfirm, &PageInitConfirm::signalShowPageNum,this,&MainWindow::setPageByPageNum);
    connect(pageThreshold, &PageThreshold::signalShowPageNum,this,&MainWindow::setPageByPageNum);
    connect(pageThresholdValue, &PageThresholdValue::signalShowPageNum,this,&MainWindow::setPageByPageNum);
    connect(pageSound,&PageSound::signalShowPageNum,this,&MainWindow::setPageByPageNum);
    connect(pageSleep,&PageSleep::signalShowPageNum,this,&MainWindow::setPageByPageNum);
    connect(pageDateTime,&PageDateTime::signalShowPageNum,this,&MainWindow::setPageByPageNum);
    connect(pageUpgrade,&PageUpgrade::signalShowPageNum,this,&MainWindow::setPageByPageNum);
    connect(pageUpgradeConfirm,&PageUpgradeConfirm::signalShowPageNum,this,&MainWindow::setPageByPageNum);
    connect(pageDeviceInfo,&PageDeviceInfo::signalShowPageNum,this,&MainWindow::setPageByPageNum);
    connect(pageUserInfo,&PageUserInfo::signalShowPageNum,this,&MainWindow::setPageByPageNum);
    connect(pageBatteryPopup,&PageBatteryPopup::signalShowPageNum,this,&MainWindow::setPageByPageNum);
    connect(pageReverse,&PageReverse::signalShowPageNum,this,&MainWindow::setPageByPageNum);
    connect(pageTrans,&PageTrans::signalShowPageNum,this,&MainWindow::setPageByPageNum);
    connect(pageHistory,&PageHistory::signalShowPageNum,this,&MainWindow::setPageByPageNum);
    */
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

    if (stackedWidget && pageNum >= 0 && pageNum < stackedWidget->count())
    {
        stackedWidget->setCurrentIndex(static_cast<int>(pageNum));

        Page *page = qobject_cast<Page*>(stackedWidget->currentWidget());
        if(page)
            page->pageShow();

    }
    else
    {
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
    if(pageNum != PAGE_GRAPH && pageNum != PAGE_BATPOPUP)
        instance.currentPage = pageNum;

    if(mapPageNumName.contains(pageNum))
        return mapPageNumName.value(pageNum);
    else
        return QString("This page is empty, pageNum:"+QString::number(pageNum));
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    static bool isEventHandled = false;

    if(event->type() == QEvent::MouseButtonPress)
    {
        if(!isEventHandled)
        {
            isEventHandled = true;

            instance.nSleepTimeCount = 0;
            qDebug()<<"MainWindow Touch Process - nSleepTimeCount: "<<instance.nSleepTimeCount;

            QTimer::singleShot(50,[&](){isEventHandled = false;});
            return false;
        }
    }

    return QMainWindow::eventFilter(watched, event);
}
