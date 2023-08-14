#include<iostream>
#include<vector>

void take_input(std::vector<unsigned long>& vect, unsigned long const& size) {
    vect.reserve(size);
    for (int i = 0; i < size; ++i) {
        int ele = 0;
        std::cin >> ele;
        vect.push_back(ele);
    }
}

/**
 * https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/searching-and-sorting/leaders-in-an-array-official/ojquestion
 * T(n) = O(n)
 * S(n) = O(n)
*/
auto leaders_in_arr(std::vector<unsigned long>& vect) {
    std::vector<unsigned long> ans;
    for (int i = vect.size() - 1; i >= 0; --i) {
        if (!ans.size() || vect.at(i) >= ans.at(ans.size() - 1)) {
            ans.push_back(vect.at(i));
        }
    }
    for (int i = 0, j = ans.size() - 1; i < j; ++i, --j) {
        std::swap(ans.at(i), ans.at(j));
    }
    return ans;
}

int main() {
    unsigned long size = 0;
    std::vector<unsigned long> vect;
    std::cin >> size;
    take_input(vect, size);
    for (auto leader : leaders_in_arr(vect)) {
        std::cout << leader << " ";
    }
}