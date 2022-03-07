#include<iostream>
 int main(){
     
     int n=0;
     std::cin>>n;
     
     for(int i=1;i<=n;i++)
     {
         //n-i space in a row
         for(int j=1;j<=n-i;j++)
             std::cout<<" ";
         
         //i numbers in a row
         for(int j=i;j<2*i;j++)
             std::cout<<j;
         
         std::cout<<std::endl;
     }
 }