#include <bits/stdc++.h>

class Collatz {
  public:
    void calculus (int n) {
      while (n != 1) {
        std::cout << n << " → ";
        if (n & 1)
          n = 3*n + 1;
        else
          n = n/2;
      }
      std::cout << n << std::endl;
    }
};

int main(void) {
  Collatz C;
  int integer;
  std::cout << "Input an intger: ";
  std::cin >> integer; std::cin.ignore();
  std::cout << "Collatz sequence: ";
  C.calculus (integer);
}
