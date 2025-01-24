#ifndef PAGEGARPH_H
#define PAGEGARPH_H

#include "page.h"

class PageGarph : public Page
{
    Q_OBJECT
public:
    PageGarph(QWidget *parent);
    void mousePressEvent(QMouseEvent *ev) override;
    virtual void paintEvent(QPaintEvent *ev) override;
    QString strDirPath = "/ImageGraph";

    QLabel *labelProgressText;
    QLabel *labelProgressValue;
    QLabel *labelProgressPercent;

    QLabel *labelProgressBarBg;
    QLabel *labelProgressBar;

    QLabel *labelAdcText;
    QLabel *labelAdcRect;

    QTimer *timerPainter;
    QLabel *labelPainter;
    QPixmap pixPainter;
    QPainter *painter;
    QPen pen,pen1,pen2,pen3;
    int nGraphPointY[50];
    int nProgressValue = 0;

    QLabel *labelLoading;
    QString strLoading;
    QLabel *labelCircle[3];
    int nCurrentIndex = 0;
    int nCount = 0;

    CustomButtonCancel *customButtonCancel;

    bool bIsProcessSuccess = false;

    void initGraphPainter();

    void update() override;
    void pageShow() override;
    void pageHide() override;
private:
    void init();
    void updatePainter();

signals:
    //void signalShowPageNum(PageNum pageNum);
};

#endif // PAGEGARPH_H
