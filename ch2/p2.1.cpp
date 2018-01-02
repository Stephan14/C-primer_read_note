#include <iostream>

using namespace std;

int main() {
	bool b = 42;
	cout << "b = " << b << endl;
	int  i = b; // i 为1
	cout << "i = " << i << endl;
	i = 3.14;   // i 为3
	cout << "i = " << i << endl;
	double pi = i;
	cout << "pi = " << pi << endl; 
	unsigned char c = -1; // 该数对256取模后的余数
	cout << "c = " << c << endl;
	signed char c2 = 256;
	cout << "c2 = " << c2 << endl;
	return 0;
}
