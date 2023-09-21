#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>

auto partition_labels(std::string str) {
    std::vector<int> ans;
    std::unordered_map<char, int> last_occurring_index;
    //Find the last occuring index of each character and store it
    for (int i = 0; i < str.size(); ++i) {
        auto index = last_occurring_index.find(str[i]);
        if (index != last_occurring_index.end()) {
            index->second = i;
        }
        else {
            last_occurring_index.insert(std::pair<char, int>(str[i], i));
        }
    }

    for (int i = 0; i < str.size();) {
        int const subset_start_index = i;
        int subset_end_index = last_occurring_index.at(str[i]);
        for (int j = i + 1; j <= subset_end_index; ++j) {
            int const occuring_index = last_occurring_index.at(str[j]);
            if (occuring_index > subset_end_index) {
                subset_end_index = occuring_index;
            }
        }
        i = subset_end_index + 1;
        ans.push_back(subset_end_index - subset_start_index + 1);
    }
    return ans;
}
int main() {
    std::string str;
    std::cin >> str;
    auto ans = partition_labels(str);
    for (auto val : ans) {
        std::cout << val << " ";
    }
    std::cout << '\n';
    return 0;
}