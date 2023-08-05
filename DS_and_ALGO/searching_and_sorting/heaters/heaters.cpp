#include<iostream>
#include<vector>
#include<algorithm>
#include<limits>

auto take_input(std::vector<int>& vect, int const& size) {
  vect.reserve(size);
  for (int i = 0; i < size; ++i) {
    int ele = 0;
    std::cin >> ele;
    vect.push_back(ele);
  }
}

/**
 * https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/searching-and-sorting/heaters-official/ojquestion
 * T(n) = nlog(m)
 * S(n) = O(1)
 * 
*/
auto binary_search(std::vector<int>& vect, int const& ele) {
  std::pair<int, int> ans(-1, -1);
  for (int i = 0, j = vect.size() - 1; i <= j;) {
    unsigned int mid = (i + j) / 2;
    if (vect.at(mid) == ele) {
      ans.first = vect.at(mid);
      ans.second = vect.at(mid);
      break;
    }
    else if (ele < vect.at(mid)) {
      j = mid - 1;
      ans.second = vect.at(mid);
    }
    else {
      i = mid + 1;
      ans.first = vect.at(mid);
    }
  }
  return ans;
}

auto min_heater_radius(std::vector<int>& houses, std::vector<int>& heaters) {
  std::sort(heaters.begin(), heaters.end());
  unsigned int max = std::numeric_limits<unsigned int>::min();
  for (int i = 0; i < houses.size(); ++i) {
    auto range = binary_search(heaters, houses.at(i));
    unsigned int left_value = range.first != -1 ? houses.at(i) - range.first : std::numeric_limits<unsigned int>::max();
    unsigned int right_value = range.second != -1 ? range.second - houses.at(i) : std::numeric_limits<unsigned int>::max();
    unsigned int heater_radius_req = std::min(left_value, right_value);
    if (heater_radius_req > max) {
      max = heater_radius_req;
    }
  }
  return max;
}

int main() {
  int houses = 0, heaters = 0;
  std::vector<int> houses_vect, heaters_vect;
  //Take houses input
  std::cin >> houses;
  take_input(houses_vect, houses);
  //Take heaters input
  std::cin >> heaters;
  take_input(heaters_vect, heaters);
  std::cout << min_heater_radius(houses_vect, heaters_vect) << '\n';
}