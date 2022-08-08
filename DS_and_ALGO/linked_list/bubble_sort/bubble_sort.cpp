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

  static int length(linked_list *head) {
    int len = 0;
    while (head != NULL) {
      head = head->get_next();
      ++len;
    }
    return len;
  }
};

linked_list *swap_nodes(linked_list *head, int i, int j) {
  if (i > j) {
    int temp = i;
    i = j;
    j = temp;
  }
  linked_list *i_node_prev = NULL;
  linked_list *i_node = NULL;
  linked_list *j_node_prev = NULL;
  linked_list *j_node = NULL;
  linked_list *temp = head;
  for (int k = 0, l = 0; (k <= i || l <= j) && temp; ++k, ++l) {
    if (k == i - 1)
      i_node_prev = temp;
    else if (k == i)
      i_node = temp;

    if (l == j - 1)
      j_node_prev = temp;
    else if (l == j)
      j_node = temp;

    temp = temp->get_next();
  }
  if (i != 0 && j != 0 && j - i != 1) {
    linked_list *temp = i_node_prev->get_next();
    i_node_prev->set_next(j_node_prev->get_next());
    j_node_prev->set_next(temp);

    temp = i_node->get_next();
    i_node->set_next(j_node->get_next());
    j_node->set_next(temp);
    return head;
  } else if (i == 0 && j > 1) {
    j_node_prev->set_next(head);

    linked_list *temp = i_node->get_next();
    i_node->set_next(j_node->get_next());
    j_node->set_next(temp);
    return j_node;
  } else if (i == 0 && j == 1) {
    i_node->set_next(j_node->get_next());
    j_node->set_next(i_node);
    return j_node;
  } else if (j - i == 1) {
    i_node_prev->set_next(j_node);
    i_node->set_next(j_node->get_next());
    j_node->set_next(i_node);
    return head;
  }

  return head;
}

linked_list *bubble_sort(linked_list *head) {

  linked_list *final_head = head;
  int len = linked_list::length(head);
  for (int i = 0; i < len - 1; ++i) {

    linked_list *temp = final_head;
    for (int j = 0; j < len - 1 - i; ++j) {
      if (temp->get_data() > temp->get_next()->get_data())
        final_head = swap_nodes(final_head, j, j + 1);
      else
        temp = temp->get_next();
    }
  }
  return final_head;
}

int main() {
  linked_list *head = linked_list::take_input();
  head = bubble_sort(head);
  linked_list::print(head);
  linked_list::delete_all(head);
  return 0;
}