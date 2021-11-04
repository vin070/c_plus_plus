#include<iostream>

void arrange_array(int array[], int size){
    
    for(int index_from_left = 0, index_from_right = size -1, value = 1;
        index_from_left <= index_from_right;
        ++index_from_left, --index_from_right, value += 2){
        array[index_from_left] = value;
        
        if( index_from_left != index_from_right)
            array[index_from_right] = value + 1;
    }
}

void print_array(int const array[], int const size){
    
    for(int i = 0; i < size; ++i)
        std::cout<<array[i]<<" ";
}

int main(){
    int number_of_array = 0;
    std::cin>>number_of_array;
    for(int i = 0; i < number_of_array; ++i){
        int array_length = 0;
        std::cin>>array_length;
        int array[array_length] = {0};
        arrange_array(array, array_length);
        print_array(array,array_length);
        std::cout<<'\n';
        
    }
}



