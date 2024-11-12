#include "pagehome.h"

PageHome::PageHome(QWidget *parent) : Page(parent)
{
    this->setGeometry(parent->geometry());
    init();
}

void PageHome::init()
{
    listRectButton.append(QRect(10,87,145,185));
    listRectButton.append(QRect(168,87,145,185));
    listRectButton.append(QRect(327,87,145,185));
    listRectButton.append(QRect(486,87,145,185));
    listRectButton.append(QRect(10,285,145,185));
    listRectButton.append(QRect(168,285,145,185));
    listRectButton.append(QRect(327,285,145,185));
    listRectButton.append(QRect(486,285,145,185));

    listRectTitle.append(QRect(10,100,145,84));
    listRectTitle.append(QRect(168,100,145,84));
    listRectTitle.append(QRect(327,100,145,84));
    listRectTitle.append(QRect(486,100,145,84));
    listRectTitle.append(QRect(10,295,145,84));
    listRectTitle.append(QRect(168,295,145,84));
    listRectTitle.append(QRect(327,295,145,84));
    listRectTitle.append(QRect(486,295,145,84));

    listRectImage.append(QRect(66,178,79,70));
    listRectImage.append(QRect(248,189,50,56));
    listRectImage.append(QRect(399,193,61,51));
    listRectImage.append(QRect(549,189,63,54));
    listRectImage.append(QRect(71,378,68,68));
    listRectImage.append(QRect(237,391,58,56));
    listRectImage.append(QRect(399,398,61,51));
    listRectImage.append(QRect(550,406,62,36));

    listRectText.append(QRect(10,175,145,76));
    listRectText.append(QRect(168,175,145,76));
    listRectText.append(QRect(327,175,145,76));
    listRectText.append(QRect(486,175,145,76));
    listRectText.append(QRect(10,369,145,76));
    listRectText.append(QRect(168,369,145,76));
    listRectText.append(QRect(327,369,145,76));
    listRectText.append(QRect(486,369,145,76));

    for(int i=0; i<8; i++)
    {
        labelGroups[i].labelButton = new QLabel(this);
        labelGroups[i].labelButton->setGeometry(listRectButton.at(i));

        labelGroups[i].labelButtonTitle = new QLabel(this);
        labelGroups[i].labelButtonTitle->setGeometry(listRectTitle.at(i));
        labelGroups[i].labelButtonTitle->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
        if(i<4)
            labelGroups[i].labelButtonTitle->setStyleSheet("color: #ffffff; padding-left: 10px;");
        else
            labelGroups[i].labelButtonTitle->setStyleSheet("color: #000000; padding-left: 10px;");

        labelGroups[i].labelButtonImage = new QLabel(this);
        labelGroups[i].labelButtonImage->setGeometry(listRectImage.at(i));

        labelGroups[i].labelButtonText = new QLabel(this);
        labelGroups[i].labelButtonText->setGeometry(listRectText.at(i));
        labelGroups[i].labelButtonText->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    }

    strListBg = QStringList{"WakeUp","BreakFastBefore","BreakFastAfter","LunchBefore","LunchAfter","DinnerBefore","DinnerAfter","BedTime"};

    update();
}

void PageHome::update()
{
    for(int i=0; i<8; i++)
    {
        QString pngPath = "/Bg_";
        pngPath += strListBg.at(order[i]);
        pngPath += ".png";

        QPixmap pixmap = instance.pixLoad(false,strDirPath,pngPath);
        labelGroups[i].labelButton->setPixmap(pixmap.copy());

        labelGroups[i].labelButtonTitle->setFont(textResource.getFont(PAGE_HOME,"labelButtonTitle"));
        labelGroups[i].labelButtonTitle->setText(textResource.getText(PAGE_HOME,"labelButtonTitle").at(order[i]));

        pngPath = "/Icon_";
        pngPath += strListBg.at(order[i]);
        pngPath += ".png";

        pixmap = instance.pixLoad(false,strDirPath,pngPath);
        labelGroups[i].labelButtonImage->setPixmap(pixmap.copy());

        labelGroups[i].labelButtonImage->hide();
        labelGroups[i].labelButtonText->hide();

        if(instance.histInfo.val[order[i]].valid_flag == 0)
        {
            labelGroups[i].labelButtonImage->show();
        }
        else
        {
            labelGroups[i].labelButtonText->show();
            int glucoseValue = instance.histInfo.val[order[i]].value;

            setLabelTextColor(labelGroups[i].labelButtonText,glucoseValue);
        }
    }
}

void PageHome::setLabelTextColor(QLabel *labelText, int &glucoseValue)
{
    int thresholdLow = instance.thresholdLow;
    int thresholdHigh = instance.thresholdHigh;

    QString strColor = "color: #666666;";

    switch (instance.getDeviceColor())
    {
    case COLOR_DEFAULT:

        if(glucoseValue<=thresholdLow || glucoseValue>=thresholdHigh)
        {
            strColor = "color: #f2b29;";
        }
        else if(glucoseValue<=thresholdLow+GLUCOSE_LOW_PLUS || glucoseValue>=thresholdHigh+GLUCOSE_HIGH_MINUS)
        {
            strColor = "color: #ff6f00;";
        }
        else
        {
            strColor = "color: #000000;";
        }
        break;
    case COLOR_BLUE:
    case COLOR_RED:
        break;
    }

    labelText->setStyleSheet(strColor+" padding-right: 5px");
    labelText->setFont(textResource.getFont(PAGE_HOME,"labelButtonText"));
    labelText->setText(QString::number(glucoseValue));
}

void PageHome::mousePressEvent(QMouseEvent *ev)
{
    for(int i=0; i<8; i++)
    {
        if(instance.touchCheck(labelGroups[i].labelButton->geometry(),ev))
        {
            instance.setTimeStatus(static_cast<TimeStatus>(i));
            emit signalShowSelect();
        }
    }
}

void PageHome::pageShow()
{

}

void PageHome::pageHide()
{

}
