#include<iostream>
#include<vector>

class Solution {
public:

    std::vector<long long int> product_except_self(std::vector<long long int>& nums, int n) {
        std::vector<long long int> left_mul, right_mul, ans;
        right_mul.resize(n, 0);
        //Fill left mul
        for (int i = 0;i < nums.size(); ++i) {
            long long const mul = (i == 0) ? nums.at(i) : nums.at(i) * left_mul.at(i - 1);
            left_mul.push_back(mul);
        }

        //Fill right mul
        for (int i = nums.size() - 1; i >= 0; --i) {
            right_mul[i] = (long long int)(i == nums.size() - 1) ? nums.at(i) : nums.at(i) * right_mul.at(i + 1);
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (i == 0) {
                ans.push_back(right_mul.at(i + 1));
            }
            else if (i + 1 == nums.size()) {
                ans.push_back(left_mul.at(i - 1));
            }
            else {
                ans.push_back(left_mul.at(i - 1) * right_mul.at(i + 1));
            }
        }
        return ans;

    }
};

int main() {
    int t = 0;
    std::cin >> t;
    while (t--)
    {
        int n;
        std::cin >> n;
        std::vector<long long int> arr(n), vec(n);
        for (int i = 0;i < n;i++) {
            std::cin >> arr[i];
        }
        Solution obj;
        vec = obj.product_except_self(arr, n);
        for (int i = 0;i < n;i++) {
            std::cout << vec[i] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}