#include<iostream>
#include<cmath>
#include<vector>

#ifndef min_val
#define min_val -1001
#endif

#ifndef max_val
#define max_val 1001
#endif

/**
 * https://leetcode.com/problems/maximum-product-of-three-numbers/description/?source=submission-noac
 * T(n) = O(n)
 * S(n) = O(1)
*/
int maximum_product(std::vector<int>& nums) {
    int min_1 = max_val;
    int min_2 = max_val;
    int    max_1 = min_val;
    int    max_2 = min_val;
    int    max_3 = min_val;

    for (int i = 0; i < nums.size(); ++i) {
        if (nums.at(i) < 0) {
            if (nums.at(i) < min_1) {
                min_2 = min_1;
                min_1 = nums.at(i);
            }
            else if (nums.at(i) < min_2) {
                min_2 = nums.at(i);
            }
        }
        if (nums.at(i) > max_1) {
            max_3 = max_2;
            max_2 = max_1;
            max_1 = nums.at(i);
        }
        else if (nums.at(i) > max_2) {
            max_3 = max_2;
            max_2 = nums.at(i);
        }
        else if (nums.at(i) > max_3) {
            max_3 = nums.at(i);
        }
    }
    if (min_1 != max_val && min_2 != max_val && max_1 >= 0) {
        return std::max(min_1 * min_2, max_2 * max_3) * max_1;
    }
    return max_1 * max_2 * max_3;

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
    std::cout << maximum_product(vect) << '\n';
    return 0;
}