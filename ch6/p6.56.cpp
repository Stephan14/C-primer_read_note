#include <iostream>
#include <vector>

using Func = int(int, int);
//int func(int, int);

int add(int a, int b){
  return a + b;
}

int sub(int a, int b){
  return a - b;
}

int mul(int a, int b){
  return a * b;
}

int divs(int a, int b){
  if (b != 0)
    return a / b;
  else
    return 0;
}


int main() {
  //std::vector<decltype (func)*> operations;
  std::vector<Func*> operations;
  operations.push_back(add);
  operations.push_back(sub);
  operations.push_back(mul);
  operations.push_back(divs);

  for(auto v: operations){
    std::cout << v(2, 3) << std::endl;
  }

  return 0;
}
