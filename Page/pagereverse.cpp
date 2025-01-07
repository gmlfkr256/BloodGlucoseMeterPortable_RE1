#include "pagereverse.h"

PageReverse::PageReverse(QWidget *parent) : Page(parent)
{
    this->setGeometry(parent->geometry());
    init();
}

void PageReverse::init()
{
    labelButtonLeft = new QLabel(this);
    labelButtonLeft->setGeometry(75,98,245,215);
    labelTextLeft = new QLabel(this);
    labelTextLeft->setGeometry(labelButtonLeft->x(),labelButtonLeft->y()+150,245,45);
    labelTextLeft->setAlignment(Qt::AlignCenter);

    labelButtonRight = new QLabel(this);
    labelButtonRight->setGeometry(320,98,245,215);
    labelTextRight = new QLabel(this);
    labelTextRight->setGeometry(labelButtonRight->x(),labelButtonRight->y()+150,245,45);
    labelTextRight->setAlignment(Qt::AlignCenter);

    labelText = new QLabel(this);
    labelText->setGeometry(0,325,640,45);
    labelText->setAlignment(Qt::AlignCenter);

    customButtonOK = new CustomButtonOK(this);
    customButtonCancel = new CustomButtonCancel(this);
}

void PageReverse::update()
{
    customButtonOK->update();
    customButtonCancel->update();

    labelTextLeft->setFont(textResource.getFont(PAGE_REVERSE,"labelTextButton"));
    labelTextLeft->setText(textResource.getText(PAGE_REVERSE,"labelTextButton").at(0));

    labelTextRight->setFont(textResource.getFont(PAGE_REVERSE,"labelTextButton"));
    labelTextRight->setText(textResource.getText(PAGE_REVERSE,"labelTextButton").at(1));

    labelText->setFont(textResource.getFont(PAGE_REVERSE,"labelText"));
    labelText->setText(textResource.getText(PAGE_REVERSE,"labelText").at(0));

#if DEVICE
    instance.guiApi.glucoseGetDispData(&instance.dispData);

    if(instance.dispData.dir == GAPI_DISP_DIR_NORMAL)
        bIsReverse = false;
    else
        bIsReverse = true;
#endif

    setImgHand();
}

void PageReverse::setImgHand()
{
    QString strImgPathLeft = "/handLeft.png";
    QString strImgPathRight = "/handRight.png";

    if(!bIsReverse)
    {
        strImgPathLeft = "/handLeftOn.png";
    }
    else
    {
        strImgPathRight = "/handRightOn.png";
    }

    instance.pixLoad(labelButtonLeft,false,strDirPath,strImgPathLeft);
    instance.pixLoad(labelButtonRight,false,strDirPath,strImgPathRight);
}

void PageReverse::setImgHandPress()
{
    QString strImgPathLeft = "/handLeft.png";
    QString strImgPathRight = "/handRight.png";

    if(!bIsReverse)
    {
        strImgPathLeft = "/handLeftPress.png";
    }
    else
    {
        strImgPathRight = "/handRightPress.png";
    }

    instance.pixLoad(labelButtonLeft,false,strDirPath,strImgPathLeft);
    instance.pixLoad(labelButtonRight,false,strDirPath,strImgPathRight);
}

void PageReverse::pageShow()
{
    update();
}

void PageReverse::pageHide()
{
    emit signalShowPageNum(PAGE_MENU);
}

void PageReverse::mousePressEvent(QMouseEvent *ev)
{
    if(instance.touchCheck(labelButtonLeft->geometry(),ev))
    {
        bIsReverse = false;
        bIsButtonTouch = true;
        setImgHandPress();
    }

    if(instance.touchCheck(labelButtonRight->geometry(),ev))
    {
        bIsReverse = true;
        bIsButtonTouch = true;
        setImgHandPress();
    }

    if(instance.touchCheck(customButtonOK->geometry(),ev))
    {
        if(bIsReverse)
            instance.dispData.dir = GAPI_DISP_DIR_REVERSE;
        else
            instance.dispData.dir = GAPI_DISP_DIR_NORMAL;
#if DEVICE
        instance.guiApi.glucoseSetDispData(&instance.dispData);
#endif
        pageHide();
    }

    if(instance.touchCheck(customButtonCancel->geometry(),ev))
    {
        pageHide();
    }
}

void PageReverse::mouseReleaseEvent(QMouseEvent *ev)
{
    Q_UNUSED(ev)

    if(bIsButtonTouch)
    {
        setImgHand();
        bIsButtonTouch = false;
    }
}
