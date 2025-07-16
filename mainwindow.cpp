#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    init();
    initConnect();

    qApp->installEventFilter(this);

    instance.updateSysUserInfo();

#if DEVICE
    int nUser = USER_MAX;
    instance.guiApi.glucoseGetActUser(&nUser);

    if(nUser != USER_MAX)
    {
        qDebug()<<"userCheck";
        instance.actUserLogin(nUser);
        setPageByPageNum(PAGE_HOME);
    }
#endif
    instance.bIsStart = true;
}

MainWindow::~MainWindow()
{

}

void MainWindow::init()
{
#if DEVICE
    instance.guiApi.glucoseAttach();
    instance.guiApi.glucoseGetDispData(&instance.dispData);
    instance.guiApi.glucoseGetLangData(&instance.langData);
    qDebug()<<"get instance.langData.used: "<<instance.langData.used;
    instance.setDeviceLanguage(instance.langData.used);

    QThread::msleep(300);
    qDebug()<<"MainWindow - instance.dispData.dir: "<<instance.dispData.dir;
#endif

    LoadFont loadFont;
    loadFont.Load();
    instance.setDeviceLanguage(instance.langData.used);
    textResource.init();

    /*
    QLabel* pLabel = new QLabel("폰트 테스트입니다. 12345 ABCDE ñáéóú");
    QFont oFont("Noto Sans KR");
    oFont.setPointSize(16);
    pLabel->setFont(oFont);
    pLabel->show();

    qDebug() << "라벨 폰트 패밀리:" << pLabel->font().family();
    qDebug() << "라벨 폰트 info:" << pLabel->fontInfo().family();
    */

    stackedWidget = new QStackedWidget(this);
    stackedWidget->setGeometry(this->geometry());

    pageSelectUser = new PageSelectUser(this);
    stackedWidget->addWidget(pageSelectUser);
    listComHiddenPageIndex.append(stackedWidget->indexOf(pageSelectUser));
    qDebug()<<"====================== PAGE_SELECT_USER";

    pagePasswordAllChat = new PagePasswordAllChat(this);
    stackedWidget->addWidget(pagePasswordAllChat);
    listComHiddenPageIndex.append(stackedWidget->indexOf(pagePasswordAllChat));
    qDebug()<<"====================== PAGE_PASSWORD_ALLCHAT";

    pagePassword = new PagePassword(this);
    stackedWidget->addWidget(pagePassword);
    listComHiddenPageIndex.append(stackedWidget->indexOf(pagePassword));
    qDebug()<<"====================== PAGE_PASSWORD";

    pagePasswordConfirm = new PagePasswordConfirm(this);
    stackedWidget->addWidget(pagePasswordConfirm);
    listComHiddenPageIndex.append(stackedWidget->indexOf(pagePasswordConfirm));
    qDebug()<<"====================== PAGE_PASSWORD_CONFIRM";

    pageHome = new PageHome(this);
    stackedWidget->addWidget(pageHome);
    qDebug()<<"====================== PAGE_HOME";

    pageSelect = new PageSelect(this);
    stackedWidget->addWidget(pageSelect);
    qDebug()<<"====================== PAGE_SELECT";

    pageMenu = new PageMenu(this);
    stackedWidget->addWidget(pageMenu);
    qDebug()<<"====================== PAGE_MENU";

    pageCaliCheck = new PageCaliCheck(this);
    stackedWidget->addWidget(pageCaliCheck);
    qDebug()<<"====================== PAGE_CALI_CHECK";

    pageCaliGainConfirm = new PageCaliGainConfirm(this);
    stackedWidget->addWidget(pageCaliGainConfirm);
    qDebug()<<"====================== PAGE_CALI_GAIN_CONFRIM";

    pageGraph = new PageGarph(this);
    stackedWidget->addWidget(pageGraph);
    listComHiddenPageIndex.append(stackedWidget->indexOf(pageGraph));
    qDebug()<<"====================== PAGE_GRAPH";

    pageCaliGainResult = new PageCaliGainResult(this);
    stackedWidget->addWidget(pageCaliGainResult);
    qDebug()<<"====================== PAGE_CALI_GAIN_RESULT";

    pageCaliSelect = new PageCaliSelect(this);
    stackedWidget->addWidget(pageCaliSelect);
    qDebug()<<"====================== PAGE_CALI_SELECT";

    pageCaliSelectInfo = new PageCaliSelectInfo(this);
    stackedWidget->addWidget(pageCaliSelectInfo);
    qDebug()<<"====================== PAGE_CALI_SELECT_INFO";

    pageCaliConfirm = new PageCaliConfirm(this);
    stackedWidget->addWidget(pageCaliConfirm);
    qDebug()<<"====================== PAGE_CALI_CONFIRM";

    pageCaliValue = new PageCaliValue(this);
    stackedWidget->addWidget(pageCaliValue);
    qDebug()<<"====================== PAGE_CALI_VALUE";

    pageCaliResult = new PageCaliResult(this);
    stackedWidget->addWidget(pageCaliResult);
    qDebug()<<"====================== PAGE_CALI_RESULT";

    pageCaliResultMulti = new PageCaliResultMulti(this);
    stackedWidget->addWidget(pageCaliResultMulti);
    qDebug()<<"====================== PAGE_CALI_RESULT_MULTI";

    pageResult = new PageResult(this);
    stackedWidget->addWidget(pageResult);
    qDebug()<<"====================== PAGE_RESULT";

    pageInit = new PageInit(this);
    stackedWidget->addWidget(pageInit);
    qDebug()<<"====================== PAGE_INIT";

    pageInitConfirm = new PageInitConfirm(this);
    stackedWidget->addWidget(pageInitConfirm);
    qDebug()<<"====================== PAGE_INIT_CONFIRM";

    pageThreshold = new PageThreshold(this);
    stackedWidget->addWidget(pageThreshold);
    qDebug()<<"====================== PAGE_THRESHOLD";

    pageThresholdValue = new PageThresholdValue(this);
    stackedWidget->addWidget(pageThresholdValue);
    qDebug()<<"====================== PAGE_THRESHOLD_VALUE";

    pageSound = new PageSound(this);
    stackedWidget->addWidget(pageSound);
    qDebug()<<"====================== PAGE_SOUND";

    pageSleep = new PageSleep(this);
    stackedWidget->addWidget(pageSleep);
    qDebug()<<"====================== PAGE_SLEEP";

    pageDateTime = new PageDateTime(this);
    stackedWidget->addWidget(pageDateTime);
    qDebug()<<"====================== PAGE_DATETIME";

    pageUpgrade = new PageUpgrade(this);
    stackedWidget->addWidget(pageUpgrade);
    qDebug()<<"====================== PAGE_UPGRADE";

    pageUpgradeConfirm = new PageUpgradeConfirm(this);
    stackedWidget->addWidget(pageUpgradeConfirm);
    qDebug()<<"====================== PAGE_UPGRADE_CONFIRM";

    pageDeviceInfo = new PageDeviceInfo(this);
    stackedWidget->addWidget(pageDeviceInfo);
    qDebug()<<"====================== PAGE_DEVICE_INFO";

    pageUserInfo = new PageUserInfo(this);
    stackedWidget->addWidget(pageUserInfo);
    qDebug()<<"====================== PAGE_USER_INFO";

    pageBatteryPopup = new PageBatteryPopup(this);
    stackedWidget->addWidget(pageBatteryPopup);
    qDebug()<<"====================== PAGE_BATTERY_POPUP";

    pageReverse = new PageReverse(this);
    stackedWidget->addWidget(pageReverse);
    qDebug()<<"====================== PAGE_REVERSE";

    pageTrans = new PageTrans(this);
    stackedWidget->addWidget(pageTrans);
    qDebug()<<"====================== PAGE_TRANS";

    pageHistory = new PageHistory(this);
    stackedWidget->addWidget(pageHistory);
    qDebug()<<"====================== PAGE_HISTORY";

    pageHistoryResult = new PageHistoryResult(this);
    stackedWidget->addWidget(pageHistoryResult);
    qDebug()<<"====================== PAGE_HISTORY_RESULT";

    pageDebug = new PageDebug(this);
    stackedWidget->addWidget(pageDebug);
    listComHiddenPageIndex.append(stackedWidget->indexOf(pageDebug));
    qDebug()<<"====================== PAGE_DEBUG";

    pageDebugSys = new PageDebugSys(this);
    stackedWidget->addWidget(pageDebugSys);
    listComHiddenPageIndex.append(stackedWidget->indexOf(pageDebugSys));
    qDebug()<<"====================== PAGE_DEBUG_SYS";

    pageDebugUsb = new PageDebugUsb(this);
    stackedWidget->addWidget(pageDebugUsb);
    listComHiddenPageIndex.append(stackedWidget->indexOf(pageDebugUsb));
    qDebug()<<"====================== PAGE_DEBUG_USB";

    pageResultFail = new PageResultFail(this);
    stackedWidget->addWidget(pageResultFail);
    qDebug()<<"====================== PAGE_RESULT_FAIL";

    pageUpgradeFail = new PageUpagradeFail(this);
    stackedWidget->addWidget(pageUpgradeFail);
    qDebug()<<"====================== PAGE_UPGRADE_FAIL";

    pageCaliResultMultiConfirm = new PageCaliResultMultiConfirm(this);
    stackedWidget->addWidget(pageCaliResultMultiConfirm);
    qDebug()<<"====================== PAGE_CALI_RESULT_MULTI_CONFIRM";

    comBat = new ComponentBattery(stackedWidget);
    comBle = new ComponentBluetooth(stackedWidget);
    comClock = new ComponentClock(stackedWidget);
    comHome = new ComponentHome(stackedWidget);
    comMenu = new ComponentMenu(stackedWidget);

    listComponent<<comBat<<comBle<<comClock<<comHome<<comMenu;

    mapPageNumName =
    {
        {PAGE_SELECT_USER, "PageSelectUser"},
        {PAGE_PASSWORD_ALLCHAT, "PagePasswordAllCaht"},
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
        {PAGE_HISTORY_RESULT, "PageHistoryResult"},
        {PAGE_DEBUG, "PageDebug"},
        {PAGE_DEBUG_SYS, "PageDebugSys"},
        {PAGE_DEBUG_USB, "PageDebugUsb"},
        {PAGE_RESULT_FAIL, "PageResultFail"},
        {PAGE_UPGRADE_FAIL, "PageUpgradeFail"},
        {PAGE_CALI_RESULT_MULTI_CONFIRM, "PageCaliResultMultiConfirm"},

        {CUSTOM_BUTTON, "CustomButton"},
        {PAGE_MAX, "InvalidPage"}  // 예외 처리
    };

    HideComponents();

#if NEW_PASSWORD
    setPageByPageNum(PAGE_SELECT_USER);
#else
    setPageByPageNum(PAGE_PASSWORD);
#endif
}

void MainWindow::initConnect()
{
    connect(stackedWidget,&QStackedWidget::currentChanged,this,&MainWindow::currentPageChanged);

    //com
    connect(comHome,&ComponentHome::singalShowPageNum,this,&MainWindow::setPageByPageNum);
    connect(comMenu,&ComponentMenu::signalShowPageNum,this,&MainWindow::setPageByPageNum);
    connect(comBat,&ComponentBattery::signalShowPageNum,this,&MainWindow::setPageByPageNum);
    connect(comClock,&ComponentClock::signalShowPageNum,this,&MainWindow::setPageByPageNum);

    //page
    for(int i=0; i<stackedWidget->count(); i++)
    {
        Page* page = qobject_cast<Page*>(stackedWidget->widget(i));

        if(page)
        {
            connect(page,&Page::signalShowPageNum,this,&MainWindow::setPageByPageNum);
        }
        else
        {
            qDebug() << "Widget at index" << i << "is not a Page instance.";
        }
    }

    connect(pageHistoryResult,&PageHistoryResult::signalUpdateClock,comClock,&ComponentClock::update);
    connect(pageReverse,&PageReverse::signalComHide,this,&MainWindow::HideComponents);
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
    connect(pageHistoryResult,&PageHistoryResult::signalShowPageNum,this,&MainWindow::setPageByPageNum);
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

        if(pageNum == PAGE_HOME)
        {
            comHome->update();
            comBle->update();
        }
        else if(pageNum == PAGE_GRAPH)
        {
            pageGraph->initGraphPainter();
        }

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
            //qDebug()<<"MainWindow Touch Process - nSleepTimeCount: "<<instance.nSleepTimeCount;

            QTimer::singleShot(50,[&](){isEventHandled = false;});
            return false;
        }
    }

    return QMainWindow::eventFilter(watched, event);
}
