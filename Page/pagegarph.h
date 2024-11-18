#ifndef PAGEGARPH_H
#define PAGEGARPH_H

#include "page.h"

class PageGarph : public Page
{
    Q_OBJECT
public:
    PageGarph(QWidget *parent);
    void mousePressEvent(QMouseEvent *ev) override;
    QString strDirPath = "/ImageGraph";

    QLabel *labelTop;
    QHBoxLayout *hBoxLayoutGraph;

    QLabel *labelProgressText;
    QLabel *labelProgressValue;
    QLabel *labelProgressPercent;

    QLabel *labelProgressBarBg;
    QLabel *labelProgressBar;

    QLabel *labelAdcText;
    QLabel *labelAdcRect;

    QLabel *labelPainter;

    CustomButtonCancel *customButtonCancel;

    void update() override;
    void pageShow() override;
    void pageHide() override;
private:
    void init();

signals:
    void signalShowPageNum(PageNum pageNum);
};

#endif // PAGEGARPH_H
