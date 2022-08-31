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

  static binary_tree<T> *take_input_recursive() {
    T data = -1;
    std::cin >> data;
    if (data == -1)
      return NULL;

    binary_tree<T> *node = new binary_tree<T>(data);
    node->update_left_node(binary_tree<T>::take_input_recursive());
    node->update_right_node(binary_tree<T>::take_input_recursive());
    return node;
  }

  static void print_recursive(binary_tree<T> *root) {
    if (!root)
      return;

    std::cout << root->get_data() << ":";

    if (root->get_left_node()) {
      std::cout << "L" << root->get_left_node()->get_data();

      if (root->get_right_node())
        std::cout << ",R" << root->get_right_node()->get_data();

    } else if (root->get_right_node())
      std::cout << "R" << root->get_right_node()->get_data();

    std::cout << '\n';

    binary_tree<T>::print_recursive(root->get_left_node());
    binary_tree<T>::print_recursive(root->get_right_node());
  }

  static void print_levelwise(binary_tree<T> *root) {
    if (!root)
      return;

    std::queue<binary_tree<T> *> q;
    q.push(root);
    while (!q.empty()) {
      binary_tree<T> *curr_node = q.front();
      q.pop();
      std::cout << curr_node->get_data() << ":";
      if (curr_node->get_left_node()) {
        std::cout << "L:" << curr_node->get_left_node()->get_data();
        q.push(curr_node->get_left_node());
      } else
        std::cout << "L:" << -1;

      if (curr_node->get_right_node()) {
        std::cout << ",R:" << curr_node->get_right_node()->get_data() << '\n';
        q.push(curr_node->get_right_node());
      } else
        std::cout << ",R:" << -1 << '\n';
    }
  }

  static unsigned long count_node(binary_tree<T> *root) {
    if (!root)
      return 0;

    return 1 + binary_tree<T>::count_node(root->get_left_node()) +
           binary_tree<T>::count_node(root->get_right_node());
  }

  ~binary_tree() {
    delete left_node;
    delete right_node;
  }
};

int main() {
  binary_tree<int> *root = binary_tree<int>::take_input_recursive();
  std::cout << binary_tree<int>::count_node(root) << std::endl;
  delete root;
  return 0;
}