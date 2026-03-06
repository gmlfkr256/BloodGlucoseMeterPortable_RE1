#ifndef PAGEFAQRESPONSE_H
#define PAGEFAQRESPONSE_H

#include "page.h"
#include <QPoint>

class PageFaqResponse : public Page
{
    Q_OBJECT

public:
    PageFaqResponse(QWidget *parent);
    void mousePressEvent(QMouseEvent *ev) override;
    void mouseReleaseEvent(QMouseEvent *ev) override;
    void mouseMoveEvent(QMouseEvent *ev) override;

    QString strDirPath = "/ImageResponse";

    QLabel *labelText;
    QLabel *labelNumCurrent;
    QLabel *labelNumBar;
    QLabel *labelNumAll;
    QLabel *labelArrowTop;
    QLabel *labelArrowDown;

    CustomButtonBack *customButtonBack;

    void update() override;
    void pageShow() override;
    void pageHide() override;

private:
    int m_nCurrentIndex = 0;
    int m_nPageIndexMax = 0;

    QStringList m_strList;

    QPoint m_pressPos;
    bool m_bIsTouch = false;
    bool m_bIsDrag = false;

    void init();
    void pagePrev();
    void pageNext();

signals:
};

#endif // PAGEFAQRESPONSE_H
