#ifndef PAGETHRESHOLDVALUE_H
#define PAGETHRESHOLDVALUE_H

#include "page.h"
#include "Component/componentspinner.h"

class PageThresholdValue : public Page
{
    Q_OBJECT
public:
    PageThresholdValue(QWidget *parent);
    void mousePressEvent(QMouseEvent *ev) override;

    QString strDirPath = "/ImageThresholdValue";

    ComponentSpinner *componentSpinner[3];

    CustomButtonOK *customButtonOK;
    CustomButtonCancel *customButtonCancel;

    int nValue = 0;

    void update() override;
    void pageShow() override;
    void pageHide() override;
private:
    void init();
    void initSpinner();

signals:
    void signalShowPageNum(PageNum pageNum);
};

#endif // PAGETHRESHOLDVALUE_H
