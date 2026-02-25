#ifndef PAGEHELP_H
#define PAGEHELP_H

#include "page.h"
#include "Component/componentwidgettextmove.h"

class PageHelp : public Page
{
    Q_OBJECT

public:
    PageHelp(QWidget *parent);
    void mousePressEvent(QMouseEvent *ev) override;
    void mouseReleaseEvent(QMouseEvent *ev) override;

    QString strDirPath = "/ImageHelp";

    QLabel *labelWindow;
    QLabel *labelTextBgTop;
    QLabel *labelTextBgCenter;
    QLabel *labelTextBgDown;

    QLabel *labelTextTop;
    //QLabel *labelTextCenter;
    ComponentWidgetTextMove *comText;
    QLabel *labelTextDown;

    QLabel *labelButtonGradientTop;
    QLabel *labelButtonGradientDown;

    QLabel *labelArrowTop;
    QLabel *labelArrowDown;

    QLabel *labelNumCurrent;
    QLabel *labelNumBar;
    QLabel *labelNumAll;

    //CustomButtonOK *customButtonOK;
    CustomButtonBack *customButtonBack;

    void update() override;
    void pageShow() override;
    void pageHide() override;

private:
    int m_nSelectIndex = 0;
    int m_nIndexRangeMax;

    QStringList m_strList;
    QTimer *timerPress;
    bool bIsTop = true;

    void init();
    void updateTextSlots();
    void moveNext();
    void movePrev();
    void setIndexNext();
    void setIndexPrev();
    void handleTimerPress();
    void handleTimerRelease();

signals:

};

#endif // PAGEHELP_H
