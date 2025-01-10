#ifndef PAGEREVERSE_H
#define PAGEREVERSE_H

#include "page.h"

class PageReverse : public Page
{
    Q_OBJECT
public:
    PageReverse(QWidget *parent);
    void mousePressEvent(QMouseEvent *ev) override;
    void mouseReleaseEvent(QMouseEvent *ev) override;
    QString strDirPath = "/ImageReverse";

    bool bIsReverse = false;
    bool bIsButtonTouch = false;

    QLabel *labelButtonLeft;
    QLabel *labelTextLeft;
    QLabel *labelButtonRight;
    QLabel *labelTextRight;
    QLabel *labelText;

    CustomButtonOK *customButtonOK;
    CustomButtonCancel *customButtonCancel;

    void update() override;
    void pageShow() override;
    void pageHide() override;
private:
    void init();
    void setImgHand();
    void setImgHandPress();

signals:
    //void signalShowPageNum(PageNum pageNum);
};

#endif // PAGEREVERSE_H
