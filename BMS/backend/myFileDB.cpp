#include"myFileDB.h"
#include<QDebug>

string myFileDB::getGuidelines()
{
    ifstream in(rootPath+"guidelines.txt");
    string s;
    string re;
    while(getline(in,s)){
        re+=s+"\n";
    }
    return re;
}

bool myFileDB::setGuidelines(string guidelines)
{
    ofstream out(rootPath+"guidelines.txt");
    if(out){
        out<<guidelines;
        return true;
    }else{
        return false;
    }
}
