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
    Button/custombuttoninput.cpp \
    Button/custombuttonmeasure.cpp \
    Button/custombuttonmeasurere.cpp \
    Button/custombuttonmeasurestart.cpp \
    Button/custombuttonok.cpp \
    Button/custombuttonsave.cpp \
    Button/custombuttonupgrade.cpp \
    Component/componentbattery.cpp \
    Component/componentbluetooth.cpp \
    Component/componentclock.cpp \
    Component/componenthome.cpp \
    Component/componentmeasureresult.cpp \
    Component/componentmenu.cpp \
    Component/componentspinner.cpp \
    Component/componentspinnerdate.cpp \
    Component/customcomponent.cpp \
    Loadfont.cpp \
    Page/page.cpp \
    Page/pagebatterypopup.cpp \
    Page/pagebooting.cpp \
    Page/pagecalicheck.cpp \
    Page/pagecaliconfirm.cpp \
    Page/pagecaligainconfirm.cpp \
    Page/pagecaligainresult.cpp \
    Page/pagecaliresult.cpp \
    Page/pagecaliresultmulti.cpp \
    Page/pagecaliselect.cpp \
    Page/pagecaliselectinfo.cpp \
    Page/pagecalivalue.cpp \
    Page/pagedatetime.cpp \
    Page/pagedebug.cpp \
    Page/pagedebugsys.cpp \
    Page/pagedebugusb.cpp \
    Page/pagedeviceinfo.cpp \
    Page/pagegarph.cpp \
    Page/pagehistory.cpp \
    Page/pagehistoryresult.cpp \
    Page/pagehome.cpp \
    Page/pageinit.cpp \
    Page/pageinitconfirm.cpp \
    Page/pagemenu.cpp \
    Page/pagepassword.cpp \
    Page/pagepasswordconfirm.cpp \
    Page/pageresult.cpp \
    Page/pageresultfail.cpp \
    Page/pagereverse.cpp \
    Page/pageselect.cpp \
    Page/pagesleep.cpp \
    Page/pagesound.cpp \
    Page/pagethreshold.cpp \
    Page/pagethresholdvalue.cpp \
    Page/pagetrans.cpp \
    Page/pageupgrade.cpp \
    Page/pageupgradeconfirm.cpp \
    Page/pageuserinfo.cpp \
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
    Button/custombuttoninput.h \
    Button/custombuttonmeasure.h \
    Button/custombuttonmeasurere.h \
    Button/custombuttonmeasurestart.h \
    Button/custombuttonok.h \
    Button/custombuttonsave.h \
    Button/custombuttonupgrade.h \
    Component/componentbattery.h \
    Component/componentbluetooth.h \
    Component/componentclock.h \
    Component/componenthome.h \
    Component/componentmeasureresult.h \
    Component/componentmenu.h \
    Component/componentspinner.h \
    Component/componentspinnerdate.h \
    Component/customcomponent.h \
    GlobalMain.h \
    Loadfont.h \
    Page/page.h \
    Page/pagebatterypopup.h \
    Page/pagebooting.h \
    Page/pagecalicheck.h \
    Page/pagecaliconfirm.h \
    Page/pagecaligainconfirm.h \
    Page/pagecaligainresult.h \
    Page/pagecaliresult.h \
    Page/pagecaliresultmulti.h \
    Page/pagecaliselect.h \
    Page/pagecaliselectinfo.h \
    Page/pagecalivalue.h \
    Page/pagedatetime.h \
    Page/pagedebug.h \
    Page/pagedebugsys.h \
    Page/pagedebugusb.h \
    Page/pagedeviceinfo.h \
    Page/pagegarph.h \
    Page/pagehistory.h \
    Page/pagehistoryresult.h \
    Page/pagehome.h \
    Page/pageinit.h \
    Page/pageinitconfirm.h \
    Page/pagemenu.h \
    Page/pagepassword.h \
    Page/pagepasswordconfirm.h \
    Page/pageresult.h \
    Page/pageresultfail.h \
    Page/pagereverse.h \
    Page/pageselect.h \
    Page/pagesleep.h \
    Page/pagesound.h \
    Page/pagethreshold.h \
    Page/pagethresholdvalue.h \
    Page/pagetrans.h \
    Page/pageupgrade.h \
    Page/pageupgradeconfirm.h \
    Page/pageuserinfo.h \
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
