#include <cstring>
#include <iostream>
#include <stack>

bool isBalanced(std::string expression) {
  int len = expression.length();
  std::stack<char> s;

  for (int i = 0; i < len; ++i) {
    if (expression[i] == '(')
      s.push(expression[i]);
    else if (expression[i] == ')') {
      if (s.empty())
        return false;
      else if (s.top() == '(' && expression[i] == ')')
        s.pop();
    }
  }
  if (s.empty()) return true;
  return false;
}

int main() {
  std::string input;
  std::cin >> input;
  std::cout << ((isBalanced(input)) ? "true" : "false") << std::endl;
  return 0;
}