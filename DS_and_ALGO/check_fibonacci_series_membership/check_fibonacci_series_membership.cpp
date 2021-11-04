#include<iostream>

/** Check if given number is member of fibonacci series
 * @param { int } number_to_check -  Given number to check against fibonacci series  
 * @returns { bool } 
*/
bool is_fibonacci_series_member(int number_to_check){
     int previous_n = 1,
         second_last_n = 0;
     
     while(previous_n + second_last_n < number_to_check){
         int current_n = previous_n + second_last_n;
         second_last_n = previous_n;
         previous_n = current_n;
     }

     if(number_to_check == previous_n + second_last_n ||
        number_to_check == 0 )
           return true;
    else 
        return false;

}

int main(){

    int number_to_check = 0;
        
    std::cin>>number_to_check;
    std::cout<<is_fibonacci_series_member(number_to_check)<<'\n';
}


