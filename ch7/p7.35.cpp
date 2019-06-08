事实上，我觉得应该这样解释：
English edition p.285；中文版：255页
Tips那里讲的很清楚:Definitions of type names usually should appear at the beginning of a class.[类型别名的定义一般出现在类定义的开头]
书上给的例子违反了这一原则（说原则可能不太合适？），类在定义了函数Account::balance后又定义了一次Money类型别名，编译器不允许这么做。
在例子前的一句话也是这么说的：However, in a class, if a member uses a name from an outer scope and that name is a type, then the class may not 【subsequently redefine】 that name.[然而，在类中，如果一个成员使用了类外作用域的类型别名，在该成员后，类不能再次定义相同名字的类型别名]
回到练习来，练习在定义类的时候立刻redefine了类型别名，在此之前没有使用原类型别名定义类成员，所以不会引发书中示例的错误，只是在定义类内成员函数的时候，编译器不知道如何匹配类内声明的double和类外声明的string。所以由Type Exercise::setVal(Type parm)修改成Exercise::Type Exercise::setVal(Type parm)，指明是类内的Type。
