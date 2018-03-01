#include <iostream>
#include <string>

int main() {
    std::string str = "this is";

    for (char &s : str) {
        s = 'x'; 
        //s = "x"; error 
    }

    std::cout << str;
}
