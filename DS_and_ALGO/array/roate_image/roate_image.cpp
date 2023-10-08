#include<iostream>
#include<vector>
#include<cmath>

void take_input(std::vector<std::vector<int>>& matrix, int const& row, int const& col) {
    for (int i = 0; i < row; ++i) {
        std::vector<int> col_vect;
        for (int j = 0; j < col; ++j) {
            int ele = 0;
            std::cin >> ele;
            col_vect.push_back(ele);
        }
        matrix.push_back(col_vect);
    }
}

void print_2D_array(std::vector<std::vector<int>>& matrix) {
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            std::cout << matrix.at(i).at(j) << " ";
        }
        std::cout << '\n';
    }
}

/**
 * https://leetcode.com/problems/rotate-image/
 * T(n) = O(n)
 * S(n) = O(1)
*/
void rotate_by_90_deg(std::vector<std::vector<int>>& matrix) {
    int const iteration_upper_limit = std::floor(matrix.size() / 2);
    for (int i = 0; i < iteration_upper_limit; ++i) {
        for (int j = i; j < matrix.size() - 1 - i; ++j) {
            int prev_cell_val = matrix[i][j];
            for (int next_i = j, next_j = matrix.size() - i - 1; next_i != i || next_j != j; ) {
                //Update next cell value
                int next_cell_val = matrix[next_i][next_j];
                matrix[next_i][next_j] = prev_cell_val;
                prev_cell_val = next_cell_val;

                //Move to next index
                int temp = next_i;
                next_i = next_j;
                next_j = matrix.size() - temp - 1;
            }
            matrix[i][j] = prev_cell_val;
        }
    }
}

int main() {
    int n = 0;
    std::vector<std::vector<int>> matrix;
    std::cin >> n;
    take_input(matrix, n, n);
    rotate_by_90_deg(matrix);
    print_2D_array(matrix);
    return 0;
}