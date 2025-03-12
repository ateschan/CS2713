//Addison Teschan Mar 12 2025
//qmn167
//Project 1

#include "functions.h"
#include <stdio.h>
#include <stdlib.h>

int getRandomNumber(int min, int max){
  return rand() % (max - min + 1) + min;
}

CHAMPION createChamion(){
  return getRandomNumber(0,2);
}

int getChampionPower(CHAMPION c) {
  switch (c) {
    case MAGE:
      return getRandomNumber(1,8);
      break;
    case FIGHTER:
      return getRandomNumber(3,7);
      break;
    case TANK:
      return getRandomNumber(5,9);
      break;
  }
  return 0; 
}

void printChampion(CHAMPION c) {
  switch (c) {
    case MAGE:
      printf("MAGE");
      break;
    case FIGHTER:
      printf("FIGHTER");
      break;
    case TANK:
      printf("TANK");
      break;
  }
}

void playRound(int* p1_total, int* p2_total, CHAMPION c1, int c1_power, CHAMPION c2, int c2_power) {
  if ((c1 == MAGE) && (c2 == MAGE)) { //MAGEVMAGE
    if (c1_power > c2_power) {
      *p1_total += c1_power;
      *p2_total -= c2_power;
      printf("Player 1 (MAGE) wins and gains their power.\n");
      printf("Player 2 (MAGE) loses and lost their power.\n");
    } 
    else if (c1_power > c2_power) {
      *p2_total += c2_power;
      *p1_total -= c1_power;
      printf("player 1 (MAGE) loses and lost their power.\n");
      printf("Player 2 (MAGE) wins and gains their power.\n");
    } 
    return;
  }
  else if (((c1 == MAGE) && (c2 == FIGHTER)) || ((c1 == FIGHTER) && (c2 == MAGE))) { //MAGEVFIGHTER
    if (c1_power > c2_power) {
      if (c1 == MAGE) {
        *p1_total = *p1_total + c1_power; 
        printf("Player 1 (MAGE) wins and gains their power.\n"); 
        printf("Player 2 (FIGHTER) loses and suffers no penalty.\n");
        *p2_total = *p2_total - c2_power;
        printf("Player 1 (FIGHTER) wins and suffers no penalty.\n");
        printf("Player 2 (MAGE) loses and lost their power.\n");
      }
    } 
    if (c1_power < c2_power) {
      if (c2 == MAGE) {
        *p2_total += c2_power;
        printf("Player 1 (FIGHTER) loses and suffers no penalty.\n");
        printf("Player 2 (MAGE) wins and gains their power.\n");
      }
      if (c2 == FIGHTER) {
        *p1_total += c1_power;
        printf("Player 1 (MAGE) loses and lost their power.\n");
        printf("Player 2 (FIGHTER) wins and suffers no penalty.\n");
      }
    }
    return;
  }

  else if (((c1 == MAGE) && (c2 == TANK)) || ((c1 == TANK) && (c2 == MAGE))) { //MAGEVTANK
    if (c1 == MAGE) {
      *p1_total += c1_power;
      *p2_total -= c2_power;
        printf("Player 1 (MAGE) wins and gains their power.\n");
        printf("Player 2 (TANK) loses and lost their power.\n");
    }  
    if (c2 == MAGE) {
      *p2_total += c2_power;
      *p1_total -= c1_power;
        printf("Player 1 (TANK) loses and lost their power.\n");
        printf("Player 2 (MAGE) wins and gains their power.\n");
    }
    return;
  }

  else if ((c1 == FIGHTER) && (c2 == FIGHTER)) { //FIGHTERVFIGHTER
    *p1_total += c1_power;
    *p2_total += c2_power;
    printf("Both players gain their power.\n");
  }
  else if (((c1 == FIGHTER) && (c2 == TANK)) || ((c1 == TANK) && (c2 == FIGHTER))) { //FIGHERVTANK
    if (c1 == FIGHTER) {
      printf("Player 1 (FIGHTER) wins and gains their power.\n");
      printf("Player 2 (TANK) loses and suffers no penalty.\n");
      *p1_total += c1_power;
    } 
    if (c2 == FIGHTER) {
      printf("Player 1 (TANK) loses and suffers no penalty.\n");
      printf("Player 2 (FIGHTER) wins and gains their power.\n");
      *p2_total += c2_power;
    } 
    return;
  }
  else if ((c1 == 2) && (c2 == 2)) { //TANKVTANK
    printf("Both players suffer no penalty.\n");
    return;
  }
}

//Makes sense bc P(3,3) == 3! == 6 lol
