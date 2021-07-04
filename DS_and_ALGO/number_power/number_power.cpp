#include<iostream>
int main()
{
     int x = 0, n =0, result = 1;
      
     std::cin>>x>>n;
    
     for(int i = 1; i <= n ; i++)
         result*=x;
         
     std::cout<<result;
}