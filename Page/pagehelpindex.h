#ifndef PAGEHELPINDEX_H
#define PAGEHELPINDEX_H

#include "page.h"
#include <QPoint>

class PageHelpIndex : public Page
{
    Q_OBJECT

public:
    PageHelpIndex(QWidget *parent);
    void mousePressEvent(QMouseEvent *ev) override;
    void mouseReleaseEvent(QMouseEvent *ev) override;
    void mouseMoveEvent(QMouseEvent *ev) override;

    QString strDirPath = "/ImageHelpIndex";

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

#endif // PAGEHELPINDEX_H
