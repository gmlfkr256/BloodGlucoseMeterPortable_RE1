#ifndef COMPONENTMEASURERESULT_H
#define COMPONENTMEASURERESULT_H

#include "customcomponent.h"

class ComponentMeasureResult : CustomComponent
{
    Q_OBJECT
public:
    ComponentMeasureResult(QWidget *parent, QRect rect);

    QLabel *labelTextResult;

    void setTextResult(unsigned char errCode);
    void setCustomGeomtry(QRect rect);

    void update() override;
    void pageShow() override;
    void pageHide() override;
private:
    void init();
};

#endif // COMPONENTMEASURERESULT_H
