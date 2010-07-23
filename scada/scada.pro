DEPENDPATH += . \
    mnemo
INCLUDEPATH += .
QT += sql \
    svg \
    network

# Input
HEADERS += mainform.h \
    mnemo.h \
    sparamdialog.h \
    about.h \
    history.h \
    alertviewdialog.h \
    apone.h \
    dlgapone.h \
    dlgapsetup.h
FORMS += mainform.ui \
    mnemo.ui \
    sparamdialog.ui \
    about.ui \
    history.ui \
    alertviewdialog.ui \
    apone.ui \
    dlgapone.ui \
    dlgapsetup.ui
SOURCES += main.cpp \
    mainform.cpp \
    mnemo.cpp \
    sparamdialog.cpp \
    history.cpp \
    alertviewdialog.cpp \
    apone.cpp \
    dlgapone.cpp \
    dlgapsetup.cpp
RESOURCES += mnemo/mnemo.qrc \
    ../../../lib/picture.qrc \
    ../../../pict/lib/valves.qrc \
    text.qrc
MOC_DIR = build
OBJECTS_DIR = build
UI_DIR = build
RCC_DIR = build
QMAKE_LIBDIR += ../../../lib
LIBS += -lrcada_client
INCLUDEPATH += ../../../lib/include
OTHER_FILES += text/alert.txt \
    text/trend \
    text/ap
win32:QTPLUGIN += qsvg
win32:CONFIG += static
PRE_TARGETDEPS += ../../../lib/librcada_client.a
