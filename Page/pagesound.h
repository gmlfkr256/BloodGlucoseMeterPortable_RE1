#ifndef PAGESOUND_H
#define PAGESOUND_H

#include "page.h"

class PageSound : public Page
{
    Q_OBJECT
public:
    PageSound(QWidget *parent);
    void mousePressEvent(QMouseEvent *ev) override;
    void mouseReleaseEvent(QMouseEvent *ev) override;
    void mouseMoveEvent(QMouseEvent *ev) override;
    QString strDirPath = "/ImageSound";

    QLabel *labelVolume;
    QLabel *labelArrowLeft;
    QLabel *labelArrowRight;
    QLabel *labelBarBg;
    QLabel *labelBar;
    QLabel *labelBarTouch;
    QLabel *labelCircle;
    QLabel *labelImgMin;
    QLabel *labelImgMax;

    int nVolume;
    gapiSpkData_t prevSpkData;
    bool isBarTouch = false;

    CustomButtonSave *customButtonSave;
    CustomButtonCancel *customButtonCancel;

    void update() override;
    void pageShow() override;
    void pageHide() override;
private:
    void init();
    void setVolume();
    void setVolumeOut();
    void setScreen();
    void setVolumeMin();
    void setVolumeMax();

signals:
    void signalShowPageNum(PageNum pageNum);
};

#endif // PAGESOUND_H
