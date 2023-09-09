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
auto majority_vote_algo(std::vector<int>& arr) {
    int val = 0, count = 0;
    for (int i = 0; i < arr.size(); ++i) {
        if (i == 0) {
            val = arr[i];
            count = 1;
        }
        else if (arr[i] != val) {
            --count;
        }
        else if (arr[i] == val) {
            ++count;
        }

        if (count == 0) {
            val = arr[i];
            count = 1;
        }
    }

    int freq = 0;
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == val) {
            ++freq;
        }
    }
    if (freq > (arr.size() / 2)) {
        std::cout << val << '\n';
    }
    else {
        std::cout << "No Majority Element exist" << '\n';
    }
}


int main() {
    int arr_size = 0;
    std::vector<int> arr;
    std::cin >> arr_size;
    take_input(arr, arr_size);
    majority_vote_algo(arr);
    return 0;
}