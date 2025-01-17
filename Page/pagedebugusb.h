#ifndef PAGEDEBUGUSB_H
#define PAGEDEBUGUSB_H

#include "page.h"

class PageDebugUsb : public Page
{
    Q_OBJECT
public:
    PageDebugUsb(QWidget *parent);
    void mousePressEvent(QMouseEvent *ev) override;

    void update() override;
    void pageShow() override;
    void pageHide() override;
private:
    void init();
};

#endif // PAGEDEBUGUSB_H
