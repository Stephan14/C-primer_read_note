#include <iostream>
#include <string>


int main ()
{
    std::string sentence;
    std::string str;

    while (std::cin >> str) {
        sentence += str + "  "; 
        //sentence += str; 
    }

    std::cout << sentence << std::endl;
}
