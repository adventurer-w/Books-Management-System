# 后端接口使用说明

##  9.28更新

### MD5（重要！）

MD5类已经实现好，前端在传**密码**之前，需要将密码用MD5加密后传给后端，（也就是说后端只会有加密后的密码，注意不要二次加密）。

使用举例

```c++
#include "backend/MD5.h"

/*
需要给string a加密，得到b
 */

MD5 md5;
string b= md5.read(a);
```



### 关于maFileDB

这里面是对文件的读写操作，前端**不需要**使用该类



### Utils使用

Utils提供了接口文档中提到的各种接口，如有不同，请以Utils.h为准。

使用举例

```c++
#include "backend/Utils.h"
#include "backend/all_head.h"

//文件储存路径，我放在了项目根目录的files文件里面
Utils utils("D:\\BMS\\Files\\"); 

User user;
user.setAccount("test");
user.setPassword("password（MD5加密后）");

utils.Register(user);  //注册

utils.Login("test","password（MD5加密后）");  //登录
```



