#include <stdio.h>
#define SIZE 10


long factorial(int n){
  long product = 1;
  while(n > 1){
    product *= n;
    n--;
  }
  return product;
}


long digit_factorial_sum(){
  long sum;
  long total = 0;
  long max;
  long i;
  int j;
  long facts[10];
  char buf[SIZE] = {0};
  
  for(i = 0; i < 10; i++){
    sum = factorial(i);
    max += sum;
    facts[i] = sum;
  }

  for(i = 10; i < max; i++){
    sum = 0;
    sprintf(buf, "%ld", i);
    for(j = 0; buf[j]; j++){
      sum += facts[buf[j] - '0'];
    }
    if(sum == i){
      total += i;
    }
  }
  return total;
}


int main(void){
  long total;

  total = digit_factorial_sum();

  printf("Total sum is %ld\n", total);

  return 0;
}
