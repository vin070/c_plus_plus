#include<iostream>
#include<vector>
#include<algorithm>

//https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/searching-and-sorting/maximize_sum_of_arr[i]*i_of_an_array/ojquestion
void take_input(std::vector<int>& arr, int const& n) {
    for (int i = 0; i < n; ++i) {
        int input = 0;
        std::cin >> input;
        arr.push_back(input);
    }
}

/**
 * Time complexity = O(nlogn)
*/
template<typename T>
T arr_max_sum(std::vector<T>& vect) {
    std::sort(vect.begin(), vect.end());
    T max = 0;
    for(int i = 0; i < vect.size(); ++i) {
        max += vect.at(i) * i;
    }
    return max;
}

int main() {
    std::vector<int> v;
    int n = 0;
    std::cin >> n;
    take_input(v, n);
    std::cout<<arr_max_sum<int>(v)<<'\n';
}