#include <iostream>

void print_array(int const array[], int const size) {
  for (int i = 0; i < size; ++i) std::cout << array[i] << " ";

  std::cout << '\n';
  return;
}

void copy_array(int copy_from[], int copy_to[], int copy_from_size) {
  for (int i = 0; i < copy_from_size; ++i) copy_to[i] = copy_from[i];
}

void print_subsets_of_array(int input[], int size, int ans[], int ans_size) {
  if (size == 0) {
    print_array(ans, ans_size);
    return;
  }

  int small_ans[ans_size + 1] = {};
  copy_array(ans,small_ans, ans_size);
  small_ans[ans_size] = input[0];

  print_subsets_of_array(input + 1, size - 1, small_ans, ans_size + 1);
  print_subsets_of_array(input + 1, size - 1, ans, ans_size);
}

void print_subsets_of_array(int input[], int size) {
  int ans[size] = {};
  print_subsets_of_array(input, size, ans, 0);
}

int main() {
  int input[1000], length;
  std::cin >> length;
  for (int i = 0; i < length; ++i) std::cin >> input[i];

  print_subsets_of_array(input, length);
  return 0;
}