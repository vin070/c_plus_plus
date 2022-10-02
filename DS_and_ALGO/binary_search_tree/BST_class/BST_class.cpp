#include <iostream>
using namespace std;

template <typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

class BST {
private:
    BinaryTreeNode<int>* root;

    bool search(BinaryTreeNode<int>* root, int const& data) {
        if (!root) return false;

        if (root->data == data)
            return true;
        if (data > root->data)
            return search(root->right, data);
        else
            return search(root->left, data);
    }

    void print(BinaryTreeNode<int>* root) {
        if (!root) return;

        std::cout << root->data << ":";
        if (root->left) {
            std::cout << "L:" << root->left->data << ',';
        }

        if (root->right) {
            std::cout << "R:" << root->right->data;
        }
        std::cout << '\n';
        if (root->left) print(root->left);
        if (root->right) print(root->right);
    }

    BinaryTreeNode<int>* insert(BinaryTreeNode<int>* root, int const& data) {
        if (!root) {
            BinaryTreeNode<int>* new_node = new BinaryTreeNode<int>(data);
            return new_node;
        }

        if (data > root->data) {
            BinaryTreeNode<int>* right_ans = insert(root->right, data);
            root->right = right_ans;
        }
        else {
            BinaryTreeNode<int>* left_ans = insert(root->left, data);
            root->left = left_ans;
        }

        return root;
    }

    BinaryTreeNode<int>* remove(BinaryTreeNode<int>* root, int const& data) {
        if (!root) return NULL;

        if (root->data == data) {

            if (!root->left && !root->right) {
                delete root;
                return NULL;
            }
            else if (!root->left) {
                BinaryTreeNode<int>* temp = root->right;
                root->right = NULL;
                delete root;
                return temp;
            }
            else if (!root->right) {
                BinaryTreeNode<int>* temp = root->left;
                root->left = NULL;
                delete root;
                return temp;
            }
            else {
                BinaryTreeNode<int>* right_node = root->right;
                while (right_node->left) {
                    right_node = right_node->left;
                }
                root->data = right_node->data;
                root->right = remove(root->right, right_node->data);
                return root;

            }
        }
        else if (data > root->data) {
            BinaryTreeNode<int>* right_ans = remove(root->right, data);
            root->right = right_ans;
        }
        else {
            BinaryTreeNode<int>* left_ans = remove(root->left, data);
            root->left = left_ans;
        }

        return root;
    }
public:
    BST() {
        root = NULL;
    }

    void remove(int data) {
        BinaryTreeNode<int>* new_root = remove(root, data);
        root = new_root;
    }

    void print() {
        print(root);
    }

    void insert(int data) {
        BinaryTreeNode<int>* new_root = insert(root, data);
        root = new_root;
    }

    bool search(int data) {
        return search(root, data);
    }

    ~BST() {
        delete root;
    }
};




int main() {
    BST* tree = new BST();
    int choice, input, q;
    cin >> q;
    while (q--) {
        cin >> choice;
        switch (choice) {
        case 1:
            cin >> input;
            tree->insert(input);
            break;
        case 2:
            cin >> input;
            tree->remove(input);
            break;
        case 3:
            cin >> input;
            cout << ((tree->search(input)) ? "true\n" : "false\n");
            break;
        default:
            tree->print();
            break;
        }
    }
    delete tree;
}