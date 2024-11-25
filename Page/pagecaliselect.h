#ifndef PAGECALISELECT_H
#define PAGECALISELECT_H

#include "page.h"

class PageCaliSelect : public Page
{
    Q_OBJECT
public:
    PageCaliSelect(QWidget *parent);
    void mousePressEvent(QMouseEvent *ev) override;
    QString strDirPath = "/ImageCaliSelect";

    QLabel *labelSelectButton[5];
    QLabel *labelSelectText[5];
    QLabel *labelSelectNum[5];

    QLabel *labelSelectTextAdc[5];
    QLabel *labelSelectTextValue[5];

    void update() override;
    void pageShow() override;
    void pageHide() override;
private:
    void init();

signals:
    void signalShowPageNum(PageNum pageNum);
};

#endif // PAGECALISELECT_H
