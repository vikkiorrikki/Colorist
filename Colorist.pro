#-------------------------------------------------
#
# Project created by QtCreator 2016-02-22T15:07:32
#
#-------------------------------------------------

QT       += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Colorist
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    toolsbar.cpp \
    paintscene.cpp

HEADERS  += widget.h \
    toolsbar.h \
    paintscene.h

FORMS    += widget.ui

RESOURCES += \
    test.qrc

DISTFILES += \
    ../build-Colorist-Desktop_Qt_5_5_1_MinGW_32bit-Debug/debug/levels.xml
