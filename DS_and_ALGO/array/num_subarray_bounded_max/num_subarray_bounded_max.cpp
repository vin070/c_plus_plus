#include<iostream>
#include<vector>

void take_input(std::vector<int>& arr, int const& n) {
    arr.reserve(n);
    for (int i = 0; i < n; ++i) {
        int ele = 0;
        std::cin >> ele;
        arr.push_back(ele);
    }
}
unsigned long factorial(int n) {
    if (n == 0)
        return 1;

    return n * factorial(n - 1);
}

int num_subarray_bounded_max(std::vector<int>& nums, int const& left, int const& right) {
    int count = 0;
    for (int start_index = 0, prev = 0, i = 0; i < nums.size(); ++i) {
        if (nums.at(i) >= left && nums.at(i) <= right) {
            prev = i - start_index + 1;
            count += prev;
        }
        else if (nums.at(i) < left) {
            count += prev;
        }
        else if (nums.at(i) > right) {
            start_index = i + 1;
            prev = 0;
        }
    }
    return count;
}

int main() {
    int size = 0, left = 0, right = 0;
    std::vector<int> vect;
    std::cin >> size;
    take_input(vect, size);
    std::cin >> left >> right;
    std::cout << num_subarray_bounded_max(vect, left, right) << '\n';
    return 0;
}