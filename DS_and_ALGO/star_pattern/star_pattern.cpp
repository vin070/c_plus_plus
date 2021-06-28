#include<iostream>
int main()
{
    
    int n=0;
    std::cin>>n;
    
    for(int i=1;i<=n;i++)
    {
       //n-i space
        for(int j=1;j<=n-i;j++)
            std::cout<<" ";
        
        //2*i-1 asterik
        for(int j=1;j<=2*i-1;j++)
            std::cout<<'*';
        
        /*
         Again n-i space
         Not needed. Will lead to extra time complexity
         
         for(int j=1;j<=n-i;j++)
            std::cout<<" ";
        */
        
        std::cout<<std::endl;
    }
}