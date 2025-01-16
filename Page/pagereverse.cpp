#include "pagereverse.h"

PageReverse::PageReverse(QWidget *parent) : Page(parent)
{
    this->setGeometry(parent->geometry());
    init();
}

void PageReverse::init()
{
    labelButtonLeft = new QLabel(this);
    labelButtonLeft->setGeometry(75,98,245,215);
    labelTextLeft = new QLabel(this);
    labelTextLeft->setGeometry(labelButtonLeft->x(),labelButtonLeft->y()+150,245,45);
    labelTextLeft->setAlignment(Qt::AlignCenter);

    labelButtonRight = new QLabel(this);
    labelButtonRight->setGeometry(320,98,245,215);
    labelTextRight = new QLabel(this);
    labelTextRight->setGeometry(labelButtonRight->x(),labelButtonRight->y()+150,245,45);
    labelTextRight->setAlignment(Qt::AlignCenter);

    labelText = new QLabel(this);
    labelText->setGeometry(0,325,640,45);
    labelText->setAlignment(Qt::AlignCenter);

    customButtonOK = new CustomButtonOK(this);
    customButtonCancel = new CustomButtonCancel(this);

    update();
}

void PageReverse::update()
{
    customButtonOK->update();
    customButtonCancel->update();

    labelTextLeft->setFont(textResource.getFont(PAGE_REVERSE,"labelTextButton"));
    labelTextLeft->setText(textResource.getText(PAGE_REVERSE,"labelTextButton").at(0));

    labelTextRight->setFont(textResource.getFont(PAGE_REVERSE,"labelTextButton"));
    labelTextRight->setText(textResource.getText(PAGE_REVERSE,"labelTextButton").at(1));

    labelText->setFont(textResource.getFont(PAGE_REVERSE,"labelText"));
    labelText->setText(textResource.getText(PAGE_REVERSE,"labelText").at(0));

#if DEVICE
    if(instance.guiApi.glucoseGetDispData(&instance.dispData) == GAPI_SUCCESS)
    {
        qDebug()<<"instance.dispData.dir: "<<instance.dispData.dir;
    }
    else
    {
        qDebug()<<"glucoseGetDispData fail";
    }


    if(instance.dispData.dir == GAPI_DISP_DIR_NORMAL)
        bIsReverse = false;
    else
        bIsReverse = true;

    qDebug()<<"bIsRevers: "<<bIsReverse;
#endif

    setImgHand();
}

void PageReverse::setImgHand()
{
    QString strImgPathLeft = "/handLeft.png";
    QString strImgPathRight = "/handRight.png";

    if(!bIsReverse)
    {
        strImgPathLeft = "/handLeftOn.png";
    }
    else
    {
        strImgPathRight = "/handRightOn.png";
    }

    instance.pixLoad(labelButtonLeft,false,strDirPath,strImgPathLeft);
    instance.pixLoad(labelButtonRight,false,strDirPath,strImgPathRight);
}

void PageReverse::setImgHandPress()
{
    QString strImgPathLeft = "/handLeft.png";
    QString strImgPathRight = "/handRight.png";

    if(!bIsReverse)
    {
        strImgPathLeft = "/handLeftPress.png";
    }
    else
    {
        strImgPathRight = "/handRightPress.png";
    }

    instance.pixLoad(labelButtonLeft,false,strDirPath,strImgPathLeft);
    instance.pixLoad(labelButtonRight,false,strDirPath,strImgPathRight);
}

void PageReverse::pageShow()
{
    update();
}

void PageReverse::pageHide()
{
    emit signalShowPageNum(PAGE_MENU);
}

void PageReverse::mousePressEvent(QMouseEvent *ev)
{
    if(instance.touchCheck(labelButtonLeft->geometry(),ev))
    {
        bIsReverse = false;
        bIsButtonTouch = true;
        setImgHandPress();
    }

    if(instance.touchCheck(labelButtonRight->geometry(),ev))
    {
        bIsReverse = true;
        bIsButtonTouch = true;

        qDebug()<<"screen";
        QScreen *screen = QGuiApplication::primaryScreen();
        screen->setOrientationUpdateMask(Qt::PortraitOrientation);

        setImgHandPress();
    }

    if(instance.touchCheck(customButtonOK->geometry(),ev))
    {
        if(bIsReverse)
            instance.dispData.dir = GAPI_DISP_DIR_REVERSE;
        else
            instance.dispData.dir = GAPI_DISP_DIR_NORMAL;
#if DEVICE
        QLabel* labelScreen = new QLabel(nullptr);
        labelScreen->setGeometry(0,0,640,480);
        labelScreen->setStyleSheet("background-color: black;");
        labelScreen->setWindowFlag(Qt::Window);
        labelScreen->show();
        QCoreApplication::processEvents();

        instance.guiApi.glucoseGetDispData(&instance.dispData); // 현재 방향 가져오기
        bool isCurrentlyReverse = (instance.dispData.dir == GAPI_DISP_DIR_REVERSE);

        if (bIsReverse != isCurrentlyReverse)
        { // 상태가 다를 때만 실행

            if (bIsReverse)
            {
                instance.dispData.dir = GAPI_DISP_DIR_REVERSE;
                qputenv("QT_QPA_EGLFS_ROTATION", "-90");
                system("echo 1 > /proc/ts_rotation");
            }
            else
            {
                instance.dispData.dir = GAPI_DISP_DIR_NORMAL;
                qputenv("QT_QPA_EGLFS_ROTATION", "90");
                system("echo 0 > /proc/ts_rotation");
            }

            system("sync");

            instance.guiApi.glucoseSetDispData(&instance.dispData);

            instance.guiApi.glucoseDetach();

            QThread::msleep(1000);

            // 프로그램 재시작

            QTimer::singleShot(1000,[](){
                QProcess::startDetached(QCoreApplication::applicationFilePath());

                QScreen *screen = QGuiApplication::primaryScreen();
                if(screen)
                    screen->deleteLater();
                QGuiApplication::sync();

                QCoreApplication::instance()->quit();
            });

        }
#endif
        //pageHide();
    }

    if(instance.touchCheck(customButtonCancel->geometry(),ev))
    {
        pageHide();
    }
}

void PageReverse::mouseReleaseEvent(QMouseEvent *ev)
{
    Q_UNUSED(ev)

    if(bIsButtonTouch)
    {
        setImgHand();
        bIsButtonTouch = false;
    }
}
