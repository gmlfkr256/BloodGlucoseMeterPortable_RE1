#ifndef PAGEHISTORY_H
#define PAGEHISTORY_H

#include "page.h"
#include "Component/componentspinner.h"

class PageHistory : public Page
{
    Q_OBJECT
public:
    PageHistory(QWidget *parent);
    void mousePressEvent(QMouseEvent *ev) override;
    QString strDirPath = "/ImageHistory";


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

#endif // PAGEHISTORY_H
