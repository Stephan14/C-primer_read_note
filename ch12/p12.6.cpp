#include <iostream>
#include <vector>

std::vector<int> * init() {
    return new std::vector<int>();
}

void input(std::vector<int> *v) {
    v->push_back(9);
    v->push_back(2);
}

void output(std::vector<int> *v) {
    for (auto i : *v) {
        std::cout << i << std::endl;
    }
}

int main() {
    auto v = init();
    input(v);
    output(v);
}
