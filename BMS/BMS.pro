#-------------------------------------------------
#
# Project created by QtCreator 2022-07-21T21:49:39
#
#-------------------------------------------------

QT       += core gui
QT += core gui axcontainer
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
UI_DIR=./UI
LIBS += -lWs2_32
SOURCES += \
        backend/MD5.cpp \
        backend/Utils.cpp \
    backend/addBooks.cpp \
        backend/addUsers.cpp \
    backend/myFileDB.cpp \
    view/adminbookmanagement.cpp \
    view/admininfo.cpp \
    view/adminmodifybookdetail.cpp \
        view/booklist.cpp \
        main.cpp \
        view/MainWidget.cpp \
        view/UserProfileWidget.cpp \
        view/bookdetails.cpp \
        view/bookranking.cpp \
    view/borrowinstruction.cpp \
    view/borrowrecord.cpp \
        view/mainwindow.cpp \
    view/modifybookcategory.cpp \
        view/modifyinfowidget.cpp \
        view/querybookwidget.cpp \
        view/register.cpp \
        view/searchlineedit.cpp \
        view/smtp.cpp \
        view/stditemmodel.cpp \
        view/widget.cpp \

HEADERS += \
        backend/Admin.h \
        backend/Book.h \
    backend/Department.h \
        backend/MD5.h \
    backend/RankItem.h \
        backend/Record.h \
        backend/Reserve.h \
    backend/SingleBook.h \
        backend/User.h \
        backend/Utils.h \
        backend/addBooks.h \
        backend/addUsers.h \
        backend/all_head.h \
        backend/length.h \
        backend/myFileDB.h \
    view/adminbookmanagement.h \
    view/admininfo.h \
    view/adminmodifybookdetail.h \
        view/booklist.h \
        view/GlobalSetting.h \
        view/MainWidget.h \
        view/UserProfileWidget.h \
        view/bookdetails.h \
        view/bookranking.h \
    view/borrowinstruction.h \
    view/borrowrecord.h \
        view/mainwindow.h \
    view/modifybookcategory.h \
        view/modifyinfowidget.h \
        view/querybookwidget.h \
    view/register.h \
        view/searchlineedit.h \
        view/smtp.h \
        view/stditemmodel.h \
        view/widget.h \

FORMS += \
    view/adminbookmanagement.ui \
    view/admininfo.ui \
    view/adminmodifybookdetail.ui \
    view/booklist.ui \
    view/bookdetails.ui \
    view/bookranking.ui \
    view/borrowinstruction.ui \
    view/borrowrecord.ui \
    view/mainwidget.ui \
    view/mainwindow.ui \
    view/modifybookcategory.ui \
    view/modifyinfowidget.ui \
    view/querybookwidget.ui \
    view/register.ui \
    view/searchlineedit.ui \
    view/userprofilewidget.ui \
    view/widget.ui \


RESOURCES += \
    image.qrc \
    qss.qrc \

DISTFILES += \
    backend/book.dat \
    backend/book_rank.dat \
    backend/boy_rank.dat \
    backend/girl_rank.dat \
    backend/point_rank.dat \
    backend/record.dat \
    backend/user.dat \
    image/SearchLineEdit/search.png \
    image/SearchLineEdit/search2.png \
    image/UserProfile/background.jpg \
    image/index/arrow_up.png \
    image/index/book_manage.png \
    image/index/book_reserve.png \
    image/index/i_no_content.png \
    image/index/i_search_no_result.png \
    image/index/like.png \
    image/index/like_selected.png \
    image/index/list.png \
    image/index/load.png \
    image/index/login.png \
    image/index/logout.png \
    image/index/logout2.png \
    image/index/search.png \
    image/index/store_like.png \
    image/mainwindow/background.jpg \
    image/mainwindow/background.png \
    image/mainwindow/background2.png \
    image/mainwindow/background_userProfile.jpg \
    image/mainwindow/credit.png \
    image/mainwindow/library.png \
    image/mainwindow/logout.png \
    image/mainwindow/lookup.png \
    image/mainwindow/major.png \
    image/mainwindow/modify.png \
    image/mainwindow/number.png \
    image/mainwindow/setting.png \
    image/mainwindow/user.png \
    image/mainwindow/username.png \
    image/mainwindow/userprofile.png \
    image/modifyinfo/background.jpg \
    image/pic/1.png \
    image/pic/2.png \
    image/pic/3.png \
    image/pic/4.png \
    image/pic/background-1.png \
    image/pic/background-2.png \
    image/pic/background-3.png \
    image/pic/background-4.png \
    image/pic/personal_head.png \
    image/pic/personal_homepage.jpg \
    image/pic/pwd.png \
    image/pic/qq-hover.png \
    image/pic/qq-old.png \
    image/pic/qq.png \
    image/pic/user_name.png \
    image/pic/wb-hover.png \
    image/pic/wb.png \
    image/pic/wb111.png \
    image/pic/wx-hover.png \
    image/pic/wx.png \
    image/pic/wx111.png \
    image/querybook/back.png \
    image/querybook/background.png \
    image/querybook/down_arrow.png \
    image/querybook/live.jpg \
    image/user/boy_blue.png \
    image/user/boy_green.png \
    image/user/boy_red.png \
    image/user/boy_yellow.png \
    image/user/girl_blue.png \
    image/user/girl_green.png \
    image/user/girl_red.png \
    image/user/girl_yellow.png \
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

CONFIG += resources_big


