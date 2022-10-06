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
        backend/Utils.cpp \
    main.cpp \
        view/MainWidget.cpp \
        view/UserProfileWidget.cpp \
        view/bookdetails.cpp \
        view/booklist.cpp \
        view/bookranking.cpp \
        view/mainwindow.cpp \
        view/modifyinfowidget.cpp \
        view/querybookwidget.cpp \
        view/searchlineedit.cpp \
        view/stditemmodel.cpp \
        view/widget.cpp \

HEADERS += \
        backend/Admin.h \
        backend/Book.h \
        backend/MD5.h \
        backend/Record.h \
        backend/Reserve.h \
        backend/User.h \
        backend/Utils.h \
        backend/all_head.h \
        backend/length.h \
        backend/myFileDB.h \
        view/GlobalSetting.h \
        view/MainWidget.h \
        view/UserProfileWidget.h \
        view/bookdetails.h \
        view/booklist.h \
        view/bookranking.h \
        view/mainwindow.h \
        view/modifyinfowidget.h \
        view/querybookwidget.h \
        view/searchlineedit.h \
        view/stditemmodel.h \
        view/widget.h \

FORMS += \
    view/bookdetails.ui \
    view/booklist.ui \
    view/bookranking.ui \
    view/mainwidget.ui \
    view/mainwindow.ui \
    view/modifyinfowidget.ui \
    view/querybookwidget.ui \
    view/searchlineedit.ui \
    view/userprofilewidget.ui \
    view/widget.ui \


RESOURCES += \
    image.qrc \
    qss.qrc \

DISTFILES += \
    backend/user.dat \
    qss/base.qss \
    qss/bookranking/bookranking.qss \
    qss/login/style-1.qss \
    qss/login/style-2.qss \
    qss/login/style-3.qss \
    qss/login/style-4.qss \
    qss/mainwindow/mainwindow.qss \
    qss/querybookwidget/querybook.qss \
    qss/searchlineedit/le_btn.qss \
    qss/userprofilewidget/userprofile.qss \
    user.dat


