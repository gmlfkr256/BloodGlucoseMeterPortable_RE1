#ifndef PAGECALIRESULTMULTI_H
#define PAGECALIRESULTMULTI_H

#include "page.h"

class PageCaliResultMulti : public Page
{
    Q_OBJECT
public:
    PageCaliResultMulti(QWidget *parent);
    void mousePressEvent(QMouseEvent *ev) override;
    QString strDirPath = "/ImageCaliResultMulti";

    QLabel *labelButton[3];
    QLabel *labelTextAdc[3];
    QLabel *labelTextTemp[3];
    QLabel *labelTextHeart[3];

    CustomButtonOK *customButtonOk;
    CustomButtonCancel *customButtonCancel;
    CustomButtonMeasure *customButtonMeasure;
    CustomButtonMeasureRe *customButtonMeasureRe;

    void update() override;
    void pageShow() override;
    void pageHide() override;
private:
    void init();

signals:
    void signalShowPageNum(PageNum pageNum);
};

#endif // PAGECALIRESULTMULTI_H
