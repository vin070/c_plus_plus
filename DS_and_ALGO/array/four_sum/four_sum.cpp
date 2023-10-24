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

void print_arr(std::vector<int> const& arr) {
    for (auto val : arr) {
        std::cout << val << " ";
    }
    std::cout << '\n';
}


auto find_distinct_pair_with_sum_k(std::vector<int>& vect, long const& sum) {
    std::vector<std::pair<int, int>> ans;
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

auto three_sum(std::vector<int>& vect, long const target) {
    std::vector<std::vector<int>> ans;
    int prev_i = 100001;
    for (auto it = vect.begin(); it != vect.end(); ++it) {
        if (prev_i != *it) {
            std::vector<int> sub_arr(it + 1, vect.end());
            auto two_pair_sum = find_distinct_pair_with_sum_k(sub_arr, target - *it);
            for (auto val : two_pair_sum) {
                std::vector<int> pair = { *it, val.first, val.second };
                ans.push_back(pair);
            }
            prev_i = *it;
        }
    }
    return ans;
}

/**
 * https://leetcode.com/problems/4sum/
 * T(n) = O(n^3)
 * S(n) = O(n^4)
*/
auto four_sum(std::vector<int>& vect, long const target) {
    std::vector<std::vector<int>> ans;
    std::sort(vect.begin(), vect.end());
    int prev_i = 100001;
    for (auto it = vect.begin(); it != vect.end(); ++it) {
        if (prev_i != *it) {
            std::vector<int> sub_arr(it + 1, vect.end());
            auto three_pair_sum = three_sum(sub_arr, target - *it);
            for (auto val : three_pair_sum) {
                std::vector<int> pair = { *it, val[0], val[1], val[2] };
                ans.push_back(pair);
            }
            prev_i = *it;
        }
    }
    return ans;
}

int main() {
    int n = 0, target = 0;
    std::vector<int> vect;
    std::cin >> n;
    take_input(vect, n);
    std::cin >> target;
    auto ans = four_sum(vect, target);
    for (auto triplet_pair : ans) {
        print_arr(triplet_pair);
    }
}