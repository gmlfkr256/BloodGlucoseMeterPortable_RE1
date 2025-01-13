#ifndef COMPONENTCLOCK_H
#define COMPONENTCLOCK_H

#include "customcomponent.h"



class ComponentClock : public CustomComponent
{
    Q_OBJECT
public:
    ComponentClock(QWidget *parent);
    bool bIsHistorySelect = false;

private:

    QLabel *labelClock;
    QTimer *timerClock;

    void init();
public slots:
    void update() override;
    void pageShow() override;
    void pageHide() override;
};

#endif // COMPONENTCLOCK_H
