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

### 列表初始值还是元素数量
```
vector<string> v5{"hi"}  //初始化列表：v5有一个元素
vector<string> v6("hi")  //错误：不能使用字符串值构建vector
vector<string> v7{10}    //10个默认初始化值
vector<string> v8{10, "hi"} //10个初始化值"hi"
```
要想使用列表初始化，列表初始化中的元素必须与vector中的类型相同
