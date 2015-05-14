#-------------------------------------------------
#
# Project created by QtCreator 2015-03-23T14:30:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets svg

VERSION = 0.1.1

DEFINES += VERSION=\\\"$$VERSION\\\"

BUILD=$${BUILD}
TARGET = RingClientWindows
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11

contains(BUILD, Debug) {
    QMAKE_STRIP = echo
    CONFIG += console
}

SOURCES += main.cpp\
        mainwindow.cpp \
    callwidget.cpp \
    configurationwidget.cpp \
    navstack.cpp \
    navbar.cpp \
    mainbar.cpp \
    navwidget.cpp \
    accountdetails.cpp \
    minimalhistorybackend.cpp \
    aboutdialog.cpp \
    pivotviewwidget.cpp \
    pivotcontrol.cpp \
    videowidget.cpp \
    utils.cpp \
    wizarddialog.cpp

HEADERS  += mainwindow.h \
    callwidget.h \
    configurationwidget.h \
    navstack.h \
    navbar.h \
    mainbar.h \
    navwidget.h \
    accountdetails.h \
    minimalhistorybackend.h \
    aboutdialog.h \
    pivotviewwidget.h \
    pivotcontrol.h \
    videowidget.h \
    utils.h \
    wizarddialog.h

FORMS    += mainwindow.ui \
    callwidget.ui \
    configurationwidget.ui \
    navbar.ui \
    mainbar.ui \
    accountdetails.ui \
    aboutdialog.ui \
    pivotviewwidget.ui \
    wizarddialog.ui

win32: LIBS += -lole32 -luuid -lshlwapi

INCLUDEPATH += $${RING}/include/libringclient

LIBS += -L$${RING}/lib/ -lringclient

RESOURCES += \
    ressources.qrc

RC_FILE = ico.rc

DISTFILES += \
    License.rtf \
    ringtones/konga.ul \
    ring.nsi

win32 {

    RINGTONES.files = ringtones
    RINGTONES.path = $$OUT_PWD/release

    PACKAGING.files = ring.nsi images/ring.ico
    PACKAGING.path = $$OUT_PWD/release

    LICENSE.files = License.rtf
    LICENSE.path = $$OUT_PWD/release

    RUNTIMEDIR=/usr/i686-w64-mingw32/bin/

    RUNTIME.files = $${RING}/bin/libring.dll $${RING}/bin/libringclient.dll
    RUNTIME.path = $$OUT_PWD/release

    QTRUNTIME.files = $$RUNTIMEDIR/Qt5Core.dll $$RUNTIMEDIR/Qt5Widgets.dll \
                            $$RUNTIMEDIR/Qt5Gui.dll $$RUNTIMEDIR/Qt5Svg.dll
    QTRUNTIME.path = $$OUT_PWD/release

    QTDEPSRUNTIME.files = $$RUNTIMEDIR/zlib1.dll $$RUNTIMEDIR/iconv.dll \
                            $$RUNTIMEDIR/libfreetype-6.dll $$RUNTIMEDIR/libglib-2.0-0.dll \
                            $$RUNTIMEDIR/libharfbuzz-0.dll \
                            $$RUNTIMEDIR/libintl-8.dll $$RUNTIMEDIR/libpcre-1.dll \
                            $$RUNTIMEDIR/libpcre16-0.dll $$RUNTIMEDIR/libpng16-16.dll
    QTDEPSRUNTIME.path = $$OUT_PWD/release

    QTPLATFORMS.files = $$(QTDIR)/plugins/platforms/qwindows.dll
    QTPLATFORMS.path = $$OUT_PWD/release/platforms

    LIBSTD.files = $$RUNTIMEDIR/libgcc_s_sjlj-1.dll $$RUNTIMEDIR/libstdc++-6.dll \
                    $$RUNTIMEDIR/libwinpthread-1.dll
    LIBSTD.path = $$OUT_PWD/release

    INSTALLS += RINGTONES PACKAGING LICENSE RUNTIME QTRUNTIME QTDEPSRUNTIME \
                 QTPLATFORMS LIBSTD
}


