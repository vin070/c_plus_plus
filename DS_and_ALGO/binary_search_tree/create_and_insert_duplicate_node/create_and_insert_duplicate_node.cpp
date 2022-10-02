#include<iostream>
#include<queue>

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

void insert_duplicate_node(BST<int>* root) {
    if (!root) return;

    BST<int>* duplicate_node = new BST<int>(root->get_data());
    if (root->get_left())
        duplicate_node->set_left(root->get_left());
    root->set_left(duplicate_node);
    insert_duplicate_node(duplicate_node->get_left());
    insert_duplicate_node(root->get_right());
}

void print_level_at_newline(BST<int>* root) {
    std::queue<BST<int>*> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        BST<int>* first = q.front();
        q.pop();
        if (!first) {
            if (q.empty()) {
                break;
            }
            std::cout << '\n';
            q.push(NULL);
            continue;
        }
        std::cout << first->get_data() << " ";
        if (first->get_left()) {
            q.push(first->get_left());
        }
        if (first->get_right()) {
            q.push(first->get_right());
        }
    }
}

int main() {
    BST<int>* root = BST<int>::create_BST_levelwise();
    insert_duplicate_node(root);
    print_level_at_newline(root);
    delete root;
}