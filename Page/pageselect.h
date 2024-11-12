#ifndef PAGESELECT_H
#define PAGESELECT_H

#include "page.h"

class PageSelect : public Page
{
    Q_OBJECT
public:
    PageSelect(QWidget *parent);
    void mousePressEvent(QMouseEvent *ev) override;
    QString strDirPath = "/ImageSelect";

    CustomButtonHome *customButtonHome;
    CustomButtonMeasureStart *customButtonMeasureStart;
    QLabel *labelArrowLeft;
    QLabel *labelArrowLeftTouch;
    QLabel *labelArrowRight;
    QLabel *labelArrowRightTouch;

    //empty
    QLabel *labelBgCircle;
    QLabel *labelImageTime;
    QLabel *labelTextStatus;
    QLabel *labelTextStatusSub;

    //value
    QLabel *labelTextGlucoseValue;
    QLabel *labelTextMgdl;
    QLabel *labelTextResult;
    QLabel *labelTextTime;

    void update() override;
    void pageShow() override;
    void pageHide() override;
private:
    void init();
    void updateStatus();

signals:
    void signalShowPageHome();
};

#endif // PAGESELECT_H
