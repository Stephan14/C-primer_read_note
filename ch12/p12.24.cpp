#include <iostream>
#include <memory>
#include <string>


int main() {
    std::shared_ptr<std::string> p = std::make_shared<std::string>();
    std::cin >> *p.get();
    std::cout << std::endl << *p.get();
    return 0;
}
