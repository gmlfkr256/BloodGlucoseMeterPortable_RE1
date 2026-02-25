#include "pageusercautions.h"

PageUserCautions::PageUserCautions(QWidget *parent) : Page(parent)
{
     this->setGeometry(parent->geometry());
     init();
}

void PageUserCautions::init()
{
    labelTitle = new QLabel(this);
    labelTitle->setGeometry(0,121,640,52);
    labelTitle->setAlignment(Qt::AlignCenter);

    labelText = new QLabel(this);
    labelText->setGeometry(0,173,640,217);
    labelText->setAlignment(Qt::AlignCenter);

    timer = new QTimer(this);

    customButtonOK = new CustomButtonOK(this); //todo: Changed
    customButtonOK->setLongWidth(true);

    update();
}

void PageUserCautions::update()
{
    customButtonOK->update();

    labelTitle->setFont(textResource.getFont(PAGE_USER_CAUTIONS,"labelTitle"));
    labelTitle->setText(textResource.getText(PAGE_USER_CAUTIONS,"labelTitle").at(0));

    labelText->setFont(textResource.getFont(PAGE_USER_CAUTIONS,"labelText"));
    if(nStep>nStepMax)
        nStep = nStepMax;
    labelText->setText(textResource.getText(PAGE_USER_CAUTIONS,"labelText").at(nStep));
}

void PageUserCautions::pageShow()
{
    nStep = 0;
    update();
}

void PageUserCautions::pageHide()
{
    emit signalShowPageNum(PAGE_CALI_CHECK);
}

void PageUserCautions::mousePressEvent(QMouseEvent *ev)
{
    if(instance.touchCheck(customButtonOK->geometry(),ev))
    {
        nStep++;

        if(nStep>nStepMax)
        {
            pageHide();
        }
        else
        {
            update();
        }
    }
}
