#include<iostream>
#include<cstring>

void reverse_str(std::string& str) {
    for (int i = 0, j = str.size() - 1; i < j; ++i, --j) {
        std::swap(str[i], str[j]);
    }
}
/**
 * https://leetcode.com/problems/add-strings/
 * T(n) = O(n)
 * S(n) = O(n)
*/
auto add_num(std::string const& num_1, std::string const& num_2) {
    std::string ans;
    int carry = 0;
    for (int i = num_1.size() - 1, j = num_2.size() - 1; i >= 0 || j >= 0; --j, --i) {
        int digit_1 = 0;
        int digit_2 = 0;
        if (i >= 0) {
            digit_1 = (int)num_1.at(i) - 48;
        }
        if (j >= 0) {
            digit_2 = (int)num_2.at(j) - 48;
        }
        int const sum = (carry + digit_1 + digit_2);
        int const remainder = sum % 10;
        carry = sum / 10;
        ans.push_back((char)(48 + remainder));
    }
    if (carry) {
        ans.push_back((char)(48 + carry));
    }
    reverse_str(ans);
    return ans;
}
int main() {
    std::string num_1;
    std::string num_2;
    std::cin >> num_1;
    std::cin >> num_2;
    std::cout << add_num(num_1, num_2) << '\n';
    return 0;
};