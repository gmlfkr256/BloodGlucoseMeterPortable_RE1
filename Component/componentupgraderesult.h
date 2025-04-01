#ifndef COMPONENTUPGRADERESULT_H
#define COMPONENTUPGRADERESULT_H

#include "customcomponent.h"

class ComponentUpgradeResult : public CustomComponent
{
    Q_OBJECT
public:
    ComponentUpgradeResult(QWidget *parent);
    explicit ComponentUpgradeResult();

    void setTextResult(QLabel *label, unsigned char errCode);
    void setResultSpk(unsigned char errCode);

    void update() override;
    void pageShow() override;
    void pageHide() override;
private:
    void init();
};

#endif // COMPONENTUPGRADERESULT_H
