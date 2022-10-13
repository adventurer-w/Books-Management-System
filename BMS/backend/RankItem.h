#ifndef RANKITEM_H
#define RANKITEM_H

#include<iostream>
#include "length.h"

using namespace std;
class RankItem{
public:
    int id;
    char isbn[ISBN_SIZE];

    int dirty;

    int getId()
    {
        return id;
    }
    void setId(int id)
    {
        this->id=id;
    }
    void setDirty(int dirty)
    {
        this->dirty=dirty;
    }
    int getDirty()
    {
        return dirty;
    }
    char* getIsbn(){return this->isbn;}
    void setIsbn(const char* isbn){
        for (int i = 0; i < ISBN_SIZE; i ++)
            this->isbn[i] = isbn[i];
    }

    string getElemType(string Elem) {
        if (Elem == "id") return typeid(id).name();
        else if (Elem == "dirty") return typeid(dirty).name();
        else if (Elem == "isbn") return typeid(isbn).name();
        else {
            throw "Field  Not Found!";
        }
    }
    int getIntElemByName(string Elem) {
        if (Elem == "id") return id;
        else if (Elem == "dirty") return dirty;
        else {
            throw "Field  Not Found!";
        }
    }
    float getFloatElemByName(string Elem) {
        return 1;
    }
    char* getCharElemByName(string Elem) {
        if (Elem == "isbn") return  isbn;
        else {
            throw "Field  Not Found!";
        }
    }
};

#endif //RANKITEM_H
