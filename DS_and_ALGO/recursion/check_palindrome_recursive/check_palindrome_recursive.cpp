#include<iostream>
#include<cstring>

bool check_palindrome(char const * const input, int start_index, int end_index){
    if( end_index - start_index <= 1)
        return true;
    
    return check_palindrome(input, start_index + 1, end_index - 1) && 
           input[start_index] == input[end_index];
}

bool checkPalindrome(char input[]) {
  return check_palindrome(input,0,strlen(input)-1);
}

int main() {
    char input[50] = {0};
    std::cin >> input;
    
    if(checkPalindrome(input))
        std::cout << "true" << '\n';
    else 
        std::cout << "false" << '\n';
}