#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#define UPPER 2000000

long long sieve(int upper){
  int bool_list[upper]; 
  int j;
  for(j = 0; j < upper; j++){
    bool_list[j] = 1;
  }
  int test_int = 2;
  double root = sqrt(upper);
  while(test_int <= root){
    int mult = test_int;
    while(mult + test_int < upper){
      mult += test_int;
      bool_list[mult] = 0;
    }
    test_int++;
    while(!bool_list[test_int] && test_int <= root){
      test_int++;
    }
  }
  int i;
  long long sum = 0;
  for(i = 2; i < upper; i++){
    if(bool_list[i]){
      sum += i;
    }
  }
  return sum;
}

int  main(int argc, char** argv){
  long long sum = sieve(UPPER);
  printf("Sum is %lld\n", sum);
  return 0;
}
