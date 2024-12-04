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
    void signalShowPageNum(PageNum pageNum);
};

#endif // PAGERESULT_H
