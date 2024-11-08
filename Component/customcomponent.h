#ifndef CUSTOMCOMPONENT_H
#define CUSTOMCOMPONENT_H

#include "singleton.h"

class CustomComponent : public QWidget
{
    Q_OBJECT
public:
    CustomComponent(QWidget *parent);

    //virtual void init() = 0;
    virtual void update() = 0;
    virtual void pageShow() = 0;
    virtual void pageHide() = 0;

    virtual ~CustomComponent() = default;
};

#endif // CUSTOMCOMPONENT_H
