#include <iostream>
#include <cstring>

bool is_permutation(char *str1, char *str2){
    
    if(strlen(str1) != strlen(str2))
        return false;
    
    int lowercase[123]= {0};

    for(int i = 0; str1[i] != '\0'; ++i)
        ++lowercase[int(str1[i])];

    for(int i = 0; str2[i] != '\0'; ++i)
        --lowercase[int(str2[i])];
    
    for(int i = 97; i < 123; ++i) {
        if(lowercase[i] != 0)
        return false;
    }
    return true;

}

int main() {
    int size = 1e6;
    char str1[size];
    char str2[size];
    std::cin >> str1 >> str2;
    std::cout << (is_permutation(str1, str2) ? "true" : "false");
}