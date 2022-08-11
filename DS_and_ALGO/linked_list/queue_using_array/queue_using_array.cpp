#include <iostream>

// How much new array size will increase when array becomes full.
#define arr_increment_factor 5

// Initial size of dynamically allocated array
#define arr_initial_size 5

template <typename T> class queue {
  T *arr;
  int capacity;
  int front_index;
  int back_index;
  int size;

public:
  queue() {
    arr = new T[arr_initial_size];
    front_index = -1;
    back_index = 0;
    capacity = arr_initial_size;
    size = 0;
  }

  void push(T data) {
    if (get_size() == capacity) {
      T *new_arr = new T[capacity + arr_increment_factor];
      for (int i = 0; i < capacity; ++i) {
        new_arr[i] = arr[front_index];
        ++front_index;
        front_index %= capacity;
      }
      front_index = 0;
      back_index = capacity;
      capacity += arr_increment_factor;
      delete[] arr;
      arr = new_arr;
      std::cout << "array size increased = " << back_index << std::endl;
    }
    std::cout << "Back index = " << back_index << std::endl;
    arr[back_index] = data;
    back_index = (back_index + 1) % capacity;
    if (front_index == -1)
      front_index = 0;
    ++size;
  }

  int get_size() const { return this->size; }

  bool is_empty() const { return size == 0; }

  void pop() {
    if (is_empty())
      return;
    front_index = (front_index + 1) % capacity;
    --size;

    if (is_empty()) {
      front_index = -1;
      back_index = 0
    }
  }

  T front() const {
    if (is_empty())
      return T();

    return arr[front_index];
  }

  T back() const {
    if (is_empty())
      return T();

    return arr[back_index];
  }
};

int main() {
  queue<int> q;

  int t = 0;
  std::cin >> t;

  while (t--) {
    int choice, input;
    std::cin >> choice;
    switch (choice) {
    case 1:
      std::cin >> input;
      q.push(input);
      break;
    case 2:
      q.pop();
      break;
    case 3:
      std::cout << q.front() << "\n";
      break;
    case 4:
      std::cout << q.get_size() << "\n";
      break;
    default:
      std::cout << ((q.is_empty()) ? "true\n" : "false\n");
      break;
    }
  }
}