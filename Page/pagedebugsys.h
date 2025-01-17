#ifndef PAGEDEBUGSYS_H
#define PAGEDEBUGSYS_H

#include "page.h"

class PageDebugSys : public Page
{
    Q_OBJECT
public:
    PageDebugSys(QWidget *parent);
    void mousePressEvent(QMouseEvent *ev) override;

    void update() override;
    void pageShow() override;
    void pageHide() override;
private:
    void init();
};

#endif // PAGEDEBUGSYS_H
