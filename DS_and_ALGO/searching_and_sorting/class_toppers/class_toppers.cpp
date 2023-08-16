#include<iostream>
#include<vector>
#include<map>

void take_input(std::vector<int>& vect, int const& size) {
    vect.reserve(size);
    for (int i = 0; i < size; ++i) {
        int ele = 0;
        std::cin >> ele;
        vect.push_back(ele);
    }
}

struct less {
    bool operator()(std::pair<int, int> const& a, std::pair<int, int> const& b) {
        if (a.second == b.second)
            return a.first < b.first;
        return a.second > b.second;
    }
};

void class_toppers(std::vector<int>& vect, int const& k) {
    std::map<std::pair<int, int>, int, less> ans;

    for (int i = 0; i < vect.size(); ++i) {
        if (ans.size() < k) {
            ans.insert(std::pair<std::pair<int, int>, int>(std::pair<int, int>(i, vect.at(i)), i));
        }
        else if (k > 0 && vect.at(i) > ((--ans.end())->first.second)) {
            ans.erase(--ans.end());
            ans.insert(std::pair<std::pair<int, int>, int>(std::pair<int, int>(i, vect.at(i)), i));
        }
    }

    for (auto it = ans.cbegin(); it != ans.cend(); ++it) {
        std::cout << it->second << " ";
    }
}

int main() {
    int size = 0, k = 0;
    std::vector<int> vect;
    std::cin >> size;
    take_input(vect, size);
    std::cin >> k;
    class_toppers(vect, k);
}