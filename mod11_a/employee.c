#include "employee.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Employee* readData(char* filename, int *arr_size) {
  FILE* fptr;
  fptr = fopen(filename,"r");
  char linebuffer[200];
  int emp_ct = 0;
  Employee* emp_arr = (Employee*) malloc(sizeof(Employee) * *arr_size);
  //1
  if (fptr == NULL) {
    printf("CANNOT OPEN FILE");
  }

  //This does nothing
  while (fgets(linebuffer, 200, fptr) != NULL) {
    emp_ct += 1;
  }
  rewind(fptr);
  
  char tmp_name[20];
  int tmp_id;
  double tmp_sal;
  emp_ct = 0;
  while (fgets(linebuffer, 200, fptr) != NULL) {
    sscanf(linebuffer, "%s %d %lf", tmp_name, &tmp_id, &tmp_sal);
    emp_arr[emp_ct].id = tmp_id;
    strcpy(emp_arr[emp_ct].name, tmp_name);
    emp_arr[emp_ct].salary = tmp_sal;
    emp_ct += 1;
  }
  fclose(fptr);
  return emp_arr;
}

//Get highest salary
Employee getBestEmployee(Employee *emp_arr, int *arr_size) {
  Employee highest;
  highest.salary = 0;
  for (int i = 0; i < *arr_size; i++) {
    if (emp_arr[i].salary > highest.salary) {
      highest = emp_arr[i];
    }
  }
  return highest;
}

void writeData(char *filename, Employee employee) {
  FILE* fptr = fopen(filename,"w");
  if (fptr == NULL) {
    printf("CANNOT OPEN FILE");
  }
  int fuckoff = (int) employee.salary;
  fprintf(fptr, "%s %d %d", employee.name, employee.id, fuckoff);
}
