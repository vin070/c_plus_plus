#include<iostream>
#include<vector>

/**
 * https://leetcode.com/problems/maximum-swap/
 * T(n) = O(n)
 * S(n) = O(n)
*/
int maximum_swap(int num) {
    std::vector<int> vect, max_num_index;
    while (num) {
        vect.push_back(num % 10);
        num /= 10;
    }

    for (int i = 0; i < vect.size(); ++i) {
        if (!i) {
            max_num_index.push_back(i);
        }
        else {
            max_num_index.push_back(vect[i] > vect[max_num_index[i - 1]] ? i : max_num_index[i - 1]);
        }
    }

    for (int i = vect.size() - 1; i >= 0; --i) {
        if (vect.at(i) != vect.at(max_num_index.at(i))) {
            std::swap(vect.at(i), vect.at(max_num_index.at(i)));
            break;
        }
    }

    int ans = 0;
    for (int i = 0, mul = 1; i < vect.size(); ++i, mul *= 10) {
        ans += (mul * vect.at(i));
    }
    return ans;
}


int main() {
    int n = 0;
    std::cin >> n;
    std::cout << maximum_swap(n) << '\n';
    return 0;
};