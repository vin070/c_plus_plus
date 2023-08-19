#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>


auto matrix_cell_distance(int const& rows, int const& cols, int const& row_center, int const& col_center) {
    std::vector<std::vector<int>> ans;
    ans.resize(rows * cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::vector<int> vect = { i,j };
            ans[i * cols + j] = vect;
        }
    }

    std::sort(ans.begin(), ans.end(), [&row_center, &col_center](std::vector<int>a, std::vector<int> b) -> bool {
        unsigned int distance_1 = std::abs(row_center - a.at(0)) + std::abs(col_center - a.at(1));
        unsigned int distance_2 = std::abs(row_center - b.at(0)) + std::abs(col_center - b.at(1));

        if (distance_1 != distance_2) {
            return distance_1 < distance_2;
        }
        return a.at(0) < b.at(0);
        });
    return ans;
}

int main() {
    int rows = 0, cols = 0, row_center = 0, col_center = 0;
    std::cin >> rows >> cols >> row_center >> col_center;
    auto ans = matrix_cell_distance(rows, cols, row_center, col_center);
    for (auto val : ans) {
        std::cout << '(' << val.at(0) << ',' << val.at(1) << "),";
    }
}