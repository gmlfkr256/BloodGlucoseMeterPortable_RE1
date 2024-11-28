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

    CustomButtonSave *customButtonSave;
    CustomButtonCancel *customButtonCancel;

    QString strTextValue;
    QString strTextColor;

    void update() override;
    void pageShow() override;
    void pageHide() override;
private:
    void init();
    void setColorValue(int nGlucoseValue = 0);

signals:
    void signalShowPageNum(PageNum pageNum);
};

#endif // PAGERESULT_H
