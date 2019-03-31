#include <iostream>
#include <vector>
#include <memory>

std::shared_ptr<std::vector<int>> init() {
    return std::make_shared<std::vector<int>>();
}

void input(std::shared_ptr<std::vector<int>> v) {
    v->push_back(9);
    v->push_back(2);
}

void output(std::shared_ptr<std::vector<int>> v) {
    for (auto i : *v) {
        std::cout << i << std::endl;
    }
}

int main() {
    auto v = init();
    input(v);
    output(v);
}
