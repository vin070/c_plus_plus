#include <iostream>
#include <limits>
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

  ~binary_tree() {
    delete left_node;
    delete right_node;
  }
};

template <typename T>
binary_tree<T> *construct_tree(T const* const input, int const start_index,
                               int const end_index) {
  if (start_index > end_index)
    return NULL;

  int mid = (start_index + end_index) / 2;
  binary_tree<T> *new_node = new binary_tree<T>(input[mid]);
  new_node->update_left_node(construct_tree<T>(input, start_index, mid - 1));
  new_node->update_right_node(construct_tree<T>(input, mid + 1, end_index));
  return new_node;
}

template <typename T = int> binary_tree<T> *construct_tree(T *input, int n) {
  return construct_tree<T>(input, 0, n - 1);
}

template <typename T> void preorder_traversal(binary_tree<T> *root) {
  if (!root)
    return;

  std::cout << root->get_data() << " ";
  preorder_traversal(root->get_left_node());
  preorder_traversal(root->get_right_node());
}

int main() {
  int size = 0;
  std::cin >> size;
  int *input = new int[size];
  for (int i = 0; i < size; i++)
    std::cin >> input[i];

  binary_tree<int> *root = construct_tree(input, size);
  preorder_traversal(root);
  delete[] input;
  delete root;
  return 0;
}