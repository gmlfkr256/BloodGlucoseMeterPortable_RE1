#ifndef PAGEUSERINFO_H
#define PAGEUSERINFO_H

#include "page.h"

class PageUserInfo : public Page
{
    Q_OBJECT
public:
    PageUserInfo(QWidget *parent);
    void mousePressEvent(QMouseEvent *ev) override;

    QString strDirPath = "/ImageUserInfo";

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
    void signalShowPageNum(PageNum pageNum);
};

#endif // PAGEUSERINFO_H
