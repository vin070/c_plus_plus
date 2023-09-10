#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

void print_arr(std::vector<int> const& arr) {
    for (auto val : arr) {
        std::cout << val << " ";
    }
    std::cout << '\n';
}

void take_input(std::vector<int>& arr, int const& n) {
    arr.reserve(n);
    for (int i = 0; i < n; ++i) {
        int ele = 0;
        std::cin >> ele;
        arr.push_back(ele);
    }
}

/**
 * T(n) = kn
 * S(n) = O(k)
 * https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/arrays-and-strings/majority-element-general/ojquestion
*/
auto majority_ele_2(std::vector<int>& arr, int const& k) {
    std::vector<int> ans;
    std::unordered_map <int, int> probable_majority_eles;
    int const& min_freq = (arr.size() / k);
    //n.k
    for (int i = 0; i < arr.size(); ++i) {
        if (probable_majority_eles.find(arr[i]) != probable_majority_eles.end()) {
            ++probable_majority_eles[arr[i]];
        }
        else if (probable_majority_eles.size() < k - 1) {
            probable_majority_eles.insert({ arr[i], 1 });
        }
        else if (probable_majority_eles.size() >= k - 1) {
            for (auto it = probable_majority_eles.begin(); it != probable_majority_eles.end();) {
                --it->second;
                if (!it->second) {
                    probable_majority_eles.erase(it);
                    continue;
                }
                ++it;
            }
        }
    }

    //kn
    for (auto val : probable_majority_eles) {
        int freq = 0;
        for (int i = 0; i < arr.size(); ++i) {
            if (arr[i] == val.first) ++freq;
        }
        if (freq > min_freq) ans.push_back(val.first);
    }

    //klog(k)
    std::sort(ans.begin(), ans.end());
    return ans;
}

int main() {
    int arr_size = 0, k = 0;
    std::vector<int> arr;
    std::cin >> arr_size;
    take_input(arr, arr_size);
    std::cin >> k;
    auto ans = majority_ele_2(arr, k);
    print_arr(ans);
    return 0;
}