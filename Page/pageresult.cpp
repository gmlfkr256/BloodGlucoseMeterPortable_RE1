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
    labelTextTime->setGeometry(20,235,180,40);
    labelTextTime->setAlignment(Qt::AlignCenter);

    labelText = new QLabel(this);
    labelText->setGeometry(31,106,300,120);
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
    labelTextTime->setStyleSheet("border: 1px solid #707070; border-radius:20px;");

    QString strTime;
#if DEVICE
    strTime = textResource.getText(PAGE_RESULT,"labelTextTime").at(0)+" "
            +QString("%1:%2").arg(
                QString::number(instance.histInfo.val[nTimeStatus].hour).rightJustified(2,'0'),
                QString::number(instance.histInfo.val[nTimeStatus].min).rightJustified(2,'0')
                );
#else
    strTime = textResource.getText(PAGE_RESULT,"labelTextTime").at(0)+" "
            +QString("%1:%2").arg(
                QString::number(instance.sysProcMonInfo.hour).rightJustified(2,'0'),
                QString::number(instance.sysProcMonInfo.min).rightJustified(2,'0')
                );
#endif
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

    if(instance.sysProcMonInfo.err_code != GAPI_PROC_ECODE_NORMAL)
    {
        strBgGlucoseValueColor = "background-color: #f2f2f2;";
        nTooltipX = 320 - (labelProgressBarTooltip->width()/2);
        strPathPngTooltip = "/triError.png";
        ComponentMeasureResult comResult;
        comResult.setTextResult(labelText,instance.sysProcMonInfo.err_code);
        labelTextGlucoseValue->setText("-");
        strTextGlucoseValueColor = "color:black;";
        nIndexTooltip = 3;
    }
    else
    {
        if(nGlucoseValue<=instance.thresholdLow || nGlucoseValue>=instance.thresholdHigh)
        {
            strBgGlucoseValueColor = "background-color: #ffebeb;";
            strPathPngTooltip = "/triWarning.png";
            strStyleSheetProgressBar = "background-image: url(:/Image/Default/Public/ImageResult/warning.png) 0 0 0 0 stretch strech;";
            nIndexTooltip = 2;
        }
        else if(nGlucoseValue<=instance.thresholdLow+GLUCOSE_LOW_PLUS || nGlucoseValue>=instance.thresholdHigh+GLUCOSE_HIGH_MINUS)
        {
            strBgGlucoseValueColor = "background-color: #fdf6e8;";
            strPathPngTooltip = "/triCaution.png";
            strStyleSheetProgressBar = "background-image: url(:/Image/Default/Public/ImageResult/caution.png) 0 0 0 0 stretch strech;";
            nIndexTooltip = 1;
        }
        else
        {
            strBgGlucoseValueColor = "background-color: #edfaf8;";
            strPathPngTooltip = "/triNormal.png";
            strStyleSheetProgressBar = "background-image: url(:/Image/Default/Public/ImageResult/normal.png) 0 0 0 0 stretch strech;";
            nIndexTooltip = 0;
        }

        nProgressBarWidth = static_cast<int>(600*(static_cast<double>(nGlucoseValue)/400));
        if(nProgressBarWidth < 30)
            nProgressBarWidth = 30;
        else if(nProgressBarWidth > 600)
            nProgressBarWidth = 600;

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
            strLabelText += "<p style='font-weight:bold; "+strTextGlucoseValueColor+" line-height: 0.5; font-size: 30px;'>"+textResource.getText(PAGE_RESULT,"indexResult").at(nBloodSugarIndex)+"</p>"
                    +"<p style='color: #808080; font-size: 30px;'>"+textResource.getText(PAGE_RESULT,"indexResultSub").at(nBloodSugarIndex)+"</p>";
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
        qDebug()<<"strLabelText: "<<strLabelText;
        labelText->setText(strLabelText);

        labelTextGlucoseValue->setText(QString::number(nGlucoseValue));
    }

    labelTextGlucoseValue->setStyleSheet(strTextGlucoseValueColor);
    labelBgGlucoseValue->setStyleSheet(strBgGlucoseValueColor+"border-raidus: 18px;");
    labelProgressBarBg->setStyleSheet("background-color: #f2f2f2; border-radius: 15px;");
    labelProgressBar->setFixedWidth(nProgressBarWidth);
    labelProgressBar->setStyleSheet(strStyleSheetProgressBar+"border-radius: 15px;");
    strStyleSheetTooltip = instance.getBgColorGlucoseValue(nGlucoseValue) + "color: #ffffff; border-radius: 11px;";
    labelProgressBarTooltip->setStyleSheet(strStyleSheetTooltip);
    labelProgressBarTooltip->setText(textResource.getText(PAGE_RESULT,"labelProgressBarTooltip").at(nIndexTooltip));
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
        emit signalShowPageNum(PAGE_HOME);
    }

    if(instance.touchCheck(customButtonCancel->geometry(),ev))
    {
        emit signalShowPageNum(PAGE_HOME);
    }
}
