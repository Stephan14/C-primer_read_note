#include <iostream>
#include <memory>

int main() {
    int ix = 1024, *p1 = &ix;
    typedef std::unique_ptr<int> IntP;
    IntP p0(new int(1024));
    //IntP p0(p1); 错误
}
