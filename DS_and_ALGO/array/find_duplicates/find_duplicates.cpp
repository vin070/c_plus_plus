#include <iostream>
#include<vector>
#include<cmath>

void print_arr(std::vector<int> const& arr) {
    for (auto val : arr) {
        std::cout << val << " ";
    }
    std::cout << '\n';
}

void take_input(std::vector<int>& arr, int const& n) {
    arr.reserve(n);
    for (int i = 0; i < n; ++i) {
        int ele = 0;
        std::cin >> ele;
        arr.push_back(ele);
    }
}

/**
 * https://leetcode.com/problems/find-all-duplicates-in-an-array/submissions/1087580091/
 * T(n) = O(n)
 * S(n) = O(1)
*/
auto find_duplicates(std::vector<int>& arr) {
    std::vector<int> ans;
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[std::abs(arr[i]) - 1] < 0) {
            ans.push_back(std::abs(arr[i]));
        }
        else {
            arr[std::abs(arr[i]) - 1] *= -1;
        }
    }
    return ans;
}

int main() {
    int n = 0;
    std::cin >> n;
    std::vector<int> arr;
    take_input(arr, n);
    auto ans = find_duplicates(arr);
    print_arr(ans);
    return 0;
}