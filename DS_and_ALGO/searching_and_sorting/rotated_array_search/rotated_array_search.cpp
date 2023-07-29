#include<iostream>
#include<vector>

void take_input(std::vector<int>& vect, int n) {
    for (int i = 0; i < n; ++i) {
        int input = 0;
        std::cin >> input;
        vect.push_back(input);
    }
}

int find_index_in_sorted_arr(std::vector<int> const& vect, int const& ele) {
    for (int start_index = 0, last_index = vect.size() - 1; start_index <= last_index; ) {
        int mid = (start_index + last_index) / 2;
        if (vect.at(mid) == ele) {
            return mid;
        }
        //First half is sorted
        else if (vect.at(start_index) < vect.at(mid)) {
            if (ele >= vect.at(start_index) && ele < vect.at(mid)) {
                last_index = mid - 1;
            }
            else {
                start_index = mid + 1;
            }
        }//Second half is sorted
        else if (vect.at(mid + 1) <= vect.at(last_index)) {
            if (ele >= vect.at(mid + 1) && ele <= vect.at(last_index)) {
                start_index = mid + 1;
            }
            else {
                last_index = mid - 1;
            }
        }
    }

    return -1;

}

int main() {
    std::vector<int> vect;
    int n = 0, ele = 0;
    std::cin >> n;
    vect.reserve(n);
    take_input(vect, n);
    std::cin >> ele;
    std::cout << find_index_in_sorted_arr(vect, ele) << '\n';
}