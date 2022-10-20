#include "stditemmodel.h"
#include <QStandardItemModel>
#include <QDebug>
#include <QPushButton>
#include <QLabel>
#include "GlobalSetting.h"
#include "booklist.h"
StdItemModel::StdItemModel()
{

}
/*
 *@author yuan
继承了QStandardItemModel类
重写QStandardItemModel的data方法，使得单元格内容能够居中对齐

*/

QVariant StdItemModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::TextAlignmentRole)
    {
        return int(Qt::AlignCenter);  //按需调整
    }
    return QStandardItemModel::data(index,role);
}
/*void StdItemModel::loadBookData(vector<Book> &re,BookList *bookList)
{




        for(int i=0;i<re.size();i++){

            this->setItem(i, 1, new QStandardItem(re[i].getBookName()));
            this->setItem(i, 2, new QStandardItem(re[i].getAuthor()));
            this->setItem(i, 3, new QStandardItem(re[i].getPublisher()));
            this->setItem(i, 4, new QStandardItem(re[i].getIsbn()));
            this->setItem(i, 5, new QStandardItem(re[i].getLeft()>0 ? "有":"无"));
            qDebug()<< i << " ";

            //往表格中添加按钮控件
            QPushButton *button = new QPushButton("详情");
            QLabel *l1 = new QLabel();     //创建lable
            qDebug()<< -i << " ";
            string t1(re[i].getImgPath());
            string t2(re[i].getIsbn());
            string pic;
            if(t2.size()==13)
                       pic=pictureDbPath+t1+"/"+t2+".jpg";
                   else
                       pic=pictureDbPath+"moren.jpg";

            QPixmap pixmap(pic.c_str());
                   QPixmap fitpixmap;
                   if(pixmap.isNull()){
                       QPixmap pixmap2((pictureDbPath+"moren.jpg").c_str());
                       fitpixmap = pixmap2.scaled(120, 150, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
                   }else{
                       fitpixmap = pixmap.scaled(120, 150, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
                   }

            qDebug()<< i << " ";
            l1->setPixmap(fitpixmap);    //加载图片
            l1->setScaledContents(true);
            qDebug()<< i+1 << " ";
            l1->setAlignment(Qt::AlignCenter);      //设置居中
            this->setItem(i,0,new QStandardItem(li));
            tbv->setIndexWidget(this->index(i,0),l1);     //显示
             //this->setData(this->index(i, 0), l1);
            qDebug()<< -i << " ";
            //设置按钮的自定义属性
            button->setProperty("tb_ISBN",this->index(i,4,QModelIndex()).data().toString());
            connect(button,&QPushButton::clicked,bookList,&BookList::on_TableBtn_clicked);
            qDebug()<< i << " ";
            //将按钮加入表格中
            tbv->setIndexWidget(this->index(i,6),button);


        }



}*/
