#include<iostream>
#include<vector>
#include<algorithm>

void take_input(std::vector<int>& vect, int const& n) {
  for (int i = 0; i < n; ++i) {
    int ele = 0;
    std::cin >> ele;
    vect.push_back(ele);
  }
}

/**
 * https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/searching-and-sorting/counting-elements-in-two-arrays-official/ojquestion
 * Time complexity = O(n)
 * Space complexity = O(n)
*/
std::vector<int> count_ele(std::vector<int>& vect1, std::vector<int>& vect2) {
  std::vector<int> freq;
  std::vector<int> ans;
  for (int i = 0; i < vect2.size(); ++i) {
    if (vect2.at(i) < freq.size()) {
      ++freq.at(vect2.at(i));
    }
    else {
      freq.resize(vect2.at(i) + 1, 0);
      freq.insert(freq.begin() + vect2.at(i), 1);
    }
  }

  for (int i = 1; i < freq.size(); ++i) {
    freq[i] += freq[i - 1];
  }

  for (int i = 0; i < vect1.size(); ++i) {
    ans.push_back(vect1[i] < freq.size() ? freq[vect1[i]] : freq.at(freq.size() - 1));
  }
  return ans;
}

int main() {
  std::vector<int> vect1, vect2;
  int arr1_size = 0, arr2_size = 0;
  std::cin >> arr1_size;
  std::cin >> arr2_size;
  vect1.reserve(arr1_size);
  vect2.reserve(arr2_size);
  take_input(vect1, arr1_size);
  take_input(vect2, arr2_size);
  std::vector<int> ans = count_ele(vect1, vect2);
  for (int i = 0; i < ans.size(); ++i) {
    std::cout << ans.at(i) << " ";
  }
}