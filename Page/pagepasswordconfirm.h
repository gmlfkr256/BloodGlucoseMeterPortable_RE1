#ifndef PAGEPASSWORDCONFIRM_H
#define PAGEPASSWORDCONFIRM_H

#include "page.h"

class PagePasswordConfirm : public Page
{
    Q_OBJECT
public:
    PagePasswordConfirm(QWidget *parent);
    void mousePressEvent(QMouseEvent *ev) override;

    QString strDirPath = "/ImagePasswordConfirm";

    QLabel *labelTitle;
    QLabel *labelText;
    CustomButtonOK *customButtonOK;
    CustomButtonCancel *customButtonCancel;

    void update() override;
    void pageShow() override;
    void pageHide() override;
private:
    void init();

signals:
    //void signalShowPageNum(PageNum pageNum);
};

#endif // PAGEPASSWORDCONFIRM_H
