#ifndef PAGEDATETIME_H
#define PAGEDATETIME_H

#include "page.h"
#include "Component/componentspinnerdate.h"

class PageDateTime : public Page
{
    Q_OBJECT
public:
    PageDateTime(QWidget *parent);
    void mousePressEvent(QMouseEvent *ev) override;
    void mouseReleaseEvent(QMouseEvent *ev) override;

    QString strDirPath = "/ImageDateTime";

    QLabel *labelBg;

    QLabel *labelLine[2];
    QLabel *labelColon;

    QList<ComponentSpinnerDate*> listCom;

    ComponentSpinnerDate *comDateYear;
    ComponentSpinnerDate *comDateMonth;
    ComponentSpinnerDate *comDateDay;
    ComponentSpinnerDate *comDateHour;
    ComponentSpinnerDate *comDateMin;

    QLabel *labelGradientTop;
    QLabel *labelGradientBottom;

    QLabel *labelArrowTop;
    QLabel *labelArrowBottom;
    bool bIsArrowTouch = false;

    CustomButtonSave *customButtonSave;
    CustomButtonCancel *customButtonCancel;

    void setDateStatus(DateStatus dateStatus);
    void changeValue();

    void update() override;
    void pageShow() override;
    void pageHide() override;
private:
    void init();

signals:
    //void signalShowPageNum(PageNum pageNum);
};

#endif // PAGEDATETIME_H
