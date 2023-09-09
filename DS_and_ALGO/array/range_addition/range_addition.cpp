#include<iostream>
#include<vector>

void take_query_input(std::vector<std::vector<int>>& query_arr, int const& query_arr_size) {
    for (int i = 0; i < query_arr_size; ++i) {
        std::vector<int> arr;
        for (int j = 0; j < 3; ++j) {
            int ele = 0;
            std::cin >> ele;
            arr.push_back(ele);
        }
        query_arr.push_back(arr);
    }
}
void print_arr(std::vector<int> const& arr) {
    for (auto val : arr) {
        std::cout << val << " ";
    }
    std::cout << '\n';
}

/**
 * https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/arrays-and-strings/range_addition/ojquestion
 * T(n) = O(n) if arr_size > query_arr_size
 * T(n) = O(q) if query_arr_size > arr_size
 * S(n) = O(n)
*/
void range_addition(std::vector<std::vector<int>> const& query_arr, std::vector<int>& arr) {
    std::vector<int> prefix_sum_arr;
    prefix_sum_arr.resize(arr.size() + 1, 0);
    for (int i = 0; i < query_arr.size(); ++i) {
        prefix_sum_arr[query_arr[i][0]] += query_arr[i][2];
        prefix_sum_arr[query_arr[i][1] + 1] += (-1 * query_arr[i][2]);
    }
    for (int i = 0; i < prefix_sum_arr.size(); ++i) {
        prefix_sum_arr[i] += (!i ? 0 : prefix_sum_arr[i - 1]);
    }
    arr.assign(prefix_sum_arr.begin(), prefix_sum_arr.end() - 1);
}


int main() {
    int arr_size = 0;
    int query_size = 0;
    std::vector<int> arr;
    std::vector<std::vector<int>> query_arr;
    std::cin >> arr_size >> query_size;
    take_query_input(query_arr, query_size);
    arr.resize(arr_size, 0);
    range_addition(query_arr, arr);
    print_arr(arr);
}