#include "functions.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
  int arr[LENGTH];
  double a, b, c, x1, x2;

  for (int i = 0; i < LENGTH; i++){
    scanf("%d", &arr[i]);
  }

  scanf("%lf", &a);
  scanf("%lf", &b);
  scanf("%lf", &c);
  
  quadraticFormula(a,b,c,&x1,&x2);

  printf("average: %.2lf\n", average(arr));
  printf("x1: %.2lf\n", x1);
  printf("x2: %.2lf\n", x2);

  return 0;
}
