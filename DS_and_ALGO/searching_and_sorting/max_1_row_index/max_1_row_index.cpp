#include<iostream>
#include<vector>
#include <limits>

auto take_input(std::vector<std::vector<int>>& vect, int const& row, int const& col) {
  vect.reserve(row);
  for (int i = 0; i < row; ++i) {
    std::vector<int> row_vect;
    row_vect.reserve(col);
    for (int j = 0; j < col; ++j) {
      int ele = 0;
      std::cin >> ele;
      row_vect.push_back(ele);
    }
    vect.push_back(row_vect);
  }
}

unsigned int binary_search(std::vector<int>& vect) {
  int index = -1;
  for (int i = 0, j = vect.size() - 1; i <= j;) {
    int mid = (i + j) / 2;
    if (vect.at(mid) == 1) {
      index = mid;
      j = mid - 1;
    }
    else if (vect.at(mid) < 1) {
      i = mid + 1;
    }
  }
  return (index == -1 ? 0 : vect.size() - index);
}

auto max_1_count_in_row(std::vector<std::vector<int>>& vect) {
  unsigned int max_1_count = 0;
  unsigned int row_index = -1;
  for (int i = 0; i < vect.size(); ++i) {
    auto count = binary_search(vect.at(i));
    if (count > max_1_count) {
      max_1_count = count;
      row_index = i;
    }
  }
  return row_index;
}

int main() {
  int row = 0, col = 0;
  std::cin >> row >> col;
  std::vector<std::vector<int>> vect;
  take_input(vect, row, col);
  std::cout << max_1_count_in_row(vect) << '\n';
}