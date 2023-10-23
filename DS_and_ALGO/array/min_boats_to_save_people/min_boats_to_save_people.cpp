#include <iostream>
#include<vector>
#include<algorithm>

void take_input(std::vector<int>& arr, int const& n) {
    arr.reserve(n);
    for (int i = 0; i < n; ++i) {
        int ele = 0;
        std::cin >> ele;
        arr.push_back(ele);
    }
}
/**
 * https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/arrays-and-strings/2-sum-target-sum-unique-pairs/ojquestion
 * T(n) = O(nlogn)
 * S(n) = O(1)
*/
auto min_boats_to_save_people(std::vector<int>& peoples_weight, int const& boat_capacity) {
    int ans = 0;
    std::sort(peoples_weight.begin(), peoples_weight.end());
    for (int i = 0, j = peoples_weight.size() - 1; i <= j;) {
        if (peoples_weight.at(i) + peoples_weight.at(j) <= boat_capacity) {
            ++i;
            --j;
            ++ans;
        }
        else if (peoples_weight.at(i) + peoples_weight.at(j) > boat_capacity) {
            ++ans;
            --j;
        }
    }
    return ans;
}
int main() {
    int peoples = 0, boat_capacity = 0;
    std::vector<int> peoples_weight;
    std::cin >> peoples;
    take_input(peoples_weight, peoples);
    std::cin >> boat_capacity;
    std::cout << min_boats_to_save_people(peoples_weight, boat_capacity) << '\n';
}