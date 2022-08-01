#include <algorithm>
#include <iostream>

class fraction {
private:
  int numerator = 0;
  int denominator = 0;

  void simplify() {
    int hcf = 1;
    int minimum = std::min(this->numerator, this->denominator);
    for (int i = 2; i <= minimum; ++i) {
      if (numerator % i == 0 && denominator % i == 0)
        hcf = i;
    }
    numerator /= hcf;
    denominator /= hcf;
  }

public:
  fraction(int numerator, int denominator) {
    this->numerator = numerator;
    this->denominator = denominator;
  }

  int get_numerator() { return numerator; }

  int get_denominator() const { return denominator; }

  void set_numerator(int numerator) { this->numerator = numerator; }

  void set_denominator(int denominator) { this->denominator = denominator; }

  fraction operator+(fraction const &f) const {
    unsigned long lcm = denominator * f.denominator;
    int new_numerator =
        numerator * (lcm / denominator) + f.numerator * (lcm / f.denominator);
    fraction add_result(new_numerator, lcm);
    add_result.simplify();
    return add_result;
  }

  fraction operator-(fraction const &f) const {
    unsigned long lcm = denominator * f.denominator;
    int new_numerator =
        numerator * (lcm / denominator) - f.numerator * (lcm / f.denominator);
    fraction add_result(new_numerator, lcm);
    add_result.simplify();
    return add_result;
  }

  fraction operator*(fraction const &f) const{
    unsigned long new_denominator = denominator * f.denominator;
    long new_numerator = numerator * f.numerator;
    fraction multiply_result(new_numerator, new_denominator);
    multiply_result.simplify();
    return multiply_result;
  }

  fraction operator/(fraction const &f) const{
    unsigned long new_denominator = denominator * f.numerator;
    long new_numerator = numerator * f.denominator;
    fraction divide_result(new_numerator, new_denominator);
    divide_result.simplify();
    return divide_result;
  }

  // Pre increment
  fraction &operator++() {
    numerator += denominator;
    this->simplify();
    return *this;
  }

  // Post increment
  fraction operator++(int) {
    fraction old_value(*this);
    numerator += denominator;
    this->simplify();
    return old_value;
  }

  // Pre decrement
  fraction &operator--() {
    numerator -= denominator;
    this->simplify();
    return *this;
  }

  // Post decrement
  fraction operator--(int) {
    fraction old_value(*this);
    numerator -= denominator;
    this->simplify();
    return old_value;
  }

  void print() const{
    std::cout << numerator << " " << denominator << std::endl;
  }

  fraction& operator+=(fraction const &f) {
    unsigned long lcm = denominator * f.denominator;
    numerator =
        numerator * (lcm / denominator) + f.numerator * (lcm / f.denominator);
    denominator = lcm;
    this->simplify();

    return *this;
  }

  fraction& operator-=(fraction const &f) {
    unsigned long lcm = denominator * f.denominator;
    numerator =
        numerator * (lcm / denominator) - f.numerator * (lcm / f.denominator);
    denominator = lcm;
    this->simplify();

    return *this;
  }
};

int main() {
  fraction f1(2, 3), f2(4, 5);
  fraction add = f1 + f2;
  fraction multiply = f1 * f2;
  fraction subtract = f1 - f2;
  fraction divide = f1 / f2;
  fraction pre_increment = ++(++f1);
  fraction post_increment = f1++;
  (--f1);
  (f1--)--;
  f1.print();
  (f1 += f2) += f2;
  f1.print();
}