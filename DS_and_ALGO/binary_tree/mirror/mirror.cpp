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

  static void print_levelwise(binary_tree<T> *root) {
    if (!root)
      return;

    std::queue<binary_tree<T> *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
      binary_tree<T> *curr_node = q.front();
      q.pop();
      if (!curr_node) {
        if (q.empty()) {
          std::cout << '\n';
          break;
        }
        std::cout << '\n';
        q.push(NULL);
        continue;
      }
      std::cout << curr_node->get_data() << " ";
      if (curr_node->get_left_node())
        q.push(curr_node->get_left_node());
      if (curr_node->get_right_node())
        q.push(curr_node->get_right_node());
    }
  }

  ~binary_tree() {
    delete left_node;
    delete right_node;
  }
};

template <typename T> void mirror_binary_tree(binary_tree<T> *root) {
  if (!root)
    return;

  mirror_binary_tree(root->get_left_node());
  mirror_binary_tree(root->get_right_node());

  // Swap left and right node
  binary_tree<T> *temp = root->get_left_node();
  root->update_left_node(root->get_right_node());
  root->update_right_node(temp);
}

int main() {
  binary_tree<int> *root = binary_tree<int>::take_input_levelwise();
  mirror_binary_tree(root);
  binary_tree<int>::print_levelwise(root);
  delete root;
  return 0;
}