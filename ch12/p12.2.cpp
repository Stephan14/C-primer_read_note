#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <initializer_list>

class StrBlob {
public:
    typedef std::vector<std::string>::size_type size_type;
    StrBlob(): data(std::make_shared<std::vector<std::string>>()) {}

    StrBlob(std::initializer_list<std::string> il): data(std::make_shared<std::vector<std::string>>(il)) {}

    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    void push_back(const std::string &t) { data->push_back(t); }
    void pop_back();

    std::string& front();
    std::string& back();

    const std::string& front() const;
    const std::string& back() const;
private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string &msg) const { // 为了重载 front 和 back 类型
        if (i > data->size()) { // 不需要判断整数，因为size_type为无符号类型，小于0时会转化成正整数
            std::cout << msg;
        }
    }
};

std::string& StrBlob::front() {
    check(0 , "front error");
    std::cout << "not const";
    return data->front();
}

std::string& StrBlob::back() {
    check(0, "back error");
    return data->back();
}

const std::string& StrBlob::front() const {
    std::cout << "const";
    check(0 , "front error");
    return data->front();
}

const std::string& StrBlob::back() const {
    check(0, "back error"); //为const类型
    return data->back();
}

int main() {
    const StrBlob s = {"ss", "sb"};
    std::cout << s.front();
    StrBlob s2 = {"ss", "sb"};
    std::cout << s2.front();
    return 0;
}
