#include <iostream>

int binary_search(int input[], int start_index, int last_index, int element) {
  if (start_index > last_index) return -1;

  int mid_index = (start_index + last_index) / 2;
  if (input[mid_index] == element)
    return mid_index;
  else if (element < input[mid_index])
    return binary_search(input, start_index, mid_index - 1, element);
  else
    return binary_search(input, mid_index + 1, last_index, element);
}
int binarySearch(int input[], int size, int element) {
  return binary_search(input, 0, size - 1, element);
}

int main() {
  int input[100000], length, element, ans;
  std::cin >> length;
  for (int i = 0; i < length; i++) std::cin >> input[i];

  std::cin >> element;
  ans = binarySearch(input, length, element);
  std::cout << ans << std::endl;
}
