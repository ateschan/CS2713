#include <stdio.h>

// Add all occurences of goal value
int CheckSingles(int dice[], int goal) {
  int goalct = 0;
  for (int i = 0; i < 5; i++) {
    if (dice[i] == goal) {
      goalct += 1;
    }
  }
  return goalct * goal;
}

// Check for three of a kind (score = 30)
int CheckThreeOfKind(int dice[]) {
  return -1;
}

// Check for four of a kind (score = 40)
int CheckFourOfKind(int dice[]) {
  return -1;
}

// Check for five of a kind (score = 50)
int CheckFiveOfKind(int dice[]) {
   /* Complete the function and update the return statement */
   return -1;
}

// Check for full house (score = 35)
int CheckFullHouse(int dice[]) {
   /* Complete the function and update the return statement */
   return -1;
}

// Check for straight (score = 45)
int CheckStraight(int values[]) {
   /* Complete the function and update the return statement */
   return -1;
}

// Find high score
int FindHighScore(int values[]) {
  int highest = 0;
  for (int i = 1; i < 7; i++) {
    if (CheckSingles(values, i) > highest){
      highest = CheckSingles(values, i);
    }
  }
   return highest;
}

int main(void) {
   int diceValues[5];
   int highScore = 0;

   // Fill array with five values from input in ascending order
   for(int i = 0; i < 5; ++i) {
      scanf("%d", &diceValues[i]);
   }
   // Find high score and output
   highScore = FindHighScore(diceValues);
   printf("High score: %d\n", highScore);
}
