#include "student.h"
#include <stdio.h>


//selection sort
void sortStudents(Student *sArr, int size) {
  for (int i = 0; i < size; i++) {
    int min_id = i;

    for (int j = i + 1; j < size; j++) { // moving up one, shrinking the unsorted portion.
      if (sArr[j].id < sArr[min_id].id) {
        min_id = j;
      }
    }

    Student temp = sArr[min_id];
    sArr[min_id] = sArr[i];
    sArr[i] = temp;
  }      
}

void print(Student *sArr, int size) {
  for (int i = 0; i < size; i++) {
    printf("(%s %d) -> ", sArr[i].name, sArr[i].id);
  }
  printf("\n");
}

//binary search
Student searchStudent(Student *sArr, int size, int id) {
  int i = 0;
  int k = size;
  while (i <= k) {
    int mid = i + (k - i) / 2;
    if (sArr[mid].id == id) {
      return sArr[mid];
    }
    if (sArr[mid].id < id) {
      i = mid + 1;
    }
    if (sArr[mid].id > id) {
      k = mid - 1;
    }
  }
  return sArr[0];
}
