#ifndef MYFILEDB_H
#define MYFILEDB_H

#include<iostream>
#include<cstring>
#include<vector>
#include<fstream>

using namespace std;

class myFileDB {
private:
    string rootPath;
public:
    myFileDB(string path) {
        rootPath = path;
    }


    //在fileName.dat文件中选择对应表单  对应实体为T  查询的字段为value

    /*
    * 选择所有：value[0]=="all"
    * 根据单项属性值选择：value[0]!="all"，并且value[1]置为对应查询的属性如id
    * 根据多项属性值选择：如：value[1] value[2] 分别表示id、name等多个匹配
    */

    template<typename T>
    int select(string fileName, T &entity, vector<string> &value, vector<T> &result) {
        ifstream readFile;
        try {
            T tem;
            int tsize = sizeof(tem);

            string Filepath = rootPath + fileName + ".dat";
            readFile.open(Filepath.c_str(), ios::in | ios::out | ios::binary);

            if (!readFile) {
                ios_base::failure fail("error");
                throw fail;
            }

            if (value[0] == "all") {
                while (readFile.read(reinterpret_cast<char *>(&tem), tsize)) {
                    if (!tem.getflag())
                        result.push_back(tem);
                }
            } else {
                if (value.size() == 2) {
                    if (value[1] == "id") {
                        selectId(readFile, entity.getId(), result);
                    } else {
                        string type_name = tem.getElemType(value[1]);
                        if (type_name == "float")
                            selectFloat(readFile, value[1], entity.getIntElemByName(value[1]), result);
                        else if (type_name == "int")
                            selectint(readFile, value[1], entity.getFloatElemByName(value[1]), result);
                        else
                            selectChars(readFile, value[1], entity.getCharElemByName(value[1]), result);
                    }
                } else {
                    selectMany(readFile, entity, value, result);
                }
            }

            readFile.close();
            if (result.size() == 0)return -1; //没找到
            return result.size();
        } catch (ios_base::failure &fail) {
            cout << fail.what() << endl;
            return -1;
        }
    }


    template<typename T>
    void selectInt(ifstream &readFile, string valueName, int value, vector<T> &result) {
        T temp;
        int tsize = sizeof(T);
        while (readFile.read(reinterpret_cast<char *>(&temp), tsize)) {
            if (!temp.getflag() && temp.getIntElemByName(valueName) == value) {
                result.push_back(temp);
            }
        }
    }


    template<typename T>
    void selectFloat(ifstream &readFile, string valueName, float value, vector<T> &result) {
        T temp;
        int tsize = sizeof(T);
        while (readFile.read(reinterpret_cast<char *>(&temp), tsize)) {
            if (!temp.getflag() && temp.getFloatElemByName(valueName) == value) {
                result.push_back(temp);
            }
        }
    }


    template<typename T>
    void selectChars(ifstream &readFile, string valueName, char *value, vector<T> &result) {
        T temp;
        int tsize = sizeof(T);
        while (readFile.read(reinterpret_cast<char *>(&temp), tsize)) {
            if (!temp.getflag() && !strcmp(temp.getCharElemByName(valueName), value)) {
                result.push_back(temp);
            }
        }
    }

    template<typename T>
    void selectId(ifstream &readFile, int id, vector<T> &result) {
        T tem;
        readFile.seekg(id * sizeof(tem), ios::beg);
        readFile.read(reinterpret_cast<char *>(&tem), sizeof(tem));
        if (!tem.getflag())
            result.push_back(tem);
    }

    template<typename T>
    void selectMuch(ifstream &readFile, T &entity, vector<string> &value, vector<T> &result) {
        T tem;
        int tsize = sizeof(T);

        vector<string> ElemType;
        vector<int> IntValue;
        vector<float> floatValue;
        vector<char *> charValue;

        for (int i = 1; i < value.size(); i++) {
            ElemType.push_back(entity.getElemType(value[i]));
            if (ElemType[i - 1] == "int") {
                IntValue.push_back(entity.getIntElemByName(value[i]));
                floatValue.push_back(0);
                charValue.push_back((char *) "");
            } else if (ElemType[i - 1] == "float") {
                floatValue.push_back(entity.getFloatElemByName(value[i]));
                IntValue.push_back(0);
                charValue.push_back((char *) "");
            } else {
                charValue.push_back(entity.getCharElemByName(value[i]));
                floatValue.push_back(0);
                IntValue.push_back(0);
            }
        }
        while (readFile.read(reinterpret_cast<char *>(&tem), tsize)) {
            if (!tem.getflag()) {
                int flag = 0;
                for (int i = 1; i < value.size(); i++) {
                    if (ElemType[i - 1] == "int") {
                        if (tem.getIntElemByName(value[i]) != IntValue[i - 1]) {
                            flag = 1;
                            break;
                        }
                    } else if (ElemType[i - 1] == "float") {
                        if (tem.getFloatElemByName(value[i]) != floatValue[i - 1]) {
                            flag = 1;
                            break;
                        }
                    } else {
                        if (strcmp(tem.getCharElemByName(value[i]), charValue[i - 1])) {
                            flag = 1;
                            break;
                        }
                    }
                }
                if (flag == 0) {
                    result.push_back(tem);
                }
            }
        }
    }


    template<typename T>
    int selectLike(string fileName, string value_name, char *value, vector<T> &result) {
        ifstream readFile;
        try {
            T tem;
            int tsize = sizeof(tem);
            string Filepath = rootPath + fileName + ".dat";

            readFile.open(Filepath.c_str(), ios::in | ios::out | ios::binary);
            if (!readFile) {
                ios_base::failure fail("ERROR");
                throw fail;
            }
            while (readFile.read(reinterpret_cast<char *>(&tem), tsize)) {
                if (tem.getflag() != -1 && strstr(tem.getCharElemByName(value_name), value)) {
                    result.push_back(tem);
                }
            }
            return result.size();
        }
        catch (ios_base::failure &fail) {
            cout << fail.what() << endl;
            return -1;
        }
    }

    //增加fileName中的数据，entity为待增加的数据
//操作失败返回-1  成功返回某个正整数 预期设定为最后插入位置所属文件中的个数
//插入前应该手动先判断是否有重复数据

    template<typename T>
    int insert(string fileName, vector<T> &entity) {
        int id;
        ifstream readFile;
        ofstream writeFile;

        T tem;
        int tsize = sizeof(tem);

        try {
            string Filepath = rootPath + fileName + ".dat";

            readFile.open(Filepath.c_str(), ios::in | ios::out | ios::binary);
            if (!readFile) {
                ios_base::failure fail("ERROR");
                throw fail;
            }
            long long l = readFile.tellg();

            readFile.seekg(0, ios::end);
            //readFile.seekg(-1*sizeof(tem),ios::cur);
            //readFile.read(reinterpret_cast<char*>(&tem),tsize);

            long long r = readFile.tellg();

            id = (r - l) / sizeof(tem);
            //cout<<id<<endl;
            readFile.close();
            //id++;



            writeFile.open(Filepath.c_str(), ios::app | ios::binary);
            //cout<<"hello"<<endl;
            if (!writeFile) {
                ios_base::failure fail("ERROR");
                throw fail;
            }

            for (int i = 0; i < entity.size(); i++) {
                entity[i].setId(id);
                entity[i].setflag(0);
                //cout<<entity[i].getId()<<endl;
                writeFile.write(reinterpret_cast<char *>(&entity[i]), sizeof(entity[i]));
                //cout<<"hel"<<endl;
                id++;
            }
            writeFile.close();
            return id;

        }
        catch (ios_base::failure &fail) {
            cout << fail.what() << endl;
            return -1;
        }
    }


    //删除fileName中的数据，其中entity代表删除的数据
//操作失败返回-1 成功返回最后一次影响的行数
    template<typename T>
    int Delete(string fileName,T& entity,vector<string>& value)
    {
        ofstream writeFile;
        ifstream readFile;
        int res = 0;
        try
        {
            if (value[0] == "all")
            {

                string Filepath=rootPath+fileName+".dat";
                writeFile.open(Filepath.c_str(), ios::in | ios::out | ios::binary);
                if (!writeFile)
                {
                    ios_base::failure fail("ERROR");
                    throw fail;
                }
                writeFile.close();
                writeFile.open(Filepath.c_str(), ios::trunc);
                writeFile.close();
                return 1;
            }
            string Filepath=rootPath+fileName+".dat";
            writeFile.open(Filepath.c_str(), ios::in | ios::out | ios::binary);
            if (!writeFile)
            {
                ios_base::failure fail("ERROR");
                throw fail;
            }
            if (value[1] == "id")
            {
                T tem;
                tem.setflag(1);

                writeFile.seekp(entity.getId() * sizeof(tem), ios::beg);
                writeFile.write((char*)&tem, sizeof(tem));
                return 1;
            }

            //string Filepath=rootPath+db_name+".dat";
            readFile.open(Filepath.c_str(), ios::in | ios::out | ios::binary);
            if (!readFile)
            {
                ios_base::failure fail("ERROR");
                throw fail;
            }
            T tem;
            int tsize = sizeof(tem);

            vector<string>ElemType;

            vector<int>IntValue;
            vector<float>floatValue;
            vector<char*>charValue;

            for(int i=1; i<value.size(); i++)
            {
                ElemType.push_back(entity.getElemType(value[i]));
                if(ElemType[i-1]=="int")
                {
                    IntValue.push_back(entity.getIntElemByName(value[i]));
                    floatValue.push_back(0);
                    charValue.push_back((char*)"");
                }
                else if(ElemType[i-1]=="float")
                {
                    floatValue.push_back(entity.getFloatElemByName(value[i]));
                    IntValue.push_back(0);
                    charValue.push_back((char*)"");
                }
                else
                {
                    charValue.push_back(entity.getCharElemByName(value[i]));
                    floatValue.push_back(0);
                    IntValue.push_back(0);
                }
            }

            for (int count = 0; readFile.read(reinterpret_cast<char*>(&tem), tsize); count++)
            {
                if (!tem.getflag())
                {
                    int flag = 1;
                    for (int i = 1; i < value.size(); i++)
                    {
                        if (ElemType[i-1] == "int")
                        {
                            if (tem.getIntElemByName(value[i]) != IntValue[i-1])
                            {
                                flag = 0;
                                break;
                            }
                        }
                        else if (ElemType[i-1] == "float")
                        {
                            if (tem.getFloatElemByName(value[i]) != floatValue[i-1])
                            {
                                flag = 0;
                                break;
                            }
                        }
                        else
                        {
                            if (strcmp(tem.getCharElemByName(value[i]), charValue[i-1]))
                            {
                                flag = 0;
                                break;
                            }
                        }
                    }
                    //符合条件，删除
                    if (flag)
                    {
                        res++;
                        writeFile.seekp(count * sizeof(entity), ios::beg);
                        tem.setflag(1);
                        writeFile.write((char*)&tem, sizeof(tem));
                    }
                }
            }
            readFile.close();
            writeFile.close();
            return res;
        }//捕获文件操作异常，返回-1
        catch (ios_base::failure &fail)
        {
            cout << fail.what() << endl;
            return -1;
        }//捕获字段赋值异常，返回-1
        catch (const char* e)
        {
            cout << "exception: " << e << endl;
            return -1;
        }
    }
};


#endif //MYFILEDB_H
