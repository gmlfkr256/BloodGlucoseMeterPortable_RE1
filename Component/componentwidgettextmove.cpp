#include "componentwidgettextmove.h"
#include <QFontMetrics>

ComponentWidgetTextMove::ComponentWidgetTextMove(QWidget *parent) : QWidget(parent)
{
    m_label = new QLabel(this);
    m_animation = nullptr;

    m_label->setWordWrap(false);
    m_label->setAlignment(Qt::AlignVCenter | Qt::AlignLeft);

    setMinimumHeight(89);
}

void ComponentWidgetTextMove::setText(const QString &text)
{
    if(m_animation)
    {
        m_animation->stop();
        m_animation->deleteLater();
        m_animation = nullptr;
    }

    m_label->setText(text);
    prepareStaticLayout();

    QTimer::singleShot(1000, this, [this](){
        startMove();
    });
}

void ComponentWidgetTextMove::prepareStaticLayout()
{
    if (m_label->text().isEmpty())
        return;

    QFontMetrics fm(m_label->font());
    int textWidth = fm.width(m_label->text()) + 4;
    int widgetHeight = height();

    m_label->resize(textWidth, widgetHeight);
    m_label->move(0,0);
}

void ComponentWidgetTextMove::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
}

void ComponentWidgetTextMove::startFirstAnimation()
{
    if (m_label->text().isEmpty())
        return;

    QFontMetrics fm(m_label->font());
    int textWidth = fm.width(m_label->text()) + 4;

    int widgetWidth  = width();
    int widgetHeight = height();

    m_label->resize(textWidth, widgetHeight);

    // 텍스트가 짧으면 애니메이션 불필요
    if (textWidth <= widgetWidth)
    {
        m_label->move(0, 0);
        return;
    }

    int startX = 0;
    int endX   = -textWidth;

    m_animation = new QPropertyAnimation(m_label, "pos", this);
    m_animation->setStartValue(QPoint(startX, 0));
    m_animation->setEndValue(QPoint(endX, 0));

    int distance   = startX - endX;
    int durationMs = (distance * 1000) / m_nSpeedPxPerSec;

    m_animation->setDuration(durationMs);

    connect(m_animation, &QPropertyAnimation::finished,
            this, &ComponentWidgetTextMove::startLoopAnimation);

    m_animation->start();
}

void ComponentWidgetTextMove::startLoopAnimation()
{
    if (m_animation)
    {
        m_animation->deleteLater();
        m_animation = nullptr;
    }

    if (m_label->text().isEmpty())
        return;

    QFontMetrics fm(m_label->font());
    int textWidth = fm.width(m_label->text()) + 4;

    int widgetWidth  = width();
    int widgetHeight = height();

    m_label->resize(textWidth, widgetHeight);

    int startX = widgetWidth;
    int endX   = -textWidth;

    m_animation = new QPropertyAnimation(m_label, "pos", this);
    m_animation->setStartValue(QPoint(startX, 0));
    m_animation->setEndValue(QPoint(endX, 0));

    int distance   = startX - endX;
    int durationMs = (distance * 1000) / m_nSpeedPxPerSec;

    m_animation->setDuration(durationMs);
    m_animation->setLoopCount(-1);

    m_animation->start();
}

void ComponentWidgetTextMove::setFont(const QFont &font)
{
    QWidget::setFont(font);
    m_label->setFont(font);

    //restartAnimation();
}

void ComponentWidgetTextMove::startMove()
{
    if(!m_animation)
    {
        startFirstAnimation();
        return;
    }

    if(m_animation && m_animation->state() != QAbstractAnimation::Running)
    {
        m_animation->start();
    }
}

void ComponentWidgetTextMove::stopMove()
{
    if(m_animation)
    {
        m_animation->stop();
        m_label->move(0,0);
    }
}

void ComponentWidgetTextMove::setSpeed(int nSpeedPxPerSec)
{
    if(nSpeedPxPerSec <= 0)
        return;

    m_nSpeedPxPerSec = nSpeedPxPerSec;
}

void ComponentWidgetTextMove::setStyleSheet(const QString &strStyleSheet)
{
    QWidget::setStyleSheet(strStyleSheet);
    m_label->setStyleSheet(strStyleSheet);
}


