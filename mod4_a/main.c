#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int dyn_size = 0;
  scanf("%d", &dyn_size);
  int* myData = malloc(sizeof(int) * dyn_size);

  for (int i = 0; i < dyn_size; i++){
    *(myData + i) = i;
  }
  
  for (int i = 0; i < dyn_size; i++){
    printf("%d ", *(myData + i));
  }

  printf("\n");;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
  
  int total = 0;
  for (int i = 0; i < dyn_size; i++) {
    total += i;
  }
  double avg = (double) total/dyn_size;
  printf("average: %.2lf\n", avg);


  return 0;
}
