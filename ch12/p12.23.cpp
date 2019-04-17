#include <iostream>
#include <memory>
#include <cstring>
#include <string>

std::shared_ptr<char> strplus(const char* p1, const char* p2) {
    std::shared_ptr<char> newstr(new char[strlen(p1)+strlen(p2)+1](), [](char *p) { delete[] p; std::cout << "end";});
    strcat(newstr.get(), p1);
    strcat(newstr.get(), p2);
    return newstr;
}

std::shared_ptr<std::string> stringplus(const std::string& p1, const std::string& p2) {
    std::shared_ptr<std::string> newstring = std::make_shared<std::string>();
    *newstring += p1;
    *newstring += p2;
    return newstring;
}

int main() {
    char* p1 = "str1";
    char* p2 = "str2";
    //const char* p1 = "str1";
    //const char* p2 = "str2";
    auto p = strplus(p1, p2);
    for (size_t i = 0; i < strlen(p.get()); i++) {
        std::cout << *(p.get() + i);
    }
    std::cout << std::endl;

    auto pstring2 = stringplus("test1", "test2");
    std::cout << *pstring2 << std::endl;
    return 0;
}
