#ifndef LENGTH_H
#define LENGTH_H
using namespace std;
static const int ACCOUNT_SIZE = 12 + 1;           //账号（学号）长度
static const int PASSWORD_SIZE = 50 + 1;          //密码长度
static const int USER_NAME_SIZE = 50 + 1;         //昵称长度
static const int MAJOR_SIZE = 50 + 1;             //专业名长度
static const int SECURITY_ANSWER_SIZE = 200 + 1;             //密保问题
static const int SECURITY_QUESTION_SIZE = 200 + 1;             //密保答案
static const int EMAIL_SIZE =  100 + 1;//邮箱长度

static const int KEY_SIZE = 100 + 1; //主码长度
static const int VAL_SIZE = 100 + 1;

static const int ISBN_SIZE = 20 + 1;             //ISBN号长度
static const int BOOK_NAME_SIZE = 100 + 1;       //书名
static const int AUTHOR_SIZE = 100 + 1;          //作者名
static const int PUBLISHER_SIZE = 100 + 1;       //出版社长度
static const int INTRODUCTION_SIZE = 2000 + 1;   //书籍简介
static const int CLASSIFICATION_SIZE = 200 + 1;  //分类
static const int IMAGE_PATH = 1000 + 1;//图书封面路径

static const int DATE_SIZE = 50 + 1;    //日期长度 格式 yyyy-mm-dd HH:mm

#endif //LENGTH_H
