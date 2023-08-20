#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>

auto calc_digit_count(int a) {
    std::pair<int, int> ans(0, 0);
    while (a) {
        ++ans.first;
        ans.second = a;
        a = a / 10;
    }
    return ans;
}

auto find_sequence_digits(int const& min, int const& max) {
    std::vector<int> ans;
    auto min_digit_count = calc_digit_count(min);
    auto max_digit_count = calc_digit_count(max);

    std::string eleven_mul = "";
    for (int i = 1; i < min_digit_count.first; ++i) {
        eleven_mul += std::to_string(1);
    }
    for (unsigned int i = min_digit_count.first; i <= max_digit_count.first; ++i) {
        eleven_mul += std::to_string(1);
        int eleven_mult = std::stoul(eleven_mul);

        //Find first digit
        std::string first_seq = "";
        for (int j = (i == min_digit_count.first ? min_digit_count.second : 1);
            (i == min_digit_count.first) ? (j < min_digit_count.first + min_digit_count.second) : (j <= i); ++j) {
            first_seq += std::to_string(j);
        }

        unsigned long first_seq_number = std::stoul(first_seq);
        for (int first_digit = (i == min_digit_count.first) ? min_digit_count.second : 1;
            first_digit + i - 1 <= 9 && first_seq_number <= max;
            ++first_digit) {
            if (first_seq_number >= min) {
                ans.push_back(first_seq_number);
            }
            first_seq_number += eleven_mult;
        }
    }
    return ans;
}


int main() {
    int min = 0, max = 0;
    std::cin >> min >> max;
    auto ans = find_sequence_digits(min, max);
    for (auto val : ans) {
        std::cout << val << " ";
    }
}