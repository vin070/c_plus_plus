#include <iostream>
#include<cstring>

/** Swap values in given array at given indexes
 * @param { char * } array - Input array in which values to be swapped
 * @param { int } i -  Index at which value to be changes
 * @param { int } j - Index at which value to be changes
 * @returns { void }
*/
void swap_values(char *array, int i, int j){
     char temp = array[i];
     array[i] = array[j];
     array[j] = temp;
}

void reverse_string(char *word,int starting_index, int end_index){
    while(starting_index < end_index){
        swap_values(word,starting_index,end_index);
        ++starting_index;
        --end_index;
    }
}

void reverse_word_wise(char *sentence){
    int sentence_length = strlen(sentence);
    reverse_string(sentence,0, sentence_length - 1);

    for( int i = 0, start_index = 0; i <= sentence_length; ++i){
         if(sentence[i] == ' '|| sentence[i] == '\0'){
             reverse_string(sentence,start_index, i - 1);
             start_index = i + 1;
         }
    }
}

int main() {
    char input[1000];
    std::cin.getline(input, 1000);
    reverse_word_wise(input);
    std::cout << input << '\n';
}
