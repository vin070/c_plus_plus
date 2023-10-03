#include<iostream>
#include<cmath>

/**
 * Q = https://leetcode.com/problems/reach-a-number/description/
 * T(n) = O(sqrt(t))
 * S(n) = O(1)
*/
auto reach_a_number(int target) {
    target = std::abs(target);
    unsigned long steps = 0, sum = 0;
    while (sum < target) {
        sum += steps;
        ++steps;
    }

    int diff = sum - target;
    while (diff % 2 != 0) {
        sum += steps;
        ++steps;
        diff = sum - target;
    }
    return steps - 1;
}

int main() {
    int target = 0;
    std::cin >> target;
    std::cout << reach_a_number(target) << '\n';
    return 0;
}