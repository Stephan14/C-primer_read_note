## 定义抽象数据类型

### 定义改进的Sales_data类

#### 定义成员函数

- 所有成员都必须在类里面声明
- 成员函数体可以定义在类内也可以定义在类外，定义在类内部的函数是隐式的内联函数
- 成员函数通过一个名为this的额外隐式参数来访问调用它的那个对象。this是一个常量指针（例如：Sales_data *const 类型）
- 在成员函数内部可以直接使用调用该函数的对象的成员

#### 引入const成员函数
默认情况下，this指针是指向类类型非常量版本的常量指针，但是这意味着不可以把this绑定到一个常量对象上。因此，可以通过将const关键字放到成员函数的参数列表之后，将this指针声明成指向常量的指针。

- 常量对象、以及常量对象的引用或者指针都只能调用常量成员函数

#### 类作用域和成员函数

编译器首先编译成员的声明，然后才轮到成员函数体，因此，成员函数可以随意使用类中的其他成员而不需要在意声明的次序

#### 在类外定义成员函数

在类外定义成员函数的时，返回类型、参数列表和函数名必须与类内部声明的保持一致。如果为const成员函数，定义时也必须在参数列表后面明确指定const属性。

#### 定义一个返回this对象的函数
内置的赋值运算符把它的左侧运算对象当成一个左值返回，因此，必须返回一个引用类型（Sales_data &）,函数体重返回return *this。

### 定义类相关的非成员函数

### 构造函数
- 构造函数没有返回类型
- 类可以有多个构造函数，构造函数之间参数列表和参数的数量之间必须有区别
- 构造函数不能被声明为const类型

#### 合成的默认构造函数
如果没有显示的定义构造函数，那么编译器会隐式定义一个默认构造函数，默认构造函数无需任何实参，其初始化逻辑如下：
- 如果存在类内初始值，用它来初始化成员
- 否侧，默认初始化成员

#### 某些类不能依赖于合成的默认构造函数
- 一旦定义了其他构造函数，不会生成默认构造函数
- 如果类中含有内置类型或者复合类型（指针和数组），它们被默认初始化时，值是未定义的；只有内置类型和复合类型被设置初始值时，才适合使用默认构造函数
- 类中包含其他类类型成员并且这些类型也没有默认构造函数

#### =default
既需要其他类型的构造函数，也需要默认构造函数；既可以和类的声明一起出现在类的内部，此时，该构造函数为内联的；也可以作为定义出现在类的外部，此时构造函数不是内联的

##### 注意
如果类中有内置类型或者复合类型，则需要为其提供初始值

#### 构造函数初始值列表
当某个数据成员被初始化列表忽略时，使用和默认构造函数相同的方式隐式初始化该数据成员

#### 在类外部定义构造函数

### 拷贝、赋值和析构

在我们不主动定义拷贝、赋值和析构时，编译器会主动替我们合成。

#### 某些类不能依赖于合成版本
- 某些类需要依赖对象之外的资源（比如：依赖指针但是vector和string除外）

### 访问控制与封装

某个访问说明符在类中能出现多少次也没有严格的限制

#### 使用class或者struct关键字

`struct`关键字默认是public，`class`关键字默认是private

#### 友元
类可以允许通过将其他类或者函数设置为友元来访问其私有成员，并且友元声明只能出现在类定义的内部，类内具体位置不限

### 类的其他特性

#### 类成员再探

##### 定义一个类型成员
```
class Screen {
public:
    typedef std::string::size_type pos;
    //using pos = std::string::size_type;
    Screen &move(pos r, pos c);
private:
    pos cursor = 0;
    pos hight = 0, width = 0;
    std::string contents;
}

inline Screen &move(pos r, pos c) { //可以在外面指定内联函数
    pos row = r * width;
    cursor = row + c;
    return *this;
}
```

##### 可变数据成员
有时希望修改某个类的数据成员，即使在一个const成员函数中也希望修改数据成员。此时，可以通过在变量的声明前加入`mutable`关键字来实现。

```
class Screen {
public:
    void some_member() const;
private:
    mutable size_t access_ctr;
}

void some_member() const {
    access_ctr++;
}
```

##### 类数据成员的初始值
当希望类的成员变量有一个默认初始值，在C++11中可以使用类内初始值实现。

```
class Window_mgr {
private:
    std::vector<Screen>{Screen(25, 55, ' ')};
};
```
当提供一个类内初始值的时候，必须以等号或许和花括号的形式初始化。

#### 返回*this的成员函数

返回对象的本身而不是对象的副本

##### 从const成员函数返回*this
一个const成员含税如果以引用的形式返回*this，则其返回类型为常量引用。

##### 基于const的重载
由于可以根据是否是底层const变量来进行函数的重载。同样，可以根据是否是const成员函数进行重载。
```
class Scren {
public:
    Screen &display(std::ostream &os) { //this 指针从非常量转化成常量指针
        do_display(os);
        return *this;
    }

    const Screen &display(std::ostream &os) const {
        do_display(os);
        return *this;
    }
private:
    void do_display(std::ostream &os) const {
        os << contents;
    }
}；

Screen myScreen(5, 3);
const Screen blank(5,3);
myScreen.set("+").display(count);
blank.display(count);

```

#### 类类型

可以把类名直接当着类型名使用，也可以把类名跟在关键字class和struct之后。
```
Sales_data item;
class Sales_data item;
```
##### 类的声明
我们可以仅声明类而暂时不定义它，这种称为向前声明。在类的声明之后定义之前是一个不完全类型。**不完全类型只有在非常有限的情况下使用，可以定义指向这种类型的指针或者引用，也可以声明但是不可以定义以不完全类型作为参数或者返回类型的函数**。

- 在创建对象之前，该类必须被定义过，而不仅仅是被声明。
- 一个类只有全部被定义之后才被认为是定义了，所以一个类个成员不应该是成员自己；一个类的名字一旦出现之后就会被认为是类已经声明过了，因此类允许包含执行自身类型的引用和指针。

#### 友元再探
友元函数可以定义在类的内部，这样函数时隐式的内联。

##### 类之间的友元关系
```
class Screen {
    //Window_mgr 可以访问Screen 的私有部分
    friend class Window_mgr;
};
```
如果一个类指定了友元，则友元类的成员可以访问包含非公有成员在内的所有成员。同时，友元不具有传递性。

##### 令成员函数作为友元
```
class Screen {
    //Window_mgr::clear必须在这个之前被声明
    friend void Window_mgr::clear(ScreenIndex);
};
```
- 先声明友元函数，但是不能定义
- 再定义相关的友元函数的依赖的类
- 最后定义相关的友元函数

##### 函数重载和友元
如果一个类想把一组重载函数声明成他的友元函数，需要对这组中的函数每一个分别进行声明。
```
extern std::ostream& storeOn(std::ostream&, Screen &);
extern BitMap& storeOn(BitMap&, Screen &);
class Screen {
    friend std::ostream& storeOn(std::ostream&, Screen &);
};
```
接受ostream&的storeOn函数声明成它的友元函数，但是接受BitMap&作为参数的版本依然不能访问Screen

##### 友元声明和作用域
```
struct X {
    friend void f() {/*友元函数可以定义在类的内部*/}
    X() { f(); } //错误：f还没有被声明
    void g();
    void h();
};
void X::g() { return f() }; // 错误：f还没有被声明
void f();
void X::h() { return f()}; // 正确
```

### 类的作用域

##### 作用域和定义在类外部的成员

一旦遇到了类名，定义的剩余部分就在类的作用域之内，剩余部分包括参数列表和函数体。例如：
```
void Window_mgr::clear(ScreenIndex i) {
  Screen &s = screens[i];
  s.contents = string(s.height * s.width, ' ')
}
```
函数的返回类型通常出现在函数名之前，也就是意味着当成员函数的定义在类的外部时，返回类型中使用的名字都位于类的作用域之外，这时返回类型需要指明是哪一个类的。例如：
```
Window_mgr::ScreenIndex Window_mgr::addScreen(const Screen &s) {
  screens.push_back(s);
  return screens.size() - 1;
}
```

#### 名字查找与类的作用域

成员函数体直到整个类可见后才会被处理，所以可以使用类中的任何名字。

#### 用于类成员声明的名字查找
上面说的只是适用于成员函数中使用的名字，对于声明中使用的名字（包括返回类型或者参数列表中的名字），都必须确保在使用前可见。例如：
```
typedef double Money;
string bal;
class Account {
public:
  Money balance() { return bal;  //返回值为类内的bal而非类外的bal, 因为balance函数体在整个类可见后才被处理；对于Money在Account类没有找到，所以会到类外进行查找}
private:
  Money bal;
};
```

#### 类型名要特殊处理
一般情况下，在内层作用域可以重新定义外层作用域的名字，即使该名字已经在内存作用域中使用；但是，在类中却不行，例如：
```
typedef double Money;
string bal;
class Account {
public:
  Money balance() { return bal; }  //使用外层Money
private:
typedef double Money;  //错误
  Money bal;
};
```

#### 成员定义中的普通块作用域的名字查找

查找顺序：
- 在成员函数内部查找该名字的声明
- 在类的内部继续查找，所有成员都被考虑
- 在成员函数定义之前的作用域内继续查找
```
int height;
class Screen {
public:
  typedef std::string::size_type pos;
  void dummy_fcn(pos height) {
    cursor = width * height;
  }

  //void dummy_fcn(pos height) {
  //  cursor = width * this->height;
  //  cursor = width * Screen::height;
  //  cursor = width * ::height;
  //}
private:
  pos cursor = 0;
  pos height = 0, width = 0;
};

```
