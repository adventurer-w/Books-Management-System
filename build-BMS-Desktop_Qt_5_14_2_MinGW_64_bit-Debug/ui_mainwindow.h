/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_quit;
    QAction *action;
    QAction *action_2;
    QWidget *centralwidget;
    QLabel *lb_currentborrow;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *btn_enterLibary;
    QSpacerItem *verticalSpacer;
    QPushButton *btn_myReserve;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QLineEdit *le_search;
    QSpacerItem *hsp_search;
    QPushButton *btn_search;
    QWidget *layoutWidget2;
    QGridLayout *gridLayout;
    QLabel *lb_username_txt;
    QSpacerItem *verticalSpacer_2;
    QLabel *lb_credit_img;
    QLabel *lb_major;
    QLabel *lb_username_img;
    QLabel *lb_major_img;
    QLabel *lb_number_img;
    QLabel *lb_credit_txt;
    QLabel *lb_username;
    QLabel *lb_number;
    QLabel *lb_credit;
    QLabel *lb_number_txt;
    QSpacerItem *verticalSpacer_3;
    QLabel *lb_major_txt;
    QSpacerItem *verticalSpacer_4;
    QMenuBar *menubar;
    QMenu *menustart;
    QMenu *menu_modify;
    QMenu *menu_library;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1200, 800);
        MainWindow->setMaximumSize(QSize(166666, 166666));
        action_quit = new QAction(MainWindow);
        action_quit->setObjectName(QString::fromUtf8("action_quit"));
        action = new QAction(MainWindow);
        action->setObjectName(QString::fromUtf8("action"));
        action_2 = new QAction(MainWindow);
        action_2->setObjectName(QString::fromUtf8("action_2"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        lb_currentborrow = new QLabel(centralwidget);
        lb_currentborrow->setObjectName(QString::fromUtf8("lb_currentborrow"));
        lb_currentborrow->setGeometry(QRect(800, 190, 161, 51));
        lb_currentborrow->setAcceptDrops(true);
        lb_currentborrow->setStyleSheet(QString::fromUtf8(""));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(1080, 190, 104, 128));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        btn_enterLibary = new QPushButton(layoutWidget);
        btn_enterLibary->setObjectName(QString::fromUtf8("btn_enterLibary"));
        btn_enterLibary->setMinimumSize(QSize(10, 10));
        btn_enterLibary->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(btn_enterLibary);

        verticalSpacer = new QSpacerItem(20, 58, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        btn_myReserve = new QPushButton(layoutWidget);
        btn_myReserve->setObjectName(QString::fromUtf8("btn_myReserve"));
        btn_myReserve->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(btn_myReserve);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(800, 70, 381, 61));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetNoConstraint);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        le_search = new QLineEdit(layoutWidget1);
        le_search->setObjectName(QString::fromUtf8("le_search"));
        le_search->setFocusPolicy(Qt::ClickFocus);
        le_search->setAcceptDrops(false);
        le_search->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(le_search);

        hsp_search = new QSpacerItem(50, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout->addItem(hsp_search);

        btn_search = new QPushButton(layoutWidget1);
        btn_search->setObjectName(QString::fromUtf8("btn_search"));
        btn_search->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(btn_search);

        layoutWidget2 = new QWidget(centralwidget);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(93, 189, 171, 211));
        gridLayout = new QGridLayout(layoutWidget2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lb_username_txt = new QLabel(layoutWidget2);
        lb_username_txt->setObjectName(QString::fromUtf8("lb_username_txt"));
        lb_username_txt->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(lb_username_txt, 0, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(10, 15, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout->addItem(verticalSpacer_2, 5, 0, 1, 1);

        lb_credit_img = new QLabel(layoutWidget2);
        lb_credit_img->setObjectName(QString::fromUtf8("lb_credit_img"));
        lb_credit_img->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(lb_credit_img, 6, 0, 1, 1);

        lb_major = new QLabel(layoutWidget2);
        lb_major->setObjectName(QString::fromUtf8("lb_major"));
        lb_major->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(lb_major, 4, 1, 1, 1);

        lb_username_img = new QLabel(layoutWidget2);
        lb_username_img->setObjectName(QString::fromUtf8("lb_username_img"));
        lb_username_img->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(lb_username_img, 0, 0, 1, 1);

        lb_major_img = new QLabel(layoutWidget2);
        lb_major_img->setObjectName(QString::fromUtf8("lb_major_img"));
        lb_major_img->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(lb_major_img, 4, 0, 1, 1);

        lb_number_img = new QLabel(layoutWidget2);
        lb_number_img->setObjectName(QString::fromUtf8("lb_number_img"));
        lb_number_img->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(lb_number_img, 2, 0, 1, 1);

        lb_credit_txt = new QLabel(layoutWidget2);
        lb_credit_txt->setObjectName(QString::fromUtf8("lb_credit_txt"));
        lb_credit_txt->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(lb_credit_txt, 6, 2, 1, 1);

        lb_username = new QLabel(layoutWidget2);
        lb_username->setObjectName(QString::fromUtf8("lb_username"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lb_username->sizePolicy().hasHeightForWidth());
        lb_username->setSizePolicy(sizePolicy);
        lb_username->setMaximumSize(QSize(500, 100));
        lb_username->setAcceptDrops(true);
        lb_username->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(lb_username, 0, 1, 1, 1);

        lb_number = new QLabel(layoutWidget2);
        lb_number->setObjectName(QString::fromUtf8("lb_number"));
        lb_number->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(lb_number, 2, 1, 1, 1);

        lb_credit = new QLabel(layoutWidget2);
        lb_credit->setObjectName(QString::fromUtf8("lb_credit"));
        lb_credit->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(lb_credit, 6, 1, 1, 1);

        lb_number_txt = new QLabel(layoutWidget2);
        lb_number_txt->setObjectName(QString::fromUtf8("lb_number_txt"));
        lb_number_txt->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(lb_number_txt, 2, 2, 1, 1);

        verticalSpacer_3 = new QSpacerItem(10, 10, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout->addItem(verticalSpacer_3, 3, 0, 1, 1);

        lb_major_txt = new QLabel(layoutWidget2);
        lb_major_txt->setObjectName(QString::fromUtf8("lb_major_txt"));
        lb_major_txt->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(lb_major_txt, 4, 2, 1, 1);

        verticalSpacer_4 = new QSpacerItem(10, 10, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout->addItem(verticalSpacer_4, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1200, 26));
        menustart = new QMenu(menubar);
        menustart->setObjectName(QString::fromUtf8("menustart"));
        menu_modify = new QMenu(menubar);
        menu_modify->setObjectName(QString::fromUtf8("menu_modify"));
        menu_library = new QMenu(menubar);
        menu_library->setObjectName(QString::fromUtf8("menu_library"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menustart->menuAction());
        menubar->addAction(menu_modify->menuAction());
        menubar->addAction(menu_library->menuAction());
        menustart->addAction(action_quit);
        menu_modify->addAction(action);
        menu_library->addAction(action_2);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        action_quit->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
        action->setText(QCoreApplication::translate("MainWindow", "\344\277\256\346\224\271\344\270\252\344\272\272\344\277\241\346\201\257", nullptr));
        action_2->setText(QCoreApplication::translate("MainWindow", "\345\200\237\351\230\205", nullptr));
        lb_currentborrow->setText(QCoreApplication::translate("MainWindow", "\345\275\223\345\211\215\345\200\237\351\230\205", nullptr));
        btn_enterLibary->setText(QCoreApplication::translate("MainWindow", "\350\277\233\345\205\245\345\233\276\344\271\246\351\246\206", nullptr));
        btn_myReserve->setText(QCoreApplication::translate("MainWindow", "\346\210\221\347\232\204\351\242\204\347\272\246", nullptr));
        btn_search->setText(QCoreApplication::translate("MainWindow", "\346\220\234\347\264\242", nullptr));
        lb_username_txt->setText(QCoreApplication::translate("MainWindow", "\346\235\260\345\223\245", nullptr));
        lb_credit_img->setText(QString());
        lb_major->setText(QCoreApplication::translate("MainWindow", "\344\270\223\344\270\232", nullptr));
        lb_username_img->setText(QString());
        lb_major_img->setText(QString());
        lb_number_img->setText(QString());
        lb_credit_txt->setText(QCoreApplication::translate("MainWindow", "100", nullptr));
        lb_username->setText(QCoreApplication::translate("MainWindow", "\345\247\223\345\220\215", nullptr));
        lb_number->setText(QCoreApplication::translate("MainWindow", "\345\255\246\345\217\267", nullptr));
        lb_credit->setText(QCoreApplication::translate("MainWindow", "\344\277\241\350\252\211", nullptr));
        lb_number_txt->setText(QCoreApplication::translate("MainWindow", "114514", nullptr));
        lb_major_txt->setText(QCoreApplication::translate("MainWindow", "\351\243\236\346\234\272", nullptr));
        menustart->setTitle(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213", nullptr));
        menu_modify->setTitle(QCoreApplication::translate("MainWindow", "\344\277\256\346\224\271", nullptr));
        menu_library->setTitle(QCoreApplication::translate("MainWindow", "\345\233\276\344\271\246\351\246\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
