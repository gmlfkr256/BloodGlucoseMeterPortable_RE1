#ifndef CUSTOMBUTTONMEASURERE_H
#define CUSTOMBUTTONMEASURERE_H

#include "custombutton.h"

class CustomButtonMeasureRe : public CustomButton
{
    Q_OBJECT
public:
    CustomButtonMeasureRe(QWidget *parent);
    QLabel *labelButtonMeasureRe;

    void update();
private:
    void init();
};

#endif // CUSTOMBUTTONMEASURERE_H
