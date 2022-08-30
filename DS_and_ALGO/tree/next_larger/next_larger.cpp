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

// Solution 1
/**
 template <typename T> class next_larger {
public:
  tree_node<T> *node;
  T diff;

  next_larger() {
    diff = std::numeric_limits<T>::max();
    node = NULL;
  }

  next_larger(tree_node<T> *node, T diff) {
    this->node = node;
    this->diff = diff;
  }
};

template <typename T>
next_larger<T> *get_next_larger_element(tree_node<T> *root, int const &x) {
  next_larger<T> *ans = new next_larger<T>();
  if (root->get_data() > x && root->get_data() - x < ans->diff) {
    delete ans;
    ans = new next_larger<T>(root, root->get_data() - x);
  }

  for (int i = 0; i < root->child.size(); ++i) {
    next_larger<T> *small_ans = get_next_larger_element(root->child.at(i), x);
    if (small_ans->diff < ans->diff) {
      delete ans;
      ans = small_ans;
    }
  }
  return ans;
}

tree_node<int> *getNextLargerElement(tree_node<int> *root, int const &x) {
  if (!root)
    return NULL;
  return get_next_larger_element<int>(root, x)->node;
}
 **/

// Solution 2
tree_node<int> *get_next_larger_element(tree_node<int> *root, int const &n) {
  tree_node<int> *ans = NULL;
  if (root->get_data() > n)
    ans = root;

  for (int i = 0; i < root->child.size(); i++) {
    tree_node<int> *child = get_next_larger_element(root->child.at(i), n);

    if (child && ans && child->get_data() < ans->get_data() || !ans)
      ans = child;
  }
  return ans;
}
int main() {
  tree_node<int> *root = tree_node<int>::take_input_levelwise();
  int lower_limit = std::numeric_limits<int>::min();
  std::cin >> lower_limit;
  tree_node<int> *ans = get_next_larger_element(root, lower_limit);
  if (ans != NULL)
    std::cout << ans->get_data() << '\n';
  return 0;
}