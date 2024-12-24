#ifndef COMPONENTSPINNERDATE_H
#define COMPONENTSPINNERDATE_H

#include "customcomponent.h"

typedef enum
{
    YEAR,
    MONTH,
    DAY,
    HOUR,
    MIN
} DateStatus;

Q_ENUMS(DataStatus)

class ComponentSpinnerDate : public CustomComponent
{
    Q_OBJECT
public:
    ComponentSpinnerDate(QWidget *parent, DateStatus dateStatus);
    void mousePressEvent(QMouseEvent *ev) override;

    QString strDirPath = "/ImageSpinnerDate";

    QVBoxLayout *vBoxLayout;
    QLabel *labelTextTop;
    QLabel *labelTextValue;
    QLabel *labelTextBottom;

    bool isSelect = false;

    const int nYearMin = 1970;
    const int nYearMax = 2070;
    const int nMonthMin = 1;
    const int nMonthMax = 12;
    const int nDayMin = 1;
    const int nDayMax = 31;
    const int nHourMin = 0;
    const int nHourMax = 23;
    const int nMinMin = 0;
    const int nMinMax = 59;

    void update() override;
    void pageShow() override;
    void pageHide() override;
private:
    void init();
};

#endif // COMPONENTSPINNERDATE_H
