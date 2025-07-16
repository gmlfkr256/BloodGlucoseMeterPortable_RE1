#ifndef PAGECALIRESULTMULTICONFIRM_H
#define PAGECALIRESULTMULTICONFIRM_H

#include "page.h"

class PageCaliResultMultiConfirm: public Page
{
    Q_OBJECT
public:
    PageCaliResultMultiConfirm(QWidget *parent);
    void mousePressEvent(QMouseEvent *ev) override;
    QString strDirPath = "/ImageCaliResultMultiPopup";

    QLabel* labelText;

    CustomButtonOK* customButtonOK;
    CustomButtonCancel* customButtonCancel;

    void update() override;
    void pageShow() override;
    void pageHide() override;
private:
    void init();
};

#endif // PAGECALIRESULTMULTICONFIRM_H
