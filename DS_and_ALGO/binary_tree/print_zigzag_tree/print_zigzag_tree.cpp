#include <iostream>
#include <queue>
#include <stack>
#include <vector>

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

template <typename T> void zig_zag_order(binary_tree<T> *root) {
  if (!root)
    return;
  int level = 0;
  std::stack<binary_tree<T> *> stack_even, stack_odd;
  stack_even.push(root);
  while (!stack_even.empty() || !stack_odd.empty()) {
    if (level % 2 == 0) {
      binary_tree<T> *curr_node = stack_even.top();
      stack_even.pop();
      if (curr_node->get_left_node())
        stack_odd.push(curr_node->get_left_node());
      if (curr_node->get_right_node())
        stack_odd.push(curr_node->get_right_node());
      std::cout << curr_node->get_data() << " ";
      if (stack_even.empty()) {
        std::cout << '\n';
        ++level;
      }
    } else {
      binary_tree<T> *curr_node = stack_odd.top();
      stack_odd.pop();
      if (curr_node->get_right_node())
        stack_even.push(curr_node->get_right_node());
      if (curr_node->get_left_node())
        stack_even.push(curr_node->get_left_node());

      std::cout << curr_node->get_data() << " ";
      if (stack_odd.empty()) {
        std::cout << '\n';
        ++level;
      }
    }
  }
}
int main() {
  binary_tree<int> *root = binary_tree<int>::take_input_levelwise();
  zig_zag_order<int>(root);
  delete root;
  return 0;
}