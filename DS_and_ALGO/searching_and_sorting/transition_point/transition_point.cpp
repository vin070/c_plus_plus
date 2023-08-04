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

auto transition_point(std::vector<int>& vect) {
  int index = -1;
  for(int i = 0, j = vect.size() - 1; i <= j; ){
    int const& mid = (i + j)/2;
    if(vect.at(mid) == 1) {
      index = mid;
    }
    if(vect.at(mid) >= 1) {
      j = mid - 1;
    } else if(vect.at(mid) <= 1) {
      i = mid + 1;
    }
  }
  return index;
}

int main() {
  int arr_size = 0;
  std::vector<int> vect;
  std::cin >> arr_size;
  take_input(vect, arr_size);
  std::cout<<transition_point(vect)<<'\n';
}