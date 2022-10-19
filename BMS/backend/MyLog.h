#ifndef MYLOG_H
#define MYLOG_H

#include <iostream>
#include "length.h"


/*
 操作编号
    用户相关
        添加用户 11   删除用户 12   查询用户 13  修改用户 14
    图书相关
        添加图书 21   删除图书 22   查询图书 23  修改图书 24
    借书相关
        借书 31   还书 32   查询记录 33
    预约相关
        预约 41   取消预约 42   查询记录 33
 */
class MyLog{
public:
    int id;
    int optionId; //操作编号
    char key_1[KEY_SIZE];//对象1主码
    char key_2[KEY_SIZE];//对象1主码
    char val_1[VAL_SIZE];//数据1
    char val_2[VAL_SIZE];//数据2
    int dirty;

    int getId() {
        return id;
    }
    void setId(int id) {
        this->id = id;
    }

    int getOptionId() {
        return optionId;
    }
    void setOptionId(int optionId) {
        this->optionId = optionId;
    }

    char* getVal_1() {
        return this->val_1;
    }
    void setVal_1(char* val_1) {
        for (int i = 0; i < VAL_SIZE; i++)
            this->val_1[i] = val_1[i];
    }

    char* getVal_2() {
        return this->val_2;
    }
    void setVal_2(char* val_2) {
        for (int i = 0; i < VAL_SIZE; i++)
            this->val_2[i] = val_2[i];
    }

    char* getKey_2() {
        return this->key_2;
    }
    void setKey_2(char* key_2) {
        for (int i = 0; i < KEY_SIZE; i++)
            this->key_2[i] = key_2[i];
    }

    char* getKey_1() {
        return this->key_1;
    }
    void setKey_1(char* key_1) {
        for (int i = 0; i < KEY_SIZE; i++)
            this->key_1[i] = key_1[i];
    }
    int getDirty() {
        return dirty;
    }
    void setDirty(int dirty) {
        this->dirty = dirty;
    }



    string getElemType(string Elem) {
        if (Elem == "id") return typeid(id).name();
        else if (Elem == "key_1") return typeid(key_1).name();
        else if (Elem == "key_2") return typeid(key_2).name();
        else if (Elem == "val_1") return typeid(val_1).name();
        else if (Elem == "val_2") return typeid(val_2).name();
        else if (Elem == "optionId") return typeid(optionId).name();
        else if (Elem == "dirty") return typeid(dirty).name();
        else {
            throw "Field  Not Found!";
        }
    }

    int getIntElemByName(string Elem) {
        if (Elem == "id") return id;
        else if (Elem == "dirty") return dirty;
        else if (Elem == "optionId") return optionId;
        else {
            throw "Field  Not Found!";
        }
    }

    float getFloatElemByName(string Elem) {
        return 1;
    }

    char* getCharElemByName(string Elem) {
        if (Elem == "key_1") return  key_1;
        if (Elem == "key_2") return  key_2;
        if (Elem == "val_1") return  val_1;
        if (Elem == "val_2") return  val_2;
        else {
            throw "Field  Not Found!";
        }
    }

};

#endif //MYLOG_H
