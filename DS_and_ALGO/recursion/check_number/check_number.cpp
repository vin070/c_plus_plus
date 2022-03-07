#include<iostream>

bool check_number(int const * const input, int const &size, int const &x) {
    if(size == 0)
        return false;
    
    return input[size - 1] == x?
           true:
           check_number(input, size - 1, x);
}

int main(){
    int n = 0,
        x = 0;
    std::cin >> n;
  
    int *input = new int[n];
    for(int i = 0; i < n; i++)
        std::cin >> input[i];
    
    std::cin >> x;
    if(check_number(input, n, x)) 
        std::cout << "true" << '\n';
    else 
        std::cout << "false" << '\n';
    
}
