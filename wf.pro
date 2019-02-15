#-------------------------------------------------
#
# Project created by QtCreator 2018-12-20T14:34:10
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = wf
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    run/run.cpp \
    _set.cpp \
    dlgcheck.cpp \
    dlgload.cpp \
    dlgsickinput.cpp \
    formdebug.cpp \
    formdebugsub1.cpp \
    formdebugsub2.cpp \
    formdebugsub3.cpp \
    formdebugsub4.cpp \
    formdebugsub5.cpp \
    formmain.cpp \
    formquery.cpp \
    formreport.cpp \
    formreportsub1.cpp \
    formsop.cpp \
    table.cpp \
    run/comm.cpp \
    run/send.cpp \
    run/sendthread.cpp \
    run/micro.cpp \
    run/microthread.cpp \
    run/pipe.cpp \
    run/pipethread.cpp \
    db/db.cpp \
    db/samplelist.cpp \
    _def.cpp \
    dlguser.cpp \
    formqc.cpp \
    formimagelib.cpp \
    formhelp.cpp \
    dlgset.cpp \
    dlgsetsub1.cpp \
    dlgsetsub2.cpp


HEADERS += \
        mainwindow.h \
    run/run.h \
    _set.h \
    dlgcheck.h \
    dlgload.h \
    dlgsickinput.h \
    formdebug.h \
    formdebugsub1.h \
    formdebugsub2.h \
    formdebugsub3.h \
    formdebugsub4.h \
    formdebugsub5.h \
    formmain.h \
    formquery.h \
    formreport.h \
    formreportsub1.h \
    formsop.h \
    table.h \
    wf_db.h \
    wf_run.h \
    wf_set.h \
    run/comm.h \
    run/send.h \
    run/sendthread.h \
    run/micro.h \
    run/microthread.h \
    run/pipe.h \
    run/pipethread.h \
    db/db.h \
    db/samplelist.h \
    _def.h \
    dlguser.h \
    formqc.h \
    formimagelib.h \
    formhelp.h \
    dlgset.h \
    dlgsetsub1.h \
    dlgsetsub2.h


FORMS += \
        mainwindow.ui \
    formquery.ui \
    formreport.ui \
    formmain.ui \
    formdebug.ui \
    formsop.ui \
    formreportsub1.ui \
    formdebugsub1.ui \
    formdebugsub2.ui \
    formdebugsub3.ui \
    formdebugsub4.ui \
    formdebugsub5.ui \
    formhelp.ui \
    formimagelib.ui \
    formqc.ui \
    dlgcheck.ui \
    dlgload.ui \
    dlgsickinput.ui \
    dlgset.ui \
    dlgsetsub1.ui \
    dlgsetsub2.ui \
    dlguser.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc

LIBS += $$PWD/libwf_run.a

DISTFILES += \
    icon/bk_black.jpg \
    icon/bk_blue.jpg \
    icon/bk_blue2.jpg \
    icon/bk_blue3.jpg \
    icon/bk_border.jpg \
    icon/bk_sea.jpg \
    icon/bk_sea2.jpg \
    icon/bk_sky.jpg \
    icon/bk_sky2.jpg \
    icon/bk_snow.jpg \
    icon/bk_star.jpg \
    icon/bk_star2.jpg \
    icon/bk_star3.jpg \
    icon/bk_tree.jpg \
    icon/bk_tree2.jpg \
    icon/bkimg.jpg \
    icon/main_back.jpg \
    icon/sample_chemic.jpg \
    icon/sample_micro.jpg \
    icon/sample_micros.jpg \
    icon/sample_state.jpg \
    icon/timg.jpg \
    icon/timg1.jpg \
    icon/v.jpg \
    icon/vv.jpg \
    icon/x.jpg \
    icon/aaaa.png \
    icon/batchprt.png \
    icon/bbb.icon.png \
    icon/book.png \
    icon/bookcolor.png \
    icon/butclose.png \
    icon/butclose_copy.png \
    icon/butmin.png \
    icon/ccd.png \
    icon/closecolor.png \
    icon/debug.png \
    icon/debugcolor.png \
    icon/help.png \
    icon/help2.png \
    icon/micro.png \
    icon/myback.png \
    icon/mypause.png \
    icon/myquery.png \
    icon/myreport.png \
    icon/myselect.png \
    icon/mystart.png \
    icon/mystop.png \
    icon/print2.png \
    icon/qc.png \
    icon/query.png \
    icon/querycolor.png \
    icon/report.png \
    icon/reportcolor.png \
    icon/return.png \
    icon/run.png \
    icon/sample.png \
    icon/sample_micro.png \
    icon/save.png \
    icon/save2.png \
    icon/save3.png \
    icon/select.png \
    icon/selectcolor.png \
    icon/set.png \
    icon/setcolor.png \
    icon/shutcolor.png \
    icon/shutdown.png \
    icon/sick.png \
    icon/sick3.png \
    icon/startcolor.png \
    icon/t.png \
    icon/ta.png \
    icon/tb.png \
    icon/tc.png \
    icon/td.png \
    icon/te.png \
    icon/tf.png \
    icon/tg.png \
    icon/th.png \
    icon/ti.png \
    icon/tj.png \
    icon/tk.png \
    icon/tl.png \
    icon/tm.png \
    icon/tn.png \
    icon/to.png \
    icon/tp.png \
    icon/up.png \
    icon/up2.png \
    icon/usercolor.png \
    icon/whpm.png \
    icon/ps/bkimg.psd \
    icon/batchprt.psd \
    icon/book.psd \
    icon/bookcolor.psd \
    icon/butclose.psd \
    icon/butmin.psd \
    icon/ccd.psd \
    icon/closecolor.psd \
    icon/debug.psd \
    icon/debugcolor.psd \
    icon/help.psd \
    icon/help2.psd \
    icon/micro.psd \
    icon/myback.psd \
    icon/mypause.psd \
    icon/myquery.psd \
    icon/myreport.psd \
    icon/myselect.psd \
    icon/mystart.psd \
    icon/mystop.psd \
    icon/print2.psd \
    icon/qc.psd \
    icon/query.psd \
    icon/querycolor.psd \
    icon/report.psd \
    icon/reportcolor.psd \
    icon/return.psd \
    icon/run.psd \
    icon/save.psd \
    icon/save2.psd \
    icon/save3.psd \
    icon/select.psd \
    icon/selectcolor.psd \
    icon/set.psd \
    icon/setcolor.psd \
    icon/shutcolor.psd \
    icon/shutdown.psd \
    icon/sick.psd \
    icon/sick2.psd \
    icon/sick3.psd \
    icon/startcolor.psd \
    icon/t.psd \
    icon/up2.psd \
    icon/usercolor.psd \
    icon/whpm.psd \
    icon/OWNERS \
    icon/checkbox_active.icon \
    icon/checkbox_normal.icon \
    icon/close.icon \
    icon/ic_close.icon \
    icon/info.icon \
    icon/launch.icon \
    icon/menu_check.icon \
    icon/menu_radio_empty.icon \
    icon/menu_radio_selected.icon \
    icon/new_incognito_window.icon \
    icon/new_tab.icon \
    icon/new_window.icon \
    icon/open.icon \
    icon/options.icon \
    icon/pin.icon \
    icon/radio_button_active.icon \
    icon/radio_button_normal.icon \
    icon/submenu_arrow.icon \
    icon/uninstall.icon \
    icon/unpin.icon


TRANSLATIONS += wf_cn.ts \
    wf_en.ts
