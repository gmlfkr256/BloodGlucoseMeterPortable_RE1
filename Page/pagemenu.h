#ifndef PAGEMENU_H
#define PAGEMENU_H

#include "page.h"

typedef enum
{
    MENU_PAGE_0 = 0,
    MENU_PAGE_1,
    MENU_PAGE_MAX
} MenuPageIndex;

class PageMenu : public Page
{
    Q_OBJECT
public:
    PageMenu(QWidget *parent);
    void mousePressEvent(QMouseEvent *ev) override;
    QString strDirPath = "/ImageMenu";

    QLabel *labelArrowLeft;
    QLabel *labelArrowLeftTouch;
    QLabel *labelArrowRight;
    QLabel *labelArrowRightTouch;
    QLabel *labelButton[6];
    QLabel *labelButtonText[6];
    QString strButtonPathPng[6];

    MenuPageIndex selectPage = MENU_PAGE_0;
    //MenuPageIndex selectPagePrev = MENU_PAGE_0;

    QString strPathPngSound;
    QString strPathPngDateTime;
    QString strPathPngReverse;
    QString strPathPngHistory;
    QString strPathPngSleep;
    QString strPathPngTranslation;
    QString strPathPngUpgrade;
    QString strPathPngColor;
    QString strPathPngCalibration;
    QString strPathPngDeviceInfo;
    QString strPathPngDebug;
    QString strPathPngThreshold;
    QString strPathPngReset;
    QString strPathPngUser;

    void update() override;
    void pageShow() override;
    void pageHide() override;
private:
    void init();

signals:

};

#endif // PAGEMENU_H
