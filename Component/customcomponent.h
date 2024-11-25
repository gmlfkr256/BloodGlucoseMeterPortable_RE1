#ifndef CUSTOMCOMPONENT_H
#define CUSTOMCOMPONENT_H

#include "singleton.h"
#include "textresource.h"

class CustomComponent : public QWidget
{
    Q_OBJECT
public:
    explicit CustomComponent(QWidget *parent);
    Singleton &instance = Singleton::getInstance();
    TextResource &textResource = TextResource::getInstance();

    //virtual void init() = 0;
    virtual void update() = 0;
    virtual void pageShow() = 0;
    virtual void pageHide() = 0;

    virtual ~CustomComponent() = default;
};

#endif // CUSTOMCOMPONENT_H
