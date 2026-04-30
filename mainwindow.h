#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "Loadfont.h"

#include "Component/componentbattery.h"
#include "Component/componentbluetooth.h"
#include "Component/componentclock.h"
#include "Component/componenthome.h"
#include "Component/componentmenu.h"

#include "Page/pagepassword.h"
#include "Page/pagepasswordconfirm.h"
#include "Page/pagehome.h"
#include "Page/pageselect.h"
#include "Page/pagemenu.h"
#include "Page/pagecalicheck.h"
#include "Page/pagecaligainconfirm.h"
#include "Page/pagegarph.h"
#include "Page/pagecaligainresult.h"
#include "Page/pagecaliselect.h"
#include "Page/pagecaliselectinfo.h"
#include "Page/pagecaliconfirm.h"
#include "Page/pagecalivalue.h"
#include "Page/pagecaliresult.h"
#include "Page/pagecaliresultmulti.h"
#include "Page/pageresult.h"
#include "Page/pageinit.h"
#include "Page/pageinitconfirm.h"
#include "Page/pagethreshold.h"
#include "Page/pagethresholdvalue.h"
#include "Page/pagesound.h"
#include "Page/pagesleep.h"
#include "Page/pagedatetime.h"
#include "Page/pageupgrade.h"
#include "Page/pageupgradeconfirm.h"
#include "Page/pagedeviceinfo.h"
#include "Page/pageuserinfo.h"
#include "Page/pagebatterypopup.h"
#include "Page/pagereverse.h"
#include "Page/pagetrans.h"
#include "Page/pagehistory.h"
#include "Page/pagehistoryresult.h"
#include "Page/pagedebug.h"
#include "Page/pagedebugsys.h"
#include "Page/pagedebugusb.h"
#include "Page/pagedebugphantom.h"
#include "Page/pageresultfail.h"
#include "Page/pageupagradefail.h"
#include "Page/pagepasswordallchat.h"
#include "Page/pageselectuser.h"
#include "Page/pagecaliresultmulticonfirm.h"
#include "Page/pagecaliselectconfirm.h"
#include "Page/pageelapsednoticepopup.h"
#include "Page/pagebloodcheck.h"
#include "Page/pagebloodnoticepopup.h"
#include "Page/pageusercheck.h"
#include "Page/pagebloodchecknotice.h"
#include "Page/pagecalivaluenotice.h"
#include "Page/pageusernotice.h"
#include "Page/pageuserfinger.h"
#include "Page/pagecalinotice.h"
#include "Page/pageuserchecknotice.h"
#include "Page/pageusercautions.h"
#include "Page/pagehelp.h"
#include "Page/pagefaq.h"
#include "Page/pageerrorhelp.h"
#include "Page/pagecaliselectre.h"
#include "Page/pageresponse.h"
#include "Page/pageresponsere.h"
#include "Page/pagefaqre.h"
#include "Page/pagehelpre.h"
#include "Page/pageerrorhelpre.h"
#include "Page/pagehelpindex.h"
#include "Page/pagefaqindex.h"
#include "Page/pageerrorhelpindex.h"
#include "Page/pagehelpresponse.h"
#include "Page/pagefaqresponse.h"
#include "Page/pageerrorhelpresponse.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    bool eventFilter(QObject *watched, QEvent *event);

    Singleton &instance = Singleton::getInstance();
    TextResource &textResource = TextResource::getInstance();

    QStackedWidget *stackedWidget;
    ComponentBattery *comBat;
    ComponentBluetooth *comBle;
    ComponentClock *comClock;
    ComponentHome *comHome;
    ComponentMenu *comMenu;
    QList<CustomComponent*> listComponent;

    PagePassword *pagePassword;
    PagePasswordConfirm *pagePasswordConfirm;
    PageHome *pageHome;
    PageSelect *pageSelect;
    PageMenu *pageMenu;
    PageCaliCheck *pageCaliCheck;
    PageCaliGainConfirm *pageCaliGainConfirm;
    PageGarph *pageGraph;
    PageCaliGainResult *pageCaliGainResult;
    PageCaliSelect *pageCaliSelect;
    PageCaliSelectInfo *pageCaliSelectInfo;
    PageCaliConfirm *pageCaliConfirm;
    PageCaliValue *pageCaliValue;
    PageCaliResult *pageCaliResult;
    PageCaliResultMulti *pageCaliResultMulti;
    PageResult *pageResult;
    PageInit *pageInit;
    PageInitConfirm *pageInitConfirm;
    PageThreshold *pageThreshold;
    PageThresholdValue *pageThresholdValue;
    PageSound *pageSound;
    PageSleep *pageSleep;
    PageDateTime *pageDateTime;
    PageUpgrade *pageUpgrade;
    PageUpgradeConfirm *pageUpgradeConfirm;
    PageDeviceInfo *pageDeviceInfo;
    PageUserInfo *pageUserInfo;
    PageBatteryPopup *pageBatteryPopup;
    PageReverse *pageReverse;
    PageTrans *pageTrans;
    PageHistory *pageHistory;
    PageHistoryResult *pageHistoryResult;
    PageDebug *pageDebug;
    PageDebugSys *pageDebugSys;
    PageDebugUsb *pageDebugUsb;
    PageDebugPhantom *pageDebugPhantom;
    PageResultFail *pageResultFail;
    PageUpagradeFail *pageUpgradeFail;
    PagePasswordAllChat *pagePasswordAllChat;
    PageSelectUser *pageSelectUser;
    PageCaliResultMultiConfirm *pageCaliResultMultiConfirm;
    PageCaliSelectConfirm *pageCaliSelectConfirm;
    PageBloodCheck *pageBloodCheck;
    PageElapsedNoticePopup *pageElapsedNoticePopup;
    PageBloodNoticePopup *pageBloodNoticePopup;
    PageUserCheck *pageUserCheck;
    PageBloodCheckNotice *pageBloodCheckNotice;
    PageCaliValueNotice *pageCaliValueNotice;
    PageUserNotice *pageUserNotice;
    PageUserFinger *pageUserFinger;
    PageCaliNotice *pageCaliNotice;
    PageUserCheckNotice *pageUserCheckNotice;
    PageUserCautions *pageUserCautions;
    PageHelp *pageHelp;
    PageFaq *pageFaq;
    PageErrorHelp *pageErrorHelp;
    PageCaliSelectRe *pageCaliSelectRe;
    PageResponse *pageResponse;
    PageResponseRe *pageResponseRe;
    PageFaqRe *pageFaqRe;
    PageHelpRe *pageHelpRe;
    PageErrorHelpRe *pageErrorHelpRe;
    PageHelpIndex *pageHelpIndex;
    PageFaqIndex *pageFaqIndex;
    PageErrorHelpIndex *pageErrorHelpIndex;
    PageHelpResponse *pageHelpResponse;
    PageFaqResponse *pageFaqResponse;
    PageErrorHelpResponse *pageErrorResponse;

    QList<int> listComHiddenPageIndex;
    QMap<PageNum,QString> mapPageNumName;
    QList<int> listComDisablePageIndex;
public slots:
     void setPageByPageNum(PageNum pageNum);
private:
    void init();
    void initConnect();
    void currentPageChanged(int index);
    void ShowComponents();
    void HideComponents();
    void componentsEnable();
    void componentsDisable();

    QString getPageName(PageNum pageNum);
};
#endif // MAINWINDOW_H
