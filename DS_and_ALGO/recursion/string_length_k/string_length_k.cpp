#include <cstring>
#include <iostream>

unsigned long power(int x, int n) {
  if (n <= 0)
    return 1;

  return x * power(x, n - 1);
}

int allStrings(std::string input, int k, std::string output[]) {

  if (k == 0) {
    output[0] = "";
    return 1;
  }

  int input_len = input.length();
  int ans = 0;
  for (int i = 0; i < input_len; ++i) {

    std::string *small_ans = new std::string[power(input_len, k - 1)];
    int small_ans_len = allStrings(input, k - 1, small_ans);

    for (int j = 0; j < small_ans_len; ++j)
      output[j + ans] = input[i] + small_ans[j];

    delete[] small_ans;
    ans += small_ans_len;
  }
  return ans;
}

int main() {
  std::string input;
  std::cin >> input;

  int k;
  std::cin >> k;

  std::string *output = new std::string[power(input.length(), k)];
  int count = allStrings(input, k, output);
  for (int i = 0; i < count && i < 1000; i++)
    std::cout << output[i] << std::endl;

  delete[] output;
  return 0;
}
