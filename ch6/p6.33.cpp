#include <iostream>
#include <vector>

void print(std::vector<int> v, int index) {
    if (index >= v.size()) {
        return;
    }

    std::cout << v[index] << std::endl;
    print(v, index + 1);

    return;
}

int main() {
    std::vector<int> v{1, 2, 3, 4};
    print(v, 0);
}
