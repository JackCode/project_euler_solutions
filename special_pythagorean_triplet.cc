#include <math.h>
#include <iostream>

bool isPythagTrip(int a, int b, int c) {
  return pow(a, 2) + pow(b, 2) == pow(c, 2);
}

int specialPytagTrip() {
  for (int a = 1; a < 998; a++) {
    for (int b = 2; b < 999; b++) {
      int c = 1000 - a - b;
      if (isPythagTrip(a, b, c)) {
        std::cout << a * b * c << " a: " << a << " b: " << b << " c: " << c << std::endl;
        return 0;     
      }
    }
  }
  return -1;
}

int main() {
  specialPytagTrip();
  return 0;
}