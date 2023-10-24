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

/**
 * https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/arrays-and-strings/2-sum-target-sum-unique-pairs/ojquestion
 * T(n) = O(nlogn)
 * S(n) = O(n)
*/
auto find_distinct_pair_with_sum_k(std::vector<int>& vect, int const& sum) {
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

/**
 * https://leetcode.com/problems/3sum/
 * T(n) = O(n)
 * O(n) = O(n^2)
*/
auto three_sum(std::vector<int>& vect) {
    std::vector<std::vector<int>> ans;
    std::sort(vect.begin(), vect.end());
    int prev_i = 100001;
    for (auto it = vect.begin(); it != vect.end(); ++it) {
        if (prev_i != *it) {
            std::vector<int> sub_arr(it, vect.end());
            auto two_pair_sum = find_distinct_pair_with_sum_k(sub_arr, (-1) * (*it));
            for (auto val : two_pair_sum) {
                std::vector<int> pair = { *it, val.first, val.second };
                ans.push_back(pair);
            }
            prev_i = *it;
        }
    }
    return ans;
}

int main() {
    int n = 0, sum = 0;
    std::vector<int> vect;
    std::cin >> n;
    take_input(vect, n);
    auto ans = three_sum(vect);
    for (auto triplet_pair : ans) {
        print_arr(triplet_pair);
        std::cout << '\n';
    }
}