#include <iostream>
#include <string>


class Person {

    std::string name;
    std::string address;

public:

    Person(std::string name, std::string address) {
        this->name = name;
        this->address = address;
    }

    auto getName() const -> std::string const& { return name; } //auto 类型推倒时会忽略掉引用类型
    //decltype(auto) getName() const -> std::string const& { return name; } //auto 类型推倒时会忽略掉引用类型.c++14
    auto getAddress() const -> const std::string&  { return address; }
};

int main() {
    Person p("name", "beijing");
    std::cout << p.getName();
    return 0;
}
