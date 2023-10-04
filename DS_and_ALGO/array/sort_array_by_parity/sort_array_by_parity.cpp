#include<iostream>
#include<vector>

/**
 * https://leetcode.com/problems/sort-array-by-parity/
 * T(n) = O(n)
 * S(n) = O(1)
*/
std::vector<int> sort_array_by_parity(std::vector<int>& nums) {
    for (int even_index = 0, odd_index = 0; even_index < nums.size() && odd_index < nums.size();) {
        if (even_index > odd_index && nums.at(even_index) % 2 == 0 && nums.at(odd_index) % 2 != 0) {
            std::swap(nums.at(odd_index), nums.at(even_index));
        }

        if (nums.at(even_index) % 2 != 0) {
            ++even_index;
        }
        else if (even_index <= odd_index) {
            ++even_index;
        }

        if (nums.at(odd_index) % 2 == 0) {
            ++odd_index;
        }
    }
    return nums;
}

void take_input(std::vector<int>& arr, int const& n) {
    arr.reserve(n);
    for (int i = 0; i < n; ++i) {
        int ele = 0;
        std::cin >> ele;
        arr.push_back(ele);
    }
}

int main() {
    int n = 0;
    std::vector<int> vect;
    std::cin >> n;
    take_input(vect, n);
    auto ans = sort_array_by_parity(vect);
    for (auto val : ans) {
        std::cout << val << " ";
    }
    return 0;
}