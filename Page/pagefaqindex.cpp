#include "pagefaqindex.h"

PageFaqIndex::PageFaqIndex(QWidget *parent) : Page(parent)
{
    this->setGeometry(parent->geometry());

    init();
}

void PageFaqIndex::init()
{
    for(int i=0; i<4; i++)
    {
        labelText[i] = new QLabel(this);
        labelText[i]->setAlignment(Qt::AlignCenter);
        labelText[i]->setWordWrap(true);
        labelText[i]->setContentsMargins(5,5,5,5);
        labelText[i]->setStyleSheet("border: 5px solid #077bdd; border-radius: 20px;");
    }

    labelText[0]->setGeometry(85,89,230,135);
    labelText[1]->setGeometry(331,89,230,135);
    labelText[2]->setGeometry(85,239,230,135);
    labelText[3]->setGeometry(331,239,230,135);

    labelArrowLeft = new QLabel(this);
    labelArrowLeft->setGeometry(0,132,70,200);
    instance.pixLoad(labelArrowLeft,false,strDirPath,"/arrowLeft.png");
    labelArrowRight = new QLabel(this);
    labelArrowRight->setGeometry(570,132,70,200);
    instance.pixLoad(labelArrowRight,false,strDirPath,"/arrowRight.png");

    customButtonBack = new CustomButtonBack(this);
    customButtonBack->setLongWidth(true);
}

void PageFaqIndex::update()
{
    customButtonBack->update();

    for(int i=0; i<4; i++)
    {
        int dataIndex = m_nPageIndex * 4 + i;

        labelText[i]->setFont(textResource.getFont(PAGE_FAQ_INDEX,"labelText"));

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

void PageFaqIndex::pageShow()
{
    m_strList = textResource.getText(PAGE_FAQ_INDEX,"labelText");
    m_nPageIndex = 0;
    m_nPageIndexMax = (m_strList.count()-1)/4;

    labelArrowLeft->setVisible(m_nPageIndexMax > 0);
    labelArrowRight->setVisible(m_nPageIndexMax > 0);

    update();
}

void PageFaqIndex::pageHide()
{
    emit signalShowPageNum(PAGE_MENU);
}

void PageFaqIndex::mousePressEvent(QMouseEvent *ev)
{
    m_pressPos = ev->pos();
    m_bIsTouch = true;
    m_bIsDrag = false;

    if(instance.touchCheck(customButtonBack->geometry(),ev))
    {
        pageHide();
        return;
    }

    if(instance.touchCheck(labelArrowLeft->geometry(),ev))
    {
        pagePrev();
    }

    if(instance.touchCheck(labelArrowRight->geometry(),ev))
    {
        pageNext();
    }
}

void PageFaqIndex::mouseReleaseEvent(QMouseEvent *ev)
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
            instance.setPageNumPrev(PAGE_FAQ_INDEX);
            instance.nSelectTextIndex = m_nPageIndex*4 + i;
            emit signalShowPageNum(PAGE_FAQ);
            return;
        }
    }
}

void PageFaqIndex::mouseMoveEvent(QMouseEvent *ev)
{
    Q_UNUSED(ev);

    if(!m_bIsTouch)
        return;

    if((ev->pos() - m_pressPos).manhattanLength() > instance.DRAG_THRESHOLD)
        m_bIsDrag = true;
}

void PageFaqIndex::pagePrev()
{
    if(m_nPageIndexMax <= 0)
        return;

    if(m_nPageIndex <= 0)
        m_nPageIndex = m_nPageIndexMax;
    else
        m_nPageIndex--;

    update();
}

void PageFaqIndex::pageNext()
{
    if(m_nPageIndexMax <= 0)
        return;

    if(m_nPageIndex >= m_nPageIndexMax)
        m_nPageIndex = 0;
    else
        m_nPageIndex++;

    update();
}
