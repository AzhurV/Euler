#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define BUF_SIZE 40
#define UPPER_LIM 354294
#define POWER 5

int digits_sum(char buf[BUF_SIZE]){
  int i;
  int sum = 0;
  for(i = 0; i < BUF_SIZE && buf[i]; i++){
    sum += (int) pow(buf[i] - '0', POWER);
  }
  return sum;
}

long sum_of_powers(){
  int i;
  long sum = 0;
  char buf[BUF_SIZE] = { 0 };

  for(i = 10; i < UPPER_LIM; i++){
    sprintf(buf, "%d", i);
    if(i == digits_sum(buf)){
      sum += i;
    }
  }

  return sum;
}

int main(void){
  long sum = sum_of_powers();

  printf("Sum of numbers that can be written as powers of 5 is %ld\n", sum);

  return 0;
}
