#include<iostream>
#include<cstring>

/**
 * https://leetcode.com/problems/multiply-strings/
 * T(n) = O(n*m)
 * S(n) = O(n + m)
*/
auto mul_nums(std::string const& num_1, std::string const& num_2) {
    std::string ans;
    ans.resize(num_1.size() + num_2.size() + 1, (char)48);
    for (int i = num_1.size() - 1;i >= 0; --i) {
        int carry = 0;
        for (int j = num_2.size() - 1; j >= 0; --j) {
            int const product = (num_1[i] - 48) * (num_2[j] - 48) + carry + (ans[i + j + 2] - 48);
            int const remainer = product % 10;
            carry = product / 10;
            //ans.size() - 1 - (num_1.size() - 1 - i) - (num_2.size() - 1 - j) = 2 + i + j
            ans[i + j + 2] = (char)(48 + remainer);
        }
        //ans.size() - 1 - num_2.size() - (num_1.size() - 1 - i) = 1 + i
        ans[i + 1] = (char)(48 + carry);
    }

    //Remove leading zero
    int last_leading_zero_index = ans.size() - 1;
    for(int i = 0; i < ans.size() - 1; ++i) {
        if(ans[i] == '0' && ans[i + 1] != '0') {
            last_leading_zero_index = i + 1;
            break;
        }
    }
    return ans.substr(last_leading_zero_index);
}
int main() {
    std::string num_1;
    std::string num_2;
    std::cin >> num_1;
    std::cin >> num_2;
    std::cout << mul_nums(num_1, num_2) << '\n';
    return 0;
};