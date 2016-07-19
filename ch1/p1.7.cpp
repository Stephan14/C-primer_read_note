#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "/*";
    std::cout << "*/";
    std::cout << /* "*/" */;//编译通不过
    std::cout << /* "*/" /* "*/" */;//编译通不过
    
    return 0;
}
