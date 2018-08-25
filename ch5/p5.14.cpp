#include <iostream>
#include <map>

int main() {
  std::pair<std::string, int> word_count_pair;
  int count = 0;

  for (std::string cur_word, pre_word; std::cin >> cur_word; pre_word = cur_word) {
    if (cur_word == pre_word) {
      count++;
    } else {
      count = 0;
    }

    if (count > word_count_pair.second) {
      word_count_pair = {cur_word, count};
    }
  }

  if (word_count_pair.first.empty()) {
    std::cout << "no " << std::endl;
  } else {
    std::cout << word_count_pair.first << " " << word_count_pair.second << std::endl;
  }

  return 0;
}
