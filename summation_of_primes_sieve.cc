#include <iostream>
#include <math.h>
#include <vector>

void summationPrimes(int limit) {
  int sieveBound = (limit - 1) / 2;
  std::vector<bool> sieve;

  for (int i = 1; i <= sieveBound; i++)
    sieve.push_back(false);

  int crossLimit = (sqrt(limit) - 1) / 2;

  for (int i = 1; i < crossLimit; i++) {
    if (!sieve[i]) {
      for (int j = 2*i*(i+1); j < sieveBound; j+=(2*i+1)) {
        sieve[j] = true;
      }
    }
  }

  unsigned long sum = 2;
  for (int i = 1; i < sieveBound; i++) {
    if (!sieve[i]) {
      sum += (2*i+1);
    }
  }

  std::cout << sum << std::endl;
}

int main() {
  summationPrimes(2000000);
  return 0;
}