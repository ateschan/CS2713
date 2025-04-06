#ifndef employee_h

#define employee_h
typedef struct employee_struct {
  char name[10];
  int id;
  double salary;
} Employee;

Employee* readData(char* filename, int* arr_size);
Employee getBestEmployee(Employee* emp_arr, int* arr_size);
void writeData(char* filename, Employee employee);
   

#endif
