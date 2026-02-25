#include "pagecaliselectre.h"

PageCaliSelectRe::PageCaliSelectRe(QWidget *parent) : Page(parent)
{
    this->setGeometry(parent->geometry());
    init();
}

void PageCaliSelectRe::init()
{
    for(int i=0; i<6; i++)
    {
        customBox[i] = new CustomBox(this);
    }

    customBox[0]->setGeometry(55,87,150,180);
    customBox[1]->setGeometry(245,87,150,180);
    customBox[2]->setGeometry(435,87,150,180);
    customBox[3]->setGeometry(55,277,150,180);
    customBox[4]->setGeometry(245,277,150,180);
    customBox[5]->setGeometry(435,277,150,180);

    for(int i=0; i<5; i++)
    {
        labelSelectArrow[i] = new QLabel(this);
    }

    labelSelectArrow[0]->setGeometry(401,162,29,29);
    labelSelectArrow[1]->setGeometry(591,162,29,29);
    labelSelectArrow[2]->setGeometry(21,352,29,29);
    labelSelectArrow[3]->setGeometry(211,352,29,29);
    labelSelectArrow[4]->setGeometry(401,352,29,29);

    update();
}

void PageCaliSelectRe::update()
{
    for(int i=0; i<5; i++)
    {
        instance.pixLoad(labelSelectArrow[i],false,strDirPath,"/labelArrowEmpty.png");
    }

    for(int i=0; i<6; i++)
    {
        customBox[i]->labelSelectText->setFont(textResource.getFont(PAGE_CALI_SELECT_RE,"labelText"));
        customBox[i]->labelSelectText->setText(textResource.getText(PAGE_CALI_SELECT_RE,"labelText").at(i));
        customBox[i]->labelSelectTextValue->setFont(textResource.getFont(PAGE_CALI_SELECT_RE,"labelTextValue"));
        //customBox[i]->labelSelectTextValue->setText("");

        if(i==0)
        {
            customBox[i]->labelSelectText->setStyleSheet("color: #cecece;");
            instance.pixLoad(customBox[i]->labelSelectButton,false,strDirPath,"/buttonFrame.png");
            for(int j=0; j<3; j++)
            {
                instance.pixLoad(customBox[i]->labelSelectCheckBox[j],false,strDirPath,"/checkEx.png");
            }

            customBox[i]->labelSelectTextValue->setText("107");
            customBox[i]->labelSelectTextValue->setStyleSheet("color: #cecece;");

            instance.pixLoad(customBox[i]->labelSelectBar,false,strDirPath,"/barEmpty.png");
        }
        else
        {
            int nValue = 0;

            customBox[i]->labelSelectTextValue->setText("");

            if(instance.getCaliIndexCompleteCheck(i-1))
            {
                customBox[i]->labelSelectText->setStyleSheet("color: #ffffff;");

                instance.pixLoad(customBox[i]->labelSelectButton,false,strDirPath,"/buttonValid.png");
                for(int j=0; j<3; j++)
                {
                    instance.pixLoad(customBox[i]->labelSelectCheckBox[j],false,strDirPath,"/checkValid.png");
                }

                if(instance.getCaliIndexVenousCheck(i-1))
                {
                    customBox[i]->labelSelectTextValue->setStyleSheet("color: #f70000;");
                }
                else
                {
                    customBox[i]->labelSelectTextValue->setStyleSheet("color: #ffffff;");
                }

                instance.pixLoad(customBox[i]->labelSelectBar,false,strDirPath,"/barVaild.png");


                nValue = instance.caliUserInfo.glucose_val[i-1];

                qDebug()<<"pageCaliSelectRe - nValue: "<<nValue<<", i:"<<i;

                if(nValue != 0)
                {
                    customBox[i]->labelSelectTextValue->setText(QString::number(nValue));

                    switch (i) {
                    case 1:
                        instance.pixLoad(labelSelectArrow[0],false,strDirPath,"/labelArrowValid.png");
                        break;
                    case 2:
                        instance.pixLoad(labelSelectArrow[1],false,strDirPath,"/labelArrowValid.png");
                        instance.pixLoad(labelSelectArrow[2],false,strDirPath,"/labelArrowValid.png");
                        break;
                    case 3:
                        instance.pixLoad(labelSelectArrow[3],false,strDirPath,"/labelArrowValid.png");
                        break;
                    case 4:
                        instance.pixLoad(labelSelectArrow[4],false,strDirPath,"/labelArrowValid.png");
                        break;
                    default:
                        qDebug()<<"pageCaliSelectRe switch default";
                        break;
                    }

                }
            }
            else
            {
                customBox[i]->labelSelectText->setStyleSheet("color: #cecece;");
                instance.pixLoad(customBox[i]->labelSelectButton,false,strDirPath,"/buttonBg.png");
                for(int j=0; j<3; j++)
                {
                    instance.pixLoad(customBox[i]->labelSelectCheckBox[j],false,strDirPath,"/checkEmpty.png");
                }

                if(instance.getCaliIndexVenousCheck(i-1))
                {
                    customBox[i]->labelSelectTextValue->setStyleSheet("color: #f70000;");
                }
                else
                {
                    customBox[i]->labelSelectTextValue->setStyleSheet("color: #cecece;");
                }

                nValue = instance.caliUserInfo.glucose_val[i-1];

                if(nValue != 0)
                {
                    customBox[i]->labelSelectTextValue->setText(QString::number(nValue));
                }

                instance.pixLoad(customBox[i]->labelSelectBar,false,strDirPath,"/barEmpty.png");
            }
        }
    }
}

void PageCaliSelectRe::pageShow()
{
    update();
}

void PageCaliSelectRe::pageHide()
{

}

void PageCaliSelectRe::mousePressEvent(QMouseEvent *ev)
{
    for(int i=0; i<6; i++)
    {
        if(instance.touchCheck(customBox[i]->geometry(),ev))
        {
            if(i==0)
                return;

            if(i!=1)
            {
                if(!instance.caliUserInfo.val[i-2].valid)
                {
                    emit signalShowPageNum(PAGE_CALI_SELECT_CONFIRM);
                    return;
                }
            }

            if(!instance.getGainCompleteCheck())
            {
                //instance.setPageNumPrev(PAGE_CALI_SELECT);
                instance.setPageNumPrev(PAGE_CALI_SELECT_RE);
                emit signalShowPageNum(PAGE_USER_NOTICE);
                return;
            }

            instance.setCaliSelectIndex(static_cast<CaliSelIndex>(i-1));
            emit signalShowPageNum(PAGE_CALI_SELECT_INFO);
        }
    }
}
