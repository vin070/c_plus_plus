#include<iostream>
int main()
{
    int number = 0, evenSum = 0, oddSum = 0;
     
    std::cin>>number;
    
    while (number != 0)
    {
        int lastDigit = number % 10;
        number = number / 10;
        lastDigit % 2 == 0?evenSum = evenSum + lastDigit
                          :oddSum = oddSum + lastDigit;
    }
    
    std::cout<<evenSum<<" "<<oddSum;
}