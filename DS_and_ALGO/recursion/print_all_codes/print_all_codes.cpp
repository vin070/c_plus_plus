#include <cstring>
#include <iostream>

void printAllPossibleCodes(std::string input, std::string output) {
  int input_len = input.length();

  if (input[0] == '\0') {
    std::cout << output << '\n';
    return;
  }
  else if(input_len < 1) return;

  int included_val = 0, excluded_val = int(input[0]) - 48;

  if (input_len >= 2)
    included_val = excluded_val * 10 + (int(input[1]) - 48);

  if (included_val >= 1 && included_val <= 26) {
    std::string included_output = output + char(96 + included_val);
    printAllPossibleCodes(input.substr(2), included_output);
  }

  std::string excluded_output = output + char(96 + excluded_val);
  printAllPossibleCodes(input.substr(1), excluded_output);
}
void printAllPossibleCodes(std::string input) {
  printAllPossibleCodes(input, "");
  return;
}

int main() {
  std::string input;
  std::cin >> input;

  printAllPossibleCodes(input);
  return 0;
}