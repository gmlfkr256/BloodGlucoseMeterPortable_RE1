#ifndef CUSTOMBUTTON_H
#define CUSTOMBUTTON_H

#include "singleton.h"
#include "textresource.h"

class CustomButton : public QWidget
{
    Q_OBJECT
public:
    CustomButton(QWidget *parent);
    Singleton &instance = Singleton::getInstance();
    TextResource &textResource = TextResource::getInstance();

    virtual void update() = 0;

    virtual ~CustomButton() = default;
private:
};

#endif // CUSTOMBUTTON_H
