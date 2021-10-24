#include<iostream>
int main(){
    
    int number = 0,
        root_starting_number = 0;

    std::cin>>number;
    long temp = number;
    
    while ((temp*temp) > number) {
        temp /= 2;
        root_starting_number = temp;
    }
    
    while(((root_starting_number+1)*(root_starting_number+1)) <= number)
       root_starting_number += 1;
   
    std::cout<<root_starting_number;
    

}