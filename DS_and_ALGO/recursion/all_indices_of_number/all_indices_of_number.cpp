#include<iostream>

int all_indexes(int const * const input, int size, int const x, int * const output) {
    if(size == 0)
        return 0;
    
    int output_size = all_indexes(input, size - 1, x, output);
    
    if(input[size - 1] == x) {
        output[output_size] = size - 1;
        return ++output_size;
    }
    else
       return output_size;
}


int main(){
    int n = 0,
        x = 0;
    std::cin >> n;
  
    int *input = new int[n];
    int *output = new int[n];

    for(int i = 0; i < n; i++)
        std::cin >> input[i];
    
    std::cin >> x;
    
    int size = all_indexes(input, n, x, output);
    for(int i = 0; i < size; i++)
        std::cout << output[i] << " ";
    
    delete [] input;
    delete [] output;
    

}


