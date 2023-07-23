#include<iostream>
#include<vector>
#include<algorithm>

void take_input(std::vector<int>& arr, int const& n) {
    for (int i = 0; i < n; ++i) {
        int input = 0;
        std::cin >> input;
        arr.push_back(input);
    }
}

/**
 * Time complexity = O(nlogn)
 * Space complexity = O(1)
*/
template<typename T>
void find_pair_method_2(std::vector<T>& arr, int const& n, int const& ele) {
    //First sort the array
    std::sort(arr.begin(), arr.end());
    for (int i = 0, j = 1; i < n && j < n;) {
        int const diff = arr.at(j) - arr.at(i);
        if (diff < ele) {
            ++j;
        }
        else if (diff > ele) {
            ++i;
        }
        else {
            std::cout << arr.at(i) << " " << arr.at(j)<<'\n';
            ++j;        }

    }
}

/**
 * Time complexity = O(nlogn)
 * Space complexity = O(n)
*/

template<typename T>
void find_pair_method_1(std::vector<T>& vec, int const& n, int const& ele) {
    //First sort the array
    std::sort(vec.begin(), vec.end());

    //Create another vector which will store summation ele + vect[i];
    std::vector<T> sum;
    sum.reserve(n);
    for (int i = 0; i < n; ++i) {
        sum.push_back(vec.at(i) + ele);
    }

    for (int i = 0; i < n; ++i) {
        auto index_addr = std::find(vec.begin(), vec.end(), sum.at(i));
        if (index_addr != vec.end()) {
            std::cout << vec.at(i) << " " << *index_addr << '\n';
        }
    }

}
int main() {
    std::vector<int> v;
    int n = 0, ele = 0;
    std::cin >> n;
    take_input(v, n);
    std::cin >> ele;
    find_pair_method_2<int>(v, n, ele);
}