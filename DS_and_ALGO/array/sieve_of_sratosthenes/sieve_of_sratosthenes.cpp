#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

/**
 * https://leetcode.com/problems/count-primes/
 * S(n) = O(n)
 * T(n) =  n* root(n)
*/
auto mark_prime_numbers(int const& n) {
    std::vector<bool> vect;
    vect.resize(n, true);
    float const upper_limit = std::sqrt(vect.size());
    for (int i = 2; i <= upper_limit; ++i) {
        if (!vect[i])
            continue;
        for (int j = i * i; j < vect.size(); j += i) {
            vect[j] = false;
        }
    }
    return vect;
}

auto find_prime_numbers(int const& n) {
    std::vector<int> ans;
    auto numbers_array = mark_prime_numbers(n);
    for (int i = 2; i < numbers_array.size(); ++i) {
        if (numbers_array[i]) ans.push_back(i);
    }
    return ans.size();
}

int main() {
    int n = 0;
    std::cin >> n;
    std::cout << find_prime_numbers(n) << '\n';
    return 0;
}