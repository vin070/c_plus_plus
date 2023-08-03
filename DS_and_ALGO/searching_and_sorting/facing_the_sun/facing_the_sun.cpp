#include<iostream>
#include<vector>

void take_input(std::vector<int>& vect, int const& n) {
  for (int i = 0; i < n; ++i) {
    int ele = 0;
    std::cin >> ele;
    vect.push_back(ele);
  }
}

/**
 * https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/searching-and-sorting/distinct-absolute-array-elements-official/ojquestion
 * T(n) = O(n)
*/
auto find_sunrise(std::vector<int>& vect) {
  int count = 0;
  int max = 0;
  for (int i = 0; i < vect.size(); ++i) {
    if (vect.at(i) > max) {
      ++count;
      max = vect.at(i);
    }
  }
  return count;
}

int main() {
  int arr_size = 0;
  std::vector<int> vect;
  std::cin >> arr_size;
  take_input(vect, arr_size);
}