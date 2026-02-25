#include "pagefaq.h"

PageFaq::PageFaq(QWidget *parent) : Page(parent)
{
    this->setGeometry(parent->geometry());
    init();
}

void PageFaq::init()
{
    labelWindow = new QLabel(this);
    labelWindow->setGeometry(0,73,640,317);

    //===========

    labelTextBgTop = new QLabel(labelWindow);
    labelTextBgTop->setGeometry(40,-9,520,105);
    instance.pixLoad(labelTextBgTop,false,strDirPath,"/boxUnused.png");

    labelTextBgCenter = new QLabel(labelWindow);
    labelTextBgCenter->setGeometry(40,106,520,105);
    instance.pixLoad(labelTextBgCenter,false,strDirPath,"/boxUsed.png");

    labelTextBgDown = new QLabel(labelWindow);
    labelTextBgDown->setGeometry(40,221,520,105);
    instance.pixLoad(labelTextBgDown,false,strDirPath,"/boxUnused.png");

    //===========

    labelTextTop = new QLabel(labelWindow);
    labelTextTop->setGeometry(65,-9,470,105);
    labelTextTop->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);

    comText = new ComponentWidgetTextMove(labelWindow);
    comText->setGeometry(65,106,470,105);

    labelTextDown = new QLabel(labelWindow);
    labelTextDown->setGeometry(65,221,470,105);
    labelTextDown->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);

    //===========

    labelArrowTop = new QLabel(this);
    labelArrowTop->setGeometry(565,83,70,70);
    instance.pixLoad(labelArrowTop,false,strDirPath,"/arrowTop.png");

    labelArrowDown = new QLabel(this);
    labelArrowDown->setGeometry(565,310,70,70);
    instance.pixLoad(labelArrowDown,false,strDirPath,"/arrowDown.png");

    //===========

    labelButtonGradientTop = new QLabel(this);
    labelButtonGradientTop->setGeometry(40,73,520,96);
    instance.pixLoad(labelButtonGradientTop,false,strDirPath,"/gradientTop.png");

    labelButtonGradientDown = new QLabel(this);
    labelButtonGradientDown->setGeometry(40,294,520,96);
    instance.pixLoad(labelButtonGradientDown,false,strDirPath,"/gradientDown.png");

    //===========

    labelNumCurrent = new QLabel(this);
    labelNumCurrent->setFont(textResource.getFont(PAGE_HELP,"labelNumCurrent"));
    labelNumCurrent->setGeometry(565,160,70,70);
    labelNumCurrent->setStyleSheet("color: #000000;");
    labelNumCurrent->setAlignment(Qt::AlignCenter);

    labelNumBar = new QLabel(this);
    labelNumBar->setGeometry(575, 230, 50, 3);
    labelNumBar->setStyleSheet("background-color: #000000;");

    labelNumAll = new QLabel(this);
    labelNumAll->setFont(textResource.getFont(PAGE_HELP,"labelNumAll"));
    labelNumAll->setGeometry(565,233,70,70);
    labelNumAll->setStyleSheet("color: #000000;");
    labelNumAll->setAlignment(Qt::AlignCenter);

    customButtonBack = new CustomButtonBack(this);
    customButtonBack->setLongWidth(true);

    update();
}

void PageFaq::update()
{
    customButtonBack->update();

    updateTextSlots();

    labelTextTop->setFont(textResource.getFont(PAGE_FAQ,"labelText"));
    comText->setFont(textResource.getFont(PAGE_FAQ,"labelTextBold"));
    labelTextDown->setFont(textResource.getFont(PAGE_FAQ,"labelText"));
}

void PageFaq::pageShow()
{
    m_nSelectIndex = 0;
    int catIdx = instance.nSelectTextIndex;
    m_strList = textResource.getText(PAGE_FAQ, QString("labelTextFaq%1").arg(catIdx));
    m_nIndexRangeMax = m_strList.count();

    labelNumAll->setText(QString::number(m_nIndexRangeMax));

    update();
}

void PageFaq::pageHide()
{
    emit signalShowPageNum(PAGE_FAQ_INDEX);
}

void PageFaq::mousePressEvent(QMouseEvent *ev)
{
    if(instance.touchCheck(comText->geometry().translated(labelWindow->pos()),ev))
    {
        instance.setPageNumPrev(PAGE_FAQ);
        instance.nSelectTextIndexSub = m_nSelectIndex;
        emit signalShowPageNum(PAGE_FAQ_RESPONSE);
        return;
    }

    if(instance.touchCheck(customButtonBack->geometry(),ev))
    {
        pageHide();
    }

    if(instance.touchCheck(labelArrowTop->geometry(),ev) || instance.touchCheck(labelButtonGradientTop->geometry(),ev))
    {
        movePrev();
        return;
    }

    if(instance.touchCheck(labelArrowDown->geometry(),ev) || instance.touchCheck(labelButtonGradientDown->geometry(),ev))
    {
        moveNext();
        return;
    }
}

void PageFaq::updateTextSlots()
{
    int total = m_strList.size();
    if(total == 0) return;

    int indexPrev = (m_nSelectIndex - 1 + total) % total;
    int indexNext = (m_nSelectIndex + 1) % total;

    labelTextTop->setText(m_strList.at(indexPrev));

    labelNumCurrent->setText(QString::number(m_nSelectIndex+1));
    comText->setText(m_strList.at(m_nSelectIndex));

    /*
    QTimer::singleShot(1000, this, [this](){
        comText->startMove();
    });
    */

    labelTextDown->setText(m_strList.at(indexNext));
}

void PageFaq::moveNext()
{
    int total = m_strList.size();
    if(total == 0)
        return;

    m_nSelectIndex = (m_nSelectIndex +1) % total;
    updateTextSlots();
}

void PageFaq::movePrev()
{
    int total = m_strList.size();
    if(total == 0)
        return;

    m_nSelectIndex = (m_nSelectIndex -1 + total) % total;
    updateTextSlots();
}



















