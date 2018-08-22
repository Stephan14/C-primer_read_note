#include<iostream>

int main() {
  int a_count = 0, e_count = 0, i_count = 0, o_count = 0, u_count = 0;
  char ch;

  while(std::cin >> ch) {
    if (ch == 'a')
      a_count++;
    else if (ch == 'e')
      e_count++;
    else if (ch == 'i')
      i_count++;
    else if (ch == 'o')
      o_count++;
    else if (ch == 'u')
      u_count++;
  }

  std::cout << a_count << std::endl;
  std::cout << e_count << std::endl;
  std::cout << i_count << std::endl;
  std::cout << o_count << std::endl;
  std::cout << u_count << std::endl;

}
