#include <iostream>

void merge_two_sorted_array(int *const input, int const &start_index, int const &end_index, int const &mid_index) {
    
    int i = start_index,
        j = mid_index + 1,
        k = 0;
    int *temp_array = new int[end_index - start_index + 1];
    //Find the smallest from two half and store it in temporary array
    while ( i <= mid_index && j <= end_index) {
        if(input[i] <= input[j]) {
            temp_array[k] = input[i];
            ++i;
        }
        else {
            temp_array[k] = input[j];
            ++j;
        }
        ++k;
    }
    
    //Copy the remaining from first half into temproray array
    while(i <= mid_index) {
        temp_array[k] = input[i];
        ++k;
        ++i;
    }

    //Copy the remaining from second half into temproray array
    while(j <= end_index){
        temp_array[k] = input[j];
        ++k;
        ++j;
    }
    
    //Copy from temporary array into original array
    for(int i = 0; i < (end_index - start_index + 1); ++i)
        input[start_index + i] = temp_array[i];

    delete [] temp_array; 
}
void merge_sort(int * const input, int const start_index, int const end_index){
    if(start_index >= end_index)
        return;
    
    int mid = (start_index + end_index)/2;
    merge_sort(input, start_index, mid);
    merge_sort(input, mid + 1, end_index);
    merge_two_sorted_array(input, start_index, end_index, mid);  
}

void merge_sort(int * const input, int length) {
    merge_sort(input, 0, length - 1); 
}

int main() {

  int length = 0;
  std::cin >> length;
  int* input = new int[length];
  
  for(int i= 0; i < length; ++i)
    std::cin >> input[i];
    
  merge_sort(input, length);
  for(int i = 0; i < length; i++)
    std::cout << input[i] << " ";

  delete [] input;  
}