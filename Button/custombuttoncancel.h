#ifndef CUSTOMBUTTONCANCEL_H
#define CUSTOMBUTTONCANCEL_H

#include "custombutton.h"

class CustomButtonCancel : public CustomButton
{
    Q_OBJECT
public:
    CustomButtonCancel(QLabel *parent);
};

#endif // CUSTOMBUTTONCANCEL_H
