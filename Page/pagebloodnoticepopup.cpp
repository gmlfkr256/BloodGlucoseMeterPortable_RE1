#include "pagebloodnoticepopup.h"

PageBloodNoticePopup::PageBloodNoticePopup(QWidget *parent) : Page(parent)
{
    this->setGeometry(parent->geometry());
    init();
}

void PageBloodNoticePopup::init()
{
    labelText = new QLabel(this);
    labelText->setGeometry(0,73,640,317);
    labelText->setAlignment(Qt::AlignCenter);

    customButtonOK = new CustomButtonOK(this);
    customButtonOK->setLongWidth(true);

    update();
}

void PageBloodNoticePopup::update()
{
    customButtonOK->update();

    labelText->setFont(textResource.getFont(PAGE_BLOOD_NOTICE_POPUP,"labelText"));
    labelText->setText(textResource.getText(PAGE_BLOOD_NOTICE_POPUP,"labelText").at(0));
}

void PageBloodNoticePopup::pageShow()
{
    update();
}

void PageBloodNoticePopup::pageHide()
{
#if PICTURE_MODE
    emit signalShowPageNum(PAGE_RESULT);
    return;
#endif

    emit signalShowPageNum(PAGE_HOME);

}

void PageBloodNoticePopup::mousePressEvent(QMouseEvent *ev)
{
    if(instance.touchCheck(customButtonOK->geometry(),ev))
    {
        pageHide();
    }
}
