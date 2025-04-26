#include <stdlib.h>
#include <stdio.h>
#ifndef route_records
#define route_records

typedef enum SearchType {
  ROUTE,
  ORIGIN,
  DESTINATION,
  AIRLINE
} SearchType;

typedef struct RouteRecord {
  char origin[50];
  char destination[50];
  char airline[50];
  int passengerCount[6];
} RouteRecord ;

RouteRecord* createRecords (FILE* fileIn);
int fillRecords (RouteRecord* r, FILE* fileIn);
int findAirlineRoute(RouteRecord* r, int length, const char* origin, const char* destination, const char* airline, int curIdx);
void searchRecords(RouteRecord* r, int length, const char* key1, const char* key2, SearchType st);
void printMenu();

#endif // !route_records
