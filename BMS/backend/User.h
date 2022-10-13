#ifndef USER_H
#define USER_H

#include<typeinfo>
#include<iostream>
#include "length.h"

class User {
public:
    int id; //学生编号
    char name[USER_NAME_SIZE];    //昵称（姓名）
    char account[ACCOUNT_SIZE];   //账号（学号）
    char password[PASSWORD_SIZE];  //密码
    int sex;    //性别
    int departmentNo;   //专业
    char security_question[SECURITY_QUESTION_SIZE];  //密保问题
    char security_answer[SECURITY_ANSWER_SIZE];   //密保答案
    int num_borrowed;     //借书数目
    int num_appointed;   //预约数
    int debet;         //欠款数
    char email[EMAIL_SIZE];  //邮箱
    int dirty;



    int getId() { return id; }
    void setId(int id) { this->id = id; }

    int getDirty() { return dirty; }

    void setDirty(int dirty) { this->dirty = dirty; }

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

    int getSex() { return this->sex; }

    void setSex(int sex) { this->sex = sex; }

    int getDepartmentNo() { return this->departmentNo; }

    void setDepartmentNo(int departmentNo) {
        this->departmentNo = departmentNo;
    }

    char *getSecurityQuestion() { return this->security_question; }

    void setSecurityQuestion(const char *security_question) {
        for (int i = 0; i < SECURITY_QUESTION_SIZE; i++)
            this->security_question[i] = security_question[i];
    }

    char *getSecurityAnswer() { return this->security_answer; }

    void setSecurityAnswer(const char *security_answer) {
        for (int i = 0; i < SECURITY_ANSWER_SIZE; i++)
            this->security_answer[i] = security_answer[i];
    }

    int getNumBorrowed() { return num_borrowed; }

    void setNumBorrowed(int num_borrowed) { this->num_borrowed = num_borrowed; }

    int getNumAppointed() { return num_appointed; }

    void setNumAppointed(int num_appointed) { this->num_appointed = num_appointed; }

    int getDebet() { return debet; }

    void setDebet(int debet) { this->debet = debet; }



    char* getEmail() { return this->email; }
    void setEmail(const char *email) {
        for (int i = 0; i < EMAIL_SIZE; i++)
            this->email[i] = email[i];
    }

    string getElemType(string Elem)  //获取变量类型
    {
        if (Elem == "id")return typeid(id).name();
        else if (Elem == "account")return typeid(account).name();
        else if (Elem == "password")return typeid(password).name();
        else if (Elem == "name")return typeid(name).name();
        else if (Elem == "sex")return typeid(sex).name();
        else if (Elem == "departmentNo")return typeid(departmentNo).name();
        else if (Elem == "num_borrowed")return typeid(num_borrowed).name();
        else if (Elem == "num_appointed") return typeid(num_appointed).name();
        else if (Elem == "debet")return typeid(debet).name();
        else if (Elem == "security_question") return typeid(security_question).name();
        else if (Elem == "security_answer") return typeid(security_answer).name();
        else if (Elem == "email") return typeid(email).name();
        else if (Elem == "dirty") return typeid(dirty).name();
        else {
            throw "Field  Not Found!";
        }
    }

    int getIntElemByName(string Elem) {
        if (Elem == "id") return id;
        else if (Elem == "sex") return sex;
        else if (Elem == "num_borrowed") return num_borrowed;
        else if (Elem == "debet")return debet;
        else if (Elem == "dirty")return dirty;
        else if (Elem == "departmentNo")return departmentNo;
        else if (Elem == "num_appointed")return num_appointed;
        else {
            throw "Field  Not Found!";
        }
    }

    float getFloatElemByName(string Elem) {
        return 0;
    }

    char *getCharElemByName(string Elem) {
        if (Elem == "account")return account;
        else if (Elem == "password")return password;
        else if (Elem == "name")return name;
        else if (Elem == "security_question")return security_question;
        else if (Elem == "security_answer")return security_answer;
        else if (Elem == "email")return email;
        else {
            throw "Field  Not Found!";
        }
    }
};

#endif //USER_H
