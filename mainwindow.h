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
#include "Page/pagehome.h"
#include "Page/pageselect.h"


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

    PagePassword *pagePassword;
    PageHome *pageHome;
    PageSelect *pageSelect;
private:
    void init();
};
#endif // MAINWINDOW_H
