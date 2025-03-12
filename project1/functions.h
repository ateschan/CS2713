//Addison Teschan Mar 12 2025
//qmn167
//Project 1

#ifndef functions_h
#define functions_h
enum CHAMPION{MAGE, FIGHTER, TANK};
typedef enum CHAMPION CHAMPION;
int getRandomNumber(int min, int max);
CHAMPION createChamion();
int getChampionPower(CHAMPION c);
void printChampion(CHAMPION c);
void playRound(int* p1_total, int* p2_total, CHAMPION c1, int c1_power, CHAMPION c2, int c2_power);
#endif
