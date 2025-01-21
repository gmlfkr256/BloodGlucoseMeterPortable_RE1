#ifndef COMPONENTCLOCK_H
#define COMPONENTCLOCK_H

#include "customcomponent.h"



class ComponentClock : public CustomComponent
{
    Q_OBJECT
public:
    ComponentClock(QWidget *parent);
    void mousePressEvent(QMouseEvent *ev) override;

private:

    QLabel *labelClock;
    QTimer *timerClock;

    int nDebugCount = 0;
    int nDebugClockCount = 0;

    void init();
public slots:
    void update() override;
    void pageShow() override;
    void pageHide() override;

signals:
    void signalShowPageNum(PageNum pageNum);
};

#endif // COMPONENTCLOCK_H
