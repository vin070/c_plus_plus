#include <cstring>
#include <iostream>

void find_largest(int **input, int const &rows, int const &cols) {
  std::string sum_direction = "row";
  int index = 0, sum = INT32_MIN;

  // Figure out sum in row first;
  for (int i = 0; i < rows; ++i) {
    int row_sum = 0;
    for (int j = 0; j < cols; ++j) {
      row_sum += input[i][j];
    }
    if (row_sum > sum) {
      index = i;
      sum = row_sum;
    }
  }

  // Figure out sum in column;
  for (int i = 0; i < cols; ++i) {
    int col_sum = 0;
    for (int j = 0; j < rows; ++j) {
      col_sum += input[j][i];
    }
    if (col_sum > sum) {
      index = i;
      sum = col_sum;
      sum_direction = "column";
    }
  }
  std::cout << sum_direction << " " << index << " " << sum;
}

void delete_2d_arr(int **arr, int const row) {
  
  for (int i = 0; i < row; ++i)
    delete[] arr[i];

  delete[] arr;
}

int main() {

  int t = 0;
  std::cin >> t;
  while (t--) {
    int row, col;
    std::cin >> row >> col;

    int **input = new int *[row];
    for (int i = 0; i < row; i++) {

      input[i] = new int[col];
      for (int j = 0; j < col; j++)
        std::cin >> input[i][j];
    }

    find_largest(input, row, col);
    delete_2d_arr(input, row);
    std::cout << '\n';
  }
}