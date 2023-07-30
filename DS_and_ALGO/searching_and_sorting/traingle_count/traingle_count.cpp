#include<iostream>
#include<vector>
#include<algorithm>

void take_input(std::vector<int>& vect, int n) {
    for (int i = 0; i < n; ++i) {
        int input = 0;
        std::cin >> input;
        vect.push_back(input);
    }
}

int traingle_count(std::vector<int>& vect) {
    int count = 0;
    std::sort(vect.begin(), vect.end());
    for (int j = vect.size() - 1; j >= 2; --j) {
        for (int i = 0, k = j - 1; i < k; ) {
            if (vect.at(i) + vect.at(k) > vect.at(j)) {
                count += (k - i);
                --k;
            } else {
                ++i;
            }
        }
    }
    return count;

}

int main() {
    std::vector<int> vect;
    int n = 0;
    std::cin >> n;
    vect.reserve(n);
    take_input(vect, n);
    std::cout << traingle_count(vect) << '\n';
}