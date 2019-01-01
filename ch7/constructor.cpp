#include <iostream>
#include <string>
#include <vector>

using namespace std;

class MyString {
    private:
        char* _data;
        size_t   _len;
        void _init_data(const char *s) {
            _data = new char[_len+1];
            memcpy(_data, s, _len);
            _data[_len] = '\0';
        }
    public:
        MyString() {
            std::cout << "Default Constructor" <<std::endl;
            _data = NULL;
            _len = 0;
        }

        MyString(const char* p) {
            std::cout << "Constructor by " + string(p) << std::endl;
            _len = strlen (p);
            _init_data(p);
        }

        MyString(const MyString& str) {
            _len = str._len;
            _init_data(str._data);
            std::cout << "Copy Constructor is called! source: " << str._data << std::endl;
        }

        MyString& operator=(const MyString& str) {
            if (this != &str) {
                _len = str._len;
                _init_data(str._data);
            }
            std::cout << "Copy Assignment is called! source: " << str._data << std::endl;
            return *this;
        }

        MyString(MyString&& str) {
            std::cout << "Move Constructor is called! source: " << str._data << std::endl;
            _len = str._len;
            _data = str._data;
            str._len = 0;
            str._data = NULL;
        }

        MyString& operator=(MyString&& str) {
            std::cout << "Move Assignment is called! source: " << str._data << std::endl;
            if (this != &str) {
                _len = str._len;
                _data = str._data;
                str._len = 0;
                str._data = NULL;
            }
            return *this;
        }

        virtual ~MyString() {
            std::cout << "Running Destoring" << std::endl;
            if (_data) {
                std::cout << "data is not null" << std::endl;
                std::cout << _data << std::endl;
                free(_data);
            } else {
                std::cout << "data is null" << std::endl;
            }
        }
};

int main() {
    MyString a;
    a = MyString("Hello");
    std::vector<MyString> vec;
    vec.push_back(MyString("World"));
}
