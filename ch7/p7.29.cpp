#include <iostream>
#include <string>

class Screen
{
    typedef std::string::size_type pos;
public:
    Screen() = default;
    Screen(pos ht, pos wd, char c): height(ht), width(wd), content(wd*ht, c){}

    inline Screen move(pos r, pos c);
    inline Screen set(char c);

    Screen display(std::ostream &os) {
        do_display(os);
        return *this;
    }

    const Screen display(std::ostream &os) const { //在C++中，只有被声明为const的成员函数才能被一个const类对象调用。
        do_display(os);
        return *this;
    }
private:
    std::string content;
    pos height = 0, width = 0;
    pos cursor = 0;

    void do_display(std::ostream &os) const { os << content; }
};

inline Screen Screen::move(pos r, pos c) {
    cursor = r * width + c;
    return *this;
}

inline Screen Screen::set(char c) {
    content[cursor] = c;
    return *this;
}

int main() {
    Screen my(5, 5, 'x');
    my.move(3, 0).set('#').display(std::cout);
    std::cout << "\n";
    my.display(std::cout);
}
