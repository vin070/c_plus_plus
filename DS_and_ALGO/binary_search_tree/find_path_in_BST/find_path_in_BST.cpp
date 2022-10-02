#include<iostream>
#include<queue>
#include<vector>

template<typename T>
class linked_list {
    T data;
    linked_list<T>* next;

public:
    linked_list() {
        data = T();
        next = NULL;
    }

    linked_list(T data) {
        this->data = data;
    }

    T get_data() {
        return this->data;
    }

    linked_list<T>* get_next() {
        return this->next;
    }

    void set_data(T data) {
        this->data = data;
    }

    void set_next(linked_list<T>* next) {
        this->next = next;
    }

    static void print_linked_list(linked_list<T>* head) {
        while (head != NULL) {
            std::cout << head->get_data() << " ";
            head = head->get_next();
        }
        std::cout << '\n';
    }

    ~linked_list() {
        delete next;
    }
};

template<typename T>
class BST {
    T data;
    BST<T>* left;
    BST<T>* right;

public:
    BST() {
        data = T();
        this->left = NULL;
        this->right = NULL;
    }

    BST(T data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

    T get_data() {
        return this->data;
    }

    void set_data(T data) {
        this->data = data;
    }

    BST<T>* get_left() {
        return this->left;
    }

    void set_left(BST<T>* left) {
        this->left = left;
    }

    BST<T>* get_right() {
        return this->right;
    }

    void set_right(BST<T>* right) {
        this->right = right;
    }

    static BST<T>* create_BST_levelwise() {
        T root_data = T();
        std::cin >> root_data;
        if (root_data == -1) return NULL;

        BST<T>* root = new BST<T>(root_data);
        std::queue<BST<T>*> q;
        q.push(root);
        while (!q.empty()) {
            BST<T>* front = q.front();
            q.pop();

            T left_data = T();
            std::cin >> left_data;
            if (left_data != -1) {
                BST<T>* left_node = new BST<T>(left_data);
                q.push(left_node);
                front->set_left(left_node);
            }

            T right_data = T();
            std::cin >> right_data;
            if (right_data != -1) {
                BST<T>* right_node = new BST<T>(right_data);
                q.push(right_node);
                front->set_right(right_node);
            }

        }
        return root;
    }

    ~BST() {
        delete left;
        delete right;
    }
};

template<typename T>
std::vector<T>* get_path(BST<T>* root, T const& data) {
    if (!root) {
        std::vector<T>* ans = new std::vector<T>();
        return ans;
    }

    if (root->get_data() == data) {
        std::vector<T>* ans = new std::vector<T>();
        ans->push_back(root->get_data());
        return ans;
    }

    std::vector<T>* left_ans = get_path(root->get_left(), data);
    if (left_ans->size()) {
        left_ans->push_back(root->get_data());
        return left_ans;
    }

    std::vector<T>* right_ans = get_path(root->get_right(), data);
    if (right_ans->size()) {
        right_ans->push_back(root->get_data());
        return right_ans;
    }

    return (new std::vector<T>());

}

int main() {
    BST<int>* root = BST<int>::create_BST_levelwise();
    int search_data = 0;
    std::cin >> search_data;
    std::vector<int>* ans = get_path<int>(root, search_data);
    delete root;

    for (std::vector<int>::const_iterator it = ans->begin(); it != ans->end(); ++it)
        std::cout << *it << " ";
    std::cout << '\n';

    delete ans;
}