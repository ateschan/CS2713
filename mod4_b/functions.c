#include "functions.h"
#include <stdio.h>
#include <math.h>

double average(int arr[]) {
  double total = 0;
  for (int i = 0; i < LENGTH; i++) {
    total+=arr[i];
  }
  return total/LENGTH;
}

void quadraticFormula(double a, double b, double c, double* x1,double*  x2) {
  *x1 = (-b + (sqrt((pow(b, 2) - 4 * a * c))))/(2*a);
  *x2 = (-b - (sqrt((pow(b, 2) - 4 * a * c))))/(2*a);
}
