#include <iostream>
#include<cstring>

void shift_right(char *input, int n){
    
    int length = strlen(input);
    for(int i = length; i >= n; --i)
        input[i + n] = input[i];
}

void replacePi(char *input) {
    if(input[0] == '\0')
        return;

    else if(input[0] == 'p' && input[1] == 'i') {
        shift_right(input, 2);
        input[0] = '3';
        input[1] = '.';
        input[2] = '1';
        input[3] = '4';
        replacePi(input + 4);
    }
    else replacePi(input + 1);
}

int main() {
    char input[10000];
    std::cin.getline(input, 10000);
    replacePi(input);
    std::cout << input << '\n';
}