#include <iostream>
#include <iostream>
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <initializer_list>

class StrBlobPtr; //提前声明,但不知道包含哪些成员,不完全类型只能以有限方式使用,不能定义该类型的对象,不完全类型只能用于定义指向该类型的指针及引用,或者用于声明(而不是定义)使用该类型作为形参类型或返回类型的函数
class StrBlob {
    friend class StrBlobPtr; // 为了访问data成员
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

    StrBlobPtr begin();
    StrBlobPtr end();
private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string &msg) const { // 为了重载 front 和 back 类型
        if (i > data->size()) { // 不需要判断整数，因为size_type为无符号类型，小于0时会转化成正整数
            std::cout << msg;
        }
    }
};

class StrBlobPtr {
public:
    StrBlobPtr(): curr(0) {}
    StrBlobPtr(StrBlob &a, size_t size = 0):wptr(a.data), curr(size) {}
    std::string& deref() const;
    StrBlobPtr& incr();
    bool operator != (const StrBlobPtr &other) { return other.curr != curr; }
private:
    std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string&) const;
    std::weak_ptr<std::vector<std::string>> wptr;
    size_t curr;
};

std::shared_ptr<std::vector<std::string>> StrBlobPtr::check(std::size_t i, const std::string &msg) const {
    auto p = wptr.lock();
    if (!p) {
       throw std::runtime_error("unbound strblobptr");
    }

    if (i >= p->size()) {
        throw std::runtime_error(msg);
    }

    return p;
}

std::string& StrBlobPtr::deref() const {
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incr() {
    check(curr, "increamemt past end of StrBlobPtr");
    ++curr;
    return *this;
}

StrBlobPtr StrBlob::begin() {
    return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end() {
    auto p = StrBlobPtr(*this, data->size());
    return p;
}

std::string& StrBlob::front() {
    check(0 , "front error");
    return data->front();
}

std::string& StrBlob::back() {
    check(0, "back error");
    return data->back();
}

const std::string& StrBlob::front() const {
    check(0 , "front error");
    return data->front();
}

const std::string& StrBlob::back() const {
    check(0, "back error"); //为const类型
    return data->back();
}

