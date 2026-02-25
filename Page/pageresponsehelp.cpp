#include "pageresponsehelp.h"

PageResponseHelp::PageResponseHelp(QWidget *parent) : Page(parent)
{
    this->setGeometry(parent->geometry());
    init();
}

void PageResponseHelp::
