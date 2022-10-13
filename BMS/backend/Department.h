#ifndef DEPARTMENT_H
#define DEPARTMENT_H
#include <iostream>
#include "length.h"

class Department{
    public:
    int id;
    int departmentNo;//专业编号
    char name[MAJOR_SIZE]; // 院系名称
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
        for (int i = 0; i < MAJOR_SIZE; i++)
            this->name[i] = name[i];
    }
    int getDirty() {
        return dirty;
    }
    void setDirty(int dirty) {
        this->dirty = dirty;
    }

    int getDepartmentNo() {
        return departmentNo;
    }
    void setDepartmentNo(int departmentNo) {
        this->departmentNo = departmentNo;
    }


    string getElemType(string Elem) {
        if (Elem == "id") return typeid(id).name();
        else if (Elem == "name") return typeid(name).name();
        else if (Elem == "dirty") return typeid(dirty).name();
        else if (Elem == "departmentNo") return typeid(departmentNo).name();
        else {
            throw "Field  Not Found!";
        }
    }

    int getIntElemByName(string Elem) {
        if (Elem == "id") return id;
        else if (Elem == "dirty") return dirty;
        else if (Elem == "departmentNo") return departmentNo;
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

#endif //DEPARTMENT_H
