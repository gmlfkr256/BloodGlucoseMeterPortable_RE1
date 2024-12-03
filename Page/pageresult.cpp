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

    customButtonSave = new CustomButtonSave(this);
    customButtonCancel = new CustomButtonCancel(this);
    update();
}

void PageResult::update()
{
    customButtonSave->update();
    customButtonCancel->update();

    int nTimeStatus = static_cast<int>(instance.getTimeStatus());

    labelTextGlucoseValue->setFont(textResource.getFont(PAGE_RESULT,"labelTextGlucoseValue"));

    labelTextMgdl->setFont(textResource.getFont(PAGE_RESULT,"labelTextMgdl"));
    labelTextMgdl->setText(textResource.getText(PAGE_RESULT,"labelTextMgdl").at(0));
    labelTextMgdl->setStyleSheet("color: #707070;");

    labelTextTime->setFont(textResource.getFont(PAGE_RESULT,"labelTextTime"));
    labelTextTime->setStyleSheet("border: 1px solid #707070; border-radius:20px;");

    QString strTime;
    strTime = textResource.getText(PAGE_RESULT,"labelTextTime").at(0)+" "
            +QString("%1:%2").arg(
                QString::number(instance.histInfo.val[nTimeStatus].hour).rightJustified(2,'0'),
                QString::number(instance.histInfo.val[nTimeStatus].min).rightJustified(2,'0')
                );

    labelTextTime->setText(textResource.getText(PAGE_RESULT,"labelTextTime").at(0));

    labelText->setFont(textResource.getFont(PAGE_RESULT,"labelText"));

    strTextColor = "color: black;";
    strTextValue = "-";

    labelProgressBarBg->setStyleSheet("background-color: #f2f2f2; border-radius: 15px;");
    labelProgressBarTooltip->setFont(textResource.getFont(PAGE_RESULT,"labelProgressBarTooltip"));

    if(instance.sysProcMonInfo.err_code != GAPI_PROC_ECODE_NORMAL)
    {
        labelBgGlucoseValue->setStyleSheet("background-color: #f2f2f2; border-radius: 18px;");
    }
    else
    {
        int nGlucoseValue;
#if DEVICE
        nGlucoseValue = instance.sysProcMonInfo.adc_raw;
#else
        nGlucoseValue = 160;
#endif
        strTextValue = QString::number(nGlucoseValue);
        strTextColor = instance.getTextColorGlucoseValue(nGlucoseValue,false);
        qDebug()<<"(pageResult) strTextColor: "<<strTextColor;
        setColorValue(nGlucoseValue);
    }

    labelTextGlucoseValue->setText(strTextValue);
    labelTextGlucoseValue->setStyleSheet(strTextColor);


}

void PageResult::setColorValue(int nGlucoseValue)
{
    QString strBgBorderRadius = "border-radius: 18px;";
    QString strBgColor;
    QString strStyleSheetProgressBar;
    int nIndexTooltip = 0;
    QString strStyleSheetTooltip;
    QString strPathPngTooltip;

    if(nGlucoseValue<=instance.nThresholdLimitLow || nGlucoseValue>=instance.nThresholdLimitHigh)
    {
        strBgColor = "background-color: #f2f2f2;";
        strStyleSheetProgressBar = "";
        nIndexTooltip = 3;
        strPathPngTooltip = "/triError.png";

    }
    else if(nGlucoseValue<=instance.thresholdLow || nGlucoseValue>=instance.thresholdHigh)
    {
        strBgColor = "background-color: #ffebeb;";
        strStyleSheetProgressBar = "background-image: url(:/Image/Default/Public/ImageResult/warning.png);";
        nIndexTooltip = 2;
        strPathPngTooltip = "/triWarning.png";
    }
    else if(nGlucoseValue<=instance.thresholdLow+GLUCOSE_LOW_PLUS || nGlucoseValue>=instance.thresholdHigh+GLUCOSE_HIGH_MINUS)
    {
        strBgColor = "background-color: #fdf6e8;";
        strStyleSheetProgressBar = "background-image: url(:/Image/Default/Public/ImageResult/caution.png);";
        nIndexTooltip = 1;
        strPathPngTooltip = "/triCaution.png";
    }
    else
    {
        strStyleSheetProgressBar = "background-image: url(:/Image/Default/Public/ImageResult/normal.png);";
        strBgColor = "background-color: #edfaf8;";
        nIndexTooltip = 0;
        strPathPngTooltip = "/triNormal.png";
    }

    labelBgGlucoseValue->setStyleSheet(strBgColor+strBgBorderRadius);

    strStyleSheetTooltip = instance.getBgColorGlucoseValue(nGlucoseValue) + "color: #ffffff; border-radius: 11px;";
    labelProgressBarTooltip->setStyleSheet(strStyleSheetTooltip);
    labelProgressBarTooltip->setText(textResource.getText(PAGE_RESULT,"labelProgressBarTooltip").at(nIndexTooltip));
    instance.pixLoad(labelProgressBarTooltipImg,false,strDirPath,strPathPngTooltip);

    int nProgressBarWidth = static_cast<int>(600*(static_cast<double>(nGlucoseValue)/400) );

    if(nProgressBarWidth <30)
        nProgressBarWidth = 30;
    else if(nProgressBarWidth >600)
        nProgressBarWidth = 600;
    labelProgressBar->setFixedWidth(nProgressBarWidth);
    labelProgressBarTooltip->move(labelProgressBar->x()+labelProgressBar->width()-(labelProgressBarTooltip->width()/2),297);
    labelProgressBarTooltipImg->setGeometry(labelProgressBarTooltip->x()+(labelProgressBarTooltip->width()/2)-3,labelProgressBarTooltip->y()+labelProgressBarTooltip->height(),7,5);
    labelProgressBar->setStyleSheet(strStyleSheetProgressBar+"border-radius: 15px;");

    QString strTextStatus = textResource.getText(PAGE_HOME,"labelTextStatus").at(instance.getTimeStatus());
    QString strResult;

    BloodSugarLevel bloodSugarLevel = instance.getBloodSugarLevel(nGlucoseValue);
    int nBloodSugarIndex = static_cast<int>(bloodSugarLevel);

    strResult = "<p style='font-weight:bold; line-height: 0.6;'>"+strTextStatus+" </p>";

    switch (instance.getDeviceLanguage())
    {
    case KR:
        strResult += "<span style='font-weight:bold; "+strTextColor+"'>"+textResource.getText(PAGE_RESULT,"indexResult").at(nBloodSugarIndex)+" </span>"
                +"<span style='color: #808080; '>"+textResource.getText(PAGE_RESULT,"indexResultSub").at(0)+"</span>";
        break;
    case EN:
        strResult += "<p style='font-weight:bold; "+strTextColor+" line-height: 0.5; font-size: 30px;'>"+textResource.getText(PAGE_RESULT,"indexResult").at(nBloodSugarIndex)+"</p>"
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

    qDebug()<<strResult;
    labelText->setText(strResult);
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
