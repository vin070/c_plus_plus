#include <iostream>
#include <cstring>

std::string compressed_string(std::string const &input) {

    std::string compressed_str = "";
    char last_char = '\n';
    int last_char_freq = 1;

    for(int i = 0; input[i] != '\0'; ++i) {
        if(input[i] != last_char) {
            if(last_char_freq > 1)
                compressed_str += std::to_string(last_char_freq);
            compressed_str += input[i];
            last_char = input[i];
            last_char_freq = 1;
        }
        else if(input[i] == last_char)
            ++last_char_freq;
    }

    return last_char_freq > 1?
           compressed_str+std::to_string(last_char_freq):
           compressed_str;
}

int main() {
    int size = 1e6;
    std::string str;
    std::getline(std::cin, str);
    str = compressed_string(str);
    std::cout << str <<'\n';
}