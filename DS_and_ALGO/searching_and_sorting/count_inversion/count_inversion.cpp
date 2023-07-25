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

/**
 * https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/searching-and-sorting/count_inversions/ojquestion
 * Time complexity = O(nlogn)
 * Space complexity = O(n)
*/
int merge_sort(std::vector<int>& vect, int const start_index, int const last_index) {
    if (start_index >= last_index) {
        return 0;
    }
    int mid_index = (start_index + last_index) / 2;
    int left_ans = merge_sort(vect, start_index, mid_index);
    int right_ans = merge_sort(vect, mid_index + 1, last_index);

    //Sort the first and second half and merge it back using temporary array
    std::vector<int> temp_vec;
    temp_vec.reserve(last_index - start_index + 1);
    int count_inv = 0,
        i = start_index,
        j = mid_index + 1;
    while (i <= mid_index && j <= last_index)
    {
        if (vect.at(i) < vect.at(j)) {
            temp_vec.push_back(vect.at(i));
            ++i;
        }
        else if (vect.at(i) > vect.at(j)) {
            temp_vec.push_back(vect.at(j));
            count_inv += (mid_index - i + 1);
            ++j;
        }
        else if (vect.at(i) == vect.at(j)) {
            temp_vec.push_back(vect.at(i));
            temp_vec.push_back(vect.at(j));
            ++i;
            ++j;
        }
    }

    for (; i <= mid_index; ++i) {
        temp_vec.push_back(vect.at(i));
    }

    for (; j <= last_index; ++j) {
        temp_vec.push_back(vect.at(j));
    }

    for (int i = start_index, j = 0; i <= last_index; ++i, ++j) {
        vect[i] = temp_vec.at(j);
    }

    return (left_ans + right_ans + count_inv);
}

int count_inversion(std::vector<int>& vect) {
    return merge_sort(vect, 0, vect.size() - 1);
}
int main() {
    std::vector<int> vect;
    int n = 0;
    std::cin >> n;
    vect.reserve(n);
    take_input(vect, n);
    std::cout << count_inversion(vect) << '\n';
}