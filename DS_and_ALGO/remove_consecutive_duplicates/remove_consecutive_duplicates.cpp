#include <iostream>
#include <cstring>

void shift_left(char *str, int const start_index){
    for(int i = start_index; str[i] != '\0'; ++i)
        str[i] = str[i + 1];
}

void remove_consecutive_duplicates(char *str){
    for(int i = 0; str[i] != '\0';){
        if(str[i] == str[i+1])
            shift_left(str,i);

        if(str[i] != str[i+1])
            ++i;
    }
}

int main() {
    int size = 1e6;
    char str[size];
    std::cin >> str;
    remove_consecutive_duplicates(str);
    std::cout << str;
}