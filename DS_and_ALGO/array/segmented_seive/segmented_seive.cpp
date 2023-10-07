#include<iostream>
#include<vector>
#include<cmath>

template<typename T>
auto mark_prime_numbers(T const& n) {
    std::vector<bool> vect;
    vect.resize(n + 1, true);
    auto const upper_limit = std::sqrt(vect.size());
    for (T i = 2; i <= upper_limit; ++i) {
        if (!vect[i])
            continue;
        for (T j = i * i; j < vect.size(); j += i) {
            vect[j] = false;
        }
    }
    return vect;
}

template<typename T>
auto find_prime_numbers(T const& n) {
    std::vector<T> ans;
    auto numbers_array = mark_prime_numbers(n);
    for (T i = 2; i < numbers_array.size(); ++i) {
        if (numbers_array[i]) ans.push_back(i);
    }
    return ans;
}

/**
 * https://practice.geeksforgeeks.org/problems/product-of-primes5328/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
 * T(n) = 
 * S(n) = O(n) where n = R - L
*/
template<typename T = long long>
auto prime_product(T const& L, T const& R) {
    //Find prime number till sqrt of number
    std::vector<T> prime_number = find_prime_numbers<T>(std::floor(std::sqrt(R)));

    //Create a array which stores whether is number is prime or not. 
    std::vector<bool> vect(std::abs(R - L + 1), true);
    for (auto val : prime_number) {
        T lowest_mul = std::max((long long)std::ceil((L * 1.0) / val), (long long)2);
        for (int i = val * lowest_mul; i - L < vect.size(); i += val) {
            vect[i - L] = false;
        }
    }
    
    //Calculate the prime number product
    long long final_ans = 1;
    for (long long i = 0; i < vect.size(); ++i) {
        if (!vect[i]) continue;
        final_ans *= (L + i);
        final_ans = final_ans % (1000000007);
    }
    return final_ans;

}

int main() {
    long long low_num = 0, upper_num = 0;
    std::cin >> low_num >> upper_num;
    std::cout << prime_product(low_num, upper_num) << '\n';
    return 0;
}