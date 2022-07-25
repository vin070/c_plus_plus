#include <cstring>
#include <iostream>

void copy_char(char source[], char destination[], int const from_index,
               int const to_index) {
  for (int i = from_index, j = 0; i < to_index; ++i, ++j) {
    destination[j] = source[i];
  }
  destination[to_index - from_index + 1] = '\0';
}

bool checksequenece(char large[], char small[]) {
  int small_len = std::strlen(small), large_len = std::strlen(large);

  if (small[0] == '\0')
    return true;
  else if (small_len > large_len)
    return false;

  bool small_ans = false;
  char *large_arr = new char[large_len];
  copy_char(large, large_arr, 1, large_len);

  if (large[0] == small[0]) {
    char *small_arr = new char[small_len];
    copy_char(small, small_arr, 1, small_len);
    small_ans = checksequenece(large_arr, small_arr);
    delete[] small_arr;
  } else
    small_ans = checksequenece(large_arr, small);

  delete[] large_arr;
  return small_ans;
}

int main() {
  char large[10000];
  char small[10000];
  std::cin >> large;
  std::cin >> small;
  bool x = checksequenece(large, small);
  if (x)
    std::cout << "true";
  else
    std::cout << "false";
}