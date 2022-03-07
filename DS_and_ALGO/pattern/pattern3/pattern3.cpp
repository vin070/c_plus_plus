#include<iostream>
int main()
{
    int n = 0;
    
    std::cin>>n;
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= i; j++)
            std::cout<<1;
        
        std::cout<<std::endl;
    }
}
