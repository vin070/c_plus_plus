#include<iostream>

int main(){
    //METHOD 1
    // int x_series = 0;
    
    // std::cin>>x_series;
   
    // for(int i = 1; i <= x_series; i++){
    //     int value = 3*i + 2;
    //     if(value % 4 == 0)
    //        ++x_series;
    //     else if(value % 4 != 0)
    //        std::cout<<value<<" ";
    // }
   
   //METHOD 2
   int x_series = 0;

   std::cin>>x_series;
   
   for(int i = 1, j = 0; j < x_series; i++){
       int value = 3*i + 2;
       if(value % 4 != 0 && j+1 == x_series){
          std::cout<<value;
          ++j; 
       }
       else if(value %4 != 0 && j+1 != x_series){
          std::cout<<value<<" ";
          ++j;
       }
    }

}