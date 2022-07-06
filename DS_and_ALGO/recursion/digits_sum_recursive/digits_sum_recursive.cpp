#include <iostream>

int sum_of_digits(int n) {
   if( n == 0)
       return 0;
    
    return n % 10 + sum_of_digits(n/10);
}

int main() {
   int n = 0;
   std::cin >> n;
   std::cout << sum_of_digits(n) << '\n';
}
