#include "pageresponsere.h"

PageResponseRe::PageResponseRe(QWidget *parent) : Page(parent)
{
    this->setGeometry(parent->geometry());
    init();
}

void PageResponseRe::init()
{
    labelText = new QLabel(this);
    labelText->setWordWrap(true);
    labelText->setGeometry(83,115,472,215);
    labelText->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    //labelText->setContentsMargins(5,5,5,5);
    labelText->setContentsMargins(0,0,0,0);

    labelPageNum = new QLabel(this);
    labelPageNum->setGeometry(83,330,472,60);
    labelPageNum->setAlignment(Qt::AlignCenter);

    labelArrowLeft = new QLabel(this);
    labelArrowLeft->setGeometry(0,132,70,200);
    instance.pixLoad(labelArrowLeft,false,strDirPath,"/arrowLeft.png");
    labelArrowRight = new QLabel(this);
    labelArrowRight->setGeometry(570,132,70,200);
    instance.pixLoad(labelArrowRight,false,strDirPath,"/arrowRight.png");

    customButtonBack = new CustomButtonBack(this);
    customButtonBack->setLongWidth(true);
}

void PageResponseRe::update()
{
    customButtonBack->update();

    labelText->setText(m_strList.at(m_nCurrentIndex));
    labelPageNum->setText(QString("%1 / %2").arg(m_nCurrentIndex + 1).arg(m_nPageIndexMax));

    if (m_nPageIndexMax > 1)
    {
        labelArrowLeft->setVisible(m_nCurrentIndex > 0);
        labelArrowRight->setVisible(m_nCurrentIndex < m_nPageIndexMax - 1);
    }
}

void PageResponseRe::pageShow()
{
    m_nCurrentIndex = 0;
    m_strList = QStringList();
    labelText->setFont(textResource.getFont(PAGE_RESPONSE,"labelText"));

    QString str;
    QString strPage = "";

    switch (instance.getPageNumPrev())
    {
    case PAGE_HELP_RE:
        strPage = "labelTextHelp";
        break;
    case PAGE_FAQ_RE:
        strPage = "labelTextFaq";
        break;
    case PAGE_ERROR_HELP_RE:
        strPage = "labelTextErrorHelp";
        break;
    default:
        qDebug()<<"PageResonseRe switch default;";
        pageHide();
        break;
    }

    str = textResource.getText(PAGE_RESPONSE,strPage).at(instance.nSelectTextIndex);

    if(str.contains("@"))
    {
        m_strList = str.split("@",QString::SkipEmptyParts);
    }
    else
    {
        m_strList.append(str);
    }

    m_nPageIndexMax = m_strList.size();

    if (m_nPageIndexMax == 1)
    {
        labelArrowLeft->setVisible(false);
        labelArrowRight->setVisible(false);
        labelPageNum->setVisible(false);
    }
    else
    {
        labelPageNum->setVisible(true);
    }

    labelPageNum->setFont(textResource.getFont(PAGE_RESPONSE,"labelPageNum"));

    update();
}

void PageResponseRe::pageHide()
{
    emit signalShowPageNum(instance.getPageNumPrev());
}

void PageResponseRe::mousePressEvent(QMouseEvent *ev)
{
    m_pressPos = ev->pos();
    m_bIsTouch = true;
    m_bIsDrag = false;

    if(instance.touchCheck(customButtonBack->geometry(),ev))
    {
        pageHide();
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

void PageResponseRe::mouseReleaseEvent(QMouseEvent *ev)
{
    if (!m_bIsTouch)
        return;

    m_bIsTouch = false;

    QPoint releasePos = ev->pos();
    int dx = releasePos.x() - m_pressPos.x();
    int dy = releasePos.y() - m_pressPos.y();

    // ① 드래그 → 페이지 이동
    if (m_bIsDrag && qAbs(dx) > qAbs(dy))
    {
        if (dx > 0)
            pagePrev();
        else
            pageNext();
        return;
    }
}

void PageResponseRe::mouseMoveEvent(QMouseEvent *ev)
{
    Q_UNUSED(ev);

    if(!m_bIsTouch)
        return;

    if((ev->pos() - m_pressPos).manhattanLength() > instance.DRAG_THRESHOLD)
        m_bIsDrag = true;
}

void PageResponseRe::pageNext()
{
    if (m_nCurrentIndex + 1 >= m_nPageIndexMax)
        return;

    m_nCurrentIndex++;
    update();
}

void PageResponseRe::pagePrev()
{
    if (m_nCurrentIndex <= 0)
        return;

    m_nCurrentIndex--;
    update();
}




