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
        backend/MD5.cpp \
        backend/Utils.cpp \
        main.cpp \
        mainwindow.cpp \
        widget.cpp

HEADERS += \
        backend/Admin.h \
        backend/Book.h \
        backend/BookClass.h \
        backend/Department.h \
        backend/MD5.h \
        backend/MyLog.h \
        backend/RankItem.h \
        backend/Record.h \
        backend/Reserve.h \
        backend/SingleBook.h \
        backend/User.h \
        backend/Utils.h \
        backend/all_head.h \
        backend/length.h \
        backend/myFileDB.h \
        mainwindow.h \
        widget.h

FORMS += \
        mainwindow.ui \
        widget.ui

RESOURCES += \
    image.qrc \
    qss.qrc


