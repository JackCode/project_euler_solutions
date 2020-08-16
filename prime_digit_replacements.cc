#include <iostream>
#include <chrono>
#include <math.h>
#include <map>

using namespace std;

int isPrime(int n) {
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

int main() {
  auto start = chrono::steady_clock::now();

  

  auto end = chrono::steady_clock::now();
  std::cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " ms\n";

  return 0;
}