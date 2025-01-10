#ifndef PAGECALIGAINCONFIRM_H
#define PAGECALIGAINCONFIRM_H

#include "page.h"

class PageCaliGainConfirm : public Page
{
    Q_OBJECT
public:
    PageCaliGainConfirm(QWidget *parent);
    void mousePressEvent(QMouseEvent *ev) override;
    QString strDirPath = "/ImageCaliGainConfirm";

    QLabel* labelTextGainConfirm;
    CustomButtonOK *customButtonOk;
    CustomButtonCancel *customButtonCancel;

    void update() override;
    void pageShow() override;
    void pageHide() override;
private:
    void init();

signals:
    //void signalShowPageNum(PageNum pageNum);
};

#endif // PAGECALIGAINCONFIRM_H
