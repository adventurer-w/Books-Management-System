#include "Utils.h"
#include "all_head.h"
#include "length.h"
#include "myFileDB.h"
#include "MD5.h"

using namespace std;

myFileDB db = myFileDB("D:\\BMS\\backend\\Files\\");


//int select(string DB_NAME, T &entity, vector<string> &VALUES, vector<T> &resultSet);
//int selectLike(string DB_NAME, string valueName, char *value, vector<T> &resultSet);
//int insert(string DB_NAME, vector<T> &entity);
//int Delete(string DB_NAME, T &entity, vector<string> &VALUES);
//int update(string DB_NAME, T &Sentity, T &Uentity, vector<string> &VALUES);


//！！！！密码用MD5储存！！！！
// 前端在传输数据之前需要使用MD5加密！


int Utils::Login(char *account, char *password) { //密码需传入md5加密后的
    User user = GetUserByAccount(account);

    if (CheckUserExist(user))
    {
        if (strcmp(password, user.getPassword()))
            return 1;
        else
            return 2;
    }else{
        return 0;
    }
}

int Utils::Register(User user) {
    if (CheckUserExist(user))
        return 0;
    else{
        if (InsertUser(user))
            return 1;
        else
            return -1;
    }
}

bool Utils::InsertUser(User user) {
    if (!CheckUserExist(user)){
        vector<User> vec;
        vec.push_back(user);
        if (db.insert("user", vec) != -1)
            return true;
        else
            return false;
    }else{
        return false;
    }
}

bool Utils::UpdateUser(User before, User after) {
    if (CheckUserExist(before)){
        vector<string> vec;
        vec.push_back("not-all");
        vec.push_back("account");
        if (db.update("user", before, after, vec) != -1)
            return true;
        else
            return false;
    }else{
        return false;
    }
}

bool Utils::DeleteUser(User user) {
    if (CheckUserExist(user)){
        vector<string> vec;
        vec.push_back("not-all");
        vec.push_back("account");
        if (db.Delete("user", user, vec) != -1)
            return true;
        else
            return false;
    }else {
        return false;
    }
}

bool Utils::Repayment(User user) {
    User user2(user);
    user2.debet=0;
    return UpdateUser(user,user2);
}

bool Utils::CheckUserExist(User user){
    vector<string> value;
    value.push_back("not-all");
    value.push_back("account");

    vector<User> result;
    if (db.select("user", user, value, result) == -1)
        return false;
    return true;
}

bool Utils::CheckBookExist(Book book){
    vector<string> value;
    value.push_back("not-all");
    value.push_back("isbn");
    vector<Book> result;
    if (db.select("book", book, value, result) == -1)
        return false;
    return true;
}

bool Utils::CheckRecordExist(Record record){
    vector<string> vec;
    vec.push_back("not-all");
    vec.push_back("account");
    vec.push_back("isbn");

    vector<Record> res;

    if (db.select("record", record, vec, res) != -1)
        return true;
    else
        return false;
}

bool Utils::CheckReserveExist(Reserve reserve){
    vector<string> vec;
    vec.push_back("not-all");
    vec.push_back("account");
    vec.push_back("isbn");

    vector<Reserve> res;

    if (db.select("reserve", reserve, vec, res) != -1)
        return true;
    else
        return false;
}



User Utils::GetUserByAccount(char *account) {
    User user = User();
    user.setAccount(account);
    if (CheckUserExist(user))
    {
        vector<string> value;
        value.push_back("not-all");
        value.push_back("account");
        vector<User> result;
        int pos = db.select("user", user, value, result);
        return result.at(0);
    }
    else{
        User user2 = User();
        return user2;
    }
}

bool Utils::GetUserByName(char* name, vector<User>&result){
    User user = User();
    user.setName(name);
    vector<string> val;
    val.push_back("not-all");
    val.push_back("name");
    if (db.select("user", user, val, result) != -1)
        return true;
    else
        return false;
}

bool Utils::GetUserByMajor(char *major, vector<User> &result){
    User user = User();
    user.setMajor(major);
    vector<string> val;
    val.push_back("not-all");
    val.push_back("major");
    if (db.select("user", user, val, result) != -1)
        return true;
    else
        return false;
}
