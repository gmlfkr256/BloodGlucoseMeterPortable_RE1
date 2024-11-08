#ifndef PAGESELECT_H
#define PAGESELECT_H

#include "page.h"

class PageSelect : public Page
{
    Q_OBJECT
public:
    PageSelect(QWidget *parent);
    QString strDirPath = "/ImageSelect";

    void update() override;
    void pageShow() override;
    void pageHide() override;
private:

};

#endif // PAGESELECT_H
