#include <iostream>
#include <string>


struct Person {

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

std::istream &read(std::istream &is, Person &p) {
    return is >> p.name << p.address;
}

std::ostream &print(std::ostream &os, const Person &p) {
    return os << p.name << p.address;
}

int main() {
    Person p("name", "beijing");
    std::cout << p.getName();
    return 0;
}
