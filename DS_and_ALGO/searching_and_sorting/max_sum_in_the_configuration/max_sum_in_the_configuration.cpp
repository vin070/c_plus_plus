#include<iostream>
#include<vector>

void take_input(std::vector<int>& vect, int n) {
    for (int i = 0; i < n; ++i) {
        int input = 0;
        std::cin >> input;
        vect.push_back(input);
    }
}
/**
 * Question = https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/searching-and-sorting/max-sum-in-the-configuration/ojquestion
 * Time complexity = O(n)
*/
int max_sum(std::vector<int>& vect) {
    int sum = 0;
    for(int i = 0; i < vect.size(); ++i) {
        sum += vect.at(i);
    }

    int max_sum = 0;
    for(int i = 0; i < vect.size(); ++i) {
        max_sum += (i*vect.at(i));
    }
     
    int prev_rotation_sum = max_sum;
    for(int i = 0; i < vect.size() - 1; ++i) {
        prev_rotation_sum = prev_rotation_sum + (sum - vect.at(vect.size() - 1 - i)) - (vect.at(vect.size() - 1 - i) * (vect.size() - 1));
        if(prev_rotation_sum > max_sum) {
            max_sum = prev_rotation_sum;
        }
    }

    return max_sum;
}
int main() {
    std::vector<int> vect;
    int n = 0;
    std::cin >> n;
    vect.reserve(n);
    take_input(vect, n);
    std::cout<<max_sum(vect)<<'\n';
}