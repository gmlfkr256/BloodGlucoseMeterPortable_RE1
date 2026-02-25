#ifndef PAGEBLOODCHECKNOTICE_H
#define PAGEBLOODCHECKNOTICE_H

#include "page.h"

class PageBloodCheckNotice : public Page
{
    Q_OBJECT
public:
    PageBloodCheckNotice(QWidget *parent);
    void mousePressEvent(QMouseEvent *ev) override;
    QString strDirPath = "/ImageBloodCheckNotice";

    QLabel *labelText;

    CustomButtonOK *customButtonOK;

    void update() override;
    void pageShow() override;
    void pageHide() override;
private:
    void init();
};

#endif // PAGEBLOODCHECKNOTICE_H
