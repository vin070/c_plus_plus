#include<iostream>
#include<vector>

void take_input(std::vector<std::vector<int>>& vect, int const& rows, int const& cols) {
    for (int i = 0; i < rows; ++i) {
        std::vector<int> new_vect;
        new_vect.reserve(cols);
        for (int j = 0; j < cols; ++j) {
            int ele = 0;
            std::cin >> ele;
            new_vect.push_back(ele);
        }
        vect.push_back(new_vect);
    }
}

/**
 * https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/searching-and-sorting/count-zeros-in-a-sorted-matrix-official/ojquestion
 * Time complexity = O(n)
*/
int count_zeroes(std::vector<std::vector<int>> const& vect, int const& rows, int const& cols) {
    int count = 0;
    for (int i = 0, j = cols - 1; i < rows && j >= 0;) {
        if (vect.at(i).at(j) == 0) {
            count += j + 1;
            ++i;
        }
        else {
            --j;
        }
    }
    return count;
}

int main() {
    std::vector<std::vector<int>> vect;
    int rows = 0, cols = 0;
    std::cin >> rows;
    std::cin >> cols;
    vect.reserve(rows);
    take_input(vect, rows, cols);
    std::cout << count_zeroes(vect, rows, cols) << '\n';
}