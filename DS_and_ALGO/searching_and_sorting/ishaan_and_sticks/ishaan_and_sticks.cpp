#include<iostream>
#include<vector>
#include<algorithm>

void take_input(std::vector<int>& vect, int const& size) {
  vect.reserve(size);
  for (int i = 0; i < size; ++i) {
    int ele = 0;
    std::cin >> ele;
    vect.push_back(ele);
  }
}
/**
 * https://practice.geeksforgeeks.org/problems/ishaan-and-sticks0542/1
 * T(n) = O(n)
 * S(n) = O(n)
*/
auto ishaan_and_sticks(std::vector<int>& vect) {
  std::vector<int> ans{ -1 };
  std::vector<int> freq;
  //Find frequency array
  for (int i = 0; i < vect.size(); ++i) {
    if (vect.at(i) >= freq.size()) {
      freq.resize(vect.at(i) + 1, 0);
    }
    ++freq[vect.at(i)];
  }

  for (int i = freq.size() - 1; i >= 0; --i) {
    if (freq.at(i) >= 4) {
      ans[0] = i * i;
      ans.push_back(freq.at(i) / 4);
      break;
    }
  }
  return ans;

}

int main() {
  int size = 0;
  std::vector<int> vect;
  std::cin >> size;
  take_input(vect, size);
  auto ans = ishaan_and_sticks(vect);
  std::cout << ans.at(0) << " " << ans.at(1);
}