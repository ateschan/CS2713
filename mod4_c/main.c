#include <stdio.h>
#include <stdlib.h>

int main() {
  int size;
  scanf("%d", &size);

  int* myData = (int*) malloc(size * sizeof(int));
  
  double total = 0;
  int offset = 0;
  for (int i = 0; i < size; i++) {
    *(myData + offset) = i;
    offset += 1;
    total += i;
  }
  double avg = total/size;
  
  for (int i = 0; i < size; i++) {
    printf("%d ", *(myData + i));
  }
  printf("\n");
  printf("average: %.2lf\n", avg);
  
}
