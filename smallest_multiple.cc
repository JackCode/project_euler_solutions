#include <iostream>
#include <vector>

int smallestMultiple(int limit) {
  int product = 1;
  int factor = 2;

  while (factor <= limit) {
    int currFactorization = 1;
    if (product % factor == 0) {
      factor++;
      continue;
    }

    while (currFactorization * factor <= limit)
      currFactorization *= factor;

    product *= currFactorization;
    factor++;
  }

  return product;
}


int main() {
  std::cout << smallestMultiple(20) << std::endl;
  return 0;
}