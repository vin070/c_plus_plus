#include <cstring>
#include <iostream>

unsigned long factorial(int n) {
  if (n == 0)
    return 1;

  return n * factorial(n - 1);
}

// Method 1
// int returnPermutations(std::string input, std::string output[]) {
//   if (input[0] == '\0') {
//     output[0] = "";
//     return 1;
//   }

//   int input_len = input.length();
//   int total_ans = 0;
//   for (int i = 0; i < input_len; ++i) {
//     std::string *small_ans = new std::string[factorial(input_len - 1)];
//     int ans_len =
//         returnPermutations(input.substr(0, i) + input.substr(i + 1),
//         small_ans);

//     for (int j = 0; j < ans_len; ++j)
//       output[j + total_ans] = input[i] + small_ans[j];

//     delete[] small_ans;
//     total_ans += ans_len;
//   }
//   return total_ans;
// }

// Method 2
int returnPermutations(std::string input, std::string output[]) {
  if (input[0] == '\0') {
    output[0] = "";
    return 1;
  }

  std::string *small_ans = new std::string[factorial(input.length() - 1)];
  int small_ans_len = returnPermutations(input.substr(1), small_ans);

  int possible_places = small_ans[0].length() + 1;
  for (int i = 0; i < small_ans_len; ++i) {
    for (int j = 0; j < possible_places; ++j) {
      output[i * possible_places + j] =
          small_ans[i].substr(0, j) + input[0] + small_ans[i].substr(j);
    }
  }
  delete[] small_ans;
  return possible_places * small_ans_len;
}

int main() {
  std::string input;
  std::cin >> input;
  std::string output[10000];
  int count = returnPermutations(input, output);
  for (int i = 0; i < count && i < 10000; i++)
    std::cout << output[i] << std::endl;

  return 0;
}