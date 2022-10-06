#ifndef RECORD_H
#define RECORD_H
#include <iostream>
#include "length.h"
class Record{
public:
    int id;
    char isbn[ISBN_SIZE];
    char account[ACCOUNT_SIZE];
    char bookName[BOOK_NAME_SIZE];//书名
    char author[AUTHOR_SIZE];//作者
    char publisher[PUBLISHER_SIZE];//出版社
    char date[DATE_SIZE]; // 借书日期
    int dirty;

    void setId(int id){this->id=id;}
    int getId(){return this->id;}

    void setDirty(int dirty){this->dirty=dirty;}
    int getDirty(){return this->dirty;}


    char* getIsbn(){return this->isbn;}
    void setIsbn(const char* isbn){
        for (int i = 0; i < ISBN_SIZE; i ++)
            this->isbn[i] = isbn[i];
    }

    char* getAccount(){return account;}
    void setAccount(const char* account){
        for (int i = 0; i < ACCOUNT_SIZE; i ++)
            this->account[i] = account[i];
    }

    char* getDate(){return date;}
    void setDate(const char* date){
        for (int i = 0; i < DATE_SIZE; i ++)
            this->date[i] = date[i];
    }

    char* getBookName(){return bookName;}
    void setBookName(const char* bookName){
        for (int i = 0; i < BOOK_NAME_SIZE; i ++)
            this->bookName[i] = bookName[i];
    }

    char* getAuthor(){return author;}
    void setAuthor(const char* author){
        for (int i = 0; i < AUTHOR_SIZE; i ++)
            this->author[i] = author[i];
    }

    char* getPublisher(){return publisher;}
    void setPublisher(const char* publisher){
        for (int i = 0; i < PUBLISHER_SIZE; i ++)
            this->publisher[i] = publisher[i];
    }

    string getElemType(string Elem) {
        if (Elem == "id") return typeid(id).name();
        else if (Elem == "isbn") return typeid(isbn).name();
        else if (Elem == "account") return typeid(account).name();
        else if (Elem == "date")return typeid(date).name();
        else if (Elem == "dirty")return typeid(dirty).name();
        else if (Elem == "bookName") return typeid(account).name();
        else if (Elem == "author")return typeid(date).name();
        else if (Elem == "publisher")return typeid(dirty).name();
        else {
            throw "Field  Not Found!";
        }
    }

    int getIntElemByName(string Elem) {
        if (Elem == "id") return id;
        else if (Elem == "dirty")return dirty;
        else {
            throw "Field  Not Found!";
        }
    }
    float getFloatElemByName(string Elem) {
        return 1;
    }
    char* getCharElemByName(string Elem) {
        if (Elem == "isbn") return  isbn;
        else if (Elem == "account") return this->account;
        else if (Elem == "date") return this->date;
        else if (Elem == "bookName") return this->bookName;
        else if (Elem == "author") return this->author;
        else if (Elem == "publisher") return this->publisher;
        else {
            throw "Field  Not Found!";
        }
    }
};
#endif //RECORD_H
