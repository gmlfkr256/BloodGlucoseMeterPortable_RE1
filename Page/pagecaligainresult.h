#ifndef PAGECALIGAINRESULT_H
#define PAGECALIGAINRESULT_H

#include "page.h"

class PageCaliGainResult : public Page
{
    Q_OBJECT
public:
    PageCaliGainResult(QWidget *parent);
    void mousePressEvent(QMouseEvent *ev) override;

    QString strDirPath = "/ImageCaliGainResult";

    QLabel *labelText;
    CustomButtonOK *customButtonOK;

    void update() override;
    void pageShow() override;
    void pageHide() override;
private:
    void init();

signals:
    //void signalShowPageNum(PageNum pageNum);
};

#endif // PAGECALIGAINRESULT_H
