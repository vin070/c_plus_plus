#include<iostream>
#include<vector>

void take_input(std::vector<int>& vect, int const& size) {
  for (int i = 0; i < size; ++i) {
    int ele = 0;
    std::cin >> ele;
    vect.push_back(ele);
  }
}
/**
 * Q = https://practice.geeksforgeeks.org/problems/punish-the-students5726/1
 * T(n) = O(n^2)
 * S(n) = 1
*/
auto will_professor_loose_job(std::vector<int>& roll, std::vector<int>& student_marks, float const& min_marks) {
  int swap_count = 0;
  //Find swap count
  for (int i = 0; i < roll.size() - 1; ++i) {
    for (int j = 0; j < roll.size() - 1 - i; ++j) {
      if (roll.at(j) > roll.at(j + 1)) {
        swap_count += 2;
        std::swap(roll.at(j), roll.at(j + 1));
      }
    }
  }
  //Find average
  int total_marks = 0;
  for (auto marks : student_marks) {
    total_marks += marks;
  }
  float avg_marks = ((float)(total_marks - swap_count) / roll.size());
  return avg_marks > min_marks ? "true" : "false";
}

int main() {
  int students = 0;
  float min_marks = 0;
  std::vector<int> roll, student_marks;
  std::cin >> students;
  take_input(roll, students);
  take_input(student_marks, students);
  std::cin >> min_marks;
  std::cout << will_professor_loose_job(roll, student_marks, students);
}