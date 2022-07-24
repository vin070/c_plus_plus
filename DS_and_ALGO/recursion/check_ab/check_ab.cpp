#include <iostream>

bool check_ab(char input[]) {
  if (input[0] == '\0') return true;

  if (input[0] == 'a' && (input[1] == '\0' || input[1] == 'a' ||
                          (input[1] == 'b' && input[2] == 'b')))
    return check_ab(input + 1);

  else if (input[0] == 'b' && input[1] == 'b' &&
           (input[2] == '\0' || input[2] == 'a'))
    return check_ab(input + 2);
  else
    return false;
}

bool checkAB(char input[]) {
  if (input[0] != 'a') return false;

  return check_ab(input);
}

int main() {
  char input[100];
  bool ans;
  std::cin >> input;
  ans = checkAB(input);
  if (ans)
    std::cout << "true" << std::endl;
  else
    std::cout << "false" << std::endl;
}