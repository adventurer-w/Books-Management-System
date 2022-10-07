#include<fstream>
#include<iostream>
#include<cstring>
#include <Windows.h>
#include "User.h"
#define iRange1  (0xf7 - 0xb0)
#define iRange2  (0xfe - 0xa1)
#include "MD5.h"
#include "Utils.h"
#include <QDebug>
using namespace std;

extern Utils now_utils;

//姓氏
string x[14] = { "赵", "钱", "孙", "李", "周", "吴", "郑", "王", "冯", "陈", "褚", "卫", "蒋", "沈"};
//男性常用名
string m1[140] = { "伟", "刚", "勇", "毅", "俊", "峰", "强", "军", "平", "保", "东", "文", "辉", "力", "明", "永", "健", "世", "广", "志", "义", "兴", "良", "海", "山", "仁", "波", "宁", "贵", "福", "生", "龙", "元", "全", "国", "胜", "学", "祥", "才", "发", "武", "新", "利", "清", "飞", "彬", "富", "顺", "信", "子", "杰", "涛", "昌", "成", "康", "星", "光", "天", "达", "安", "岩", "中", "茂", "进", "林", "有", "坚", "和", "彪", "博", "诚", "先", "敬", "震", "振", "壮", "会", "思", "群", "豪", "心", "邦", "承", "乐", "绍", "功", "松", "善", "厚", "庆", "磊", "民", "友", "裕", "河", "哲", "江", "超", "浩", "亮", "政", "谦", "亨", "奇", "固", "之", "轮", "翰", "朗", "伯", "宏", "言", "若", "鸣", "朋", "斌", "梁", "栋", "维", "启", "克", "伦", "翔", "旭", "鹏", "泽", "晨", "辰", "士", "以", "建", "家", "致", "树", "炎", "德", "行", "时", "泰", "盛" };
//女性常用名
string m2[165] = { "秀", "娟", "英", "华", "慧", "巧", "美", "娜", "静", "淑", "惠", "珠", "翠", "雅", "芝", "玉", "萍", "红", "娥", "玲", "芬", "芳", "燕", "彩", "春", "菊", "兰", "凤", "洁", "梅", "琳", "素", "云", "莲", "真", "环", "雪", "荣", "爱", "妹", "霞", "香", "月", "莺", "媛", "艳", "瑞", "凡", "佳", "嘉", "琼", "勤", "珍", "贞", "莉", "桂", "娣", "叶", "璧", "璐", "娅", "琦", "晶", "妍", "茜", "秋", "珊", "莎", "锦", "黛", "青", "倩", "婷", "姣", "婉", "娴", "瑾", "颖", "露", "瑶", "怡", "婵", "雁", "蓓", "纨", "仪", "荷", "丹", "蓉", "眉", "君", "琴", "蕊", "薇", "菁", "梦", "岚", "苑", "筠", "柔", "竹", "霭", "凝", "晓", "欢", "霄", "枫", "芸", "菲", "寒", "欣", "滢", "伊", "亚", "宜", "可", "姬", "舒", "影", "荔", "枝", "思", "丽", "秀", "飘", "育", "馥", "琦", "晶", "妍", "茜", "秋", "珊", "莎", "锦", "黛", "青", "倩", "婷", "宁","蓓", "纨", "苑", "婕", "馨", "瑗", "琰", "韵", "融", "园", "艺", "咏", "卿", "聪", "澜", "纯", "毓", "悦", "昭", "冰", "爽", "琬", "茗", "羽", "希" };
//专业名
string major[20]={"电子信息科学与技术","电子工程系","电子信息工程","通信工程 ","微电子科学与工程 ","智能科学与技术 ","数据科学与大数据 ","网络空间安全"
                  ,"计算机科学与技术 ","保密管理","会计学 ","会计学（ACCA） ","财务管理 ","市场营销 ","电子商务","英语 ","日语 ","朝鲜语 ","法语 ","德语"} ;
string question[5]={"你的真实姓名是？","你的小学班主任叫什么?","你现在从事的职业是？","你的理想工作是？","你的生日是？"};

void insert()
{
    User u;
    string t;
    int i,j,k;

    //id

    //name
    t=x[rand()%14];
    j=rand()%2+1;
    for (i=0;i<j;i++)
    {
        if(rand()%2==0)
            t+=m1[rand()%140];
        else
            t+=m2[rand()%165];
    }
    strcpy(u.name,t.data());
    t.clear();

    //账号（学号）
    for(i=0;i<ACCOUNT_SIZE-1;i++)
        t+=to_string(rand()%10);
    strcpy(u.account,t.data());
    qDebug()<<QString::fromStdString(t)<<" ";
    string ta=t;
    t.clear();


    //密码
    j=rand()%8+8;
    for(i=0;i<j;i++){
        k=rand()%3;
        if(k==0){
            t+=char(rand()%10+48);
        }else if(k==1){
            t+=char(rand()%26+65);
        }else{
            t+=char(rand()%26+97);
        }
    }
    qDebug()<<QString::fromStdString(t);
    MD5 md5;
    string t1="sdgvsdv";
    const char* tt=md5.read(t1);
    char* pwd2=const_cast<char*>(tt);
    qDebug()<<QString::fromStdString(tt)<<"\n";
    u.setPassword(pwd2);
    t.clear();

    //性别
    u.sex=rand()%2+1;//1男 2女

    //专业
    t=major[rand()%20];
    strcpy(u.major,t.data());

    //密保问题
    t=question[rand()%5];
    strcpy(u.security_question,t.data());

    //密保答案
    j=rand()%20+3;
    for (i=0;i<j;i++)
    {
        if(rand()%2==0)
            t+=m1[rand()%140];
        else
            t+=m2[rand()%165];
    }
    strcpy(u.security_answer,t.data());
    t.clear();

    //借书数目
    u.num_borrowed=rand()%6;

    //预约数
    u.num_appointed=rand()%3;

    //欠款数
    u.debet=rand()%50;

    now_utils.Register(u);
    User u2;
    now_utils.GetUserByAccount(u.account,u2);
    qDebug()<<QString::fromStdString(u2.getName());
    qDebug()<<QString::fromStdString(u2.getAccount());
    qDebug()<<QString::fromStdString(u2.getPassword());
    qDebug()<<QString::fromStdString(u2.getSecurityQuestion());

}


