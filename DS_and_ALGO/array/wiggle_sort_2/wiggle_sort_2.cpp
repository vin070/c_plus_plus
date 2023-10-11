#include<iostream>
#include<vector>
#include<cmath>
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
 * https://leetcode.com/problems/wiggle-sort-ii/description/
 * T(n) = O(nlog(n))
 * S(n) = O(n)
*/
void wiggle_sort_2(std::vector<int>& vect) {
    std::vector<int> sorted_nums(vect);
    std::sort(sorted_nums.begin(), sorted_nums.end());

    int const even_index_count = std::ceil((vect.size() * 1.0) / 2);

    //Place smallest number at even index
    for (int i = 0, count = even_index_count - 1; count >= 0; i += 2, --count) {
        vect[i] = sorted_nums[count];
    }

    //Place largest element at odd index 
    for (int i = 1, count = vect.size() - 1; count >= even_index_count; --count, i += 2) {
        vect[i] = sorted_nums[count];
    }
}

int main() {
    int n = 0;
    std::vector<int> vect;
    std::cin >> n;
    take_input(vect, n);
    wiggle_sort_2(vect);
    print_arr(vect);
    return 0;
};