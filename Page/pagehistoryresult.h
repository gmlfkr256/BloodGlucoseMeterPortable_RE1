#ifndef PAGEHISTORYRESULT_H
#define PAGEHISTORYRESULT_H

#include "page.h"

class PageHistoryResult : public Page
{
    Q_OBJECT
public:
    PageHistoryResult(QWidget *parent);
    void mousePressEvent(QMouseEvent *ev) override;
    QString strDirPath = "/ImageHome"; //"/ImageHistoryResult";

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

    QStringList strListBg;

    void update() override;
    void pageShow() override;
    void pageHide() override;
private:
    void init();
};

#endif // PAGEHISTORYRESULT_H
