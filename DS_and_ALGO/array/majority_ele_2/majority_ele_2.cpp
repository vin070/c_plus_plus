#include<iostream>
#include<vector>
#include<cmath>

void print_arr(std::vector<int> const& arr) {
    for (auto val : arr) {
        std::cout << val << " ";
    }
    std::cout << '\n';
}

void take_input(std::vector<int>& arr, int const& n) {
    arr.reserve(n);
    for (int i = 0; i < n; ++i) {
        int ele = 0;
        std::cin >> ele;
        arr.push_back(ele);
    }
}

/**
 * T(n) = O(n)
 * S(n) = O(1)
 * https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/arrays-and-strings/majority-element-i/ojquestion
*/
auto majority_ele_2(std::vector<int>& arr) {
    std::vector<int> ans;
    int val_1 = 0, count_1 = 0, val_2 = 0, count_2 = 0;
    int const min_freq = arr.size() / 3;
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == val_1) {
            ++count_1;
        }
        else if (arr[i] == val_2) {
            ++count_2;
        }
        else {
            if (count_1 == 0) {
                val_1 = arr[i];
                count_1 = 1;
            }
            else if (count_2 == 0) {
                val_2 = arr[i];
                count_2 = 1;
            }
            else {
                --count_1;
                --count_2;
            }
        }
    }
    int val_1_freq = 0, val_2_freq = 0;
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == val_1 && count_1) {
            ++val_1_freq;
        }
        if (arr[i] == val_2 && count_2) {
            ++val_2_freq;
        }
    }
    if (val_1_freq > min_freq) ans.push_back(val_1);
    if (val_2_freq > min_freq) ans.push_back(val_2);
    return ans;
}


int main() {
    int arr_size = 0;
    std::vector<int> arr;
    std::cin >> arr_size;
    take_input(arr, arr_size);
    auto ans = majority_ele_2(arr);
    print_arr(ans);
    return 0;
}