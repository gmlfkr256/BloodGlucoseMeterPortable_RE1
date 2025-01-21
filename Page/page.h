#ifndef PAGE_H
#define PAGE_H

#include "singleton.h"
#include "textresource.h"
#include "Button/custombuttonok.h"
#include "Button/custombuttoncancel.h"
#include "Button/custombuttonhome.h"
#include "Button/custombuttonmeasurestart.h"
#include "Button/custombuttonmeasure.h"
#include "Button/custombuttoninput.h"
#include "Button/custombuttonmeasurere.h"
#include "Button/custombuttonsave.h"
#include "Button/custombuttonupgrade.h"

class Page : public QWidget
{
    Q_OBJECT
public:
    Singleton &instance = Singleton::getInstance();
    TextResource &textResource = TextResource::getInstance();
    Page(QWidget *parent);

    virtual void update() = 0;
    virtual void pageShow() = 0;
    virtual void pageHide() = 0;

    void setBgTopHide();
    void setBgHide();

signals:
    void signalShowPageNum(PageNum pageNum);
private:
    QLabel *labelBg;
    QLabel *labelBgTop;

    void init();
    void initBG();
};

#endif // PAGE_H
