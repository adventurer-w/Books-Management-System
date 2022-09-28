#ifndef UTILS_H
#define UTILS_H
#include "all_head.h"
#include <vector>
#include "myfiledb.h"

class Utils {
public:

    myFileDB db;
    Utils(string path) : db(path) {}

    //登录
    int Login(char* account, char* password); //参数1:账号，参数2:密码。返回值：0:账户不存在；1:登陆成功；2:密码错误

    //注册
    int Register(User user); //参数：用户对象。返回值：0:账号已存在，1:注册成功, -1：注册失败


    //修改信息
    bool UpdateUser(User before, User after); //参数1为需要修改的User对象，参数2为修改后的User对象，返回修改操作是否成功


    //获取推荐列表
    bool GetRecommendList(User user, vector<Book>&result); //参数1为User对象,参数2为存结果列表，返回值为该用户的推荐书目列表


    //获取借书列表
    bool GetRecordList(User user, vector<Book>&result); //参数1为User对象，参数2为存结果列表，返回该用户的正在借书列表


    //获取预约列表
    bool GetReserveList(User user, vector<Book>&result); //参数1为User对象，参数2为存结果列表，返回该用户预约的图书列表


    //登录
    int AdminLogin(char* account, char* password);  //参数1:账号，参数2:密码。返回值：0:账户不存在；1:登陆成功；2:密码错误


    //还款
    bool Repayment(User user); //参数为用户对象，返回是否成功


    //管理员注册
    int AdminRegister(Admin admin); //参数：管理员对象。返回值：0:账号已存在，1:注册成功, -1：注册失败


    //添加学生
    bool InsertUser(User user); //参数：User对象，进行插入操作，返回是操作是否成功


    //添加书
    bool InsertBook(Book book); //参数：Book对象，进行插入操作，返回是操作是否成功


    //添加借书关系
    bool InsertRecord(Record record); //参数：Record对象，进行插入操作，返回是操作是否成功


    //添加预约关系
    bool InsertReserve(Reserve reserve); //参数：Reserve对象，进行插入操作，返回是操作是否成功


    //删除学生
    bool DeleteUser(User user); //参数：User对象，返回是操作是否成功


    //删除书
    bool DeleteBook(Book book); //参数：Book对象，进行插入操作，返回是操作是否成功


    //删除借书关系
    bool DeleteRecord(Record record); //参数：Record对象，返回是操作是否成功


    //删除预约关系
    bool DeleteReserve(Reserve reserve); //参数：Reverse对象，返回是操作是否成功


    //根据ISBN获取图书
    Book GetBookbyIsbn(char* isbn); //参数为图书isbn，返回该isbn对应的图书对象


    //根据id获取图书
    Book GetBookbyId(char* id); //参数为图书id，返回该id对应的图书对象


    //修改图书信息
    bool UpdateBook(Book before, Book after); //参数1为需要修改的Book对象，参数2为修改后的Book对象，返回修改操作是否成功


    //按书名找书
    bool GetBooksByBookName(char* name, vector<Book>&result); //参数1为图书名，参数2为存结果列表，操作为根据书名检索图书，返回操作是否成功


    //按作者找书
    bool GetBooksByAuthor(char* author, vector<Book>&result); //参数1为作者名，参数2为存结果列表，操作为根据作者名检索图书，返回操作是否成功


    //按分区找书
    bool GetBooksByClassificationId(int classification_id, vector<Book>&result); //参数1为分区id，参数2为存结果列表，操作为根据分区id检索图书，返回操作是否成功的结果


    //由名字筛选用户
    bool GetUserByName(char* name, vector<User>&result);

    //由名字筛选用户
    User GetUserByAccount(char* account);


    //由专业筛选用户
    bool GetUserByMajor(char* major, vector<User>&result);


    //查找借书
    Record GetRecord(char* account, char* id);//参数1学生账号，参数2图书id，返回唯一的Record对象


    //查找预约
    Record GetReserve(char* account, char* id);//参数1学生账号，参数2图书id，返回唯一的Reverse对象


    //修改借书信息
    bool UpdateRecord(Record before, Record after);//参数1为需要修改的Record对象，参数2为修改后的Record对象，返回修改操作是否成功


    //修改预约信息
    bool UpdateReserve(Reserve before, Reserve after);//参数1为需要修改的Reverse对象，参数2为修改后的Reverse对象，返回修改操作是否成功


    //查看该书余量
    int GetBookMargin(char* id);//参数1为图书id，返回该书还有多少没有被借走


    //查看借书用户
    User GetBorrowUser(Book book, int book_id); //参数1为图书对象，参数2为单本Id,返回借阅这本书的用户


    //借书
    bool Borrow(User user, Book book); //参数1:借书者用户，参数2:所借图书（需满足有余量），返回操作是否成功


    //还书
    bool Return(User user, Book book); //参数1:还书者用户，参数2:所还图书唯一编号，返回操作是否成功


    //预约
    bool Appoint(User user, Book book); //参数1:预约者用户，参数2:所预约图书,返回操作是否成功，需满足：剩余量为0且无人预约


    //取消预约
    bool PreAppoint(User user, Book book); //参数1:取消预约者用户，参数2:所取消预约图书,返回操作是否成功



    bool CheckUserExist(User user);//该对象只需要有只需填账号（学号）


    bool CheckBookExist(Book book);//该对象只需要有ISBN


    bool CheckRecordExist(Record record);//该对象只需要有学号和ISBN号


    bool CheckReserveExist(Reserve reserve); //该对象只需要有学号和ISBN号

};


#endif //UTILS_H
