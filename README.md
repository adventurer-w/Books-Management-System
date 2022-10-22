# 2022-10-21

已经合并完三条分支，对应的功能简单的测试了一下都没有问题。（一键尾页不卡死，历史借阅，修改图书封面）

现在pull下来的整个项目，基本上可以当作实机测试的成品了。

（注意要在view文件夹下的GlobalSetting.h配置路径）

图书封面的相关细节请搭配cover文件夹食用。（需要在cover里面再建一个zother文件夹，用来存放用户新添加的封面）

### 测试用账号

用户：20040032002

管理员：000001

密码：123456aA



# 管理员界面-图书管理

## 10.19

#### 需要增加的功能：

#### 1.修改类别modifybookcategory的后端逻辑

#### 2.添加单本book adminbookmanagement::add_book的逻辑，理论界面跳转到修改图书详情界面（复用），需要对modifybookdetails界面做一定的修改。

#### 3.用户管理的功能



### 修复的bug：

#### 1.qss问题，按钮闪现bug，和分类按钮的显示前端逻辑；

#### 2.图书管理无法删除和修改图书的问题，通过信号槽和tableview自带函数实现修复

#### 3.大部分界面背景图显示问题

### ==注：为了方便测试我把用户名密码写死为user的账号了，可以前往widget和mainwindow进行修改。（催下邮箱验证码修改）==

## 功能方面

已经实现了图书管理界面的

- 图书查询
- 图书修改
- 图书删除
- 图书批量导入

目前已知bug（怀疑这些bug都是因为没有实时刷新，因为代码与用户界面几乎一致，但是就是不刷新）

- 顶端栏按钮不一致问题。（明明后台是按照书名分类查找，但是界面上的按钮并非这样）
- 底部翻页、右上角添加书籍按钮没有qss，不能正常显示，鼠标放上去可以显示
- 任何操作之后，管理员界面的booklist不会立刻刷新。但是确实是成功修改（删除）了

以上bug导致，现在想要测试这些功能，需要反复进入图书管理界面，才会刷新。但是功能真的是好的

还没做的部分：

- 添加分类（因为qt没加载出来新按钮，有可能是我代码还没改，但是这个不急）
- 有关封面的各种操作（这个涉及相对路径绝对路径比较麻烦）





## 关于修改的文件

因为我的分支里面的其他内容比较老旧，只pull我改动的文件即可。

目前改动了的文件：

### 专门负责这些功能的三大主要文件（建议直接覆盖旧文件）：

admininfo.h、admininfo.cpp

adminbookmanagement.h、adminbookmanagement.cpp、adminbookmanagement.ui

adminmodifybookdetail.h、adminmodifybookdetail.cpp

### mainwindow.cpp

将原先的

```
userType = 0;
```

改为

```
if(!now_user.getAccount()[0] && !now_user.getAccount()[1])userType = 0;

else userType = 1;
```

### 配置文件：

BMS.pro （只是在尾部加上了 `QT += axcontainer`）



