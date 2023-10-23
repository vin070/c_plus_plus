#include <iostream>
#include<vector>
#include<climits>

void take_input(std::vector<int>& arr, int const& n) {
    arr.reserve(n);
    for (int i = 0; i < n; ++i) {
        int ele = 0;
        std::cin >> ele;
        arr.push_back(ele);
    }
}


/**
 * https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/
 * T(n) = O(n)
 * S(n) = O(n)
*/

/* Approach 1
int min_domino_rotation(std::vector<int>& top, std::vector<int>& bottom) {
  std::vector<int>top_freq, bottom_freq;
  top_freq.resize(7, 0);
  bottom_freq.resize(7, 0);
  for (int i = 0; i < top.size(); ++i) {
    ++top_freq[top[i]];
    ++bottom_freq[bottom[i]];
  }

  int ans = INT_MAX;
  for (int i = 1; i < top_freq.size(); ++i) {
    if (top_freq[i] + bottom_freq[i] >= top.size()) {
      if (top_freq[i] >= bottom_freq[i]) {
        int min_swap_count = 0;
        for (int j = 0; j < top.size(); ++j) {
          if (top[j] != i && bottom[j] == i) {
            ++min_swap_count;
          }
        }

        if (top_freq[i] + min_swap_count == top.size() && min_swap_count < ans) {
          ans = min_swap_count;
        }
      }
      else {
        int min_swap_count = 0;
        for (int j = 0; j < bottom.size(); ++j) {
          if (bottom[j] != i && top[j] == i) {
            ++min_swap_count;
          }
        }

        if (bottom_freq[i] + min_swap_count == top.size() && min_swap_count < ans) {
          ans = min_swap_count;
        }
      }
    }
  }
  return ans == INT_MAX ? -1 : ans;
}
*/

/**
 * Approach 2
*/
int min_domino_rotation(std::vector<int>& top, std::vector<int>& bottom) {
    int num_1_count = 0;
    int num_2_count = 0;
    int num_1_freq = 1;
    int num_2_freq = 1;
    for (int i = 1; i < top.size(); ++i) {
        if (top[i] == bottom[0] && top[i] != bottom[i]) {
            ++num_2_count;
        }
        else if (bottom[i] == top[0] && top[i] != bottom[i]) {
            ++num_1_count;
        }
        else if (top[i] == bottom[i] && top[i] != top[0] && top[i] != bottom[0]) {
            return -1;
        }
        else if (top[i] != bottom[0] && bottom[i] != top[0] && top[i] != top[0] && bottom[i] != bottom[0]) {
            return -1;
        }

        if (top[i] == top[0]) {
            ++num_1_freq;
        }
        if (bottom[i] == bottom[0]) {
            ++num_2_freq;
        }
    }
    if (num_1_freq == top.size() || num_2_freq == top.size()) {
        return 0;
    }
    else if (num_1_count == 0) {
        return num_2_count;
    }
    else if (num_2_count == 0) {
        return num_1_count;
    }
    else  if (num_1_count + num_1_freq == top.size() && num_1_count <= num_2_count) {
        return num_1_count;
    }
    else  if (num_2_count + num_2_freq == top.size() && num_2_count < num_1_count) {
        return num_2_count;
    }
    return -1;
}

int main() {
    int n = 0;
    std::vector<int> top, bottom;
    std::cin >> n;
    take_input(top, n);
    take_input(bottom, n);
    std::cout << min_domino_rotation(top, bottom) << '\n';
}