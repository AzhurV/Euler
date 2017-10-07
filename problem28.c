#include <stdio.h>
#define SIZE 1001

long spiral_sum(){
  long sum = 1;
  int current = 1;
  int jump = 2;
  int i = 0;

  while(current < SIZE * SIZE){
    current += jump;
    i++;
    sum += current;

    if(i % 4 == 0){
      jump+= 2;
    }
  }
  return sum;
}

int main(void){
  long sum = spiral_sum();

  printf("Sum of diagonals for %d by %d matrix is %ld\n", SIZE, SIZE, sum);

  return 0;
}
