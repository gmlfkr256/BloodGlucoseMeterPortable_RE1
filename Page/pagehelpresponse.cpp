#include "pagehelpresponse.h"

PageHelpResponse::PageHelpResponse(QWidget *parent) : Page(parent)
{
    this->setGeometry(parent->geometry());
    init();
}

void PageHelpResponse::init()
{
    labelText = new QLabel(this);
    labelText->setWordWrap(true);
    labelText->setGeometry(65,95,472,250);
    labelText->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    labelText->setContentsMargins(0,0,0,0);

    labelNumCurrent = new QLabel(this);
    labelNumCurrent->setGeometry(565,160,70,70);
    labelNumCurrent->setStyleSheet("color: #000000;");
    labelNumCurrent->setAlignment(Qt::AlignCenter);

    labelNumBar = new QLabel(this);
    labelNumBar->setGeometry(575,230,50,3);
    labelNumBar->setStyleSheet("background-color: #000000;");

    labelNumAll = new QLabel(this);
    labelNumAll->setGeometry(565,233,70,70);
    labelNumAll->setStyleSheet("color: #000000;");
    labelNumAll->setAlignment(Qt::AlignCenter);

    labelArrowTop = new QLabel(this);
    labelArrowTop->setGeometry(565,83,70,70);
    instance.pixLoad(labelArrowTop,false,strDirPath,"/arrowTop.png");

    labelArrowDown = new QLabel(this);
    labelArrowDown->setGeometry(565,310,70,70);
    instance.pixLoad(labelArrowDown,false,strDirPath,"/arrowDown.png");

    customButtonBack = new CustomButtonBack(this);
    customButtonBack->setLongWidth(true);
}

void PageHelpResponse::update()
{
    customButtonBack->update();

    if(m_strList.isEmpty())
        return;

    labelText->setText(m_strList.at(m_nCurrentIndex));
    labelNumCurrent->setText(QString::number(m_nCurrentIndex + 1));
    labelNumAll->setText(QString::number(m_nPageIndexMax));

    labelArrowTop->setVisible(m_nCurrentIndex > 0);
    labelArrowDown->setVisible(m_nCurrentIndex < m_nPageIndexMax - 1);

    bool showNum = m_nPageIndexMax > 1;
    labelNumCurrent->setVisible(showNum);
    labelNumBar->setVisible(showNum);
    labelNumAll->setVisible(showNum);
}

void PageHelpResponse::pageShow()
{
    m_nCurrentIndex = 0;
    m_strList.clear();

    labelText->setFont(textResource.getFont(PAGE_HELP_RESPONSE,"labelText"));
    labelNumCurrent->setFont(textResource.getFont(PAGE_HELP_RESPONSE,"labelNumCurrent"));
    labelNumAll->setFont(textResource.getFont(PAGE_HELP_RESPONSE,"labelNumAll"));

    int idx = instance.nSelectTextIndex;
    QString key = QString("labelTextHelp%1").arg(idx);
    m_strList = textResource.getText(PAGE_HELP_RESPONSE, key);

    if(m_strList.isEmpty())
    {
        pageHide();
        return;
    }

    m_nPageIndexMax = m_strList.size();
    update();
}

void PageHelpResponse::pageHide()
{
    instance.setPageNumPrev(PAGE_HELP_RESPONSE);
    emit signalShowPageNum(PAGE_HELP_INDEX);
}

void PageHelpResponse::mousePressEvent(QMouseEvent *ev)
{
    m_pressPos = ev->pos();
    m_bIsTouch = true;
    m_bIsDrag = false;

    if(instance.touchCheck(customButtonBack->geometry(),ev))
    {
        pageHide();
        return;
    }

    if(instance.touchCheck(labelArrowTop->geometry(),ev))
    {
        pagePrev();
        return;
    }

    if(instance.touchCheck(labelArrowDown->geometry(),ev))
    {
        pageNext();
        return;
    }
}

void PageHelpResponse::mouseReleaseEvent(QMouseEvent *ev)
{
    if(!m_bIsTouch)
        return;

    m_bIsTouch = false;

    QPoint releasePos = ev->pos();
    int dx = releasePos.x() - m_pressPos.x();
    int dy = releasePos.y() - m_pressPos.y();

    if(m_bIsDrag && qAbs(dy) > qAbs(dx))
    {
        if(dy < 0)
            pageNext();
        else
            pagePrev();
        return;
    }
}

void PageHelpResponse::mouseMoveEvent(QMouseEvent *ev)
{
    Q_UNUSED(ev);

    if(!m_bIsTouch)
        return;

    if((ev->pos() - m_pressPos).manhattanLength() > instance.DRAG_THRESHOLD)
        m_bIsDrag = true;
}

void PageHelpResponse::pageNext()
{
    if(m_nCurrentIndex + 1 >= m_nPageIndexMax)
        return;

    m_nCurrentIndex++;
    update();
}

void PageHelpResponse::pagePrev()
{
    if(m_nCurrentIndex <= 0)
        return;

    m_nCurrentIndex--;
    update();
}
