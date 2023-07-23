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
    for (int i = 0; i < v.size() - 1;) {
        int new_step = 0, j = i;
        for (; j < v.size() - 1; ++j) {
            if (v.at(j) < v.at(j + 1)) {
                ++new_step;
                ++i;
            }
            else {
                break;
            }
        }
        if (new_step > max_step) {
            max_step = new_step;
        }
        i = j + 1;
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