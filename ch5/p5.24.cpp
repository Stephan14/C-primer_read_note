#include <iostream>

int main() {
  int i, j;
  try {
    std::cin >> i >> j;
    if (j == 0) {
      throw std::runtime_error("0 exception");
    }
  }  catch (std::runtime_error err) {
    std::cout << err.what() << std::endl;
  }
  std::cout << i / j << std::endl;
  return 0;
}
