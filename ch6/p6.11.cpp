#include <iostream>

void reset(int &i) {
    i = 0;
}

int main() {
    int a = 42;
    std::cout << a << std::endl;
    reset(a);
    std::cout << a << std::endl;
}
