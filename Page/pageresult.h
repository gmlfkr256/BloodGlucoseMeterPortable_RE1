#ifndef PAGERESULT_H
#define PAGERESULT_H

#include "page.h"
#include "Component/componentmeasureresult.h"

class PageResult : public Page
{
    Q_OBJECT
public:
    PageResult(QWidget *parent);
    void mousePressEvent(QMouseEvent *ev) override;
    QString strDirPath = "/ImageResult";

    QLabel *labelBgGlucoseValue;
    QLabel *labelTextGlucoseValue;
    QLabel *labelTextMgdl;
    QLabel *labelText;
    QLabel *labelTextTime;

    QLabel *labelProgressBarBg;
    QLabel *labelProgressBar;
    QLabel *labelProgressBarTooltip;
    QLabel *labelProgressBarTooltipImg;
    QLabel *labelProgressBarTextStart;
    QLabel *labelProgressBarTextEnd;

#if PICTURE_MODE
    int fglucoseValue = 76;
    QMap<int,int> fMap = {{0,76},{1,75},{2,75},
                          {3,201},{4,199},{5,198},
                          {6,300},{7,301},{8,297},
                          {9,71},{10,70},{11,72},
                          {12,80},{13,79},{14,79},
                          {15,296},{16,302},{17,301},
                          {18,251},{19,254},{20,250},
                         };
    int fCount = 0;
#endif

    CustomButtonSave *customButtonSave;
    CustomButtonCancel *customButtonCancel;

    //QString strTextValue;
    QString strTextColor;

    void update() override;
    void pageShow() override;
    void pageHide() override;
private:
    void init();
    void setValueUI();

signals:
    //void signalShowPageNum(PageNum pageNum);
};

#endif // PAGERESULT_H
