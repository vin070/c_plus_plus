#include <cstring>
#include <iostream>

const std::string keypad_code_mapping[] = {"",    "",    "abc",  "def", "ghi",
                                           "jkl", "mno", "pqrs", "tuv", "wxyz"};

void print_keypad(int num, std::string ans) {
  if (num == 0) std::cout << ans << '\n';

  std::string keypad_code = keypad_code_mapping[num % 10];
  int keypad_code_length = keypad_code.length();
  for (int i = 0; i < keypad_code_length; ++i) {
    std::string small_ans = keypad_code[i] + ans;
    print_keypad(num / 10, small_ans);
  }
}

void print_keypad(int num) {
  if (num <= 1) return;

  print_keypad(num, "");
}

int main() {
  int num;
  std::cin >> num;
  print_keypad(num);
  return 0;
}