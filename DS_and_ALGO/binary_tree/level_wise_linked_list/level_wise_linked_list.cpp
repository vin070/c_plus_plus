#include <iostream>
#include <queue>
#include <vector>

template <typename T> class linked_list {
private:
  T data;
  linked_list *next = NULL;

public:
  linked_list(T data) { this->data = data; }

  T get_data() const { return this->data; }

  void set_next(linked_list *next) { this->next = next; }

  linked_list *get_next() const { return this->next; }

  static void print(linked_list *head) {
    while (head != NULL) {
      std::cout << head->get_data() << " ";
      head = head->get_next();
    }
    std::cout << std::endl;
  }
};

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
std::vector<linked_list<T> *>
construct_linked_list_for_each_level(binary_tree<T> *root) {
  std::vector<linked_list<T> *> v = {};
  if (!root)
    return v;

  std::queue<binary_tree<T> *> q;
  q.push(root);
  q.push(NULL);
  linked_list<T> *tail = NULL;

  while (!q.empty()) {
    binary_tree<T> *curr_node = q.front();
    q.pop();
    if (!curr_node) {
      if (q.size())
        q.push(NULL);
      tail = NULL;
      continue;
    }
    linked_list<T> *new_node = new linked_list<T>(curr_node->get_data());
    if (curr_node->get_left_node())
      q.push(curr_node->get_left_node());
    if (curr_node->get_right_node())
      q.push(curr_node->get_right_node());

    if (!tail) {
      v.push_back(new_node);
      tail = new_node;
    } else {
      tail->set_next(new_node);
      tail = new_node;
    }
  }
  return v;
}

int main() {
  binary_tree<int> *root = binary_tree<int>::take_input_levelwise();
  std::vector<linked_list<int> *> v =
      construct_linked_list_for_each_level<int>(root);
  for (std::vector<linked_list<int> *>::const_iterator it = v.begin();
       it != v.end(); ++it) {
    linked_list<int>::print(*it);
  }
  delete root;
  return 0;
}