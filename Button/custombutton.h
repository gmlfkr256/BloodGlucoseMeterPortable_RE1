#ifndef CUSTOMBUTTON_H
#define CUSTOMBUTTON_H

#include "singleton.h"

class CustomButton : public QLabel
{
    Q_OBJECT
public:
    CustomButton(QLabel *parent);
};

#endif // CUSTOMBUTTON_H
