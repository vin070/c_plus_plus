#include<iostream>
#include<cstring>

bool is_vowel(const char str) {
    if (str == 'a' || str == 'e' || str == 'i' || str == 'o' || str == 'u' ||
        str == 'A' || str == 'E' || str == 'I' || str == 'O' || str == 'U'
        ) {
        return true;
    }
    return false;
}

void reverse_only_vowels(std::string* str) {
    for (int i = 0, j = str->length() - 1; i < j;) {
        if (is_vowel(str->at(i)) && is_vowel(str->at(j))) {
            std::swap(str->at(i), str->at(j));
            ++i;
            --j;
        }
        else if (!is_vowel(str->at(i))) {
            ++i;
        }
        else if (!is_vowel(str->at(j))) {
            --j;
        }
    }
}

int main() {
    std::string str;
    std::cin >> str;
    reverse_only_vowels(&str);
    std::cout << str << '\n';
    return 0;
};