#include <iostream>

int main() {
  char ch;
  int a_count = 0, e_count = 0, i_count = 0, o_count = 0, u_count = 0;

  while (std::cin >> ch) {
    switch (ch) {
      case 'a':
      case 'A':
        a_count++;
        break;
      case 'e':
      case 'E':
        e_count++;
        break;
      case 'i':
      case 'I':
        i_count++;
        break;
      case 'o':
      case 'O':
        o_count++;
        break;
      case 'u':
      case 'U':
        u_count++;
        break;
    }
  }

  std::cout << a_count << std::endl;
  std::cout << e_count << std::endl;
  std::cout << i_count << std::endl;
  std::cout << o_count << std::endl;
  std::cout << u_count << std::endl;

  return 0;
}
