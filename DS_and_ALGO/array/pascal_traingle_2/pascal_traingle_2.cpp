#include <iostream>
#include<vector>

void print_arr(std::vector<int> const& arr) {
    for (auto val : arr) {
        std::cout << val << " ";
    }
    std::cout << '\n';
}

/**
 * https://leetcode.com/problems/pascals-triangle-ii/submissions/1087499036/
 * T(n) = O(n)
 * S(n) = O(n)
*/
auto get_row(int const& row_index) {
    std::vector<int> ans;
    for (int i = 0; i <= row_index; ++i) {
        if (!i || i == row_index) {
            ans.push_back(1);
        }
        else {
            int const i_cooeificent = (((long)ans[i - 1] * long(row_index - i + 1))) / i;
            ans.push_back(i_cooeificent);
        }
    }
    return ans;
}

int main() {
    int n = 0;
    std::cin >> n;
    auto ans = get_row(n);
    print_arr(ans);
    return 0;
}