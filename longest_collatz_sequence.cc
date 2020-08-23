#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

void collatzCount(int n, std::unordered_map<int, std::pair<bool, int>>& visited) {
  int count = 1;
  unsigned long long currentNumber = n;
  std::vector<int> numbersVisitedthisRound;

  while (currentNumber != 1) {
    if(!visited[currentNumber].first) {
      numbersVisitedthisRound.push_back(currentNumber);
    }
    if (currentNumber%2 == 0) {
      currentNumber /= 2;
      if (visited[currentNumber].first) {
        count += visited[currentNumber].second;
        break;
      }
    } else {
      currentNumber = 3 * currentNumber + 1;
      if (visited[currentNumber].first) {
        count += visited[currentNumber].second;
        break;
      }
    }
    count++;
  }

  for (int i = 0; i < numbersVisitedthisRound.size(); i++) {
    visited[numbersVisitedthisRound[i]] = {true, count};
    count--;
  }
  
}

int longestCollatzSeq() {
  unsigned long limit = 1000000;
  unsigned long startingNumber = 13;
  std::unordered_map<int, std::pair<bool, int>> visited;

  visited[0] = {true, 0};
  visited[1] = {true, 1};

  for (int i = 2; i <= limit; i++) {
    if (!visited[i].first) {
      collatzCount(i, visited);
    }
  }

  int maxCount = 1;
  int currentMax = 1;
  for (int i = 1; i <= limit; i++) {
    if (visited[i].second > maxCount) {
      maxCount = visited[i].second;
      currentMax = i;
    }
  }
  return currentMax;
}

int main() {
  std::cout << longestCollatzSeq() << std::endl;
  return 0;
}