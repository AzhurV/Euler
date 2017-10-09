#include <stdio.h>
#define UPPER 1000


int main(void){
  int sum = 0;
  int multiple;
  for(multiple = 3; multiple < UPPER; multiple += 3){
    sum += multiple;
  }

  for(multiple = 5; multiple < UPPER; multiple += 5){
    if(multiple % 3 != 0){
      sum += multiple;
    }
  }

  printf("%d\n", sum);
  return 0;
}
