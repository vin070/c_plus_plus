#include<iostream>
int main()
{
    int n=0;
    std::cin>>n;
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
          std::cout<<char('A'+i);

        std::cout<<std::endl;
    }
}