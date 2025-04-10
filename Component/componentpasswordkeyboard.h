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
        mapKey[0] = QStringList({"1", "2", "3", "4", "5", "6", "7", "8", "9","0"});

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

typedef enum
{
    KEY_FUNC_NORMAL = 0,
    KEY_FUNC_TOP,
    KEY_FUNC_RIGHT,
    KEY_FUNC_MAX
} KeyboradType;

class ComponentPasswordKeyboard : public CustomComponent
{
    Q_OBJECT
public:
    ComponentPasswordKeyboard(QWidget *parent);
    void mousePressEvent(QMouseEvent *ev) override;
    void mouseReleaseEvent(QMouseEvent *ev) override;

    QString strDirPath = "/ImageComPasswordKeyBoard";

    QLabel *labelFunction[5];
    QLabel *labelButton[10];
    QLabel *labelButtonDel;
    QLabel *labelButtonDelImg;
    QLabel *labelButtonCancel;
    QLabel *labelButtonCancelImg;
    QLabel *labelButtonOK;
    QLabel *labelButtonOKImg;
    KeyBoardIndex *keyBoardIndex;
    int nFunctionNum = 0;
    QString strKey = "";
    bool bIsShowAll = false;
    int nLabelIndex = -1;

    void clearKey();

    void update() override;
    void pageShow() override;
    void pageHide() override;
public slots:
    void deleteLastKey();
    void functionShowHide();
private:
    void init();
    QString getDisplayText();
    void setFunctionNumBytButton(int nIndex);
    void processOK();
    bool bIsPasswordValid(const QString strKey);
    QString bIsKeyPress(bool bIsPress = false, KeyboradType keyType = KEY_FUNC_MAX);
signals:
    void signalKeyClick(QString strKey);
    void signalCheckLogin();
    void signalCancel();
    void signalUpdateShowHide(bool);
};

#endif // COMPONENTPASSWORDKEYBOARD_H
