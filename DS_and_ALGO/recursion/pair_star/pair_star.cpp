#include <iostream>
#include<cstring>

void shift_right(char *input, int n) {
    
    int length = strlen(input);
    for(int i = length; i >= 0; --i)
        input[i + n] = input[i];
}

void pair_star(char *input) {
    if(input[0] == '\0')
        return;
    
    else if(input[0] == input[1]) {
        shift_right(input + 1, 1);
        input[1] = '*';
        pair_star(input + 2);
    }
    else
        pair_star(input + 1);
}

int main() {
   char input[100];
   std::cin.getline(input, 100);
   pair_star(input);
   std::cout << input << '\n';
}