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

  void static delete_all(linked_list *head) {
    while (head != NULL) {
      linked_list *new_head = head->get_next();
      delete head;
      head = new_head;
    }
    return;
  }

  static void print(linked_list *head) {
    while (head != NULL) {
      std::cout << head->get_data() << " ";
      head = head->get_next();
    }
    std::cout << std::endl;
  }
};

linked_list *swap_nodes(linked_list *head, int const &i, int const &j) {

  linked_list *temp = head;
  linked_list *i_node_prev = NULL;
  linked_list *j_node_prev = NULL;
  for (int k = 0, l = 0; (k < i || l < j) && temp;) {
    if (i - 1 == k)
      i_node_prev = temp;
    if (j - 1 == l)
      j_node_prev = temp;
    temp = temp->get_next();
    ++k;
    ++l;
  }

  if (i_node_prev && i_node_prev) {
    linked_list *temp = i_node_prev->get_next();
    i_node_prev->set_next(j_node_prev->get_next());
    j_node_prev->set_next(temp);

    temp = i_node_prev->get_next()->get_next();
    i_node_prev->get_next()->set_next(j_node_prev->get_next()->get_next());
    j_node_prev->get_next()->set_next(temp);
    return head;
  } else if (i_node_prev) {
    linked_list *temp1 = i_node_prev->get_next();
    linked_list *temp = head->get_next();
    i_node_prev->set_next(head);
    head->set_next(temp1->get_next());
    temp1->set_next(temp);
    return temp1;
  } else if (j_node_prev) {
    linked_list *temp1 = j_node_prev->get_next();
    linked_list *temp = head->get_next();
    j_node_prev->set_next(head);
    head->set_next(temp1->get_next());
    temp1->set_next(temp);
    return temp1;
  } else
    return head;
}

int main() {
  int test_cases = 0;
  std::cin >> test_cases;
  while (test_cases--) {
    int first_node = 0;
    int second_node = 0;
    linked_list *head = linked_list::take_input();
    std::cin >> first_node >> second_node;
    head = swap_nodes(head, first_node, second_node);
    linked_list::print(head);
    linked_list::delete_all(head);
  }
  return 0;
}