#ifndef MYFILEDB_H
#define MYFILEDB_H

#include<cstring>
#include<vector>
#include<fstream>
#include<iostream>

using namespace std;

class myFileDB {
public:
    string rootPath;

    template<typename T>
    void selectInt(ifstream &readFile, string valueName, int value, vector<T> &resultSet);

    template<typename T>
    void selectChar(ifstream &readFile, string valueName, char *value, vector<T> &resultSet);

    template<typename T>
    void selectFloat(ifstream &readFile, string valueName, float value, vector<T> &resultSet);

    template<typename T>
    void selectId(ifstream &readFile, int Id, vector<T> &resultSet);

    template<typename T>
    void selectMany(ifstream &readFile, T &entity, vector<string> &VALUES, vector<T> &resultSet);

    //构造函数，传入路径
    myFileDB(string path)
    {
        rootPath=path;
    }
    /*
     在DB_NAME.dat文件中选择对应表单  entity选择条件 value选择字段 resultSet结果
     成功则返回查询结果个数，失败返回-1
     选择所有：value[0]=="all"
     根据单项属性值选择：value[0]!="all"，并且value[1]置为对应查询的属性 如id
     根据多项属性值选择：如：value[1] value[2] 分别表示id、name等多个匹配
    */

    template<typename T>
    int select(string DB_NAME, T &entity, vector<string> &VALUES, vector<T> &resultSet);


    //对字符串进行模糊查询
    template<typename T>
    int selectLike(string DB_NAME, string valueName, char *value, vector<T> &resultSet);


    //增加DB_NAME中的数据，entity为待增加的数据
    //操作失败返回-1  成功返回某个正整数 预期设定为最后插入位置所属文件中的个数
    //插入前应该手动先判断是否有重复数据
    template<typename T>
    int insert(string DB_NAME, vector<T> &entity);


    //删除fileName中的数据，其中entity代表删除的数据
    //操作失败返回-1 成功返回最后一次影响的行数
    template<typename T>
    int Delete(string DB_NAME, T &entity, vector<string> &VALUES);


    //更新DB_NAME的数据，Sentity为选择条件，Uentity为更新内容，VALUES为选择字段
    //操作成功，返回受影响的行数，操作失败，返回-1
    template<typename T>
    int update(string DB_NAME, T &Sentity, T &Uentity, vector<string> &VALUES);

    template<typename T>
    int getMaxId(string DB_NAME, T &entity);

    template<typename T>
    int getAtBeginOf(string DB_NAME,vector<T> &resultSet);
};

template<typename T>
int myFileDB::select(string DB_NAME, T &entity, vector<string> &VALUES, vector<T> &resultSet) {
    ifstream readFile;
    try {
        T temp;
        int TSize = sizeof(temp);
        readFile.open(rootPath + DB_NAME + ".dat", ios::in | ios::out | ios::binary);
        if (!readFile) {
            ios_base::failure fail("ERROR");
            throw fail;
        }
        //查询所有
        if (VALUES[0] == "all") {
            while (readFile.read(reinterpret_cast<char *>(&temp), TSize)) {
                //去除无效数据
                if (temp.dirty!=1)
                    resultSet.push_back(temp);
            }
        }
            //查询满足条件的
        else {
            if (VALUES.size() == 2) {
                if (VALUES[1] == "id") {
                    selectId(readFile, entity.getId(), resultSet);
                } else {
                    if (temp.getElemType(VALUES[1]) == "int")
                        selectInt(readFile, VALUES[1], entity.getIntElemByName(VALUES[1]), resultSet);
                    else if (temp.getElemType(VALUES[1]) == "float")
                        selectFloat(readFile, VALUES[1], entity.getFloatElemByName(VALUES[1]), resultSet);
                    else
                        selectChar(readFile, VALUES[1], entity.getCharElemByName(VALUES[1]), resultSet);
                }
            }

                //多个查询
            else {
                selectMany(readFile, entity, VALUES, resultSet);
            }
        }
        readFile.close();
        if(!resultSet.empty()) return resultSet.size();
        else return -1;
    }
    catch (ios_base::failure &fail) {
        cout << fail.what() << endl;
        return -1;
    }
}

template<typename T>
int myFileDB::selectLike(string DB_NAME, string valueName, char *value, vector<T> &resultSet) {
    ifstream readFile;
    try {
        T temp;
        int TSize = sizeof(temp);
        readFile.open(rootPath + DB_NAME + ".dat", ios::in | ios::out | ios::binary);
        if (!readFile) {
            ios_base::failure fail("ERROR");
            throw fail;
        }
        while (readFile.read(reinterpret_cast<char *>(&temp), TSize)) {
            if (!temp.dirty != -1 && strstr(temp.getCharElemByName(valueName), value)) {
                resultSet.push_back(temp);
            }
        }
        return resultSet.size();
    }
    catch (ios_base::failure &fail) {
        cout << fail.what() << endl;
        return -1;
    }
}


template<typename T>
int myFileDB::insert(string DB_NAME, vector<T> &entity) {
    int id;
    ofstream writeFile;
    ifstream readFile;

    T tem;
    int tsize = sizeof(tem);
    try {
        string Filepath = rootPath + DB_NAME + ".dat";
        readFile.open(Filepath.c_str(), ios::in | ios::out | ios::binary);

        if (!readFile) {
            ios_base::failure fail("ERROR");
            throw fail;
        }
        long long l = readFile.tellg();

        readFile.seekg(0, ios::end);
        long long r = readFile.tellg();
        id = (r - l) / sizeof(tem);
        readFile.close();

        writeFile.open(Filepath.c_str(), ios::app | ios::binary);
        if (!writeFile) {
            ios_base::failure fail("ERROR");
            throw fail;
        }

        for (int i = 0; i < entity.size(); i++) {
            entity[i].setId(id);
            entity[i].setDirty(0);
            writeFile.write(reinterpret_cast<char *>(&entity[i]), sizeof(entity[i]));
            id++;
        }

        writeFile.close();
        return id;
    } catch (ios_base::failure &fail) {
        cout << fail.what() << endl;
        return -1;
    }
}

template<typename T>
int myFileDB::Delete(string DB_NAME, T &entity, vector<string> &VALUES) {
    ofstream writeFile;
    ifstream readFile;
    int res = 0;
    //删除所有
    try {
        if (VALUES[0] == "all") {
            writeFile.open(rootPath + DB_NAME + ".dat", ios::in | ios::out | ios::binary);
            if (!writeFile) {
                ios_base::failure fail("ERROR");
                throw fail;
            }
            writeFile.open(rootPath + DB_NAME + ".dat", ios::trunc);
            writeFile.close();
            return 1;
        }

        writeFile.open(rootPath + DB_NAME + ".dat", ios::in | ios::out | ios::binary);
        if (!writeFile) {
            ios_base::failure fail("ERROR");
            throw fail;
        }

        if (VALUES[1] == "id") {
            T deleteT;
            deleteT.setDirty(1);
            writeFile.seekp(entity.getId() * sizeof(deleteT), ios::beg);
            writeFile.write((char *) &deleteT, sizeof(deleteT));
            return 1;
        }


        readFile.open(rootPath + DB_NAME + ".dat", ios::in | ios::out | ios::binary);
        if (!readFile) {
            ios_base::failure fail("ERROR");
            throw fail;
        }
        T temp;
        int TSize = sizeof(temp);


        vector<string> elemType;
        vector<int> elemIntValue;
        vector<float> elemFloatValue;
        vector<char *> elemCharValue;
        elemType.push_back("");
        elemIntValue.push_back(0);
        elemFloatValue.push_back(0);
        elemCharValue.push_back("");
        for (int i = 1; i < VALUES.size(); i++) {
            elemType.push_back(entity.getElemType(VALUES[i]));
        }
        for (int i = 1; i < VALUES.size(); i++) {
            if (elemType[i] == "int") {
                elemIntValue.push_back(entity.getIntElemByName(VALUES[i]));
                elemFloatValue.push_back(0);
                elemCharValue.push_back("");
            } else if (elemType[i] == "float") {
                elemFloatValue.push_back(entity.getFloatElemByName(VALUES[i]));
                elemIntValue.push_back(0);
                elemCharValue.push_back("");
            } else {
                elemFloatValue.push_back(0);
                elemIntValue.push_back(0);
                elemCharValue.push_back(entity.getCharElemByName(VALUES[i]));
            }
        }

        for (int count = 0; readFile.read(reinterpret_cast<char *>(&temp), TSize); count++) {
            //去除无效数据
            if (temp.dirty!=1) {
                int flag = 1;
                //遍历选择条件
                for (int i = 1; i < VALUES.size(); i++) {
                    if (elemType[i] == "int") {
                        if (temp.getIntElemByName(VALUES[i]) != elemIntValue[i]) {
                            flag = 0;
                            break;
                        }
                    } else if (elemType[i] == "float") {
                        if (temp.getFloatElemByName(VALUES[i]) != elemFloatValue[i]) {
                            flag = 0;
                            break;
                        }
                    } else {
                        if (strcmp(temp.getCharElemByName(VALUES[i]), elemCharValue[i])) {
                            flag = 0;
                            break;
                        }
                    }
                }
                //符合条件，删除
                if (flag) {
                    res++;
                    //移动文件指针，在count * sizeof(entity)出重写数据，将Dirty置为1
                    writeFile.seekp(count * sizeof(entity), ios::beg);
                    T deleteT;
                    deleteT.setDirty(1);
                    writeFile.write((char *) &deleteT, sizeof(deleteT));
                }
            }
        }
        readFile.close();
        writeFile.close();
        return res;
    }//捕获文件操作异常
    catch (ios_base::failure &fail) {
        cout << fail.what() << endl;
        return -1;
    }//捕获字段赋值异常
    catch (const char *e) {
        cout << "exception: " << e << endl;
        return -1;
    }
}

template<typename T>
int myFileDB::update(string DB_NAME, T &Sentity, T &Uentity, vector<string> &VALUES) {
    ofstream writeFile;
    ifstream readFile;
    try {
        writeFile.open(rootPath + DB_NAME + ".dat", ios::in | ios::out | ios::binary);
        if (!writeFile) {
            ios_base::failure fail("ERROR");
            throw fail;
        }
        if (VALUES[1] == "id") {
            Uentity.setId(Sentity.getId());
            Uentity.setDirty(0);
            writeFile.seekp(Sentity.getId() * sizeof(Sentity), ios::beg);
            writeFile.write((char *) &Uentity, sizeof(Uentity));
            return 1;
        }
        readFile.open(rootPath + DB_NAME + ".dat", ios::in | ios::out | ios::binary);
        if (!readFile) {
            ios_base::failure fail("ERROR");
            throw fail;
        }
        T temp;


        vector<string> elemType;
        vector<int> elemIntValue;
        vector<float> elemFloatValue;
        vector<char *> elemCharValue;
        elemType.push_back("");
        elemIntValue.push_back(0);
        elemFloatValue.push_back(0);
        elemCharValue.push_back("");
        for (int i = 1; i < VALUES.size(); i++) {
            elemType.push_back(Sentity.getElemType(VALUES[i]));
        }
        for (int i = 1; i < VALUES.size(); i++) {
            if (elemType[i] == "int") {
                elemIntValue.push_back(Sentity.getIntElemByName(VALUES[i]));
                elemFloatValue.push_back(0);
                elemCharValue.push_back("");
            } else if (elemType[i] == "float") {
                elemFloatValue.push_back(Sentity.getFloatElemByName(VALUES[i]));
                elemIntValue.push_back(0);
                elemCharValue.push_back("");
            } else {
                elemFloatValue.push_back(0);
                elemIntValue.push_back(0);
                elemCharValue.push_back(Sentity.getCharElemByName(VALUES[i]));
            }
        }

        for (int count = 0; readFile.read(reinterpret_cast<char *>(&temp), sizeof(temp)); count++) {

            if (temp.dirty!=1) {
                int flag = 1;
                //遍历选择条件
                for (int i = 1; i < VALUES.size(); i++) {
                    if (elemType[i] == "int") {
                        if (temp.getIntElemByName(VALUES[i]) != elemIntValue[i]) {
                            flag = 0;
                            break;
                        }
                    } else if (elemType[i] == "float") {
                        if (temp.getFloatElemByName(VALUES[i]) != elemFloatValue[i]) {
                            flag = 0;
                            break;
                        }
                    } else {
                        if (strcmp(temp.getCharElemByName(VALUES[i]), elemCharValue[i])) {
                            flag = 0;
                            break;
                        }
                    }
                }

                if (flag) {
                    Uentity.setId(temp.id);
                    Uentity.setDirty(0);

                    writeFile.seekp(count * sizeof(Sentity), ios::beg);
                    writeFile.write((char *) &Uentity, sizeof(Uentity));
                }
            }
        }
        readFile.close();
        writeFile.close();
        return 1;
    }//捕获文件操作异常
    catch (ios_base::failure &fail) {
        cout << fail.what() << endl;
        return -1;
    }//捕获字段赋值异常
    catch (const char *e) {
        cout << "exception: " << e << endl;
        return -1;
    }
}


template<typename T>
void myFileDB::selectInt(ifstream &readFile, string valueName, int value, vector<T> &resultSet) {
    T temp;
    int TSize = sizeof(T);
    while (readFile.read(reinterpret_cast<char *>(&temp), TSize)) {
        if (temp.dirty!=1 && temp.getIntElemByName(valueName) == value) {
            resultSet.push_back(temp);
        }
    }
}

template<typename T>
void myFileDB::selectChar(ifstream &readFile, string valueName, char *value, vector<T> &resultSet) {
    T temp;
    int TSize = sizeof(T);
    while (readFile.read(reinterpret_cast<char *>(&temp), TSize)) {
        if (temp.dirty!=1 && !strcmp(temp.getCharElemByName(valueName), value)) {
            resultSet.push_back(temp);
        }
    }
}

template<typename T>
void myFileDB::selectFloat(ifstream &readFile, string valueName, float value, vector<T> &resultSet) {
    T temp;
    int TSize = sizeof(T);
    while (readFile.read(reinterpret_cast<char *>(&temp), TSize)) {
        if (temp.dirty!=1 && temp.getFloatElemByName(valueName) == value) {
            resultSet.push_back(temp);
        }
    }
}

template<typename T>
void myFileDB::selectId(ifstream &readFile, int Id, vector<T> &resultSet) {
    T temp;
    readFile.seekg(Id * sizeof(temp), ios::beg);
    readFile.read(reinterpret_cast<char *>(&temp), sizeof(temp));
    resultSet.push_back(temp);
}

template<typename T>
void myFileDB::selectMany(ifstream &readFile, T &entity, vector<string> &VALUES, vector<T> &resultSet) {
    T temp;
    int TSize = sizeof(T);

    vector<string> elemType;
    vector<int> elemIntValue;
    vector<float> elemFloatValue;
    vector<char *> elemCharValue;
    elemType.push_back("");
    elemIntValue.push_back(0);
    elemFloatValue.push_back(0);
    elemCharValue.push_back("");
    for (int i = 1; i < VALUES.size(); i++) {
        elemType.push_back(entity.getElemType(VALUES[i]));
    }
    for (int i = 1; i < VALUES.size(); i++) {
        if (elemType[i] == "int") {
            elemIntValue.push_back(entity.getIntElemByName(VALUES[i]));
            elemFloatValue.push_back(0);
            elemCharValue.push_back("");
        } else if (elemType[i] == "float") {
            elemFloatValue.push_back(entity.getFloatElemByName(VALUES[i]));
            elemIntValue.push_back(0);
            elemCharValue.push_back("");
        } else {
            elemFloatValue.push_back(0);
            elemIntValue.push_back(0);
            elemCharValue.push_back(entity.getCharElemByName(VALUES[i]));
        }
    }

    while (readFile.read(reinterpret_cast<char *>(&temp), TSize)) {
        if (temp.dirty!=1) {
            int flag = 1;
            //遍历选择条件
            for (int i = 1; i < VALUES.size(); i++) {
                if (elemType[i] == "int") {
                    if (temp.getIntElemByName(VALUES[i]) != elemIntValue[i]) {
                        flag = 0;
                        break;
                    }
                } else if (elemType[i] == "float") {
                    if (temp.getFloatElemByName(VALUES[i]) != elemFloatValue[i]) {
                        flag = 0;
                        break;
                    }
                } else {
                    if (strcmp(temp.getCharElemByName(VALUES[i]), elemCharValue[i])) {
                        flag = 0;
                        break;
                    }
                }
            }
            //符合条件，加入结果集
            if (flag)
                resultSet.push_back(temp);
        }
    }
}

template<typename T>
int myFileDB::getMaxId(string DB_NAME, T &entity){
    int id;
    ifstream readFile;

    T tem;
    int tsize = sizeof(tem);
    try {
        string Filepath = rootPath + DB_NAME + ".dat";
        readFile.open(Filepath.c_str(), ios::in | ios::out | ios::binary);

        if (!readFile) {
            ios_base::failure fail("ERROR");
            throw fail;
        }
        readFile.seekg(0, ios::end);

        long long l = readFile.tellg();

        readFile.seekg(0, ios::end);
        long long r = readFile.tellg();
        id = (r - l) / sizeof(tem);

        return id;
    } catch (ios_base::failure &fail) {
        cout << fail.what() << endl;
        return -1;
    }
}

template<typename T>
int myFileDB::getAtBeginOf(string DB_NAME,vector<T> &resultSet){
    int cnt;
    ifstream readFile;

    T temp;
    int TSize = sizeof(temp);
    try {
        string Filepath = rootPath + DB_NAME + ".dat";
        readFile.open(Filepath.c_str(), ios::in | ios::out | ios::binary);

        if (!readFile) {
            ios_base::failure fail("ERROR");
            throw fail;
        }
        readFile.seekg(0, ios::end);
        long long l = readFile.tellg();

        readFile.seekg(0, ios::end);
        long long r = readFile.tellg();
        cnt = (r - l) / sizeof(temp);

        for(int i=0;cnt >= 0 && i<=50;){
            readFile.seekg(cnt*TSize);
            readFile.read(reinterpret_cast<char *>(&temp), TSize);

            if (temp.dirty!=1) {
                resultSet.push_back(temp);
                i++;
            }
            cnt--;
        }
        return 1;
    } catch (ios_base::failure &fail) {
        cout << fail.what() << endl;
        return -1;
    }

}


#endif //MYFILEDB_H
