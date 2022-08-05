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
      return temp;

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

  static linked_list *insert_recursively(linked_list *head, int start_index,
                                         int index, int data) {

    if (start_index == index) {
      linked_list *new_node = new linked_list(data);
      new_node->set_next(head);
      return new_node;
    } else if (head == NULL)
      return NULL;

    linked_list *small_ans = linked_list::insert_recursively(
        head->get_next(), start_index + 1, index, data);
    head->set_next(small_ans);
    return head;
  }

  static linked_list *delete_recursively(linked_list *head, int start_index,
                                         int index) {
    if (head == NULL || start_index > index)
      return head;
    else if (start_index == index) {
      linked_list *delete_node_next = head->get_next();
      delete head;
      return delete_node_next;
    }

    linked_list *small_ans = linked_list::delete_recursively(
        head->get_next(), start_index + 1, index);
    head->set_next(small_ans);
    return head;
  }

  static int find_node(linked_list *head, int start_index, int data) {
    if (!head)
      return -1;
    else if (head->get_data() == data)
      return start_index;

    return linked_list::find_node(head->get_next(), start_index + 1, data);
  }
};

linked_list *reverse_linked_list(linked_list *head) {
  linked_list *prev = NULL;
  linked_list *curr = head;
  while (curr) {
    linked_list *next = curr->get_next();
    curr->set_next(prev);
    prev = curr;
    curr = next;
  }
  return prev;
}

int main() {
  int test_cases = 0;
  std::cin >> test_cases;
  while (test_cases--) {
    linked_list *head = linked_list::take_input();
    head = reverse_linked_list(head);
    linked_list::print(head);
    linked_list::delete_all(head);
  }
  return 0;
}