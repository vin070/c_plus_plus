#include <iostream>
#include <string>

bool checkRedundantBrackets(std::string expression) {
  if (expression[0] == '\0')
    return false;

  if ((expression[0] == '(' && expression[1] == '(') ||
      (expression[0] == '(' && expression[1] == ')') ||
      (expression[0] == '(' && expression[2] == ')'))
    return true;

  return checkRedundantBrackets(expression.substr(1));
}

int main() {
  std::string input;
  std::cin >> input;
  std::cout << ((checkRedundantBrackets(input)) ? "true" : "false");
}