#ifndef COMPONENTMEASURERESULT_H
#define COMPONENTMEASURERESULT_H

#include "customcomponent.h"

class ComponentMeasureResult : public CustomComponent
{
    Q_OBJECT
public:
    ComponentMeasureResult(QWidget *parent);
    explicit ComponentMeasureResult();

    void setTextResult(QLabel *label,unsigned char errCode);

    void update() override;
    void pageShow() override;
    void pageHide() override;
private:
    void init();
};

#endif // COMPONENTMEASURERESULT_H
