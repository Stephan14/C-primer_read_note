#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> vec{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  for (auto &one : vec) {
      one = (one & 0x01) ? one * 2 : one;
  }
  return 0;
}
