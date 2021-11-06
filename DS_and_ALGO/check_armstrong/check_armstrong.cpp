#include<iostream>

int number_of_digits(int number){

    int digits = 0;
    do{
        number /= 10;
        ++digits; 
    }while (number != 0);
    return digits;
}

int power_of_number(int number, int power){
    
    int total_power = 1;
    for(int i = 1; i <= power; ++i)
        total_power *= number;
    
    return total_power;
}

int sum_of_digits(int number){
    int total_digits = number_of_digits(number),
        sum = 0;
    while(number != 0){
        int digit = number % 10;
        sum += power_of_number(digit, total_digits);
        number /= 10;
    }
    return sum;
}

int main(){
    int number = 0;
    std::cin>>number;
    if(number == sum_of_digits(number))
        std::cout<<"true";
    else
        std::cout<<"false";
    
}