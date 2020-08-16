#include <iostream>

bool isPrime(int n) {
  bool isPrime = true;

  if (n == 0 || n == 1) {
      isPrime = false;
  } else {
    for (int i = 2; i <= n / 2; ++i) {
        if (n % i == 0) {
            isPrime = false;
            break;
        }
    }
  }
  return isPrime;
}

int a_10001st_prime() {
  int count = 0;
  int i = 0;

  while (count < 10001) {
    i++;
    if (isPrime(i)) {
      count++;
    }
  }
  return i;
}

int main() {
  std::cout << a_10001st_prime() << std::endl;
  return 0;
}