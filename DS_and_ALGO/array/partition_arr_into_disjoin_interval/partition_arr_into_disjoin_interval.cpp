#include<iostream>
#include<vector>

int partition_disjoint(std::vector<int>& nums) {
    unsigned int chunks = 1;
    for (int i = 1, gt = nums.at(0), last_chunks_gt = nums.at(0); i < nums.size(); ++i) {
        if (nums.at(i) > gt) {
            gt = nums.at(i);
        }
        if (nums.at(i) < last_chunks_gt) {
            chunks = i + 1;
            last_chunks_gt = gt;
        }
    }
    return chunks;
}

void take_input(std::vector<int>& vect, int const& n) {
    vect.reserve(n);
    for (int i = 0; i < n; ++i) {
        int ele = 0;
        std::cin >> ele;
        vect.push_back(ele);
    }
}

int main() {
    int n = 0;
    std::vector<int> vect;
    std::cin >> n;
    take_input(vect, n);
    std::cout << partition_disjoint(vect) << '\n';
    return 0;
}