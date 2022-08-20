#include <iostream>
#include <stack>

int *stock_span(int const *const price, int const &n) {

  std::stack<int> stk;
  int *output = new int[n];

  if (n == 0)
    return output;

  stk.push(0);
  output[0] = 1;
  for (int i = 1; i < n; ++i) {
    while (!stk.empty() && price[i] > price[stk.top()])
      stk.pop();
    if (stk.empty())
      output[i] = i + 1;
    else
      output[i] = i - stk.top();

    stk.push(i);
  }
  return output;
}

int main() {
  int size = 0;
  std::cin >> size;

  int *input = new int[size];
  for (int i = 0; i < size; i++)
    std::cin >> input[i];

  int *output = stock_span(input, size);
  for (int i = 0; i < size; i++)
    std::cout << output[i] << " ";

  std::cout << '\n';

  delete[] input;
  delete[] output;
}