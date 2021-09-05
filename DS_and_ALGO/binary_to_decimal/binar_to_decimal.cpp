#include<iostream>
int main() {
    
    int binary_n = 0, decimal_n = 0;
    
    std::cin>>binary_n;

    for(int two_multiplier = 1; 
        binary_n != 0;
        two_multiplier *= 2, binary_n /= 10){
        int last_digit = binary_n % 10;
        decimal_n += last_digit * two_multiplier;
    }
    
    std::cout<<decimal_n;
}