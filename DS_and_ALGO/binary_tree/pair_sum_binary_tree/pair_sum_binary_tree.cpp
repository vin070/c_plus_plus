#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

template<typename T>
class binary_tree {
    T data;
    binary_tree<T>* left;
    binary_tree<T>* right;

public:
    binary_tree() {
        data = T();
        this->left = NULL;
        this->right = NULL;
    }

    binary_tree(T data) {
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

    binary_tree<T>* get_left() {
        return this->left;
    }

    void set_left(binary_tree<T>* left) {
        this->left = left;
    }

    binary_tree<T>* get_right() {
        return this->right;
    }

    void set_right(binary_tree<T>* right) {
        this->right = right;
    }

    static binary_tree<T>* create_binary_tree_levelwise() {
        T root_data = T();
        std::cin >> root_data;
        if (root_data == -1) return NULL;

        binary_tree<T>* root = new binary_tree<T>(root_data);
        std::queue<binary_tree<T>*> q;
        q.push(root);
        while (!q.empty()) {
            binary_tree<T>* front = q.front();
            q.pop();

            T left_data = T();
            std::cin >> left_data;
            if (left_data != -1) {
                binary_tree<T>* left_node = new binary_tree<T>(left_data);
                q.push(left_node);
                front->set_left(left_node);
            }

            T right_data = T();
            std::cin >> right_data;
            if (right_data != -1) {
                binary_tree<T>* right_node = new binary_tree<T>(right_data);
                q.push(right_node);
                front->set_right(right_node);
            }

        }
        return root;
    }

    ~binary_tree() {
        delete left;
        delete right;
    }
};

void tree_to_arr(binary_tree<int>* root, std::vector<int>* ans) {
    if (!root) return;

    ans->push_back(root->get_data());
    tree_to_arr(root->get_left(), ans);
    tree_to_arr(root->get_right(), ans);
}

void pair_sum(binary_tree<int>* root, int const& sum) {
    std::vector<int>* ans = new std::vector<int>();
    tree_to_arr(root, ans);
    std::sort(ans->begin(), ans->end());
    for (int i = 0, j = ans->size() - 1; i < j;) {
        if (ans->at(i) + ans->at(j) == sum) {
            std::cout << ans->at(i) << " " << ans->at(j) << '\n';
            ++i;
            --j;
        }
        else if (ans->at(i) + ans->at(j) < sum)
            ++i;
        else
            --j;
    }
    delete ans;
}

int main() {
    int sum = 0;
    binary_tree<int>* root = binary_tree<int>::create_binary_tree_levelwise();
    std::cin >> sum;
    pair_sum(root, sum);
    delete root;
}