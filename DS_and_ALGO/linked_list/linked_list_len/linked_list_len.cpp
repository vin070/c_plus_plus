#include <iostream>

class linked_list {
private:
  int data;
  linked_list *next = NULL;

public:
  linked_list(int data) { this->data = data; }

  int get_data() const { return this->data; }

  void set_next(linked_list *next) { this->next = next; }

  linked_list *get_next() const { return this->next; }

  static linked_list *take_input() {
    int data = 0;
    std::cin >> data;
    linked_list *head = NULL, *tail = NULL;
    while (data != -1) {
      linked_list *node = new linked_list(data);
      if (head == NULL) {
        head = node;
        tail = node;
      } else {
        tail->set_next(node);
        tail = node;
      }
      std::cin >> data;
    }
    return head;
  }

  static int length(linked_list *head) {
    // Non recursively
    int len = 0;
    while (head != NULL) {
      head = head->get_next();
      ++len;
    }
    return len;
  }

  static void print(linked_list *head) {
    while (head != NULL) {
      std::cout << head->get_data() << " ";
      head = head->get_next();
    }
    std::cout << std::endl;
  }
};

int main() {
  int test_case = 0;
  std::cin >> test_case;
  while (test_case--) {
    linked_list *head = linked_list::take_input();
    std::cout << linked_list::length(head) << std::endl;
  }
  return 0;
}