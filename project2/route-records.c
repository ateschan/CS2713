#include "route-records.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

RouteRecord* createRecords(FILE *fileIn) {
  char buff[50];
  fgets(buff, 50, fileIn);
  int ct = 0;

  while (fgets(buff, 50, fileIn)) {
    ct++;
  }    

  RouteRecord* records = (RouteRecord *) malloc(sizeof(RouteRecord) * ct);

  for (int i = 0; i < ct; i++) {
    for (int j = 0; j < 6; j++) {
      records[i].passengerCount[j] = 0;
    }
  }
  return records;
}

int fillRecords(RouteRecord *r, FILE *fileIn) {
  char buff[50];
  fgets(buff, 50, fileIn);
  int recCt = 0;
 
  int tmpMonth = 0;
  char tmpDst[4];
  char tmpOrg[4];
  char tmpArln[4];
  int tmpPass = 0;

  while (fgets(buff, 50, fileIn)) {
    sscanf(buff, "%d, %[^,], %[^,], %[^,], %d", &tmpMonth, tmpOrg, tmpDst, tmpArln, &tmpPass); 
    //printf("%d %s %s %s %d", tmpMonth, tmpOrg, tmpDst, tmpArln, tmpPass); 
    if (strlen(tmpArln) < 3) {
      if (recCt == 0){
        recCt += 1;
        r[recCt].passengerCount[tmpMonth - 1] = tmpPass;
        strcpy(r[recCt].destination, tmpDst);
        strcpy(r[recCt].airline, tmpArln);
        strcpy(r[recCt].origin, tmpOrg);
      }
      else {
        for (int i = 0; i < recCt; i++) {
          if ((strcmp(tmpOrg, r[i].origin) == 0) && (strcmp(tmpDst, r[i].destination) == 0) && (strcmp(tmpArln, r[i].airline) == 0)) {
            r[i].passengerCount[tmpMonth - 1] += tmpPass; 
            break;
          }
          else {
            recCt += 1;
            r[recCt].passengerCount[tmpMonth - 1] += tmpPass;
            strcpy(r[recCt].destination, tmpDst);
            strcpy(r[recCt].airline, tmpArln);
            strcpy(r[recCt].origin, tmpOrg);
            break;
          }
        }
      }
    }
  }
  return recCt;
}

int findAirlineRoute(RouteRecord *r, int length, const char *origin, const char *destination, const char *airline, int curIdx) {
  if (curIdx == length) {
    return -1;
  }
  if ((strcmp(r[curIdx].origin, origin) == 0) && (strcmp(r[curIdx].airline, airline) == 0) && (strcmp(r[curIdx].destination, destination) == 0)) {
    return curIdx;
  }
  return findAirlineRoute(r, length, origin, destination, airline, curIdx + 1);
}

//TODO write out the big ass print function
void searchRecords(RouteRecord *r, int length, const char *key1, const char *key2, SearchType st) {
  int tmpMonthPass[6] = {0};
  int totalPass = 0;
  int matches = 0;

  for (int i = 0; i < length - 1; i++) {
    switch (st) {
      case ROUTE:
        if ((strcmp(r[i].origin, key1) == 0) && (strcmp(r[i].destination, key2) == 0)) {
          for (int j = 0; j < 6; j++) {
            tmpMonthPass[j] += r[i].passengerCount[j];
          }
          matches+=1;
          printf("%s (%s-%s) ", r[i].airline, r[i].origin, r[i].destination);
        }
        break;
      case ORIGIN:
        if (strcmp(r[i].origin, key1) == 0) {
          for (int j = 0; j < 6; j++) {
            tmpMonthPass[j] += r[i].passengerCount[j];
          }
          matches+=1;
          printf("%s (%s-%s) ", r[i].airline, r[i].origin, r[i].destination);
        }
        break;
      case DESTINATION:
        if (strcmp(r[i].destination, key1) == 0) {
          for (int j = 0; j < 6; j++) {
            tmpMonthPass[j] += r[i].passengerCount[j];
          }
          matches+=1;
          printf("%s (%s-%s) ", r[i].airline, r[i].origin, r[i].destination);
        }
        break;
      case AIRLINE:
        if (strcmp(r[i].airline, key1) == 0) {
          for (int j = 0; j < 6; j++) {
            tmpMonthPass[j] += r[i].passengerCount[j];
          }
          matches+=1;
          printf("%s (%s-%s) ", r[i].airline, r[i].origin, r[i].destination);
        }
        break;
    }
  }

  for (int i = 0; i < 6; i++) {
    totalPass += tmpMonthPass[i];
  }

  printf("\n%d matches were found.\n", matches);
  printf("\nStatistics\n");
  printf("Total passangers: %d\n", totalPass);
  printf("Total passangers in Month 1: %d\n", tmpMonthPass[0]);
  printf("Total passangers in Month 2: %d\n", tmpMonthPass[1]);
  printf("Total passangers in Month 3: %d\n", tmpMonthPass[2]);
  printf("Total passangers in Month 4: %d\n", tmpMonthPass[3]);
  printf("Total passangers in Month 5: %d\n", tmpMonthPass[4]);
  printf("Total passangers in Month 6: %d\n", tmpMonthPass[5]);
  printf("\nAverage Passangers per Month: %d\n", totalPass / 6);
}

void printMenu() {
  printf( "\n\n######### Airline Route Records Database MENU #########\n" );
  printf( "1. Search by Route\n" );
  printf( "2. Search by Origin Airport\n" );
  printf( "3. Search by Destination Airport\n" );
  printf( "4. Search by Airline\n" );
  printf( "5. Quit\n" );
  printf( "Enter your selection: " );
}

