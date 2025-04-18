#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "student.h"


int main(int argc, char * argv[]) {
  int sCount = 0;
  int sindex = 0;
  char buff[100];
  
  if (argc != 2) {
    printf("ERROR NO ARGS\n");
    return 0;
  }

  FILE* fptr = fopen(argv[1], "r");

  if (fptr == NULL) {
    printf("ERROR FILE NOT OPEN\n");
    return 0;
  }

  while (fgets(buff, 100, fptr)) {
    sCount+=1;
  }

  rewind(fptr);
  Student* sArr = (Student*) malloc(sizeof(Student) * sCount);

  while (fgets(buff, 100, fptr)) {
    sscanf(buff, "%d,%s", &sArr[sindex].id, sArr[sindex].name); 
    sindex+=1;
  }

  print(sArr,sCount);
  sortStudents(sArr,sCount);
  print(sArr,sCount);
  
  scanf("%d", &sindex);
  Student myStudent = searchStudent(sArr, sCount, sindex);
  printf("(%d,%s)", myStudent.id, myStudent.name);
  free(sArr);
}
