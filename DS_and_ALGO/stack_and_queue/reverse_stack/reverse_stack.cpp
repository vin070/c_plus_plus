#include <iostream>
#include <stack>

// Recursive approach
// void reverse_stack(stack<int> &input, stack<int> &extra) {
//     if(input.empty()){
//         input.swap(extra);
//         return;
//     };

//     extra.push(input.top());
//     input.pop();

//     reverse_stack(input,extra);
// }

// Non recursive approach
void reverse_stack(std::stack<int> &input, std::stack<int> &extra) {
  while (!input.empty()) {
    extra.push(input.top());
    input.pop();
  }
  input.swap(extra);
}

int main() {
  std::stack<int> input, extra;
  int size = 0;
  std::cin >> size;

  for (int i = 0; i < size; i++) {
    int val = 0;
    std::cin >> val;
    input.push(val);
  }

  reverse_stack(input, extra);

  while (!input.empty()) {
    std::cout << input.top() << " ";
    input.pop();
  }
  return 0;
}