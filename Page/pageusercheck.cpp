#include "pageusercheck.h"

PageUserCheck::PageUserCheck(QWidget *parent) : Page(parent)
{
    this->setGeometry(parent->geometry());
    init();
}

void PageUserCheck::init()
{
    labelTitle = new QLabel(this);
    labelTitle->setGeometry(0,121,640,52);
    labelTitle->setAlignment(Qt::AlignCenter);

    /*
    for(int i=0; i<3; i++)
    {
        labelButton[i] = new QLabel(this);
        labelText[i] = new QLabel(this);
        labelText[i]->setStyleSheet("color: #000000;");
        labelText[i]->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    }

    labelButton[0]->setGeometry(53,216,40,40);
    labelText[0]->setGeometry(109,210,220,52);


    labelButton[1]->setGeometry(336,308,40,40);
    labelText[1]->setGeometry(392,302,220,52);

    labelButton[2]->setGeometry(53,308,40,40);
    labelText[2]->setGeometry(109,302,220,52);
    */

    labelButton = new QLabel(this);
    labelText = new QLabel(this);
    labelText->setStyleSheet("color: #000000;");
    labelText->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);

    labelButton->setGeometry(196,246,40,40);
    labelText->setGeometry(252,240,388,52);

    customButtonOk = new CustomButtonOK(this);
    customButtonOk->setLongWidth(true);

    update();
}

void PageUserCheck::update()
{

    customButtonOk->update();

    labelTitle->setFont(textResource.getFont(PAGE_USER_CHECK,"labelTitle"));
    labelTitle->setText(textResource.getText(PAGE_USER_CHECK,"labelTitle").at(0));

    /*
    for(int i=0; i<3; i++)
    {
        labelText[i]->setFont(textResource.getFont(PAGE_USER_CHECK,"labelText"));
        labelText[i]->setText(textResource.getText(PAGE_USER_CHECK,"labelText").at(i));
        instance.pixLoad(labelButton[i],false,strDirPath,"/circleOFF.png");
    }
    */
    //instance.pixLoad(labelButton[nSelect],false,strDirPath,"/circleON.png");

    labelText->setFont(textResource.getFont(PAGE_USER_CHECK,"labelText"));
    labelText->setText(textResource.getText(PAGE_USER_CHECK,"labelText").at(0));

    if(customButtonOk->getEnable())
        instance.pixLoad(labelButton,false,strDirPath,"/circleON.png");
    else
        instance.pixLoad(labelButton,false,strDirPath,"/circleOFF.png");
}

void PageUserCheck::pageShow()
{
    qDebug()<<"PageUserCheck: pageShow";
    //nSelect = getUserType();
    customButtonOk->setDisable();
    update();
}

void PageUserCheck::pageHide()
{
    //setUserType(nSelect);
    setUserType(0);
    emit signalShowPageNum(PAGE_USER_FINGER);
}

void PageUserCheck::mousePressEvent(QMouseEvent *ev)
{
    /*
    for(int i=0; i<3; i++)
    {
        if(instance.touchCheck(labelText[i]->geometry(),ev) || instance.touchCheck(labelButton[i]->geometry(),ev))
        {
            nSelect = i;
            update();
        }
    }
    */
    if(instance.touchCheck(labelText->geometry(),ev) || instance.touchCheck(labelButton->geometry(),ev))
    {
        if(!customButtonOk->getEnable())
            customButtonOk->setEnable();
        else
            customButtonOk->setDisable();

        update();
    }

    if(instance.touchCheck(customButtonOk->geometry(),ev))
    {
        if(customButtonOk->getEnable())
        {
            pageHide();
        }
    }
}

void PageUserCheck::setUserType(int nSelect)
{
    int nSelectType = GAPI_CALI_UTYPE_PRE_DIABETES;

    switch (nSelect) {
    case 0:
        nSelectType = GAPI_CALI_UTYPE_PRE_DIABETES;
        break;
    case 1:
        nSelectType = GAPI_CALI_UTYPE_NORMAL;
        break;
    case 2:
        nSelectType = GAPI_CALI_UTYPE_DIABETES;
        break;
    default:
        nSelectType = GAPI_CALI_UTYPE_PRE_DIABETES;
        break;
    }
#if DEVICE
    instance.setNumUserCheck(nSelectType);
#endif

}

int PageUserCheck::getUserType()
{
    int nSelectType;

#if DEVICE
    nSelectType = instance.getNumUserCheck();
#else
    nSelectType = GAPI_CALI_UTYPE_PRE_DIABETES;
#endif

    switch (nSelectType) {
    case GAPI_CALI_UTYPE_PRE_DIABETES:
        return 0;
        break;
    case GAPI_CALI_UTYPE_NORMAL:
        return 1;
        break;
    case GAPI_CALI_UTYPE_DIABETES:
        return 2;
        break;
    default:
        return 0;
        break;
    }
}
