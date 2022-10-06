#include "Utils.h"
#include "all_head.h"
#include "length.h"
#include "MD5.h"

using namespace std;

//int select(string DB_NAME, T &entity, vector<string> &VALUES, vector<T> &resultSet);
//int selectLike(string DB_NAME, string valueName, char *value, vector<T> &resultSet);
//int insert(string DB_NAME, vector<T> &entity);
//int Delete(string DB_NAME, T &entity, vector<string> &VALUES);
//int update(string DB_NAME, T &Sentity, T &Uentity, vector<string> &VALUES);


//！！！！密码用MD5储存！！！！
// 前端在传输数据之前需要使用MD5加密！


int Utils::Login(char *account, char *password) { //密码需传入md5加密后的
    User user = User();
    GetUserByAccount(account,user);

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
    user2.setDebet(0);
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

bool Utils::CheckAdminExist(Admin admin){
    vector<string> value;
    value.push_back("not-all");
    value.push_back("account");

    vector<Admin> result;
    if (db.select("admin", admin, value, result) == -1)
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



bool Utils::GetUserByAccount(char *account,User& user0) {
    User user = User();
    user.setAccount(account);
    if (CheckUserExist(user))
    {
        vector<string> value;
        value.push_back("not-all");
        value.push_back("account");
        vector<User> result;
        int pos = db.select("user", user, value, result);
        if(result.empty()){
            return false;
        }else{
            if(result[0].dirty==1){
                return false;
            }else{
                user0 = result[0];
                return true;
            }
        }
    }
    else{
        return false;
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


bool Utils::GetUserById(int id,User& user0) {
    User user = User();
    user.setId(id);


    vector<string> value;
    value.push_back("not-all");
    value.push_back("id");
    vector<User> result;
    db.select("user", user, value, result);
    if(result.empty()){
        return false;
    }else{
        if(result[0].dirty == 1){
            return false;
        }else{
            user0 = result[0];
            return true;
        }
    }
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


Admin Utils::GetAdminByAccount(char *account) {
    Admin admin = Admin();
    admin.setAccount(account);
    if (CheckAdminExist(admin))
    {
        vector<string> value;
        value.push_back("not-all");
        value.push_back("account");
        vector<Admin> result;
        int pos = db.select("user", admin, value, result);
        return result.at(0);
    }
    else{
        Admin admin2 = Admin();
        return admin2;
    }
}

bool Utils::GetAdminByName(char* name, vector<Admin>&result){
    Admin admin = Admin();
    admin.setName(name);
    vector<string> val;

    val.push_back("not-all");
    val.push_back("name");
    if (db.select("user", admin, val, result) != -1)
        return true;
    else
        return false;
}


int Utils::AdminLogin(char *account, char *password) {
    Admin admin = GetAdminByAccount(account);

    if (CheckAdminExist(admin))
    {
        if (strcmp(password, admin.getPassword()))
            return 1;
        else
            return 2;
    }else{
        return 0;
    }
}


int Utils::AdminRegister(Admin admin) {
    if (CheckAdminExist(admin))
        return 0;
    else{
        if (InsertAdmin(admin))
            return 1;
        else
            return -1;
    }
}

bool Utils::InsertAdmin(Admin admin){
    if (!CheckAdminExist(admin)){
        vector<Admin> vec;
        vec.push_back(admin);
        if (db.insert("admin", vec) != -1)
            return true;
        else
            return false;
    }else{
        return false;
    }
}

bool Utils::InsertBook(Book book)
{
    if (!CheckBookExist(book)){
        vector<Book> entity;
        entity.push_back(book);
        if (db.insert("book", entity) != -1){
            return true;
        }else {
            return false;
        }
    }else {
        return false;
    }
}

bool Utils::DeleteBook(Book book){
    if (CheckBookExist(book)){
        vector<string> vec;
        vec.push_back("not-all");
        vec.push_back("isbn");
        if (db.Delete("book", book, vec) != -1)
            return true;
        else
            return false;
    }else {
        return false;
    }
}

bool Utils::UpdateBook(Book before, Book after){
    if (CheckBookExist(before)){
        vector<string> vec;
        vec.push_back("not-all");
        vec.push_back("isbn");
        if (db.update("book", before, after, vec) != -1)
            return true;
        else
            return false;
    }else{
        return false;
    }
}

bool Utils::GetBookByIsbn(char* isbn,Book &book0) // 参数为图书isbn，返回包含该图书信息的图书对象
{
    Book book = Book();
    book.setIsbn(isbn);
    if (CheckBookExist(book))
    {
        vector<string> value;
        value.push_back("not-all");
        value.push_back("isbn");
        vector<Book> result;
        db.select("book", book, value, result);
        if(result.size() != 0){
            if(result[0].dirty==1){
                return false;
            }else{
                book0 = result[0];
                return true;
            }
        }else{return    false;}
    }
    else{
        return false;
    }
}

bool Utils::GetBooksByBookName(char* name, vector<Book>&result){
    vector<string> value;
    value.push_back("not-all");
    value.push_back("bookName");
    Book book = Book();
    book.setBookName(name);
    if (db.select("book", book, value, result) != -1)
        return true;
    else
        return false;
}

bool Utils::GetBooksByAuthor(char* author, vector<Book>&result){
    vector<string> value;
    value.push_back("not-all");
    value.push_back("author");
    Book book = Book();
    book.setAuthor(author);
    if (db.select("book", book, value, result) != -1)
        return true;
    else
        return false;
}

bool Utils::GetBooksByClassification(char* classification, vector<Book>&result){
    vector<string> value;
    value.push_back("not-all");
    value.push_back("classification");
    Book book = Book();
    book.setClassification(classification);
    if (db.select("book", book, value, result) != -1)
        return true;
    else
        return false;
}


int Utils::GetBookMargin(char* isbn){
    Book book = Book();
    GetBookByIsbn(isbn,book);
    return book.getLeft();
}


bool Utils::GetBookById(int id,Book &book0) {
    Book book = Book();
    book.setId(id);

    vector<string> value;
    value.push_back("not-all");
    value.push_back("id");
    vector<Book> result;
    db.select("book", book, value, result);
    if(result.size() != 0){
        if(result[0].dirty==1){
            return false;
        }
        book0 = result[0];
        return true;

    } else  {return false;}

}



bool Utils::InsertRecord(Record record){
    if (!CheckRecordExist(record)){
        vector<Record> entity;
        entity.push_back(record);
        if (db.insert("record", entity) != -1){
            return true;
        }else {
            return false;
        }
    }else {
        return false;
    }
}


bool Utils::DeleteRecord(Record record){
    if (CheckRecordExist(record)){
        vector<string> vec;
        vec.push_back("not-all");
        vec.push_back("isbn");
        vec.push_back("account");
        if (db.Delete("record", record, vec) != -1)
            return true;
        else
            return false;
    }else {
        return false;
    }
}

bool Utils::GetBookBorrowList(char* isbn,vector<Record>&result){

    Record record = Record();
    record.setIsbn(isbn);

    vector<string> value;
    value.push_back("not-all");
    value.push_back("isbn");

    db.select("record", record, value, result);

    if(result.empty()) return false;
    return true;

}
bool Utils::GetUserBorrowList(char* account,vector<Record>&result){

    Record record= Record();
    record.setAccount(account);

    vector<string> value;
    value.push_back("not-all");
    value.push_back("account");

    db.select("record", record, value, result);

    if(result.empty()) return false;
    return true;
}

bool Utils::GetRecord(char* account, char* isbn,Record &record0){
    Record record = Record();
    record.setAccount(account);
    record.setIsbn(isbn);

    if (CheckRecordExist(record))
    {
        vector<string> value;
        value.push_back("not-all");
        value.push_back("account");
        value.push_back("isbn");

        vector<Record> result;
        db.select("record", record, value, result);
        if(result.empty()){
            return false;
        }else{
            record0 = result[0];
            return true;
        }
    }
    else{
        return false;
    }

}

bool Utils::Return(char* account, char* isbn){
    Record record = Record();
    GetRecord(account,isbn,record);
    if(record.getAccount()[0]==account[0]&&record.getIsbn()[0]==isbn[0]){
        return DeleteRecord(record);
    }else return false;
}


bool Utils::UpdateRecord(Record before, Record after){
    if (CheckRecordExist(before)){
        vector<string> vec;
        vec.push_back("not-all");
        vec.push_back("account");
        vec.push_back("isbn");

        if (db.update("record", before, after, vec) != -1)
            return true;
        else
            return false;
    }else{
        return false;
    }
}


bool Utils::InsertReserve(Reserve reserve){
    // 如果这本书有记录了
    vector<string> value;
    value.push_back("not-all");
    value.push_back("isbn");

    Reserve temp= Reserve();
    temp.setIsbn(reserve.getIsbn());

    vector<Reserve> result;
    db.select("reserve", temp, value, result);
    if(!result.empty()) return false;

    //书籍剩余为0才能预约
    Book book = Book();
    GetBookByIsbn(reserve.getIsbn(),book);
    if(book.getLeft()!=0) return false;

    if (!CheckReserveExist(reserve)){
        vector<Reserve> vec;
        vec.push_back(reserve);
        if (db.insert("reserve", vec) != -1)
            return true;
        else
            return false;
    }else{
        return false;
    }
}


bool Utils::DeleteReserve(Reserve reserve){
    if (CheckReserveExist(reserve)){
        vector<string> vec;
        vec.push_back("not-all");
        vec.push_back("isbn");
        vec.push_back("account");
        if (db.Delete("reserve", reserve, vec) != -1)
            return true;
        else
            return false;
    }else {
        return false;
    }
}




bool Utils::GetReserve(char* account, char* isbn,Reserve &reserve0){
    Reserve reserve = Reserve();
    reserve.setAccount(account);
    reserve.setIsbn(isbn);

    if (CheckReserveExist(reserve))
    {
        vector<string> value;
        value.push_back("not-all");
        value.push_back("account");
        value.push_back("isbn");

        vector<Reserve> result;
        db.select("reserve", reserve, value, result);
        if(result.empty()){
            return false;
        }else{
            reserve0 = result[0];
            return  true;
        }
    }
    else{
        return false;
    }
}

bool Utils::PreAppoint(char* account, char* isbn){
    Reserve reserve = Reserve();
    GetReserve(account,isbn,reserve);

    if(reserve.getAccount()[0]==account[0]&&reserve.getIsbn()[0]==isbn[0]){
        return DeleteReserve(reserve);
    }else return false;
}

bool Utils::UpdateReserve(Reserve before, Reserve after){
    if (CheckReserveExist(before)){
        vector<string> vec;
        vec.push_back("not-all");
        vec.push_back("account");
        vec.push_back("isbn");

        if (db.update("reserve", before, after, vec) != -1)
            return true;
        else
            return false;
    }else{
        return false;
    }
}

bool Utils::GetReserveUser(char* isbn,Reserve &reserve0){
    Reserve reserve = Reserve();
    reserve.setIsbn(isbn);
    vector<string> value;
    value.push_back("not-all");
    value.push_back("isbn");
    vector<Reserve> result;

    db.select("reserve", reserve, value, result);

    if(result.empty()) return false;
    else{
        reserve0 = result[0];
        return true;
    }
}


bool Utils::GetUserReserveList(char * account,vector<Reserve>&result){
    Reserve reserve = Reserve();
    reserve.setAccount(account);

    vector<string> value;
    value.push_back("not-all");
    value.push_back("account");

    db.select("reserve", reserve, value, result);

    if(result.empty()) return false;
    return true;
}
