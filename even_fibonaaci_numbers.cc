#include <vector>
#include <iostream>

int sumEvenFib() {
  std::vector<int> fibs = {0, 1};
  int sumOfEvens = 0;

  int i = 2;
  do {
    fibs.push_back(fibs[i-1] + fibs[i-2]);
    std::cout << fibs[i] << std::endl;
    if (fibs[i] % 2 == 0) sumOfEvens += fibs[i];
    i++;
  } while (fibs[i-1] < 4000000);

  return sumOfEvens;
}

int main() {
  std::cout << sumEvenFib() << std::endl;
  return 0;
}