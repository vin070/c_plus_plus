#include <iostream>
#include<vector>
#include<algorithm>

void take_input(std::vector<int>& arr, int const& n) {
  arr.reserve(n);
  for (int i = 0; i < n; ++i) {
    int ele = 0;
    std::cin >> ele;
    arr.push_back(ele);
  }
}
/**
 * https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/arrays-and-strings/2-sum-target-sum-unique-pairs/ojquestion
 * T(n) = O(nlogn)
 * S(n) = O(n)
*/
auto find_distinct_pair_with_sum_k(std::vector<int>& vect, int const& sum) {
  std::vector<std::pair<int, int>> ans;
  std::sort(vect.begin(), vect.end());

  for (int i = 0, j = vect.size() - 1, prev = -1000000000, next = 1000000000; i < j; ) {
    if (vect.at(i) == prev && vect.at(j) == next) {
      ++i;
      --j;
    }
    else if (vect.at(i) + vect.at(j) > sum) {
      --j;
    }
    else if (vect.at(i) + vect.at(j) < sum) {
      ++i;
    }
    else {
      std::pair<int, int> pair(vect.at(i), vect.at(j));
      ans.push_back(pair);
      prev = vect.at(i);
      next = vect.at(j);
      ++i;
      --j;
    }
  }
  return ans;
}
int main() {
  int n = 0, k = 0;
  std::vector<int> vect;
  std::cin >> n;
  take_input(vect, n);
  std::cin >> k;
  auto ans = find_distinct_pair_with_sum_k(vect, k);
  for (auto val : ans) {
    std::cout << val.first << " " << val.second << '\n';
  }
}