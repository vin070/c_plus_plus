#include <cstring>
#include <iostream>

const std::string keypad_code_mapping[] = {
    "", "", "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"
};

int keypad(int num, std::string output[]) {
  if (num <= 1) return 1;

  int possible_combinations = keypad(num / 10, output);

  std::string keypad_code = keypad_code_mapping[num % 10];
  int keypad_code_length = keypad_code.length();
  
  for (int i = 0; i < keypad_code_length; ++i) {
    for (int j = 0; j < possible_combinations; ++j) {
      if (i + 1 != keypad_code_length)
        output[possible_combinations * (i + 1) + j] =
            output[possible_combinations * i + j];
    
      output[possible_combinations * i + j] += keypad_code[i];
    }
  }
  return possible_combinations * keypad_code_length;
}


int main(){
    int num;
    std::cin >> num;

    std::string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        std::cout << output[i] << std::endl;
    }
    return 0;
}