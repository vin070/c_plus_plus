#include <iostream>
#include <queue>

void reverseQueue(std::queue<int> &input) {
  if (input.empty())
    return;

  int front = input.front();
  input.pop();

  reverseQueue(input);
  input.push(front);
}

int main() {
  int t = 0;
  std::cin >> t;

  while (t--) {
    std::queue<int> q;
    int size;
    std::cin >> size;

    for (int i = 0; i < size; i++) {
      int val = 0;
      std::cin >> val;
      q.push(val);
    }

    reverseQueue(q);
    while (!q.empty()) {
      std::cout << q.front() << " ";
      q.pop();
    }

    std::cout << "\n";
  }
}