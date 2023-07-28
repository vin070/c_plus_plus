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
 * Time complexity = O(n/2)
*/
auto find_first_and_last_index_1(std::vector<int>& vect, int const& ele) {
    int* const ans = new int[2] {-1, -1};
    for (int i = 0, j = vect.size() - 1; i <= j;) {
        if (vect.at(i) != ele && vect.at(j) != ele) {
            ++i;
            --j;
        }
        else if (vect.at(i) != ele && vect.at(j) == ele) {
            ++i;
        }
        else if (vect.at(i) == ele && vect.at(j) != ele) {
            --j;
        }
        else {
            ans[0] = i;
            ans[1] = j;
            break;
        }
    }
    return ans;
}


int main() {
    std::vector<int> vect;
    int n = 0, ele = 0;
    std::cin >> n;
    vect.reserve(n);
    take_input(vect, n);
    std::cin >> ele;

    /**
     * Approach 2
     * Time complexity = O(logn)
    */
    int first_index = -1, last_index = -1;
    for (int i = 0, j = vect.size() - 1; i <= j;) {
        int const mid = (i + j) / 2;
        if (vect.at(mid) == ele) {
            first_index = mid;
            j = mid - 1;
        }
        else if (vect.at(mid) < ele) {
            i = mid + 1;
        }
        else {
            j = mid - 1;
        }
    }

    for (int i = 0, j = vect.size() - 1; i <= j;) {
        int const mid = (i + j) / 2;
        if (vect.at(mid) == ele) {
            last_index = mid;
            i = mid + 1;
        }
        else if (vect.at(mid) < ele) {
            i = mid + 1;
        }
        else {
            j = mid - 1;
        }
    }

    std::cout << first_index << " " << last_index << '\n';
}