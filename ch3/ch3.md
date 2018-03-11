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
