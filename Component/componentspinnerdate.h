#ifndef COMPONENTSPINNERDATE_H
#define COMPONENTSPINNERDATE_H

#include "customcomponent.h"

typedef enum
{
    DATE_YEAR,
    DATE_MONTH,
    DATE_DAY,
    DATE_HOUR,
    DATE_MIN
} DateStatus;

Q_ENUMS(DataStatus)

class ComponentSpinnerDate : public CustomComponent
{
    Q_OBJECT
public:
    ComponentSpinnerDate(QWidget *parent, DateStatus dateStatus);
    void mousePressEvent(QMouseEvent *ev) override;
    void mouseReleaseEvent(QMouseEvent *ev) override;

    QString strDirPath = "/ImageSpinnerDate";

    QLabel *labelBg;
    QLabel *labelBgLineTop;
    QLabel *labelBgLintBottom;

    QLabel *labelLine[2];
    QLabel *labelColon;

    QVBoxLayout *vBoxLayout;
    QLabel *labelTextTop;
    QLabel *labelTextValue;
    QLabel *labelTextBottom;

    DateStatus dateStatus;

    int nValue = 0;

    bool isSelect = false;

    const int nYearMin = 1970;
    const int nYearMax = 2070;
    const int nMonthMin = 1;
    const int nMonthMax = 12;
    const int nDayMin = 1;
    int nDayMax = 31;
    const int nHourMin = 1;
    const int nHourMax = 24;
    const int nMinMin = 0;
    const int nMinMax = 59;
    int nMin = 0, nMax = 0;

    void setValue(int nValue);
    void checkValueRange();
    int getDateValue();
    void valuePlus();
    void valueMinus();
    void timeStop();

    void setValidRange(int min, int max);
    bool isValueValid(int value);

    void update() override;
    void pageShow() override;
    void pageHide() override;
private:
    QTimer *timerPress;
    bool isPlus = false;

    void init();
    void handleTimerPress();
signals:
    void signalSetDateStatus(DateStatus dateStatus);
    void signalChangeValue();
};

#endif // COMPONENTSPINNERDATE_H
