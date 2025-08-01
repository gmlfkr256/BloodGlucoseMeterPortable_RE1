#ifndef PAGECALIVALUE_H
#define PAGECALIVALUE_H

#include "page.h"
#include "Component/componentspinner.h"

class PageCaliValue : public Page
{
    Q_OBJECT
public:
    PageCaliValue(QWidget *parent);
    void mousePressEvent(QMouseEvent *ev) override;
    QString strDirPath = "/ImageCaliValue";

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
    //void signalShowPageNum(PageNum pageNum);
};

#endif // PAGECALIVALUE_H
