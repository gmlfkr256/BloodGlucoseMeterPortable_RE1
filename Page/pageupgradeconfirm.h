#ifndef PAGEUPGRADECONFIRM_H
#define PAGEUPGRADECONFIRM_H

#include "page.h"

class PageUpgradeConfirm : public Page
{
    Q_OBJECT
public:
    PageUpgradeConfirm(QWidget *parent);
    void mousePressEvent(QMouseEvent *ev) override;

    QString strDirPath = "/ImageUpgradeConfirm";

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

#endif // PAGEUPGRADECONFIRM_H
