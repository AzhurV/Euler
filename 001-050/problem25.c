#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1024
#define DIGITS_N 1000

void copy_fib(int fib_1[MAX_SIZE], int fib_2[MAX_SIZE], int next[MAX_SIZE]){
  int i;
  for(i = 0; i < MAX_SIZE; i++){
    fib_1[i] = fib_2[i];
    fib_2[i] = next[i];
  }
  return;
}


int reverse_fib_add(char fib_1[MAX_SIZE], char fib_2[MAX_SIZE], int cur_digit){
  int remainder = 0;
  int i = 0;
  int sum = 0;
  char temp[MAX_SIZE] = {'0'};
  for(i = 0; i < MAX_SIZE; i++){
    temp[i] = '0';
  }
  i = 0;
  while(i < cur_digit || remainder > 0){
    sum = fib_1[i] - '0'+ fib_2[i] - '0' + remainder;
    remainder = 0;
    while(sum >= 10){
      remainder++;
      sum = sum - 10;
    }
    temp[i] = sum + '0';
    i++;
  }
  copy_fib(fib_1, fib_2, temp);
  return i;
}

void print_first_n(int n, char array[MAX_SIZE]){
  int i;
  for(i = 0; i < n; i++){
    printf("%c", array[i]);
  }
  printf("\n");
  return;
}

int main(void){
  char fib_1[MAX_SIZE];
  char fib_2[MAX_SIZE];
  int i;
  for(i = 0; i < MAX_SIZE; i++){
    fib_1[i] = fib_2[i] = '0';
  }
  fib_1[0] = '1';
  fib_2[0] = '1';

  int cur_digit = 1;
  i = 2;
  while(cur_digit < DIGITS_N){
    cur_digit = reverse_fib_add(fib_1, fib_2, cur_digit);
    i++;
  }
  printf("Index of first term with 1000 digits is %d\n", i);

  return 0;
}
