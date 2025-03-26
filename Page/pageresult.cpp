#include "pageresult.h"

PageResult::PageResult(QWidget *parent) : Page(parent)
{
    this->setGeometry(parent->geometry());
    init();
}

void PageResult::init()
{
    labelBgGlucoseValue = new QLabel(this);
    labelBgGlucoseValue->setGeometry(347,106,256,164);
    labelTextGlucoseValue = new QLabel(this);
    labelTextGlucoseValue->setGeometry(347,106,256,129);
    labelTextGlucoseValue->setAlignment(Qt::AlignCenter);
    labelTextMgdl = new QLabel(this);
    labelTextMgdl->setGeometry(347,222,256,34);
    labelTextMgdl->setAlignment(Qt::AlignCenter);

    labelTextTime = new QLabel(this);
    labelTextTime->setGeometry(37,235,180,40);
    labelTextTime->setAlignment(Qt::AlignCenter);

    labelText = new QLabel(this);
    labelText->setGeometry(37,106,300,120);
    labelText->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);

    labelProgressBarBg = new QLabel(this);
    labelProgressBarBg->setGeometry(20,329,600,30);
    labelProgressBar = new QLabel(this);
    labelProgressBar->setGeometry(20,329,600,30);

    labelProgressBarTooltip = new QLabel(this);
    labelProgressBarTooltip->setGeometry(0,297,75,23);
    labelProgressBarTooltip->setAlignment(Qt::AlignCenter);

    labelProgressBarTooltipImg = new QLabel(this);
    labelProgressBarTooltipImg->setGeometry(0,0,7,5);

    labelProgressBarTextStart = new QLabel(this);
    labelProgressBarTextStart->setGeometry(31,302,10,20);
    labelProgressBarTextStart->setAlignment(Qt::AlignCenter);
    labelProgressBarTextEnd = new QLabel(this);
    labelProgressBarTextEnd->setGeometry(580,302,30,20);
    labelProgressBarTextEnd->setAlignment(Qt::AlignCenter);

    customButtonSave = new CustomButtonSave(this);
    customButtonCancel = new CustomButtonCancel(this);

    update();
}

void PageResult::update()
{
    customButtonSave->update();
    customButtonCancel->update();

    labelTextGlucoseValue->setFont(textResource.getFont(PAGE_RESULT,"labelTextGlucoseValue"));

    labelTextMgdl->setFont(textResource.getFont(PAGE_RESULT,"labelTextMgdl"));
    labelTextMgdl->setText(textResource.getText(PAGE_RESULT,"labelTextMgdl").at(0));
    labelTextMgdl->setStyleSheet("color: #707070;");

    labelTextTime->setFont(textResource.getFont(PAGE_RESULT,"labelTextTime"));
    labelTextTime->setStyleSheet("color: #707070; border: 1px solid #707070; border-radius:20px;");

    QString strTime;
    /*
#if DEVICE
    strTime = textResource.getText(PAGE_RESULT,"labelTextTime").at(0)+" "
            +QString("%1:%2").arg(
                QString::number(instance.histInfo.val[instance.getTimeStatus()].hour).rightJustified(2,'0'),
                QString::number(instance.histInfo.val[instance.getTimeStatus()].min).rightJustified(2,'0')
                );
#else
*/
    strTime = textResource.getText(PAGE_RESULT,"labelTextTime").at(0)+" "
            +QString("%1:%2").arg(
                QString::number(instance.sysProcMonInfo.hour).rightJustified(2,'0'),
                QString::number(instance.sysProcMonInfo.min).rightJustified(2,'0')
                );

    //#endif
    labelTextTime->setText(strTime);
    labelText->setFont(textResource.getFont(PAGE_RESULT,"labelText"));

    setValueUI();

    labelProgressBarTextStart->setStyleSheet("color: #777777;");
    labelProgressBarTextStart->setText("0");
    labelProgressBarTextEnd->setStyleSheet("color: #777777");
    labelProgressBarTextEnd->setText("400");
}

void PageResult::setValueUI()
{
    int nGlucoseValue = instance.sysProcMonInfo.adc_raw;
#if !DEVICE
    //nGlucoseValue = 250;
#endif
    if(nGlucoseValue>999)
        nGlucoseValue = 999;

    int nProgressBarWidth = 0;
    int nTooltipX = 0;
    int nIndexTooltip = 0;

    QString strBgGlucoseValueColor = "";
    QString strPathPngTooltip = "";
    QString strStyleSheetProgressBar = "";
    QString strStyleSheetTooltip = "";
    QString strLabelText = "";
    QString strTextGlucoseValueColor = "";

    QString strTooltip;

    ComponentMeasureResult comResult;
    instance.sysProcMonInfo.err_code = GAPI_PROC_ECODE_TIMEOUT;
    comResult.setTextResult(nullptr,instance.sysProcMonInfo.err_code);


    if(instance.sysProcMonInfo.err_code != GAPI_PROC_ECODE_NORMAL)
    {
        strBgGlucoseValueColor = "background-color: #f2f2f2;";
        nTooltipX = 320 - (labelProgressBarTooltip->width()/2);
        strPathPngTooltip = "/triError.png";

        labelTextGlucoseValue->setText("-");
        strTextGlucoseValueColor = "color:black;";
        nIndexTooltip = 3;

        labelProgressBarTooltip->hide();
        labelProgressBarTooltipImg->hide();
    }
    else
    {
        if(nGlucoseValue<=instance.thresholdLow || nGlucoseValue>=instance.thresholdHigh)
        {
            strBgGlucoseValueColor = "background-color: #ffebeb;";
            strPathPngTooltip = "/triWarning.png";
            strStyleSheetProgressBar = "background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, "
                                       "stop:0 #ffc94d, stop:1 #ec2c15);";
            nIndexTooltip = 2;
        }
        else if(nGlucoseValue<=instance.thresholdLow+GLUCOSE_LOW_PLUS || nGlucoseValue>=instance.thresholdHigh+GLUCOSE_HIGH_MINUS)
        {
            strBgGlucoseValueColor = "background-color: #fdf6e8;";
            strPathPngTooltip = "/triCaution.png";
            strStyleSheetProgressBar = "background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, "
                                       "stop:0 #52d0ba, stop:1 #ffc94d);";
            nIndexTooltip = 1;
        }
        else
        {
            strBgGlucoseValueColor = "background-color: #edfaf8;";
            strPathPngTooltip = "/triNormal.png";
            strStyleSheetProgressBar = "background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, "
                                       "stop:0 #077bdd , stop:1 #52d0ba);";
            nIndexTooltip = 0;
        }

        nProgressBarWidth = static_cast<int>(600*(static_cast<double>(nGlucoseValue)/400));
        if(nProgressBarWidth < 30)
            nProgressBarWidth = 30;
        else if(nProgressBarWidth > 600)
            nProgressBarWidth = 600;

        //
        strTooltip = textResource.getText(PAGE_RESULT,"labelProgressBarTooltip").at(nIndexTooltip);
        QFontMetrics metrics(labelProgressBarTooltip->font());
        int nTextWidth;
#if QT_VERSION >= QT_VERSION_CHECK(5, 11, 0)
        nTextWidth = metrics.horizontalAdvance(strTooltip) + 20;
#else
        nTextWidth = metrics.width(strTooltip) + 20;
#endif

        labelProgressBarTooltip->setFixedWidth(nTextWidth);
        //
        nTooltipX = labelProgressBar->x()+nProgressBarWidth-(labelProgressBarTooltip->width()/2);
        if(nTooltipX > labelProgressBarTextEnd->x()-labelProgressBarTooltip->width())
            nTooltipX = labelProgressBarTextEnd->x()-labelProgressBarTooltip->width()-5;
        else if(nTooltipX < labelProgressBarTextStart->x()+labelProgressBarTextStart->width())
            nTooltipX = labelProgressBarTextStart->x()+labelProgressBarTextStart->width()+5;

        QString strTextStatus = textResource.getText(PAGE_HOME,"labelTextStatus").at(instance.getTimeStatus());
        BloodSugarLevel bloodSugarLevel = instance.getBloodSugarLevel(nGlucoseValue);
        int nBloodSugarIndex = static_cast<int>(bloodSugarLevel);
        strLabelText = "<p style='font-weight:bold; line-height: 0.7;'>"+strTextStatus+" </p>";

        strTextGlucoseValueColor = instance.getTextColorGlucoseValue(nGlucoseValue,false);

        switch (instance.getDeviceLanguage())
        {
        case KR:
            strLabelText += "<span style='font-weight:bold; "+strTextGlucoseValueColor+"'>"+textResource.getText(PAGE_RESULT,"indexResult").at(nBloodSugarIndex)+" </span>"
                    +"<span style='color: #808080; '>"+textResource.getText(PAGE_RESULT,"indexResultSub").at(0)+"</span>";
            break;
        case EN:
        case JP:
        case SC:
        case TC:
        case ES:
            strLabelText += "<p style='font-weight:bold; "+strTextGlucoseValueColor+" line-height: 0.5; font-size: 30px;'>"+textResource.getText(PAGE_RESULT,"indexResult").at(nBloodSugarIndex)+"</p>"
                    +"<p style='color: #808080; font-size: 30px;'>"+textResource.getText(PAGE_RESULT,"indexResultSub").at(nBloodSugarIndex)+"</p>";
        case LAN_MAX:
            break;
        }
        //qDebug()<<"strLabelText: "<<strLabelText;
        labelText->setText(strLabelText);

        labelTextGlucoseValue->setText(QString::number(nGlucoseValue));

        labelProgressBarTooltip->show();
        labelProgressBarTooltipImg->show();
    }

    labelTextGlucoseValue->setStyleSheet(strTextGlucoseValueColor);
    labelBgGlucoseValue->setStyleSheet(strBgGlucoseValueColor+"border-radius: 18px;");
    labelProgressBarBg->setStyleSheet("background-color: #f2f2f2; border-radius: 15px;");
    labelProgressBar->setFixedWidth(nProgressBarWidth);
    labelProgressBar->setStyleSheet("");
    labelProgressBar->setStyleSheet(strStyleSheetProgressBar+"border-radius: 15px;");
    strStyleSheetTooltip = instance.getBgColorGlucoseValue(nGlucoseValue) + "color: #ffffff; border-radius: 11px;";
    labelProgressBarTooltip->setStyleSheet(strStyleSheetTooltip);

    labelProgressBarTooltip->setText(strTooltip);
    //labelProgressBarTooltip->setText(textResource.getText(PAGE_RESULT,"labelProgressBarTooltip").at(nIndexTooltip));
    labelProgressBarTooltip->move(nTooltipX,297);
    instance.pixLoad(labelProgressBarTooltipImg,false,strDirPath,strPathPngTooltip);
    labelProgressBarTooltipImg->setGeometry(labelProgressBarTooltip->x()+(labelProgressBarTooltip->width()/2)-3,labelProgressBarTooltip->y()+labelProgressBarTooltip->height(),7,5);


}

void PageResult::pageShow()
{
    update();
}

void PageResult::pageHide()
{

}

void PageResult::mousePressEvent(QMouseEvent *ev)
{
    if(instance.touchCheck(customButtonSave->geometry(),ev))
    {
#if DEVICE
        instance.histValue.valid_flag = instance.sysProcMonInfo.valid;
        instance.histValue.value = instance.sysProcMonInfo.adc_raw;
        instance.histValue.hour = instance.sysProcMonInfo.hour;
        instance.histValue.min = instance.sysProcMonInfo.min;

        if(instance.sysProcMonInfo.err_code == GAPI_PROC_ECODE_NORMAL)
            instance.guiApi.saveMeasurement(instance.getTimeStatus(),&instance.histValue);
        else
            qDebug()<<"result save fail - err_code:"<<instance.sysProcMonInfo.err_code;
#else
        /*
        instance.histInfo.val[instance.getTimeStatus()].valid_flag = 1;
        instance.histInfo.val[instance.getTimeStatus()].value = instance.sysProcMonInfo.adc_raw;
        instance.histInfo.val[instance.getTimeStatus()].hour = instance.sysProcMonInfo.hour;
        instance.histInfo.val[instance.getTimeStatus()].min = instance.sysProcMonInfo.min;
        */
        instance.hisInfo[0].val[instance.getTimeStatus()].valid_flag = 1;
        instance.hisInfo[0].val[instance.getTimeStatus()].value = instance.sysProcMonInfo.adc_raw;
        instance.hisInfo[0].val[instance.getTimeStatus()].hour = instance.sysProcMonInfo.hour;
        instance.hisInfo[0].val[instance.getTimeStatus()].min = instance.sysProcMonInfo.min;
#endif
        emit signalShowPageNum(PAGE_HOME);
    }

    if(instance.touchCheck(customButtonCancel->geometry(),ev))
    {
        emit signalShowPageNum(PAGE_HOME);
    }
}
