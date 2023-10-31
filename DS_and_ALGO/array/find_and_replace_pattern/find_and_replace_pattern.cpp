#include <iostream>
#include<vector>
#include<cstring>
#include<unordered_map>

void print_arr(std::vector<std::string> const& arr) {
    for (auto val : arr) {
        std::cout << val << " ";
    }
    std::cout << '\n';
}

void take_input(std::vector<std::string>& arr, int const& n) {
    arr.reserve(n);
    for (int i = 0; i < n; ++i) {
        std::string ele = "";
        std::cin >> ele;
        arr.push_back(ele);
    }
}

auto is_matching_pattern(const std::string& word, const std::string& pattern) {
    std::unordered_map<char, char> word_to_pattern, pattern_to_word;
    for (int i = 0; i < word.size(); ++i) {
        auto word_to_pattern_it = word_to_pattern.find(word[i]);
        auto pattern_to_word_it = pattern_to_word.find(pattern[i]);
        if (pattern_to_word_it != pattern_to_word.end() && pattern_to_word_it->second != word[i]) {
            return false;
        }
        else if (word_to_pattern_it != word_to_pattern.end() && word_to_pattern_it->second != pattern[i]) {
            return false;
        }
        else {
            word_to_pattern.insert({ word[i], pattern[i] });
            pattern_to_word.insert({ pattern[i], word[i] });
        }
    }
    return true;
}

/**
 * https://leetcode.com/problems/find-and-replace-pattern/description/
 * T(n) = O(n * s * s)
 * S(n) = O(s)
*/
auto find_and_replace_pattern(const std::vector<std::string>& arr, const std::string& pattern) {
    std::vector<std::string> ans;
    for (int i = 0; i < arr.size(); ++i) {
        if (is_matching_pattern(arr[i], pattern)) {
            ans.push_back(arr[i]);
        }
    }
    return ans;
}

int main() {
    int n = 0;
    std::vector<std::string> arr;
    std::string pattern = "";
    std::cin >> n;
    take_input(arr, n);
    std::cin >> pattern;
    auto ans = find_and_replace_pattern(arr, pattern);
    print_arr(ans);
    return 0;
}