#include "pagecaliselect.h"

PageCaliSelect::PageCaliSelect(QWidget *parent) : Page(parent)
{
    this->setGeometry(parent->geometry());
    init();
}

void PageCaliSelect::init()
{
    for(int i=0; i<5; i++)
    {
        labelSelectButton[i] = new QLabel(this);
        labelSelectText[i] = new QLabel(this);
        labelSelectText[i]->setAlignment(Qt::AlignCenter);
        labelSelectNum[i] = new QLabel(this);

        labelSelectTextAdc[i] = new QLabel(this);
        labelSelectTextAdc[i]->setAlignment(Qt::AlignCenter);
        labelSelectTextValue[i] = new QLabel(this);
        labelSelectTextValue[i]->setAlignment(Qt::AlignCenter);
    }

    labelSelectButton[0]->setGeometry(160,90,150,180);
    labelSelectButton[1]->setGeometry(330,90,150,180);
    labelSelectButton[2]->setGeometry(80,280,150,180);
    labelSelectButton[3]->setGeometry(245,280,150,180);
    labelSelectButton[4]->setGeometry(410,280,150,180);

    for(int i=0; i<5; i++)
    {
        labelSelectText[i]->setGeometry(labelSelectButton[i]->geometry().x(),labelSelectButton[i]->y(),labelSelectButton[i]->width(),75);
        labelSelectNum[i]->setGeometry(labelSelectButton[i]->geometry().x()+33,labelSelectButton[i]->y()+75,85,85);

        labelSelectTextAdc[i]->setGeometry(labelSelectButton[i]->geometry().x(),labelSelectButton[i]->y()+38,labelSelectButton[i]->width(),45);
        labelSelectTextValue[i]->setGeometry(labelSelectButton[i]->geometry().x(),labelSelectButton[i]->y()+96,labelSelectButton[i]->width(),45);
    }

    update();
}

void PageCaliSelect::update()
{
    for(int i=0; i<5; i++)
    {
        if(instance.getCaliIndexCompleteCheck(i))
            instance.pixLoad(labelSelectButton[i],false,strDirPath,"/validBg.png");
        else
            instance.pixLoad(labelSelectButton[i],false,strDirPath,"/buttonBg.png");

        labelSelectText[i]->setFont(textResource.getFont(PAGE_CALI_SELECT,"labelSelectText"));
        labelSelectText[i]->setStyleSheet("color: #cecece;");

        if(i<2)
            labelSelectText[i]->setText(textResource.getText(PAGE_CALI_SELECT,"labelSelectText").at(0));
        else
            labelSelectText[i]->setText(textResource.getText(PAGE_CALI_SELECT,"labelSelectText").at(1));

        labelSelectTextAdc[i]->setFont(textResource.getFont(PAGE_CALI_SELECT,"labelSelectTextAdc"));
        labelSelectTextAdc[i]->setStyleSheet("color: #000000;");
        labelSelectTextValue[i]->setFont(textResource.getFont(PAGE_CALI_SELECT,"labelSelectTextValue"));
        labelSelectTextValue[i]->setStyleSheet("color: #000000;");
    }

    QStringList listPng = {"/num01.png","/num02.png","/num01.png","/num02.png","/num03.png"};
    for(int i=0; i<listPng.size(); i++)
    {
        instance.pixLoad(labelSelectNum[i],false,strDirPath,listPng.at(i));
    }

    for(int i=0; i<5; i++)
    {
        labelSelectText[i]->hide();
        labelSelectNum[i]->hide();
        labelSelectTextAdc[i]->hide();
        labelSelectTextValue[i]->hide();
    }

    for(int i=0; i<5; i++)
    {
        if(instance.caliUserInfo.val[i].valid)
        {
            int nAdcSum = 0;

            for(int j=0; j<3; j++)
            {
                nAdcSum += instance.caliUserInfo.val[i].adc[j];
            }

            int nAdcAvg = static_cast<int>(nAdcSum/3);
            int nValue = instance.caliUserInfo.glucose_val[i];

            qDebug()<<"pageSelect - adc: "<<nAdcAvg<<", nValie:"<<nValue;
            labelSelectTextAdc[i]->setText(QString::number(nAdcAvg));
            labelSelectTextValue[i]->setText(QString::number(nValue));

            labelSelectTextAdc[i]->show();
            labelSelectTextValue[i]->show();
        }
        else
        {
            labelSelectText[i]->show();
            labelSelectNum[i]->show();
        }
    }
}

void PageCaliSelect::mousePressEvent(QMouseEvent *ev)
{
    for(int i=0; i<5; i++)
    {
        if(instance.touchCheck(labelSelectButton[i]->geometry(),ev))
        {
            instance.setCaliSelectIndex(static_cast<CaliSelIndex>(i));
            emit signalShowPageNum(PAGE_CALI_SELECT_INFO);
        }
    }
}

void PageCaliSelect::pageShow()
{

}

void PageCaliSelect::pageHide()
{

}


