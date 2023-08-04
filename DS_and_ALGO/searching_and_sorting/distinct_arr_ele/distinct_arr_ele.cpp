#include<iostream>
#include<vector>
#include <limits>

void take_input(std::vector<int>& vect, int const& n) {
  for (int i = 0; i < n; ++i) {
    int ele = 0;
    std::cin >> ele;
    vect.push_back(ele);
  }
}

auto find_distinct_ele(std::vector<int>& vect) {
  int count = 0;
  for (int i = 0,
    j = vect.size() - 1,
    prev = std::numeric_limits<int>::min(),
    next = std::numeric_limits<int>::max();
    i <= j; ) {
    if (std::abs(vect.at(i)) == vect.at(j)) {
      if (prev != vect.at(i) && next != vect.at(j)) {
        ++count;
      }
      prev = vect.at(i);
      next = vect.at(j);
      --j;
      ++i;
    }
    else if (vect.at(j) > std::abs(vect.at(i))) {
      if (next != vect.at(j)) {
        ++count;
      }
      next = vect.at(j);
      --j;
    }
    else if (std::abs(vect.at(i)) > vect.at(j)) {
      if (prev != vect.at(i)) {
        ++count;
      }
      prev = vect.at(i);
      ++i;
    }
  }

  return count;
}

int main() {
  int arr_size = 0;
  std::vector<int> vect;
  std::cin >> arr_size;
  take_input(vect, arr_size);
  std::cout << find_distinct_ele(vect) << '\n';
}