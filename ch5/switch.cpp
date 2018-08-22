#include <iostream>

int main() {
  int belan = 2;

  switch (belan) {
    case 1:
      int b; //只声明不定义
      std::cout << b << std::endl;
      {
        int a = 1; //在作用域内初始化，在别的case标签中不可以使用
        std::cout << a << std::endl;
      }
      break;
    case 2:
      int c = 2; //最后case标签中可以定义变量
      //std::cout << a << std::endl;//不可以使用别的case中的变量
      std::cout << b << std::endl;
      std::cout << c << std::endl;
      break;
  }
}
