#ifndef PAGECALISELECTRE_H
#define PAGECALISELECTRE_H

#include "page.h"


class CustomBox : public QWidget
{
    Q_OBJECT
public:
    CustomBox(QWidget *parent) : QWidget(parent)
    {
        labelSelectButton = new QLabel(this);
        labelSelectButton->setGeometry(0,0,150,180);

        labelSelectText = new QLabel(this);

        labelSelectText->setGeometry(0,0,150,82);
        labelSelectText->setAlignment(Qt::AlignCenter);

        for(int i=0; i<3; i++)
        {
            labelSelectCheckBox[i] = new QLabel(this);
            labelSelectCheckBox[i]->setGeometry(29+(34*i),76,29,29);
        }

        labelSelectTextValue = new QLabel(this);
        labelSelectTextValue->setGeometry(0,120,150,45);
        labelSelectTextValue->setAlignment(Qt::AlignCenter);

        labelSelectBar = new QLabel(this);
        labelSelectBar->setGeometry(36,162,78,3);
    }

    QLabel *labelSelectButton;
    QLabel *labelSelectText;
    QLabel *labelSelectCheckBox[3];
    QLabel *labelSelectTextValue;
    QLabel *labelSelectBar;
};

class PageCaliSelectRe : public Page
{
    Q_OBJECT
public:
    PageCaliSelectRe(QWidget *parent);
    void mousePressEvent(QMouseEvent *ev) override;
    QString strDirPath = "/ImageCaliSelectRe";

    CustomBox *customBox[6];
    QLabel *labelSelectArrow[5];

    void update() override;
    void pageShow() override;
    void pageHide() override;
private:
    void init();

signals:

};

#endif // PAGECALISELECTRE_H
