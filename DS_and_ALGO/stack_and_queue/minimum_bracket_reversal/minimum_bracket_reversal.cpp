#include <iostream>
#include <stack>
#include <string>

int count_bracket_reversals(std::string input) {
  int len = input.length();
  if (len % 2 != 0)
    return -1;
  std::stack<char> stk;
  for (int i = 0; i < len; ++i) {
    if (!stk.empty() && stk.top() == '{' && input[i] == '}')
      stk.pop();
    else
      stk.push(input[i]);
  }

  int count = 0;
  while (!stk.empty()) {
    char c2, c1;
    c2 = stk.top();
    stk.pop();
    c1 = stk.top();
    stk.pop();

    count += c1 == c2 ? 1 : 2;
  }
  return count;
}

int main() {
  std::string input;
  std::cin >> input;
  std::cout << count_bracket_reversals(input);
}