#include "pagephantommode.h"
#include "qrcodegen/qrcodegen.hpp"
#include <QPainter>

PagePhantomMode::PagePhantomMode(QWidget *parent) : Page(parent)
{
    this->setGeometry(parent->geometry());
    this->setStyleSheet("background-color: black;");
    init();
}

void PagePhantomMode::init()
{
    labelBg = new QLabel(this);
    labelBg->setGeometry(0,0,640,480);
    labelBg->setStyleSheet("background-color: black;");

    QFont font = QFont(instance.fontSuit,32,QFont::Bold);

    labelTitle = new QLabel(this);
    labelTitle->setGeometry(0,20,640,50);
    labelTitle->setStyleSheet("color: white;");
    labelTitle->setFont(font);
    labelTitle->setAlignment(Qt::AlignCenter);
    labelTitle->setText("PHANTOM");

    labelPhantomButton = new QLabel(this);
    labelPhantomButton->setGeometry(350,100,250,250);
    labelPhantomButton->setFont(font);
    labelPhantomButton->setAlignment(Qt::AlignCenter);
    labelPhantomButton->setStyleSheet("background-color: blue; color: white;");

    //hrkim 20261025 왼쪽 'Phantom:' 글자 자리에 디지털 라벨 QR + 글자 (최종 테스트 스캔용, XW-0416 (a))
    labelDlabelCode = new QLabel(this);
    labelDlabelCode->setGeometry(76,78,198,198);
    labelDlabelCode->setStyleSheet("color: white;");
    labelDlabelCode->setFont(QFont(instance.fontSuit,20,QFont::Bold));
    labelDlabelCode->setAlignment(Qt::AlignCenter);
    labelDlabelCode->setWordWrap(true);

    labelDlabelText = new QLabel(this);
    labelDlabelText->setGeometry(10,280,330,30);
    labelDlabelText->setStyleSheet("color: white;");
    labelDlabelText->setAlignment(Qt::AlignCenter);

    labelDlabelResult = new QLabel(this);
    labelDlabelResult->setGeometry(10,312,330,76);
    labelDlabelResult->setStyleSheet("color: white;");
    labelDlabelResult->setFont(QFont(instance.fontSuit,20,QFont::Bold));
    labelDlabelResult->setAlignment(Qt::AlignCenter);
    labelDlabelResult->setWordWrap(true);

    customButtonSave = new CustomButtonSave(this);
    customButtonCancel = new CustomButtonCancel(this);

    update();
}

void PagePhantomMode::update()
{
    if(nPhantomMode == GAPI_PHANTOM_MODE_MASS_PRODUCT)
    {
        labelPhantomButton->setText("MASS");
        labelPhantomButton->setStyleSheet("background-color: red; color: white;");
    }
    else if(nPhantomMode == GAPI_PHANTOM_MODE_QUALITY)
    {
        labelPhantomButton->setText("QUALITY");
        labelPhantomButton->setStyleSheet("background-color: green; color: white;");
    }
    else
    {
        labelPhantomButton->setText("OFF");
        labelPhantomButton->setStyleSheet("background-color: white; color: black;");
    }
}

//hrkim 20261025 mes-dlabel/prod_serial 값을 QR(ECC M, 여백 4칸, 흰 바탕) + 글자로 표시, 없으면 '디지털 라벨 없음' (XW-0416 (a))
void PagePhantomMode::updateDlabelCode()
{
    QString strLabel = instance.getDigitalLabel();
    labelDlabelText->clear();
    if(strLabel.isEmpty())
    {
        labelDlabelCode->setText("디지털 라벨 없음");
        return;
    }

    try
    {
        qrcodegen::QrCode qr = qrcodegen::QrCode::encodeText(strLabel.toUtf8().constData(), qrcodegen::QrCode::Ecc::MEDIUM);
        const int nQuiet = 4;
        int nCount = qr.getSize() + nQuiet*2;
        int nScale = qMax(1, labelDlabelCode->width() / nCount);

        QImage img(nCount*nScale, nCount*nScale, QImage::Format_RGB32);
        img.fill(Qt::white);
        QPainter painter(&img);
        for(int y=0; y<qr.getSize(); y++)
            for(int x=0; x<qr.getSize(); x++)
                if(qr.getModule(x,y))
                    painter.fillRect((x+nQuiet)*nScale, (y+nQuiet)*nScale, nScale, nScale, Qt::black);
        painter.end();
        labelDlabelCode->setPixmap(QPixmap::fromImage(img));
    }
    catch(const std::exception &e)
    {
        qDebug()<<"[fail] dlabel QR encode: "<<e.what();
        labelDlabelCode->setText("QR 오류");
    }

    //글자는 칸 폭에 맞을 때까지 줄임
    QFont fontText(instance.fontSuit,18,QFont::Bold);
    while(fontText.pointSize() > 10)
    {
#if QT_VERSION >= QT_VERSION_CHECK(5, 11, 0)
        int nTextWidth = QFontMetrics(fontText).horizontalAdvance(strLabel);
#else
        int nTextWidth = QFontMetrics(fontText).width(strLabel);
#endif
        if(nTextWidth <= labelDlabelText->width())
            break;
        fontText.setPointSize(fontText.pointSize()-1);
    }
    labelDlabelText->setFont(fontText);
    labelDlabelText->setText(strLabel);
}

void PagePhantomMode::pageShow()
{
    nPhantomMode = instance.nPhantomMode;
    bWaitConfirm = false;
    labelDlabelResult->clear();
    updateDlabelCode();
    update();
}

void PagePhantomMode::pageHide()
{
    emit signalShowPageNum(PAGE_MENU);
}

void PagePhantomMode::mousePressEvent(QMouseEvent *ev)
{
    if(instance.touchCheck(customButtonSave->geometry(),ev))
    {
        //hrkim 20260909 MASS/QUALITY → OFF 저장 = 테스트 종료: 팬텀 메뉴 숨김 (히든 토글로만 재노출)
        bool bTestEnd = (instance.nPhantomMode != GAPI_PHANTOM_MODE_NORMAL
                         && nPhantomMode == GAPI_PHANTOM_MODE_NORMAL);

        //hrkim 20261021 테스트 종료 시 디지털 라벨 삭제를 SET(직후 재부팅) 앞에 → 결과 표시 → SAVE 한 번 더 눌러야 SET (XW-0416)
        if(bTestEnd && !bWaitConfirm)
        {
            int nResult = instance.deleteDigitalLabel();
            updateDlabelCode();   //hrkim 20261025 삭제 결과를 QR 자리에도 반영 (XW-0416 (a))
            if(nResult == DLABEL_DELETE_FAIL)
            {
                //삭제 실패 시 SET 막음 (Hr 2026-10-21) — SAVE 다시 누르면 재시도
                labelDlabelResult->setStyleSheet("color: red;");
                labelDlabelResult->setText("LABEL DELETE FAIL");
                return;
            }

            labelDlabelResult->setStyleSheet("color: white;");
            labelDlabelResult->setText(nResult == DLABEL_DELETE_OK ? "LABEL DELETED\nSAVE TO FINISH"
                                                                   : "NO LABEL\nSAVE TO FINISH");
            bWaitConfirm = true;
            return;
        }

        //hrkim 20261021 메뉴 숨김 플래그를 SET 앞에 저장 (SET 직후 재부팅으로 유실 방지, XW-0416)
        if(bTestEnd)
            instance.savePhantomMenuShow(false);

        instance.nPhantomMode = nPhantomMode;
#if DEVICE
        instance.guiApi.glucoseSetPhantomUsage(nPhantomMode);
        instance.getCaliGainCompleteCheck();
#endif
        pageHide();
    }

    if(instance.touchCheck(customButtonCancel->geometry(),ev))
    {
        pageHide();
    }

    //hrkim 20261021 라벨 삭제 후 확인 대기 중에는 모드 변경 막음 (XW-0416)
    if(!bWaitConfirm && instance.touchCheck(labelPhantomButton->geometry(),ev))
    {
        nPhantomMode = (nPhantomMode + 1) % GAPI_PHANTOM_MODE_END;
        labelDlabelResult->clear();
        update();
    }
}
