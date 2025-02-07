#ifndef PAGEHISTORY_H
#define PAGEHISTORY_H

#include "page.h"
#include "Component/componentspinnerdate.h"

class PageHistory : public Page
{
    Q_OBJECT
public:
    PageHistory(QWidget *parent);
    void mousePressEvent(QMouseEvent *ev) override;
    void mouseReleaseEvent(QMouseEvent *ev) override;
    QString strDirPath = "/ImageHistory";

    QLabel *labelBg;
    QLabel *labelLine[2];

    QList<ComponentSpinnerDate*> listCom;

    ComponentSpinnerDate *comDateYear;
    ComponentSpinnerDate *comDateMonth;
    ComponentSpinnerDate *comDateDay;

    QLabel *labelGradientTop;
    QLabel *labelGradientBottom;

    QLabel *labelArrowTop;
    QLabel *labelArrowBottom;
    bool bIsArrowTouch = false;

    QLabel *labelDataCheck;

    QLabel *labelButtonToday;
    QLabel *labelButtonDayPlus;
    QLabel *labelButtonDayMinus;

    CustomButtonOK *customButtonOK;
    CustomButtonCancel *customButtonCancel;

    void setDateStatus(DateStatus dateStatus);
    void changeValue();
    void getHistoryAll();
    int getSelectedDateIndex();

    void update() override;
    void pageShow() override;
    void pageHide() override;
private:
    QDate dateSelected;
    void init();

signals:
    //void signalShowPageNum(PageNum pageNum);
};

#endif // PAGEHISTORY_H
