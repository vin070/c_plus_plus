#include<iostream>
int main()
{
    int n = 0;
    std::cin>>n;
    
    for(int i = n; i >= 1; i--)
    {
        for(int j = 1; j <= i; j++)
            std::cout<<j;
        
        std::cout<<std::endl;
    }
}