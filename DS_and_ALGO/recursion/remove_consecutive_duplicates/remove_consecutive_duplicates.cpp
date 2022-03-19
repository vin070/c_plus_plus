#include <iostream>

void shift_left(char * const input, int const &shift_factor){

   int i = shift_factor;
   for(;input[i] != '\0'; ++i)
     input[i - shift_factor] = input[i];
    
   input[i - shift_factor] = '\0';
}

void remove_consecutive_duplicates(char * const input) {
    if(input[0] == '\0')
        return;

    else if(input[0] == input[1]){
        shift_left(input,1);
        remove_consecutive_duplicates(input);
    }
    else remove_consecutive_duplicates(input + 1);
}

int main() {
    char s[100000];
    std::cin >> s;
    remove_consecutive_duplicates(s);
    std::cout << s << '\n';
}