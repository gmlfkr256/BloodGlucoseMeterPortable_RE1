#ifndef PAGECALISELECTINFO_H
#define PAGECALISELECTINFO_H

#include "page.h"

class PageCaliSelectInfo : public Page
{
    Q_OBJECT
public:
    PageCaliSelectInfo(QWidget *parent);
    void mousePressEvent(QMouseEvent *ev) override;
    QString strDirPath = "/ImageCaliSelectInfo";

    QLabel *labelSelectInfoText;

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

#endif // PAGECALISELECTINFO_H
