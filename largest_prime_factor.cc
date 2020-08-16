#include <iostream>
#include <map>

unsigned long largestPrimeFactor(unsigned long n) {
  std::map<int, bool> factors;
  int f = 2;
  while (f <= n) {
    while (n % f == 0) {
      factors.insert({f, true});
      n /= f;
    };
    f++;
  }
  if (factors.empty()) return 1;

  return factors.rbegin()->first;
}

int main() {
  std::cout << largestPrimeFactor(600851475143) << std::endl;
  return 0;
}