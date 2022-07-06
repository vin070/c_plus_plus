#include <iostream>

int count_zeros(int n){
   if( n >= 1 && n <= 9)
      return 0;
   else if( n == 0)
       return 1;
       
   return n % 10 == 0? (1 + count_zeros(n/10)):count_zeros(n/10);   
}

int main() {
    int n = 0;
    std::cin >> n;
    std::cout << count_zeros(n) << '\n';
}