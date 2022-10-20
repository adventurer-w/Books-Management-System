#ifndef BOOLCLASS_H
#define BOOLCLASS_H
#include <iostream>
#include "length.h"

class BookClass{
public:
    int id;
    int classNo;//分类号
    char name[CLASSIFICATION_SIZE]; // 名称
    int dirty; //脏位


    int getId() {
        return id;
    }
    void setId(int id) {
        this->id = id;
    }
    char* getName() {
        return this->name;
    }
    void setName(char* name) {
        for (int i = 0; i < CLASSIFICATION_SIZE; i++)
            this->name[i] = name[i];
    }
    int getDirty() {
        return dirty;
    }
    void setDirty(int dirty) {
        this->dirty = dirty;
    }

    int getClassNo() {
        return classNo;
    }
    void setClassNo(int classNo) {
        this->classNo = classNo;
    }


    string getElemType(string Elem) {
        if (Elem == "id") return typeid(id).name();
        else if (Elem == "name") return typeid(name).name();
        else if (Elem == "dirty") return typeid(dirty).name();
        else if (Elem == "classNo") return typeid(classNo).name();
        else {
            throw "Field  Not Found!";
        }
    }

    int getIntElemByName(string Elem) {
        if (Elem == "id") return id;
        else if (Elem == "dirty") return dirty;
        else if (Elem == "classNo") return classNo;
        else {
            throw "Field  Not Found!";
        }
    }

    float getFloatElemByName(string Elem) {
        return 1;
    }

    char* getCharElemByName(string Elem) {
        if (Elem == "name") return  name;
        else {
            throw "Field  Not Found!";
        }
    }

};

#endif //BOOLCLASS_H
