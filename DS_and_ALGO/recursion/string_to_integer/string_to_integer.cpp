#include <iostream>
#include<cstring>
#include<cmath>

int string_to_number(char const *input, unsigned int power_of_10){
    if(*input == '\0')
        return 0;
    
    return (int(*input) - 48) * power_of_10 + string_to_number(input+1,power_of_10/10);
}

int string_to_number(char const *input) {    
    unsigned int length = strlen(input),
                 power_of_10 = pow(10, length - 1);
    
    return string_to_number(input, power_of_10);
}

int main() {
    char input[50];
    std::cin >> input;
    std::cout << string_to_number(input) << '\n';
}