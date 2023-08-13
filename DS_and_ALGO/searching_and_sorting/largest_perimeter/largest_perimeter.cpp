#include <iostream> 
#include<vector>
#include<algorithm>

void take_input(std::vector<int>& vect, int const& size) {
    vect.reserve(size);
    for (int i = 0; i < size; ++i) {
        int ele = 0;
        std::cin >> ele;
        vect.push_back(ele);
    }
}
/**
 * https://leetcode.com/problems/largest-perimeter-triangle/
 * T(n) = O(n)
 * S(n) = 1
*/
auto  largest_perimeter(std::vector<int>& vect) {
    std::sort(vect.begin(), vect.end());
    for (int i = vect.size() - 1; i >= 0 && i >= 2; --i) {
        if (vect.at(i - 2) + vect.at(i - 1) > vect.at(i)) {
            return (vect.at(i - 2) + vect.at(i - 1) + vect.at(i));
        }
    }
    return 0;
}

int main() {
    int size = 0;
    std::vector<int> vect;
    std::cin >> size;
    take_input(vect, size);
    std::cout << largest_perimeter(vect);
    return 0;
}