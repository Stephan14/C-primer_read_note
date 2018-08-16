#include <iostram>
#include <vector>
#include <string>

int main() {
  std::vector<string> score = {"F", "D", "C", "B", "A", "A++"};

  for (int g; cin >> g) {
    std::string letter = g < 60 ? score[0] : score[(g - 50)/ 10];
    letter += g % 10 > 7? "+" : g % 10 < 3? "-" : "";
  }

  std::cout << letter << std::endl;
  return 0;
}
