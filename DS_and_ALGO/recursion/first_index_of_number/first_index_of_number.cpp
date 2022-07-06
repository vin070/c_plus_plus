#include<iostream>

int first_index(int const * const input, int const &size, int const &x) {
    if( size == 0)
        return -1;
    
    int index_value = first_index(input, size - 1, x);
    
    if(index_value != -1)
        return index_value;
    else if(input[size  -1] == x)
        return size -1;
    else
        return -1;
}


int main(){
    int n = 0,
        x = 0;
    std::cin >> n;
  
    int *input = new int[n]; 
    for(int i = 0; i < n; i++)
        std::cin >> input[i];
    
    std::cin >> x;
    std::cout << first_index(input, n, x) << '\n';
    delete [] input;

}


