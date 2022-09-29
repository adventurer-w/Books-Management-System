#-------------------------------------------------
#
# Project created by QtCreator 2022-07-21T21:49:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BMS
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


SOURCES += \
        main.cpp \
        mainwidget.cpp \
        mainwindow.cpp \
        querybookwidget.cpp \
        searchlineedit.cpp \
        stditemmodel.cpp \
        userprofilewidget.cpp \
        widget.cpp

HEADERS += \
        mainwidget.h \
        mainwindow.h \
        querybookwidget.h \
        searchlineedit.h \
        stditemmodel.h \
        userprofilewidget.h \
        widget.h

FORMS += \
    mainwidget.ui \
        mainwindow.ui \
    querybookwidget.ui \
    searchlineedit.ui \
    userprofilewidget.ui \
        widget.ui \

RESOURCES += \
    image.qrc \
    qss.qrc

DISTFILES += \
    qss/base.qss \
    qss/login/style-1.qss \
    qss/login/style-2.qss \
    qss/login/style-3.qss \
    qss/login/style-4.qss \
    qss/mainwindow/mainwindow.qss \
    qss/searchlineedit/le_btn.qss \
    qss/userprofilewidget/userprofile.qss


