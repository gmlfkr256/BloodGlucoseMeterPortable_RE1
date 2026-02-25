#ifndef PAGEBLOODCHECK_H
#define PAGEBLOODCHECK_H

#include "page.h"

class PageBloodCheck : public Page
{
    Q_OBJECT
public:
    PageBloodCheck(QWidget *parent);
    void mousePressEvent(QMouseEvent *ev) override;
    QString strDirPath = "/ImageBloodCheck";

    QLabel *labelText;

    CustomButtonYes* customButtonYes;
    CustomButtonNo* customButtonNo;

    void update() override;
    void pageShow() override;
    void pageHide() override;
private:
    void init();
};

#endif // PAGEBLOODCHECK_H
