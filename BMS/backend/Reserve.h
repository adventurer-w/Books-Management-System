#ifndef RESERVE_H
#define RESERVE_H
#include <iostream>
#include "length.h"

class Reserve{
public:
    int id;
    char isbn[ISBN_SIZE];
    char account[ACCOUNT_SIZE];
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

    string getElemType(string Elem) {
        if (Elem == "id") return typeid(id).name();
        else if (Elem == "isbn") return typeid(isbn).name();
        else if (Elem == "account") return typeid(account).name();
        else if (Elem == "date")return typeid(date).name();
        else if (Elem == "dirty")return typeid(dirty).name();
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
        else {
            throw "Field  Not Found!";
        }
    }
};
#endif //RESERVE_H
