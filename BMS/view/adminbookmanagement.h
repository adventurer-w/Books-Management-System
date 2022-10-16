#ifndef ADMINBOOKMANAGEMENT_H
#define ADMINBOOKMANAGEMENT_H

#include <QWidget>
#include "MainWidget.h"
#include "stditemmodel.h"
#include "backend/Utils.h"

namespace Ui
{
    class AdminBookManagement;
}

class AdminBookManagement : public QWidget
{
    Q_OBJECT

public:
    explicit AdminBookManagement(QWidget *parent = nullptr);

    void getBookList(QString classification, QString key);

    void paintEvent(QPaintEvent *);

    bool loadQss(const QString &StyleSheetFile);

    ~AdminBookManagement();

    void setShadow();

    void showPopularBook();

    void loadIntialBooks();

    void new_button(QString button_text,QString picture_name, int position, Book book, int i);

    void loadBooks();

    void setStackWidget(MainWidget *p);

    void setIcons();

    void on_TableBtn_clicked();

    int nCurScroller = 0; //��ҳʱ�ĵ�ʱ������λ��
    int curPgNum = 1;
    int maxPgNum = 4; // һҳ��ʾ����
    int maxPgs;//���ҳ��
    int curRecord = 0;//�Ѿ�����ļ�¼
    QString pages;//��ʾ��ǰҳ
    StdItemModel *model;


public:
    MainWidget *sub_mw;
    
private
    slots:
            void on_btn_search_clicked();

    void on_btn_author_clicked();

    void on_btn_bookname_clicked();

    void on_btn_ISBN_clicked();

    void on_cbox_classify_currentIndexChanged(int);

    void on_lineEdit_returnPressed();

    void on_btn_first_3_clicked();

    void on_btn_la_3_clicked();

    void on_btn_last_3_clicked();

    void on_btn_fore_3_clicked();

    void on_line_3_returnPressed();

    void on_btn_addbook_clicked();

private:
    Ui::AdminBookManagement *ui;
    QString classify;//��ǰѡ��ķ���
    MainWidget *psw;//�ײ�stackwidget�����ָ�룬���ڷ���
};

#endif // ADMINBOOKLIST_H
