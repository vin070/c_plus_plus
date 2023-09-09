#include<iostream>
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
 * T(n) = O(n)
 * S(n) = O(1)
 * https://leetcode.com/problems/container-with-most-water/submissions/
*/

auto max_water_container(std::vector<int>& vect) {
    unsigned long max_area = 0;
    for (int i = 0, j = vect.size() - 1; i < j;) {
        unsigned long area = (j - i) * std::min(vect.at(i), vect.at(j));
        if (area > max_area) {
            max_area = area;
        }
        if (vect.at(i) > vect.at(j)) {
            --j;
        }
        else {
            ++i;
        }
    }
    return max_area;
}

int main() {
    int arr_size = 0;
    std::vector<int> arr;
    std::cin >> arr_size;
    take_input(arr, arr_size);
    std::cout << max_water_container(arr) << '\n';
}