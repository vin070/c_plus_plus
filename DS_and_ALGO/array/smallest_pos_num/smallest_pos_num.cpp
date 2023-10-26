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
 * https://leetcode.com/vineewyueiu/
 * T(n) = O(n)
 * S(n) = O(1)
*/

int find_smallest_positive_num(std::vector<int>& arr) {
    bool is_num_one_exist = false;
    //First mark all the out of range number as 1.
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == 1) {
            is_num_one_exist = true;
        }
        else if (arr[i] < 1 || arr[i] > arr.size()) {
            arr[i] = 1;
        }
    }

    if (!is_num_one_exist) return 1;
    for (int i = 0; i < arr.size(); ++i) {
        arr[std::abs(arr[i]) - 1] = -1 * std::abs(arr[std::abs(arr[i]) - 1]);
    }

    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] >= 1) return i + 1;
    }
    return arr.size() + 1;
}

int main() {
    int n = 0;
    std::vector<int> arr;
    std::cin >> n;
    take_input(arr, n);
    std::cout << find_smallest_positive_num(arr);
    return 0;
}