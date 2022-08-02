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

    // Recursively
    // if (head == NULL)
    //   return 0;

    // return 1 + linked_list::length(head->get_next());
  }

  static void print(linked_list *head) {
    while (head != NULL) {
      std::cout << head->get_data() << " ";
      head = head->get_next();
    }
    std::cout << std::endl;
  }

  static void print_node(linked_list *head, int index) {
    int i = 0;
    while (head != NULL) {
      if (i == index) {
        std::cout << head->get_data() << std::endl;
        break;
      }
      head = head->get_next();
      ++i;
    }
    return;
  }

  static linked_list *insert(linked_list *head, int const &index, int data) {
    linked_list *temp = head;
    int len = linked_list::length(temp);
    if (index < 0 || index > len)
      return head;

    for (int i = 0; i < index - 1; ++i)
      temp = temp->get_next();

    linked_list *new_node = new linked_list(data);

    if (index == 0) {
      new_node->set_next(temp);
      return new_node;
    } else if (index == len) {
      temp->set_next(new_node);
    } else {
      linked_list *temp1 = temp->get_next();
      temp->set_next(new_node);
      new_node->set_next(temp1);
    }
    return head;
  }

  static linked_list *delete_node(linked_list *head, int const &index) {
    linked_list *temp = head;
    int len = linked_list::length(temp);
    if (index < 0 || index >= len)
      return head;

    for (int i = 0; i < index - 1; ++i)
      temp = temp->get_next();

    if (index == 0) {
      linked_list *new_head = temp->get_next();
      delete temp;
      return new_head;
    } else if (index == len - 1) {
      delete temp->get_next();
      temp->set_next(NULL);
    } else {
      linked_list *delete_node = temp->get_next();
      temp->set_next(delete_node->get_next());
      delete delete_node;
    }
    return head;
  }

  void static delete_all(linked_list *head) {
    while (head != NULL) {
      linked_list *new_head = head->get_next();
      delete head;
      head = new_head;
    }
    return;
  }
};

int main() {
  int test_case = 0;
  std::cin >> test_case;
  while (test_case--) {
    linked_list *head = linked_list::take_input();
    int insert_index = 0, insert_data = 0;
    std::cin >> insert_index >> insert_data;
    head = linked_list::insert(head, insert_index, insert_data);

    int delete_index = 0;
    std::cin >> delete_index;
    head = linked_list::delete_node(head, delete_index);
    linked_list::print(head);
    linked_list::delete_all(head);
  }
  return 0;
}