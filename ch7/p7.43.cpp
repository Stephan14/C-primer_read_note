#include <iostream>

class NoDefault {
public:
    NoDefault(int i):a(i) {}
private:
    int a;
};

class C {
public:
    C(): a(0){}
    NoDefault a;
};
