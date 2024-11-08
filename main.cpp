#include "mainwindow.h"

#include <QApplication>
#include <singleton.h>
#include "Page/pagebooting.h"

QRect getInitialWindowRect(QScreen* screen) {
#if DEVICE == false
    // 개발용 임시 윈도우 크기
    Q_UNUSED(screen);
    return QRect(0, 0, 640, 480);
#else
    // 실제 장치 화면 크기
    return screen->availableGeometry();
#endif
}

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    // 주 화면 정보 가져오기
    QScreen* screen = qApp->primaryScreen();
    QRect windowRect = getInitialWindowRect(screen);

    // 터치 이벤트가 처리되지 않았을 때 마우스 이벤트로 대체
    QCoreApplication::setAttribute(Qt::AA_SynthesizeMouseForUnhandledTouchEvents);

    PageBooting* pageBooting = new PageBooting(windowRect);

    MainWindow w;
    w.setGeometry(windowRect);
    w.move(pageBooting->getBootingPoint());

    QObject::connect(pageBooting,&PageBooting::signalFinished,[&](){
        w.show();
        delete pageBooting;
    });

    return a.exec();
}
