#include <iostream>
#include <math.h>

bool isPrime(int n) {
  bool isPrime = true;
  if (n == 0 || n == 1) {
      isPrime = false;
  }
  else {
      for (int i = 2; i <= sqrt(n); ++i) {
          if (n % i == 0) {
              isPrime = false;
              break;
          }
      }
  }
  return isPrime;
}

void sumOfPrimes(int limit) {
  unsigned long sum = 0;

  int n = 1;
  while (n < limit) {
    std::cout << n << std::endl;
    sum += (isPrime(n)) ? n : 0;
    n += 2;
  }
  std::cout << "Sum: " << sum << std::endl;
}

int main() {
  sumOfPrimes(5000000);
  return 0;
}