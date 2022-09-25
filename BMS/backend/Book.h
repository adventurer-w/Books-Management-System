#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include "length.h"
#include <string>

class Book{
private:
    int id;
    int left;//余量
    int allNum;//总数
    int historyNum;//历史借阅数
    int boyHistoryNum;//男生历史借阅数
    int girlHistoryNum;//女生历史借阅数
    int flag;
    char bookName[BOOK_NAME_SIZE];//书名
    char author[AUTHOR_SIZE];//作者
    char publisher[PUBLISHER_SIZE];//出版社
    char isbn[ISBN_SIZE];//13位
    char classification[CLASSIFICATION_SIZE];//类别
    char publishDate[DATE_SIZE];//出版时间
    char introduction[INTRODUCTION_SIZE]; //简介
    char imgPath[IMAGE_PATH];//图片路径
    float point; //评分

public:
    int getId() { return id; }

    void setId(int id) { this->id = id; }

    int getFlag() { return flag; }
    void setFlag(int flag) { this->flag = flag; }

    char* getBookName() {return this->bookName;}
    void setBookName(const char *bookName) {
        for (int i = 0; i < BOOK_NAME_SIZE; i++)
            this->bookName[i] = bookName[i];
    }

    char *getAuthor() { return this->author; }
    void setAuthor(const char *author) {
        for (int i = 0; i < AUTHOR_SIZE; i++)
            this->author[i] = author[i];
    }

    char *getPublisher() { return this->publisher; }

    void setPublisher(const char *publisher) {
        for (int i = 0; i < PUBLISHER_SIZE; i++)
            this->publisher[i] = publisher[i];
    }

    char *getIsbn() { return this->isbn; }

    void setIsbn(const char *isbn) {
        for (int i = 0; i < ISBN_SIZE; i++)
            this->isbn[i] = isbn[i];
    }

    char *getClassifition() { return this->classification; }

    void setClassification(const char *classification) {
        for (int i = 0; i < CLASSIFICATION_SIZE; i++)
            this->classification[i] = classification[i];
    }

    char *getPublishDate(){ return this->publishDate; }
    void setPublishDate(const char *publish_date) {
        for (int i = 0; i < DATE_SIZE; i++)
            this->publishDate[i] = publish_date[i];
    }

    char *getIntroduction(){ return this->introduction; }
    void setIntroduction(const char *introduction) {
        for (int i = 0; i < INTRODUCTION_SIZE; i++)
            this->introduction[i] = introduction[i];
    }

    char *getImgPath(){ return this->imgPath; }
    void setImgPath(const char *imgPath) {
        for (int i = 0; i < IMAGE_PATH; i++)
            this->imgPath[i] = imgPath[i];
    }

    int getAllNum() { return this->allNum; }
    void setAllNum(int allNum) { this->allNum = allNum; }

    int getLeft() { return this->left; }
    void setLeft(int left) { this->left = left; }

    int getHistoryNum() { return this->historyNum; }
    void setHistoryNum(int historyNum) { this->historyNum = historyNum; }

    int getBoyHistoryNum() { return this->boyHistoryNum; }
    void setBoyHistoryNum(int boyHistoryNum) { this->boyHistoryNum = boyHistoryNum;}

    int getGirlHistoryNum() { return this->girlHistoryNum; }
    void setGirlHistoryNum(int girlHistoryNum) { this->girlHistoryNum = girlHistoryNum;}

    float getPoint() { return this->point; }
    void setPoint(int point) { this->point = point;}

    string getElemType(string Elem)  //获取变量类型
    {
        if (Elem == "id")return typeid(id).name();
        else if (Elem == "bookName")return typeid(bookName).name();
        else if (Elem == "author")return typeid(author).name();
        else if (Elem == "publisher")return typeid(publisher).name();
        else if (Elem == "isbn")return typeid(isbn).name();
        else if (Elem == "classification")return typeid(classification).name();
        else if (Elem == "publishDate")return typeid(publishDate).name();
        else if (Elem == "introduction")return typeid(introduction).name();
        else if (Elem == "imgPath")return typeid(imgPath).name();
        else if (Elem == "left")return typeid(left).name();
        else if (Elem == "allNum")return typeid(allNum).name();
        else if (Elem == "historyNum")return typeid(historyNum).name();
        else if (Elem == "boyHistoryNum")return typeid(boyHistoryNum).name();
        else if (Elem == "girlHistoryNum")return typeid(girlHistoryNum).name();
        else if (Elem == "point")return typeid(point).name();
        else if (Elem == "flag")return typeid(flag).name();
        else {
            throw "Field  Not Found!";
        }
    }

    int getIntElemByName(string Elem)
    {
        if (Elem == "id") return id;
        else if (Elem == "left") return left;
        else if (Elem == "allNum") return allNum;
        else if (Elem == "historyNum")return historyNum;
        else if (Elem == "boyHistoryNum")return boyHistoryNum;
        else if (Elem == "girlHistoryNum")return girlHistoryNum;
        else if (Elem == "flag")return flag;
        else
        {
            throw "Field  Not Found!";
        }
    }

    float getFloatElemByName(string Elem)
    {
        if (Elem == "point") return point;
        else
        {
            throw "Field  Not Found!";
        }
    }

    char* getCharElemByName(string Elem)
    {
        if (Elem == "bookName")return  bookName;
        else if (Elem == "author")return author;
        else if (Elem == "publisher")return publisher;
        else if(Elem=="isbn")return isbn;
        else if(Elem=="classification")return classification;
        else if(Elem=="publishDate")return publishDate;
        else if(Elem=="introduction")return introduction;
        else if(Elem=="imgPath")return imgPath;
        else
        {
            throw "Field  Not Found!";
        }
    }

};

#endif //BOOK_H
