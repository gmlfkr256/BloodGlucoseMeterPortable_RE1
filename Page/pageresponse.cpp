#include "pageresponse.h"

PageResponse::PageResponse(QWidget *parent) : Page(parent)
{
    this->setGeometry(parent->geometry());
    init();
}

void PageResponse::init()
{
    labelArrowTop = new QLabel(this);
    labelArrowTop->setGeometry(565,83,70,70);
    labelArorwDown = new QLabel(this);
    labelArorwDown->setGeometry(565,310,70,70);

    widgetWindow = new QWidget(this);
    widgetWindow->setGeometry(50,106,465,245);
    widgetWindow->setAttribute(Qt::WA_StyledBackground, true);
    widgetWindow->setContentsMargins(0,0,0,0);

    labelText = new QLabel(widgetWindow);
    labelText->setWordWrap(true);
    labelText->move(0,0);
    labelText->setMargin(0);
    labelText->setContentsMargins(0,0,0,0);

    labelNumCurrent = new QLabel(this);
    labelNumCurrent->setFont(textResource.getFont(PAGE_RESPONSE,"labelNumCurrent"));
    labelNumCurrent->setGeometry(565,160,70,70);
    labelNumCurrent->setStyleSheet("color: #000000;");
    labelNumCurrent->setAlignment(Qt::AlignCenter);

    labelNumBar = new QLabel(this);
    labelNumBar->setGeometry(575,230,50,3);
    labelNumBar->setStyleSheet("background-color: #000000;");

    labelNumAll = new QLabel(this);
    labelNumAll->setFont(textResource.getFont(PAGE_RESPONSE,"labelNumAll"));
    labelNumAll->setGeometry(565,233,70,70);
    labelNumAll->setStyleSheet("color: #000000;");
    labelNumAll->setAlignment(Qt::AlignCenter);

    labelTouchTop = new QLabel(this);
    labelTouchTop->setGeometry(40,73,520,96);

    labelTouchDown = new QLabel(this);
    labelTouchDown->setGeometry(40,249,520,96);

    customButtonOK = new CustomButtonOK(this);
    customButtonOK->setLongWidth(true);

    instance.pixLoad(labelArrowTop,false,strDirPath,"/arrowTop.png");
    instance.pixLoad(labelArorwDown,false,strDirPath,"/arrowDown.png");

    timerPress = new QTimer(this);
    connect(timerPress, &QTimer::timeout, this, &PageResponse::handleTimerPress);

    update();
}

void PageResponse::update()
{
    customButtonOK->update();
    labelText->setFont(textResource.getFont(PAGE_RESPONSE,"labelText"));

    switch (instance.getPageNumPrev()) {
    case PAGE_HELP:
        labelText->setText(textResource.getText(PAGE_RESPONSE,"labelTextHelp").at(instance.nSelectTextIndex));
        break;
    case PAGE_FAQ:
        labelText->setText(textResource.getText(PAGE_RESPONSE,"labelTextFaq").at(instance.nSelectTextIndex));
        break;
    case PAGE_FAQ_RE:
        labelText->setText(textResource.getText(PAGE_RESPONSE,"labelTextFaq").at(instance.nSelectTextIndex));
        break;
    case PAGE_ERROR_HELP:
        labelText->setText(textResource.getText(PAGE_RESPONSE,"labelTextErrorHelp").at(instance.nSelectTextIndex));
        break;
    default:
        pageHide();
        break;
    }

    const int nViewWidth = 465;
    const int nViewHeight = 245;

    QFontMetrics fm = QFontMetrics(labelText->font());
    QRect rectText = fm.boundingRect(QRect(0,0,nViewWidth,10000),Qt::TextWordWrap,labelText->text());

    int textHeight = rectText.height();

    if(textHeight <= nViewHeight)
    {
        labelText->setGeometry(0,0,nViewWidth,nViewHeight);
        labelText->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
        m_nMaxLine = 0;

        labelNumCurrent->hide();
        labelNumBar->hide();
        labelNumAll->hide();
    }
    else
    {
        labelText->setGeometry(0,0,nViewWidth,textHeight);
        labelText->setAlignment(Qt::AlignLeft | Qt::AlignTop);
        m_nMaxLine = ( (labelText->height() - widgetWindow->height()) / m_nStep )+1;
        if(m_nMaxLine<0)
            m_nMaxLine = 0;

        labelNumCurrent->show();
        labelNumBar->show();
        labelNumAll->show();
    }

    m_nStep = fm.lineSpacing();

    labelNumCurrent->setText(QString::number(m_nCurrentLine+1));
    labelNumAll->setText(QString::number(m_nMaxLine+1));
}

void PageResponse::pageShow()
{
    m_nCurrentLine = 0;
    labelText->move(0,0);
    update();
}

void PageResponse::pageHide()
{
    emit signalShowPageNum(instance.getPageNumPrev());
}

void PageResponse::mousePressEvent(QMouseEvent *ev)
{
    if(instance.touchCheck(customButtonOK->geometry(),ev))
    {
        pageHide();
    }

    if(instance.touchCheck(labelArrowTop->geometry(),ev) || instance.touchCheck(labelTouchTop->geometry(),ev))
    {
        //textUp();
        bIsTop = true;
        handleTimerPress();
    }

    if(instance.touchCheck(labelArorwDown->geometry(),ev) || instance.touchCheck(labelTouchDown->geometry(),ev))
    {
        //textDown();
        bIsTop = false;
        handleTimerPress();
    }
}

void PageResponse::mouseReleaseEvent(QMouseEvent *ev)
{
    Q_UNUSED(ev)
    handleTimerRelease();
}

void PageResponse::textUp()
{
    if(m_nCurrentLine <= 0)
        return;

    m_nCurrentLine--;
    labelText->move(0,-m_nCurrentLine*m_nStep);
    labelNumCurrent->setText(QString::number(m_nCurrentLine+1));
}

void PageResponse::textDown()
{
    if(m_nCurrentLine >= m_nMaxLine)
        return;

    m_nCurrentLine++;
    labelText->move(0, -m_nCurrentLine*m_nStep);
    labelNumCurrent->setText(QString::number(m_nCurrentLine+1));
}

void PageResponse::handleTimerPress()
{
    if(bIsTop)
    {
        textUp();
    }
    else
    {
        textDown();
    }
    timerPress->start(200);
}

void PageResponse::handleTimerRelease()
{
    timerPress->stop();
}






