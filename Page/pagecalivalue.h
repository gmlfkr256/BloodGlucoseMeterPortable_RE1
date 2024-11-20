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

    ComponentSpinner *componentSpinner;

    CustomButtonOK *customButtonOK;
    CustomButtonCancel *customButtonCancel;

    void update() override;
    void pageShow() override;
    void pageHide() override;
private:
    void init();

signals:
    void signalShowPageNum(PageNum pageNum);
};

#endif // PAGECALIVALUE_H
