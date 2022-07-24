#include <iostream>

int subset(int input[], int n, int output[][20]) {
  if (n <= 0) {
    output[0][0] = 0;
    return 1;
  }

  int output_length = subset(input + 1, n - 1, output);

  for (int i = 0; i < output_length; ++i) {

    int row_index = output_length + i;
    for (int j = 0; j <= output[i][0]; ++j) {
      if (j == 0)
        output[row_index][j] = output[i][j];
      else
        output[row_index][j + 1] = output[i][j];
    }
    
    ++output[row_index][0];
    output[row_index][1] = input[0];
  }

  return 2 * output_length;
}

int main() {
  int input[20], length, output[35000][20];
  cin >> length;
  for (int i = 0; i < length; i++) cin >> input[i];

  int size = subset(input, length, output);

  for (int i = 0; i < size; i++) {
    for (int j = 1; j <= output[i][0]; j++) cout << output[i][j] << " ";
    cout << endl;
  }
}