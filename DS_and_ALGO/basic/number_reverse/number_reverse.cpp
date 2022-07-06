#include<iostream>

int main(){
   int original_n = 0;
   int reverse_n = 0;

   std::cin>>original_n;

   while(original_n != 0){
       int last_digit = original_n % 10;
       reverse_n = reverse_n * 10 + last_digit;
       original_n /= 10;    
   }

   std::cout<<reverse_n;    
}