#include <iostream>

void print_array(int const *const array, int const size) {
  for (int i = 0; i < size; ++i) {
    std::cout << array[i];
    if (i + 1 != size) std::cout << " ";
  }
  std::cout << '\n';
  return;
}

void print_subset_sum_to_k(int input[], int size, int k, int ans[],
                           int ans_size) {
  if (k == 0) {
    print_array(ans, ans_size);
    return;
  } else if (size == 0)
    return;

  int *small_ans = new int[ans_size + 1];
  for (int i = 0; i < ans_size; ++i) small_ans[i] = ans[i];

  small_ans[ans_size] = input[0];
  print_subset_sum_to_k(input + 1, size - 1, k - input[0], small_ans,
                        ans_size + 1);
  print_subset_sum_to_k(input + 1, size - 1, k, ans, ans_size);

  delete[] small_ans;
}

void print_subset_sum_to_k(int input[], int size, int k) {
  int *ans = new int[size];
  print_subset_sum_to_k(input, size, k, ans, 0);
  delete[] ans;
}

int main() {
  int input[1000], length, k;
  std::cin >> length;
  for (int i = 0; i < length; i++) std::cin >> input[i];
  std::cin >> k;
  print_subset_sum_to_k(input, length, k);
}