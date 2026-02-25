#ifndef PAGEFAQINDEX_H
#define PAGEFAQINDEX_H

#include "page.h"
#include <QPoint>

class PageFaqIndex : public Page
{
    Q_OBJECT

public:
    PageFaqIndex(QWidget *parent);
    void mousePressEvent(QMouseEvent *ev) override;
    void mouseReleaseEvent(QMouseEvent *ev) override;
    void mouseMoveEvent(QMouseEvent *ev) override;

    QString strDirPath = "/ImageFaqIndex";

    QLabel *labelText[4];
    QLabel *labelArrowLeft;
    QLabel *labelArrowRight;
    CustomButtonBack *customButtonBack;

    void update() override;
    void pageShow() override;
    void pageHide() override;

private:
    int m_nPageIndex = 0;
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

#endif // PAGEFAQINDEX_H
