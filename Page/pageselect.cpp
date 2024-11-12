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

    labelTextGlucoseValue = new QLabel(this);
    labelTextGlucoseValue->setGeometry(0,98,376,163);
    labelTextGlucoseValue->setAlignment(Qt::AlignRight | Qt::AlignVCenter);

    labelTextMgdl = new QLabel(this);
    labelTextMgdl->setGeometry(379,189,261,34);
    labelTextMgdl->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);

    labelTextResult = new QLabel(this);
    labelTextResult->setGeometry(0,253,640,40);
    labelTextResult->setAlignment(Qt::AlignCenter);

    labelTextTime = new QLabel(this);
    labelTextTime->setGeometry(237,305,167,36);
    labelTextTime->setAlignment(Qt::AlignCenter);

    update();
}

void PageSelect::update()
{
    QString pngPath;
    QPixmap pixmap;

    pngPath = "/buttonArrowLeft.png";
    pixmap = instance.pixLoad(false,strDirPath,pngPath);
    labelArrowLeft->setPixmap(pixmap.copy());

    pngPath = "/buttonArrowRight.png";
    pixmap = instance.pixLoad(false,strDirPath,pngPath);
    labelArrowRight->setPixmap(pixmap.copy());

    labelTextStatus->setFont(textResource.getFont(PAGE_SELECT,"labelTextStatus"));
    labelTextStatusSub->setFont(textResource.getFont(PAGE_SELECT,"labelTextStatusSub"));
    labelTextStatusSub->setText(textResource.getText(PAGE_SELECT,"labelTextStatusSub").at(0));

    labelTextGlucoseValue->setFont(textResource.getFont(PAGE_SELECT,"labelTextGlucoseValue"));

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

    labelTextGlucoseValue->hide();
    labelTextMgdl->hide();
    labelTextResult->hide();
    labelTextTime->hide();

    if(instance.histInfo.val[nTimeStatus].valid_flag == 0)
    {
        pngPath = "/bg"+QString::number(nTimeStatus)+".png";
        pixmap = instance.pixLoad(false,strDirPath,pngPath);
        labelBgCircle->setPixmap(pixmap.copy());
        pngPath = "/"+QString::number(nTimeStatus)+".png";
        pixmap = instance.pixLoad(false,strDirPath,pngPath);
        labelImageTime->setPixmap(pixmap.copy());

        labelTextStatus->setText(textResource.getText(PAGE_SELECT,"labelTextStatus").at(nTimeStatus));

        labelBgCircle->show();
        labelImageTime->show();
        labelTextStatus->show();
        labelTextStatusSub->show();
    }
    else
    {
        int nTimeStatus = instance.getTimeStatus();
        int glucoseValue = instance.histInfo.val[nTimeStatus].value;
        labelTextGlucoseValue->setText(QString::number(glucoseValue));

        QString strStyleSheet = instance.getTextColorGlucoseValue(glucoseValue);
        labelTextGlucoseValue->setStyleSheet(strStyleSheet);

        labelTextGlucoseValue->show();
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
}

void PageSelect::pageShow()
{

}

void PageSelect::pageHide()
{

}

