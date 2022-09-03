#include <cmath>
#include <iostream>
#include <queue>

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

template <typename T> std::pair<int, bool> is_balanced(binary_tree<T> *root) {
  if (!root) {
    std::pair<int, int> p(0, true);
    return p;
  }

  std::pair<int, bool> left_child = is_balanced(root->get_left_node());
  std::pair<int, bool> right_child = is_balanced(root->get_right_node());

  std::pair<int, bool> ans;
  ans.first = std::max(left_child.first, right_child.first) + 1;
  ans.second = (std::abs(left_child.first - right_child.first) <= 1) &&
               left_child.second && right_child.second;
  return ans;
}

template <typename T> bool is_balanced(binary_tree<int> *root) {
  return is_balanced(root).second;
}

int main() {
  binary_tree<int> *root = binary_tree<int>::take_input_levelwise();
  bool balanced = is_balanced<int>(root);
  std::cout << (balanced ? "true" : "false") << '\n';
  delete root;
  return 0;
}