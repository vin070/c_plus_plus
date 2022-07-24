#include <iostream>

int staircase(int n) {
  if (n == 0)
    return 1;
  else if (n < 0)
    return 0;

  return staircase(n - 1) + staircase(n - 2) + staircase(n - 3);
}

int main() {
  int n, output;
  std::cin >> n;
  output = staircase(n);
  std::cout << output << '\n'
}
