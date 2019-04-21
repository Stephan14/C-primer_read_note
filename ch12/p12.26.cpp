#include <iostream>
#include <string>
#include <memory>

int main() {
    int n = 5;
    std::allocator<std::string> all;
    auto p = all.allocate(n);
    auto q = p;

    std::string s;
    while (std::cin >> s && q != p + n) {
        all.construct(q++, s);
    }

    while (p != q) {
        std::cout << *--q << std::endl;
        all.destroy(q);
    }

    all.deallocate(p, n);
}
