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
/**
 * https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
 * T(n) = O(n)
 * S(n) = O(1)
*/
int find_unsorted_subarray(std::vector<int>& nums) {
    int max_index = 0;
    int right_transition_index = -1;
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] < nums[max_index]) {
            right_transition_index = i;
        }
        else if (nums[i] > nums[max_index]) {
            max_index = i;
        }
    }
    if (right_transition_index == -1) return 0;

    int min_index = nums.size() - 1;
    int left_transition_index = -1;
    for (int i = nums.size() - 2; i >= 0; --i) {
        if (nums[i] > nums[min_index]) {
            left_transition_index = i;
        }
        else if (nums[i] < nums[min_index]) {
            min_index = i;
        }
    }
    return right_transition_index - left_transition_index + 1;

}
int main() {
    int n = 0;
    std::vector<int> vect;
    std::cin >> n;
    take_input(vect, n);
    std::cout << find_unsorted_subarray(vect) << '\n';
    return 0;
};