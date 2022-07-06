#include<iostream>

/** Swap values in given array at given indexes
 * @param { int * } array - Input array in which values to be swapped
 * @param { int } i -  Index at which value to be changes
 * @param { int } j - Index at which value to be changes
 * @returns { void }
*/
void swap_values(int *array, int i, int j){
     int temp = array[i];
     array[i] = array[j];
     array[j] = temp;
}

int partition_array(int *const input, int const &start_index, int const &end_index){
    int partition_index = start_index;
    for(int i = start_index; i <= end_index; ++i) { 
        if(input[i] < input[start_index])
            ++partition_index;
    }
    swap_values(input, start_index, partition_index);
    
    for(int i = start_index, j = partition_index + 1; i < partition_index && j <= end_index;) {
        if(input[i] < input[partition_index])
            ++i;
        else if(input[j] >= input[partition_index])
            ++j;
        else if( input[i] >= input[partition_index] && input[j] < input[partition_index]){
            swap_values(input,i,j);
            ++i;
            ++j;
        }
    }
    return partition_index;
}

void quick_sort(int * const input, int const start_index, int end_index) {
    if(start_index >= end_index)
       return;
    
    int partition_index = partition_array(input, start_index, end_index);
    quick_sort(input, start_index, partition_index - 1);
    quick_sort(input, partition_index + 1, end_index);
}
void quick_sort(int * const input, int const length){
     quick_sort(input, 0, length - 1);
}

int main(){
    int n = 0;
    std::cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; ++i) 
        std::cin >> input[i];
    
    quick_sort(input, n);
    for(int i = 0; i < n; ++i) 
        std::cout << input[i] << " ";
    
    delete [] input;
}