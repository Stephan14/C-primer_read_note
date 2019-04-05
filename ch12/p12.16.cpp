#include <iostream>
#include <memory>
#include <string>

int main() {
    std::unique_ptr<std::string> p1(new std::string("xxxx"));
    //std::unique_ptr<std::string> p2(p1);
    std::cout << *p1 << std::endl;
	p1.reset(nullptr);
	return 0;
}
