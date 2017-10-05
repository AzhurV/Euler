#include <stdio.h>
#include <stdlib.h>

#define UPPER 28123 + 1

long sums[UPPER] = {0};
int isAddend[UPPER] = {0};

//Populate the sums list
void populate_sums(){
  int i, divisor;
  long sum;
  for(i = 1; i < UPPER; i++){
    sum = 0;
    for(divisor = 1; divisor <= i / 2; divisor++){
      if(i % divisor == 0){
	sum += divisor;
      }
    }
    sums[i] = sum;
  }
}

int is_abundant(int i){
  if(sums[i] > i){
    return 1;
  }
  return 0;
}

//Populate the list isAddend to indicate which numbers are made of abundant numbers
void populate_addends(){
  int i, j;
  for(i = 0; i < UPPER; i++){
    for(j = 0; j + i < UPPER; j++){
      if(is_abundant(i) && is_abundant(j)){
	isAddend[j + i] = 1;
      }
    }
  }
}



int main(int argc, char** argv){
  populate_sums();
  populate_addends();
  long sum;
  int current;
  sum = 0;
  for(current = 1; current < UPPER; current++){
    if(!isAddend[current]){
      sum += current;
    }
  }
  printf("Sum is %ld\n", sum);
  exit(EXIT_SUCCESS);
}

  
