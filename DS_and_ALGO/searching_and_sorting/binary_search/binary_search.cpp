#include<iostream>

int binary_search(int *input, int size, int search_val){
    for(int i = 0, j = size - 1; i <= j;){
        int mid_index = (i + j)/2;
        if(input[mid_index] == search_val)
            return mid_index;
        else if(input[mid_index] > search_val)
            j = mid_index - 1;
        else if(input[mid_index] < search_val)
            i = mid_index + 1;
    }
    return -1;
}

void take_input(int *array, int size){
    for(int i = 0; i < size; ++i)
        std::cin>>array[i];   
}

int main(){
    int array_size = 0,
        array[1000000] = {0},
        number_of_test_cases = 0;
    
    std::cin>>array_size;
    take_input(array, array_size);
    std::cin>>number_of_test_cases;

    for(int i = 0; i < number_of_test_cases; ++i){
        int search_element = 0;
        std::cin>>search_element;
        std::cout<<binary_search(array, array_size, search_element)<<'\n';
    }

}