#ifndef PAGERESULTFAIL_H
#define PAGERESULTFAIL_H

#include "page.h"
#include "Component/componentmeasureresult.h"

class PageResultFail : public Page
{
    Q_OBJECT
public:
    PageResultFail(QWidget *parent);
    void mousePressEvent(QMouseEvent *ev) override;
    QString strDirPath = "/ImageResultFail";

    QLabel *labelText;
    CustomButtonOK *customButtonOK;

    void update() override;
    void pageShow() override;
    void pageHide() override;
private:
    void init();
};

#endif // PAGERESULTFAIL_H
