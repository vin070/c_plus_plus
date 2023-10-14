#include<iostream>
#include<vector>
#include<cmath>
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
 * https://leetcode.com/problems/car-fleet/
 * T(n) = O(nlogn)
 * S(n) = O(n)
*/
int car_fleet(int const& target, std::vector<int>& position, std::vector<int>& speed) {
    std::vector<std::pair<int, int>> vect;
    for (int i = 0; i < position.size(); ++i) {
        vect.push_back(std::pair<int, int>(position.at(i), speed.at(i)));
    }
    

    std::sort(vect.begin(), vect.end(), [](std::pair<int, int> a, std::pair<int, int> b) -> bool {
        if (a.first < b.first) return true;
        return false;
    });

    std::vector<float> time;
    for (int i = 0; i < vect.size(); ++i) {
        time.push_back(((target - vect.at(i).first) * 1.0) / vect.at(i).second);
    }

    int fleet_count = 1;
    int high_time_index = time.size() - 1;
    for (int i = time.size() - 2; i >= 0; --i) {
        if (time.at(i) <= time.at(high_time_index)) {
            time[i] = time.at(high_time_index);
        }
        else {
            ++fleet_count;
            high_time_index = i;
        }
    }
    return fleet_count;
}

int main() {
    unsigned int target = 0;
    int size = 0;
    std::cin >> target >> size;
    std::vector<int> pos, speed;
    take_input(pos, size);
    take_input(speed, size);
    std::cout << car_fleet(target, pos, speed) << '\n';
    return 0;
};