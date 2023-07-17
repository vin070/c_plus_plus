//https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/searching-and-sorting/find_pivot_index/ojquestion
#include <iostream>

int pivot_index(int const* const arr, int size) {
    int left_part_sum = 0;
    int right_part_sum = 0;

    //First find the right part sum
    for (int i = 0; i < size; ++i) {
        right_part_sum += arr[i];
    }

    if (left_part_sum == right_part_sum) return 0;

    for (int i = 0; i < size;++i) {
        right_part_sum -= arr[i];
        if (i != 0) {
            left_part_sum += arr[i - 1];
        }

        if (left_part_sum == right_part_sum) return i;
    }
    return -1;
}

int main() {
    int n = 0;
    int* arr = NULL;
    std::cin >> n;
    arr = new int[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    std::cout << pivot_index(arr, n) << '\n';
    delete[] arr;
}