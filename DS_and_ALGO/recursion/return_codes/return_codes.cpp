#include <iostream>
#include <cstring>

unsigned long power(int x, int n) {
  if (n == 0)
    return 1;
  else if (n < 0)
    return 0;
  return x * power(x, n - 1);
}

int get_codes(std::string input, std::string output[10000]) {
  if (input[0] == '\0') {
    output[0] = "";
    return 1;
  }

  std::string *combined = new std::string[power(2, input.length() - 2) + 2];
  std::string *not_combined = new std::string[power(2, input.length() - 1) + 2];

  int excluded_decimal_val = (int(input[0]) - 48);
  int included_decimal_val = 27;
  if (input.length() >= 2)
    included_decimal_val = excluded_decimal_val * 10 + (int(input[1]) - 48);

  int next_combined_len = 0;
  if (input.length() >= 2 && included_decimal_val >= 1 &&
      included_decimal_val <= 26)
    next_combined_len = get_codes(input.substr(2), combined);

  int next_not_combined_len = get_codes(input.substr(1), not_combined);

  for (int i = 0; i < next_combined_len; ++i)
    output[i] = char(96 + included_decimal_val) + combined[i];

  for (int i = 0; i < next_not_combined_len; ++i)
    output[i + next_combined_len] =
        char(96 + excluded_decimal_val) + not_combined[i];

  delete[] combined;
  delete[] not_combined;
  output[next_combined_len + next_not_combined_len] = '\0';
  return next_combined_len + next_not_combined_len;
}

int main() {
  std::string input;
  std::cin >> input;

  std::string output[10000];
  int count = get_codes(input, output);
  for (int i = 0; i < count && i < 10000; i++)
    std::cout << output[i] << std::endl;
  return 0;
}
