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


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

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
