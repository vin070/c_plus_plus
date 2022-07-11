#include <iostream>

long sum(int const *const input, int n) {
  if (n == 1) return input[0];

  return input[n - 1] + sum(input, n - 1);
}

int main() {
  int n;
  std::cin >> n;

  int *input = new int[n];

  for (int i = 0; i < n; i++) std::cin >> input[i];

  std::cout << sum(input, n) << '\n';
  delete[] input;
}