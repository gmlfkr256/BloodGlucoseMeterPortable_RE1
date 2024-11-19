#ifndef CUSTOMBUTTONMEASURE_H
#define CUSTOMBUTTONMEASURE_H

#include "custombutton.h"

class CustomButtonMeasure : public CustomButton
{
    Q_OBJECT
public:
    CustomButtonMeasure(QWidget *parent);
    QLabel *labelButtonMeasure;

    void update() override;
private:
    void init();
};

#endif // CUSTOMBUTTONMEASURE_H
