#ifndef COMPONENTPASSWORDKEYBOARD_H
#define COMPONENTPASSWORDKEYBOARD_H

#include "customcomponent.h"
#include <QMap>

class KeyBoardIndex : public QObject
{
    Q_OBJECT
public:
    QMap<int, QStringList> mapKey;

    KeyBoardIndex(QObject *parent): QObject(parent) {
        // 0: 숫자 0~9
        mapKey[0] = QStringList({"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"});

        // 1~3: 대문자 A-Z (26자 → 3그룹: 10 + 10 + 6)
        mapKey[1] = QStringList({"A", "B", "C", "D", "E", "F", "G", "H", "I", "J"});
        mapKey[2] = QStringList({"K", "L", "M", "N", "O", "P", "Q", "R", "S", "T"});
        mapKey[3] = QStringList({"U", "V", "W", "X", "Y", "Z", "", "", "", ""}); // 빈 문자열로 10개 맞춤

        // 4~6: 소문자 a-z (26자 → 3그룹: 10 + 10 + 6)
        mapKey[4] = QStringList({"a", "b", "c", "d", "e", "f", "g", "h", "i", "j"});
        mapKey[5] = QStringList({"k", "l", "m", "n", "o", "p", "q", "r", "s", "t"});
        mapKey[6] = QStringList({"u", "v", "w", "x", "y", "z", "", "", "", ""}); // 빈 문자열로 10개 맞춤

        // 7~9: 특수문자 (30자 → 3그룹: 10 + 10 + 10)
        mapKey[7] = QStringList({"!", "@", "#", "$", "%", "^", "&", "*", "(", ")"});
        mapKey[8] = QStringList({"-", "_", "=", "+", "{", "}", "[", "]", "|", "\\"});
        mapKey[9] = QStringList({":", ";", "\"", "'", "<", ">", ",", ".", "?", "/"});
    }
};

class ComponentPasswordKeyboard : public CustomComponent
{
    Q_OBJECT
public:
    ComponentPasswordKeyboard(QWidget *parent);
    void mousePressEvent(QMouseEvent *ev) override;
    void mouseReleaseEvent(QMouseEvent *ev) override;

    QString strDirPath = "/ImageComponentPasswordKeyBoard";

    QLabel *labelFunction[5];
    QLabel *labelButton[10];
    KeyBoardIndex *keyBoardIndex;
    int nFunctionNum = 0;
    QString strKey = "";

    void update() override;
    void pageShow() override;
    void pageHide() override;
public slots:
    void deleteLastKey();
private:
    void init();
signals:
    void signalKeyClick(QString strKey);

};

#endif // COMPONENTPASSWORDKEYBOARD_H
