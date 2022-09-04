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

template <typename T>
void elements_in_range_K1K2(binary_tree<T> *root, int const &k1,
                            int const &k2) {
  if (!root)
    return;

  if (root->get_data() > std::max(k1, k2))
    elements_in_range_K1K2(root->get_left_node(), k1, k2);
  else if (root->get_data() < std::min(k1, k2))
    elements_in_range_K1K2(root->get_right_node(), k1, k2);
  else if (root->get_data() >= k1 && root->get_data() <= k2) {
    elements_in_range_K1K2(root->get_left_node(), k1, k2);
    std::cout << root->get_data() << " ";
    elements_in_range_K1K2(root->get_right_node(), k1, k2);
  }
}

int main() {
  binary_tree<int> *root = binary_tree<int>::take_input_levelwise();
  int lower_bound = 0, upper_bound = 0;
  std::cin >> lower_bound >> upper_bound;
  elements_in_range_K1K2(root, lower_bound, upper_bound);
  delete root;
  return 0;
}