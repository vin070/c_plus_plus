#include <iostream>

void spiral_print(int **input, int const &rows, int const &cols){
     int row_start = 0,
         row_end = rows - 1,
         col_start = 0,
         col_end = cols -1;
     
     while(row_start <= row_end) {
         //Print the right arrow
        for(int i = col_start; i <= col_end; ++i)
            std::cout<<input[row_start][i]<<" ";
        
        //Print the down arrow
        for(int i = row_start + 1; i <= row_end; ++i)
            std::cout<<input[i][col_end]<<" ";
        
        //Print the left arrow
        for(int i = col_end - 1; i >= col_start; --i)
            std::cout<<input[row_end][i]<<" ";
        
        //Print the up arrow
        for(int i = row_end - 1; i > row_start; --i)
            std::cout<<input[i][col_start]<<" ";

        row_start += 1;
        row_end -= 1;
        col_start += 1;
        col_end -= 1;
     }

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
		spiral_print(input, row, col);
        //TODO: Release the input array memory
		std::cout <<'\n';
	}
}