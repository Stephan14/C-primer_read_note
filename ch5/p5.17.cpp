#include <iostream>
#include <vector>

bool is_prefix(std::vector<int>& short_vec, std::vector<int>& long_vec) {
  if (short_vec.size() > long_vec.size()) {
    return is_prefix(long_vec, short_vec);
  }

  for (int index = 0; index < short_vec.size(); ++index) {
    if (short_vec[index] != long_vec[index]) {
      return false;
    }
  }

  return true;
}
int main() {

  std::vector<int> l{ 0, 1, 1, 2 };
  std::vector<int> r{ 0, 1, 1, 2, 3, 5, 8 };
  std::cout << (is_prefix(r, l) ? "yes\n" : "no\n");
  return 0;
}
