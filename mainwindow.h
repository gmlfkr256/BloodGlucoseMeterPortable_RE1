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


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    bool eventFilter(QObject *watched, QEvent *event);

    Singleton &instance = Singleton::getInstance();

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

    QList<int> listComHiddenPageIndex;
    QMap<PageNum,QString> mapPageNumName;
public slots:
     void setPageByPageNum(PageNum pageNum);
private:
    void initGuiApi();
    void init();
    void initConnect();
    void currentPageChanged(int index);
    void ShowComponents();
    void HideComponents();

    QString getPageName(PageNum pageNum);
};
#endif // MAINWINDOW_H
