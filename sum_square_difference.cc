#include <iostream>
#include <math.h>

int sumOfSquares(int limit) {
  int result = 0;
  
  for (int i = 1; i <= limit; i++) {
    result += pow(i, 2);
  }

  return result;
}

int squareOfSums(int limit) {
  int result = 0;

  for (int i = 1; i <= limit; i++)
    result += i;

  return pow(result, 2);
}

int squareOfSumsMinusSumOfSquares(int limit) {
  return squareOfSums(limit) - sumOfSquares(limit);
}

int main() {
  std::cout << squareOfSumsMinusSumOfSquares(100) << std::endl;
}