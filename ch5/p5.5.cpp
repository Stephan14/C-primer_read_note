#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::cin;

int main() {
  std::vector<string> score = {"F", "D", "C", "B", "A", "A++"};

  for (int g; cin >> g;) {
    string letter;
    if (g < 60) {
      letter = score[0];
    } else {
      letter = score[(g - 50) / 10];
      if (g != 100) {
          letter += g % 10 > 7 ? "+" : g % 10 < 3? "-" : "";
      }
    }

    std::cout << letter << std::endl;
  }
  return 0;
}
