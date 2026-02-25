#ifndef PAGEELAPSEDNOTICEPOPUP_H
#define PAGEELAPSEDNOTICEPOPUP_H

#include "page.h"

class PageElapsedNoticePopup : public Page
{
    Q_OBJECT
public:
    PageElapsedNoticePopup(QWidget *parent);
    void mousePressEvent(QMouseEvent *ev) override;
    QString strDirPath = "/ImageElapsedNoticePopup";

    QLabel *labelTitle;
    QLabel *labelText;
    CustomButtonOK* customButtonOK;

    void update() override;
    void pageShow() override;
    void pageHide() override;
private:
    void init();
};

#endif // PAGEELAPSEDNOTICEPOPUP_H
