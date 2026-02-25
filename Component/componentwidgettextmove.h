#ifndef COMPONENTWIDGETTEXTMOVE_H
#define COMPONENTWIDGETTEXTMOVE_H

#include <QWidget>
#include <QLabel>
#include <QPropertyAnimation>
#include <QTimer>

class ComponentWidgetTextMove : public QWidget
{
    Q_OBJECT

public:
    explicit ComponentWidgetTextMove(QWidget *parent = nullptr);

    void setText(const QString &text);
    void setFont(const QFont &font);
    void setSpeed(int nSpeedPxPerSec);
    void setStyleSheet(const QString &strStyleSheet);

public slots:
    void startMove();
    void stopMove();

protected:
    void resizeEvent(QResizeEvent *event) override;

private:
    void startFirstAnimation();
    void startLoopAnimation();
    void prepareStaticLayout();

private:
    QLabel *m_label;
    QPropertyAnimation *m_animation;

    int m_nSpeedPxPerSec = 140;
};

#endif // COMPONENTWIDGETTEXTMOVE_H
