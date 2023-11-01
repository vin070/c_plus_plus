#include <iostream>

/**
 * https://leetcode.com/problems/consecutive-numbers-sum/
 * T(n) = O(sqrt(n))
 * S(n) = O(1)
*/
int consecutive_numbers_sum(int n) {
    int ans = 1;
    for (int i = 2; 2 * n > i * (i - 1); ++i) {
        if ((n - (i * (i - 1) / 2)) % i == 0) {
            ++ans;
        }
    }
    return ans;
}

int main() {
    int n = 1;
    std::cout << consecutive_numbers_sum(n) << '\n';
    return 0;
}