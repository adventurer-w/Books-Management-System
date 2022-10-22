#include "backend/addBooks.h"
#include<fstream>
#include<iostream>
#include<cstring>
#include <Windows.h>
#include "Utils.h"
#include <QDebug>
#include <QTime>
using namespace std;

extern Utils now_utils;

int num=0;

void addBooks(string origin,string cla) {
//    qDebug()<<QString::fromStdString(origin);
//    qDebug()<<cla;

    QList < int > list;
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    //姓氏
    string x[14] = { "赵", "钱", "孙", "李", "周", "吴", "郑", "王", "冯", "陈", "褚", "卫", "蒋", "沈" };
    //男性常用名
    string m1[140] = { "伟", "刚", "勇", "毅", "俊", "峰", "强", "军", "平", "保", "东", "文", "辉", "力", "明", "永", "健", "世", "广", "志", "义", "兴", "良", "海", "山", "仁", "波", "宁", "贵", "福", "生", "龙", "元", "全", "国", "胜", "学", "祥", "才", "发", "武", "新", "利", "清", "飞", "彬", "富", "顺", "信", "子", "杰", "涛", "昌", "成", "康", "星", "光", "天", "达", "安", "岩", "中", "茂", "进", "林", "有", "坚", "和", "彪", "博", "诚", "先", "敬", "震", "振", "壮", "会", "思", "群", "豪", "心", "邦", "承", "乐", "绍", "功", "松", "善", "厚", "庆", "磊", "民", "友", "裕", "河", "哲", "江", "超", "浩", "亮", "政", "谦", "亨", "奇", "固", "之", "轮", "翰", "朗", "伯", "宏", "言", "若", "鸣", "朋", "斌", "梁", "栋", "维", "启", "克", "伦", "翔", "旭", "鹏", "泽", "晨", "辰", "士", "以", "建", "家", "致", "树", "炎", "德", "行", "时", "泰", "盛" };
    //女性常用名
    string m2[165] = { "秀", "娟", "英", "华", "慧", "巧", "美", "娜", "静", "淑", "惠", "珠", "翠", "雅", "芝", "玉", "萍", "红", "娥", "玲", "芬", "芳", "燕", "彩", "春", "菊", "兰", "凤", "洁", "梅", "琳", "素", "云", "莲", "真", "环", "雪", "荣", "爱", "妹", "霞", "香", "月", "莺", "媛", "艳", "瑞", "凡", "佳", "嘉", "琼", "勤", "珍", "贞", "莉", "桂", "娣", "叶", "璧", "璐", "娅", "琦", "晶", "妍", "茜", "秋", "珊", "莎", "锦", "黛", "青", "倩", "婷", "姣", "婉", "娴", "瑾", "颖", "露", "瑶", "怡", "婵", "雁", "蓓", "纨", "仪", "荷", "丹", "蓉", "眉", "君", "琴", "蕊", "薇", "菁", "梦", "岚", "苑", "筠", "柔", "竹", "霭", "凝", "晓", "欢", "霄", "枫", "芸", "菲", "寒", "欣", "滢", "伊", "亚", "宜", "可", "姬", "舒", "影", "荔", "枝", "思", "丽", "秀", "飘", "育", "馥", "琦", "晶", "妍", "茜", "秋", "珊", "莎", "锦", "黛", "青", "倩", "婷", "宁","蓓", "纨", "苑", "婕", "馨", "瑗", "琰", "韵", "融", "园", "艺", "咏", "卿", "聪", "澜", "纯", "毓", "悦", "昭", "冰", "爽", "琬", "茗", "羽", "希" };


    string t, t2, s;
    int i=0, j;
    ifstream in("C:\\Users\\chp\\Desktop\\bookByPython\\"+origin+".txt", ios::in);
//    if(!in){
//        qDebug()<<"!!!";
//    }
    while (getline(in, s))
    {
//        qDebug()<<num<<"本";

        Book b;
        b.setBookName(s.c_str());
//                    qDebug()<<b.getBookName();
        s.clear();
        getline(in, s);
        b.setAuthor(s.c_str());
        s.clear();
        getline(in, s);
        b.setPublisher(s.c_str());
        s.clear();
        getline(in, s);
        if(s.size()==0)
            b.setPublishDate("未知");
        else
            b.setPublishDate(s.c_str());
        s.clear();
        getline(in, s);
        b.setIsbn(s.c_str());

        vector<BookClass> re;
        now_utils.GetClassByName(const_cast<char*>(cla.c_str()),re);
        b.setClassNo(re[0].getClassNo());

        //余量
        b.setLeft(qrand() % 20+3);


        //总数
        b.setAllNum(b.getLeft());

        b.setBoyHistoryNum(qrand() % 1000 + 20);

        b.setGirlHistoryNum(qrand() % 1000 + 20);

        //历史借阅数
        b.setHistoryNum(b.getBoyHistoryNum()+b.getGirlHistoryNum());
        //简介
        j = rand() % 50 + 20;
        for (int i = 0; i < j; i++)
        {
            if (rand() % 2 == 0)
                t += m1[qrand() % 140];
            else
                t += m2[qrand() % 165];
        }
        b.setIntroduction(t.c_str());

        //评分
        b.setPoint(float(qrand() % 800 + 200) / float(100));

        string tt(b.getIsbn());
        if(tt.size()==13){
            string imgpath=origin+"/"+tt+".jpg";
            b.setImgPath(imgpath.c_str());
            if(now_utils.InsertBook(b)){
                num++;
                if(num%100==0)
                    qDebug()<<num<<"成功";
            }
        }
    }
    in.close();
}
