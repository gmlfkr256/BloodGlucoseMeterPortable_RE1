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
    Button/custombuttonback.cpp \
    Button/custombuttoncancel.cpp \
    Button/custombuttonhome.cpp \
    Button/custombuttoninput.cpp \
    Button/custombuttonlanguage.cpp \
    Button/custombuttonmeasure.cpp \
    Button/custombuttonmeasurere.cpp \
    Button/custombuttonmeasurestart.cpp \
    Button/custombuttonno.cpp \
    Button/custombuttonok.cpp \
    Button/custombuttonsave.cpp \
    Button/custombuttonupgrade.cpp \
    Button/custombuttonyes.cpp \
    Component/componentbattery.cpp \
    Component/componentbluetooth.cpp \
    Component/componentclock.cpp \
    Component/componenthome.cpp \
    Component/componentmeasureresult.cpp \
    Component/componentmenu.cpp \
    Component/componentpasswordkeyboard.cpp \
    Component/componentspinner.cpp \
    Component/componentspinnerdate.cpp \
    Component/componentupgraderesult.cpp \
    Component/componentwidgettextmove.cpp \
    Component/customcomponent.cpp \
    Loadfont.cpp \
    Page/page.cpp \
    Page/pagebatterypopup.cpp \
    Page/pagebloodcheck.cpp \
    Page/pagebloodchecknotice.cpp \
    Page/pagebloodnoticepopup.cpp \
    Page/pagebooting.cpp \
    Page/pagecalicheck.cpp \
    Page/pagecaliconfirm.cpp \
    Page/pagecaligainconfirm.cpp \
    Page/pagecaligainresult.cpp \
    Page/pagecalinotice.cpp \
    Page/pagecaliresult.cpp \
    Page/pagecaliresultmulti.cpp \
    Page/pagecaliresultmulticonfirm.cpp \
    Page/pagecaliselect.cpp \
    Page/pagecaliselectconfirm.cpp \
    Page/pagecaliselectinfo.cpp \
    Page/pagecaliselectre.cpp \
    Page/pagecalivalue.cpp \
    Page/pagecalivaluenotice.cpp \
    Page/pagedatetime.cpp \
    Page/pagedebug.cpp \
    Page/pagedebugsys.cpp \
    Page/pagedebugusb.cpp \
    Page/pagedeviceinfo.cpp \
    Page/pageelapsednoticepopup.cpp \
    Page/pageerrorhelp.cpp \
    Page/pageerrorhelpindex.cpp \
    Page/pageerrorhelpre.cpp \
    Page/pageerrorhelpresponse.cpp \
    Page/pagefaq.cpp \
    Page/pagefaqindex.cpp \
    Page/pagefaqre.cpp \
    Page/pagefaqresponse.cpp \
    Page/pagegarph.cpp \
    Page/pagehelp.cpp \
    Page/pagehelpindex.cpp \
    Page/pagehelpre.cpp \
    Page/pagehelpresponse.cpp \
    Page/pagehistory.cpp \
    Page/pagehistoryresult.cpp \
    Page/pagehome.cpp \
    Page/pageinit.cpp \
    Page/pageinitconfirm.cpp \
    Page/pagemenu.cpp \
    Page/pagepassword.cpp \
    Page/pagepasswordallchat.cpp \
    Page/pagepasswordconfirm.cpp \
    Page/pageresponse.cpp \
    Page/pageresponsere.cpp \
    Page/pageresult.cpp \
    Page/pageresultfail.cpp \
    Page/pagereverse.cpp \
    Page/pageselect.cpp \
    Page/pageselectuser.cpp \
    Page/pagesleep.cpp \
    Page/pagesound.cpp \
    Page/pagethreshold.cpp \
    Page/pagethresholdvalue.cpp \
    Page/pagetrans.cpp \
    Page/pageupagradefail.cpp \
    Page/pageupgrade.cpp \
    Page/pageupgradeconfirm.cpp \
    Page/pageusercautions.cpp \
    Page/pageusercheck.cpp \
    Page/pageuserchecknotice.cpp \
    Page/pageuserfinger.cpp \
    Page/pageuserinfo.cpp \
    Page/pageusernotice.cpp \
    guiapi/guiapi.cpp \
    guiapi/vtipc.cpp \
    main.cpp \
    mainwindow.cpp \
    singleton.cpp \
    textresource.cpp

HEADERS += \
    Button/custombutton.h \
    Button/custombuttonback.h \
    Button/custombuttoncancel.h \
    Button/custombuttonhome.h \
    Button/custombuttoninput.h \
    Button/custombuttonlanguage.h \
    Button/custombuttonmeasure.h \
    Button/custombuttonmeasurere.h \
    Button/custombuttonmeasurestart.h \
    Button/custombuttonno.h \
    Button/custombuttonok.h \
    Button/custombuttonsave.h \
    Button/custombuttonupgrade.h \
    Button/custombuttonyes.h \
    Component/componentbattery.h \
    Component/componentbluetooth.h \
    Component/componentclock.h \
    Component/componenthome.h \
    Component/componentmeasureresult.h \
    Component/componentmenu.h \
    Component/componentpasswordkeyboard.h \
    Component/componentspinner.h \
    Component/componentspinnerdate.h \
    Component/componentupgraderesult.h \
    Component/componentwidgettextmove.h \
    Component/customcomponent.h \
    GlobalMain.h \
    Loadfont.h \
    Page/page.h \
    Page/pagebatterypopup.h \
    Page/pagebloodcheck.h \
    Page/pagebloodchecknotice.h \
    Page/pagebloodnoticepopup.h \
    Page/pagebooting.h \
    Page/pagecalicheck.h \
    Page/pagecaliconfirm.h \
    Page/pagecaligainconfirm.h \
    Page/pagecaligainresult.h \
    Page/pagecalinotice.h \
    Page/pagecaliresult.h \
    Page/pagecaliresultmulti.h \
    Page/pagecaliresultmulticonfirm.h \
    Page/pagecaliselect.h \
    Page/pagecaliselectconfirm.h \
    Page/pagecaliselectinfo.h \
    Page/pagecaliselectre.h \
    Page/pagecalivalue.h \
    Page/pagecalivaluenotice.h \
    Page/pagedatetime.h \
    Page/pagedebug.h \
    Page/pagedebugsys.h \
    Page/pagedebugusb.h \
    Page/pagedeviceinfo.h \
    Page/pageelapsednoticepopup.h \
    Page/pageerrorhelp.h \
    Page/pageerrorhelpindex.h \
    Page/pageerrorhelpre.h \
    Page/pageerrorhelpresponse.h \
    Page/pagefaq.h \
    Page/pagefaqindex.h \
    Page/pagefaqre.h \
    Page/pagefaqresponse.h \
    Page/pagegarph.h \
    Page/pagehelp.h \
    Page/pagehelpindex.h \
    Page/pagehelpre.h \
    Page/pagehelpresponse.h \
    Page/pagehistory.h \
    Page/pagehistoryresult.h \
    Page/pagehome.h \
    Page/pageinit.h \
    Page/pageinitconfirm.h \
    Page/pagemenu.h \
    Page/pagepassword.h \
    Page/pagepasswordallchat.h \
    Page/pagepasswordconfirm.h \
    Page/pageresponse.h \
    Page/pageresponsere.h \
    Page/pageresult.h \
    Page/pageresultfail.h \
    Page/pagereverse.h \
    Page/pageselect.h \
    Page/pageselectuser.h \
    Page/pagesleep.h \
    Page/pagesound.h \
    Page/pagethreshold.h \
    Page/pagethresholdvalue.h \
    Page/pagetrans.h \
    Page/pageupagradefail.h \
    Page/pageupgrade.h \
    Page/pageupgradeconfirm.h \
    Page/pageusercautions.h \
    Page/pageusercheck.h \
    Page/pageuserchecknotice.h \
    Page/pageuserfinger.h \
    Page/pageuserinfo.h \
    Page/pageusernotice.h \
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
