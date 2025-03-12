#include <stdio.h>
int main() {
int num;
scanf("%d", &num);
if (num%3 == 0){
    printf("CS");
  }
if (num%5 == 0){
    printf("1714");
  }
if ((num%5 == 0) && (num%3 == 0)){
    printf("CS1714");
  }
if (!((num%5 == 0) || (num%3 == 0))) {
    printf("ERROR");
  }
}
