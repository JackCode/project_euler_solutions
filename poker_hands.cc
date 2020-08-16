#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>

bool allSameSuit(std::string hand) {
  // Check that all suits match
  for (int i = 1; i < 14; i+=3) {
    if (hand[i] != hand[1]) {
      return false;
    }
  }
  return true;
}

std::vector<int> getSortedValues(std::string hand) {
  std::vector<int> values;

  for (int i = 0; i < 13; i+=3) {
    switch(hand[i]) {
      case 'J':
        values.push_back(11);
        break;
      case 'Q':
        values.push_back(12);
        break;
      case 'K':
        values.push_back(13);
        break;
      case 'A':
        values.push_back(14);
        break;
      case 'T':
        values.push_back(10);
        break;
      default:
        values.push_back(hand[i]-48);
        break;
    }
  }
  std::sort(values.begin(), values.end());
  return values;
}

bool isConsecutive(std::vector<int> values) {
  for (int i = 0; i < 4; i++) {
    if(values[i] != values[i+1]-1) return false;
  }
  return true;
}

int countPairs(std::vector<int> values) {
  int index = 0;
  int count = 0;

  while (index < 4) {
    if (values[index] == values[index+1]) {
      count++;
      index += 2;
    } else {
      index++;
    }
  }
  return count;
}

bool isRoyalFlush(std::string hand) {
  if (!allSameSuit(hand)) return false;
  std::vector<int> values = getSortedValues(hand);
  if (values[0] != 10) return false;
  return isConsecutive(values);
}

bool isStraightFlush(std::string hand) {
  if (!allSameSuit(hand)) return false;
  std::vector<int> values = getSortedValues(hand);
  return isConsecutive(values);
}

bool isFourOfKind(std::string hand) {
  std::vector<int> values = getSortedValues(hand);
  return ((values[0] == values[1] && values[0] == values[2] && values[0] == values[3]) ||
          (values[1] == values[2] && values[1] == values[3] && values[1] == values[4]) );
}

bool isFullHouse(std::string hand) {
  std::vector<int> values = getSortedValues(hand);
  int pairs = countPairs(values);
  if (pairs != 2) return false;

  return (values[0] == values[1] && values[0] == values[2] ||
          values[2] == values[3] && values[2] == values[4]);
}

bool isFlush(std::string hand) {
  return allSameSuit(hand);
}

bool isStraight(std::string hand) {
  std::vector<int> values = getSortedValues(hand);
  return isConsecutive(values);
}

bool isThreeOfKind(std::string hand) {
  std::vector<int> values = getSortedValues(hand);
  return ((values[0] == values[1] && values[0] == values[2]) ||
          (values[1] == values[2] && values[1] == values[3]) ||
          (values[2] == values[3] && values[2] == values[4]) );
}

bool isTwoPairs(std::string hand) {
  std::vector<int> values = getSortedValues(hand);
  return countPairs(values) == 2;
}

bool isOnePair(std::string hand) {
  std::vector<int> values = getSortedValues(hand);
  return countPairs(values) == 1;
}

int highCard(std::string hand) {
  std::vector<int> values = getSortedValues(hand);
  return values[4];
}

int classifyHand(std::string hand) {
  if (isRoyalFlush(hand)) return 23;
  if (isStraightFlush(hand)) return 22;
  if (isFourOfKind(hand)) return 21;
  if (isFullHouse(hand)) return 20;
  if (isFlush(hand)) return 19;
  if (isStraight(hand)) return 18;
  if (isThreeOfKind(hand)) return 17;
  if (isTwoPairs(hand)) return 16;
  if (isOnePair(hand)) return 15;
  return highCard(hand);
}

int breakTie(std::string player1, std::string player2, int classification) {
  std::vector<int> player1Values = getSortedValues(player1);
  std::vector<int> player2Values = getSortedValues(player2);
  
  // Two RF is a tie
  if (classification == 23) return -1;
  
  // Straight Flush
  if (classification == 22) {
    if (player1Values[4] == player2Values[4]) return -1;
    return (player1Values[4] > player2Values[4]) ? 1 : 2;
  }

  // Four of a kind
  if (classification == 21) {
    int player1High = player1Values[2];
    int player2High = player2Values[2];

    if (player1High != player2High) {
      return (player1High > player2High) ? 1 : 2;
    } else {
      return -1;
    }
  }

  // Full House
  if (classification == 20) {
    int player1High = player1Values[2];
    int player2High = player2Values[2];

    if (player1High != player2High) {
      return (player1High > player2High) ? 1 : 2;
    } else {
      return -1;
    }
  }

  // Flush
  if (classification == 19) {
    int index = 4;

    while (player1Values[index] == player2Values[index] && index >= 0) {
      index--;
    }

    if (index == -1) return -1;

    return (player1Values[index] > player2Values[index]) ? 1 : 2;
  }

  // Straight
  if (classification == 18) {
    if (player1Values[4] == player2Values[4]) return -1;

    return (player1Values[4] > player2Values[4]) ? 1 : 2;
  }

  // Three of a kind
  if (classification == 17) {
    int player1High = player1Values[2];
    int player2High = player2Values[2];

    if (player1High != player2High) {
      return (player1High > player2High) ? 1 : 2;
    } else {
      return -1;
    }
  }

  // Two Pairs
  if (classification == 16) {
    // not needed for this given set of games
    return -1;
  }

  // One Pairs
  if (classification == 15) {
    int player1pair = 0;
    int player2pair = 0;

    int index = 0;
    while (index < 4) {
      if (player1Values[index] == player1Values[index+1]) {
        player1pair = player1Values[index];
        break;
      }
      index++;
    }

    index = 0;
    while (index < 4) {
      if (player2Values[index] == player2Values[index+1]) {
        player2pair = player2Values[index];
        break;
      }
      index++;
    }
    if (player1pair == player2pair) return -1;
    return (player1pair > player2pair) ? 1 : 2;
  }

  // High Card
  if (classification < 15) {
    int index = 4;
    while (player1Values[index] == player2Values[index] && index >= 0) {
      index--;
    }

    if (index == -1) return -1;

    return (player1Values[index] > player2Values[index]) ? 1 : 2;
  } 
  return -1;
}

int winningPlayer(std::string player1, std::string player2) {
  int handPlayer1 = classifyHand(player1);
  int handPlayer2 = classifyHand(player2);
  int winner = 0;

  if (handPlayer1 == handPlayer2) {
    winner = breakTie(player1, player2, handPlayer1);
  } else {
    winner = (handPlayer1 > handPlayer2) ? 1 : 2;
  }

  return winner;
}

int main() {
  int tieGames = 0;
  int playerOne = 0;
  int playerTwo = 0;

  std::string game = "";
  std::ifstream poker("poker.txt");
  std::ofstream tieGamesText("tieGames.txt");

  if (poker.is_open() && tieGamesText.is_open()) {
    while (getline(poker, game)) {
      int winner = winningPlayer(game.substr(0, 14), game.substr(15, 14));
      if (winner == -1) {
        tieGamesText << game << "\n";
        tieGames++;
      } else if (winner == 1) {
        playerOne++;
      } else {
        playerTwo++;
      }
    }

    std::cout << "Player One: " << playerOne << std::endl;
    std::cout << "Player Two: " << playerTwo << std::endl;
    std::cout << "Tie Games: " << tieGames << std::endl; // Judge by hand :)

    tieGamesText.close();
    poker.close();
  } else {
    std::cout << "Unable to open file.\n";
  }
  return 0;
}

