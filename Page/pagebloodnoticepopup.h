#ifndef PAGEBLOODNOTICEPOPUP_H
#define PAGEBLOODNOTICEPOPUP_H

#include "page.h"

class PageBloodNoticePopup : public Page
{
    Q_OBJECT
public:
    PageBloodNoticePopup(QWidget *parent);
    void mousePressEvent(QMouseEvent *ev) override;
    QString strDirPath = "/ImageBloodNoticePopup";

    //QLabel *labelImg;
    QLabel *labelText;

    CustomButtonOK *customButtonOK;

    void update() override;
    void pageShow() override;
    void pageHide() override;
private:
    void init();
};

#endif // PAGEBLOODNOTICEPOPUP_H
