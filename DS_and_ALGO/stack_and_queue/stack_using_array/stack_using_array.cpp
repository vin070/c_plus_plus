#include <iostream>

// How much new array size will increase when array becomes full.
#define arr_increment_factor 10

// Initial size of dynamically allocated array
#define arr_initial_size 10

template <typename T> class stack {
  T *arr = NULL;
  int next_index = 0;
  int capacity = arr_initial_size;

public:
  stack() { this->arr = new T[arr_initial_size]; }

  void push(T const &data) {
    if (next_index == capacity) {

      T *new_arr = new T[capacity + arr_increment_factor];
      for (int i = 0; i < next_index; ++i)
        new_arr[i] = this->arr[i];

      delete[] this->arr;
      this->arr = new_arr;
      this->capacity += arr_increment_factor;
    }
    this->arr[this->next_index] = data;
    ++this->next_index;
  }

  bool is_empty() const { return this->next_index == 0; }

  int size() const { return this->next_index; }

  T top() const {
    if (this->is_empty())
      return -1;
    return this->arr[next_index - 1];
  }

  void pop() {
    if (this->is_empty())
      return;
    --this->next_index;
  }
};

int main() {

  stack<int> *s = new stack<int>();
  for (int i = 0; i < 20; ++i)
    s->push(i + 1);

  std::cout << "size before deletion = " << s->size() << std::endl;
  for (int i = 0; i < 20; ++i)
    s->pop();

  std::cout << "top element = " << s->top() << std::endl;
  std::cout << "size after deletion = " << s->size() << std::endl;

  stack<int> *s1 = new stack<int>();
  s1->push(10.123);
  std::cout << s1->top() << std::endl;

  delete s;
  delete s1;
  return 0;
}