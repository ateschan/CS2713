#include "employee.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  char f_name[20];
  scanf("%s", f_name);
  int ect = 4;

  Employee* emp_arr = readData(f_name, &ect);
  
  for (int i = 0; i < ect; i++) {
    printf("%s %d %lf\n", emp_arr[i].name, emp_arr[i].id, emp_arr[i].salary);
  }

  writeData("out", getBestEmployee(emp_arr, &ect));
  free(emp_arr);
}
