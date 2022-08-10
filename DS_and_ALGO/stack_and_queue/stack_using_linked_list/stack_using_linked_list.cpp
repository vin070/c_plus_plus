#include <iostream>

template <typename l> class linked_list {
private:
  l data;
  linked_list *next;

public:
  linked_list() {
    this->data = l();
    this->next = NULL;
  }

  linked_list(l data) { this->data = data; }

  l get_data() const { return this->data; }

  void set_next(linked_list *next) { this->next = next; }

  linked_list *get_next() const { return this->next; }
};

template <typename s> class stack : protected linked_list<s> {
  int size = 0;
  linked_list<s> *head;

public:
  stack() {
    this->size = 0;
    this->head = NULL;
  }

  void push(s data) {
    linked_list<s> *new_node = new linked_list<s>(data);
    new_node->set_next(this->head);
    this->head = new_node;
    ++this->size;
  }

  bool is_empty() { return this->head == NULL; }

  void pop() {
    if (this->is_empty())
      return;

    linked_list<s> *next = this->head->get_next();
    delete this->head;
    this->head = next;
    --this->size;
  }

  int get_size() const { return this->size; }

  s top() {
    if (this->is_empty())
      return s();

    return this->head->get_data();
  }
};


int main() {
  stack<int> st;

  int q = 0;
  std::cin >> q;

  while (q--) {
    int choice;
    int input;
    std::cin >> choice;
    switch (choice) {
    case 1:
      std::cin >> input;
      st.push(input);
      break;
    case 2:
      st.pop();
      break;
    case 3:
      std::cout << st.top() << "\n";
      break;
    case 4:
      std::cout << st.get_size() << "\n";
      break;
    default:
      std::cout << ((st.is_empty()) ? "true\n" : "false\n");
      break;
    }
  }
}