#ifndef ADMIN_H
#define ADMIN_H

#include<typeinfo>
#include<iostream>
#include "length.h"

using namespace std;

class Admin {
private:
    int id; //管理员编号
    char name[USER_NAME_SIZE];    //姓名
    char account[ACCOUNT_SIZE];   //账号
    char password[PASSWORD_SIZE];  //密码
    int flag; //是否被删除
public:
    int getId() { return id; }
    void setId(int id) { this->id = id; }

    int getFlag() { return flag; }
    void setFlag(int flag) { this->flag = flag; }

    char *getName() { return this->name; }

    void setName(const char *name) {
        for (int i = 0; i < USER_NAME_SIZE; i++)
            this->name[i] = name[i];
    }

    char *getAccount() { return this->account; }

    void setAccount(const char *account) {
        for (int i = 0; i < ACCOUNT_SIZE; i++)
            this->account[i] = account[i];
    }

    char *getPassword() { return this->password; }

    void setPassword(const char *password) {
        for (int i = 0; i < PASSWORD_SIZE; i++)
            this->password[i] = password[i];
    }

    string getElemType(string Elem)  //获取变量类型
    {
        if (Elem == "id")return typeid(id).name();
        else if (Elem == "account")return typeid(account).name();
        else if (Elem == "password")return typeid(password).name();
        else if (Elem == "name")return typeid(name).name();
        else if (Elem == "flag")return typeid(flag).name();
        else {
            throw "Field  Not Found!";
        }
    }

    int getIntElemByName(string Elem)
    {
        if (Elem == "id") return id;
        if (Elem == "flag") return flag;
        else
        {
            throw "Field  Not Found!";
        }
    }

    float getFloatElemByName(string Elem)
    {
        return 0;
    }

    char* getCharElemByName(string Elem)
    {
        if (Elem == "account")return  account;
        else if (Elem == "password")return password;
        else if (Elem == "name")return name;
        else
        {
            throw "Field  Not Found!";
        }
    }
};


#endif //ADMIN_H
