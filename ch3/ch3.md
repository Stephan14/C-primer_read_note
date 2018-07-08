## 命名空间的using声明

为了避免名字冲突，使用命名空间来进行限制，通过*using namespace::name;* 的方式来进行声明

```
using std::cout;
```
### 注意
- 头文件中不应该包含using，因为可能带来命名冲突

## 标准库类型string

### 定义和初始化string对象

直接初始化和拷贝初始化

### string对象操作

- cin >> 读入字符串，去掉开头的空格、制表符、换行符到再遇到他们时结束
- getline 读取一整行，不保存换行符
- size()函数返回类型为string::size_type类型，为无符号整数，不要与int一起使用进行大小比较
- 字符字面值和字符串字面值可以转化成string类型，但是为了与C兼容，字符串字面值并不是string类型
- +操作符左右两侧必须有一个是string类型

### 处理字符串对象中的字符

#### 访问字符串中的每一个字符
利用C++11提供的for语句来处理字符串中的每一个字符，例如：

```
std::string str("hello word!");
std::decltype(str.size()) num = 0;

for (auto s : str) {
  std::cout << s;
}
```

#### 改变字符串中的每一个字符
将循环变量定义成引用的形式，例如：
```
std::string str("hello word!");
std::decltype(str.size()) num = 0;

for (auto &s : str) {
  s = std::toupper(s);
}
```

#### 只处理字符串的一部分
通过访问下标的形式来处理字符串中的一部分字符串。例如：

```
for (std::decltype(str.size()) index = 0;
index != str.size() && !isspace(str[index]); ++index) {
  str[index] = std::toupper(str[index]);
}

```

##### 注意
- 使用下表之前，判断字符串是不是空的（empty()）
- 保证下标的合法性，一般声明为无符号类型并保证小于size

## 标准库类型vector
vector中所有的对象的类型都是一样的，每个对象有一个索引与之对应，可以通过索引进行访问。由于引用不属于对象，所以不存在包含引用的vector。


### 定义和初始化vector对象
```
vector<T>  v1(n, val)           //n个元素每个元素是val
vector<T>  v2(n)                //n个元素每个元素默认值
vector<T>  v3{a, b, c, d....}   //只能使用花括号
vector<T>  v4 = {a, b, c, d....}
vector<T>  v5 = v4              //拷贝原对象的副本

//使用列表初始化，花括号里的值必须与T相同
vector<string> v5{"HI"}        //列表初始化，一个元素
vector<string> v6("HI")        //错误
vector<string> v7{10}          //10个默认值
vector<string> v8{10, "HI"}    //10个‘HI’值

```

#### 注意
- 注意类型是不是匹配
- 有些类不提供默认初始化，必须显示初始化，提供默认值
- 注意初始化的时候，圆括号与花括号的区别
- 由于引用不是对象，不存在包含引用的vector
- 使用拷贝初始化时(=),只提供一个初始值
- 如果提供一个类内初始值，只能使用拷贝初始化或者列表初始化
- **vector中不可以存放引用类型**

### 列表初始值还是元素数量
```
vector<string> v5{"hi"}  //初始化列表：v5有一个元素
vector<string> v6("hi")  //错误：不能使用字符串值构建vector
vector<string> v7{10}    //10个默认初始化值
vector<string> v8{10, "hi"} //10个初始化值"hi"
```
要想使用列表初始化，列表初始化中的元素必须与vector中的类型相同

### 其他操作

#### 注意
- 要使用size_type首先要指定由哪一种类型定义，vector对象类型包含元素类型，例如：vector<int>::size_type
- vector中下标运算符可以用于访问已经存在的元素，而不能用于添加元素，添加元素使用push_back
- 可以通过下标访问已知存在的元素

## 迭代器介绍
标准库所有容器类型都可以使用迭代器，其中只有少数的几种支持下标运算

### 使用迭代器

- 如果容器为空，则begin和end返回的是同一个迭代器，都是尾后迭代器
- 迭代器运算符包括一些部分，其中对月非法的迭代器或者尾迭代器进行解引用操作的结果是未定义的
![](http://res.cloudinary.com/bytedance14/image/upload/v1529509092/%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7_2018-06-20_%E4%B8%8B%E5%8D%8811.34.01.png)

### 迭代器类型
迭代器有`iterator`和`const_iterator`两种类型，其区别如下：
```
vector<int>::iterator it; //it可以读也可以写
string::iterator    it2;  //it2可以读也可以写

vector<int>::const_iterator it3; //it3只能读元素，不能写元素
string::const_iterator it4;      //it4只能读元素，不能写元素
```
#### 注意
- 如果vector对象或者string对象是一个常量，只能使用`const_iterator`;如果vector对象或者string对象不是常量，既可以使用iterator也可以使用const_iterator

### begin和end运算符

- begin和end返回的具体类型由对象是否为常量决定，如果对象是常量，begin和end返回const_iterator;如果对象不是常量，返回iterator
- 不论vector对象是不是常量，`cbegin`和`cend`返回值都是const_iterator

### 某些对vector对象的操作会使迭代器失效``
- 不能在使用迭代器中for循环中使用添加元素，会使迭代器失效
- 任何可能改变vector对象容量的操作会使迭代器失效
- 凡是使用迭代器的循环体都不要想迭代器所属的容器添加元素

## 数组
与vector不同的是数组的大小是不确定的，不能随便的向数组中添加元素

- 如果在函数内部定义了某种类型的数组，那么默认初始化会令数组含有未定义的值
- 定义数组的时候必须指定数组的类型，不允许使用auto推荐数组类型
- 与vector一样，数组元素为对象，**不存在引用的数组**

### 字符数组的特殊性

字符数组初始化的时候字符结尾处还有一个空字符串，这个空字符串会像其他字符一样拷贝到字符数组中去。
```
char a1[] = {'c', 'd', 'x'};     //真实的长度为4
char a2[] = {'c', '+', '+', '\0'};
char a3[] = "C++";               //真实的长度为4
const char a4[6] = "Daniel";     //错误，没有空间可以存放空字符串
```
### 不允许拷贝和赋值
不能将数组的内容拷贝给其他的数组作为初始值，也不能进行赋值。
```
int a[] = {0, 1, 2};
int a2[] = a;  //错误:不允许一个数组初始化另一个数组
a2 = a;        //错误:不允许一个数组赋值给另一个数组
```

### 复杂数组声明

**由于数组为对象**，所以允许定义数组的指针和数组的引用
- int &refs[10]  /*不存在引用的数组*/
- int (*Parrary)[10] /*Parrary指向一个含有10个整数的数组,默认情况是从右向左匹配，但是有括号优先级更高一些*/
- int (*ref)[10] /*ref引用含有一个10个整数的数组，默认情况是从右向左匹配，但是有括号优先级更高一些*/

### 访问数组元素
