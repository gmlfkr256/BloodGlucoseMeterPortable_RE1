#ifndef PAGECALICONFIRM_H
#define PAGECALICONFIRM_H

#include "page.h"

class PageCaliConfirm : public Page
{
    Q_OBJECT
public:
    PageCaliConfirm(QWidget *parent);
    void mousePressEvent(QMouseEvent *ev) override;
    QString strDirPath = "/ImageCaliConfirm";

    QLabel *labelText;

    CustomButtonMeasure *customButtonMeasure;
    CustomButtonInput *customButtonInput;

    void update() override;
    void pageShow() override;
    void pageHide() override;
private:
    void init();

signals:
    void signalShowPageNum(PageNum pageNum);
};

#endif // PAGECALICONFIRM_H
