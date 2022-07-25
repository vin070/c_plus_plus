#include <iostream>
#include <string>

// Method 1
// void printPermutations(std::string input, std::string output) {
//   if (input[0] == '\0') {
//     std::cout << output << std::endl;
//     return;
//   }

//   for (int i = 0; i < input.length(); ++i) {
//     printPermutations(input.substr(0, i) + input.substr(i + 1),
//                       input[i] + output);
//   }
// }

// Method 2
void printPermutations(std::string input, std::string output) {
  if (input[0] == '\0') {
    std::cout << output << std::endl;
    return;
  }

  for (int i = 0; i < output.length() + 1; ++i) {
    std::string small_out = output.substr(0, i) + input[0] + output.substr(i);
    printPermutations(input.substr(1), small_out);
  }
}
void printPermutations(std::string input) {
  printPermutations(input, "");
  return;
}
int main() {
  std::string input;
  std::cin >> input;
  printPermutations(input);
  return 0;
}