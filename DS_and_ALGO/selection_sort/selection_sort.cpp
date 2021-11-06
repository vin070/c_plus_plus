#include<iostream>

void take_input(int *array, int size){
    for(int i = 0; i < size; ++i)
        std::cin>>array[i];   
}

void print_array(int const array[], int const size){
    
    for(int i = 0; i < size; ++i)
        std::cout<<array[i]<<" ";
    
    std::cout<<"\n";
}

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

void selection_sort(int *input, int size){
    for(int i = 0; i < size; ++i){
        int minimum_value_index = i;
        for(int j = i+1; j < size; ++j){
            if(input[j] < input[minimum_value_index])
                minimum_value_index = j;
        }
        swap_values(input, i, minimum_value_index);
    }
}

int main(){
    int array_size = 0,
        array[1000000] = {0};

    std::cin>>array_size;
    take_input(array, array_size);
    selection_sort(array, array_size);
    print_array(array, array_size);

}