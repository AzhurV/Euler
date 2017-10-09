#include <stdio.h>
#define UPPER 4000000

int sum_even_fib(){
  int fib1 = 1;
  int fib2 = 1;
  int sum = 0;
  int temp;
  
  while(fib2 < UPPER){
    if(fib2 % 2 == 0){
      sum += fib2;
    }
    temp = fib2;
    fib2 += fib1;
    fib1 = temp;
  }

  return sum;
}

int main(void){
  int sum = sum_even_fib();

  printf("%d\n", sum);

  return 0;
}
