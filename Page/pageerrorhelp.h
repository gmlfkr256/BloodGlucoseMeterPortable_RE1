#ifndef PageErrorHelp_H
#define PageErrorHelp_H

#include "page.h"
#include "Component/componentwidgettextmove.h"

class PageErrorHelp : public Page
{
    Q_OBJECT

public:
    PageErrorHelp(QWidget *parent);
    void mousePressEvent(QMouseEvent *ev) override;

    QString strDirPath = "/ImageErrorHelp";

    QLabel *labelWindow;
    QLabel *labelTextBgTop;
    QLabel *labelTextBgCenter;
    QLabel *labelTextBgDown;

    QLabel *labelTextTop;
    ComponentWidgetTextMove *comText;
    QLabel *labelTextDown;

    QLabel *labelButtonGradientTop;
    QLabel *labelButtonGradientDown;

    QLabel *labelArrowTop;
    QLabel *labelArrowDown;

    QLabel *labelNumCurrent;
    QLabel *labelNumBar;
    QLabel *labelNumAll;

    int nSelectIndex = 0;
    int nIndexRangeMax;

    CustomButtonBack *customButtonBack;

    void update() override;
    void pageShow() override;
    void pageHide() override;

private:
    int m_nSelectIndex = 0;
    int m_nIndexRangeMax;

    QStringList m_strList;

    void init();
    void updateTextSlots();
    void moveNext();
    void movePrev();

signals:
};

#endif // PageErrorHelp_H
