#include <stdio.h>
#include <math.h>
#define UPPER 1000000


void sieve(int bool_list[UPPER], int upper){
  int j;
  for(j = 2; j < upper; j++){
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
  return;
}


long nth_prime(int n){
  long i = 0;
  int cur;
  int primes[UPPER] = { 0 };
  
  sieve(primes, UPPER);

  for(cur = 0; cur != n; cur++){
    i++;
    while(!primes[i]){
      i++;
      if(i >= UPPER){
	printf("Max reached\n");
	return -1;
      }
    }
  }

  return i;
}


int main(void){
  long prime = nth_prime(10001);

  printf("%ld\n", prime);

  return 0;
}
