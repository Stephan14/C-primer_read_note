## 函数

### 函数基础

#### 形参和实参

- 形参和实参的类型必须保持一致
- 但是没有规定实参的求值顺序

#### 局部对象

##### 自动对象
局部变量随着函数的控制路径经过变量的创建语句时创建，函数到达定义所在的块末尾时销毁它，称这种对象为**自动对象**。形参是一种自动变量；局部变量也是一种自动变量。

##### 局部静态对象
贯穿函数调用以及其之后的局部变量为局部静态对象，在函数的执行路径第一次创建时**初始化**，直到程序终止时才完成，即使对象所在的函数执行完成对其也没有影响。如果局部静态变量没有经过**显式初始化**，则执行默认初始化。

#### 函数声明

函数只可以被定义一次，但是可以被声明一次。

#### 分离式编译

### 参数传递

形参的类型决定了形参和实参的交互方式。如果形参是引用类型，它将绑定到对应的实参上，否则，将实参的值拷贝给形参。

#### 传值参数

##### 指针形参
可以使用指针的形参访问函数外部的对象，在C++中建议使用引用代替。

#### 传引用参数
改变引用就是改变实例对象，对于某些不支持拷贝操作时，函数只能通过引用形参访问该类型的对象
- 当参数无需修改时最好将其设置为常量引用类型
- 使用引用作为参数可以返回值使用

#### const形参和实参

- **实参初始化形参的时候会忽略掉顶层const**,当形参有顶层const时，传给他常量对象和非常量对象
- 函数重载时忽略掉顶层const

##### 指针或者引用形参参与const
- 可以使用非常量来初始化一个底层const对象
- 一个普通的对象必须使用同一个类型的对象初始化
- 尽量使用常量引用，使用普通引用而不是常量引用会极大的限制住函数所能接受的实参类型，不能把**const对象、字面值或者需要类型转换的对象传给普通的引用形参**

#### 数组形参

数组的特殊性质：
- 不允许拷贝数组
- 数组通常会被转成指针

以下三种函数声明等价：
```
void print(const int*);
void print(const int[]);
void print(const int[10]);
```

##### 注意
以数组作为形参的函数也必须确保使用数组时不会越界

##### 管理指针形参的三种方式
- 使用标记指定数组长度
要求数组本身包含一种结束标记，例如C字符串中的空格
- 使用标准库规范
传递指向数组首元素和尾后元素的指针
- 显示传递一个表示数组大小的形参

##### 数组形参和const
关于引用的讨论适用于指针，当不需要对数组的形参执行写操作的时候，数组的形参应该指向const指针；只有当函数确实需要改变元素值的时候，才能把形参定义成指向非常量的指针。

##### 数组引用形参
```
void print(int (&arr)[10]) {
    for (auto elem : arr) {
        cout << elem << endl;
    }
}
```
`&arr`两端的括号必不可少，否则声明成引用的数组。

##### 传递多维数组
```
void print(int (*matrix)[10], int rowSize);
```

###### 注意
- `int *matrix[10]`表示10个指针构成的数组
- `int (*matrix)[10]`表示指向含有10个整数的数组的指针