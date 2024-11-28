#ifndef PAGEHOME_H
#define PAGEHOME_H

#include "page.h"

class PageHome : public Page
{
    Q_OBJECT
public:
    PageHome(QWidget *parent);
    void mousePressEvent(QMouseEvent *ev) override;

    QList<QRect> listRectButton;
    QList<QRect> listRectTitle;
    QList<QRect> listRectImage;
    QList<QRect> listRectText;

    class labelGroup
    {
    public:
        QLabel *labelButton;
        QLabel *labelTextStatus;
        QLabel *labelButtonImage;
        QLabel *labelButtonText;
    };

    labelGroup labelGroups[8];

    int order[8] = {0,1,3,5,7,2,4,6};

    QString strDirPath = "/ImageHome";
    QStringList strListBg;


    void update() override;
    void pageShow() override;
    void pageHide() override;
private:
    void init();

signals:
    void signalShowPageSelect();
};

#endif // PAGEHOME_H
