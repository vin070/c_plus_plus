#include <iostream>
#include <math.h>
#include <iomanip>

unsigned long power(int x, int n) {
    if(n == 0)
        return 1;
    
    return x * power(x, n-1); 
}

double geometric_sum(int k) { 
    return 2 - (1.0/power(2,k));
}

int main() {
    int k;
    std::cin >> k;
    std::cout << std::fixed << std::setprecision(5);
    std::cout << geometric_sum(k) << '\n';   
}