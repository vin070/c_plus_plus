#include <iostream>
#include<functional>
#include<vector>
#include<queue>

struct node {
    int val;
    int i;
    int j;

    node(int val, int i, int j) {
        this->val = val;
        this->i = i;
        this->j = j;
    }
};

struct comparator {
    bool operator() (node a, node b) {
        return a.val > b.val;
    }
};


template<typename T>
void print(std::vector<T>& vect) {
    for (auto it = vect.cbegin(); it != vect.cend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << '\n';
}

void take_input(std::vector<std::vector<int>>& vect, int const& row) {
    for (int i = 0; i < row; ++i) {
        std::vector<int> row;
        int col = 0;
        std::cin >> col;
        for (int j = 0; j < col; ++j) {
            int ele = 0;
            std::cin >> ele;
            row.push_back(ele);
        }
        vect.push_back(row);
    }
}

/**
 * https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/
 * T(n) = O(col* row * log(row))
 * S(n) = O(row)
*/
auto find_smallest_range(std::vector<std::vector<int>>& vect) {
    int max_range = -100001;
    std::priority_queue<node, std::vector<node>, comparator> pq;
    for (int i = 0; i < vect.size(); ++i) {
        pq.push(node(vect[i][0], i, 0));
        if (vect[i][0] > max_range) max_range = vect[i][0];
    }

    std::vector<int> ans = { pq.top().val, max_range };
    while (true) {
        if (!pq.empty() && pq.top().j + 1 == vect.at(pq.top().i).size()) break;

        node min_num = pq.top();
        pq.pop();
        pq.push(node(vect[min_num.i][min_num.j + 1], min_num.i, min_num.j + 1));
        if (vect[min_num.i][min_num.j + 1] > max_range) {
            max_range = vect[min_num.i][min_num.j + 1];
        }
        if (max_range - pq.top().val < ans[1] - ans[0] || (max_range - pq.top().val == ans[1] - ans[0] && pq.top().val < ans[0])) {
            ans[0] = pq.top().val;
            ans[1] = max_range;
        }
    }
    return ans;
}


int main() {
    int row = 0;
    std::vector<std::vector<int>> vect;
    std::cin >> row;
    take_input(vect, row);
    auto ans = find_smallest_range(vect);
    print<int>(ans);
}