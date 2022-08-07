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

// Recursive approach
linked_list *skip_M_delete_N_node(linked_list *head, int const &M,
                                  int const &N) {
  if (!head || N == 0)
    return head;

  // Skip M node
  linked_list *skip_node = head;
  for (int i = 0; i < M - 1 && skip_node; ++i)
    skip_node = skip_node->get_next();

  // Delete N node
  linked_list *delete_node = NULL;
  if (M == 0)
    delete_node = skip_node;
  else if (skip_node && M > 0)
    delete_node = skip_node->get_next();
  for (int i = 0; i < N && delete_node; ++i) {
    linked_list *next_node = delete_node->get_next();
    delete delete_node;
    delete_node = next_node;
  }

  // Call the recursion on remaining node
  linked_list *ans = skip_M_delete_N_node(delete_node, M, N);
  if (M != 0) {
    if (skip_node)
      skip_node->set_next(ans);
    return head;
  } else if (M == 0)
    return ans;
}

int main() {
  int test_cases = 0;
  std::cin >> test_cases;
  while (test_cases--) {
    int skip_node = 0;
    int delete_node = 0;
    linked_list *head = linked_list::take_input();
    std::cin >> skip_node >> delete_node;
    head = skip_M_delete_N_node(head, skip_node, delete_node);
    linked_list::print(head);
    linked_list::delete_all(head);
  }
  return 0;
}