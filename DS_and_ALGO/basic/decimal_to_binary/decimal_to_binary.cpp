#include<iostream>
int main() {
    
    int decimial_n = 0;
    long binary_n = 0, mul = 1;
    
    std::cin>>decimial_n;

    for(;decimial_n != 0; decimial_n /= 2, mul *= 10){
        int remainder = decimial_n %2;
        binary_n = binary_n + mul*remainder; 
    }

    std::cout<<binary_n;
}