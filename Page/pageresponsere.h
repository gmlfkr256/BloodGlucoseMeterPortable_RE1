#ifndef PAGERESPONSERE_H
#define PAGERESPONSERE_H

#include "page.h"
#include <QPoint>

class PageResponseRe : public Page
{
    Q_OBJECT

public:
    PageResponseRe(QWidget *parent);
    void mousePressEvent(QMouseEvent *ev) override;
    void mouseReleaseEvent(QMouseEvent *ev) override;
    void mouseMoveEvent(QMouseEvent *ev) override;

    QString strDirPath = "/ImageResponse";

    QLabel *labelText;
    QLabel *labelPageNum;
    QLabel *labelArrowLeft;
    QLabel *labelArrowRight;

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

#endif // PAGERESPONSERE_H
