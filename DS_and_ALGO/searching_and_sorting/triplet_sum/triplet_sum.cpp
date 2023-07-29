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

int triplet_sum(std::vector<int>& vect) {
    int count = 0;
    std::sort(vect.begin(), vect.end());

    for (int i = 0; i < vect.size() - 1; ++i) {
        for (int j = 0, k = vect.size() - 2 - i; j < k; ) {
            int const sum = vect.at(k) + vect.at(j); 
          if(sum == vect.at(vect.size() - 1 - i)) {
               ++j;
               --k;
               ++count;
          } else if(sum > vect.at(vect.size() - 1 - i)) {
            --k;
          } else {
            ++j;
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
    std::cout<<triplet_sum(vect)<<'\n';
}