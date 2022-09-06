#include <iostream>
#include <limits>
#include <queue>
template <typename T> class linked_list {
private:
  T data;
  linked_list *next = NULL;

public:
  linked_list(T data) { this->data = data; }

  T get_data() const { return this->data; }

  void set_next(linked_list *next) { this->next = next; }

  linked_list *get_next() const { return this->next; }

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

template <typename T> class binary_tree {
  T data;
  binary_tree<T> *left_node;
  binary_tree<T> *right_node;

public:
  binary_tree(T data) {
    this->data = data;
    left_node = NULL;
    right_node = NULL;
  }

  void update_data(T data) { this->data = data; }

  T get_data() const { return data; }

  void update_left_node(binary_tree<T> *const left_node) {
    this->left_node = left_node;
  }

  void update_right_node(binary_tree<T> *const right_node) {
    this->right_node = right_node;
  }

  binary_tree<T> *get_left_node() const { return left_node; }
  binary_tree<T> *get_right_node() const { return right_node; }
  static binary_tree<T> *take_input_levelwise() {
    int root_data = -1;
    std::cin >> root_data;
    if (root_data == -1)
      return NULL;
    binary_tree<T> *root = new binary_tree<T>(root_data);
    std::queue<binary_tree<T> *> q;
    q.push(root);

    while (!q.empty()) {
      binary_tree<T> *curr_node = q.front();
      q.pop();
      int left_child = -1, right_child = -1;
      std::cin >> left_child;
      if (left_child != -1) {
        binary_tree<T> *left_node = new binary_tree<T>(left_child);
        curr_node->update_left_node(left_node);
        q.push(left_node);
      }

      std::cin >> right_child;
      if (right_child != -1) {
        binary_tree<T> *right_node = new binary_tree<T>(right_child);
        curr_node->update_right_node(right_node);
        q.push(right_node);
      }
    }
    return root;
  }

  ~binary_tree() {
    delete left_node;
    delete right_node;
  }
};

template <typename T>
std::pair<linked_list<T> *, linked_list<T> *>
construct_linked_list_helper(binary_tree<T> *root) {
  if (!root) {
    std::pair<linked_list<T> *, linked_list<T> *> ans(NULL, NULL);
    return ans;
  }
  std::pair<linked_list<T> *, linked_list<T> *> left_head =
      construct_linked_list_helper<T>(root->get_left_node());
  std::pair<linked_list<T> *, linked_list<T> *> right_head =
      construct_linked_list_helper<T>(root->get_right_node());
  linked_list<T> *middle_node = new linked_list<T>(root->get_data());
  middle_node->set_next(right_head.first);
  std::pair<linked_list<T> *, linked_list<T> *> ans(NULL, NULL);
  if (left_head.first) {
    left_head.second->set_next(middle_node);
    ans.first = left_head.first;
  } else
    ans.first = middle_node;

  if (right_head.second) {
    ans.second = right_head.second;
  } else
    ans.second = middle_node;
  return ans;
}

template <typename T>
linked_list<T> *construct_linked_list(binary_tree<T> *root) {
  return construct_linked_list_helper<T>(root).first;
}

int main() {
  binary_tree<int> *root = binary_tree<int>::take_input_levelwise();
  linked_list<int> *head = construct_linked_list<int>(root);
  linked_list<int>::print(head);
  linked_list<int>::delete_all(head);
  delete root;
  return 0;
}