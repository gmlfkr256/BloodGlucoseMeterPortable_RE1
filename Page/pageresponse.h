#ifndef PAGERESPONSE_H
#define PAGERESPONSE_H

#include "page.h"

class PageResponse : public Page
{
    Q_OBJECT
public:
    PageResponse(QWidget *parent);
    void mousePressEvent(QMouseEvent *ev) override;
    void mouseReleaseEvent(QMouseEvent *ev) override;

    QString strDirPath = "/ImageResponse";

    QWidget *widgetWindow;
    QLabel *labelText;

    QLabel *labelArrowTop;
    QLabel *labelArorwDown;

    QLabel *labelNumCurrent;
    QLabel *labelNumBar;
    QLabel *labelNumAll;

    QLabel *labelTouchTop;
    QLabel *labelTouchDown;

    CustomButtonOK *customButtonOK;

    void update() override;
    void pageShow() override;
    void pageHide() override;
private:
    int m_nCurrentLine = 0;
    int m_nMaxLine = 0;
    int m_nStep = 0;

    QTimer *timerPress;
    bool bIsTop = true;

    void init();
    void textDown();
    void textUp();
    void handleTimerPress();
    void handleTimerRelease();
signals:
};

#endif // PAGERESPONSE_H
