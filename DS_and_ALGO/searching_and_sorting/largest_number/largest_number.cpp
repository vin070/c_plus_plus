#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

void take_input(std::vector<int>& vect, int const& size) {
    for (int i = 0; i < size; ++i) {
        int ele = 0;
        std::cin >> ele;
        vect.push_back(ele);
    }
}

auto custom_sort(std::string l, std::string r) {
    return l + r > r + l;
}

auto find_max_num(std::vector<int>& vect) {
    std::string ans = "";
    std::vector<std::string> new_arr;
    for (int i = 0; i < vect.size(); ++i) {
        new_arr.push_back(std::to_string(vect.at(i)));
    }
    std::sort(new_arr.begin(), new_arr.end(), custom_sort);
    for (auto it = new_arr.cbegin(); it != new_arr.cend(); ++it) {
        ans += *it;
    }
    if (ans.length() && ans.at(0) == '0') {
        ans = "0";
    }
    return ans;
}

int main() {
    int size = 0;
    std::vector<int> vect;
    std::cin >> size;
    take_input(vect, size);
    std::cout << find_max_num(vect);
}