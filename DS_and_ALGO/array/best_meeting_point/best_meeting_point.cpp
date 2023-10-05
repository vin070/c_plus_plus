#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

void take_input(std::vector<std::vector<int>>& vect, int const& row, int const& col) {
    for (int i = 0; i < row; ++i) {
        std::vector<int> row;
        for (int j = 0; j < col; ++j) {
            int ele = 0;
            std::cin >> ele;
            row.push_back(ele);
        }
        vect.push_back(row);
    }
}

/**
 * https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/arrays-and-strings/best-meeting-point/ojquestion
 * T(n) = O(row * col)
 * S(n) = (m * n)
*/
auto best_meeting_point(std::vector<std::vector<int>>& vect, int const& col) {
    std::vector<int> row_index;
    std::vector<int> col_index;

    //Iterate row wise;
    for (int i = 0; i < vect.size(); ++i) {
        for (int j = 0; j < vect.at(i).size(); ++j) {
            if (vect.at(i).at(j) == 1) {
                row_index.push_back(i);
            }
        }
    }

    //Iterate column wise
    for (int i = 0; i < col; ++i) {
        for (int j = 0; j < vect.size(); ++j) {
            if (vect.at(j).at(i) == 1) {
                col_index.push_back(i);
            }
        }
    }
    int x_coord = row_index.at(row_index.size() / 2);
    int y_coord = col_index.at(col_index.size() / 2);
    int sum = 0;
    std::for_each(row_index.begin(), row_index.end(), [&sum, &x_coord](int a) -> void {
        sum += std::abs(x_coord - a);
        });

    std::for_each(col_index.begin(), col_index.end(), [&sum, &y_coord](int a) -> void {
        sum += std::abs(y_coord - a);
        });
    return sum;
}

int main() {
    int row = 0, col = 0;
    std::vector<std::vector<int>> vect;
    std::cin >> row;
    std::cin >> col;
    take_input(vect, row, col);
    std::cout << best_meeting_point(vect, col) << '\n';
    return 0;
}