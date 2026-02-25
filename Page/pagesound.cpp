#include "pagesound.h"

PageSound::PageSound(QWidget *parent) : Page(parent)
{
    this->setGeometry(parent->geometry());
    soundWatcher = new QFutureWatcher<void>(this);
    connect(soundWatcher, &QFutureWatcher<void>::finished,this,[this](){touchEnabled = true;});
    init();
}

void PageSound::init()
{
    labelVolume = new QLabel(this);
    labelVolume->setGeometry(0,121,640,138);
    labelVolume->setAlignment(Qt::AlignCenter);

    labelArrowLeft = new QLabel(this);
    //labelArrowLeft->setGeometry(135,155,70,70);
    labelArrowLeft->setGeometry(62,155,70,70);
    labelArrowRight = new QLabel(this);
    //labelArrowRight->setGeometry(435,155,70,70);
    labelArrowRight->setGeometry(508,155,70,70);

    labelBarBg = new QLabel(this);
    labelBarBg->setGeometry(70,311,500,5);
    labelBar = new QLabel(this);
    labelBar->setGeometry(70,311,500,5);
    labelBarTouch = new QLabel(this);
    labelBarTouch->setGeometry(70,266,500,92);

    labelCircle = new QLabel(this);
    labelCircle->setFixedSize(18,18);
    labelImgMin = new QLabel(this);
    labelImgMin->setGeometry(70,266,35,35);
    labelMinTouch = new QLabel(this);
    labelMinTouch->setGeometry(0,266,69,92);
    labelImgMax = new QLabel(this);
    labelImgMax->setGeometry(535,266,35,35);
    labelMaxTouch = new QLabel(this);
    labelMaxTouch->setGeometry(571,266,69,92);

    customButtonSave = new CustomButtonSave(this);
    customButtonCancel = new CustomButtonCancel(this);

    update();
}

void PageSound::initVolume()
{
    instance.guiApi.glucoseGetSpeakerData(&instance.spkData);
    nVolume = instance.spkData.vol;

    setVolume();
}

void PageSound::update()
{
    customButtonSave->update();
    customButtonCancel->update();

    labelVolume->setFont(textResource.getFont(PAGE_SOUND,"labelVolume"));
    instance.pixLoad(labelArrowLeft,false,strDirPath,"/arrowLeft.png");
    instance.pixLoad(labelArrowRight,false,strDirPath,"/arrowRight.png");
    instance.pixLoad(labelCircle,false,strDirPath,"/circle.png");
    instance.pixLoad(labelImgMin,false,strDirPath,"/imgMin.png");
    instance.pixLoad(labelImgMax,false,strDirPath,"/imgMax.png");

    labelBarBg->setStyleSheet("background-color: #cccccc; border-radius: 2px;");
    labelBar->setStyleSheet("background-color: #077bdd; border-radius: 2px;");

    setScreen();
}

void PageSound::setVolume()
{
#if DEVICE
    //qDebug()<<"set nVolume" << nVolume;
    instance.spkData.vol = nVolume;
    //qDebug()<<"set spkData.vol: "<<instance.spkData.vol;
    instance.guiApi.glucoseSetSpeakerData(&instance.spkData);

    checkVolume();

    QString hexReg, hexVal;
    hexReg = "0x0C";

    if(nVolume <= 0)
    {
        hexVal = "0x100";
    }
    else
    {
        int regVal = 0xCB + ((nVolume -5)/5)*2;
        regVal |= 0x100;
        hexVal = QString("0x%1").arg(regVal, 3, 16, QLatin1Char('0')).toUpper();
    }

    QProcess::execute("/run/media/mmcblk0p3/gui/rpmsg_tool.sh",{hexReg,hexVal});
#else

#endif
}

void PageSound::setVolumeOut()
{
    if(!touchEnabled || bIsProcessing)
        return;

    touchEnabled = false;
    bIsProcessing = true;

#if DEVICE
    QtConcurrent::run([this](){
        instance.guiApi.glucoseSpeakerOut(GAPI_SPK_VOLUME_BEEP);

        QMetaObject::invokeMethod(this,[this](){
            touchEnabled = true;
            bIsProcessing = false;
        },Qt::QueuedConnection);
    });
#else
    QTimer::singleShot(100, this, [this]() { // 500ms는 예제값, 소리 출력 시간을 대체
            touchEnabled = true;
            bIsProcessing = false;
    });

#endif
}

void PageSound::setScreen()
{
    checkVolume();

    labelBar->setGeometry(70,311,5*nVolume,5);
    labelCircle->move(70+labelBar->width()-9,305);
    labelVolume->setText(QString::number(nVolume));
}

void PageSound::setVolumeMin()
{
    nVolume = 0;
    setScreen();
    setVolume();
    setVolumeOut();
}

void PageSound::setVolumeMax()
{
    nVolume = 100;
    setScreen();
    setVolume();
    setVolumeOut();
}

void PageSound::pageShow()
{
#if DEVICE
    touchEnabled = true;
    //qDebug()<<"PageSound prev spkData.vol:"<<&instance.spkData.vol;
    instance.guiApi.glucoseGetSpeakerData(&instance.spkData);
    qDebug()<<"PageSound get spkData.vol:"<<instance.spkData.vol;
#endif

    prevSpkData = instance.spkData;
    nVolume = instance.spkData.vol;
    update();
}

void PageSound::checkVolume()
{
    if(nVolume<0)
    {
        nVolume = 0;
    }
    else if(nVolume>100)
    {
        nVolume = 100;
    }
}

void PageSound::pageHide()
{
    emit signalShowPageNum(PAGE_MENU);
}

void PageSound::mousePressEvent(QMouseEvent *ev)
{
    if(touchEnabled != true)
        return;

    if(instance.touchCheck(customButtonSave->geometry(),ev))
    {
#if DEVICE
#else
        instance.spkData.vol = nVolume;
#endif
        pageHide();
    }

    if(instance.touchCheck(customButtonCancel->geometry(),ev))
    {
#if DEVICE
        instance.guiApi.glucoseSetSpeakerData(&prevSpkData);
        nVolume = prevSpkData.vol;
        setVolume();
#else
        instance.spkData = prevSpkData;
#endif
        pageHide();
    }

    if (instance.touchCheck(labelArrowLeft->geometry(), ev))
    {
        if ((nVolume - 5) % 5 == 0)
        {
            nVolume -= 5; // 5를 빼도 5의 배수로 유지되는 경우
        }
        else
        {
            nVolume = (nVolume / 5) * 5; // 5로 나눈 몫에 5를 곱하여 5의 배수로 만듦
        }
        setVolume();
        setVolumeOut();
        setScreen();
    }

    if (instance.touchCheck(labelArrowRight->geometry(), ev))
    {
        if ((nVolume + 5) % 5 == 0)
        {
            nVolume += 5; // 5를 더해도 5의 배수로 유지되는 경우
        }
        else
        {
            nVolume = ((nVolume / 5) + 1) * 5; // 5의 배수로 올림
        }
        setVolume();
        setVolumeOut();
        setScreen();
    }

    /*
    if(instance.touchCheck(labelImgMin->geometry(),ev))
    {
        setVolumeMin();
    }

    if(instance.touchCheck(labelImgMax->geometry(),ev))
    {
        setVolumeMax();
    }
    */
    if(instance.touchCheck(labelMinTouch->geometry(),ev))
    {
        setVolumeMin();
    }
    if(instance.touchCheck(labelMaxTouch->geometry(),ev))
    {
        setVolumeMax();
    }

    if(instance.touchCheck(labelBarTouch->geometry(),ev))
    {
        isBarTouch = true;
        //nVolume = static_cast<int>((ev->x() - 70)/5);
        int rawVolume = (ev->x() -70)/5;
        nVolume = ((rawVolume +2)/5)*5;
        setScreen();
    }
}

void PageSound::mouseReleaseEvent(QMouseEvent *ev)
{
    Q_UNUSED(ev)

    if(isBarTouch == true)
    {
        isBarTouch = false;
        setVolume();
        setVolumeOut();
    }
}

void PageSound::mouseMoveEvent(QMouseEvent *ev)
{
    /*
    if(isBarTouch == true)
    {
        nVolume = (ev->x() -70)/5;
        setScreen();
    }
    */

    if(isBarTouch == true)
    {
        int rawVolume = (ev->x() - 70) / 5;
        // 5단위로 반올림
        nVolume = ((rawVolume + 2) / 5) * 5;

        setScreen();
    }
}
