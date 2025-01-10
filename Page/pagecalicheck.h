#ifndef PAGECALICHECK_H
#define PAGECALICHECK_H

#include "page.h"

class PageCaliCheck : public Page
{
    Q_OBJECT
public:
    PageCaliCheck(QWidget *parent);
    void mousePressEvent(QMouseEvent *ev) override;
    QString strDirPath = "/ImageCaliCheck";

    QLabel* labelTextCheck;
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

#endif // PAGECALICHECK_H
