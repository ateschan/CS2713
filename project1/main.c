//Addison Teschan Mar 12 2025
//qmn167
//Project 1

#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int* p1_total = (int*) malloc(sizeof(int));
  int* p2_total = (int*) malloc(sizeof(int));
  srand(time(NULL));
  
  printf("Enter the number of rounds: ");
  int rounds = 0;
  scanf("%d", &rounds);

  for (int i = 0; i < rounds; i ++) {
    printf("ROUND %d\n", i);
    printf("--------\n");
    printf("Player points at the start of the round --  P1 = %d        P2 = %d\n", *p1_total, *p2_total);
    int c1 = createChamion();
    int c2 = createChamion();
    int c1_pwr = getChampionPower(c1);
    int c2_pwr = getChampionPower(c2);
    printf("P1: ");
    printChampion(c1);
    printf("-%d vs P2 : ", c1_pwr);
    printChampion(c2);
    printf("-%d\n", c2_pwr );
    playRound(p1_total, p2_total, c1, c1_pwr, c2, c2_pwr);
    printf("Player points at the end of the round --  P1 = %d        P2 = %d\n\n\n\n", *p1_total, *p2_total);
  }

  printf("GAME OVER!!!\n");
  if (*p1_total > *p2_total) {
    printf("Player 1 won.\n");
  }
  else if (*p1_total < *p2_total){
    printf("Player 2 won.\n");
  }
  else {
    printf("Tie.");
  }

  free(p1_total);
  free(p2_total);
}
