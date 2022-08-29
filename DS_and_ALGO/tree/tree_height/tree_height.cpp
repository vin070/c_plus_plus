#include <iostream>
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

  static void print_tree_levelwise(tree_node<T> const *const root) {
    if (!root)
      return;
    std::queue<tree_node<T> *> q;
    q.push(root);
    while (!q.empty()) {
      tree_node<T> *curr_node = q.front();
      q.pop();
      std::cout << curr_node->get_data() << ":";
      for (int i = 0; i < curr_node->chid.size(); ++i) {
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

template <typename T> tree_node<T> *max_data_node(tree_node<T> *root) {
  tree_node<T> *max = root;

  for (int i = 0; i < root->children.size(); ++i) {
    tree_node<T> *ans = max_data_node(root->children.at(i));
    max = ans->get_data() > max->get_data() ? ans : max;
  }
  return max;
}

template <typename T> int tree_height(tree_node<T> const *const root) {
  if (!root)
    return 0;

  int child_height = 0;
  for (int i = 0; i < root->child.size(); ++i) {
    int ans = tree_height(root->child.at(i));
    child_height = ans > child_height ? ans : child_height;
  }
  return child_height + 1;
}

int main() {
  tree_node<int> *root = tree_node<int>::take_input_levelwise();
  tree_node<int>::print_tree_recursive(root);
  std::cout << tree_node<int>::count_node(root) << '\n';
  std::cout << tree_height(root) << std::endl;
  return 0;
}