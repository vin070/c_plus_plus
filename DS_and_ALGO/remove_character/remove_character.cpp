#include <iostream>
#include <cstring>

void remove_occurence_of_char(char *input, char const & c) {

     int remove_char_occurence = 0;
     for(int i = 0; input[i] != '\0'; ++i) {
        if(input[i] == c)
            ++remove_char_occurence;
        else if(i - remove_char_occurence != i)
            input[i - remove_char_occurence] = input[i];      
     }

     input[std::strlen(input) - remove_char_occurence] = '\0';
}

int main() {
    int size = 1e6;
    char str[size];
    std::cin.getline(str, size);
    char c;
    std::cin >> c;
    remove_occurence_of_char(str, c);
    std::cout << str;
}