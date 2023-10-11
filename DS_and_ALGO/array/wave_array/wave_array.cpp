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

void print_arr(std::vector<int> const& arr) {
    for (auto val : arr) {
        std::cout << val << " ";
    }
    std::cout << '\n';
}

/**
 * https://practice.geeksforgeeks.org/problems/wave-array-1587115621/1
 * T(n) = O(n)
 * S(n) = O(1)
*/
void wave_array(std::vector<int>& vect) {
    for (int i = 0; i < vect.size() - 1; ++i) {
        //At even index, number should be greater than or equal to [index - 1] and [index + 1] number.
        if (i % 2 == 0 && vect[i] < vect[i + 1]) {
            std::swap(vect[i], vect[i + 1]);
        }
        //At odd index, number should be less than or equal to [index - 1] and [index + 1] number.
        else if (i % 2 != 0 && vect[i] > vect[i + 1]) {
            std::swap(vect[i], vect[i + 1]);
        }
    }
}

int main() {
    int n = 0;
    std::vector<int> vect;
    std::cin >> n;
    take_input(vect, n);
    wave_array(vect);
    print_arr(vect);
    return 0;
}