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

template <typename T>
binary_tree<T> *build_tree(T *preorder, T *inorder, int preorder_start,
                           int preorder_end, int inorder_start,
                           int inorder_end) {

  if (preorder_start > preorder_end || inorder_start > inorder_end)
    return NULL;

  int inorder_root_index = -1;
  for (int i = inorder_start; i <= inorder_end; ++i) {
    if (preorder[preorder_start] == inorder[i]) {
      inorder_root_index = i;
      break;
    }
  }

  if (inorder_root_index == -1)
    return NULL;
    
  binary_tree<T> *node = new binary_tree<T>(preorder[preorder_start]);
  int inorder_left_start = inorder_start;
  int inorder_left_end = inorder_root_index - 1;
  int inorder_right_start = inorder_root_index + 1;
  int inorder_right_end = inorder_end;
  int preorder_left_start = preorder_start + 1;
  int preorder_left_end =
      inorder_left_end - inorder_left_start + preorder_left_start;
  int preorder_right_start = preorder_left_end + 1;
  int preorder_right_end = preorder_end;

  node->update_left_node(build_tree(preorder, inorder, preorder_left_start,
                                    preorder_left_end, inorder_left_start,
                                    inorder_left_end));
  node->update_right_node(build_tree(preorder, inorder, preorder_right_start,
                                     preorder_right_end, inorder_right_start,
                                     inorder_right_end));
  return node;
}
template <typename T>
binary_tree<T> *build_tree(T *preorder, int preLength, T *inorder,
                           int inLength) {
  return build_tree(preorder, inorder, 0, preLength - 1, 0, inLength - 1);
}

int main() {
  int *preorder = NULL, *inorder = NULL;
  int size = 0;
  std::cin >> size;
  preorder = new int[size];
  inorder = new int[size];

  for (int i = 0; i < size; ++i)
    std::cin >> preorder[i];

  for (int i = 0; i < size; ++i)
    std::cin >> inorder[i];
  binary_tree<int> *root = build_tree(preorder, size, inorder, size);
  binary_tree<int>::print_levelwise(root);
  delete[] preorder;
  delete[] inorder;
  return 0;
}