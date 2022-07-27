#include <iostream>

bool split_array(int *arr, int size, int index, int arr_3_sum, int arr_5_sum) {
  if (index == size)
    return arr_3_sum == arr_5_sum;

  // Divisible by 5
  if (arr[index] % 5 == 0)
    return split_array(arr, size, index + 1, arr_3_sum, arr_5_sum + arr[index]);
  // Divisible by 3 but not 5
  else if (arr[index] % 3 == 0)
    return split_array(arr, size, index + 1, arr_3_sum + arr[index], arr_5_sum);
  // Neither divisible by 3 not 5.
  else
    return split_array(arr, size, index + 1, arr_3_sum + arr[index],
                       arr_5_sum) ||
           split_array(arr, size, index + 1, arr_3_sum, arr_5_sum + arr[index]);
}

bool split_array(int *arr, int n) { return split_array(arr, n, 0, 0, 0); }

int main() {
  int size;
  std::cin >> size;
  int *input = new int[size];
  for (int i = 0; i < size; i++)
    std::cin >> input[i];

  if (split_array(input, size))
    std::cout << "true" << std::endl;
  else
    std::cout << "false" << std::endl;

  delete[] input;
  return 0;
}