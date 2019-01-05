#include <iostream>
#include <string>


struct Person {

    std::string name = "name";
    std::string address;

public:

    Person(std::string name, std::string address) {
        this->name = name;
        this->address = address;
    }

    Person() {
        //name = "test1";
    }

    auto getName() const -> std::string const& { return name; } //auto 类型推倒时会忽略掉引用类型
    //decltype(auto) getName() const -> std::string const& { return name; } //auto 类型推倒时会忽略掉引用类型.c++14
    auto getAddress() const -> const std::string&  { return address; }
};

int main() {
    Person p("name_1", "beijing");
    Person t;
    std::cout << p.getName();
    std::cout << t.getName();
    return 0;
}
