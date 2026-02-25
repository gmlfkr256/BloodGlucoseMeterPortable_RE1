#include "pagehelpre.h"

PageHelpRe::PageHelpRe(QWidget *parent) : Page(parent)
{
    this->setGeometry(parent->geometry());

    init();
}

void PageHelpRe::init()
{
    for(int i=0; i<4; i++)
    {
        labelText[i] = new QLabel(this);
        labelText[i]->setAlignment(Qt::AlignCenter);
        labelText[i]->setWordWrap(true);
        labelText[i]->setContentsMargins(5,5,5,5);
        labelText[i]->setStyleSheet("border: 5px solid #077bdd; border-radius: 20px;");
    }

    labelText[0]->setGeometry(70,83,245,180);
    labelText[1]->setGeometry(325,83,245,180);
    labelText[2]->setGeometry(70,273,245,180);
    labelText[3]->setGeometry(325,273,245,180);

    labelArrowLeft = new QLabel(this);
    labelArrowLeft->setGeometry(0,175,70,200);
    instance.pixLoad(labelArrowLeft,false,strDirPath,"/arrowLeft.png");
    labelArrowRight = new QLabel(this);
    labelArrowRight->setGeometry(570,175,70,200);
    instance.pixLoad(labelArrowRight,false,strDirPath,"/arrowRight.png");
}

void PageHelpRe::update()
{
    for(int i=0; i<4; i++)
    {
        int dataIndex = m_nPageIndex * 4 + i;

        labelText[i]->setFont(textResource.getFont(PAGE_HELP,"labelTextBold"));

        if(dataIndex <  m_strList.size())
        {
            labelText[i]->setText(m_strList.at(dataIndex));
            labelText[i]->setVisible(true);
        }
        else
        {
            labelText[i]->setText("");
            labelText[i]->setVisible(false);
        }
    }
}

void PageHelpRe::pageShow()
{
    m_strList = textResource.getText(PAGE_HELP,"labelText");
    m_nPageIndex = instance.nSelectTextIndex/4;
    m_nPageIndexMax = (m_strList.count()-1)/4;

    labelArrowLeft->setVisible(m_nPageIndexMax > 0);
    labelArrowRight->setVisible(m_nPageIndexMax > 0);

    update();
}

void PageHelpRe::pageHide()
{

}

void PageHelpRe::mousePressEvent(QMouseEvent *ev)
{
    m_pressPos = ev->pos();
    m_bIsTouch = true;
    m_bIsDrag = false;

    if(instance.touchCheck(labelArrowLeft->geometry(),ev))
    {
        pagePrev();
    }

    if(instance.touchCheck(labelArrowRight->geometry(),ev))
    {
        pageNext();
    }
}

void PageHelpRe::mouseReleaseEvent(QMouseEvent *ev)
{
    if (!m_bIsTouch)
        return;

    m_bIsTouch = false;

    QPoint releasePos = ev->pos();
    int dx = releasePos.x() - m_pressPos.x();
    int dy = releasePos.y() - m_pressPos.y();

    if (m_bIsDrag && qAbs(dx) > qAbs(dy))
    {
        if (dx > 0)
            pagePrev();
        else
            pageNext();
        return;
    }

    if (m_bIsDrag)
        return;

    for (int i = 0; i < 4; i++)
    {
        if (labelText[i]->isVisible() && instance.touchCheck(labelText[i]->geometry(), ev))
        {
            instance.setPageNumPrev(PAGE_HELP_RE);
            instance.nSelectTextIndex = m_nPageIndex*4 + i;
            emit signalShowPageNum(PAGE_RESPONSE_RE);
            return;
        }
    }
}

void PageHelpRe::mouseMoveEvent(QMouseEvent *ev)
{
    Q_UNUSED(ev);

    if(!m_bIsTouch)
        return;

    if((ev->pos() - m_pressPos).manhattanLength() > instance.DRAG_THRESHOLD)
        m_bIsDrag = true;
}

void PageHelpRe::pagePrev()
{
    /*
    if(m_nPageIndex <= 0)
        return;
    m_nPageIndex--;
    */

    if(m_nPageIndexMax <= 0)
        return;

    if(m_nPageIndex <= 0)
        m_nPageIndex = m_nPageIndexMax;
    else
        m_nPageIndex--;

    update();
}

void PageHelpRe::pageNext()
{
    /*
    if(m_nPageIndex >= m_nPageIndexMax)
        return;

    m_nPageIndex++;
    */

    if(m_nPageIndexMax <= 0)
        return;

    if(m_nPageIndex >= m_nPageIndexMax)
        m_nPageIndex = 0;
    else
        m_nPageIndex++;

    update();
}
