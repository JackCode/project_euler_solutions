#include <iostream>
#include <map>
#include <math.h>

bool isPalindrome(int num) {
   int rev=0,val;
   val = num;
   while(num > 0) {
      rev = rev * 10 + num % 10;
      num = num / 10;
   }
   return val == rev;
}

int largestPalindromeProduct() {
  std::map<int, bool> palindromes;

  for (int i = 100; i <= 999; i++) {
    for (int j = 100; j <= 999; j++) {
      if (isPalindrome(i*j)) palindromes.insert({i*j, true});
    }
  }

  if (palindromes.empty()) return 0;
  return palindromes.rbegin()->first;
}

int main() {
  std::cout << largestPalindromeProduct() << std::endl;
  return 0;
}

