#ifndef COMPONENTMEASURERESULT_H
#define COMPONENTMEASURERESULT_H

#include "customcomponent.h"

class ComponentMeasureResult : public CustomComponent
{
    Q_OBJECT
public:
    explicit ComponentMeasureResult(QWidget *parent, QRect rect);
    ComponentMeasureResult(QWidget *parent);

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
