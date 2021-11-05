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

/**
 * Sorts the array containing 0's and 1's in inreasing order
 * @param { int * } array - Array in which sorting to be done
 * @param { int } size - Size of array
 * @returns { void }
 */
void sortZeroesAndOne(int *array, int size)
{
    for(int index_from_left = 0, index_from_right = size -1;
       index_from_left <= index_from_right;){
       if(array[index_from_left] == 1 && array[index_from_right] == 0)
           swap_values(array,index_from_left,index_from_right);
       
       if(array[index_from_left] == 0)
           ++index_from_left;
       if(array[index_from_right] == 1)
           --index_from_right;
    }
}

void print_array(int const array[], int const size){
    
    for(int i = 0; i < size; ++i)
        std::cout<<array[i]<<" ";

    std::cout<<'\n';
}

void take_input_array(int *array, int size){
    for(int i = 0; i < size; ++i)
        std::cin>>array[i];
}

int main(){
    int number_of_array = 0;
    std::cin>>number_of_array;
    for(int i = 0; i < number_of_array; ++i){
        int array_length = 0;
        std::cin>>array_length;
        int array[array_length] = {0};
        take_input_array(array, array_length);  
        sortZeroesAndOne(array, array_length);
        print_array(array,array_length);        
    }
}
