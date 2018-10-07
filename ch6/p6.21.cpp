#include <iostream>

int compare(int a, const int * b) {
    return  (a > *b) ? a : *b;
}

int main() {
    int i = 7;
    std::cout << compare(8, &i);
}
