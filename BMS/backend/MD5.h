#ifndef MD5_H
#define MD5_H
#include "string"
#include <vector>


/*
    使用方法：例如需要给string a加密，得到b
    MD5 md5;
    string b= md5.read(a);
 */

using namespace std;
class MD5 {
public:
    MD5();
    ~MD5();
    const char * read(string a);
    void HMD5(int q);
    const char *Encryption();
private:
    vector<unsigned int *> MessageFlow;
    unsigned int A,B,C,D;
};

#endif //MD5_H
