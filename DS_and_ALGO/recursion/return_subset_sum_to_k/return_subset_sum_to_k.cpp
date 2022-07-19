#include <iostream>

int subset_sum_to_k(int input[], int n, int output[][50], int k) {
  if (k == 0) {
    output[0][0] = 0;
    return 1;
  } else if (n == 0)
    return 0;

  unsigned long output_max_size = (n * (n + 1)) / 2;
  int small_out_1[output_max_size][50];
  int small_out_2[output_max_size][50];
  int included_ans =
      subset_sum_to_k(input + 1, n - 1, small_out_1, k - input[0]);
  int excluded_ans = subset_sum_to_k(input + 1, n - 1, small_out_2, k);

  for (int i = 0; i < included_ans; ++i) {
    for (int j = 0; j <= small_out_1[i][0]; ++j) {
      if (j == 0)
        output[i][j] = small_out_1[i][j];
      else
        output[i][j + 1] = small_out_1[i][j];
    }
    ++output[i][0];
    output[i][1] = input[0];
  }

  for (int i = 0; i < excluded_ans; ++i) {
    for (int j = 0; j <= small_out_2[i][0]; ++j)
      output[i + included_ans][j] = small_out_2[i][j];
  }

  return included_ans + excluded_ans;
}

int main() {
  int input[20], length, output[10000][50], k;
  std::cin >> length;
  for (int i = 0; i < length; i++) std::cin >> input[i];

  std::cin >> k;

  int size = subset_sum_to_k(input, length, output, k);
  std::cout << "size = " << size << '\n';
  for (int i = 0; i < size; i++) {
    for (int j = 1; j <= output[i][0]; j++) std::cout << output[i][j] << " ";
    std::cout << std::endl;
  }
}