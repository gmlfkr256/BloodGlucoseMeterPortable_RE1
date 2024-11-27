#ifndef COMPONENTSPINNER_H
#define COMPONENTSPINNER_H

#include "customcomponent.h"

class ComponentSpinner : public CustomComponent
{
    Q_OBJECT
public:
    ComponentSpinner(QWidget *parent, QRect rect);
    void mousePressEvent(QMouseEvent *ev) override;

    QString strDirPath = "/ImageSpinner";

    QLabel *labelSpinnerBg;
    QVBoxLayout *vBoxLayoutSpinner;
    QLabel *labelButtonTop;
    QLabel *labelButtonTopArrow;
    QLabel *labelTextValue;
    QLabel *labelButtonBottom;
    QLabel *labelButtonBottomArrow;

    int nValue = 0;

    void setValue(int nValue);
    int getValue();

    void update() override;
    void pageShow() override;
    void pageHide() override;
private:
    void init();
    void updateValue();
};

#endif // COMPONENTSPINNER_H
