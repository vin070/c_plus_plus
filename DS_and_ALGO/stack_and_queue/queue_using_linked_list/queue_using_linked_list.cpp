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

template <typename q> 
class queue: protected linked_list<q> {
  linked_list<q> *head;
  linked_list<q> *tail;
  int size;

public:
  queue() {
    head = NULL;
    tail = NULL;
    size = 0;
  }

  int get_size() const { return size; }

  bool is_empty() const { return size == 0; }

  void push(q data) {
    linked_list<q> *new_node = new linked_list<q>(data);
    if (!head) {
      head = new_node;
      tail = new_node;
    } else if (tail) {
      tail->set_next(new_node);
      tail = new_node;
    }
    ++size;
  }

  q pop() {
    if (is_empty())
      return q();
      
    q temp = head->get_data();
    linked_list<q> *head_next = head->get_next();
    delete head;
    head = head_next;
    --size;
    if (get_size() == 0)
      tail = NULL;
    return temp;
  }

  q front() {
    if (is_empty())
      return q();
    return head->get_data();
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