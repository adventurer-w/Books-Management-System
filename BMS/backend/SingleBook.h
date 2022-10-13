#ifndef SINGLEBOOK_H
#define SINGLEBOOK_H

#include <iostream>
#include "length.h"
using namespace std;
class SingleBook{

public:
    int id;
    int dirty;
    int isBorrowed;//是否被借走
    char isbn[ISBN_SIZE];//13位

    int getId() { return id; }
    void setId(int id) { this->id = id; }

    int getDirty() { return dirty; }
    void setDirty(int dirty) { this->dirty = dirty; }

    int getIsBorrowed() { return isBorrowed; }
    void setIsBorrowed(int isBorrowed) { this->isBorrowed = isBorrowed; }


    char *getIsbn() { return this->isbn; }
    void setIsbn(const char *isbn) {
        for (int i = 0; i < ISBN_SIZE; i++)
            this->isbn[i] = isbn[i];
    }


    string getElemType(string Elem)  //获取变量类型
    {
        if (Elem == "id")return typeid(id).name();
        else if (Elem == "isbn")return typeid(isbn).name();
        else if (Elem == "dirty")return typeid(dirty).name();
        else if (Elem == "isBorrowed")return typeid(isBorrowed).name();
        else {
            throw "Field  Not Found!";
        }
    }

    int getIntElemByName(string Elem)
    {
        if (Elem == "id") return id;
        else if (Elem == "dirty")return dirty;
        else if (Elem == "isBorrowed")return isBorrowed;
        else
        {
            throw "Field  Not Found!";
        }
    }

    float getFloatElemByName(string Elem)
    {
        throw "Field  Not Found!";
    }

    char* getCharElemByName(string Elem)
    {
        if(Elem=="isbn")return isbn;
        else
        {
            throw "Field  Not Found!";
        }
    }

};

#endif //SINGLEBOOK_H
