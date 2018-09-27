## 简单语句

### 空语句
空语句中只包含一个单独的分号

#### 注意
- 使用空语句应该加上注释，从而告诉读者是有意省略的

### 复合语句（块）

用花括号括起来的语句和声明序列被称之为块

#### 注意
- 块不以分号作为结束

## 语句作用域

定义在控制结构中的变量只有在相应语句的内部可见，一旦语句结束，变量超出其作用范围

## 条件语句

### if语句
#### 注意使用花括号

在if和else之后必须加上花括号（while和for循环的两端也有同样的要求），避免代码混乱不清

#### 悬垂else
else与离它最近的尚未匹配的if匹配

### switch语句

方便我们在若干固定选项中作出选择

#### 注意
- **case标签必须是整型常量表达式**
- 通常在下一个case标签之前应该有一个break语句

#### switch内部变量定义

C++不允许跨过变量的初始化语句直接跳转到该变量作用域内的另一个变量

```
case true:
    string file_name; //错误：控制流绕过一个隐式初始化的变量
    int ival = 0 ; //错误：控制流绕过一个显式初始化的变量
    int jval; //jval没有初始化
    break;
case false:
    jval = next_num(); //正确：给jval赋值
    if (file_name.empty()) //file_name在作用域内，但是没有初始化
```

如果需要为某个case分支定义并初始化一个变量，应该把该变量定义在块内，从而确保后面所有的case标签都在变量的作用域之外。

```
case true:
    {
        string file_name; //错误：控制流绕过一个隐式初始化的变量
    }
    break;
case false:
    if (file_name.empty()) //错误：file_name不在作用域之内
```

## 迭代语句

### while语句
当不确定迭代多少次的时候，就使用while循环

### 传统的for语句
```
for (init-statement; condition; expression)
{
        statment
}
```
#### for语句头中多重定义
`init-statement`可以定义多个对象，但是只有一个声明语句，因此所有类型变量必须相同

#### 省略for语句头的某些部分
`condition`省略等价于在条件部分写了一个true

### 范围for循环
```
for (declaration: expression)
    statement
```
`expression`表示一个数组、花括号的初始化列表、vector或者string类型，这些类型都拥有可以返回迭代器的begin()和end()成员

### do while语句
```
do
    statment
while (condition);
```
不允许在condition部分定义变量

## 跳转语句
### break语句

break语句负责终止离它最近的while、do while、for或者switch语句，并从这些语句之后的第一条语句开始执行。
### goto语句

- 标签独立于变量或者其他标识符的名字，可以和程序中其他实体的标识符使用同一名字
- 沟通语句和控制权转向的那个标签语句必须在同一个函数之内
- 和switch语句类似，goto语句不能能够将程序的控制权从变量的作用域之外转移到作用域之内：
```
    //...
    goto end;
    int ix = 10;//跳过一个带有初始化的变量的定义
end:
    ix = 42;    //goto语句绕过了声明
```
向后跳过一个已经执行的定义是合法的。
- 跳回到变量之前意味着系统将销毁该变量，然后重新创建它

## try语句块和异常处理
### try语句块
try语句块内声明的变量在块外无法访问，特别是cache子句块内也无法访问
