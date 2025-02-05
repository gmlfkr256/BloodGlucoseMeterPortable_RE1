#ifndef PAGEDEBUGUSB_H
#define PAGEDEBUGUSB_H

#include "page.h"

class PageDebugUsb : public Page
{
    Q_OBJECT
public:
    PageDebugUsb(QWidget *parent);
    void mousePressEvent(QMouseEvent *ev) override;

    bool bIsGetUsbData = false;
    int usbData = GAPI_ACT_START;

    QLabel *labelBg;
    QLabel *labelTitle;
    QLabel *labelUsbText;
    QLabel *labelUsbButton;

    CustomButtonSave *customButtonSave;
    CustomButtonCancel *customButtonCancel;

    void update() override;
    void pageShow() override;
    void pageHide() override;
private:
    void init();
};

#endif // PAGEDEBUGUSB_H
