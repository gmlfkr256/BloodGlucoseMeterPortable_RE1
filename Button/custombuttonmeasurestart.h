#ifndef CUSTOMBUTTONMEASURESTART_H
#define CUSTOMBUTTONMEASURESTART_H

#include "custombutton.h"

class CustomButtonMeasureStart : public CustomButton
{
    Q_OBJECT
public:
    CustomButtonMeasureStart(QWidget *parent);
    QLabel *labelButtonMeasureStart;

    void update() override;
private:
    void init();
};

#endif // CUSTOMBUTTONMEASURESTART_H
