#include <iostream>
#include <string>

int main() {
  std::string cur_word, pre_word;

  while (std::cin >> cur_word) {
    if (cur_word == pre_word) {
      std::cout << cur_word << std::endl;
      break;
    }

    pre_word = cur_word;
  }
  return 0;
}
