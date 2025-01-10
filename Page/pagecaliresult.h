#ifndef PAGECALIRESULT_H
#define PAGECALIRESULT_H

#include "page.h"
#include "Component/componentmeasureresult.h"

class PageCaliResult : public Page
{
    Q_OBJECT
public:
    PageCaliResult(QWidget *parent);
    void mousePressEvent(QMouseEvent *ev) override;

    QLabel *labelTextAdc;
    QLabel *labelTextAdcColon;
    QLabel *labelTextAdcValue;
    QLabel *labelTextTemp;
    QLabel *labelTextTempColon;
    QLabel *labelTextTempValue;
    QLabel *labelTextHeart;
    QLabel *labelTextHeartColon;
    QLabel *labelTextHeartValue;
    QLabel *labelTextResult;

    CustomButtonOK *customButtonOK;

    void update() override;
    void pageShow() override;
    void pageHide() override;
private:
    void init();

signals:
    //void signalShowPageNum(PageNum pageNum);
};

#endif // PAGECALIRESULT_H
