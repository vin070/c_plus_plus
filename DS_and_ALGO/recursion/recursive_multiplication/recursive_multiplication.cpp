#include <iostream>

int multiply_numbers(int m, int n) {
    if(n==0)
       return 0;
    
    return m + multiply_numbers(m,n-1);
}

int main() {
    int m = 0, n = 0;
    std::cin >> m >> n;
    std::cout << multiply_numbers(m, n) << '\n';
}
