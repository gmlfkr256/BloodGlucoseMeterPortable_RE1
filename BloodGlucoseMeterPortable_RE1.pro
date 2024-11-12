QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Blood_glucose_meter_portable

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Button/custombutton.cpp \
    Button/custombuttoncancel.cpp \
    Button/custombuttonhome.cpp \
    Button/custombuttonmeasurestart.cpp \
    Button/custombuttonok.cpp \
    Component/componentbattery.cpp \
    Component/componentbluetooth.cpp \
    Component/componentclock.cpp \
    Component/componenthome.cpp \
    Component/componentmenu.cpp \
    Component/customcomponent.cpp \
    Loadfont.cpp \
    Page/page.cpp \
    Page/pagebooting.cpp \
    Page/pagehome.cpp \
    Page/pagepassword.cpp \
    Page/pagepasswordconfirm.cpp \
    Page/pageselect.cpp \
    guiapi/guiapi.cpp \
    guiapi/vtipc.cpp \
    main.cpp \
    mainwindow.cpp \
    singleton.cpp \
    textresource.cpp

HEADERS += \
    Button/custombutton.h \
    Button/custombuttoncancel.h \
    Button/custombuttonhome.h \
    Button/custombuttonmeasurestart.h \
    Button/custombuttonok.h \
    Component/componentbattery.h \
    Component/componentbluetooth.h \
    Component/componentclock.h \
    Component/componenthome.h \
    Component/componentmenu.h \
    Component/customcomponent.h \
    GlobalMain.h \
    Loadfont.h \
    Page/page.h \
    Page/pagebooting.h \
    Page/pagehome.h \
    Page/pagepassword.h \
    Page/pagepasswordconfirm.h \
    Page/pageselect.h \
    guiapi/gapi.h \
    guiapi/guiapi.h \
    guiapi/vtipc.h \
    mainwindow.h \
    singleton.h \
    textresource.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
