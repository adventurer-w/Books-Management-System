# 前端界面说明

## 10.15更新

> 登录可以自己注册账号，或者使用`20040032002`    `123456aA`进行登录

#### 注明：图片显示有bug，因为后端把绝对路径存进去了，获取也是绝对路径。

#### 如果可以的话试着改改。

### 1.新文件

1.admininfo，管理员个人信息界面

2.adminbookmanagement，管理员图书管理界面



### 2.修改说明

#### 1.管理员个人信息界面

只写好了最基本的函数，只要获取到管理员信息即可，个人信息界面同时可以修改信息，可以参照个人信息modifyinfowidget修改来写。

#### 2.管理员图书查询

只写好了最基本的函数，需要获取图书的信息，可参照图书查找。除此以外还需要完成动态按钮创建，可以参照booklist函数，完成对某一条图书记录的删除修改；右上角还有添加按钮，需要能够增加图书记录，支持excel批量导入等。分类，按照各种方式查询，目前按钮逻辑也没写，可以参照bookquerywidget。

目标效果如下，渲染部分不需要做，下方页面页码不需要管。

![image-20221015205511303](https://yuan-1314071695.cos.ap-nanjing.myqcloud.com/img/image-20221015205511303.png)

#### 3.进入管理员

只需要在登录后的mainwindow里面，构造函数中寻找userType成员变量。根据后端提供的信息，确定userType为0，则会自动加载管理员界面。如果为1则为普通用户,自动加载用户界面。

```c++
ui->setupUi(this);
this->setWindowTitle("图书系统");
this->resize(1600,900);
/* judge admin 0 or user 1 here*/
/* start */
userType = 1;
/* end */
loadUserInfo();
loadMenuBar();
loadPages(0);
```



你无需关心界面跳转，这些已经写好了。同时个人信息界面存在修改后延迟的问题，这个是因为我还没写相关的槽函数，如果你硬要改，可以参照如下

```c++
oid MainWindow::loadPages(int mode){
    if(mode == 0){
        mw->resize(1300,900);
        mw->move(this->x()+300,this->y());
        mw->setParent(this);
    }
    if(userType == 0){//表示管理员
        if(mode == 0 || mode==1){
            /*导入管理员个人信息界面  */
            AdminInfo *adminInfo = new AdminInfo;
            adminInfo->resize(1300,900);
            //connect(adminInfo,SIGNAL(modifySignal()),this,SLOT(loadUserInfo()));
            mw->insertWidget(0,adminInfo);
        }

        if(mode == 0||mode == 2){
            /*导入管理员图书信息管理界面 */
            AdminBookManagement *adminBookManagement = new AdminBookManagement;
            adminBookManagement->resize(1300,900);
            //connect(adminBookManagement,SIGNAL(modifySignal()),this,SLOT(loadAdminInfo()));
            mw->insertWidget(1,adminBookManagement);
        }
        if(mode == 0||mode ==3){
            /*导入管理员个人借阅信息管理界面  */
        }
    }
 ……
       }


}
```

其中注释的部分就是刷新状态的函数，其中loadAdminInfo还没写，需要你完成。

