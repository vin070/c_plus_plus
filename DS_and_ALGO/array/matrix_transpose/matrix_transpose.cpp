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

/**
 * https://leetcode.com/problems/shortest-unsorted-continuous-subarray/description/
 * T(n) = O(m * n)
 * S(n) = O(m * n)
*/
auto transpose(std::vector<std::vector<int>>& matrix) {
    //Find row count
    int const row_size = matrix.size();
    //Find column count
    int const col_size = matrix.at(0).size();
    //Create a matrix of col * row size because matrix transpose will reverse the matrix size.
    std::vector<std::vector<int>> transpose_matrix;
    for (int i = 0; i < col_size; ++i) {
        std::vector<int> vect(row_size);
        transpose_matrix.push_back(vect);
    }

    // Transpose the matrix by swapping the [row_index, col_index] value.
    // If any [row_index, col_index] does not exist, the don't swap, just place it
    for (int i = 0; i < row_size; ++i) {
        for (int j = i < std::min(row_size, col_size) ? i : 0; j < col_size; ++j) {
            transpose_matrix[j][i] = matrix[i][j];
            if (j < row_size && i < col_size) {
                transpose_matrix[i][j] = matrix[j][i];
            }
        }
    }
    return transpose_matrix;
}

void print_2D_array(std::vector<std::vector<int>>& matrix) {
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            std::cout << matrix.at(i).at(j) << " ";
        }
        std::cout << '\n';
    }
}

int main() {
    int row = 0, col = 0;
    std::vector<std::vector<int>> matrix;
    std::cin >> row >> col;
    take_input(matrix, row, col);
    auto ans = transpose(matrix);
    print_2D_array(ans);
    return 0;
}