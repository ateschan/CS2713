#ifndef student_h
#define student_h

typedef struct student_struct {
  int id;
  char name[10];
} Student;

void sortStudents(Student sArr[], int size);
void print(Student sArr[], int size);
Student searchStudent(Student sArr[], int size, int id);

#endif // !student_h
