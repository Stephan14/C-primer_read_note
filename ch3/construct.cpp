#include <iostream>
using namespace std;

class	A
{
	public:
		A(int i = 0):val(i){}
        //复制初始化首先使用指定构造函数创建一个临时对象，然后用复制构造函数将那个临时对象复制到正在创建的对象。
		//但是 C++ 标准允许编译器在某些特定情况下把复制构造的步骤省略掉，这样就可以节省若干临时变量,
		//可以用 -fno-elide-constructors 把这一优化关闭
	private:
		A(const A& a):val(a.val){
			cout << "come to copy create" << endl;
		}
	private:
		int val;
};

int main()
{
	A a1 = 3;
	A a2(4);
	return 0;
}
