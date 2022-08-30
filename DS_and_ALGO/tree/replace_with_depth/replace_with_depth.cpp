#include <iostream>
#include <limits>
#include <queue>
#include <vector>

template <typename T> class tree_node {
private:
  T data;

public:
  std::vector<tree_node<T> *> child;

  tree_node() {
    data = T();
    child = {};
  }

  tree_node(T const &data) {
    this->data = data;
    child = {};
  }

  T get_data() const { return data; }

  void set_data(T data) { this->data = data; }
  void update_data(T const &data) { this->data = data; }

  static tree_node<T> *take_input_recursive() {
    T data = T();
    std::cin >> data;
    tree_node<T> *root = new tree_node<T>(data);
    int n = 0;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
      tree_node<T> *child = tree_node<T>::take_input();
      root->child.push_back(child);
    }
    return root;
  }

  static void print_tree_recursive(tree_node<T> const *const root) {
    if (!root)
      return;

    std::cout << root->get_data() << ": ";
    for (int i = 0; i < root->child.size(); ++i) {
      std::cout << root->child.at(i)->get_data();
      if (i + 1 != root->child.size())
        std::cout << ",";
    }
    std::cout << std::endl;
    for (int i = 0; i < root->child.size(); ++i) {
      tree_node<T>::print_tree_recursive(root->child.at(i));
    }
  }

  static void print_tree_levelwise(tree_node<T> *const root) {
    if (!root)
      return;
    std::queue<tree_node<T> *>q;
    q.push(root);
    while (!q.empty()) {
      tree_node<T> *curr_node = q.front();
      q.pop();
      std::cout << curr_node->get_data() << ":";
      for (int i = 0; i < curr_node->child.size(); ++i) {
        std::cout << curr_node->child.at(i)->get_data();
        if (i + 1 != curr_node->child.size())
          std::cout << ",";
        q.push(curr_node->child.at(i));
      }
      std::cout << std::endl;
    }
  }

  static tree_node<T> *take_input_levelwise() {
    std::queue<tree_node<T> *> pending_nodes;
    T data = T();
    std::cin >> data;
    tree_node<T> *root = new tree_node<T>(data);
    pending_nodes.push(root);
    while (!pending_nodes.empty()) {
      tree_node<T> *node = pending_nodes.front();
      pending_nodes.pop();
      int num_of_child = 0;
      std::cin >> num_of_child;
      for (int i = 0; i < num_of_child; ++i) {
        T child_data = T();
        std::cin >> child_data;
        tree_node<T> *new_child = new tree_node<T>(child_data);
        pending_nodes.push(new_child);
        node->child.push_back(new_child);
      }
    }
    return root;
  }

  static unsigned long count_node(tree_node<T> *root) {
    if (!root)
      return 0;

    unsigned long ans = 1;
    for (int i = 0; i < root->child.size(); ++i) {
      ans += count_node(root->child.at(i));
    }
    return ans;
  }
};

template <typename T>
void replace_with_depth_value(tree_node<T> *root, int curr_level) {

  if (!root)
    return;

  root->set_data(curr_level);
  for (int i = 0; i < root->child.size(); ++i)
    replace_with_depth_value(root->child.at(i), curr_level + 1);
}

template <typename T> void replace_with_depth_value(tree_node<int> *root) {
  replace_with_depth_value(root, 0);
}
int main() {
  tree_node<int> *root = tree_node<int>::take_input_levelwise();
  replace_with_depth_value<int>(root);
  tree_node<int>::print_tree_levelwise(root);
  return 0;
}