#include<iostream>
#include<queue>
#include<cmath>
#include<algorithm>

template<typename T>
void take_input(T* arr, int const n) {
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
}

int binary_search(int const* const arr, int const& start_index, int const& last_index, int const& ele) {
    if (start_index >= last_index) {
        return start_index;
    }

    int mid = (start_index + last_index) / 2;
    if (ele < arr[mid]) {
        return binary_search(arr, start_index, mid - 1, ele);
    }
    else {
        return binary_search(arr, mid, last_index, ele);
    }
}

template<typename T>
void print(T const* const arr, int const& n) {
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << ' ';
    }
}
//Approach using binary search()
void k_nearest_ele_binary(int const* const arr, int const& n, int const& k, int const& ele) {
    int right_pos = binary_search(arr, 0, n - 1, ele);
    int i = right_pos - 1, j = right_pos, l = 0;
    std::vector<int> ans(k);
    while (i >= 0 && j < n && l < k) {
        if (std::abs(arr[i] - ele) < std::abs(arr[j] - ele) ||
            (std::abs(arr[i] - ele) == std::abs(arr[j] - ele) && arr[i] < arr[j])) {
            ans.push_back(arr[i]);
            --i;
        }
        else {
            ans.push_back(arr[j]);
            ++j;
        }
        ++l;
    }

    while (l < k && i >= 0) {
        ans.push_back(arr[i]);
        --i;
        ++l;
    }

    while (l < k && j < n) {
        ans.push_back(arr[j]);
        ++j;
        ++l;
    }

    std::sort(ans.begin(), ans.end());
    for (std::vector<int>::const_iterator it = ans.cbegin(); it != ans.cend(); ++it) {
        std::cout << *it << " ";
    }

}

//Approach using priority queue. Time complexity is log(n)
void k_nearest_ele(const int* arr, int const& n, int const& k, int const& ele) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> max_pq;

    //Push first k ele into priority queue. Assume it is k nearest neighbou
    for (int i = 0; i < k && i < n; ++i) {
        max_pq.push(arr[i]);
    }

    for (int i = k; i < n; ++i) {
        if (std::abs(arr[i] - ele) < std::abs(max_pq.top() - ele) ||
            (std::abs(arr[i] - ele) == std::abs(max_pq.top() - ele) && arr[i] < max_pq.top())) {
            max_pq.pop();
            max_pq.push(arr[i]);
        }
    }

    while (max_pq.size() > 0) {
        std::cout << max_pq.top() << " ";
        max_pq.pop();
    }
}

int main() {
    int n = 0, k = 0, ele = 0, * arr = NULL;
    //take array size input
    std::cin >> n;
    arr = new int[n];

    //Get array element input
    take_input<int>(arr, n);
    //How many nearest element we want 
    std::cin >> k;
    //Element to which we have to find nearest element
    std::cin >> ele;

    k_nearest_ele_binary(arr, n, k, ele);

    //Delete memory
    delete[] arr;
}