#include<iostream>
int main()
{
    int n = 0;
    
    std::cin>>n;
        
    for(int i = 0; i < n; i++ )
    {
        for(int j = 0; j <= i; j++)
        {
            if(i == 0)
                std::cout<<1;
            else if(j == i || j == 0)
                std::cout<<i;
            else
                std::cout<<0;
        }
        std::cout<<std::endl;
    }
}