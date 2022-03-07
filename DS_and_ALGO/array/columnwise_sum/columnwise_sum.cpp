#include<iostream>

void take_input(int arr[][1000], int const &num_of_rows, int const &num_of_cols){
    for(int i = 0; i < num_of_rows; ++i){

        for(int j = 0; j < num_of_cols; ++j)
            std::cin>>arr[i][j];
    }
}

void print_columnwise_sum(int arr[][1000], int const &num_of_rows, int const &num_of_cols){
    for(int i = 0; i < num_of_cols; ++i) {
        
        int col_sum = 0;
        for(int j = 0; j < num_of_rows; ++j)
            col_sum += arr[j][i];
        
        std::cout<<col_sum<<' ';    
    }
}

int main(){
    int num_of_rows = 0,
        num_of_column = 0,
        arr[1000][1000] = {};

    std::cin>>num_of_rows>>num_of_column;
    take_input(arr,num_of_rows,num_of_column);
    print_columnwise_sum(arr,num_of_rows,num_of_column);
        
}
