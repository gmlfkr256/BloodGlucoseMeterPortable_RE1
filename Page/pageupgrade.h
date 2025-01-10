#ifndef PAGEUPGRADE_H
#define PAGEUPGRADE_H

#include "page.h"

class PageUpgrade : public Page
{
    Q_OBJECT
public:
    PageUpgrade(QWidget *parent);
    void mousePressEvent(QMouseEvent *ev) override;

    QString strDirPath = "/ImageUpgrade";

    QLabel *labelText;
    QLabel *labelTextVersion;

    CustomButtonUpgrade *customButtonUpgrade;

    void update() override;
    void pageShow() override;
    void pageHide() override;
private:
    void init();

signals:
    //void signalShowPageNum(PageNum pageNum);
};

#endif // PAGEUPGRADE_H
