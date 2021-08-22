#include<iostream>

/**
 * Calculate sum from 1 to N
 * @param{ int } n - upper bound number to which sum is to be calculated
 * @returns{ int } - computed sum value from 1 to n  
*/
int sum(int n){
    
    int sum = 0;
    for(int i = 1; i <= n; i++)
        sum += i;
    return sum;
}

/**
 * @param{ int } n - upper bound number to which product is to be calculated
 * @returns{ int } - computed product value from 1 to n
*/
int product(int n){
    
    int product = 1;
    for(int i = 1; i <= n; i++)
        product *= i;
    return product;
}

int main(){
    
    int number = 0, choice = 0;

    std::cin>>number>>choice;

    if(choice == 1)
        std::cout<<sum(number);
    else if(choice == 2)
        std::cout<<product(number);
    else
        std::cout<<-1;
}