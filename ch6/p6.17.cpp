#include<iostream>

bool is_big_alphabet(const std::string& str) {
    for (auto ch : str) {
        if (ch >= 65 && ch <= 90) {
            return true;
        }
    }

    return false;
}

void change_alphabet(std::string& str) {
    for (auto &ch : str) {
        if (ch >= 65 && ch <= 90) {
            ch += 32;
        }
    }
}

int main() {
    std::string str = "xxxxxxAZRRR";
    std::cout << is_big_alphabet(str) << std::endl;
    change_alphabet(str);
    std::cout << str << std::endl;
}
