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
    QList<PageNum> listPageNum;
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
    void signalShowPageNum(PageNum pageNum);
    /*
    void signalShowPageCalibration();
    void signalShowPageThreshold();
    void signalShowPageHistory();
    void signalShowPageSound();
    void signalShowPageSleep();
    void signalShowPageReverse();

    void signalShowPageDateTime();
    void signalShowPageTranslation();
    void signalShowPageUpgrade();
    void signalShowPageDeviceInfo();
    void signalShowPageReset();
    void signalShowPageUser();

    void signalShowPageColor();
    */
};

#endif // PAGEMENU_H
