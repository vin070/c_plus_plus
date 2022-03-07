#include <iostream>
#include <cstring>

void reverse_word(char *str, int start_index, int end_index) {
    while(start_index < end_index){
        char temp = str[start_index];
        str[start_index] = str[end_index];
        str[end_index] = temp;
        ++start_index;
        --end_index;        
    }
}

void reverse_each_word(char *str) {
    int start_index = 0;
    for(int i = 0; str[i] != '\0'; ++i) {
        if(str[i+1] == ' ' || str[i+1] == '\0'){
            reverse_word(str,start_index,i);
            start_index = i + 2; 
        }
    }
}

int main() {
    int size = 1e6;
    char str[size];
    std::cin.getline(str, size);
    reverse_each_word(str);
    std::cout << str;
}