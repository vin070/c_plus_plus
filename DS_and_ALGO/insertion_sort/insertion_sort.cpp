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

void insertion_sort(int *input, int size){
    for(int i = 1; i < size; ++i){
        for(int j = i ; j > 0; --j){
            if(input[j] < input[j - 1])
                swap_values(input, j, j - 1);
            else 
                break;
        }
    }
}

int main(){
    int array_size = 0,
        array[1000000] = {0},
        number_of_test_cases = 0;

    std::cin>>number_of_test_cases;
    for( int i = 0; i < number_of_test_cases; ++i){
        std::cin>>array_size;
        array[1000000] = {0};
        take_input(array, array_size);
        insertion_sort(array, array_size);
        print_array(array, array_size);
    }

}