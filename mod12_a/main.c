#include "flights.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if (argc == 1) {
    printf("ERROR NO ARGS\n");
    return(0);
  }

  FILE* fptr = fopen(argv[1], "r");
  if (fptr == NULL) {
    printf("ERROR FILE CANNOT OPEN");
    return 0;
  }

  Flight* f_arr = (Flight*) malloc(sizeof(Flight) * NUM_FLIGHTS);
  
  char line_buff[200];
  char tmp_o[4];
  char tmp_d[4];
  char tmp_a[3];
  int tmp_p = 0;

  int fc = 0;
  while (fgets(line_buff, 200, fptr) != NULL) {
    sscanf(line_buff, "%[^,],%[^,],%[^,],%d", tmp_o, tmp_d, tmp_a, &tmp_p);
    strcpy(f_arr[fc].origin, tmp_o);
    strcpy(f_arr[fc].destination, tmp_d);
    strcpy(f_arr[fc].airline, tmp_a);
    f_arr[fc].passangers = tmp_p;
    fc++;
  }

  char user_in[3];
  scanf("%s", user_in);

  int airline_flights = 0;
  int airline_passangers = 0;
  for (int i = 0; i < NUM_FLIGHTS; i++) {
    if (strcmp(f_arr[i].airline, user_in) == 0) {
      airline_flights += 1;
      airline_passangers += f_arr[i].passangers;
    }
  }

  printf("airline: %s\n", user_in);
  printf("flights: %d\n", airline_flights);
  printf("passangers: %d\n", airline_passangers);
}
