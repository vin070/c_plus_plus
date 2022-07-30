#include <iostream>

class complex_numbers {
  int real;
  int imaginary;

public:
  complex_numbers(int real, int imaginary) {
    this->imaginary = imaginary;
    this->real = real;
  }

  void plus(complex_numbers const &c2) {
    real += c2.real;
    imaginary += c2.imaginary;
    return;
  }

  void multiply(complex_numbers const &c2) {
    int new_real = real * c2.real - imaginary * c2.imaginary;
    int new_imaginary = (real * c2.imaginary) + (imaginary * c2.real);
    real = new_real;
    imaginary = new_imaginary;
    return;
  }

  void print() {
    std::cout << real << " "
              << "+"
              << " "
              << "i" << imaginary;
  }
};

int main() {
  int real1, imaginary1, real2, imaginary2;

  std::cin >> real1 >> imaginary1;
  std::cin >> real2 >> imaginary2;

  complex_numbers c1(real1, imaginary1);
  complex_numbers c2(real2, imaginary2);

  int choice;
  std::cin >> choice;

  if (choice == 1) {
    c1.plus(c2);
    c1.print();
  } else if (choice == 2) {
    c1.multiply(c2);
    c1.print();
  } else
    return 0;
}