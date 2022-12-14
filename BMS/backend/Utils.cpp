#include "Utils.h"
#include "all_head.h"
#include "length.h"
#include "MD5.h"
#include <algorithm>

using namespace std;

//！！！！密码用MD5储存！！！！
// 前端在传输数据之前需要使用MD5加密！

bool Utils::isName(string name){
    for(int i=0;i<name.size();i++){
        if(name[i]>='0'&&name[i]<='9'){
            return false;
        }
    }
    return true;
}

string Utils::getGuidelines(){
    return db.getGuidelines();
}

bool Utils::setGuidelines(string guidelines){
    return db.setGuidelines(guidelines);
}


int Utils::Login(char *account, char *password) { //密码需传入md5加密后的

//    if(account[0]=='0'&&account[1]=='0'){
//        return AdminLogin(account,password)+3;
//    }
//    else{
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
//    }
}

int Utils::Register(User user) {
    if(!CheckAccount(user.getAccount())) return -2;
//    if(user.getAccount()[0]=='0'&&user.getAccount()[1]=='0') return -2;
//    if(!CheckEmail(user.getEmail())) return -4;
//    if(!CheckUserExistByEmail(user.getEmail())) return -4;
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
//    if(!CheckUserExistByEmail(user.getEmail())) return false;
    if (!CheckUserExist(user)){
        vector<User> vec;
        vec.push_back(user);
        if (db.insert("user", vec) != -1){
            MyLog myLog = MyLog();
            myLog.setOptionId(11);
            myLog.setKey_1(user.getAccount());
            myLog.setKey_2(user.getEmail());

            vector<MyLog>  ett;
            ett.push_back(myLog);
            db.insert("log", ett);
            return true;
        }
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
        if (db.Delete("user", user, vec) != -1){
            MyLog myLog = MyLog();
            myLog.setOptionId(12);
            myLog.setKey_1(user.getAccount());

            vector<MyLog>  ett;
            ett.push_back(myLog);
            db.insert("log", ett);
            return true;
        }
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

bool Utils::CheckHistoryExist(Record record){
    vector<string> vec;
    vec.push_back("not-all");
    vec.push_back("account");
    vec.push_back("isbn");

    vector<Record> res;

    if (db.select("recordHistory", record, vec, res) != -1)
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
        db.select("user", user, value, result);
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




bool Utils::GetUserByDepartmentNo(int departmentNo, vector<User> &result){
    User user = User();
    user.setDepartmentNo(departmentNo);
    vector<string> val;
    val.push_back("not-all");
    val.push_back("departmentNo");
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
        db.select("user", admin, value, result);
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
        if(admin.getAccount()[0]!='0'||admin.getAccount()[1]!='0') return false;
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
            vector<SingleBook> books;
            SingleBook x = SingleBook();
            x.setIsbn(book.getIsbn());

            for(int i=0;i<=50&&i<book.getLeft();i++){
                books.push_back(x);
            }
            InsertSingleBooks(books);

            MyLog myLog = MyLog();
            myLog.setOptionId(21);
            myLog.setKey_1(book.getIsbn());


            vector<MyLog>  ett;
            ett.push_back(myLog);
            db.insert("log", ett);

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
        if (db.Delete("book", book, vec) != -1){
            MyLog myLog = MyLog();
            myLog.setOptionId(32);
            myLog.setKey_1(book.getIsbn());

            vector<MyLog>  ett;
            ett.push_back(myLog);
            db.insert("log", ett);
            return true;
        }

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

bool Utils::GetBooksByBookNameLike(char* name, vector<Book>&result){
    if (db.selectLike("book", "bookName", name, result) != -1)
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

bool Utils::GetBooksByAuthorLike(char* author, vector<Book>&result){
    if (db.selectLike("book", "author", author, result) != -1)
        return true;
    else
        return false;
}


bool Utils::GetUserByNameLike(char* name, vector<User>&result){
    if (db.selectLike("user", "name", name, result) != -1)
        return true;
    else
        return false;
}


bool Utils::GetBooksByClassNo(int classNo, vector<Book>&result){
    vector<string> value;
    value.push_back("not-all");
    value.push_back("classNo");
    Book book = Book();
    book.setClassNo(classNo);
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



bool Utils::GetAllBooks(vector<Book>&result){
    vector<string> value;
    value.push_back("all");
    Book book= Book();
    db.select("book", book, value, result);
    return true;
}


bool Utils::InsertRecord(Record record){
    if (!CheckRecordExist(record)){
        vector<Record> entity;
        entity.push_back(record);
        if (db.insert("record", entity) != -1){
            MyLog myLog = MyLog();
            myLog.setOptionId(31);
            myLog.setKey_1(record.getAccount());
            myLog.setKey_2(record.getIsbn());

            vector<MyLog>  ett;
            ett.push_back(myLog);
            db.insert("log", ett);

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
        if (db.Delete("record", record, vec) != -1){
            vector<Record> entity;
            entity.push_back(record);
            db.insert("recordHistory",entity);

            MyLog myLog = MyLog();
            myLog.setOptionId(32);
            myLog.setKey_1(record.getAccount());
            myLog.setKey_2(record.getIsbn());

            vector<MyLog>  ett;
            ett.push_back(myLog);
            db.insert("log", ett);

            return true;
        }else
            return false;
    }else {
        return false;
    }
}

bool Utils::GetAllDepartment(vector<Department> &result){
    vector<string> vec;
    vec.push_back("all");
    Department d =Department();

    if (db.select("department",d,vec, result) != -1)
        return true;
    else
        return false;
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

bool Utils::GetUserBorrowHistory(char* account,vector<Record>&result){

    Record record= Record();
    record.setAccount(account);

    vector<string> value;
    value.push_back("not-all");
    value.push_back("account");

    db.select("recordHistory", record, value, result);

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
        if (db.insert("reserve", vec) != -1){
            MyLog myLog = MyLog();
            myLog.setOptionId(31);
            myLog.setKey_1(reserve.getAccount());
            myLog.setKey_2(reserve.getIsbn());

            vector<MyLog>  ett;
            ett.push_back(myLog);
            db.insert("log", ett);

            return true;
        }
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
        if (db.Delete("reserve", reserve, vec) != -1){
            MyLog myLog = MyLog();
            myLog.setOptionId(32);
            myLog.setKey_1(reserve.getAccount());
            myLog.setKey_2(reserve.getIsbn());

            vector<MyLog>  ett;
            ett.push_back(myLog);
            db.insert("log", ett);
            return true;
        }
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


bool Utils::GetNewBookList(vector<Book>&result){
    Book book = Book();
    if(db.getAtBeginOf("book",result)==-1) return false;
    return true;
}


bool Utils::cmp_boy(Book a,Book b){
    return a.getBoyHistoryNum() > b.getBoyHistoryNum();
}


bool Utils::cmp_girl(Book a,Book b){
    return a.getGirlHistoryNum() > b.getGirlHistoryNum();
}


bool Utils::cmp_all(Book a,Book b){
    return a.getHistoryNum() > b.getHistoryNum();
}


bool Utils::cmp_point(Book a,Book b){
    return a.getPoint() > b.getPoint();
}



bool Utils::GetGirlRank(vector<Book>&result){
    return GetAnyRank("girl_rank",result);
}


bool Utils::UpdateGirlRank(){
    return UpdateAnyRank("girl_rank");
}


bool Utils::GetBoyRank(vector<Book>&result){
    return GetAnyRank("boy_rank",result);
}


bool Utils::UpdateBoyRank(){
    return UpdateAnyRank("boy_rank");
}

bool Utils::GetBookRank(vector<Book>&result){
    return GetAnyRank("book_rank",result);
}

bool Utils::UpdateBookRank(){
    return UpdateAnyRank("book_rank");
}


bool Utils::GetPointRank(vector<Book>&result){
    return GetAnyRank("point_rank",result);
}


bool Utils::UpdatePointRank(){
    return UpdateAnyRank("point_rank");
}


bool Utils::UpdateAnyRank(string DB_NAME){
    vector<Book> result;
    vector<string> value;
    value.push_back("all");
    Book book = Book();

    if (db.select("book", book, value, result) != -1){
        if(DB_NAME == "boy_rank") sort(result.begin(), result.end(), cmp_boy);
        if(DB_NAME == "girl_rank") sort(result.begin(), result.end(), cmp_girl);
        if(DB_NAME == "book_rank") sort(result.begin(), result.end(), cmp_all);
        if(DB_NAME == "point_rank") sort(result.begin(), result.end(), cmp_point);

        Book rank_t = Book();
        if (db.Delete(DB_NAME, rank_t, value) != -1){
            vector<Book> insert_list;
            for (int i = 0 ; i < result.size() && i< 10; i ++) {
                Book rank = result.at(i);
                insert_list.push_back(rank);
            }
            if (db.insert(DB_NAME, insert_list) != -1)
                return true;
            else
                return false;
        }else{
            return false;
        }
    }

    return false;
}

bool Utils::GetAnyRank(string DB_NAME,vector<Book>&result){
    Book rank_t;
    vector<string> value;
    value.push_back("all");
    vector<Book> result_rank;

    int pos = db.select(DB_NAME, rank_t, value, result_rank);
    if (pos != -1){
        Book book = Book();
        for (int i = 0; i < result_rank.size(); i ++ )
        {
            GetBookByIsbn(result_rank.at(i).getIsbn(),book);
            result.push_back(book);
        }
        return true;
    }
    else
        return false;
}

bool Utils::CheckDepartmentExistByNo(int departmentNo){
    vector<string> value;
    value.push_back("not-all");
    value.push_back("departmentNo");
    Department department = Department();
    department.setDepartmentNo(departmentNo);

    vector<Department> result;
    if (db.select("department", department, value, result) == -1)
        return false;
    return true;
}

bool Utils::CheckDepartmentExistByName(char *name){
    vector<string> value;
    value.push_back("not-all");
    value.push_back("name");
    Department department = Department();
    department.setName(name);

    vector<Department> result;
    if (db.select("department", department, value, result) == -1)
        return false;
    return true;
}

bool Utils::CheckClassExistByNo(int classNo){
    vector<string> value;
    value.push_back("not-all");
    value.push_back("classNo");
    BookClass bookClass = BookClass();
    bookClass.setClassNo(classNo);

    vector<BookClass> result;
    if (db.select("bookClass", bookClass, value, result) == -1)
        return false;
    return true;
}

bool Utils::CheckClassExistByName(char *name){
    vector<string> value;
    value.push_back("not-all");
    value.push_back("name");
    BookClass bookClass = BookClass();
    bookClass.setName(name);

    vector<BookClass> result;
    if (db.select("bookClass", bookClass, value, result) == -1)
        return false;
    return true;
}


bool Utils::ChangeClassByNo(BookClass before, BookClass after){
    if (CheckClassExistByNo(before.classNo)){
        vector<string> vec;
        vec.push_back("not-all");
        vec.push_back("classNo");

        if (db.update("bookClass", before, after, vec) != -1)
            return true;
        else
            return false;
    }else{
        return false;
    }
}


bool Utils::CheckUserExistByEmail(char *email){
    vector<string> value;
    value.push_back("not-all");
    value.push_back("email");
    User user = User();
    user.setEmail(email);

    vector<User> result;
    if (db.select("user", user, value, result) == -1)
        return false;
    return true;
}

bool Utils::InsertDepartment(Department department){
    if (!CheckDepartmentExistByName(department.getName()) && !CheckDepartmentExistByNo(department.getDepartmentNo())){
        vector<Department> vec;
        vec.push_back(department);
        if (db.insert("department", vec) != -1)
            return true;
        else
            return false;
    }else{
        return false;
    }
}

bool Utils::DeleteDepartment(Department department){
    if (CheckDepartmentExistByName(department.getName())){
        vector<string> vec;
        vec.push_back("not-all");
        vec.push_back("name");
        if (db.Delete("department", department, vec) != -1)
            return true;
        else
            return false;
    }else {
        return false;
    }
}

bool Utils::GetDepartmentByNo(int departmentNo,vector<Department> &result){
    Department department = Department();
    department.setDepartmentNo(departmentNo);

    vector<string> val;
    val.push_back("not-all");
    val.push_back("departmentNo");
    if (db.select("department", department, val, result) != -1)
        return true;
    else
        return false;
}

bool Utils::GetDepartmentByName(char* name,vector<Department> &result){
    Department department = Department();
    department.setName(name);

    vector<string> val;
    val.push_back("not-all");
    val.push_back("name");
    if (db.select("department", department, val, result) != -1)
        return true;
    else
        return false;
}


bool Utils::InsertSingleBooks(vector<SingleBook> entity){
    if (db.insert("singleBook", entity) != -1){
        return true;
    }else {
        return false;
    }
}


bool Utils::DeleteSingleBook(SingleBook singleBook){
    vector<string> vec;
    vec.push_back("not-all");
    vec.push_back("id");
    if (db.Delete("singleBook", singleBook, vec) != -1)
        return true;
    else
        return false;
}

bool Utils::BorrowSingleBook(SingleBook singleBook){
    if(singleBook.dirty==2){
        vector<string> vec;
        vec.push_back("not-all");
        vec.push_back("id");
        if (db.Delete("singleBook", singleBook, vec) != -1)
            return true;
        else
            return false;
    }
    return true;
}

bool Utils::ReturnSingleBook(SingleBook singleBook){
    if(singleBook.dirty==2){
        vector<string> vec;
        vec.push_back("not-all");
        vec.push_back("id");
        if (db.Delete("singleBook", singleBook, vec) != -1)
            return true;
        else
            return false;
    }
    return true;
}




bool Utils::InsertClass(BookClass bookClass) {
    if (!CheckClassExistByName(bookClass.getName()) && !CheckClassExistByNo(bookClass.getClassNo())){
        vector<BookClass> vec;
        vec.push_back(bookClass);
        if (db.insert("bookClass", vec) != -1)
            return true;
        else
            return false;
    }else{
        return false;
    }
}

bool Utils::DeleteClass(BookClass bookClass) {
    if (CheckClassExistByName(bookClass.getName())){
        vector<string> vec;
        vec.push_back("not-all");
        vec.push_back("name");
        if (db.Delete("bookClass", bookClass, vec) != -1)
            return true;
        else
            return false;
    }else {
        return false;
    }
}

bool Utils::GetClassByNo(int classNo,vector<BookClass> &result){
    BookClass bookClass = BookClass();
    bookClass.setClassNo(classNo);

    vector<string> val;
    val.push_back("not-all");
    val.push_back("classNo");
    if (db.select("bookClass", bookClass, val, result) != -1)
        return true;
    else
        return false;
}

bool Utils::GetClassByName(char* name,vector<BookClass> &result){
    BookClass bookClass = BookClass();
    bookClass.setName(name);

    vector<string> val;
    val.push_back("not-all");
    val.push_back("name");
    if (db.select("bookClass", bookClass, val, result) != -1)
        return true;
    else
        return false;
}

bool Utils::GetAllClass(vector<BookClass> &result){
    vector<string> vec;
    vec.push_back("all");
    BookClass d =BookClass();

    if (db.select("bookClass",d,vec, result) != -1)
        return true;
    else
        return false;
}


bool Utils::CheckAccount(char *account){
    regex reg("^[0-9]{6,11}$");
    return regex_match(account, reg);
}
bool Utils::CheckPassword(char *password){
    regex reg("^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)[^]{6,30}$");
//    regex reg(^(?!_)(?!.*?_$)[a-zA-Z0-9_]+$
//    regex reg("[0-9]+|[a-z]+|[A-Z]+{6,30}$");
    return regex_match(password, reg);
}
bool Utils::CheckPassword2(char *password){
    regex reg("^(?!_)(?!.*?_$)[a-zA-Z0-9_]+$");
    return regex_match(password, reg);
}
bool Utils::CheckEmail(char *email){
    regex reg("^[a-zA-Z0-9_-]+@[a-zA-Z0-9_-]+(\\.[a-zA-Z0-9_-]+)+$");
    return regex_match(email, reg);
}
