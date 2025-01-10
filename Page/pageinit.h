#ifndef PAGEINIT_H
#define PAGEINIT_H

#include "page.h"

class PageInit : public Page
{
    Q_OBJECT
public:
    PageInit(QWidget *parent);
    void mousePressEvent(QMouseEvent *ev) override;

    QString strDirPath = "/ImageInit";

    QLabel *labelText[3];
    QLabel *labelArrow[3];
    QLabel *labelLine[3];

    CustomButtonOK *customButtonOK;

    void update() override;
    void pageShow() override;
    void pageHide() override;
private:
    void init();

signals:
    //void signalShowPageNum(PageNum pageNum);
};

#endif // PAGEINIT_H
