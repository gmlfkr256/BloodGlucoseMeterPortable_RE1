#include "pageuserinfo.h"

PageUserInfo::PageUserInfo(QWidget *parent) : Page(parent)
{
    this->setGeometry(parent->geometry());
    init();
}

void PageUserInfo::init()
{
    for(int i=0; i<4; i++)
    {
        labelText[i] = new QLabel(this);
        labelText[i]->setGeometry(25,80+(i*75),590,75);
        labelText[i]->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
        labelArrow[i] = new QLabel(this);
        labelArrow[i]->setGeometry(labelText[i]->x()+551,labelText[i]->y(),40,73);

        labelLine[i] = new QLabel(this);
        labelLine[i]->setGeometry(labelText[i]->x(),labelText[i]->y()+labelText[i]->height()-1,labelText[i]->width(),1);
    }



    customButtonOK = new CustomButtonOK(this);
    customButtonOK->setLongWidth(true);
    update();
}

void PageUserInfo::update()
{
    customButtonOK->update();

    for(int i=0; i<4; i++)
    {
        labelText[i]->setFont(textResource.getFont(PAGE_USERINFO,"labelText"));
        labelText[i]->setText(textResource.getText(PAGE_USERINFO,"labelText").at(i));
        instance.pixLoad(labelArrow[i],false,strDirPath,"/arrow.png");

        labelLine[i]->setStyleSheet("background-color: #c5c5c5;");
    }

#if !NEW_PASSWORD
        labelText[1]->hide();
        labelArrow[1]->hide();
        labelArrow[1]->hide();

        labelText[3]->setGeometry(labelText[2]->geometry());
        labelArrow[3]->setGeometry(labelText[2]->geometry());
        labelLine[3]->setGeometry(labelText[2]->geometry());
        labelText[2]->setGeometry(labelText[1]->geometry());
        labelArrow[2]->setGeometry(labelText[1]->geometry());
        labelLine[2]->setGeometry(labelText[1]->geometry());
#endif
}

void PageUserInfo::pageShow()
{
    update();
}

void PageUserInfo::pageHide()
{
    emit signalShowPageNum(PAGE_MENU);
}

void PageUserInfo::mousePressEvent(QMouseEvent *ev)
{
    if(instance.touchCheck(customButtonOK->geometry(),ev))
    {
        pageHide();
    }

    if(instance.touchCheck(labelText[0]->geometry(),ev))
    {
        instance.setPasswordStrStatus(PASSWORD_STR_EDIT);
        emit signalShowPageNum(PAGE_PASSWORD_CONFIRM);
    }

#if NEW_PASSWORD
    if(instance.touchCheck(labelText[1]->geometry(),ev))
    {
        instance.setPasswordStrStatus(PASSWORD_STR_INIT);
        emit signalShowPageNum(PAGE_PASSWORD_CONFIRM);
    }
#endif

    if(instance.touchCheck(labelText[2]->geometry(),ev))
    {
        instance.setPasswordStrStatus(PASSWORD_STR_DELETE);
        emit signalShowPageNum(PAGE_PASSWORD_CONFIRM);
    }

    if(instance.touchCheck(labelText[3]->geometry(),ev))
    {
        instance.setPasswordStrStatus(PASSWORD_STR_LOGOUT);
        emit signalShowPageNum(PAGE_PASSWORD_CONFIRM);
    }
}
