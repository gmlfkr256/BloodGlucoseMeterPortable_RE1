#include "pagesound.h"

PageSound::PageSound(QWidget *parent) : Page(parent)
{
    this->setGeometry(parent->geometry());
    init();
}

void PageSound::init()
{
    labelVolume = new QLabel(this);
    labelVolume->setGeometry(0,121,640,138);
    labelVolume->setAlignment(Qt::AlignCenter);

    labelArrowLeft = new QLabel(this);
    labelArrowLeft->setGeometry(135,155,70,70);
    labelArrowRight = new QLabel(this);
    labelArrowRight->setGeometry(435,155,70,70);

    labelBarBg = new QLabel(this);
    labelBarBg->setGeometry(70,311,500,5);
    labelBar = new QLabel(this);
    labelBar->setGeometry(70,311,500,5);
    labelBarTouch = new QLabel(this);
    labelBarTouch->setGeometry(70,305,500,18);

    labelCircle = new QLabel(this);
    labelCircle->setFixedSize(18,18);
    labelImgMin = new QLabel(this);
    labelImgMin->setGeometry(70,273,35,35);
    labelImgMax = new QLabel(this);
    labelImgMax->setGeometry(535,273,35,35);

    customButtonSave = new CustomButtonSave(this);
    customButtonCancel = new CustomButtonCancel(this);

    update();
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
    if(nVolume>0)
    {
        instance.spkData.used = 1;
    }
    else
    {
        instance.spkData.used = 0;
    }

    checkVolume();

    instance.spkData.vol = nVolume;

#if DEVICE
    instance.guiApi.glucoseSetSpeakerData(&instance.spkData);
#endif
}

void PageSound::setVolumeOut()
{
#if DEVICE
    instance.guiApi.glucoseSpeakerOut(GAPI_SPK_VOLUME_BEEP);
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
}

void PageSound::pageShow()
{
#if DEVICE
    instance.guiApi.glucoseGetSpeakerData(&instance.spkData);
#else
    instance.spkData.vol = 50;
    instance.spkData.used = 1;
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
    if(instance.touchCheck(customButtonSave->geometry(),ev))
    {
        pageHide();
    }

    if(instance.touchCheck(customButtonCancel->geometry(),ev))
    {
#if DEVICE
        instance.guiApi.glucoseSetSpeakerData(&prevSpkData);
#else
        instance.spkData = prevSpkData;
#endif
        pageHide();
    }

    if(instance.touchCheck(labelArrowLeft->geometry(),ev))
    {
        nVolume-=5;
        nVolume = (nVolume/5)*5;
        setVolume();
        setVolumeOut();
        setScreen();
    }

    if(instance.touchCheck(labelArrowRight->geometry(),ev))
    {
        nVolume+=5;
        nVolume = (nVolume/5)*5;
        setVolume();
        setVolumeOut();
        setScreen();
    }

    if(instance.touchCheck(labelImgMin->geometry(),ev))
    {
        setVolumeMin();
    }

    if(instance.touchCheck(labelImgMax->geometry(),ev))
    {
        setVolumeMax();
    }

    if(instance.touchCheck(labelBarTouch->geometry(),ev))
    {
        isBarTouch = true;
        nVolume = (ev->x() - 70)/5;
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
    if(isBarTouch == true)
    {
        nVolume = (ev->x() -70)/5;
        setScreen();
    }
}
