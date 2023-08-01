#include<iostream>
#include<vector>

void take_input(std::vector<int>& vect, int const& n) {
  for (int i = 0; i < n; ++i) {
    int ele = 0;
    std::cin >> ele;
    vect.push_back(ele);
  }
}

auto print_XOR_pairs(std::vector<int>& vect) {
  std::vector<int> freq;
  for (int i = 0; i < vect.size(); ++i) {
    if (vect.at(i) < freq.size()) {
      ++freq.at(vect.at(i));
    }
    else {
      freq.resize(vect.at(i) + 1, 0);
      freq[vect.at(i)] = 1;
    }
  }

  int count = 0;
  for (int i = 0; i < freq.size(); ++i) {
    if (freq.at(i) > 1) {
      count += (freq.at(i) * (freq.at(i) - 1)) / 2;
    }
    else {
      continue;
    }
  }
  return count;
}

int main() {
  int arr_size = 0;
  std::vector<int> vect;
  std::cin >> arr_size;
  take_input(vect, arr_size);
  std::cout << print_XOR_pairs(vect) << '\n';
}