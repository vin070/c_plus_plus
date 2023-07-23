#include<iostream>
#include<vector>

//https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/searching-and-sorting/roof_top/ojquestion
void take_input(std::vector<int>& arr, int const& n) {
    for (int i = 0; i < n; ++i) {
        int input = 0;
        std::cin >> input;
        arr.push_back(input);
    }
}

/**
 * Time complexity = O(n)
 * Space complexity = O(1)
*/
void find_step(std::vector<int>& v) {
    int max_step = 0;
    int curr_max = 0;
    for (int i = 0; i < v.size() - 1; ++i) {
        if (v.at(i + 1) > v.at(i)) {
            ++curr_max;
        }
        else {
            if (curr_max > max_step) {
                max_step = curr_max;
            }
            curr_max = 0;
        }
    }
    if (curr_max > max_step) {
        max_step = curr_max;
    }
    std::cout << max_step << '\n';
}
int main() {
    std::vector<int> v;
    int n = 0;
    std::cin >> n;
    take_input(v, n);
    find_step(v);
}