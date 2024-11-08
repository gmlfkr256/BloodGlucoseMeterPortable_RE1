#ifndef PAGE_H
#define PAGE_H

#include "singleton.h"
#include "textresource.h"

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
private:
    QLabel *labelBg;
    QLabel *labelBgTop;

    void init();
    void initBG();
};

#endif // PAGE_H
