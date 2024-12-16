#ifndef PAGEINITCONFIRM_H
#define PAGEINITCONFIRM_H

#include "page.h"

class PageInitConfirm : public Page
{
    Q_OBJECT
public:
    PageInitConfirm(QWidget* parent);
    void mousePressEvent(QMouseEvent *ev) override;

    QString strDirPath = "/ImageInitConfirm";

    QLabel *labelText;
    CustomButtonOK *customButtonOK;
    CustomButtonCancel *customButtonCancel;

    void update() override;
    void pageShow() override;
    void pageHide() override;
private:
    void init();

signals:
    void signalShowPageNum(PageNum pageNum);
};

#endif // PAGEINITCONFIRM_H
