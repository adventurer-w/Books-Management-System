#ifndef UTILS_H
#define UTILS_H
#include "all_head.h"
#include "myFileDB.h"
#include "BookClass.h"
#include <regex>

class Utils {
public:
    //登录
    myFileDB db;
    Utils(string path) : db(path) {}

    //用正则表达式判断是否合法
    bool CheckAccount(char *account);
    bool CheckPassword(char *password);
    bool CheckEmail(char *email);


    string getGuidelines();
    bool setGuidelines(string guidelines);

    int Login(char* account, char* password); //参数1:账号，参数2:密码。   返回值：0:账户不存在； 2:登陆成功；1:密码错误

    //注册
    int Register(User user); //参数：用户对象。    返回值：0:账号已存在，1:注册成功, -1：注册失败,-2用户名不合法，-3密码不合法，-4邮箱不合法

    //修改信息
    bool UpdateUser(User before, User after); //参数1为需要修改的User对象（只需要有学号），参数2为修改后的User对象，返回修改操作是否成功

    //由名字筛选用户
    bool GetUserByName(char* name, vector<User>&result);

    //由名字筛选用户
    bool GetUserByAccount(char* account,User& user0);

    //由id筛选用户,速度最快建议首选
    bool GetUserById(int id,User& user0);

    //由专业筛选用户
    bool GetUserByDepartmentNo(int departmentNo, vector<User>&result);

    //删除学生
    bool DeleteUser(User user); //参数：User对象，返回是操作是否成功

    //还款
    bool Repayment(User user); //参数为用户对象，返回是否成功

    //添加学生
    bool InsertUser(User user); //参数：User对象，进行插入操作，返回是操作是否成功

    //添加院系
    bool InsertDepartment(Department department);

    //删除院系(依据名称检索)
    bool DeleteDepartment(Department department);

    //用departmentNo获取Department对象（只有一个，对象中有院系名）
    bool GetDepartmentByNo(int departmentNo,vector<Department> &result);

    //用院系名获取Department对象（只有一个,对象中有departmentNo）
    bool GetDepartmentByName(char *name,vector<Department> &result);


    //获取所有系
    bool GetAllDepartment(vector<Department> &result);

    //管理员登录
    int AdminLogin(char* account, char* password);  //参数1:账号，参数2:密码。返回值：0:账户不存在；1:登陆成功；2:密码错误

    //由名字筛选管理员
    bool GetAdminByName(char* name, vector<Admin>&result);

    //由账号筛选管理员
    Admin GetAdminByAccount(char* account);

    //管理员注册
    int AdminRegister(Admin admin); //参数：管理员对象。返回值：0:账号已存在，1:注册成功, -1：注册失败

    //添加管理员
    bool InsertAdmin(Admin admin); //参数：管理员对象，进行插入操作，返回是操作是否成功







    //添加书的种类（！！注意！！增加书的数量请用UpdateBook）
    bool InsertBook(Book book); //参数：Book对象，进行插入操作，返回是操作是否成功

    //删除书
    bool DeleteBook(Book book); //参数：Book对象，只需要有isbn号，进行插入操作，返回是操作是否成功

    //修改图书信息
    bool UpdateBook(Book before, Book after); //参数1为需要修改的Book对象（只需要有isbn号），参数2为修改后的Book对象，返回修改操作是否成功

    //根据ISBN获取图书
    bool GetBookByIsbn(char* isbn,Book &book0); //参数为图书isbn，返回该isbn对应的图书对象

    //按书名找书
    bool GetBooksByBookName(char* name, vector<Book>&result); //参数1为图书名，参数2为存结果列表，操作为根据书名检索图书，返回操作是否成功

    //按作者找书
    bool GetBooksByAuthor(char* author, vector<Book>&result); //参数1为作者名，参数2为存结果列表，操作为根据作者名检索图书，返回操作是否成功

    //按分区号找书
    bool GetBooksByClassNo(int classNo, vector<Book>&result); //参数1为分区id，参数2为存结果列表，操作为根据分区id检索图书，返回操作是否成功的结果

    //查看该书余量
    int GetBookMargin(char* isbn);//参数1为图书isbn，返回该书还有多少没有被借走

    //由id筛选书,速度最快建议首选
    bool GetBookById(int id,Book &book0); //参数为图书id，返回该id对应的图书对象

    //获取所有数
    bool GetAllBooks(vector<Book>&result);

    //插入单本书
    bool InsertSingleBooks(vector<SingleBook> entity);

    //删除单本书
    bool DeleteSingleBook(SingleBook singleBook);

    //借走单本书
    bool BorrowSingleBook(SingleBook singleBook);

    //归还单本书
    bool ReturnSingleBook(SingleBook singleBook);







    //添加分类
    bool InsertClass(BookClass bookClass);

    //删除分类(依据名称检索)
    bool DeleteClass(BookClass bookClass);

    //用classNo获取BookClass对象
    bool GetClassByNo(int classNo,vector<BookClass> &result);

    //用类别名获取BookClass对象
    bool GetClassByName(char *name,vector<BookClass> &result);

    //获取所有分类
    bool GetAllClass(vector<BookClass> &result);





    //添加借书关系
    bool InsertRecord(Record record); //参数：Record对象，进行插入操作，返回是操作是否成功

    //删除借书关系
    bool DeleteRecord(Record record); //参数：Record对象，返回是操作是否成功

    //返回关于这本书的借阅记录
    bool GetBookBorrowList(char* isbn,vector<Record>&result);

    //返回用户的借书记录
    bool GetUserBorrowList(char * account,vector<Record>&result);

    //查找借书
    bool GetRecord(char* account, char* isbn,Record &record0);//参数1学生账号，参数2图书isbn，返回唯一的Record对象

    //还书
    bool Return(char* account, char* isbn);

    //修改借书信息
    bool UpdateRecord(Record before, Record after);//参数1为需要修改的Record对象，参数2为修改后的Record对象，返回修改操作是否成功

    //获取新书列表（返回最多50本）
    bool GetNewBookList(vector<Book>&result);

    //返回用户的历史借书
    bool GetUserBorrowHistory(char * account,vector<Record>&result);









    //获取总排行榜（前50）
    bool GetBookRank(vector<Book>&result);

    //更新总排行榜
    bool UpdateBookRank();

    //获取男生排行榜（前50）
    bool GetBoyRank(vector<Book>&result);

    //更新男生排行榜
    bool UpdateBoyRank();

    //获取女生排行榜（前50）
    bool GetGirlRank(vector<Book>&result);

    //更新女生排行榜
    bool UpdateGirlRank();

    //获取高分榜（前50）
    bool GetPointRank(vector<Book>&result);

    //更新高分榜
    bool UpdatePointRank();

    //前端不要调用！ 更新某个排行榜
    bool UpdateAnyRank(string DB_NAME);

    //前端不要调用！ 获得某个排行榜
    bool GetAnyRank(string DB_NAME,vector<Book>&result);

    //前端不要调用！
    bool static cmp_boy(Book a,Book b);

    //前端不要调用！
    bool static cmp_girl(Book a,Book b);

    //前端不要调用！
    bool static cmp_all(Book a,Book b);

    //前端不要调用！
    bool static cmp_point(Book a,Book b);




    //(！！需要没人预约且无人预约,否则会返回失败!!)
    bool InsertReserve(Reserve reserve); //参数：Reserve对象，进行插入操作，返回是操作是否成功

    //删除预约关系
    bool DeleteReserve(Reserve reserve); //参数：Reserve对象(只需要account 和 ISBN)，返回是操作是否成功

    //取消预约
    bool PreAppoint(char* account, char* isbn); //参数1:取消预约者用户，参数2:所取消预约图书,返回操作是否成功

    //查找预约
    bool GetReserve(char* account, char* isbn,Reserve &reserve0);//参数1学生账号，参数2图书id，返回唯一的Reserve对象

    //修改预约信息
    bool UpdateReserve(Reserve before, Reserve after);//参数1为需要修改的Reserve对象，参数2为修改后的Reserve对象，返回修改操作是否成功

    //返回预约这本书的人，如果没有，返回FALSE
    bool GetReserveUser(char* isbn,Reserve &reserve0);

    //返回用户的所有预约记录
    bool GetUserReserveList(char * account,vector<Reserve>&result);






    //获取推荐列表
    bool GetRecommendList(User user, vector<Book>&result); //参数1为User对象,参数2为存结果列表，返回值为该用户的推荐书目列表




    bool CheckUserExist(User user);//该对象只需要有只需填账号（学号）

    bool CheckUserExistByEmail(char *email);

    bool CheckAdminExist(Admin admin);//该对象只需要有只需填账号

    bool CheckBookExist(Book book);//该对象只需要有ISBN

    bool CheckRecordExist(Record record);//该对象只需要有学号和ISBN号

    bool CheckHistoryExist(Record record);//该对象只需要有学号和ISBN号

    bool CheckReserveExist(Reserve reserve); //该对象只需要有学号和ISBN号

    bool CheckDepartmentExistByNo(int departmentNO); //查看该departmentNO的记录是否存在

    bool CheckDepartmentExistByName(char *name); //查看该name的记录是否存在

    bool CheckClassExistByNo(int classNo); //查看该departmentNO的记录是否存在

    bool CheckClassExistByName(char *name); //查看该name的记录是否存在
};


#endif //UTILS_H

//int select(string DB_NAME, T &entity, vector<string> &VALUES, vector<T> &resultSet);
//int selectLike(string DB_NAME, string valueName, char *value, vector<T> &resultSet);
//int insert(string DB_NAME, vector<T> &entity);
//int Delete(string DB_NAME, T &entity, vector<string> &VALUES);
//int update(string DB_NAME, T &Sentity, T &Uentity, vector<string> &VALUES);


//！！！！密码用MD5储存！！！！
// 前端在传输数据之前需要使用MD5加密！

