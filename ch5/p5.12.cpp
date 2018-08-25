#include <iostream>

int main() {
  char ch, pre_ch = '\0';
  int a_count = 0, e_count = 0, i_count = 0, o_count = 0, u_count = 0, space_count = 0, tab_count = 0, new_count = 0;
  int ff_count = 0, fl_count = 0, fi_count = 0;

  while (std::cin >> std::noskipws >> ch) { //不跳过空格
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
        if (pre_ch == 'f')  fi_count++;
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
      case ' ':
        ++space_count;
        break;
      case '\t':
        ++tab_count;
        break;
      case '\n':
        ++new_count;
        break;
      case 'l':
        if (pre_ch == 'f')
          fl_count++;
        break;
      case 'f':
        if (pre_ch == 'f')
          ff_count++;
        break;
    }
    pre_ch = ch;
  }

//  std::cout << a_count << std::endl;
//  std::cout << e_count << std::endl;
//  std::cout << i_count << std::endl;
//  std::cout << o_count << std::endl;
//  std::cout << u_count << std::endl;
//  std::cout << space_count << std::endl;
//  std::cout << tab_count << std::endl;
//  std::cout << new_count << std::endl;
  std::cout << fl_count << std::endl;
  std::cout << fi_count << std::endl;
  std::cout << ff_count << std::endl;

  return 0;
}
