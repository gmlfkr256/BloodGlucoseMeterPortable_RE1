#include "pageselect.h"

PageSelect::PageSelect(QWidget *parent): Page(parent)
{
    this->setGeometry(parent->geometry());
    init();
}

void PageSelect::init()
{
    customButtonHome = new CustomButtonHome(this);
    customButtonMeasureStart = new CustomButtonMeasureStart(this);

    labelArrowLeft = new QLabel(this);
    labelArrowLeft->setGeometry(10,202,53,53);
    labelArrowLeftTouch = new QLabel(this);
    labelArrowLeftTouch->setGeometry(0,73,100,317);

    labelArrowRight = new QLabel(this);
    labelArrowRight->setGeometry(578,202,53,53);
    labelArrowRightTouch = new QLabel(this);
    labelArrowRightTouch->setGeometry(540,73,100,317);

    labelBgCircle = new QLabel(this);
    labelBgCircle->setGeometry(239,98,162,162);
    labelImageTime = new QLabel(this);
    labelImageTime->setGeometry(260,129,120,100);

    labelTextStatus = new QLabel(this);
    labelTextStatus->setGeometry(0,275,640,52);
    labelTextStatus->setAlignment(Qt::AlignCenter);

    labelTextStatusSub = new QLabel(this);
    labelTextStatusSub->setGeometry(0,329,640,30);
    labelTextStatusSub->setAlignment(Qt::AlignCenter);

    //value
    labelTextStatusValue = new QLabel(this);
    labelTextStatusValue->setGeometry(0,84,640,50);
    labelTextStatusValue->setAlignment(Qt::AlignCenter);

    labelTextIcon = new QLabel(this);
    labelTextIcon->setGeometry(83,214,150,33);
    labelTextIcon->setAlignment(Qt::AlignCenter);

    labelTextGlucoseValue = new QLabel(this);
    labelTextGlucoseValue->setGeometry(0,149,640,162);
    labelTextGlucoseValue->setAlignment(Qt::AlignCenter);

    labelTextMgdl = new QLabel(this);
    labelTextMgdl->setGeometry(446,245,100,38);
    labelTextMgdl->setAlignment(Qt::AlignCenter);

    labelTextResult = new QLabel(this);
    labelTextResult->setGeometry(0,311,640,45);
    labelTextResult->setAlignment(Qt::AlignCenter);

    labelTextTime = new QLabel(this);
    labelTextTime->setGeometry(0,137,640,26);
    labelTextTime->setAlignment(Qt::AlignCenter);

    update();
}

void PageSelect::update()
{
    QString pngPath;
    QPixmap pixmap;

    pngPath = "/buttonArrowLeft.png";
    instance.pixLoad(labelArrowLeft,false,strDirPath,pngPath);

    pngPath = "/buttonArrowRight.png";
    instance.pixLoad(labelArrowRight,false,strDirPath,pngPath);

    labelTextStatus->setFont(textResource.getFont(PAGE_SELECT,"labelTextStatus"));
    labelTextStatusSub->setFont(textResource.getFont(PAGE_SELECT,"labelTextStatusSub"));
    labelTextStatusSub->setText(textResource.getText(PAGE_SELECT,"labelTextStatusSub").at(0));

    labelTextStatusValue->setFont(textResource.getFont(PAGE_SELECT,"labelTextStatusValue"));
    labelTextGlucoseValue->setFont(textResource.getFont(PAGE_SELECT,"labelTextGlucoseValue"));
    labelTextMgdl->setFont(textResource.getFont(PAGE_SELECT,"labelTextMgdl"));
    labelTextResult->setFont(textResource.getFont(PAGE_SELECT,"labelTextResult"));
    labelTextIcon->setFont(textResource.getFont(PAGE_SELECT,"labelTextIcon"));

    updateStatus();
}

void PageSelect::updateStatus()
{
    QString pngPath;
    QPixmap pixmap;
    int nTimeStatus = static_cast<int>(instance.getTimeStatus());

    labelBgCircle->hide();
    labelImageTime->hide();
    labelTextStatus->hide();
    labelTextStatusSub->hide();

    labelTextStatusValue->hide();
    labelTextGlucoseValue->hide();
    labelTextMgdl->hide();
    labelTextResult->hide();
    labelTextTime->hide();
    labelTextIcon->hide();

    if(instance.histInfo.val[nTimeStatus].valid_flag == 0)
    {
        pngPath = "/bg"+QString::number(nTimeStatus)+".png";
        instance.pixLoad(labelBgCircle,false,strDirPath,pngPath);
        pngPath = "/"+QString::number(nTimeStatus)+".png";
        instance.pixLoad(labelImageTime,false,strDirPath,pngPath);

        labelTextStatus->setText(textResource.getText(PAGE_HOME,"labelTextStatus").at(nTimeStatus));

        labelBgCircle->show();
        labelImageTime->show();
        labelTextStatus->show();
        labelTextStatusSub->show();
    }
    else
    {
        labelTextStatusValue->setText(textResource.getText(PAGE_HOME,"labelTextStatus").at(nTimeStatus));

        int glucoseValue = instance.histInfo.val[nTimeStatus].value;
        labelTextGlucoseValue->setText(QString::number(glucoseValue));

        QString strStyleSheetColor = instance.getTextColorGlucoseValue(glucoseValue);
        labelTextGlucoseValue->setStyleSheet(strStyleSheetColor);

        labelTextMgdl->setText("mg/dL");
        labelTextMgdl->setStyleSheet("color: #666666;");

        QString strResult;

        BloodSugarLevel bloodSugarLevel = instance.getBloodSugarLevel(glucoseValue);
        int bloodSugarIndex = static_cast<int>(bloodSugarLevel);

        strResult = textResource.getText(PAGE_SELECT,"labelTextResult").at(bloodSugarIndex);

        /*
        strResult =  "<span style='font-weight:bold;'>"+textResource.getText(PAGE_HOME,"labelTextStatus").at(nTimeStatus)+" "+"</span>" +
                "<span style='font-weight:bold; "+strStyleSheetColor+"'>"+textResource.getText(PAGE_SELECT,"labelTextResult").at(bloodSugarIndex)+" "+"</span>";
        switch (instance.getDeviceLanguage())
        {
        case KR:
            strResult +=
                    "<span>"+textResource.getText(PAGE_SELECT,"resultSub").at(0)+"</span>";
            break;
        case EN:
            break;
        case JP:
            break;
        case CN_GAN:
            break;
        case CN_BUN:
            break;
        case LAN_MAX:
            break;
        }
        */

        labelTextResult->setText(strResult);

        //labelTextTime->setStyleSheet("color: #777777; border: 1px solid #777777; border-radius: 18px");
        labelTextTime->setStyleSheet("color: #707070;");
        QString strTime;
        strTime = textResource.getText(PAGE_SELECT,"labelTextTime").at(0)+" "+QString("%1:%2").arg(QString::number(instance.histInfo.val[nTimeStatus].hour).rightJustified(2,'0'),QString::number(instance.histInfo.val[nTimeStatus].min).rightJustified(2,'0'));
        labelTextTime->setText(strTime);

        labelTextIcon->setText(textResource.getText(PAGE_SELECT,"labelTextIcon").at(bloodSugarIndex));

        switch (bloodSugarLevel)
        {
        case BLOOD_NORMAL:
            labelTextIcon->setStyleSheet("background-color: #52d0ba; color: #ffffff; padding-right: 13px; padding-left: 13px; border-radius: 16px;");
            break;
        case BLOOD_CAUTION_LOW:
        case BLOOD_CAUTION_HIGH:
            labelTextIcon->setStyleSheet("background-color: #ffb200; color: #ffffff;  padding-right: 13px; padding-left: 13px; border-radius: 16px;");
            break;
        case BLOOD_WARNING_LOW:
        case BLOOD_WARNING_HIGH:
            labelTextIcon->setStyleSheet("background-color: #f70000; color: #ffffff;  padding-right: 13px; padding-left: 13px; border-radius: 16px;");
            break;
        }

        labelTextIcon->adjustSize();

        labelTextStatusValue->show();
        labelTextGlucoseValue->show();
        labelTextMgdl->show();
        labelTextResult->show();
        labelTextTime->show();
        labelTextIcon->show();
    }
}

void PageSelect::mousePressEvent(QMouseEvent *ev)
{
    if(instance.touchCheck(labelArrowLeftTouch->geometry(),ev))
    {
        int nTimeStatus = instance.getTimeStatus();

        nTimeStatus--;

        nTimeStatus = (nTimeStatus<WAKE_UP) ? WAKE_UP : nTimeStatus;

        instance.setTimeStatus(static_cast<TimeStatus>(nTimeStatus));
        updateStatus();
    }

    if(instance.touchCheck(labelArrowRightTouch->geometry(),ev))
    {
        int nTimeStatus = instance.getTimeStatus();

        nTimeStatus++;

        nTimeStatus = (nTimeStatus>BED_TIME) ? BED_TIME : nTimeStatus;

        instance.setTimeStatus((static_cast<TimeStatus>(nTimeStatus)));
        updateStatus();
    }

    if(instance.touchCheck(customButtonHome->geometry(),ev))
    {
        emit signalShowPageNum(PAGE_HOME);
    }

    if(instance.touchCheck(customButtonMeasureStart->geometry(),ev))
    {
        if(instance.getCaliGainCompleteCheck())
        {
            instance.setGraphMode(GRAPH_MEASURE);
            emit signalShowPageNum(PAGE_GRAPH);
        }
    }
}

void PageSelect::pageShow()
{
    update();
}

void PageSelect::pageHide()
{

}

