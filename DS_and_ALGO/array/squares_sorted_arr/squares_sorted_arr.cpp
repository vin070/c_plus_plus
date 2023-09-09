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
 *T(n) = O(n)
  S(n) = O(n)
  https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/arrays-and-strings/majority-element-i/ojquestion
*/
auto find_sqr_sorted_arr(std::vector<int>& vect) {
    int first_positive_num_index = 0;
    std::vector<int> sqrt_arr;
    int i = 0;
    for (; i < vect.size(); ++i) {
        if (vect.at(i) >= 0) {
            first_positive_num_index = i;
            break;
        }
    }

    if (i == vect.size()) {
        first_positive_num_index = vect.size();
    }

    for (int i = first_positive_num_index, j = first_positive_num_index - 1; i < vect.size() || j >= 0;) {
        if (i < vect.size() && j >= 0 && std::abs(vect.at(i)) <= std::abs(vect.at(j))) {
            sqrt_arr.push_back(vect.at(i) * vect.at(i));
            ++i;
        }
        else if (i < vect.size() && j >= 0 && std::abs(vect.at(j)) < std::abs(vect.at(i))) {
            sqrt_arr.push_back(vect.at(j) * vect.at(j));
            --j;
        }
        else if (i < vect.size()) {
            sqrt_arr.push_back(vect.at(i) * vect.at(i));
            ++i;
        }
        else if (j >= 0) {
            sqrt_arr.push_back(vect.at(j) * vect.at(j));
            --j;
        }
    }
    return sqrt_arr;

}

int main() {
    int arr_size = 0;
    std::vector<int> arr;
    std::cin >> arr_size;
    take_input(arr, arr_size);
    auto ans = find_sqr_sorted_arr(arr);
    print_arr(ans);
    return 0;
}