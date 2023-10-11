#include<iostream>
#include<vector>
#include<climits>

void take_input(std::vector<int>& arr, int const& n) {
    arr.reserve(n);
    for (int i = 0; i < n; ++i) {
        int ele = 0;
        std::cin >> ele;
        arr.push_back(ele);
    }
}

int max_chunks_to_sorted(std::vector<int>& arr) {
    std::vector<int> left_max, right_min;
    left_max.reserve(arr.size());
    right_min.resize(arr.size() + 1);

    for (int i = 0; i < arr.size(); ++i) {
        if (i == 0) {
            left_max.push_back(arr.at(i));
        }
        else {
            left_max.push_back(std::max(arr.at(i), left_max.back()));
        }
    }

    right_min[arr.size()] = INT_MAX;
    for (int i = arr.size() - 1; i >= 0; --i) {
        right_min[i] = std::min(right_min[i + 1], arr[i]);
    }

    int count = 0;
    for (int i = 0; i < left_max.size(); ++i) {
        if (left_max.at(i) <= right_min.at(i + 1)) {
            ++count;
        }
    }
    return count;
}

int main() {
    int n = 0;
    std::cin >> n;
    std::vector<int> vect;
    take_input(vect, n);
    std::cout << max_chunks_to_sorted(vect) << '\n';
    return 0;
}